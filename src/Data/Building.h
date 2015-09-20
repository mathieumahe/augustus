#ifndef DATA_BUILDING_H
#define DATA_BUILDING_H

#define MAX_BUILDINGS 2000
#define MAX_STORAGES 200
#define MAX_HOUSE_LEVELS 20

enum {
	Building_None = 0,
	Building_Menu_Farms = 2,
	Building_Menu_RawMaterials = 3,
	Building_Menu_Workshops = 4,
	Building_Road = 5,
	Building_Wall = 6,
	Building_DraggableReservoir = 7,
	Building_Aqueduct = 8,
	Building_ClearLand = 9,
	Building_HouseVacantLot = 10,
	Building_HouseSmallTent = 10,
	Building_HouseLargeTent = 11,
	Building_HouseSmallShack = 12,
	Building_HouseLargeShack = 13,
	Building_HouseSmallHovel = 14,
	Building_HouseLargeHovel = 15,
	Building_HouseSmallCasa = 16,
	Building_HouseLargeCasa = 17,
	Building_HouseSmallInsula = 18,
	Building_HouseMediumInsula = 19,
	Building_HouseLargeInsula = 20,
	Building_HouseGrandInsula = 21,
	Building_HouseSmallVilla = 22,
	Building_HouseMediumVilla = 23,
	Building_HouseLargeVilla = 24,
	Building_HouseGrandVilla = 25,
	Building_HouseSmallPalace = 26,
	Building_HouseMediumPalace = 27,
	Building_HouseLargePalace = 28,
	Building_HouseLuxuryPalace = 29,
	Building_Amphitheater = 30,
	Building_Theater = 31,
	Building_Hippodrome = 32,
	Building_Colosseum = 33,
	Building_GladiatorSchool = 34,
	Building_LionHouse = 35,
	Building_ActorColony = 36,
	Building_ChariotMaker = 37,
	Building_Plaza = 38,
	Building_Gardens = 39,
	Building_FortLegionaries = 40,
	Building_SmallStatue = 41,
	Building_MediumStatue = 42,
	Building_LargeStatue = 43,
	Building_FortJavelin = 44,
	Building_FortMounted = 45,
	Building_Doctor = 46,
	Building_Hospital = 47,
	Building_Bathhouse = 48,
	Building_Barber = 49,
	Building_DistributionCenter_Unused = 50,
	Building_School = 51,
	Building_Academy = 52,
	Building_Library = 53,
	Building_FortGround = 54,
	Building_Prefecture = 55,
	Building_TriumphalArch = 56,
	Building_Fort = 57,
	Building_Gatehouse = 58,
	Building_Tower = 59,
	Building_SmallTempleCeres = 60,
	Building_SmallTempleNeptune = 61,
	Building_SmallTempleMercury = 62,
	Building_SmallTempleMars = 63,
	Building_SmallTempleVenus = 64,
	Building_LargeTempleCeres = 65,
	Building_LargeTempleNeptune = 66,
	Building_LargeTempleMercury = 67,
	Building_LargeTempleMars = 68,
	Building_LargeTempleVenus = 69,
	Building_Market = 70,
	Building_Granary = 71,
	Building_Warehouse = 72,
	Building_WarehouseSpace = 73,
	Building_Shipyard = 74,
	Building_Dock = 75,
	Building_Wharf = 76,
	Building_GovernorsHouse = 77,
	Building_GovernorsVilla = 78,
	Building_GovernorsPalace = 79,
	Building_MissionPost = 80,
	Building_EngineersPost = 81,
	Building_LowBridge = 82,
	Building_ShipBridge = 83,
	Building_Senate = 84,
	Building_SenateUpgraded = 85,
	Building_Forum = 86,
	Building_ForumUpgraded = 87,
	Building_NativeHut = 88,
	Building_NativeMeeting = 89,
	Building_Reservoir = 90,
	Building_Fountain = 91,
	Building_Well = 92,
	Building_NativeCrops = 93,
	Building_MilitaryAcademy = 94,
	Building_Barracks = 95,
	Building_Menu_SmallTemples = 96,
	Building_Menu_LargeTemples = 97,
	Building_Oracle = 98,
	Building_BurningRuin = 99,
	Building_WheatFarm = 100,
	Building_VegetableFarm = 101,
	Building_FruitFarm = 102,
	Building_OliveFarm = 103,
	Building_VinesFarm = 104,
	Building_PigFarm = 105,
	Building_MarbleQuarry = 106,
	Building_IronMine = 107,
	Building_TimberYard = 108,
	Building_ClayPit = 109,
	Building_WineWorkshop = 110,
	Building_OilWorkshop = 111,
	Building_WeaponsWorkshop = 112,
	Building_FurnitureWorkshop = 113,
	Building_PotteryWorkshop = 114
};

