#include "macros.h"

#include "data/projectile_data.h"

const s16 sWaveBeamPartVelocity[16] = {
    24, 16, 8, 4,
    4, 8, 16, 24,
    32, 20, 8, 4,
    4, 8, 20, 32
};

const s16 sWaveBeamPartVelocity_Unused[16] = {
    24, 20, 16, 12,
    12, 8, 4, 0,
    0, 4, 8, 12,
    12, 16, 20, 24
};

const s16 sNormalMissileVelocity[7] = {
    4, 6, 8, 12,
    14, 16, 18
};

const s16 sSuperMissileVelocity[7] = {
    4, 6, 8, 12,
    16, 20, 24
};

const s16 sIceMissileVelocity[7] = {
    4, 8, 12, 16,
    20, 24, 28
};

const s16 sDiffusionMissileVelocity[7] = {
    8, 12, 16, 20,
    24, 28, 32
};

const s16 sTumblingMissileFallingVelocity[16] = {
    -12, -10, -8, -6,
    -4, -2, 0, 0,
    1, 2, 4, 8,
    12, 16, 20, SHORT_MAX
};

const u16 sNormalBeamPal[1 * 16] = INCBIN_U16("data/projectiles/normal_beam.pal");
const u16 sChargeBeamPal[1 * 16] = INCBIN_U16("data/projectiles/charge_beam.pal");
const u16 sWideBeamPal[1 * 16] = INCBIN_U16("data/projectiles/wide_beam.pal");
const u16 sPlasmaBeamPal[1 * 16] = INCBIN_U16("data/projectiles/plasma_beam.pal");
const u16 sWaveBeamPal[1 * 16] = INCBIN_U16("data/projectiles/wave_beam.pal");
const u16 sIceBeamPal[1 * 16] = INCBIN_U16("data/projectiles/ice_beam.pal");

const u8 sNormalBeamGfx_Top[20 * 32] = INCBIN_U8("data/projectiles/normal_beam_top.gfx");
const u8 sNormalBeamGfx_Bottom[20 * 32] = INCBIN_U8("data/projectiles/normal_beam_bottom.gfx");
const u8 sChargeBeamGfx_Top[20 * 32] = INCBIN_U8("data/projectiles/charge_beam_top.gfx");
const u8 sChargeBeamGfx_Bottom[20 * 32] = INCBIN_U8("data/projectiles/charge_beam_bottom.gfx");
const u8 sWideBeamGfx_Top[20 * 32] = INCBIN_U8("data/projectiles/wide_beam_top.gfx");
const u8 sWideBeamGfx_Bottom[20 * 32] = INCBIN_U8("data/projectiles/wide_beam_bottom.gfx");
const u8 sPlasmaBeamGfx_Top[20 * 32] = INCBIN_U8("data/projectiles/plasma_beam_top.gfx");
const u8 sPlasmaBeamGfx_Bottom[20 * 32] = INCBIN_U8("data/projectiles/plasma_beam_bottom.gfx");
const u8 sWaveBeamGfx_Top[20 * 32] = INCBIN_U8("data/projectiles/wave_beam_top.gfx");
const u8 sWaveBeamGfx_Bottom[20 * 32] = INCBIN_U8("data/projectiles/wave_beam_bottom.gfx");
const u8 sIceBeamGfx_Top[20 * 32] = INCBIN_U8("data/projectiles/ice_beam_top.gfx");
const u8 sIceBeamGfx_Bottom[20 * 32] = INCBIN_U8("data/projectiles/ice_beam_bottom.gfx");

const u8 sNormalMissileGfx_Top[4 * 32] = INCBIN_U8("data/projectiles/normal_missile_top.gfx");
const u8 sNormalMissileGfx_Bottom[4 * 32] = INCBIN_U8("data/projectiles/normal_missile_bottom.gfx");
const u8 sSuperMissileGfx_Top[4 * 32] = INCBIN_U8("data/projectiles/super_missile_top.gfx");
const u8 sSuperMissileGfx_Bottom[4 * 32] = INCBIN_U8("data/projectiles/super_missile_bottom.gfx");
const u8 sIceMissileGfx_Top[4 * 32] = INCBIN_U8("data/projectiles/ice_missile_top.gfx");
const u8 sIceMissileGfx_Bottom[4 * 32] = INCBIN_U8("data/projectiles/ice_missile_bottom.gfx");
const u8 sDiffusionMissileGfx_Top[4 * 32] = INCBIN_U8("data/projectiles/diffusion_missile_top.gfx");
const u8 sDiffusionMissileGfx_Bottom[4 * 32] = INCBIN_U8("data/projectiles/diffusion_missile_bottom.gfx");

static const u16 sNormalBeamOam_Horizontal_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 128, 2, 0),
};

static const u16 sNormalBeamOam_Horizontal_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-6, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 160, 2, 0),
};

static const u16 sNormalBeamOam_Diagonal_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 131, 2, 0),
};

static const u16 sNormalBeamOam_Diagonal_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-6, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 139, 2, 0),
};

static const u16 sNormalBeamOam_Vertical_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 130, 2, 0),
};

static const u16 sNormalBeamOam_Vertical_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -6, OAM_DIMS_8x16, OAM_NO_FLIP, 138, 2, 0),
};

static const u16 sChargedNormalBeamOam_Horizontal_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 136, 2, 0),
};

static const u16 sChargedNormalBeamOam_Horizontal_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-6, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 168, 2, 0),
};

static const u16 sChargedNormalBeamOam_Diagonal_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 134, 2, 0),
};

static const u16 sChargedNormalBeamOam_Diagonal_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-6, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 142, 2, 0),
};

static const u16 sChargedNormalBeamOam_Vertical_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 133, 2, 0),
};

static const u16 sChargedNormalBeamOam_Vertical_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -6, OAM_DIMS_8x16, OAM_NO_FLIP, 141, 2, 0),
};

static const u16 sParticleOam_ChargedNormalBeamTrail_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 144, 2, 0),
};

static const u16 sParticleOam_ChargedNormalBeamTrail_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 145, 2, 0),
};

static const u16 sParticleOam_ChargedNormalBeamTrail_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 146, 2, 0),
};

static const u16 sParticleOam_ChargedNormalBeamTrail_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 147, 2, 0),
};

static const u16 sParticleOam_ChargedNormalBeamTrail_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 179, 2, 0),
};

const struct FrameData sNormalBeamOam_Horizontal[3] = {
    [0] = {
        .pFrame = sNormalBeamOam_Horizontal_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sNormalBeamOam_Horizontal_Frame1,
        .timer = 4
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sNormalBeamOam_Diagonal[3] = {
    [0] = {
        .pFrame = sNormalBeamOam_Diagonal_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sNormalBeamOam_Diagonal_Frame1,
        .timer = 4
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sNormalBeamOam_Vertical[3] = {
    [0] = {
        .pFrame = sNormalBeamOam_Vertical_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sNormalBeamOam_Vertical_Frame1,
        .timer = 4
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedNormalBeamOam_Horizontal[3] = {
    [0] = {
        .pFrame = sChargedNormalBeamOam_Horizontal_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sChargedNormalBeamOam_Horizontal_Frame1,
        .timer = 4
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedNormalBeamOam_Diagonal[3] = {
    [0] = {
        .pFrame = sChargedNormalBeamOam_Diagonal_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sChargedNormalBeamOam_Diagonal_Frame1,
        .timer = 4
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedNormalBeamOam_Vertical[3] = {
    [0] = {
        .pFrame = sChargedNormalBeamOam_Vertical_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sChargedNormalBeamOam_Vertical_Frame1,
        .timer = 4
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_ChargedNormalBeamTrail[6] = {
    [0] = {
        .pFrame = sParticleOam_ChargedNormalBeamTrail_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sParticleOam_ChargedNormalBeamTrail_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sParticleOam_ChargedNormalBeamTrail_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sParticleOam_ChargedNormalBeamTrail_Frame3,
        .timer = 2
    },
    [4] = {
        .pFrame = sParticleOam_ChargedNormalBeamTrail_Frame4,
        .timer = 2
    },
    [5] = FRAME_DATA_TERMINATOR
};

static const u16 sChargeBeamOam_SingleHorizontal_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 146, 2, 0),
};

static const u16 sOam_58d874[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 178, 2, 0),
};

static const u16 sChargeBeamOam_SingleDiagonal_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 146, 2, 0),
};

static const u16 sOam_58d884[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 178, 2, 0),
};

static const u16 sChargeBeamOam_SingleVertical_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 146, 2, 0),
};

static const u16 sOam_58d894[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 178, 2, 0),
};

static const u16 sChargeBeamOam_DoubleHorizontal_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 128, 2, 0),
};

static const u16 sChargeBeamOam_DoubleHorizontal_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-2, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 138, 2, 0),
};

