#ifndef ROOMS_DATA_H
#define ROOMS_DATA_H

#include "types.h"
#include "structs/room.h"
#include "structs/sprite.h"

extern const u16 sDestroyedDockingBayAnimatedPal[6 * 16];

extern const u8 sBackground_Empty[52];

extern const u8 sEnemyRoomData_Empty[3];

extern const struct TilesetEntry sTilesetEntries[98];

extern const struct Door sMainDeckDoors[206];
extern const struct Door sSector1Doors[116];
extern const struct Door sSector2Doors[147];
extern const struct Door sSector3Doors[91];
extern const struct Door sSector5Doors[125];
extern const struct Door sSector4Doors[119];
extern const struct Door sSector6Doors[94];
extern const struct Door sTest1Doors[12];
extern const struct Door sTest2Doors[12];
extern const struct Door sTest3Doors[12];
extern const struct Door sTestDoors_Unused[2];

extern const u8 sTest1_0_Spriteset[ENEMY_ROOM_DATA_ARRAY_SIZE(2)];
extern const u8 sTest1_1_Spriteset[ENEMY_ROOM_DATA_ARRAY_SIZE(1)];
extern const u8 sTest1_2_Spriteset[ENEMY_ROOM_DATA_ARRAY_SIZE(1)];
extern const u8 sTest1_3_Spriteset[ENEMY_ROOM_DATA_ARRAY_SIZE(1)];
extern const u8 sTest2_0_Spriteset[ENEMY_ROOM_DATA_ARRAY_SIZE(2)];
extern const u8 sTest2_1_Spriteset[ENEMY_ROOM_DATA_ARRAY_SIZE(1)];
extern const u8 sTest2_2_Spriteset[ENEMY_ROOM_DATA_ARRAY_SIZE(1)];
extern const u8 sTest2_3_Spriteset[ENEMY_ROOM_DATA_ARRAY_SIZE(1)];
extern const u8 sTest3_0_Spriteset[ENEMY_ROOM_DATA_ARRAY_SIZE(7)];
extern const u8 sTest3_1_Spriteset[ENEMY_ROOM_DATA_ARRAY_SIZE(1)];
extern const u8 sTest3_2_Spriteset[ENEMY_ROOM_DATA_ARRAY_SIZE(1)];
extern const u8 sTest3_3_Spriteset[ENEMY_ROOM_DATA_ARRAY_SIZE(1)];

extern const struct RoomEntryRom sMainDeckRoomEntries[87];
extern const struct RoomEntryRom sSector1RoomEntries[54];
extern const struct RoomEntryRom sSector2RoomEntries[61];
extern const struct RoomEntryRom sSector3RoomEntries[39];
extern const struct RoomEntryRom sSector5RoomEntries[52];
extern const struct RoomEntryRom sSector4RoomEntries[48];
extern const struct RoomEntryRom sSector6RoomEntries[41];
extern const struct RoomEntryRom sTest1RoomEntries[4];
extern const struct RoomEntryRom sTest2RoomEntries[4];
extern const struct RoomEntryRom sTest3RoomEntries[4];

#endif /* ROOMS_DATA_H */