enum {
	BuildingState_Unused = 0,
	BuildingState_InUse = 1,
	BuildingState_Undo = 2,
	BuildingState_Created = 3,
	BuildingState_Rubble = 4,
	BuildingState_DeletedByGame = 5, // used for earthquakes, fires, house mergers
	BuildingState_DeletedByPlayer = 6
};

enum {
	BuildingStorageState_Accepting = 0,
	BuildingStorageState_NotAccepting = 1,
	BuildingStorageState_Getting = 2
};

enum {
	HouseLevel_SmallTent = 0,
	HouseLevel_LargeTent = 1,
	HouseLevel_SmallShack = 2,
	HouseLevel_LargeShack = 3,
	HouseLevel_SmallHovel = 4,
	HouseLevel_LargeHovel = 5,
	HouseLevel_SmallCasa = 6,
	HouseLevel_LargeCasa = 7,
	HouseLevel_SmallInsula = 8,
	HouseLevel_MediumInsula = 9,
	HouseLevel_LargeInsula = 10,
	HouseLevel_GrandInsula = 11,
	HouseLevel_SmallVilla = 12,
	HouseLevel_MediumVilla = 13,
	HouseLevel_LargeVilla = 14,
	HouseLevel_GrandVilla = 15,
	HouseLevel_SmallPalace = 16,
	HouseLevel_MediumPalace = 17,
	HouseLevel_LargePalace = 18,
	HouseLevel_LuxuryPalace = 19,
};

#define BuildingIsHouse(type) ((type) >= Building_HouseVacantLot && (type) <= Building_HouseLuxuryPalace)
#define BuildingIsFarm(type) ((type) >= Building_WheatFarm && (type) <= Building_PigFarm)
#define BuildingIsWorkshop(type) ((type) >= Building_WineWorkshop && (type) <= Building_PotteryWorkshop)
#define BuildingIsEntertainment(type) ((type) >= Building_Theater && (type) <= Building_ChariotMaker)

#define BuildingIsInUse(buildingId) (Data_Buildings[buildingId].state == BuildingState_InUse)