static const u16 sChargeBeamOam_DoubleDiagonal_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-6, -6, OAM_DIMS_16x8, OAM_NO_FLIP, 129, 2, 0),
    OAM_ENTRY(-6, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 161, 2, 0),
};

static const u16 sChargeBeamOam_DoubleDiagonal_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 139, 2, 0),
    OAM_ENTRY(-4, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 171, 2, 0),
};

static const u16 sChargeBeamOam_DoubleVertical_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 131, 2, 0),
};

static const u16 sChargeBeamOam_DoubleVertical_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 163, 2, 0),
};

static const u16 sChargedChargeBeamOam_DoubleHorizontal_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 133, 2, 0),
    OAM_ENTRY(-1, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 133, 2, 0),
    OAM_ENTRY(6, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 141, 2, 0),
};

static const u16 sChargedChargeBeamOam_DoubleHorizontal_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 141, 2, 0),
    OAM_ENTRY(7, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 141, 2, 0),
    OAM_ENTRY(14, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 141, 2, 0),
};

static const u16 sChargedChargeBeamOam_DoubleDiagonal_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-10, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 134, 2, 0),
    OAM_ENTRY(-5, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 134, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 134, 2, 0),
};

static const u16 sChargedChargeBeamOam_DoubleDiagonal_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-6, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 142, 2, 0),
    OAM_ENTRY(-1, -1, OAM_DIMS_16x16, OAM_NO_FLIP, 142, 2, 0),
    OAM_ENTRY(4, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 142, 2, 0),
};

static const u16 sChargedChargeBeamOam_DoubleVertical_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 136, 2, 0),
    OAM_ENTRY(-8, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 136, 2, 0),
    OAM_ENTRY(-8, 6, OAM_DIMS_16x8, OAM_NO_FLIP, 136, 2, 0),
};

static const u16 sChargedChargeBeamOam_DoubleVertical_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 144, 2, 0),
    OAM_ENTRY(-8, 5, OAM_DIMS_16x8, OAM_NO_FLIP, 144, 2, 0),
    OAM_ENTRY(-8, 12, OAM_DIMS_16x8, OAM_NO_FLIP, 144, 2, 0),
};

static const u16 sChargedChargeBeamOam_SingleHorizontal_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 147, 2, 0),
};

static const u16 sChargedChargeBeamOam_SingleDiagonal_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 147, 2, 0),
};

static const u16 sOam_58d960[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 147, 2, 0),
};

static const u16 sParticleOam_ChargedChargeBeamTrail_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 162, 2, 0),
};

static const u16 sParticleOam_ChargedChargeBeamTrail_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 168, 2, 0),
};

static const u16 sParticleOam_ChargedChargeBeamTrail_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 172, 2, 0),
};

static const u16 sParticleOam_ChargedChargeBeamTrail_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 179, 2, 0),
};

static const u16 sParticleOam_ChargedChargeBeamTrail_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 178, 2, 0),
};

const struct FrameData sChargeBeamOam_DoubleHorizontal[3] = {
    [0] = {
        .pFrame = sChargeBeamOam_DoubleHorizontal_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sChargeBeamOam_DoubleHorizontal_Frame1,
        .timer = 4
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargeBeamOam_DoubleDiagonal[3] = {
    [0] = {
        .pFrame = sChargeBeamOam_DoubleDiagonal_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sChargeBeamOam_DoubleDiagonal_Frame1,
        .timer = 4
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargeBeamOam_DoubleVertical[3] = {
    [0] = {
        .pFrame = sChargeBeamOam_DoubleVertical_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sChargeBeamOam_DoubleVertical_Frame1,
        .timer = 4
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargeBeamOam_SingleHorizontal[2] = {
    [0] = {
        .pFrame = sChargeBeamOam_SingleHorizontal_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargeBeamOam_SingleDiagonal[2] = {
    [0] = {
        .pFrame = sChargeBeamOam_SingleDiagonal_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargeBeamOam_SingleVertical[2] = {
    [0] = {
        .pFrame = sChargeBeamOam_SingleVertical_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedChargeBeamOam_DoubleHorizontal[3] = {
    [0] = {
        .pFrame = sChargedChargeBeamOam_DoubleHorizontal_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sChargedChargeBeamOam_DoubleHorizontal_Frame1,
        .timer = 4
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedChargeBeamOam_DoubleDiagonal[3] = {
    [0] = {
        .pFrame = sChargedChargeBeamOam_DoubleDiagonal_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sChargedChargeBeamOam_DoubleDiagonal_Frame1,
        .timer = 4
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedChargeBeamOam_DoubleVertical[3] = {
    [0] = {
        .pFrame = sChargedChargeBeamOam_DoubleVertical_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sChargedChargeBeamOam_DoubleVertical_Frame1,
        .timer = 4
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedChargeBeamOam_SingleHorizontal[2] = {
    [0] = {
        .pFrame = sChargedChargeBeamOam_SingleHorizontal_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedChargeBeamOam_SingleDiagonal[2] = {
    [0] = {
        .pFrame = sChargedChargeBeamOam_SingleDiagonal_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedChargeBeamOam_SingleVertical[2] = {
    [0] = {
        .pFrame = sChargedChargeBeamOam_SingleDiagonal_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_ChargedChargeBeamTrail[6] = {
    [0] = {
        .pFrame = sParticleOam_ChargedChargeBeamTrail_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sParticleOam_ChargedChargeBeamTrail_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sParticleOam_ChargedChargeBeamTrail_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sParticleOam_ChargedChargeBeamTrail_Frame3,
        .timer = 6
    },
    [4] = {
        .pFrame = sParticleOam_ChargedChargeBeamTrail_Frame4,
        .timer = 6
    },
    [5] = FRAME_DATA_TERMINATOR
};

static const u16 sWideBeamOam_Horizontal_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 128, 2, 0),
};

static const u16 sWideBeamOam_Horizontal_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 129, 2, 0),
};

static const u16 sWideBeamOam_Horizontal_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 130, 2, 0),
};

static const u16 sWideBeamOam_Diagonal_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-6, -6, OAM_DIMS_16x8, OAM_NO_FLIP, 131, 2, 0),
    OAM_ENTRY(-6, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 163, 2, 0),
};

static const u16 sWideBeamOam_Diagonal_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-6, -6, OAM_DIMS_16x8, OAM_NO_FLIP, 133, 2, 0),
    OAM_ENTRY(-6, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 164, 2, 0),
};

static const u16 sWideBeamOam_Diagonal_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-6, -6, OAM_DIMS_16x8, OAM_NO_FLIP, 135, 2, 0),
    OAM_ENTRY(-6, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 165, 2, 0),
};

static const u16 sWideBeamOam_Vertical_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 166, 2, 0),
};

static const u16 sWideBeamOam_Vertical_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 137, 2, 0),
};

static const u16 sWideBeamOam_Vertical_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 169, 2, 0),
};

static const u16 sChargedWideBeamOam_Horizontal_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 139, 2, 0),
};

static const u16 sChargedWideBeamOam_Horizontal_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-3, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 139, 2, 0),
};

static const u16 sChargedWideBeamOam_Diagonal_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 140, 2, 0),
};

