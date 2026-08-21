#include "types.h"
#include "macros.h"
#include "gba/display.h"

const u32 sSector1_Bg3_0[351] = {
    BGCNT_SIZE_512x256,
    _INCBIN_U32("data/rooms/sector_1/sector_1_bg3_0.tm.lz")
};

const u32 sSector1_Bg3_1[348] = {
    BGCNT_SIZE_512x256,
    _INCBIN_U32("data/rooms/sector_1/sector_1_bg3_1.tm.lz")
};

const u32 sBg0_StabilizerRoomFog[178] = {
    BGCNT_SIZE_256x256,
    _INCBIN_U32("data/rooms/sector_1/stabilizer_room_fog_bg0.tm.lz")
};

const u32 sSector1_Bg3_2[306] = {
    BGCNT_SIZE_256x512,
    _INCBIN_U32("data/rooms/sector_1/sector_1_bg3_2.tm.lz")
};
