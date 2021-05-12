#include "animation.h"

#include "assets/assets.h"
#include "building/industry.h"
#include "building/model.h"
#include "building/monument.h"
#include "building/type.h"
#include "city/festival.h"
#include "core/calc.h"
#include "core/image.h"
#include "game/animation.h"
#include "map/image.h"
#include "map/sprite.h"

int building_animation_offset(building *b, int image_id, int grid_offset)
{
    if (b->type == BUILDING_FOUNTAIN && (b->num_workers <= 0 || !b->has_water_access)) {
        return 0;
    }
    if (b->type == BUILDING_RESERVOIR && !b->has_water_access) {
        return 0;
    }
    if (building_is_workshop(b->type)) {
        if (b->loads_stored <= 0 || b->num_workers <= 0 || b->strike_duration_days > 0) {
            return 0;
        }
    }
    if ((b->type == BUILDING_PREFECTURE || b->type == BUILDING_ENGINEERS_POST) && b->num_workers <= 0) {
        return 0;
    }
    if (b->type == BUILDING_MARKET && b->num_workers <= 0) {
        return 0;
    }
    if (b->type == BUILDING_WAREHOUSE && b->num_workers < model_get_building(b->type)->laborers) {
        return 0;
    }
    if (b->type == BUILDING_DOCK && b->data.dock.num_ships <= 0) {
        map_sprite_animation_set(grid_offset, 1);
        return 1;
    }
    if (b->type == BUILDING_MARBLE_QUARRY && (b->num_workers <= 0 || b->strike_duration_days > 0)) {
        map_sprite_animation_set(grid_offset, 1);
        return 1;
    } else if ((b->type == BUILDING_IRON_MINE || b->type == BUILDING_CLAY_PIT ||
        b->type == BUILDING_TIMBER_YARD) && (b->num_workers <= 0 || b->strike_duration_days > 0)) {
        return 0;
    }
    if (b->type == BUILDING_GLADIATOR_SCHOOL) {
        if (b->num_workers <= 0) {
            map_sprite_animation_set(grid_offset, 1);
            return 1;
        }
    } else if (b->type >= BUILDING_THEATER && b->type <= BUILDING_CHARIOT_MAKER &&
        b->type != BUILDING_HIPPODROME && b->num_workers <= 0) {
        return 0;
    }
    if (b->type == BUILDING_GRANARY && b->num_workers < model_get_building(b->type)->laborers) {
        return 0;
    }
    if (building_monument_is_monument(b) && (b->type != BUILDING_ORACLE && b->type != BUILDING_NYMPHAEUM && (b->num_workers <= 0 || b->data.monument.phase != MONUMENT_FINISHED))) {
        return 0;
    }
    if ((b->type == BUILDING_ARCHITECT_GUILD || b->type == BUILDING_MESS_HALL || b->type == BUILDING_ARENA) && b->num_workers <= 0) {
        return 0;
    }
    if (b->type == BUILDING_TAVERN && (b->num_workers <= 0 || !b->data.market.inventory[4])) { //wine
        return 0;
    }
    if (b->type == BUILDING_WATCHTOWER && (b->num_workers <= 0 || !b->figure_id4)) {
        return 0;
    }
    if (b->type == BUILDING_LARGE_STATUE && !b->has_water_access) {
        return 0;
    }
    if (b->type == BUILDING_COLOSSEUM) {
        switch (city_festival_games_active()) {
            case 1:
                map_image_set(grid_offset, assets_get_image_id(assets_get_group_id("Areldir", "Colosseum"), "Col Naumachia"));
                break;
            case 2:
                map_image_set(grid_offset, assets_get_image_id(assets_get_group_id("Areldir", "Colosseum"), "Col Imp Games"));
                break;
            case 3:
                map_image_set(grid_offset, assets_get_image_id(assets_get_group_id("Areldir", "Colosseum"), "Col Exec"));
                break;
            default:
                map_image_set(grid_offset, assets_get_image_id(assets_get_group_id("Areldir", "Colosseum"), "Col Glad Fight"));
                if (b->num_workers <= 0) {
                    map_image_set(grid_offset, assets_get_image_id(assets_get_group_id("Areldir", "Colosseum"), "Coloseum OFF"));
                }
        }
    }

    //if (b->type == BUILDING_HIPPODROME) {
    //    switch (city_festival_games_active()) {
    //    case 1:
    //        map_image_set(grid_offset, assets_get_image_id(assets_get_group_id("Areldir", "Colosseum"), "Col Naumachia"));
    //        break;
    //    case 2:
    //        map_image_set(grid_offset, assets_get_image_id(assets_get_group_id("Areldir", "Colosseum"), "Col Naumachia"));
    //        break;
    //    case 3:
    //        map_image_set(grid_offset, assets_get_image_id(assets_get_group_id("Areldir", "Colosseum"), "Col Naumachia"));
    //        break;
    //    default:
    //        map_image_set(grid_offset, image_group(GROUP_BUILDING_HIPPODROME_1));
    //        if (b->num_workers <= 0) {
    //            return 0;
    //        }
    //    }
    //}

    const image *img = image_get(image_id);
    if (!game_animation_should_advance(img->animation_speed_id)) {
        return map_sprite_animation_at(grid_offset) & 0x7f;
    }
    // advance animation
    int new_sprite = 0;
    int is_reverse = 0;
    if (b->type == BUILDING_WINE_WORKSHOP) {
        // exception for wine...
        int pct_done = calc_percentage(b->data.industry.progress, 400);
        if (pct_done <= 0) {
            new_sprite = 0;
        } else if (pct_done < 4) {
            new_sprite = 1;
        } else if (pct_done < 8) {
            new_sprite = 2;
        } else if (pct_done < 12) {
            new_sprite = 3;
        } else if (pct_done < 96) {
            if (map_sprite_animation_at(grid_offset) < 4) {
                new_sprite = 4;
            } else {
                new_sprite = map_sprite_animation_at(grid_offset) + 1;
                if (new_sprite > 8) {
                    new_sprite = 4;
                }
            }
        } else {
            // close to done
            if (map_sprite_animation_at(grid_offset) < 9) {
                new_sprite = 9;
            } else {
                new_sprite = map_sprite_animation_at(grid_offset) + 1;
                if (new_sprite > 12) {
                    new_sprite = 12;
                }
            }
        }
    } else if (img->animation_can_reverse) {
        if (map_sprite_animation_at(grid_offset) & 0x80) {
            is_reverse = 1;
        }
        int current_sprite = map_sprite_animation_at(grid_offset) & 0x7f;
        if (is_reverse) {
            new_sprite = current_sprite - 1;
            if (new_sprite < 1) {
                new_sprite = 1;
                is_reverse = 0;
            }
        } else {
            new_sprite = current_sprite + 1;
            if (new_sprite > img->num_animation_sprites) {
                new_sprite = img->num_animation_sprites;
                is_reverse = 1;
            }
        }
    } else {
        // Absolutely normal case
        new_sprite = map_sprite_animation_at(grid_offset) + 1;
        if (new_sprite > img->num_animation_sprites) {
            new_sprite = 1;
        }
    }

    map_sprite_animation_set(grid_offset, is_reverse ? new_sprite | 0x80 : new_sprite);
    return new_sprite;
}