static const u16 sChargedWideBeamOam_Diagonal_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-7, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 140, 2, 0),
};

static const u16 sChargedWideBeamOam_Vertical_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 142, 2, 0),
};

static const u16 sChargedWideBeamOam_Vertical_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -3, OAM_DIMS_16x8, OAM_NO_FLIP, 142, 2, 0),
};

static const u16 sOam_58dc84_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 168, 2, 0),
};

static const u16 sOam_58dc94_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 144, 2, 0),
};

static const u16 sOam_58dca4_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 145, 2, 0),
};

static const u16 sOam_58dcb4_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 174, 2, 0),
};

static const u16 sOam_58dcc4_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 175, 2, 0),
};

static const u16 sOam_58dcd4_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 146, 2, 0),
};

static const u16 sParticleOam_ChargedWideBeamTrail_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 147, 2, 0),
};

static const u16 sParticleOam_ChargedWideBeamTrail_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 176, 2, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 176, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 176, 2, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 176, 2, 0),
};

static const u16 sParticleOam_ChargedWideBeamTrail_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 177, 2, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 177, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 177, 2, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 177, 2, 0),
};

static const u16 sParticleOam_ChargedWideBeamTrail_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 178, 2, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 178, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 178, 2, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 178, 2, 0),
};

static const u16 sParticleOam_ChargedWideBeamTrail_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 179, 2, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 179, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 179, 2, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 179, 2, 0),
};

const struct FrameData sWideBeamOam_Horizontal[4] = {
    [0] = {
        .pFrame = sWideBeamOam_Horizontal_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sWideBeamOam_Horizontal_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sWideBeamOam_Horizontal_Frame2,
        .timer = 4
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sWideBeamOam_Diagonal[4] = {
    [0] = {
        .pFrame = sWideBeamOam_Diagonal_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sWideBeamOam_Diagonal_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sWideBeamOam_Diagonal_Frame2,
        .timer = 4
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sWideBeamOam_Vertical[4] = {
    [0] = {
        .pFrame = sWideBeamOam_Vertical_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sWideBeamOam_Vertical_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sWideBeamOam_Vertical_Frame2,
        .timer = 4
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedWideBeamOam_Horizontal[3] = {
    [0] = {
        .pFrame = sChargedWideBeamOam_Horizontal_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sChargedWideBeamOam_Horizontal_Frame1,
        .timer = 2
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedWideBeamOam_Diagonal[3] = {
    [0] = {
        .pFrame = sChargedWideBeamOam_Diagonal_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sChargedWideBeamOam_Diagonal_Frame1,
        .timer = 2
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedWideBeamOam_Vertical[3] = {
    [0] = {
        .pFrame = sChargedWideBeamOam_Vertical_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sChargedWideBeamOam_Vertical_Frame1,
        .timer = 2
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_58dc84[2] = {
    [0] = {
        .pFrame = sOam_58dc84_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_58dc94[2] = {
    [0] = {
        .pFrame = sOam_58dc94_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_58dca4[2] = {
    [0] = {
        .pFrame = sOam_58dca4_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_58dcb4[2] = {
    [0] = {
        .pFrame = sOam_58dcb4_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_58dcc4[2] = {
    [0] = {
        .pFrame = sOam_58dcc4_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_58dcd4[2] = {
    [0] = {
        .pFrame = sOam_58dcd4_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_ChargedWideBeamTrail[6] = {
    [0] = {
        .pFrame = sParticleOam_ChargedWideBeamTrail_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sParticleOam_ChargedWideBeamTrail_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sParticleOam_ChargedWideBeamTrail_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sParticleOam_ChargedWideBeamTrail_Frame3,
        .timer = 2
    },
    [4] = {
        .pFrame = sParticleOam_ChargedWideBeamTrail_Frame4,
        .timer = 2
    },
    [5] = FRAME_DATA_TERMINATOR
};

static const u16 sPlasmaBeamOam_Horizontal_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 128, 2, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_16x8, OAM_X_FLIP, 128, 2, 0),
};

static const u16 sPlasmaBeamOam_Horizontal_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 160, 2, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_16x8, OAM_X_FLIP, 160, 2, 0),
};

static const u16 sPlasmaBeamOam_Diagonal_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-14, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 130, 2, 0),
    OAM_ENTRY(-2, -2, OAM_DIMS_16x16, OAM_XY_FLIP, 130, 2, 0),
};

static const u16 sPlasmaBeamOam_Diagonal_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-14, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 134, 2, 0),
    OAM_ENTRY(-2, -2, OAM_DIMS_16x16, OAM_XY_FLIP, 134, 2, 0),
};

static const u16 sPlasmaBeamOam_Vertical_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 132, 2, 0),
    OAM_ENTRY(-4, 0, OAM_DIMS_8x16, OAM_Y_FLIP, 132, 2, 0),
};

static const u16 sPlasmaBeamOam_Vertical_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 133, 2, 0),
    OAM_ENTRY(-4, 0, OAM_DIMS_8x16, OAM_Y_FLIP, 133, 2, 0),
};

static const u16 sChargedPlasmaBeamOam_Horizontal_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 136, 2, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_16x8, OAM_X_FLIP, 136, 2, 0),
};

static const u16 sChargedPlasmaBeamOam_Horizontal_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 168, 2, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_16x8, OAM_X_FLIP, 168, 2, 0),
};

static const u16 sChargedPlasmaBeamOam_Diagonal_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-13, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 138, 2, 0),
    OAM_ENTRY(-3, -3, OAM_DIMS_16x16, OAM_XY_FLIP, 138, 2, 0),
};

static const u16 sChargedPlasmaBeamOam_Diagonal_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-13, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 141, 2, 0),
    OAM_ENTRY(-3, -3, OAM_DIMS_16x16, OAM_XY_FLIP, 141, 2, 0),
};

static const u16 sChargedPlasmaBeamOam_Vertical_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 140, 2, 0),
    OAM_ENTRY(-4, 0, OAM_DIMS_8x16, OAM_Y_FLIP, 140, 2, 0),
};

static const u16 sChargedPlasmaBeamOam_Vertical_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 143, 2, 0),
    OAM_ENTRY(-4, 0, OAM_DIMS_8x16, OAM_Y_FLIP, 143, 2, 0),
};

static const u16 sParticleOam_ChargedPlasmaBeamTrail_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 144, 2, 0),
};

static const u16 sParticleOam_ChargedPlasmaBeamTrail_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 145, 2, 0),
};

static const u16 sParticleOam_ChargedPlasmaBeamTrail_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 146, 2, 0),
};

static const u16 sParticleOam_ChargedPlasmaBeamTrail_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 147, 2, 0),
};

static const u16 sParticleOam_ChargedPlasmaBeamTrail_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 176, 2, 0),
};

static const u16 sParticleOam_ChargedPlasmaBeamTrail_Frame5[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 177, 2, 0),
};

