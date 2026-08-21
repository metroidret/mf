#ifndef ROOM_STRUCTS_H
#define ROOM_STRUCTS_H

#include "types.h"
#include "oam.h"

#include "constants/connection.h"

#define ROOM_SPRITE_DATA_TERMINATOR UCHAR_MAX, UCHAR_MAX, UCHAR_MAX

struct TilesetTransparentColor {
    u16 transparentColor;
    u16 field_2;
};

extern struct TilesetTransparentColor gTilesetTransparentColor;

struct RoomEntry {
    u8 tilesetNumber;
    u8 bg0Prop;
    u8 bg1Prop;
    u8 bg2Prop;
    u8 bg3Prop;
    u8 scrollsFlag;
    u8 bg3Scroll;
    u8 transparency;
    const u8* pEnemyRoomData;
    u8 firstSpritesetEvent;
    u8 secondSpritesetEvent;
    u8 mapX;
    u8 mapY;
    u8 visualEffect;
    u16 effectY;
    u8 damagingEffect;
    u16 musicTrack;
    u8 bg0Size;
    u8 bg3Size;
    u8 animatedTileset;
    u8 animatedPalette;
};

extern struct RoomEntry gCurrentRoomEntry;

struct Bg3Movement {
    u8 direction;
    u8 timer;
    u8 leftToRightStage;
    u16 xOffset;
};

extern struct Bg3Movement gBg3Movement;

struct HorizontalTilemap {
    u8 tileCount;
    u16 blockX;
    u16 blockY;
    u16 unk_6[56]; // ((SCREEN_SIZE_Y / PIXEL_PER_BLOCK) + 4) * 4
};

extern struct HorizontalTilemap gHorizontalTilemap[3];

struct VerticalTilemap {
    u8 tileCount;
    u16 blockX;
    u16 blockY;
    u16 unk_6[76]; // ((SCREEN_SIZE_X / PIXEL_PER_BLOCK) + 4) * 4
};

extern struct VerticalTilemap gVerticalTilemap[3];

struct TilesetEntry {
    const u32* pTileGraphics;
    const u16* pPalette;
    const u32* pBackgroundGraphics;
    const u8* pTilemap;
    u8 animatedTileset;
    u8 animatedPalette;
};

struct RoomEntryRom {
    u8 tileset;
    u8 bg0Prop;
    u8 bg1Prop;
    u8 bg2Prop;
    u8 bg3Prop;
    const u8* pBg0Data;
    const u8* pBg1Data;
    const u8* pBg2Data;
    const u8* pClipData;
    const u32* pBg3Data;
    u8 bg3Scrolling;
    u8 transparency;
    const u8* pDefaultSpriteData;
    u8 defaultSpriteset;
    u8 firstSpritesetEvent;
    const u8* pFirstSpriteData;
    u8 firstSpriteset;
    u8 secondSpritesetEvent;
    const u8* pSecondSpriteData;
    u8 secondSpriteset;
    u8 mapX;
    u8 mapY;
    u8 effect;
    u8 effectY;
    u16 musicTrack;
};

extern const struct RoomEntryRom* sAreaRoomEntryPointers[AREA_END];

extern u16 gDecompClipdataMap[1024];
extern u16 gDecompBg0Map[6144];
extern u16 gDecompBg1Map[6144];
extern u16 gDecompBg2Map[6144];
extern u16 gDecompBg3Map[2048];

extern u8 gSpritesetEntryUsed;
extern u8 gScrollCounter;

struct Unk_3004e10 {
    s16 unk_0;
    s16 unk_2;
    s16 unk_4;
    s16 unk_6;
};

extern struct Unk_3004e10 gUnk_3004e10;

struct Unk_3004e20 {
    u8 unk_0;
    u16 unk_2;
    u16 unk_4;
    u16 unk_6;
};

extern struct Unk_3004e20 gUnk_3004e20;

struct Unk_3004e30 {
    u32 unk_0[2];
};

extern struct Unk_3004e30 gUnk_3004e30;

struct Unk_3004e4c {
    u8 unk_0[8]; // Padding
    s16 unk_8;
};

extern struct Unk_3004e4c gUnk_3004e4c;

#endif /* ROOM_STRUCTS_H */
