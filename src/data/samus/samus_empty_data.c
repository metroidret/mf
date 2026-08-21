#include "data/samus/samus_empty_data.h"

const u8 sSamusGfx_Empty[SAMUS_GFX_SIZE(0, 0)] = {
    0, 0
};

const u16 sSamusOam_Empty[OAM_DATA_SIZE(0)] = {
    0
};

const s16 sArmCannonOffset_Empty[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(0),
    [ACO_X] = C_S9_2_S16(0)
};