static const u16 sParticleOam_ChargedPlasmaBeamTrail_Frame6[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 178, 2, 0),
};

const struct FrameData sPlasmaBeamOam_Horizontal[3] = {
    [0] = {
        .pFrame = sPlasmaBeamOam_Horizontal_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sPlasmaBeamOam_Horizontal_Frame1,
        .timer = 3
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPlasmaBeamOam_Diagonal[3] = {
    [0] = {
        .pFrame = sPlasmaBeamOam_Diagonal_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sPlasmaBeamOam_Diagonal_Frame1,
        .timer = 3
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPlasmaBeamOam_Vertical[3] = {
    [0] = {
        .pFrame = sPlasmaBeamOam_Vertical_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sPlasmaBeamOam_Vertical_Frame1,
        .timer = 3
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedPlasmaBeamOam_Horizontal[3] = {
    [0] = {
        .pFrame = sChargedPlasmaBeamOam_Horizontal_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sChargedPlasmaBeamOam_Horizontal_Frame1,
        .timer = 2
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedPlasmaBeamOam_Diagonal[3] = {
    [0] = {
        .pFrame = sChargedPlasmaBeamOam_Diagonal_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sChargedPlasmaBeamOam_Diagonal_Frame1,
        .timer = 2
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedPlasmaBeamOam_Vertical[3] = {
    [0] = {
        .pFrame = sChargedPlasmaBeamOam_Vertical_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sChargedPlasmaBeamOam_Vertical_Frame1,
        .timer = 2
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_ChargedPlasmaBeamTrail[8] = {
    [0] = {
        .pFrame = sParticleOam_ChargedPlasmaBeamTrail_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sParticleOam_ChargedPlasmaBeamTrail_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sParticleOam_ChargedPlasmaBeamTrail_Frame2,
        .timer = 3
    },
    [3] = {
        .pFrame = sParticleOam_ChargedPlasmaBeamTrail_Frame3,
        .timer = 3
    },
    [4] = {
        .pFrame = sParticleOam_ChargedPlasmaBeamTrail_Frame4,
        .timer = 3
    },
    [5] = {
        .pFrame = sParticleOam_ChargedPlasmaBeamTrail_Frame5,
        .timer = 3
    },
    [6] = {
        .pFrame = sParticleOam_ChargedPlasmaBeamTrail_Frame6,
        .timer = 3
    },
    [7] = FRAME_DATA_TERMINATOR
};

static const u16 sWaveBeamOam_Horizontal_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 128, 2, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 128, 2, 0),
};

static const u16 sWaveBeamOam_Diagonal_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-14, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 130, 2, 0),
    OAM_ENTRY(-2, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 130, 2, 0),
};

static const u16 sWaveBeamOam_Vertical_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 132, 2, 0),
    OAM_ENTRY(-4, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 132, 2, 0),
};

static const u16 sChargedWaveBeamOam_Horizontal_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(0, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 135, 2, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 135, 2, 0),
};

static const u16 sChargedWaveBeamOam_Horizontal_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 167, 2, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 167, 2, 0),
};

static const u16 sChargedWaveBeamOam_Diagonal_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-14, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 137, 2, 0),
    OAM_ENTRY(-2, -2, OAM_DIMS_16x16, OAM_XY_FLIP, 137, 2, 0),
};

static const u16 sChargedWaveBeamOam_Diagonal_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-2, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 139, 2, 0),
    OAM_ENTRY(-14, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 139, 2, 0),
};

static const u16 sChargedWaveBeamOam_Vertical_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 134, 2, 0),
    OAM_ENTRY(-4, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 134, 2, 0),
};

static const u16 sChargedWaveBeamOam_Vertical_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 133, 2, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 133, 2, 0),
};

static const u16 sParticleOam_ChargedWaveBeamTrail_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 141, 2, 0),
};

static const u16 sParticleOam_ChargedWaveBeamTrail_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 142, 2, 0),
};

static const u16 sParticleOam_ChargedWaveBeamTrail_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 144, 2, 0),
};

static const u16 sParticleOam_ChargedWaveBeamTrail_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 146, 2, 0),
};

const struct FrameData sWaveBeamOam_Horizontal[2] = {
    [0] = {
        .pFrame = sWaveBeamOam_Horizontal_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sWaveBeamOam_Diagonal[2] = {
    [0] = {
        .pFrame = sWaveBeamOam_Diagonal_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sWaveBeamOam_Vertical[2] = {
    [0] = {
        .pFrame = sWaveBeamOam_Vertical_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedWaveBeamOam_Horizontal[3] = {
    [0] = {
        .pFrame = sChargedWaveBeamOam_Horizontal_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sChargedWaveBeamOam_Horizontal_Frame1,
        .timer = 2
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedWaveBeamOam_Diagonal[3] = {
    [0] = {
        .pFrame = sChargedWaveBeamOam_Diagonal_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sChargedWaveBeamOam_Diagonal_Frame1,
        .timer = 2
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedWaveBeamOam_Vertical[3] = {
    [0] = {
        .pFrame = sChargedWaveBeamOam_Vertical_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sChargedWaveBeamOam_Vertical_Frame1,
        .timer = 2
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_ChargedWaveBeamTrail[5] = {
    [0] = {
        .pFrame = sParticleOam_ChargedWaveBeamTrail_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sParticleOam_ChargedWaveBeamTrail_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sParticleOam_ChargedWaveBeamTrail_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sParticleOam_ChargedWaveBeamTrail_Frame3,
        .timer = 4
    },
    [4] = FRAME_DATA_TERMINATOR
};

static const u16 sIceBeamOam_Horizontal_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-12, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 128, 2, 0),
    OAM_ENTRY(4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 160, 2, 0),
};

static const u16 sIceBeamOam_Diagonal_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-9, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 130, 2, 0),
    OAM_ENTRY(4, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 161, 2, 0),
};

static const u16 sIceBeamOam_Vertical_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -12, OAM_DIMS_8x16, OAM_NO_FLIP, 132, 2, 0),
    OAM_ENTRY(-4, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 133, 2, 0),
};

static const u16 sChargedIceBeamOam_Horizontal_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 134, 2, 0),
};

static const u16 sChargedIceBeamOam_Diagonal_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 136, 2, 0),
};

static const u16 sChargedIceBeamOam_Vertical_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 138, 2, 0),
};

static const u16 sParticleOam_IceBeamTrail_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 140, 2, 0),
};

static const u16 sParticleOam_IceBeamTrail_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 141, 2, 0),
};

static const u16 sParticleOam_IceBeamTrail_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 142, 2, 0),
};

static const u16 sParticleOam_IceBeamTrail_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 143, 2, 0),
};

static const u16 sParticleOam_IceBeamTrail_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 144, 2, 0),
};

static const u16 sParticleOam_IceBeamTrail_Frame5[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -1, OAM_DIMS_8x8, OAM_NO_FLIP, 145, 2, 0),
};

static const u16 sParticleOam_IceBeamTrail_Frame6[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 146, 2, 0),
};

static const u16 sOam_58e2b8_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 140, 2, 0),
};

static const u16 sOam_58e2b8_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -1, OAM_DIMS_8x8, OAM_NO_FLIP, 141, 2, 0),
    OAM_ENTRY(-1, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 140, 2, 0),
};

static const u16 sOam_58e2b8_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -1, OAM_DIMS_8x8, OAM_NO_FLIP, 142, 2, 0),
    OAM_ENTRY(0, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 141, 2, 0),
    OAM_ENTRY(-7, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 140, 2, 0),
};