extern struct Data_Building {
	unsigned char state;
	unsigned char ciid;
	unsigned char __unknown_02;
	unsigned char size;
	unsigned char houseIsMerged;
	unsigned char houseSize;
	unsigned char x;
	unsigned char y;
	short gridOffset;
	short type;
	union {
		short houseLevel;
		short warehouseResourceId;
		short workshopResource;
		short orientation;
		short fortWalkerType;
		short nativeMeetingCenterId;
	} subtype;
	unsigned char roadNetworkId;
	unsigned char __unknown_0f;
	unsigned short createdSequence;
	short housesCovered;
	short percentageWorkers;
	short housePopulation;
	short housePopulationRoom;
	short distanceFromEntry;
	short houseMaxPopulationSeen;
	short houseUnreachableTicks;
	unsigned char roadAccessX; // 20
	unsigned char roadAccessY; // 21
	short walkerId;
	short walkerId2; // labor seeker or market buyer
	short immigrantWalkerId;
	short walkerId4; // 28; tower ballista or burning ruin prefect
	unsigned char walkerSpawnDelay; // 2a
	unsigned char __unused_2b;
	unsigned char walkerRoamDirection;
	unsigned char hasWaterAccess;
	unsigned char __unused_2e;
	unsigned char __unused_2f;
	short prevPartBuildingId;
	short nextPartBuildingId;
	short loadsStored; // 34
	unsigned char __unused_36;
	unsigned char hasWellAccess;
	short numWorkers;
	unsigned char laborCategory;
	unsigned char outputResourceId; //3b
	unsigned char hasRoadAccess;
	unsigned char houseCriminalActive;
	short damageRisk;
	short fireRisk;
	short fireDuration; //42
	unsigned char fireProof; //44 cannot catch fire or collapse
	unsigned char houseGenerationDelay;
	unsigned char houseTaxCoverage;
	unsigned char __unused_47;
	short formationId;
	union {
		struct {
			short dockQueuedDockerId; // 4a
			char __unknown_4c;
			char __unknown_4d;
			char __unknown_4e;
			char __unknown_4f;
			char __unknown_50;
			char __unknown_51;
			char __unknown_52;
			char __unknown_53;
			char __unknown_54;
			char __unknown_55;
			char __unknown_56;
			char __unknown_57;
			char fishingBoatHasFish; // 58
			char __unknown_59;
			char __unknown_5a;
			char __unknown_5b;
			char __unknown_5c;
			char __unknown_5d;
			char __unknown_5e;
			char __unknown_5f;
			char __unknown_60;
			char __unknown_61;
			char __unknown_62;
			char __unknown_63;
			char __unknown_64;
			unsigned char dockNumShips; // 65 dock number of ships
			char __unknown_66;
			char __unknown_67;
			char dockOrientation; // 68
			char __unknown_69;
			char __unknown_6a;
			char __unknown_6b; // farm cursed
			short dockWalkerIds[3]; // 6c, 6e, 70
			short boatWalkerId; // 72
		} other;
		struct {
			short unknown; //4a
			short inventory[8];
			short potteryDemand; // 5c
			short furnitureDemand; // 5e
			short oilDemand; // 60
			short wineDemand; // 62
			char __padding[6]; // 64 - 69
			unsigned char fetchInventoryId; // 6a
		} market;
		struct {
			short unknown; //4a
			short resourceStored[16]; //4c and further
		} storage;
		struct {
			short progress; //4a+b
			char __padding[27];
			unsigned char blessingDaysLeft; //67
			char __pad68;
			unsigned char hasFullResource; //69
			char __pad6a;
			unsigned char curseDaysLeft; //6b
		} industry;
		struct {
			char __padding[26];
			unsigned char numShows; // 64
			unsigned char days1;
			unsigned char days2;
			unsigned char play;
		} entertainment;
		struct {
			short inventory[8]; //4a
			unsigned char theater; //5a
			unsigned char amphitheaterActor;
			unsigned char amphitheaterGladiator;
			unsigned char colosseumGladiator;
			unsigned char colosseumLion;
			unsigned char hippodrome;
			unsigned char school; //60
			unsigned char library;
			unsigned char academy;
			unsigned char barber;
			unsigned char clinic;
			unsigned char bathhouse;
			unsigned char hospital;
			unsigned char templeCeres;
			unsigned char templeNeptune;//68
			unsigned char templeMercury;
			unsigned char templeMars;
			unsigned char templeVenus;
			unsigned char noSpaceToExpand;
			unsigned char numFoods;
			unsigned char entertainment;
			unsigned char education;
			unsigned char health; //70
			unsigned char numGods;
			unsigned char devolveDelay;
			unsigned char evolveTextId;
		} house;
	} data;
	int taxIncomeOrStorage; // 74
	unsigned char houseDaysWithoutFood; // 78
	unsigned char ruinHasPlague;
	signed char desirability;
	unsigned char isDeleted; // 7b
	unsigned char isAdjacentToWater;
	unsigned char storageId;
	union {
		char houseHappiness;
		char nativeAnger;
	} sentiment;
	unsigned char showOnProblemOverlay;
} Data_Buildings[MAX_BUILDINGS];

extern struct Data_Building_Storage {
	int startUnused;
	int buildingId;
	unsigned char inUse;
	unsigned char emptyAll;
	unsigned char resourceState[22];
} Data_Building_Storages[MAX_STORAGES];

extern struct Data_Buildings_Extra {
	int highestBuildingIdInUse;
	int highestBuildingIdEver;
	int createdSequence;
	int barracksTowerSentryRequested;
} Data_Buildings_Extra;

extern struct Data_BuildingList {
	struct {
		int size;
		short items[MAX_BUILDINGS];
	} large;
	struct {
		int size;
		short items[500];
	} small;
	struct {
		int size;
		short items[500];
		int index;
		int totalBurning;
	} burning;
} Data_BuildingList;

#define DATA_BUILDINGLIST_SMALL_ENQUEUE(n) \
	Data_BuildingList.small.items[Data_BuildingList.small.size++] = i;\
	if (Data_BuildingList.small.size >= 500) {\
		Data_BuildingList.small.size = 499;\
	}

#define DATA_BUILDINGLIST_SMALL_FOREACH(block) \
	for (int i = 0; i < Data_BuildingList.small.size; i++) {\
		int item = Data_BuildingList.small.items[i];\
		block;\
	}

#endif
