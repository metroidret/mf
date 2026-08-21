#include "types.h"
#include "macros.h"
#include "gba/display.h"

const u32 sSector5_Bg3_0[274] = {
    BGCNT_SIZE_512x256,
    _INCBIN_U32("data/rooms/sector_5/sector_5_bg3_0.tm.lz")
};

const u32 sSector5_Bg3_1[336] = {
    BGCNT_SIZE_512x256,
    _INCBIN_U32("data/rooms/sector_5/sector_5_bg3_1.tm.lz")
};

const u32 sBg0_Snowflakes[66] = {
    BGCNT_SIZE_256x256,
    _INCBIN_U32("data/rooms/sector_5/snowflakes_bg0.tm.lz")
};

const u32 sSector5_Bg3_2[359] = {
    BGCNT_SIZE_256x512,
    _INCBIN_U32("data/rooms/sector_5/sector_5_bg3_2.tm.lz")
};

const u32 sBg0_NightmareRoom[80] = {
    BGCNT_SIZE_256x256,
    _INCBIN_U32("data/rooms/sector_5/nightmare_room_bg0.tm.lz")
};

const u32 sBg0_NightmareSilhouette[180] = {
    BGCNT_SIZE_512x256,
    _INCBIN_U32("data/rooms/sector_5/nightmare_silhouette_bg0.tm.lz")
};