static const u16 sOam_58e2b8_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 143, 2, 0),
    OAM_ENTRY(0, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 142, 2, 0),
    OAM_ENTRY(-7, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 141, 2, 0),
};

static const u16 sOam_58e2b8_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 144, 2, 0),
    OAM_ENTRY(0, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 143, 2, 0),
    OAM_ENTRY(-7, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 142, 2, 0),
};

static const u16 sOam_58e2b8_Frame5[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 145, 2, 0),
    OAM_ENTRY(0, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 144, 2, 0),
    OAM_ENTRY(-7, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 143, 2, 0),
};

static const u16 sOam_58e2b8_Frame6[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 146, 2, 0),
    OAM_ENTRY(1, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 145, 2, 0),
    OAM_ENTRY(-7, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 144, 2, 0),
};

static const u16 sOam_58e2b8_Frame7[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(1, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 146, 2, 0),
    OAM_ENTRY(-7, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 145, 2, 0),
};

static const u16 sOam_58e2b8_Frame8[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-7, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 146, 2, 0),
};

static const u16 sOam_58e308_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 172, 2, 0),
};

static const u16 sOam_58e308_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -1, OAM_DIMS_8x8, OAM_NO_FLIP, 173, 2, 0),
    OAM_ENTRY(-1, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 172, 2, 0),
};

static const u16 sOam_58e308_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -1, OAM_DIMS_8x8, OAM_NO_FLIP, 174, 2, 0),
    OAM_ENTRY(0, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 173, 2, 0),
    OAM_ENTRY(-7, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 172, 2, 0),
};

static const u16 sOam_58e308_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -1, OAM_DIMS_8x8, OAM_NO_FLIP, 175, 2, 0),
    OAM_ENTRY(0, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 174, 2, 0),
    OAM_ENTRY(-7, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 173, 2, 0),
};

static const u16 sOam_58e308_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -1, OAM_DIMS_8x8, OAM_NO_FLIP, 176, 2, 0),
    OAM_ENTRY(0, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 175, 2, 0),
    OAM_ENTRY(-7, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 174, 2, 0),
};

static const u16 sOam_58e308_Frame5[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -1, OAM_DIMS_8x8, OAM_NO_FLIP, 177, 2, 0),
    OAM_ENTRY(0, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 176, 2, 0),
    OAM_ENTRY(-7, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 175, 2, 0),
};

static const u16 sOam_58e308_Frame6[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -1, OAM_DIMS_8x8, OAM_NO_FLIP, 178, 2, 0),
    OAM_ENTRY(1, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 177, 2, 0),
    OAM_ENTRY(-7, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 176, 2, 0),
};

static const u16 sOam_58e308_Frame7[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(1, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 178, 2, 0),
    OAM_ENTRY(-7, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 177, 2, 0),
};

static const u16 sOam_58e308_Frame8[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-7, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 178, 2, 0),
};

static const u16 sParticleOam_ChargedIceBeamTrail_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 172, 2, 0),
};

static const u16 sParticleOam_ChargedIceBeamTrail_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 173, 2, 0),
};

static const u16 sParticleOam_ChargedIceBeamTrail_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 174, 2, 0),
};

static const u16 sParticleOam_ChargedIceBeamTrail_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 175, 2, 0),
};

static const u16 sParticleOam_ChargedIceBeamTrail_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 176, 2, 0),
};

static const u16 sParticleOam_ChargedIceBeamTrail_Frame5[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -1, OAM_DIMS_8x8, OAM_NO_FLIP, 177, 2, 0),
};

static const u16 sParticleOam_ChargedIceBeamTrail_Frame6[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 178, 2, 0),
};

const struct FrameData sIceBeamOam_Horizontal[2] = {
    [0] = {
        .pFrame = sIceBeamOam_Horizontal_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIceBeamOam_Diagonal[2] = {
    [0] = {
        .pFrame = sIceBeamOam_Diagonal_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIceBeamOam_Vertical[2] = {
    [0] = {
        .pFrame = sIceBeamOam_Vertical_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedIceBeamOam_Horizontal[2] = {
    [0] = {
        .pFrame = sChargedIceBeamOam_Horizontal_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedIceBeamOam_Diagonal[2] = {
    [0] = {
        .pFrame = sChargedIceBeamOam_Diagonal_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedIceBeamOam_Vertical[2] = {
    [0] = {
        .pFrame = sChargedIceBeamOam_Vertical_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_IceBeamTrail[8] = {
    [0] = {
        .pFrame = sParticleOam_IceBeamTrail_Frame0,
        .timer = 5
    },
    [1] = {
        .pFrame = sParticleOam_IceBeamTrail_Frame1,
        .timer = 5
    },
    [2] = {
        .pFrame = sParticleOam_IceBeamTrail_Frame2,
        .timer = 5
    },
    [3] = {
        .pFrame = sParticleOam_IceBeamTrail_Frame3,
        .timer = 5
    },
    [4] = {
        .pFrame = sParticleOam_IceBeamTrail_Frame4,
        .timer = 5
    },
    [5] = {
        .pFrame = sParticleOam_IceBeamTrail_Frame5,
        .timer = 5
    },
    [6] = {
        .pFrame = sParticleOam_IceBeamTrail_Frame6,
        .timer = 5
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_ChargedIceBeamTrail[8] = {
    [0] = {
        .pFrame = sParticleOam_ChargedIceBeamTrail_Frame0,
        .timer = 5
    },
    [1] = {
        .pFrame = sParticleOam_ChargedIceBeamTrail_Frame1,
        .timer = 5
    },
    [2] = {
        .pFrame = sParticleOam_ChargedIceBeamTrail_Frame2,
        .timer = 5
    },
    [3] = {
        .pFrame = sParticleOam_ChargedIceBeamTrail_Frame3,
        .timer = 5
    },
    [4] = {
        .pFrame = sParticleOam_ChargedIceBeamTrail_Frame4,
        .timer = 5
    },
    [5] = {
        .pFrame = sParticleOam_ChargedIceBeamTrail_Frame5,
        .timer = 5
    },
    [6] = {
        .pFrame = sParticleOam_ChargedIceBeamTrail_Frame6,
        .timer = 5
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_58e2b8[10] = {
    [0] = {
        .pFrame = sOam_58e2b8_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sOam_58e2b8_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sOam_58e2b8_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sOam_58e2b8_Frame3,
        .timer = 8
    },
    [4] = {
        .pFrame = sOam_58e2b8_Frame4,
        .timer = 8
    },
    [5] = {
        .pFrame = sOam_58e2b8_Frame5,
        .timer = 8
    },
    [6] = {
        .pFrame = sOam_58e2b8_Frame6,
        .timer = 8
    },
    [7] = {
        .pFrame = sOam_58e2b8_Frame7,
        .timer = 8
    },
    [8] = {
        .pFrame = sOam_58e2b8_Frame8,
        .timer = 8
    },
    [9] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_58e308[10] = {
    [0] = {
        .pFrame = sOam_58e308_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sOam_58e308_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sOam_58e308_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sOam_58e308_Frame3,
        .timer = 8
    },
    [4] = {
        .pFrame = sOam_58e308_Frame4,
        .timer = 8
    },
    [5] = {
        .pFrame = sOam_58e308_Frame5,
        .timer = 8
    },
    [6] = {
        .pFrame = sOam_58e308_Frame6,
        .timer = 8
    },
    [7] = {
        .pFrame = sOam_58e308_Frame7,
        .timer = 8
    },
    [8] = {
        .pFrame = sOam_58e308_Frame8,
        .timer = 8
    },
    [9] = FRAME_DATA_TERMINATOR
};

static const u16 sNormalSuperMissileOam_Horizontal_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 156, 3, 0),
    OAM_ENTRY(4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 202, 3, 0),
};

static const u16 sNormalSuperMissileOam_Horizontal_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 156, 3, 0),
    OAM_ENTRY(7, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 365, 3, 0),
};

static const u16 sNormalSuperMissileOam_Diagonal_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 158, 3, 0),
    OAM_ENTRY(1, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 202, 3, 0),
};

static const u16 sNormalSuperMissileOam_Diagonal_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 158, 3, 0),
    OAM_ENTRY(3, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 327, 3, 0),
};

static const u16 sNormalSuperMissileOam_Vertical_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 188, 3, 0),
    OAM_ENTRY(-4, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 189, 3, 0),
    OAM_ENTRY(-4, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 202, 3, 0),
};

static const u16 sNormalSuperMissileOam_Vertical_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 188, 3, 0),
    OAM_ENTRY(-4, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 189, 3, 0),
    OAM_ENTRY(-4, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 364, 3, 0),
};

static const u16 sParticleOam_SuperMissileTrail_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 323, 3, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 323, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 323, 3, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 323, 3, 0),
};

static const u16 sParticleOam_SuperMissileTrail_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 324, 3, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 324, 3, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 324, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 324, 3, 0),
};

static const u16 sParticleOam_SuperMissileTrail_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 325, 3, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 325, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 325, 3, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 325, 3, 0),
};

