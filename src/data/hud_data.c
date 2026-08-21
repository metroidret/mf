#include "data/hud_data.h"

const u16 sCommonSpritesPal[6 * 16] = INCBIN_U16("data/hud/common.pal");
const u8 sCommonSpritesGfx[14 * 32 * 32] = INCBIN_U8("data/hud/common.gfx");

const u8 sMissileIconGfx[4 * 32] = INCBIN_U8("data/hud/missile_icon.gfx");
const u8 sPowerBombIconGfx[4 * 32] = INCBIN_U8("data/hud/power_bomb_icon.gfx");
const u8 sAmmoDigitsGfx[36 * 32] = INCBIN_U8("data/hud/ammo_digits.gfx");
const u8 sEnergyDigitsGfx[10 * 32] = INCBIN_U8("data/hud/energy_digits.gfx");
const u8 sEnergyTanksGfx_Full[5 * 256] = INCBIN_U8("data/hud/energy_tanks_full.gfx");
const u8 sEnergyTanksGfx_Empty[11 * 256] = INCBIN_U8("data/hud/energy_tanks_empty.gfx");
const u8 sEnergyTankGfx_OneFull[1 * 32] = INCBIN_U8("data/hud/energy_tank_one_full.gfx");
const u8 sEnergyTankGfx_OneFullOneEmpty[1 * 32] = INCBIN_U8("data/hud/energy_tank_one_full_one_empty.gfx");

const u16 sEscapeDigitsPal[3 * 16] = INCBIN_U16("data/hud/escape_timer_digits.pal");
const u8 sEscapeDigitsGfx[2048] = INCBIN_U8("data/hud/escape_timer_digits.gfx");

const u16 sEscapeDigitsOam[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(0, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 0x3c0, 15, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 0x3c0, 15, 0),
    OAM_ENTRY(16, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3ca, 15, 0),
    OAM_ENTRY(24, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 0x3c0, 15, 0),
    OAM_ENTRY(32, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 0x3c0, 15, 0),
    OAM_ENTRY(40, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3ea, 15, 0),
    OAM_ENTRY(48, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 0x3c0, 15, 0),
    OAM_ENTRY(56, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 0x3c0, 15, 0),
};

const struct FrameData sEscapeTimerFrameData[2] = {
    [0] = {
        .pFrame = sEscapeDigitsOam,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};
