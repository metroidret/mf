#include "types.h"
#include "macros.h"
#include "gba/display.h"

const u32 sSector6_Bg3_0[370] = {
    BGCNT_SIZE_512x256,
    _INCBIN_U32("data/rooms/sector_6/sector_6_bg3_0.tm.lz")
};

const u32 sSector6_Bg3_1[370] = {
    BGCNT_SIZE_512x256,
    _INCBIN_U32("data/rooms/sector_6/sector_6_bg3_1.tm.lz")
};

const u32 sSector6_Bg3_2[504] = {
    BGCNT_SIZE_512x256,
    _INCBIN_U32("data/rooms/sector_6/sector_6_bg3_2.tm.lz")
};

const u32 sSector6_Bg0_GreenRocksSpotlight[168] = {
    BGCNT_SIZE_512x256,
    _INCBIN_U32("data/rooms/sector_6/sector_6_green_rocks_spotlight_bg0.tm.lz")
};

const u32 sSector6_Bg0_CavesSpotlight[170] = {
    BGCNT_SIZE_512x256,
    _INCBIN_U32("data/rooms/sector_6/sector_6_caves_spotlight_bg0.tm.lz")
};

// Animated graphics, etc...
static const u8 sBlob_5594a8_575a60[] = INCBIN_U8("data/Blob_5594a8_575a60.bin");