static const u16 sParticleOam_SuperMissileTrail_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 326, 3, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 326, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 326, 3, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 326, 3, 0),
};

static const u16 sParticleOam_SuperMissileTrail_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 344, 3, 0),
};

static const u16 sParticleOam_SuperMissileTrail_Frame5[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 345, 3, 0),
};

static const u16 sParticleOam_SuperMissileTrail_Frame6[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-3, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 346, 3, 0),
};

static const u16 sParticleOam_SuperMissileTrail_Frame7[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
};

static const u16 sParticleOam_SuperMissileTrail_Frame8[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-3, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
};

static const u16 sIceMissileOam_Horizontal_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 156, 3, 0),
    OAM_ENTRY(4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 229, 4, 0),
    OAM_ENTRY(10, -8, OAM_DIMS_8x8, OAM_X_FLIP, 229, 4, 0),
    OAM_ENTRY(10, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 229, 4, 0),
    OAM_ENTRY(4, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 229, 4, 0),
};

static const u16 sIceMissileOam_Horizontal_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 156, 3, 0),
    OAM_ENTRY(12, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 365, 4, 0),
    OAM_ENTRY(6, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 203, 4, 0),
};

static const u16 sIceMissileOam_Diagonal_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 158, 3, 0),
    OAM_ENTRY(1, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 229, 4, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_8x8, OAM_X_FLIP, 229, 4, 0),
    OAM_ENTRY(7, 7, OAM_DIMS_8x8, OAM_XY_FLIP, 229, 4, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_8x8, OAM_Y_FLIP, 229, 4, 0),
};

static const u16 sIceMissileOam_Diagonal_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 158, 3, 0),
    OAM_ENTRY(7, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 327, 4, 0),
    OAM_ENTRY(2, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 203, 4, 0),
};

static const u16 sIceMissileOam_Vertical_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 188, 3, 0),
    OAM_ENTRY(-4, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 189, 3, 0),
    OAM_ENTRY(-8, 5, OAM_DIMS_8x8, OAM_NO_FLIP, 229, 4, 0),
    OAM_ENTRY(0, 5, OAM_DIMS_8x8, OAM_X_FLIP, 229, 4, 0),
    OAM_ENTRY(0, 11, OAM_DIMS_8x8, OAM_XY_FLIP, 229, 4, 0),
    OAM_ENTRY(-8, 11, OAM_DIMS_8x8, OAM_Y_FLIP, 229, 4, 0),
};

static const u16 sIceMissileOam_Vertical_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 188, 3, 0),
    OAM_ENTRY(-4, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 189, 3, 0),
    OAM_ENTRY(-4, 13, OAM_DIMS_8x8, OAM_NO_FLIP, 364, 4, 0),
    OAM_ENTRY(-4, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 203, 4, 0),
};

static const u16 sParticleOam_IceMissileTrail_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 323, 4, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 323, 4, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 323, 4, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 323, 4, 0),
};

static const u16 sParticleOam_IceMissileTrail_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 324, 4, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 324, 4, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 324, 4, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 324, 4, 0),
};

static const u16 sParticleOam_IceMissileTrail_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 325, 4, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 325, 4, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 325, 4, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 325, 4, 0),
};

static const u16 sParticleOam_IceMissileTrail_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 326, 4, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 326, 4, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 326, 4, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 326, 4, 0),
};

static const u16 sParticleOam_NormalMissileTrail_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 202, 3, 0),
};

static const u16 sParticleOam_NormalMissileTrail_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 203, 3, 0),
};

static const u16 sParticleOam_NormalMissileTrail_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 204, 3, 0),
};

static const u16 sParticleOam_NormalMissileTrail_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 205, 3, 0),
};

static const u16 sDiffusionMissileOam_Horizontal_Frame0[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 156, 3, 0),
    OAM_ENTRY(4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 229, 4, 0),
    OAM_ENTRY(10, -8, OAM_DIMS_8x8, OAM_X_FLIP, 229, 4, 0),
    OAM_ENTRY(10, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 229, 4, 0),
    OAM_ENTRY(4, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 229, 4, 0),
    OAM_ENTRY(-5, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 216, 4, 0),
    OAM_ENTRY(11, -16, OAM_DIMS_16x16, OAM_X_FLIP, 216, 4, 0),
    OAM_ENTRY(11, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 216, 4, 0),
    OAM_ENTRY(-5, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 216, 4, 0),
};

static const u16 sDiffusionMissileOam_Horizontal_Frame1[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 156, 3, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 218, 4, 0),
    OAM_ENTRY(20, -16, OAM_DIMS_16x16, OAM_X_FLIP, 218, 4, 0),
    OAM_ENTRY(20, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 218, 4, 0),
    OAM_ENTRY(4, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 218, 4, 0),
    OAM_ENTRY(13, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 365, 4, 0),
    OAM_ENTRY(6, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 203, 4, 0),
};

static const u16 sDiffusionMissileOam_Diagonal_Frame0[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 158, 3, 0),
    OAM_ENTRY(1, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 229, 4, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_8x8, OAM_X_FLIP, 229, 4, 0),
    OAM_ENTRY(7, 7, OAM_DIMS_8x8, OAM_XY_FLIP, 229, 4, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_8x8, OAM_Y_FLIP, 229, 4, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 216, 4, 0),
    OAM_ENTRY(8, -8, OAM_DIMS_16x16, OAM_X_FLIP, 216, 4, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_XY_FLIP, 216, 4, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_16x16, OAM_Y_FLIP, 216, 4, 0),
};

static const u16 sDiffusionMissileOam_Diagonal_Frame1[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 158, 3, 0),
    OAM_ENTRY(7, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 327, 4, 0),
    OAM_ENTRY(2, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 203, 4, 0),
    OAM_ENTRY(-2, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 218, 4, 0),
    OAM_ENTRY(14, -2, OAM_DIMS_16x16, OAM_X_FLIP, 218, 4, 0),
    OAM_ENTRY(14, 14, OAM_DIMS_16x16, OAM_XY_FLIP, 218, 4, 0),
    OAM_ENTRY(-2, 14, OAM_DIMS_16x16, OAM_Y_FLIP, 218, 4, 0),
};

