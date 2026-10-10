#include "data/menus/pause_debug.h"
#include "macros.h"
#include "gba.h"
#include "globals.h"

#include "constants/samus.h"

const u8 sPauseDebugBeamFlags[5] = {
    [0] = BF_CHARGE_BEAM,
    [1] = BF_WIDE_BEAM,
    [2] = BF_PLASMA_BEAM,
    [3] = BF_WAVE_BEAM,
    [4] = BF_ICE_BEAM,
};

const u8 sPauseDebugMissileFlags[4] = {
    [0] = MBF_MISSILES,
    [1] = MBF_SUPER_MISSILES,
    [2] = MBF_ICE_MISSILES,
    [3] = MBF_DIFFUSION_MISSILES,
};

const u8 sPauseDebugBombFlags[2] = {
    [0] = MBF_BOMBS,
    [1] = MBF_POWER_BOMBS,
};

const u8 sPauseDebugSuitFlags[2] = {
    [0] = SMF_VARIA_SUIT,
    [1] = SMF_GRAVITY_SUIT,
};

const u8 sPauseDebugMiscFlags[5] = {
    [0] = SMF_MORPH_BALL,
    [1] = SMF_HIGH_JUMP,
    [2] = SMF_SPEED_BOOSTER,
    [3] = SMF_SPACE_JUMP,
    [4] = SMF_SCREW_ATTACK,
};

const u8 sStatusScreenSectionSizes[5] = {
    [0] = ARRAY_SIZE(sPauseDebugBeamFlags),
    [1] = ARRAY_SIZE(sPauseDebugMissileFlags),
    [2] = ARRAY_SIZE(sPauseDebugBombFlags),
    [3] = ARRAY_SIZE(sPauseDebugSuitFlags),
    [4] = ARRAY_SIZE(sPauseDebugMiscFlags),
};

const u16 sPauseDebugNumbersIncrementValues[5] = {
    1, 10, 100, 1000, 10000,
};

const u16 sPauseDebugNumbersMaxValues[3] = {
    [PAUSE_DEBUG_AMMO_TYPE_HEALTH] = 2099,
    [PAUSE_DEBUG_AMMO_TYPE_MISSILES] = 255,
    [PAUSE_DEBUG_AMMO_TYPE_POWER_BOMBS] = 254,
};

const u8 sMinimap_576190[48] = {
    0x00, 0x01, 0x01, 0x0C, 0x0E, 0x05, 0x0C, 0x07,
    0x01, 0x01, 0x01, 0x01, 0x0C, 0x0C, 0x0C, 0x0C,
    0x00, 0x01, 0x0D, 0x0D, 0x0E, 0x05, 0x01, 0x07,
    0x08, 0x02, 0x0A, 0x07, 0x08, 0x02, 0x0A, 0x07,
    0x00, 0x01, 0x03, 0x03, 0x0E, 0x05, 0x01, 0x07,
    0x08, 0x02, 0x0A, 0x07, 0x08, 0x02, 0x0A, 0x07,
};

const u8 sMinimap_5761C0[48] = {
    0x00, 0x10, 0x10, 0xC0, 0xE0, 0x50, 0xC0, 0x70,
    0x10, 0x10, 0x10, 0x10, 0xC0, 0xC0, 0xC0, 0xC0,
    0x00, 0x10, 0xD0, 0xD0, 0xE0, 0x50, 0x10, 0x70,
    0x80, 0x20, 0xA0, 0x70, 0x80, 0x20, 0xA0, 0x70,
    0x00, 0x10, 0x30, 0x30, 0xE0, 0x50, 0x10, 0x70,
    0x80, 0x20, 0xA0, 0x70, 0x80, 0x20, 0xA0, 0x70,
};

const void* const sPauseScreen_5761f0[8] = {
    [0] = VRAM_OBJ + 0x3700 + 0x60 * 1,
    [1] = VRAM_OBJ + 0x3700 + 0x60 * 2,
    [2] = VRAM_OBJ + 0x3B00 + 0x60 * 1,
    [3] = VRAM_OBJ + 0x3B00 + 0x60 * 2,
    [4] = VRAM_OBJ + 0x3F00 + 0x60 * 1,
    [5] = VRAM_OBJ + 0x3F00 + 0x60 * 2,
    [6] = VRAM_OBJ + 0x3300 + 0x60 * 1,
    [7] = VRAM_OBJ + 0x3300 + 0x60 * 2,
};

const u8 sMaintainedInputDelays[7] = {
    15, 10, 6, 4, 4, 4, 2,
};
