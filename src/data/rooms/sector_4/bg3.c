#include "types.h"
#include "macros.h"
#include "gba/display.h"

const u32 sBg0_Water[137] = {
    BGCNT_SIZE_256x512,
    _INCBIN_U32("data/rooms/sector_4/water_bg0.tm.lz")
};

const u32 sBg0_ElectrifiedWater[135] = {
    BGCNT_SIZE_256x512,
    _INCBIN_U32("data/rooms/sector_4/electrified_water_bg0.tm.lz")
};

const u32 sSector4_Bg3_0[278] = {
    BGCNT_SIZE_256x512,
    _INCBIN_U32("data/rooms/sector_4/sector_4_bg3_0.tm.lz")
};

const u32 sSector4_Bg3_1[313] = {
    BGCNT_SIZE_512x256,
    _INCBIN_U32("data/rooms/sector_4/sector_4_bg3_1.tm.lz")
};

const u32 sSector4_Bg3_2[194] = {
    BGCNT_SIZE_512x256,
    _INCBIN_U32("data/rooms/sector_4/sector_4_bg3_2.tm.lz")
};

const u32 sSector4_Bg3_3[453] = {
    BGCNT_SIZE_512x256,
    _INCBIN_U32("data/rooms/sector_4/sector_4_bg3_3.tm.lz")
};