static const u16 sDiffusionMissileOam_Vertical_Frame0[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 188, 3, 0),
    OAM_ENTRY(-4, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 189, 3, 0),
    OAM_ENTRY(-8, 5, OAM_DIMS_8x8, OAM_NO_FLIP, 229, 4, 0),
    OAM_ENTRY(0, 5, OAM_DIMS_8x8, OAM_X_FLIP, 229, 4, 0),
    OAM_ENTRY(0, 11, OAM_DIMS_8x8, OAM_XY_FLIP, 229, 4, 0),
    OAM_ENTRY(-8, 11, OAM_DIMS_8x8, OAM_Y_FLIP, 229, 4, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 216, 4, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_16x16, OAM_X_FLIP, 216, 4, 0),
    OAM_ENTRY(0, 12, OAM_DIMS_16x16, OAM_XY_FLIP, 216, 4, 0),
    OAM_ENTRY(-16, 12, OAM_DIMS_16x16, OAM_Y_FLIP, 216, 4, 0),
};

static const u16 sDiffusionMissileOam_Vertical_Frame1[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 188, 3, 0),
    OAM_ENTRY(-4, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 189, 3, 0),
    OAM_ENTRY(-16, 5, OAM_DIMS_16x16, OAM_NO_FLIP, 218, 4, 0),
    OAM_ENTRY(0, 5, OAM_DIMS_16x16, OAM_X_FLIP, 218, 4, 0),
    OAM_ENTRY(0, 21, OAM_DIMS_16x16, OAM_XY_FLIP, 218, 4, 0),
    OAM_ENTRY(-16, 21, OAM_DIMS_16x16, OAM_Y_FLIP, 218, 4, 0),
    OAM_ENTRY(-4, 13, OAM_DIMS_8x8, OAM_NO_FLIP, 364, 4, 0),
    OAM_ENTRY(-4, 6, OAM_DIMS_8x8, OAM_NO_FLIP, 203, 4, 0),
};

static const u16 sParticleOam_DiffusionMissileTrail_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 4, 0),
};

static const u16 sParticleOam_DiffusionMissileTrail_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 402, 4, 0),
};

static const u16 sParticleOam_DiffusionMissileTrail_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 404, 4, 0),
};

static const u16 sParticleOam_DiffusionMissileTrail_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 406, 4, 0),
};

static const u16 sParticleOam_DiffusionMissileTrail_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
};

static const u16 sParticleOam_DiffusionMissileTrail_Frame5[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
};

static const u16 sParticleOam_DiffusionMissileTrail_Frame6[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
};

static const u16 sParticleOam_DiffusionMissileTrail_Frame7[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
};

static const u16 sParticleOam_DiffusionMissileTrail_Frame8[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
};

static const u16 sParticleOam_DiffusionMissileTrail_Frame9[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
};

static const u16 sParticleOam_ChargedDiffusionMissileTrail_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 4, 0),
};

static const u16 sParticleOam_ChargedDiffusionMissileTrail_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 402, 4, 0),
    OAM_ENTRY(-4, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 4, 0),
};

static const u16 sParticleOam_ChargedDiffusionMissileTrail_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 404, 4, 0),
    OAM_ENTRY(-3, -3, OAM_DIMS_16x16, OAM_NO_FLIP, 402, 4, 0),
    OAM_ENTRY(-12, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 4, 0),
};

static const u16 sParticleOam_ChargedDiffusionMissileTrail_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 406, 4, 0),
    OAM_ENTRY(-2, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 404, 4, 0),
    OAM_ENTRY(-13, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 402, 4, 0),
};

static const u16 sParticleOam_ChargedDiffusionMissileTrail_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-1, -1, OAM_DIMS_16x16, OAM_NO_FLIP, 406, 4, 0),
    OAM_ENTRY(-14, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 404, 4, 0),
};

static const u16 sParticleOam_ChargedDiffusionMissileTrail_Frame5[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-15, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 406, 4, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
};

static const u16 sMissileOam_Tumbling_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 156, 3, 0),
};

static const u16 sMissileOam_Tumbling_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 158, 3, 0),
};

static const u16 sMissileOam_Tumbling_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 188, 3, 0),
    OAM_ENTRY(-4, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 189, 3, 0),
};

static const u16 sMissileOam_Tumbling_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_X_FLIP, 158, 3, 0),
};

static const u16 sMissileOam_Tumbling_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -4, OAM_DIMS_16x8, OAM_X_FLIP, 156, 3, 0),
};

static const u16 sMissileOam_Tumbling_Frame5[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_XY_FLIP, 158, 3, 0),
};

static const u16 sMissileOam_Tumbling_Frame6[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 188, 3, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_Y_FLIP, 189, 3, 0),
};

static const u16 sMissileOam_Tumbling_Frame7[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_Y_FLIP, 158, 3, 0),
};

const struct FrameData sNormalSuperMissileOam_Horizontal[3] = {
    [0] = {
        .pFrame = sNormalSuperMissileOam_Horizontal_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sNormalSuperMissileOam_Horizontal_Frame1,
        .timer = 2
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sNormalSuperMissileOam_Diagonal[3] = {
    [0] = {
        .pFrame = sNormalSuperMissileOam_Diagonal_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sNormalSuperMissileOam_Diagonal_Frame1,
        .timer = 2
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sNormalSuperMissileOam_Vertical[3] = {
    [0] = {
        .pFrame = sNormalSuperMissileOam_Vertical_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sNormalSuperMissileOam_Vertical_Frame1,
        .timer = 2
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_SuperMissileTrail[10] = {
    [0] = {
        .pFrame = sParticleOam_SuperMissileTrail_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sParticleOam_SuperMissileTrail_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sParticleOam_SuperMissileTrail_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sParticleOam_SuperMissileTrail_Frame3,
        .timer = 4
    },
    [4] = {
        .pFrame = sParticleOam_SuperMissileTrail_Frame4,
        .timer = 6
    },
    [5] = {
        .pFrame = sParticleOam_SuperMissileTrail_Frame5,
        .timer = 6
    },
    [6] = {
        .pFrame = sParticleOam_SuperMissileTrail_Frame6,
        .timer = 6
    },
    [7] = {
        .pFrame = sParticleOam_SuperMissileTrail_Frame7,
        .timer = 6
    },
    [8] = {
        .pFrame = sParticleOam_SuperMissileTrail_Frame8,
        .timer = 6
    },
    [9] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIceMissileOam_Horizontal[3] = {
    [0] = {
        .pFrame = sIceMissileOam_Horizontal_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sIceMissileOam_Horizontal_Frame1,
        .timer = 2
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIceMissileOam_Diagonal[3] = {
    [0] = {
        .pFrame = sIceMissileOam_Diagonal_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sIceMissileOam_Diagonal_Frame1,
        .timer = 2
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIceMissileOam_Vertical[3] = {
    [0] = {
        .pFrame = sIceMissileOam_Vertical_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sIceMissileOam_Vertical_Frame1,
        .timer = 2
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_NormalMissileTrail[10] = {
    [0] = {
        .pFrame = sParticleOam_NormalMissileTrail_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sParticleOam_NormalMissileTrail_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sParticleOam_NormalMissileTrail_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sParticleOam_NormalMissileTrail_Frame3,
        .timer = 4
    },
    [4] = {
        .pFrame = sParticleOam_SuperMissileTrail_Frame4,
        .timer = 6
    },
    [5] = {
        .pFrame = sParticleOam_SuperMissileTrail_Frame5,
        .timer = 6
    },
    [6] = {
        .pFrame = sParticleOam_SuperMissileTrail_Frame6,
        .timer = 6
    },
    [7] = {
        .pFrame = sParticleOam_SuperMissileTrail_Frame7,
        .timer = 6
    },
    [8] = {
        .pFrame = sParticleOam_SuperMissileTrail_Frame8,
        .timer = 6
    },
    [9] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_IceMissileTrail[10] = {
    [0] = {
        .pFrame = sParticleOam_IceMissileTrail_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sParticleOam_IceMissileTrail_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sParticleOam_IceMissileTrail_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sParticleOam_IceMissileTrail_Frame3,
        .timer = 4
    },
    [4] = {
        .pFrame = sParticleOam_SuperMissileTrail_Frame4,
        .timer = 6
    },
    [5] = {
        .pFrame = sParticleOam_SuperMissileTrail_Frame5,
        .timer = 6
    },
    [6] = {
        .pFrame = sParticleOam_SuperMissileTrail_Frame6,
        .timer = 6
    },
    [7] = {
        .pFrame = sParticleOam_SuperMissileTrail_Frame7,
        .timer = 6
    },
    [8] = {
        .pFrame = sParticleOam_SuperMissileTrail_Frame8,
        .timer = 6
    },
    [9] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_DiffusionMissileTrail[11] = {
    [0] = {
        .pFrame = sParticleOam_DiffusionMissileTrail_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sParticleOam_DiffusionMissileTrail_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sParticleOam_DiffusionMissileTrail_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sParticleOam_DiffusionMissileTrail_Frame3,
        .timer = 4
    },
    [4] = {
        .pFrame = sParticleOam_DiffusionMissileTrail_Frame4,
        .timer = 8
    },
    [5] = {
        .pFrame = sParticleOam_DiffusionMissileTrail_Frame5,
        .timer = 8
    },
    [6] = {
        .pFrame = sParticleOam_DiffusionMissileTrail_Frame6,
        .timer = 8
    },
    [7] = {
        .pFrame = sParticleOam_DiffusionMissileTrail_Frame7,
        .timer = 8
    },
    [8] = {
        .pFrame = sParticleOam_DiffusionMissileTrail_Frame8,
        .timer = 8
    },
    [9] = {
        .pFrame = sParticleOam_DiffusionMissileTrail_Frame9,
        .timer = 8
    },
    [10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDiffusionMissileOam_Horizontal[3] = {
    [0] = {
        .pFrame = sDiffusionMissileOam_Horizontal_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sDiffusionMissileOam_Horizontal_Frame1,
        .timer = 2
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDiffusionMissileOam_Diagonal[3] = {
    [0] = {
        .pFrame = sDiffusionMissileOam_Diagonal_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sDiffusionMissileOam_Diagonal_Frame1,
        .timer = 2
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDiffusionMissileOam_Vertical[3] = {
    [0] = {
        .pFrame = sDiffusionMissileOam_Vertical_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sDiffusionMissileOam_Vertical_Frame1,
        .timer = 2
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_ChargedDiffusionMissileTrail[11] = {
    [0] = {
        .pFrame = sParticleOam_ChargedDiffusionMissileTrail_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sParticleOam_ChargedDiffusionMissileTrail_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sParticleOam_ChargedDiffusionMissileTrail_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sParticleOam_ChargedDiffusionMissileTrail_Frame3,
        .timer = 4
    },
    [4] = {
        .pFrame = sParticleOam_ChargedDiffusionMissileTrail_Frame4,
        .timer = 4
    },
    [5] = {
        .pFrame = sParticleOam_ChargedDiffusionMissileTrail_Frame5,
        .timer = 4
    },
    [6] = {
        .pFrame = sParticleOam_DiffusionMissileTrail_Frame6,
        .timer = 6
    },
    [7] = {
        .pFrame = sParticleOam_DiffusionMissileTrail_Frame7,
        .timer = 6
    },
    [8] = {
        .pFrame = sParticleOam_DiffusionMissileTrail_Frame8,
        .timer = 6
    },
    [9] = {
        .pFrame = sParticleOam_DiffusionMissileTrail_Frame9,
        .timer = 6
    },
    [10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMissileOam_Tumbling[9] = {
    [0] = {
        .pFrame = sMissileOam_Tumbling_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sMissileOam_Tumbling_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sMissileOam_Tumbling_Frame2,
        .timer = 3
    },
    [3] = {
        .pFrame = sMissileOam_Tumbling_Frame3,
        .timer = 3
    },
    [4] = {
        .pFrame = sMissileOam_Tumbling_Frame4,
        .timer = 3
    },
    [5] = {
        .pFrame = sMissileOam_Tumbling_Frame5,
        .timer = 3
    },
    [6] = {
        .pFrame = sMissileOam_Tumbling_Frame6,
        .timer = 3
    },
    [7] = {
        .pFrame = sMissileOam_Tumbling_Frame7,
        .timer = 3
    },
    [8] = FRAME_DATA_TERMINATOR
};

static const u16 sOam_58eac0_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
};

static const u16 sOam_58eac0_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
};

static const u16 sOam_58eac0_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
};

static const u16 sOam_58eac0_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
};

static const u16 sBombOam_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 334, 3, 0),
};

static const u16 sBombOam_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 335, 3, 0),
};

static const u16 sBombOam_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 336, 3, 0),
};

static const u16 sBombOam_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 337, 3, 0),
};

static const u16 sPowerBombOam_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 331, 3, 0),
};

static const u16 sPowerBombOam_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 332, 3, 0),
};

static const u16 sPowerBombOam_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 333, 3, 0),
};

const struct FrameData sOam_58eac0[5] = {
    [0] = {
        .pFrame = sOam_58eac0_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sOam_58eac0_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sOam_58eac0_Frame2,
        .timer = 3
    },
    [3] = {
        .pFrame = sOam_58eac0_Frame3,
        .timer = 3
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sBombOam_Slow[5] = {
    [0] = {
        .pFrame = sBombOam_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sBombOam_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sBombOam_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sBombOam_Frame3,
        .timer = 8
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sBombOam_Fast[5] = {
    [0] = {
        .pFrame = sBombOam_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sBombOam_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sBombOam_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sBombOam_Frame3,
        .timer = 2
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPowerBombOam_Slow[4] = {
    [0] = {
        .pFrame = sPowerBombOam_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sPowerBombOam_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sPowerBombOam_Frame2,
        .timer = 8
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPowerBombOam_Fast[4] = {
    [0] = {
        .pFrame = sPowerBombOam_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sPowerBombOam_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sPowerBombOam_Frame2,
        .timer = 3
    },
    [3] = FRAME_DATA_TERMINATOR
};

const u8 sFlareHorizontalGfx_Top[40 * 32] = INCBIN_U8("data/projectiles/flare_horizontal_top.gfx");
const u8 sFlareHorizontalGfx_Bottom[40 * 32] = INCBIN_U8("data/projectiles/flare_horizontal_bottom.gfx");
const u8 sFlareDiagonalGfx_Top[40 * 32] = INCBIN_U8("data/projectiles/flare_diagonal_top.gfx");
const u8 sFlareDiagonalGfx_Bottom[40 * 32] = INCBIN_U8("data/projectiles/flare_diagonal_bottom.gfx");
const u8 sFlareVerticalGfx_Top[40 * 32] = INCBIN_U8("data/projectiles/flare_vertical_top.gfx");
const u8 sFlareVerticalGfx_Bottom[40 * 32] = INCBIN_U8("data/projectiles/flare_vertical_bottom.gfx");

static const u16 sFlareOam_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 148, 2, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 152, 2, 0),
};

const struct FrameData sFlareOam[2] = {
    [0] = {
        .pFrame = sFlareOam_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};
