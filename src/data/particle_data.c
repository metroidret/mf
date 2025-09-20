#include "data/particle_data.h"
#include "macros.h"

static const u16 sParticleOam_Bomb_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 230, 3, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_8x8, OAM_Y_FLIP, 230, 3, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_8x8, OAM_X_FLIP, 230, 3, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_8x8, OAM_XY_FLIP, 230, 3, 0),
};

static const u16 sParticleOam_Bomb_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 231, 3, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_8x8, OAM_X_FLIP, 231, 3, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_8x8, OAM_Y_FLIP, 231, 3, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_8x8, OAM_XY_FLIP, 231, 3, 0),
};

static const u16 sParticleOam_Bomb_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 256, 3, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_16x16, OAM_Y_FLIP, 256, 3, 0),
    OAM_ENTRY(0, -20, OAM_DIMS_16x16, OAM_X_FLIP, 256, 3, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_16x16, OAM_XY_FLIP, 256, 3, 0),
};

static const u16 sParticleOam_Bomb_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 258, 3, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_16x16, OAM_Y_FLIP, 258, 3, 0),
    OAM_ENTRY(0, -20, OAM_DIMS_16x16, OAM_X_FLIP, 258, 3, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_16x16, OAM_XY_FLIP, 258, 3, 0),
};

static const u16 sParticleOam_Bomb_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 260, 3, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_16x16, OAM_Y_FLIP, 260, 3, 0),
    OAM_ENTRY(0, -20, OAM_DIMS_16x16, OAM_X_FLIP, 260, 3, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_16x16, OAM_XY_FLIP, 260, 3, 0),
};

static const u16 sParticleOam_Explosion2_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 202, 3, 0),
};

static const u16 sParticleOam_Explosion2_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 229, 3, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 229, 3, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 229, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 229, 3, 0),
};

static const u16 sParticleOam_Explosion2_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 262, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 262, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 262, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 262, 3, 0),
};

static const u16 sParticleOam_Explosion2_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 264, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 264, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 264, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 264, 3, 0),
};

static const u16 sParticleOam_Explosion2_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 266, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 266, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 266, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 266, 3, 0),
};

static const u16 sParticleOam_Explosion2_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 268, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 268, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 268, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 268, 3, 0),
};

static const u16 sParticleOam_Explosion1_Frame3[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 270, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 270, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 270, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 270, 3, 0),
    OAM_ENTRY(-24, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 304, 3, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_8x8, OAM_X_FLIP, 304, 3, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 272, 3, 0),
    OAM_ENTRY(-4, 16, OAM_DIMS_8x8, OAM_Y_FLIP, 272, 3, 0),
};

static const u16 sParticleOam_Explosion1_Frame4[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-16, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 273, 3, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_16x16, OAM_XY_FLIP, 273, 3, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_16x16, OAM_X_FLIP, 273, 3, 0),
    OAM_ENTRY(-16, 8, OAM_DIMS_16x16, OAM_Y_FLIP, 273, 3, 0),
    OAM_ENTRY(-24, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 275, 3, 0),
    OAM_ENTRY(-24, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 275, 3, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x16, OAM_X_FLIP, 275, 3, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 275, 3, 0),
};

static const u16 sParticleOam_Explosion1_Frame5[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-24, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 277, 3, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_16x16, OAM_Y_FLIP, 277, 3, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_XY_FLIP, 277, 3, 0),
    OAM_ENTRY(8, -24, OAM_DIMS_16x16, OAM_X_FLIP, 277, 3, 0),
    OAM_ENTRY(-24, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 279, 3, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_8x16, OAM_X_FLIP, 279, 3, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 312, 3, 0),
    OAM_ENTRY(-8, 16, OAM_DIMS_16x8, OAM_Y_FLIP, 312, 3, 0),
};

static const u16 sParticleOam_SuperMissileExplosion_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 229, 3, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 229, 3, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 229, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 229, 3, 0),
};

static const u16 sParticleOam_SuperMissileExplosion_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 262, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 262, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 262, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 262, 3, 0),
};

static const u16 sParticleOam_SuperMissileExplosion_Frame2[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 270, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 270, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 270, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 270, 3, 0),
    OAM_ENTRY(-24, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 304, 3, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_8x8, OAM_X_FLIP, 304, 3, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 272, 3, 0),
    OAM_ENTRY(-4, 16, OAM_DIMS_8x8, OAM_Y_FLIP, 272, 3, 0),
};

static const u16 sParticleOam_SuperMissileExplosion_Frame3[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-16, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 273, 3, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_16x16, OAM_XY_FLIP, 273, 3, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_16x16, OAM_X_FLIP, 273, 3, 0),
    OAM_ENTRY(-16, 8, OAM_DIMS_16x16, OAM_Y_FLIP, 273, 3, 0),
    OAM_ENTRY(-24, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 275, 3, 0),
    OAM_ENTRY(-24, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 275, 3, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x16, OAM_X_FLIP, 275, 3, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 275, 3, 0),
};

static const u16 sParticleOam_SuperMissileExplosion_Frame4[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-24, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 277, 3, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_16x16, OAM_Y_FLIP, 277, 3, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_XY_FLIP, 277, 3, 0),
    OAM_ENTRY(8, -24, OAM_DIMS_16x16, OAM_X_FLIP, 277, 3, 0),
    OAM_ENTRY(-24, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 279, 3, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_8x16, OAM_X_FLIP, 279, 3, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 312, 3, 0),
    OAM_ENTRY(-8, 16, OAM_DIMS_16x8, OAM_Y_FLIP, 312, 3, 0),
};

static const u16 sParticleOam_FireBeam_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 235, 2, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 235, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 235, 2, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 235, 2, 0),
};

static const u16 sParticleOam_FireBeam_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 362, 2, 0),
    OAM_ENTRY(2, -10, OAM_DIMS_8x8, OAM_X_FLIP, 362, 2, 0),
    OAM_ENTRY(2, 2, OAM_DIMS_8x8, OAM_XY_FLIP, 362, 2, 0),
    OAM_ENTRY(-10, 2, OAM_DIMS_8x8, OAM_Y_FLIP, 362, 2, 0),
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 234, 2, 0),
};

static const u16 sParticleOam_FireBeam_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-11, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 361, 2, 0),
    OAM_ENTRY(-11, 3, OAM_DIMS_8x8, OAM_Y_FLIP, 361, 2, 0),
    OAM_ENTRY(3, -11, OAM_DIMS_8x8, OAM_X_FLIP, 361, 2, 0),
    OAM_ENTRY(3, 3, OAM_DIMS_8x8, OAM_XY_FLIP, 361, 2, 0),
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 234, 2, 0),
};

static const u16 sParticleOam_3ea63c_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 202, 3, 0),
};

static const u16 sParticleOam_3ea63c_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 203, 3, 0),
};

static const u16 sParticleOam_3ea63c_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 204, 3, 0),
};

static const u16 sParticleOam_3ea63c_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 205, 3, 0),
};

static const u16 sParticleOam_AbsorbRedXAbsorbing_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-4, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 201, 2, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 384, 2, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 384, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 384, 2, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 384, 2, 0),
    OAM_ENTRY(19, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 201, 2, 0),
};

static const u16 sParticleOam_AbsorbRedXAbsorbing_Frame4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 386, 2, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 386, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 386, 2, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 386, 2, 0),
    OAM_ENTRY(14, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 199, 2, 0),
    OAM_ENTRY(-24, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 201, 2, 0),
};

static const u16 sParticleOam_AbsorbRedXAbsorbing_Frame8[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(10, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 200, 2, 0),
    OAM_ENTRY(-21, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 199, 2, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 388, 2, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 388, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 388, 2, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 388, 2, 0),
};

static const u16 sParticleOam_AbsorbRedXAbsorbing_Frame12[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(6, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 200, 2, 0),
    OAM_ENTRY(-19, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 200, 2, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 390, 2, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 390, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 390, 2, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 390, 2, 0),
    OAM_ENTRY(-20, 20, OAM_DIMS_8x8, OAM_NO_FLIP, 201, 2, 0),
};

static const u16 sParticleOam_AbsorbRedXAbsorbing_Frame16[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(3, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 201, 2, 0),
    OAM_ENTRY(-15, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 200, 2, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 384, 2, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 384, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 384, 2, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 384, 2, 0),
    OAM_ENTRY(-15, 17, OAM_DIMS_8x8, OAM_NO_FLIP, 199, 2, 0),
};

static const u16 sParticleOam_AbsorbRedXAbsorbing_Frame20[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(0, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 201, 2, 0),
    OAM_ENTRY(-11, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 201, 2, 0),
    OAM_ENTRY(-11, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 200, 2, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 386, 2, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 386, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 386, 2, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 386, 2, 0),
};

static const u16 sParticleOam_AbsorbRedXAbsorbing_Frame24[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 201, 2, 0),
    OAM_ENTRY(-8, 6, OAM_DIMS_8x8, OAM_NO_FLIP, 200, 2, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 388, 2, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 388, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 388, 2, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 388, 2, 0),
};

static const u16 sParticleOam_AbsorbRedXAbsorbing_Frame28[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-5, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 201, 2, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 390, 2, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 390, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 390, 2, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 390, 2, 0),
};

static const u16 sParticleOam_AbsorbRedXEnding_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 384, 2, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 384, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 384, 2, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 384, 2, 0),
};

static const u16 sParticleOam_AbsorbRedXEnding_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-15, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 386, 2, 0),
    OAM_ENTRY(-1, -15, OAM_DIMS_16x16, OAM_X_FLIP, 386, 2, 0),
    OAM_ENTRY(-1, -1, OAM_DIMS_16x16, OAM_XY_FLIP, 386, 2, 0),
    OAM_ENTRY(-15, -1, OAM_DIMS_16x16, OAM_Y_FLIP, 386, 2, 0),
};

static const u16 sParticleOam_AbsorbRedXEnding_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-2, -2, OAM_DIMS_16x16, OAM_XY_FLIP, 388, 2, 0),
    OAM_ENTRY(-14, -2, OAM_DIMS_16x16, OAM_Y_FLIP, 388, 2, 0),
    OAM_ENTRY(-14, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 388, 2, 0),
    OAM_ENTRY(-2, -14, OAM_DIMS_16x16, OAM_X_FLIP, 388, 2, 0),
};

static const u16 sParticleOam_AbsorbRedXEnding_Frame6[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 230, 2, 0),
    OAM_ENTRY(0, -7, OAM_DIMS_8x8, OAM_X_FLIP, 230, 2, 0),
    OAM_ENTRY(0, -1, OAM_DIMS_8x8, OAM_XY_FLIP, 230, 2, 0),
    OAM_ENTRY(-8, -1, OAM_DIMS_8x8, OAM_Y_FLIP, 230, 2, 0),
};

static const u16 sParticleOam_AbsorbRedXEnding_Frame8[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-32, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 224, 2, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_32x8, OAM_X_FLIP, 224, 2, 0),
};

static const u16 sParticleOam_AbsorbRedXEnding_Frame10[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 224, 2, 0),
    OAM_ENTRY(0, -5, OAM_DIMS_16x8, OAM_X_FLIP, 224, 2, 0),
};

static const u16 sParticleOam_AbsorbRedXEnding_Frame12[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 224, 2, 0),
    OAM_ENTRY(0, -5, OAM_DIMS_8x8, OAM_X_FLIP, 224, 2, 0),
};

static const u16 sParticleOam_AbsorbRedXEnding_Frame14[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-5, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 224, 2, 0),
    OAM_ENTRY(-3, -5, OAM_DIMS_8x8, OAM_X_FLIP, 224, 2, 0),
};

static const u16 sParticleOam_AbsorbHealthXAbsorbing_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 251, 3, 0),
};

static const u16 sParticleOam_AbsorbMissileXAbsorbing_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-4, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 201, 3, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 384, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 384, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 384, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 384, 3, 0),
    OAM_ENTRY(19, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 201, 3, 0),
};

static const u16 sParticleOam_AbsorbMissileXAbsorbing_Frame4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 386, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 386, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 386, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 386, 3, 0),
    OAM_ENTRY(14, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 199, 3, 0),
    OAM_ENTRY(-24, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 201, 3, 0),
};

static const u16 sParticleOam_AbsorbMissileXAbsorbing_Frame8[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(10, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 200, 3, 0),
    OAM_ENTRY(-21, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 199, 3, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 388, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 388, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 388, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 388, 3, 0),
};

static const u16 sParticleOam_AbsorbMissileXAbsorbing_Frame12[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(6, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 200, 3, 0),
    OAM_ENTRY(-19, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 200, 3, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 390, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 390, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 390, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 390, 3, 0),
    OAM_ENTRY(-20, 20, OAM_DIMS_8x8, OAM_NO_FLIP, 201, 3, 0),
};

static const u16 sParticleOam_AbsorbMissileXAbsorbing_Frame16[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(3, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 201, 3, 0),
    OAM_ENTRY(-15, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 200, 3, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 384, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 384, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 384, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 384, 3, 0),
    OAM_ENTRY(-15, 17, OAM_DIMS_8x8, OAM_NO_FLIP, 199, 3, 0),
};

static const u16 sParticleOam_AbsorbMissileXAbsorbing_Frame20[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(0, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 201, 3, 0),
    OAM_ENTRY(-11, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 201, 3, 0),
    OAM_ENTRY(-11, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 200, 3, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 386, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 386, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 386, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 386, 3, 0),
};

static const u16 sParticleOam_AbsorbMissileXAbsorbing_Frame24[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 201, 3, 0),
    OAM_ENTRY(-8, 6, OAM_DIMS_8x8, OAM_NO_FLIP, 200, 3, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 388, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 388, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 388, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 388, 3, 0),
};

static const u16 sParticleOam_AbsorbMissileXAbsorbing_Frame28[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-5, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 201, 3, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 390, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 390, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 390, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 390, 3, 0),
};

static const u16 sParticleOam_AbsorbMissileXEnding_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 384, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 384, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 384, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 384, 3, 0),
};

static const u16 sParticleOam_AbsorbMissileXEnding_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-15, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 386, 3, 0),
    OAM_ENTRY(-1, -15, OAM_DIMS_16x16, OAM_X_FLIP, 386, 3, 0),
    OAM_ENTRY(-1, -1, OAM_DIMS_16x16, OAM_XY_FLIP, 386, 3, 0),
    OAM_ENTRY(-15, -1, OAM_DIMS_16x16, OAM_Y_FLIP, 386, 3, 0),
};

static const u16 sParticleOam_AbsorbMissileXEnding_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-2, -2, OAM_DIMS_16x16, OAM_XY_FLIP, 388, 3, 0),
    OAM_ENTRY(-14, -2, OAM_DIMS_16x16, OAM_Y_FLIP, 388, 3, 0),
    OAM_ENTRY(-14, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 388, 3, 0),
    OAM_ENTRY(-2, -14, OAM_DIMS_16x16, OAM_X_FLIP, 388, 3, 0),
};

static const u16 sParticleOam_AbsorbMissileXEnding_Frame6[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 230, 3, 0),
    OAM_ENTRY(0, -7, OAM_DIMS_8x8, OAM_X_FLIP, 230, 3, 0),
    OAM_ENTRY(0, -1, OAM_DIMS_8x8, OAM_XY_FLIP, 230, 3, 0),
    OAM_ENTRY(-8, -1, OAM_DIMS_8x8, OAM_Y_FLIP, 230, 3, 0),
};

static const u16 sParticleOam_AbsorbMissileXEnding_Frame8[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-32, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 224, 3, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_32x8, OAM_X_FLIP, 224, 3, 0),
};

static const u16 sParticleOam_AbsorbMissileXEnding_Frame10[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 224, 3, 0),
    OAM_ENTRY(0, -5, OAM_DIMS_16x8, OAM_X_FLIP, 224, 3, 0),
};

static const u16 sParticleOam_AbsorbMissileXEnding_Frame12[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 224, 3, 0),
    OAM_ENTRY(0, -5, OAM_DIMS_8x8, OAM_X_FLIP, 224, 3, 0),
};

static const u16 sParticleOam_AbsorbMissileXEnding_Frame14[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-5, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 224, 3, 0),
    OAM_ENTRY(-3, -5, OAM_DIMS_8x8, OAM_X_FLIP, 224, 3, 0),
};

static const u16 sParticleOam_AbsorbHealthXAbsorbing_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-4, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 201, 4, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 384, 4, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 384, 4, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 384, 4, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 384, 4, 0),
    OAM_ENTRY(19, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 201, 4, 0),
};

static const u16 sParticleOam_AbsorbHealthXAbsorbing_Frame4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 386, 4, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 386, 4, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 386, 4, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 386, 4, 0),
    OAM_ENTRY(14, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 199, 4, 0),
    OAM_ENTRY(-24, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 201, 4, 0),
};

static const u16 sParticleOam_AbsorbHealthXAbsorbing_Frame8[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(10, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 200, 4, 0),
    OAM_ENTRY(-21, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 199, 4, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 388, 4, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 388, 4, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 388, 4, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 388, 4, 0),
};

static const u16 sParticleOam_AbsorbHealthXAbsorbing_Frame12[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(6, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 200, 4, 0),
    OAM_ENTRY(-19, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 200, 4, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 390, 4, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 390, 4, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 390, 4, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 390, 4, 0),
    OAM_ENTRY(-20, 20, OAM_DIMS_8x8, OAM_NO_FLIP, 201, 4, 0),
};

static const u16 sParticleOam_AbsorbHealthXAbsorbing_Frame16[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(3, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 201, 4, 0),
    OAM_ENTRY(-15, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 200, 4, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 384, 4, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 384, 4, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 384, 4, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 384, 4, 0),
    OAM_ENTRY(-15, 17, OAM_DIMS_8x8, OAM_NO_FLIP, 199, 4, 0),
};

static const u16 sParticleOam_AbsorbHealthXAbsorbing_Frame20[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(0, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 201, 4, 0),
    OAM_ENTRY(-11, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 201, 4, 0),
    OAM_ENTRY(-11, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 200, 4, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 386, 4, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 386, 4, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 386, 4, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 386, 4, 0),
};

static const u16 sParticleOam_AbsorbHealthXAbsorbing_Frame24[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 201, 4, 0),
    OAM_ENTRY(-8, 6, OAM_DIMS_8x8, OAM_NO_FLIP, 200, 4, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 388, 4, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 388, 4, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 388, 4, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 388, 4, 0),
};

static const u16 sParticleOam_AbsorbHealthXAbsorbing_Frame28[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-5, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 201, 4, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 390, 4, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 390, 4, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 390, 4, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 390, 4, 0),
};

static const u16 sParticleOam_AbsorbHealthXEnding_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 384, 4, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 384, 4, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 384, 4, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 384, 4, 0),
};

static const u16 sParticleOam_AbsorbHealthXEnding_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-15, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 386, 4, 0),
    OAM_ENTRY(-1, -15, OAM_DIMS_16x16, OAM_X_FLIP, 386, 4, 0),
    OAM_ENTRY(-1, -1, OAM_DIMS_16x16, OAM_XY_FLIP, 386, 4, 0),
    OAM_ENTRY(-15, -1, OAM_DIMS_16x16, OAM_Y_FLIP, 386, 4, 0),
};

static const u16 sParticleOam_AbsorbHealthXEnding_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-2, -2, OAM_DIMS_16x16, OAM_XY_FLIP, 388, 4, 0),
    OAM_ENTRY(-14, -2, OAM_DIMS_16x16, OAM_Y_FLIP, 388, 4, 0),
    OAM_ENTRY(-14, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 388, 4, 0),
    OAM_ENTRY(-2, -14, OAM_DIMS_16x16, OAM_X_FLIP, 388, 4, 0),
};

static const u16 sParticleOam_AbsorbHealthXEnding_Frame6[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 230, 4, 0),
    OAM_ENTRY(0, -7, OAM_DIMS_8x8, OAM_X_FLIP, 230, 4, 0),
    OAM_ENTRY(0, -1, OAM_DIMS_8x8, OAM_XY_FLIP, 230, 4, 0),
    OAM_ENTRY(-8, -1, OAM_DIMS_8x8, OAM_Y_FLIP, 230, 4, 0),
};

static const u16 sParticleOam_AbsorbHealthXEnding_Frame8[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-32, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 224, 4, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_32x8, OAM_X_FLIP, 224, 4, 0),
};

static const u16 sParticleOam_AbsorbHealthXEnding_Frame10[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 224, 4, 0),
    OAM_ENTRY(0, -5, OAM_DIMS_16x8, OAM_X_FLIP, 224, 4, 0),
};

static const u16 sParticleOam_AbsorbHealthXEnding_Frame12[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 224, 4, 0),
    OAM_ENTRY(0, -5, OAM_DIMS_8x8, OAM_X_FLIP, 224, 4, 0),
};

static const u16 sParticleOam_AbsorbHealthXEnding_Frame14[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-5, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 224, 4, 0),
    OAM_ENTRY(-3, -5, OAM_DIMS_8x8, OAM_X_FLIP, 224, 4, 0),
};

static const u16 sParticleOam_3ea974_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 3, 0),
};

static const u16 sParticleOam_3ea974_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 402, 3, 0),
};

static const u16 sParticleOam_3ea974_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 404, 3, 0),
};

static const u16 sParticleOam_3ea974_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 406, 3, 0),
};

static const u16 sParticleOam_Explosion4_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 203, 3, 0),
};

static const u16 sParticleOam_Explosion4_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 229, 3, 0),
    OAM_ENTRY(-8, -1, OAM_DIMS_8x8, OAM_Y_FLIP, 229, 3, 0),
    OAM_ENTRY(0, -9, OAM_DIMS_8x8, OAM_X_FLIP, 229, 3, 0),
    OAM_ENTRY(0, -1, OAM_DIMS_8x8, OAM_XY_FLIP, 229, 3, 0),
};

static const u16 sParticleOam_Explosion4_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 262, 3, 0),
    OAM_ENTRY(-16, -3, OAM_DIMS_16x16, OAM_Y_FLIP, 262, 3, 0),
    OAM_ENTRY(0, -19, OAM_DIMS_16x16, OAM_X_FLIP, 262, 3, 0),
    OAM_ENTRY(0, -3, OAM_DIMS_16x16, OAM_XY_FLIP, 262, 3, 0),
};

static const u16 sParticleOam_Explosion4_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 264, 3, 0),
    OAM_ENTRY(-16, -6, OAM_DIMS_16x16, OAM_Y_FLIP, 264, 3, 0),
    OAM_ENTRY(0, -22, OAM_DIMS_16x16, OAM_X_FLIP, 264, 3, 0),
    OAM_ENTRY(0, -6, OAM_DIMS_16x16, OAM_XY_FLIP, 264, 3, 0),
};

static const u16 sParticleOam_Explosion4_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 266, 3, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_16x16, OAM_Y_FLIP, 266, 3, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_16x16, OAM_X_FLIP, 266, 3, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_XY_FLIP, 266, 3, 0),
};

static const u16 sParticleOam_Explosion4_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 268, 3, 0),
    OAM_ENTRY(-16, -10, OAM_DIMS_16x16, OAM_Y_FLIP, 268, 3, 0),
    OAM_ENTRY(0, -26, OAM_DIMS_16x16, OAM_X_FLIP, 268, 3, 0),
    OAM_ENTRY(0, -10, OAM_DIMS_16x16, OAM_XY_FLIP, 268, 3, 0),
};

static const u16 sParticleOam_Explosion3_Frame3[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-16, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 270, 3, 0),
    OAM_ENTRY(-16, -2, OAM_DIMS_16x16, OAM_Y_FLIP, 270, 3, 0),
    OAM_ENTRY(0, -18, OAM_DIMS_16x16, OAM_X_FLIP, 270, 3, 0),
    OAM_ENTRY(0, -2, OAM_DIMS_16x16, OAM_XY_FLIP, 270, 3, 0),
    OAM_ENTRY(-24, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 304, 3, 0),
    OAM_ENTRY(16, -6, OAM_DIMS_8x8, OAM_X_FLIP, 304, 3, 0),
    OAM_ENTRY(-4, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 272, 3, 0),
    OAM_ENTRY(-4, 14, OAM_DIMS_8x8, OAM_Y_FLIP, 272, 3, 0),
};

static const u16 sParticleOam_Explosion3_Frame4[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-16, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 273, 3, 0),
    OAM_ENTRY(0, 5, OAM_DIMS_16x16, OAM_XY_FLIP, 273, 3, 0),
    OAM_ENTRY(0, -27, OAM_DIMS_16x16, OAM_X_FLIP, 273, 3, 0),
    OAM_ENTRY(-16, 5, OAM_DIMS_16x16, OAM_Y_FLIP, 273, 3, 0),
    OAM_ENTRY(-24, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 275, 3, 0),
    OAM_ENTRY(-24, -3, OAM_DIMS_16x16, OAM_Y_FLIP, 275, 3, 0),
    OAM_ENTRY(8, -19, OAM_DIMS_16x16, OAM_X_FLIP, 275, 3, 0),
    OAM_ENTRY(8, -3, OAM_DIMS_16x16, OAM_XY_FLIP, 275, 3, 0),
};

static const u16 sParticleOam_Explosion3_Frame5[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-24, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 277, 3, 0),
    OAM_ENTRY(-24, 5, OAM_DIMS_16x16, OAM_Y_FLIP, 277, 3, 0),
    OAM_ENTRY(8, 5, OAM_DIMS_16x16, OAM_XY_FLIP, 277, 3, 0),
    OAM_ENTRY(8, -27, OAM_DIMS_16x16, OAM_X_FLIP, 277, 3, 0),
    OAM_ENTRY(-24, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 279, 3, 0),
    OAM_ENTRY(16, -11, OAM_DIMS_8x16, OAM_X_FLIP, 279, 3, 0),
    OAM_ENTRY(-8, -27, OAM_DIMS_16x8, OAM_NO_FLIP, 312, 3, 0),
    OAM_ENTRY(-8, 13, OAM_DIMS_16x8, OAM_Y_FLIP, 312, 3, 0),
};

static const u16 sParticleOam_NormalMissileExplosion_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-14, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 218, 3, 0),
    OAM_ENTRY(-2, -14, OAM_DIMS_16x16, OAM_X_FLIP, 218, 3, 0),
    OAM_ENTRY(-2, -2, OAM_DIMS_16x16, OAM_XY_FLIP, 218, 3, 0),
    OAM_ENTRY(-14, -2, OAM_DIMS_16x16, OAM_Y_FLIP, 218, 3, 0),
};

static const u16 sParticleOam_NormalMissileExplosion_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 218, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 218, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 218, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 218, 3, 0),
};

static const u16 sParticleOam_Explosion6_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 202, 3, 0),
};

static const u16 sParticleOam_Explosion6_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 203, 3, 0),
};

static const u16 sParticleOam_Explosion6_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 204, 3, 0),
};

static const u16 sParticleOam_Explosion6_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 205, 3, 0),
};

static const u16 sParticleOam_Explosion5_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 3, 0),
};

static const u16 sParticleOam_Explosion5_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 402, 3, 0),
};

static const u16 sParticleOam_Explosion5_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 404, 3, 0),
};

static const u16 sParticleOam_Explosion5_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 406, 3, 0),
};

static const u16 sParticleOam_IceMissileExplosion_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 468, 4, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 468, 4, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 468, 4, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 468, 4, 0),
};

static const u16 sParticleOam_IceMissileExplosion_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 469, 4, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 469, 4, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 469, 4, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 469, 4, 0),
};

static const u16 sParticleOam_IceMissileExplosion_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 460, 4, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 460, 4, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 460, 4, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 460, 4, 0),
};

static const u16 sParticleOam_ChargedDiffusionMissileExplosion_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 462, 4, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 462, 4, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 462, 4, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 462, 4, 0),
};

static const u16 sParticleOam_ChargedDiffusionMissileExplosion_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 464, 4, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 464, 4, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 464, 4, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 464, 4, 0),
};

static const u16 sParticleOam_ChargedDiffusionMissileExplosion_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 466, 4, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 466, 4, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 466, 4, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 466, 4, 0),
};

static const u16 sParticleOam_AbsorbIceXPreVaria_Frame16[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-12, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 500, 4, 0),
};

static const u16 sParticleOam_AbsorbIceXPreVaria_Frame17[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-12, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 501, 4, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 500, 4, 0),
};

static const u16 sParticleOam_AbsorbIceXPreVaria_Frame18[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-12, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 470, 4, 0),
    OAM_ENTRY(0, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 501, 4, 0),
    OAM_ENTRY(2, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 500, 4, 0),
};

static const u16 sParticleOam_AbsorbIceXPreVaria_Frame19[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-12, -1, OAM_DIMS_8x8, OAM_NO_FLIP, 502, 4, 0),
    OAM_ENTRY(0, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 470, 4, 0),
    OAM_ENTRY(2, 5, OAM_DIMS_8x8, OAM_NO_FLIP, 501, 4, 0),
};

static const u16 sParticleOam_AbsorbIceXPreVaria_Frame20[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-12, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 503, 4, 0),
    OAM_ENTRY(0, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 502, 4, 0),
    OAM_ENTRY(2, 6, OAM_DIMS_8x8, OAM_NO_FLIP, 470, 4, 0),
};

static const u16 sParticleOam_AbsorbIceXPreVaria_Frame21[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 503, 4, 0),
    OAM_ENTRY(2, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 502, 4, 0),
};

static const u16 sParticleOam_AbsorbIceXPreVaria_Frame22[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(2, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 503, 4, 0),
};

static const u16 sParticleOam_IceMissileExplosion_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 410, 4, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 410, 4, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 410, 4, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 410, 4, 0),
};

static const u16 sParticleOam_IceMissileExplosion_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 408, 4, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 408, 4, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 408, 4, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 408, 4, 0),
};

static const u16 sParticleOam_AbsorbIceXPreVaria_Frame10[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 208, 4, 0),
    OAM_ENTRY(-24, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 215, 4, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 208, 4, 0),
    OAM_ENTRY(16, 16, OAM_DIMS_8x8, OAM_XY_FLIP, 215, 4, 0),
};

static const u16 sParticleOam_AbsorbIceXPreVaria_Frame11[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-14, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 208, 4, 0),
    OAM_ENTRY(-21, -21, OAM_DIMS_8x8, OAM_NO_FLIP, 215, 4, 0),
    OAM_ENTRY(-2, -2, OAM_DIMS_16x16, OAM_XY_FLIP, 208, 4, 0),
    OAM_ENTRY(13, 13, OAM_DIMS_8x8, OAM_XY_FLIP, 215, 4, 0),
};

static const u16 sParticleOam_AbsorbIceXPreVaria_Frame12[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-7, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 241, 4, 0),
    OAM_ENTRY(-13, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 208, 4, 0),
    OAM_ENTRY(-1, -1, OAM_DIMS_8x8, OAM_XY_FLIP, 241, 4, 0),
    OAM_ENTRY(5, 5, OAM_DIMS_8x8, OAM_XY_FLIP, 208, 4, 0),
};

static const u16 sParticleOam_AbsorbIceXPreVaria_Frame13[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 208, 4, 0),
    OAM_ENTRY(16, -24, OAM_DIMS_8x8, OAM_X_FLIP, 215, 4, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 208, 4, 0),
    OAM_ENTRY(-24, 16, OAM_DIMS_8x8, OAM_Y_FLIP, 215, 4, 0),
};

static const u16 sParticleOam_AbsorbIceXPreVaria_Frame14[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-2, -14, OAM_DIMS_16x16, OAM_X_FLIP, 208, 4, 0),
    OAM_ENTRY(13, -21, OAM_DIMS_8x8, OAM_X_FLIP, 215, 4, 0),
    OAM_ENTRY(-14, -2, OAM_DIMS_16x16, OAM_Y_FLIP, 208, 4, 0),
    OAM_ENTRY(-21, 13, OAM_DIMS_8x8, OAM_Y_FLIP, 215, 4, 0),
};

static const u16 sParticleOam_AbsorbIceXPreVaria_Frame15[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-1, -7, OAM_DIMS_8x8, OAM_X_FLIP, 241, 4, 0),
    OAM_ENTRY(5, -13, OAM_DIMS_8x8, OAM_X_FLIP, 208, 4, 0),
    OAM_ENTRY(-7, -1, OAM_DIMS_8x8, OAM_Y_FLIP, 241, 4, 0),
    OAM_ENTRY(-13, 5, OAM_DIMS_8x8, OAM_Y_FLIP, 208, 4, 0),
};

static const u16 sParticleOam_IceXTrail_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 500, 4, 0),
};

static const u16 sParticleOam_IceXTrail_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 501, 4, 0),
};

static const u16 sParticleOam_IceXTrail_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 470, 4, 0),
};

static const u16 sParticleOam_IceXTrail_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 502, 4, 0),
};

static const u16 sParticleOam_IceXTrail_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 503, 4, 0),
};

static const u16 sParticleOam_IceXTrail_Frame5[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 328, 6, 0),
};

const struct FrameData sParticleOam_Bomb[6] = {
    [0] = {
        .pFrame = sParticleOam_Bomb_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sParticleOam_Bomb_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sParticleOam_Bomb_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sParticleOam_Bomb_Frame3,
        .timer = 3
    },
    [4] = {
        .pFrame = sParticleOam_Bomb_Frame4,
        .timer = 4
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_Explosion2[7] = {
    [0] = {
        .pFrame = sParticleOam_Explosion2_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sParticleOam_Explosion2_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sParticleOam_Explosion2_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sParticleOam_Explosion2_Frame3,
        .timer = 3
    },
    [4] = {
        .pFrame = sParticleOam_Explosion2_Frame4,
        .timer = 4
    },
    [5] = {
        .pFrame = sParticleOam_Explosion2_Frame5,
        .timer = 4
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_Explosion1[7] = {
    [0] = {
        .pFrame = sParticleOam_Explosion2_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sParticleOam_Explosion2_Frame2,
        .timer = 2
    },
    [2] = {
        .pFrame = sParticleOam_Explosion2_Frame3,
        .timer = 3
    },
    [3] = {
        .pFrame = sParticleOam_Explosion1_Frame3,
        .timer = 3
    },
    [4] = {
        .pFrame = sParticleOam_Explosion1_Frame4,
        .timer = 4
    },
    [5] = {
        .pFrame = sParticleOam_Explosion1_Frame5,
        .timer = 4
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_FireBeam[4] = {
    [0] = {
        .pFrame = sParticleOam_FireBeam_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sParticleOam_FireBeam_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sParticleOam_FireBeam_Frame2,
        .timer = 1
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_3ea63c[5] = {
    [0] = {
        .pFrame = sParticleOam_3ea63c_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sParticleOam_3ea63c_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sParticleOam_3ea63c_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sParticleOam_3ea63c_Frame3,
        .timer = 4
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_AbsorbHealthXAbsorbing[33] = {
    [0] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame0,
        .timer = 1
    },
    [3] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [4] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame4,
        .timer = 1
    },
    [5] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [6] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame4,
        .timer = 1
    },
    [7] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [8] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame8,
        .timer = 1
    },
    [9] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [10] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame8,
        .timer = 1
    },
    [11] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [12] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame12,
        .timer = 1
    },
    [13] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [14] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame12,
        .timer = 1
    },
    [15] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [16] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame16,
        .timer = 1
    },
    [17] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [18] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame16,
        .timer = 1
    },
    [19] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [20] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame20,
        .timer = 1
    },
    [21] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [22] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame20,
        .timer = 1
    },
    [23] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [24] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame24,
        .timer = 1
    },
    [25] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [26] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame24,
        .timer = 1
    },
    [27] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [28] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame28,
        .timer = 1
    },
    [29] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [30] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame28,
        .timer = 1
    },
    [31] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [32] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_AbsorbHealthXEnding[16] = {
    [0] = {
        .pFrame = sParticleOam_AbsorbHealthXEnding_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sParticleOam_AbsorbHealthXEnding_Frame2,
        .timer = 1
    },
    [3] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [4] = {
        .pFrame = sParticleOam_AbsorbHealthXEnding_Frame4,
        .timer = 1
    },
    [5] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [6] = {
        .pFrame = sParticleOam_AbsorbHealthXEnding_Frame6,
        .timer = 1
    },
    [7] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [8] = {
        .pFrame = sParticleOam_AbsorbHealthXEnding_Frame8,
        .timer = 1
    },
    [9] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [10] = {
        .pFrame = sParticleOam_AbsorbHealthXEnding_Frame10,
        .timer = 1
    },
    [11] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [12] = {
        .pFrame = sParticleOam_AbsorbHealthXEnding_Frame12,
        .timer = 1
    },
    [13] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [14] = {
        .pFrame = sParticleOam_AbsorbHealthXEnding_Frame14,
        .timer = 1
    },
    [15] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_AbsorbMissileXAbsorbing[33] = {
    [0] = {
        .pFrame = sParticleOam_AbsorbMissileXAbsorbing_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sParticleOam_AbsorbMissileXAbsorbing_Frame0,
        .timer = 1
    },
    [3] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [4] = {
        .pFrame = sParticleOam_AbsorbMissileXAbsorbing_Frame4,
        .timer = 1
    },
    [5] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [6] = {
        .pFrame = sParticleOam_AbsorbMissileXAbsorbing_Frame4,
        .timer = 1
    },
    [7] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [8] = {
        .pFrame = sParticleOam_AbsorbMissileXAbsorbing_Frame8,
        .timer = 1
    },
    [9] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [10] = {
        .pFrame = sParticleOam_AbsorbMissileXAbsorbing_Frame8,
        .timer = 1
    },
    [11] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [12] = {
        .pFrame = sParticleOam_AbsorbMissileXAbsorbing_Frame12,
        .timer = 1
    },
    [13] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [14] = {
        .pFrame = sParticleOam_AbsorbMissileXAbsorbing_Frame12,
        .timer = 1
    },
    [15] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [16] = {
        .pFrame = sParticleOam_AbsorbMissileXAbsorbing_Frame16,
        .timer = 1
    },
    [17] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [18] = {
        .pFrame = sParticleOam_AbsorbMissileXAbsorbing_Frame16,
        .timer = 1
    },
    [19] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [20] = {
        .pFrame = sParticleOam_AbsorbMissileXAbsorbing_Frame20,
        .timer = 1
    },
    [21] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [22] = {
        .pFrame = sParticleOam_AbsorbMissileXAbsorbing_Frame20,
        .timer = 1
    },
    [23] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [24] = {
        .pFrame = sParticleOam_AbsorbMissileXAbsorbing_Frame24,
        .timer = 1
    },
    [25] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [26] = {
        .pFrame = sParticleOam_AbsorbMissileXAbsorbing_Frame24,
        .timer = 1
    },
    [27] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [28] = {
        .pFrame = sParticleOam_AbsorbMissileXAbsorbing_Frame28,
        .timer = 1
    },
    [29] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [30] = {
        .pFrame = sParticleOam_AbsorbMissileXAbsorbing_Frame28,
        .timer = 1
    },
    [31] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [32] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_AbsorbMissileXEnding[16] = {
    [0] = {
        .pFrame = sParticleOam_AbsorbMissileXEnding_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sParticleOam_AbsorbMissileXEnding_Frame2,
        .timer = 1
    },
    [3] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [4] = {
        .pFrame = sParticleOam_AbsorbMissileXEnding_Frame4,
        .timer = 1
    },
    [5] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [6] = {
        .pFrame = sParticleOam_AbsorbMissileXEnding_Frame6,
        .timer = 1
    },
    [7] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [8] = {
        .pFrame = sParticleOam_AbsorbMissileXEnding_Frame8,
        .timer = 1
    },
    [9] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [10] = {
        .pFrame = sParticleOam_AbsorbMissileXEnding_Frame10,
        .timer = 1
    },
    [11] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [12] = {
        .pFrame = sParticleOam_AbsorbMissileXEnding_Frame12,
        .timer = 1
    },
    [13] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [14] = {
        .pFrame = sParticleOam_AbsorbMissileXEnding_Frame14,
        .timer = 1
    },
    [15] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_3ea974[5] = {
    [0] = {
        .pFrame = sParticleOam_3ea974_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sParticleOam_3ea974_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sParticleOam_3ea974_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sParticleOam_3ea974_Frame3,
        .timer = 6
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_Explosion4[7] = {
    [0] = {
        .pFrame = sParticleOam_Explosion4_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sParticleOam_Explosion4_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sParticleOam_Explosion4_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sParticleOam_Explosion4_Frame3,
        .timer = 6
    },
    [4] = {
        .pFrame = sParticleOam_Explosion4_Frame4,
        .timer = 6
    },
    [5] = {
        .pFrame = sParticleOam_Explosion4_Frame5,
        .timer = 6
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_Explosion3[7] = {
    [0] = {
        .pFrame = sParticleOam_Explosion2_Frame1,
        .timer = 6
    },
    [1] = {
        .pFrame = sParticleOam_Explosion2_Frame2,
        .timer = 6
    },
    [2] = {
        .pFrame = sParticleOam_Explosion2_Frame3,
        .timer = 6
    },
    [3] = {
        .pFrame = sParticleOam_Explosion3_Frame3,
        .timer = 6
    },
    [4] = {
        .pFrame = sParticleOam_Explosion3_Frame4,
        .timer = 6
    },
    [5] = {
        .pFrame = sParticleOam_Explosion3_Frame5,
        .timer = 6
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_SuperMissileExplosion[6] = {
    [0] = {
        .pFrame = sParticleOam_SuperMissileExplosion_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sParticleOam_SuperMissileExplosion_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sParticleOam_SuperMissileExplosion_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sParticleOam_SuperMissileExplosion_Frame3,
        .timer = 3
    },
    [4] = {
        .pFrame = sParticleOam_SuperMissileExplosion_Frame4,
        .timer = 3
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_NormalMissileExplosion[7] = {
    [0] = {
        .pFrame = sParticleOam_Explosion2_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sParticleOam_Explosion2_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sParticleOam_Explosion2_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sParticleOam_Explosion2_Frame4,
        .timer = 2
    },
    [4] = {
        .pFrame = sParticleOam_NormalMissileExplosion_Frame4,
        .timer = 2
    },
    [5] = {
        .pFrame = sParticleOam_NormalMissileExplosion_Frame5,
        .timer = 2
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_Explosion6[5] = {
    [0] = {
        .pFrame = sParticleOam_Explosion6_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sParticleOam_Explosion6_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sParticleOam_Explosion6_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sParticleOam_Explosion6_Frame3,
        .timer = 6
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_Explosion5[5] = {
    [0] = {
        .pFrame = sParticleOam_Explosion5_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sParticleOam_Explosion5_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sParticleOam_Explosion5_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sParticleOam_Explosion5_Frame3,
        .timer = 8
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_AbsorbRedXAbsorbing[33] = {
    [0] = {
        .pFrame = sParticleOam_AbsorbRedXAbsorbing_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sParticleOam_AbsorbRedXAbsorbing_Frame0,
        .timer = 1
    },
    [3] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [4] = {
        .pFrame = sParticleOam_AbsorbRedXAbsorbing_Frame4,
        .timer = 1
    },
    [5] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [6] = {
        .pFrame = sParticleOam_AbsorbRedXAbsorbing_Frame4,
        .timer = 1
    },
    [7] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [8] = {
        .pFrame = sParticleOam_AbsorbRedXAbsorbing_Frame8,
        .timer = 1
    },
    [9] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [10] = {
        .pFrame = sParticleOam_AbsorbRedXAbsorbing_Frame8,
        .timer = 1
    },
    [11] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [12] = {
        .pFrame = sParticleOam_AbsorbRedXAbsorbing_Frame12,
        .timer = 1
    },
    [13] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [14] = {
        .pFrame = sParticleOam_AbsorbRedXAbsorbing_Frame12,
        .timer = 1
    },
    [15] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [16] = {
        .pFrame = sParticleOam_AbsorbRedXAbsorbing_Frame16,
        .timer = 1
    },
    [17] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [18] = {
        .pFrame = sParticleOam_AbsorbRedXAbsorbing_Frame16,
        .timer = 1
    },
    [19] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [20] = {
        .pFrame = sParticleOam_AbsorbRedXAbsorbing_Frame20,
        .timer = 1
    },
    [21] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [22] = {
        .pFrame = sParticleOam_AbsorbRedXAbsorbing_Frame20,
        .timer = 1
    },
    [23] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [24] = {
        .pFrame = sParticleOam_AbsorbRedXAbsorbing_Frame24,
        .timer = 1
    },
    [25] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [26] = {
        .pFrame = sParticleOam_AbsorbRedXAbsorbing_Frame24,
        .timer = 1
    },
    [27] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [28] = {
        .pFrame = sParticleOam_AbsorbRedXAbsorbing_Frame28,
        .timer = 1
    },
    [29] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [30] = {
        .pFrame = sParticleOam_AbsorbRedXAbsorbing_Frame28,
        .timer = 1
    },
    [31] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [32] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_AbsorbRedXEnding[16] = {
    [0] = {
        .pFrame = sParticleOam_AbsorbRedXEnding_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sParticleOam_AbsorbRedXEnding_Frame2,
        .timer = 1
    },
    [3] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [4] = {
        .pFrame = sParticleOam_AbsorbRedXEnding_Frame4,
        .timer = 1
    },
    [5] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [6] = {
        .pFrame = sParticleOam_AbsorbRedXEnding_Frame6,
        .timer = 1
    },
    [7] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [8] = {
        .pFrame = sParticleOam_AbsorbRedXEnding_Frame8,
        .timer = 1
    },
    [9] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [10] = {
        .pFrame = sParticleOam_AbsorbRedXEnding_Frame10,
        .timer = 1
    },
    [11] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [12] = {
        .pFrame = sParticleOam_AbsorbRedXEnding_Frame12,
        .timer = 1
    },
    [13] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [14] = {
        .pFrame = sParticleOam_AbsorbRedXEnding_Frame14,
        .timer = 1
    },
    [15] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_IceMissileExplosion[6] = {
    [0] = {
        .pFrame = sParticleOam_IceMissileExplosion_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sParticleOam_IceMissileExplosion_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sParticleOam_IceMissileExplosion_Frame2,
        .timer = 16
    },
    [3] = {
        .pFrame = sParticleOam_IceMissileExplosion_Frame3,
        .timer = 8
    },
    [4] = {
        .pFrame = sParticleOam_IceMissileExplosion_Frame4,
        .timer = 8
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_DiffusionMissileExplosion[6] = {
    [0] = {
        .pFrame = sParticleOam_IceMissileExplosion_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sParticleOam_IceMissileExplosion_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sParticleOam_IceMissileExplosion_Frame2,
        .timer = 16
    },
    [3] = {
        .pFrame = sParticleOam_IceMissileExplosion_Frame3,
        .timer = 8
    },
    [4] = {
        .pFrame = sParticleOam_IceMissileExplosion_Frame4,
        .timer = 8
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_ChargedDiffusionMissileExplosion[7] = {
    [0] = {
        .pFrame = sParticleOam_IceMissileExplosion_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sParticleOam_IceMissileExplosion_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sParticleOam_IceMissileExplosion_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sParticleOam_ChargedDiffusionMissileExplosion_Frame3,
        .timer = 14
    },
    [4] = {
        .pFrame = sParticleOam_ChargedDiffusionMissileExplosion_Frame4,
        .timer = 7
    },
    [5] = {
        .pFrame = sParticleOam_ChargedDiffusionMissileExplosion_Frame5,
        .timer = 7
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDiffusionFlakeOam[6] = {
    [0] = {
        .pFrame = sParticleOam_IceMissileExplosion_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sParticleOam_IceMissileExplosion_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sParticleOam_IceMissileExplosion_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sParticleOam_ChargedDiffusionMissileExplosion_Frame3,
        .timer = 4
    },
    [4] = {
        .pFrame = sParticleOam_ChargedDiffusionMissileExplosion_Frame4,
        .timer = 4
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_AbsorbIceXPreVaria[24] = {
    [0] = {
        .pFrame = sParticleOam_IceMissileExplosion_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sParticleOam_IceMissileExplosion_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sParticleOam_IceMissileExplosion_Frame0,
        .timer = 2
    },
    [3] = {
        .pFrame = sParticleOam_IceMissileExplosion_Frame1,
        .timer = 2
    },
    [4] = {
        .pFrame = sParticleOam_IceMissileExplosion_Frame2,
        .timer = 2
    },
    [5] = {
        .pFrame = sParticleOam_ChargedDiffusionMissileExplosion_Frame3,
        .timer = 2
    },
    [6] = {
        .pFrame = sParticleOam_IceMissileExplosion_Frame2,
        .timer = 2
    },
    [7] = {
        .pFrame = sParticleOam_ChargedDiffusionMissileExplosion_Frame3,
        .timer = 16
    },
    [8] = {
        .pFrame = sParticleOam_ChargedDiffusionMissileExplosion_Frame4,
        .timer = 4
    },
    [9] = {
        .pFrame = sParticleOam_ChargedDiffusionMissileExplosion_Frame5,
        .timer = 8
    },
    [10] = {
        .pFrame = sParticleOam_AbsorbIceXPreVaria_Frame10,
        .timer = 1
    },
    [11] = {
        .pFrame = sParticleOam_AbsorbIceXPreVaria_Frame11,
        .timer = 1
    },
    [12] = {
        .pFrame = sParticleOam_AbsorbIceXPreVaria_Frame12,
        .timer = 1
    },
    [13] = {
        .pFrame = sParticleOam_AbsorbIceXPreVaria_Frame13,
        .timer = 1
    },
    [14] = {
        .pFrame = sParticleOam_AbsorbIceXPreVaria_Frame14,
        .timer = 1
    },
    [15] = {
        .pFrame = sParticleOam_AbsorbIceXPreVaria_Frame15,
        .timer = 1
    },
    [16] = {
        .pFrame = sParticleOam_AbsorbIceXPreVaria_Frame16,
        .timer = 8
    },
    [17] = {
        .pFrame = sParticleOam_AbsorbIceXPreVaria_Frame17,
        .timer = 8
    },
    [18] = {
        .pFrame = sParticleOam_AbsorbIceXPreVaria_Frame18,
        .timer = 8
    },
    [19] = {
        .pFrame = sParticleOam_AbsorbIceXPreVaria_Frame19,
        .timer = 8
    },
    [20] = {
        .pFrame = sParticleOam_AbsorbIceXPreVaria_Frame20,
        .timer = 8
    },
    [21] = {
        .pFrame = sParticleOam_AbsorbIceXPreVaria_Frame21,
        .timer = 8
    },
    [22] = {
        .pFrame = sParticleOam_AbsorbIceXPreVaria_Frame22,
        .timer = 8
    },
    [23] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_AbsorbCoreXAbsorbing[33] = {
    [0] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sParticleOam_AbsorbMissileXAbsorbing_Frame0,
        .timer = 1
    },
    [3] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [4] = {
        .pFrame = sParticleOam_AbsorbRedXAbsorbing_Frame4,
        .timer = 1
    },
    [5] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [6] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame4,
        .timer = 1
    },
    [7] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [8] = {
        .pFrame = sParticleOam_AbsorbMissileXAbsorbing_Frame8,
        .timer = 1
    },
    [9] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [10] = {
        .pFrame = sParticleOam_AbsorbRedXAbsorbing_Frame8,
        .timer = 1
    },
    [11] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [12] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame12,
        .timer = 1
    },
    [13] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [14] = {
        .pFrame = sParticleOam_AbsorbMissileXAbsorbing_Frame12,
        .timer = 1
    },
    [15] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [16] = {
        .pFrame = sParticleOam_AbsorbRedXAbsorbing_Frame16,
        .timer = 1
    },
    [17] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [18] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame16,
        .timer = 1
    },
    [19] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [20] = {
        .pFrame = sParticleOam_AbsorbMissileXAbsorbing_Frame20,
        .timer = 1
    },
    [21] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [22] = {
        .pFrame = sParticleOam_AbsorbRedXAbsorbing_Frame20,
        .timer = 1
    },
    [23] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [24] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame24,
        .timer = 1
    },
    [25] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [26] = {
        .pFrame = sParticleOam_AbsorbMissileXAbsorbing_Frame24,
        .timer = 1
    },
    [27] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [28] = {
        .pFrame = sParticleOam_AbsorbRedXAbsorbing_Frame28,
        .timer = 1
    },
    [29] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [30] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame28,
        .timer = 1
    },
    [31] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [32] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_AbsorbCoreXEnding[16] = {
    [0] = {
        .pFrame = sParticleOam_AbsorbHealthXEnding_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sParticleOam_AbsorbMissileXEnding_Frame2,
        .timer = 1
    },
    [3] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [4] = {
        .pFrame = sParticleOam_AbsorbRedXEnding_Frame4,
        .timer = 1
    },
    [5] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [6] = {
        .pFrame = sParticleOam_AbsorbHealthXEnding_Frame6,
        .timer = 1
    },
    [7] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [8] = {
        .pFrame = sParticleOam_AbsorbMissileXEnding_Frame8,
        .timer = 1
    },
    [9] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [10] = {
        .pFrame = sParticleOam_AbsorbRedXEnding_Frame10,
        .timer = 1
    },
    [11] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [12] = {
        .pFrame = sParticleOam_AbsorbHealthXEnding_Frame12,
        .timer = 1
    },
    [13] = {
        .pFrame = sParticleOam_AbsorbHealthXAbsorbing_Frame1,
        .timer = 1
    },
    [14] = {
        .pFrame = sParticleOam_AbsorbMissileXEnding_Frame14,
        .timer = 1
    },
    [15] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_IceXTrail[7] = {
    [0] = {
        .pFrame = sParticleOam_IceXTrail_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sParticleOam_IceXTrail_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sParticleOam_IceXTrail_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sParticleOam_IceXTrail_Frame3,
        .timer = 8
    },
    [4] = {
        .pFrame = sParticleOam_IceXTrail_Frame4,
        .timer = 8
    },
    [5] = {
        .pFrame = sParticleOam_IceXTrail_Frame5,
        .timer = 8
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_DiffusionFlakeTrail[8] = {
    [0] = {
        .pFrame = sParticleOam_AbsorbIceXPreVaria_Frame16,
        .timer = 8
    },
    [1] = {
        .pFrame = sParticleOam_AbsorbIceXPreVaria_Frame17,
        .timer = 8
    },
    [2] = {
        .pFrame = sParticleOam_AbsorbIceXPreVaria_Frame18,
        .timer = 8
    },
    [3] = {
        .pFrame = sParticleOam_AbsorbIceXPreVaria_Frame19,
        .timer = 8
    },
    [4] = {
        .pFrame = sParticleOam_AbsorbIceXPreVaria_Frame20,
        .timer = 8
    },
    [5] = {
        .pFrame = sParticleOam_AbsorbIceXPreVaria_Frame21,
        .timer = 8
    },
    [6] = {
        .pFrame = sParticleOam_AbsorbIceXPreVaria_Frame22,
        .timer = 8
    },
    [7] = FRAME_DATA_TERMINATOR
};

static const u16 sSpriteDebrisOam_NormalCloud_Frame5[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 369, 3, 0),
    OAM_ENTRY(-8, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
};

static const u16 sSpriteDebrisOam_NormalCloud_Frame6[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 368, 3, 0),
    OAM_ENTRY(-8, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
};

static const u16 sSpriteDebrisOam_NormalCloud_Frame7[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 367, 3, 0),
    OAM_ENTRY(-8, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
};

static const u16 sSpriteDebrisOam_NormalCloud_Frame8[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 367, 3, 0),
    OAM_ENTRY(-8, -44, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
};

static const u16 sSpriteDebrisOam_NormalCloud_Frame9[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 366, 3, 0),
};

static const u16 sSpriteDebrisOam_NormalCloud_Frame10[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_X_FLIP, 366, 3, 0),
};

static const u16 sParticleOam_HeavyDust_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
};

static const u16 sParticleOam_HeavyDust_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
};

static const u16 sParticleOam_HeavyDust_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
};

static const u16 sParticleOam_HeavyDust_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
};

static const u16 sSpriteDebrisOam_NormalCloud_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 3, 0),
};

static const u16 sSpriteDebrisOam_NormalCloud_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-12, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 402, 3, 0),
    OAM_ENTRY(-4, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 3, 0),
};

static const u16 sSpriteDebrisOam_NormalCloud_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 404, 3, 0),
    OAM_ENTRY(0, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 402, 3, 0),
};

static const u16 sSpriteDebrisOam_NormalCloud_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-20, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 406, 3, 0),
    OAM_ENTRY(4, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 404, 3, 0),
};

static const u16 sSpriteDebrisOam_NormalCloud_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(8, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 406, 3, 0),
};

static const u16 sParticleOam_EnterOrExitWater_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-5, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 351, 3, 0),
    OAM_ENTRY(-3, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 351, 3, 0),
    OAM_ENTRY(-8, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
};

static const u16 sParticleOam_EnterOrExitWater_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-6, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 351, 3, 0),
    OAM_ENTRY(-3, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 351, 3, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
};

static const u16 sParticleOam_EnterOrExitWater_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -3, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(-6, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 351, 3, 0),
    OAM_ENTRY(-2, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 351, 3, 0),
    OAM_ENTRY(-6, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 383, 3, 0),
    OAM_ENTRY(-2, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 383, 3, 0),
};

static const u16 sParticleOam_EnterOrExitWater_Frame3[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-1, -16, OAM_DIMS_8x8, OAM_X_FLIP, 351, 3, 0),
    OAM_ENTRY(-7, -16, OAM_DIMS_8x8, OAM_X_FLIP, 351, 3, 0),
    OAM_ENTRY(-1, -8, OAM_DIMS_8x8, OAM_X_FLIP, 383, 3, 0),
    OAM_ENTRY(-7, -8, OAM_DIMS_8x8, OAM_X_FLIP, 383, 3, 0),
    OAM_ENTRY(-8, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(0, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(-8, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
};

static const u16 sParticleOam_EnterOrExitWater_Frame4[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 383, 3, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 383, 3, 0),
    OAM_ENTRY(-8, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 351, 3, 0),
    OAM_ENTRY(0, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 351, 3, 0),
    OAM_ENTRY(0, -22, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(-8, -22, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(-8, -1, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
};

static const u16 sParticleOam_EnterOrExitWater_Frame5[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(-9, -7, OAM_DIMS_8x8, OAM_X_FLIP, 383, 3, 0),
    OAM_ENTRY(1, -7, OAM_DIMS_8x8, OAM_X_FLIP, 383, 3, 0),
    OAM_ENTRY(-9, -11, OAM_DIMS_8x8, OAM_X_FLIP, 351, 3, 0),
    OAM_ENTRY(1, -11, OAM_DIMS_8x8, OAM_X_FLIP, 351, 3, 0),
    OAM_ENTRY(0, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(-8, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
};

static const u16 sParticleOam_EnterOrExitWater_Frame6[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-9, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 351, 3, 0),
    OAM_ENTRY(1, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 351, 3, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
    OAM_ENTRY(-8, 1, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
};

static const u16 sParticleOam_EnterOrExitWater_Frame7[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, 2, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(-10, -4, OAM_DIMS_8x8, OAM_X_FLIP, 351, 3, 0),
    OAM_ENTRY(2, -4, OAM_DIMS_8x8, OAM_X_FLIP, 351, 3, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
};

static const u16 sWaterDropOam_Spawning_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 353, 3, 0),
};

static const u16 sWaterDropOam_Spawning_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 353, 3, 0),
};

static const u16 sWaterDropOam_Spawning_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 354, 3, 0),
};

static const u16 sWaterDropOam_Falling_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 352, 3, 0),
};

static const u16 sWaterDropOam_Splashing_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-6, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 192, 3, 0),
    OAM_ENTRY(-2, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 192, 3, 0),
};

static const u16 sWaterDropOam_Splashing_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-6, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 193, 3, 0),
    OAM_ENTRY(-2, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 193, 3, 0),
};

static const u16 sWaterDropOam_Splashing_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-6, -8, OAM_DIMS_8x8, OAM_X_FLIP, 194, 3, 0),
    OAM_ENTRY(-2, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 194, 3, 0),
};

static const u16 sWaterDropOam_Splashing_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-6, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 195, 3, 0),
    OAM_ENTRY(-2, -8, OAM_DIMS_8x8, OAM_X_FLIP, 195, 3, 0),
};

static const u16 sWaterDropOam_Splashing_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-6, -8, OAM_DIMS_8x8, OAM_X_FLIP, 196, 3, 0),
    OAM_ENTRY(-2, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 196, 3, 0),
};

static const u16 sBubbles1Oam_Idle_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-7, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 376, 3, 0),
    OAM_ENTRY(-3, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 378, 3, 0),
};

static const u16 sBubbles1Oam_Idle_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-7, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 377, 3, 0),
    OAM_ENTRY(-2, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 376, 3, 0),
    OAM_ENTRY(-4, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 376, 3, 0),
};

static const u16 sBubbles1Oam_Idle_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 378, 3, 0),
    OAM_ENTRY(-2, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 377, 3, 0),
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 376, 3, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 377, 3, 0),
    OAM_ENTRY(-5, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 377, 3, 0),
};

static const u16 sBubbles1Oam_Idle_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-9, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 379, 3, 0),
    OAM_ENTRY(-2, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 378, 3, 0),
    OAM_ENTRY(-4, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 377, 3, 0),
    OAM_ENTRY(-3, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 378, 3, 0),
    OAM_ENTRY(-5, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 378, 3, 0),
};

static const u16 sBubbles1Oam_Idle_Frame4[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-1, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 379, 3, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 378, 3, 0),
    OAM_ENTRY(-2, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 379, 3, 0),
    OAM_ENTRY(-6, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 379, 3, 0),
    OAM_ENTRY(-3, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 377, 3, 0),
};

static const u16 sBubbles1Oam_Idle_Frame5[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 379, 3, 0),
    OAM_ENTRY(-3, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 377, 3, 0),
};

static const u16 sBubbles1Oam_Idle_Frame6[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-3, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 378, 3, 0),
};

static const u16 sBubbles1Oam_Idle_Frame7[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-3, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 379, 3, 0),
};

static const u16 sBubbles2Oam_Idle_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-5, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 376, 3, 0),
    OAM_ENTRY(-5, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 377, 3, 0),
};

static const u16 sBubbles2Oam_Idle_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 377, 3, 0),
    OAM_ENTRY(-4, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 376, 3, 0),
};

static const u16 sBubbles2Oam_Idle_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-3, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 378, 3, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 377, 3, 0),
    OAM_ENTRY(0, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 376, 3, 0),
};

static const u16 sBubbles2Oam_Idle_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-2, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 379, 3, 0),
    OAM_ENTRY(-4, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 378, 3, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 377, 3, 0),
    OAM_ENTRY(3, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 377, 3, 0),
};

static const u16 sBubbles2Oam_Idle_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 379, 3, 0),
    OAM_ENTRY(1, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 378, 3, 0),
    OAM_ENTRY(-4, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 377, 3, 0),
    OAM_ENTRY(5, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 378, 3, 0),
};

static const u16 sBubbles2Oam_Idle_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(2, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 379, 3, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 377, 3, 0),
    OAM_ENTRY(-3, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 378, 3, 0),
    OAM_ENTRY(6, -22, OAM_DIMS_8x8, OAM_NO_FLIP, 379, 3, 0),
};

static const u16 sBubbles2Oam_Idle_Frame6[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 378, 3, 0),
    OAM_ENTRY(-2, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 379, 3, 0),
};

static const u16 sBubbles2Oam_Idle_Frame7[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 379, 3, 0),
    OAM_ENTRY(-5, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 376, 3, 0),
};

static const u16 sBubbles2Oam_Idle_Frame8[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 377, 3, 0),
};

static const u16 sParticleOam_EnterOrExitWaterBig_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-12, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
    OAM_ENTRY(-4, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
    OAM_ENTRY(-7, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 351, 3, 0),
    OAM_ENTRY(-1, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 351, 3, 0),
};

static const u16 sParticleOam_EnterOrExitWaterBig_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-13, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
    OAM_ENTRY(-3, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 351, 3, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 383, 3, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 351, 3, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 383, 3, 0),
};

static const u16 sParticleOam_EnterOrExitWaterBig_Frame2[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-15, -1, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(-1, -1, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(5, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 351, 3, 0),
    OAM_ENTRY(-13, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 351, 3, 0),
    OAM_ENTRY(-13, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(5, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(-7, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 351, 3, 0),
    OAM_ENTRY(-1, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 351, 3, 0),
};

static const u16 sParticleOam_EnterOrExitWaterBig_Frame3[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 351, 3, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 351, 3, 0),
    OAM_ENTRY(-13, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(5, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(0, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(-8, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 351, 3, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 383, 3, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 351, 3, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 383, 3, 0),
};

static const u16 sParticleOam_EnterOrExitWaterBig_Frame4[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-16, 1, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(0, 1, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(1, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 351, 3, 0),
    OAM_ENTRY(-9, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 351, 3, 0),
    OAM_ENTRY(7, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(-9, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(-17, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 351, 3, 0),
    OAM_ENTRY(-17, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 383, 3, 0),
    OAM_ENTRY(9, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 351, 3, 0),
    OAM_ENTRY(9, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 383, 3, 0),
    OAM_ENTRY(-15, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(1, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
};

static const u16 sParticleOam_EnterOrExitWaterBig_Frame5[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-16, 2, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(0, 2, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(-16, -21, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
    OAM_ENTRY(1, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
    OAM_ENTRY(-18, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 351, 3, 0),
    OAM_ENTRY(10, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 351, 3, 0),
    OAM_ENTRY(2, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 351, 3, 0),
    OAM_ENTRY(2, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 383, 3, 0),
    OAM_ENTRY(-10, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 351, 3, 0),
    OAM_ENTRY(-10, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 383, 3, 0),
    OAM_ENTRY(-9, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
    OAM_ENTRY(8, -21, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
};

static const u16 sParticleOam_EnterOrExitWaterBig_Frame6[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-16, 3, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(0, 3, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(3, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 351, 3, 0),
    OAM_ENTRY(-11, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 351, 3, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
    OAM_ENTRY(-16, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
    OAM_ENTRY(8, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
};

static const u16 sParticleOam_EnterOrExitWaterBig_Frame7[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-16, 5, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(0, 5, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
    OAM_ENTRY(-16, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
    OAM_ENTRY(8, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
};

static const u16 sParticleOam_SpriteEnterOrExitWater_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
    OAM_ENTRY(-8, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
};

static const u16 sParticleOam_SpriteEnterOrExitWater_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
    OAM_ENTRY(-20, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
    OAM_ENTRY(-20, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
};

static const u16 sParticleOam_SpriteEnterOrExitWater_Frame2[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
    OAM_ENTRY(-8, -3, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(-20, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(-20, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
    OAM_ENTRY(-20, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
    OAM_ENTRY(4, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
    OAM_ENTRY(4, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
};

static const u16 sParticleOam_SpriteEnterOrExitWater_Frame3[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(-8, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(-8, -3, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(-21, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(-21, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(-21, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
    OAM_ENTRY(-21, -3, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(4, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
    OAM_ENTRY(4, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
};

static const u16 sParticleOam_SpriteEnterOrExitWater_Frame4[OAM_DATA_SIZE(13)] = {
    13,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(-8, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(-21, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(-21, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(-21, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(-21, -3, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(5, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(5, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(5, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
    OAM_ENTRY(5, -3, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
};

static const u16 sParticleOam_SpriteEnterOrExitWater_Frame5[OAM_DATA_SIZE(13)] = {
    13,
    OAM_ENTRY(1, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(-9, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(-8, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(-22, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(-22, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(-14, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(-22, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(-22, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(5, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(5, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(5, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(5, -3, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
};

static const u16 sParticleOam_SpriteEnterOrExitWater_Frame6[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-8, -1, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(2, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
    OAM_ENTRY(-10, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
    OAM_ENTRY(-14, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(-24, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(-23, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(-23, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(6, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(14, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(6, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(6, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
};

static const u16 sParticleOam_SpriteEnterOrExitWater_Frame7[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(3, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
    OAM_ENTRY(-11, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
    OAM_ENTRY(-23, -1, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(-13, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
    OAM_ENTRY(-25, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
    OAM_ENTRY(15, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(5, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(6, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
};

static const u16 sParticleOam_SpriteEnterOrExitWater_Frame8[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-24, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(-13, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
    OAM_ENTRY(-27, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
    OAM_ENTRY(7, -1, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(17, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
    OAM_ENTRY(5, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
};

static const u16 sParticleOam_SpriteEnterOrExitWater_Frame9[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(8, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(19, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
    OAM_ENTRY(5, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
};

static const u16 sSpriteDebrisOam_IceCloud_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 4, 0),
};

static const u16 sSpriteDebrisOam_IceCloud_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-12, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 402, 4, 0),
    OAM_ENTRY(-4, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 4, 0),
};

static const u16 sSpriteDebrisOam_IceCloud_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 404, 4, 0),
    OAM_ENTRY(0, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 402, 4, 0),
};

static const u16 sSpriteDebrisOam_IceCloud_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-20, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 406, 4, 0),
    OAM_ENTRY(4, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 404, 4, 0),
};

static const u16 sSpriteDebrisOam_IceCloud_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(8, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 406, 4, 0),
};

static const u16 sSpriteDebrisOam_IceCloud_Frame5[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 369, 4, 0),
    OAM_ENTRY(-8, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
};

static const u16 sSpriteDebrisOam_IceCloud_Frame6[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 368, 4, 0),
    OAM_ENTRY(-8, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
};

static const u16 sSpriteDebrisOam_IceCloud_Frame7[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 367, 4, 0),
    OAM_ENTRY(-8, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
};

static const u16 sSpriteDebrisOam_IceCloud_Frame8[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 367, 4, 0),
    OAM_ENTRY(-8, -44, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
};

static const u16 sSpriteDebrisOam_IceCloud_Frame9[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 366, 3, 0),
};

static const u16 sSpriteDebrisOam_IceCloud_Frame10[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_X_FLIP, 366, 3, 0),
};

static const u16 sSpriteDebrisOam_NoCloud_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 369, 3, 0),
};

static const u16 sSpriteDebrisOam_NoCloud_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 368, 3, 0),
};

static const u16 sSpriteDebrisOam_NoCloud_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 367, 3, 0),
};

static const u16 sSpriteDebrisOam_NoCloud_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 366, 3, 0),
};

static const u16 sParticleOam_OutwardIceExplosion_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 4, 0),
    OAM_ENTRY(-2, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 4, 0),
};

static const u16 sParticleOam_OutwardIceExplosion_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-15, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 402, 4, 0),
    OAM_ENTRY(-30, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 4, 0),
    OAM_ENTRY(-15, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 4, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_X_FLIP, 402, 4, 0),
    OAM_ENTRY(14, -16, OAM_DIMS_16x16, OAM_X_FLIP, 400, 4, 0),
    OAM_ENTRY(-1, -20, OAM_DIMS_16x16, OAM_X_FLIP, 400, 4, 0),
};

static const u16 sParticleOam_OutwardIceExplosion_Frame2[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 404, 4, 0),
    OAM_ENTRY(-31, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 402, 4, 0),
    OAM_ENTRY(-46, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 4, 0),
    OAM_ENTRY(-31, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 4, 0),
    OAM_ENTRY(-16, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 402, 4, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 404, 4, 0),
    OAM_ENTRY(15, -16, OAM_DIMS_16x16, OAM_X_FLIP, 402, 4, 0),
    OAM_ENTRY(32, -16, OAM_DIMS_16x16, OAM_X_FLIP, 400, 4, 0),
    OAM_ENTRY(15, -22, OAM_DIMS_16x16, OAM_X_FLIP, 400, 4, 0),
    OAM_ENTRY(0, -20, OAM_DIMS_16x16, OAM_X_FLIP, 402, 4, 0),
};

static const u16 sParticleOam_OutwardIceExplosion_Frame3[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-17, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 406, 4, 0),
    OAM_ENTRY(-32, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 404, 4, 0),
    OAM_ENTRY(-47, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 402, 4, 0),
    OAM_ENTRY(-48, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 4, 0),
    OAM_ENTRY(-32, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 402, 4, 0),
    OAM_ENTRY(-17, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 404, 4, 0),
    OAM_ENTRY(1, -16, OAM_DIMS_16x16, OAM_X_FLIP, 406, 4, 0),
    OAM_ENTRY(16, -16, OAM_DIMS_16x16, OAM_X_FLIP, 404, 4, 0),
    OAM_ENTRY(32, -16, OAM_DIMS_16x16, OAM_X_FLIP, 402, 4, 0),
    OAM_ENTRY(32, -24, OAM_DIMS_16x16, OAM_X_FLIP, 400, 4, 0),
    OAM_ENTRY(16, -22, OAM_DIMS_16x16, OAM_X_FLIP, 402, 4, 0),
    OAM_ENTRY(1, -20, OAM_DIMS_16x16, OAM_X_FLIP, 404, 4, 0),
};

static const u16 sParticleOam_OutwardIceExplosion_Frame4[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-33, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 406, 4, 0),
    OAM_ENTRY(-48, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 404, 4, 0),
    OAM_ENTRY(-50, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 402, 4, 0),
    OAM_ENTRY(-33, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 404, 4, 0),
    OAM_ENTRY(-18, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 406, 4, 0),
    OAM_ENTRY(17, -16, OAM_DIMS_16x16, OAM_X_FLIP, 406, 4, 0),
    OAM_ENTRY(32, -16, OAM_DIMS_16x16, OAM_X_FLIP, 404, 4, 0),
    OAM_ENTRY(34, -26, OAM_DIMS_16x16, OAM_X_FLIP, 402, 4, 0),
    OAM_ENTRY(17, -22, OAM_DIMS_16x16, OAM_X_FLIP, 404, 4, 0),
    OAM_ENTRY(2, -20, OAM_DIMS_16x16, OAM_X_FLIP, 406, 4, 0),
    OAM_ENTRY(-56, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 4, 0),
    OAM_ENTRY(40, -20, OAM_DIMS_16x16, OAM_X_FLIP, 400, 4, 0),
};

static const u16 sParticleOam_OutwardIceExplosion_Frame5[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-49, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 406, 4, 0),
    OAM_ENTRY(-52, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 404, 4, 0),
    OAM_ENTRY(-34, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 406, 4, 0),
    OAM_ENTRY(33, -16, OAM_DIMS_16x16, OAM_X_FLIP, 406, 4, 0),
    OAM_ENTRY(36, -28, OAM_DIMS_16x16, OAM_X_FLIP, 404, 4, 0),
    OAM_ENTRY(18, -24, OAM_DIMS_16x16, OAM_X_FLIP, 406, 4, 0),
    OAM_ENTRY(-56, -20, OAM_DIMS_16x16, OAM_X_FLIP, 402, 4, 0),
    OAM_ENTRY(40, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 402, 4, 0),
};

static const u16 sParticleOam_OutwardIceExplosion_Frame6[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-54, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 406, 4, 0),
    OAM_ENTRY(38, -30, OAM_DIMS_16x16, OAM_X_FLIP, 406, 4, 0),
    OAM_ENTRY(-56, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 404, 4, 0),
    OAM_ENTRY(40, -20, OAM_DIMS_16x16, OAM_X_FLIP, 404, 4, 0),
};

static const u16 sParticleOam_OutwardIceExplosion_Frame7[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-56, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 406, 4, 0),
    OAM_ENTRY(40, -20, OAM_DIMS_16x16, OAM_X_FLIP, 406, 4, 0),
};

static const u16 sParticleOam_ScrewAttackKilled_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 202, 3, 0),
};

static const u16 sParticleOam_ScrewAttackKilled_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 229, 3, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 229, 3, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 229, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 229, 3, 0),
};

static const u16 sParticleOam_ScrewAttackKilled_Frame2[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 262, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 262, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 262, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 262, 3, 0),
    OAM_ENTRY(2, -18, OAM_DIMS_16x16, OAM_X_FLIP, 400, 3, 0),
    OAM_ENTRY(-18, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 3, 0),
    OAM_ENTRY(2, 2, OAM_DIMS_16x16, OAM_XY_FLIP, 400, 3, 0),
    OAM_ENTRY(-18, 2, OAM_DIMS_16x16, OAM_Y_FLIP, 400, 3, 0),
};

static const u16 sParticleOam_ScrewAttackKilled_Frame3[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 264, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 264, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 264, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 264, 3, 0),
    OAM_ENTRY(-24, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 402, 3, 0),
    OAM_ENTRY(-36, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 3, 0),
    OAM_ENTRY(8, -24, OAM_DIMS_16x16, OAM_X_FLIP, 402, 3, 0),
    OAM_ENTRY(20, -32, OAM_DIMS_16x16, OAM_X_FLIP, 400, 3, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_16x16, OAM_Y_FLIP, 402, 3, 0),
    OAM_ENTRY(-32, 16, OAM_DIMS_16x16, OAM_Y_FLIP, 400, 3, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_XY_FLIP, 402, 3, 0),
    OAM_ENTRY(16, 16, OAM_DIMS_16x16, OAM_XY_FLIP, 400, 3, 0),
};

static const u16 sParticleOam_ScrewAttackKilled_Frame4[OAM_DATA_SIZE(16)] = {
    16,
    OAM_ENTRY(-24, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(8, -24, OAM_DIMS_16x16, OAM_X_FLIP, 396, 3, 0),
    OAM_ENTRY(-36, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 402, 3, 0),
    OAM_ENTRY(-48, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 3, 0),
    OAM_ENTRY(20, -32, OAM_DIMS_16x16, OAM_X_FLIP, 402, 3, 0),
    OAM_ENTRY(32, -40, OAM_DIMS_16x16, OAM_X_FLIP, 400, 3, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_16x16, OAM_Y_FLIP, 396, 3, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_XY_FLIP, 396, 3, 0),
    OAM_ENTRY(-32, 16, OAM_DIMS_16x16, OAM_Y_FLIP, 402, 3, 0),
    OAM_ENTRY(-40, 24, OAM_DIMS_16x16, OAM_Y_FLIP, 400, 3, 0),
    OAM_ENTRY(16, 16, OAM_DIMS_16x16, OAM_XY_FLIP, 402, 3, 0),
    OAM_ENTRY(24, 24, OAM_DIMS_16x16, OAM_XY_FLIP, 400, 3, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 266, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 266, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 266, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 266, 3, 0),
};

static const u16 sParticleOam_ScrewAttackKilled_Frame5[OAM_DATA_SIZE(16)] = {
    16,
    OAM_ENTRY(-24, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(8, -24, OAM_DIMS_16x16, OAM_X_FLIP, 398, 3, 0),
    OAM_ENTRY(-50, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 402, 3, 0),
    OAM_ENTRY(34, -40, OAM_DIMS_16x16, OAM_X_FLIP, 402, 3, 0),
    OAM_ENTRY(-36, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(20, -32, OAM_DIMS_16x16, OAM_X_FLIP, 396, 3, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_16x16, OAM_Y_FLIP, 398, 3, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_XY_FLIP, 398, 3, 0),
    OAM_ENTRY(-42, 26, OAM_DIMS_16x16, OAM_Y_FLIP, 402, 3, 0),
    OAM_ENTRY(26, 26, OAM_DIMS_16x16, OAM_XY_FLIP, 402, 3, 0),
    OAM_ENTRY(-32, 16, OAM_DIMS_16x16, OAM_Y_FLIP, 396, 3, 0),
    OAM_ENTRY(16, 16, OAM_DIMS_16x16, OAM_XY_FLIP, 396, 3, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 268, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 268, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 268, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 268, 3, 0),
};

static const u16 sParticleOam_ScrewAttackKilled_Frame6[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-52, -42, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(-36, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(36, -42, OAM_DIMS_16x16, OAM_X_FLIP, 396, 3, 0),
    OAM_ENTRY(20, -32, OAM_DIMS_16x16, OAM_X_FLIP, 398, 3, 0),
    OAM_ENTRY(-44, 28, OAM_DIMS_16x16, OAM_Y_FLIP, 396, 3, 0),
    OAM_ENTRY(-32, 16, OAM_DIMS_16x16, OAM_Y_FLIP, 398, 3, 0),
    OAM_ENTRY(28, 28, OAM_DIMS_16x16, OAM_XY_FLIP, 396, 3, 0),
    OAM_ENTRY(16, 16, OAM_DIMS_16x16, OAM_XY_FLIP, 398, 3, 0),
};

static const u16 sParticleOam_ScrewAttackKilled_Frame7[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-54, -44, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(38, -44, OAM_DIMS_16x16, OAM_X_FLIP, 398, 3, 0),
    OAM_ENTRY(-46, 30, OAM_DIMS_16x16, OAM_Y_FLIP, 398, 3, 0),
    OAM_ENTRY(30, 30, OAM_DIMS_16x16, OAM_XY_FLIP, 398, 3, 0),
};

static const u16 sParticleOam_SpeedboosterKilled_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 202, 3, 0),
};

static const u16 sParticleOam_SpeedboosterKilled_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 229, 3, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 229, 3, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 229, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 229, 3, 0),
    OAM_ENTRY(-12, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 202, 3, 0),
};

static const u16 sParticleOam_SpeedboosterKilled_Frame2[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 262, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 262, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 262, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 262, 3, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 229, 3, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_8x8, OAM_Y_FLIP, 229, 3, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_8x8, OAM_X_FLIP, 229, 3, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_XY_FLIP, 229, 3, 0),
    OAM_ENTRY(4, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 202, 3, 0),
};

static const u16 sParticleOam_SpeedboosterKilled_Frame3[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 264, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 264, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 264, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 264, 3, 0),
    OAM_ENTRY(-24, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 262, 3, 0),
    OAM_ENTRY(-24, -8, OAM_DIMS_16x16, OAM_Y_FLIP, 262, 3, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_X_FLIP, 262, 3, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_XY_FLIP, 262, 3, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 229, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_8x8, OAM_Y_FLIP, 229, 3, 0),
    OAM_ENTRY(8, -24, OAM_DIMS_8x8, OAM_X_FLIP, 229, 3, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_8x8, OAM_XY_FLIP, 229, 3, 0),
};

static const u16 sParticleOam_SpeedboosterKilled_Frame4[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 266, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 266, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 266, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 266, 3, 0),
    OAM_ENTRY(-24, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 264, 3, 0),
    OAM_ENTRY(-24, -8, OAM_DIMS_16x16, OAM_Y_FLIP, 264, 3, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_X_FLIP, 264, 3, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_XY_FLIP, 264, 3, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 262, 3, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 262, 3, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_16x16, OAM_X_FLIP, 262, 3, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x16, OAM_XY_FLIP, 262, 3, 0),
};

static const u16 sParticleOam_SpeedboosterKilled_Frame5[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 268, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 268, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 268, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 268, 3, 0),
    OAM_ENTRY(-24, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 266, 3, 0),
    OAM_ENTRY(-24, -8, OAM_DIMS_16x16, OAM_Y_FLIP, 266, 3, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_X_FLIP, 266, 3, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_XY_FLIP, 266, 3, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 264, 3, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 264, 3, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_16x16, OAM_X_FLIP, 264, 3, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x16, OAM_XY_FLIP, 264, 3, 0),
};

static const u16 sParticleOam_SpeedboosterKilled_Frame6[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-24, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 268, 3, 0),
    OAM_ENTRY(-24, -8, OAM_DIMS_16x16, OAM_Y_FLIP, 268, 3, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_X_FLIP, 268, 3, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_XY_FLIP, 268, 3, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 266, 3, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 266, 3, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_16x16, OAM_X_FLIP, 266, 3, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x16, OAM_XY_FLIP, 266, 3, 0),
};

static const u16 sParticleOam_SpeedboosterKilled_Frame7[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 268, 3, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 268, 3, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_16x16, OAM_X_FLIP, 268, 3, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x16, OAM_XY_FLIP, 268, 3, 0),
};

static const u16 sParticleOam_ShinesparkKilled_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 3, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 3, 0),
    OAM_ENTRY(-12, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 3, 0),
};

static const u16 sParticleOam_ShinesparkKilled_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 3, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 402, 3, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 402, 3, 0),
    OAM_ENTRY(-12, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 402, 3, 0),
    OAM_ENTRY(-12, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 3, 0),
    OAM_ENTRY(-18, 2, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 3, 0),
};

static const u16 sParticleOam_ShinesparkKilled_Frame2[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(24, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 3, 0),
    OAM_ENTRY(8, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 402, 3, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 404, 3, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 404, 3, 0),
    OAM_ENTRY(-12, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 404, 3, 0),
    OAM_ENTRY(-12, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 402, 3, 0),
    OAM_ENTRY(-18, 2, OAM_DIMS_16x16, OAM_NO_FLIP, 402, 3, 0),
    OAM_ENTRY(-16, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 3, 0),
    OAM_ENTRY(-28, 12, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 3, 0),
};

static const u16 sParticleOam_ShinesparkKilled_Frame3[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(24, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 402, 3, 0),
    OAM_ENTRY(8, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 404, 3, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 406, 3, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 406, 3, 0),
    OAM_ENTRY(-12, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 406, 3, 0),
    OAM_ENTRY(-12, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 404, 3, 0),
    OAM_ENTRY(-18, 2, OAM_DIMS_16x16, OAM_NO_FLIP, 404, 3, 0),
    OAM_ENTRY(-16, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 402, 3, 0),
    OAM_ENTRY(-28, 12, OAM_DIMS_16x16, OAM_NO_FLIP, 402, 3, 0),
};

static const u16 sParticleOam_ShinesparkKilled_Frame4[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-12, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 406, 3, 0),
    OAM_ENTRY(-18, 2, OAM_DIMS_16x16, OAM_NO_FLIP, 406, 3, 0),
    OAM_ENTRY(8, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 406, 3, 0),
    OAM_ENTRY(-16, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 404, 3, 0),
    OAM_ENTRY(24, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 404, 3, 0),
    OAM_ENTRY(-28, 12, OAM_DIMS_16x16, OAM_NO_FLIP, 404, 3, 0),
    OAM_ENTRY(-20, -56, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
    OAM_ENTRY(40, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
    OAM_ENTRY(-38, 22, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
};

static const u16 sParticleOam_ShinesparkKilled_Frame5[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-28, 12, OAM_DIMS_16x16, OAM_NO_FLIP, 406, 3, 0),
    OAM_ENTRY(-16, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 406, 3, 0),
    OAM_ENTRY(24, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 406, 3, 0),
    OAM_ENTRY(-20, -56, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(40, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(-38, 22, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
};

static const u16 sParticleOam_ShinesparkKilled_Frame6[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-20, -56, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(40, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(-38, 22, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
};

static const u16 sOam_3ebd40[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-20, -56, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(40, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(-38, 22, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
};

static const u16 sParticleOam_PseudoScrewKilled_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-12, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 3, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_16x16, OAM_X_FLIP, 400, 3, 0),
};

static const u16 sParticleOam_PseudoScrewKilled_Frame1[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-12, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 402, 3, 0),
    OAM_ENTRY(-24, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 3, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_16x16, OAM_X_FLIP, 402, 3, 0),
    OAM_ENTRY(4, -8, OAM_DIMS_16x16, OAM_X_FLIP, 400, 3, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 262, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 262, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 262, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 262, 3, 0),
};

static const u16 sParticleOam_PseudoScrewKilled_Frame2[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-12, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 404, 3, 0),
    OAM_ENTRY(-24, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 402, 3, 0),
    OAM_ENTRY(-36, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 3, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_16x16, OAM_X_FLIP, 404, 3, 0),
    OAM_ENTRY(12, -8, OAM_DIMS_16x16, OAM_X_FLIP, 402, 3, 0),
    OAM_ENTRY(21, -8, OAM_DIMS_16x16, OAM_X_FLIP, 400, 3, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 264, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 264, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 264, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 264, 3, 0),
};

static const u16 sParticleOam_PseudoScrewKilled_Frame3[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-12, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 406, 3, 0),
    OAM_ENTRY(-24, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 404, 3, 0),
    OAM_ENTRY(-42, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 402, 3, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_16x16, OAM_X_FLIP, 406, 3, 0),
    OAM_ENTRY(8, -8, OAM_DIMS_16x16, OAM_X_FLIP, 404, 3, 0),
    OAM_ENTRY(26, -8, OAM_DIMS_16x16, OAM_X_FLIP, 402, 3, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 266, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 266, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 266, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 266, 3, 0),
};

static const u16 sParticleOam_PseudoScrewKilled_Frame4[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-20, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 406, 3, 0),
    OAM_ENTRY(-44, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 404, 3, 0),
    OAM_ENTRY(-20, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 406, 3, 0),
    OAM_ENTRY(-28, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 404, 3, 0),
    OAM_ENTRY(4, -8, OAM_DIMS_16x16, OAM_X_FLIP, 406, 3, 0),
    OAM_ENTRY(28, -8, OAM_DIMS_16x16, OAM_X_FLIP, 404, 3, 0),
    OAM_ENTRY(4, -8, OAM_DIMS_16x16, OAM_X_FLIP, 406, 3, 0),
    OAM_ENTRY(12, -8, OAM_DIMS_16x16, OAM_X_FLIP, 404, 3, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 268, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 268, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 268, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 268, 3, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
};

static const u16 sParticleOam_PseudoScrewKilled_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-45, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 406, 3, 0),
    OAM_ENTRY(29, -8, OAM_DIMS_16x16, OAM_X_FLIP, 406, 3, 0),
    OAM_ENTRY(-20, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(4, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
};

static const u16 sParticleOam_PseudoScrewKilled_Frame6[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(-24, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
};

static const u16 sParticleOam_PseudoScrewKilled_Frame7[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-28, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(12, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
};

static const u16 sParticleOam_OutwardSmoke_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
    OAM_ENTRY(-2, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
};

static const u16 sParticleOam_OutwardSmoke_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-30, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(-15, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
    OAM_ENTRY(14, -16, OAM_DIMS_16x16, OAM_X_FLIP, 392, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 394, 3, 0),
    OAM_ENTRY(-1, -20, OAM_DIMS_16x16, OAM_X_FLIP, 392, 3, 0),
};

static const u16 sParticleOam_OutwardSmoke_Frame2[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-46, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
    OAM_ENTRY(-31, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(-31, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
    OAM_ENTRY(-16, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(30, -16, OAM_DIMS_16x16, OAM_X_FLIP, 392, 3, 0),
    OAM_ENTRY(15, -16, OAM_DIMS_16x16, OAM_X_FLIP, 394, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 396, 3, 0),
    OAM_ENTRY(15, -22, OAM_DIMS_16x16, OAM_X_FLIP, 392, 3, 0),
    OAM_ENTRY(0, -20, OAM_DIMS_16x16, OAM_X_FLIP, 394, 3, 0),
};

static const u16 sParticleOam_OutwardSmoke_Frame3[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-47, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(-17, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(-17, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(-32, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(-32, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(-48, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
    OAM_ENTRY(31, -16, OAM_DIMS_16x16, OAM_X_FLIP, 394, 3, 0),
    OAM_ENTRY(1, -20, OAM_DIMS_16x16, OAM_X_FLIP, 396, 3, 0),
    OAM_ENTRY(1, -16, OAM_DIMS_16x16, OAM_X_FLIP, 398, 3, 0),
    OAM_ENTRY(16, -16, OAM_DIMS_16x16, OAM_X_FLIP, 396, 3, 0),
    OAM_ENTRY(16, -22, OAM_DIMS_16x16, OAM_X_FLIP, 394, 3, 0),
    OAM_ENTRY(32, -24, OAM_DIMS_16x16, OAM_X_FLIP, 392, 3, 0),
};

static const u16 sParticleOam_OutwardSmoke_Frame4[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-50, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(-33, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(-18, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(-33, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(-48, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(40, -20, OAM_DIMS_16x16, OAM_X_FLIP, 392, 3, 0),
    OAM_ENTRY(34, -26, OAM_DIMS_16x16, OAM_X_FLIP, 394, 3, 0),
    OAM_ENTRY(17, -22, OAM_DIMS_16x16, OAM_X_FLIP, 396, 3, 0),
    OAM_ENTRY(2, -20, OAM_DIMS_16x16, OAM_X_FLIP, 398, 3, 0),
    OAM_ENTRY(17, -16, OAM_DIMS_16x16, OAM_X_FLIP, 398, 3, 0),
    OAM_ENTRY(32, -16, OAM_DIMS_16x16, OAM_X_FLIP, 396, 3, 0),
    OAM_ENTRY(-56, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
};

static const u16 sParticleOam_OutwardSmoke_Frame5[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-52, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(-34, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(-49, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(-56, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(36, -28, OAM_DIMS_16x16, OAM_X_FLIP, 396, 3, 0),
    OAM_ENTRY(18, -24, OAM_DIMS_16x16, OAM_X_FLIP, 398, 3, 0),
    OAM_ENTRY(33, -16, OAM_DIMS_16x16, OAM_X_FLIP, 398, 3, 0),
    OAM_ENTRY(40, -20, OAM_DIMS_16x16, OAM_X_FLIP, 394, 3, 0),
};

static const u16 sParticleOam_OutwardSmoke_Frame6[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-56, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(-54, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(40, -20, OAM_DIMS_16x16, OAM_X_FLIP, 396, 3, 0),
    OAM_ENTRY(38, -30, OAM_DIMS_16x16, OAM_X_FLIP, 398, 3, 0),
};

static const u16 sParticleOam_OutwardSmoke_Frame7[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-56, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(40, -20, OAM_DIMS_16x16, OAM_X_FLIP, 398, 3, 0),
};

static const u16 sParticleOam_ExplosionSmoke_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 3, 0),
};

static const u16 sParticleOam_ExplosionSmoke_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 402, 3, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
};

static const u16 sParticleOam_ExplosionSmoke_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 404, 3, 0),
    OAM_ENTRY(-8, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
};

static const u16 sParticleOam_ExplosionSmoke_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 406, 3, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
};

static const u16 sOam_3ec02e[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
};

const struct FrameData sSpriteDebrisOam_IceCloud[12] = {
    [0] = {
        .pFrame = sSpriteDebrisOam_IceCloud_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sSpriteDebrisOam_IceCloud_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sSpriteDebrisOam_IceCloud_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sSpriteDebrisOam_IceCloud_Frame3,
        .timer = 4
    },
    [4] = {
        .pFrame = sSpriteDebrisOam_IceCloud_Frame4,
        .timer = 4
    },
    [5] = {
        .pFrame = sSpriteDebrisOam_IceCloud_Frame5,
        .timer = 4
    },
    [6] = {
        .pFrame = sSpriteDebrisOam_IceCloud_Frame6,
        .timer = 4
    },
    [7] = {
        .pFrame = sSpriteDebrisOam_IceCloud_Frame7,
        .timer = 4
    },
    [8] = {
        .pFrame = sSpriteDebrisOam_IceCloud_Frame8,
        .timer = 4
    },
    [9] = {
        .pFrame = sSpriteDebrisOam_IceCloud_Frame9,
        .timer = 4
    },
    [10] = {
        .pFrame = sSpriteDebrisOam_IceCloud_Frame10,
        .timer = 255
    },
    [11] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSpriteDebrisOam_NoCloud[5] = {
    [0] = {
        .pFrame = sSpriteDebrisOam_NoCloud_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sSpriteDebrisOam_NoCloud_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sSpriteDebrisOam_NoCloud_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sSpriteDebrisOam_NoCloud_Frame3,
        .timer = 255
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_ScrewAttackKilled[9] = {
    [0] = {
        .pFrame = sParticleOam_ScrewAttackKilled_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sParticleOam_ScrewAttackKilled_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sParticleOam_ScrewAttackKilled_Frame2,
        .timer = 3
    },
    [3] = {
        .pFrame = sParticleOam_ScrewAttackKilled_Frame3,
        .timer = 3
    },
    [4] = {
        .pFrame = sParticleOam_ScrewAttackKilled_Frame4,
        .timer = 3
    },
    [5] = {
        .pFrame = sParticleOam_ScrewAttackKilled_Frame5,
        .timer = 4
    },
    [6] = {
        .pFrame = sParticleOam_ScrewAttackKilled_Frame6,
        .timer = 4
    },
    [7] = {
        .pFrame = sParticleOam_ScrewAttackKilled_Frame7,
        .timer = 4
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_ShinesparkKilled[8] = {
    [0] = {
        .pFrame = sParticleOam_ShinesparkKilled_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sParticleOam_ShinesparkKilled_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sParticleOam_ShinesparkKilled_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sParticleOam_ShinesparkKilled_Frame3,
        .timer = 3
    },
    [4] = {
        .pFrame = sParticleOam_ShinesparkKilled_Frame4,
        .timer = 3
    },
    [5] = {
        .pFrame = sParticleOam_ShinesparkKilled_Frame5,
        .timer = 3
    },
    [6] = {
        .pFrame = sParticleOam_ShinesparkKilled_Frame6,
        .timer = 4
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSpriteDebrisOam_NormalCloud[12] = {
    [0] = {
        .pFrame = sSpriteDebrisOam_NormalCloud_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sSpriteDebrisOam_NormalCloud_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sSpriteDebrisOam_NormalCloud_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sSpriteDebrisOam_NormalCloud_Frame3,
        .timer = 4
    },
    [4] = {
        .pFrame = sSpriteDebrisOam_NormalCloud_Frame4,
        .timer = 4
    },
    [5] = {
        .pFrame = sSpriteDebrisOam_NormalCloud_Frame5,
        .timer = 4
    },
    [6] = {
        .pFrame = sSpriteDebrisOam_NormalCloud_Frame6,
        .timer = 4
    },
    [7] = {
        .pFrame = sSpriteDebrisOam_NormalCloud_Frame7,
        .timer = 4
    },
    [8] = {
        .pFrame = sSpriteDebrisOam_NormalCloud_Frame8,
        .timer = 4
    },
    [9] = {
        .pFrame = sSpriteDebrisOam_NormalCloud_Frame9,
        .timer = 4
    },
    [10] = {
        .pFrame = sSpriteDebrisOam_NormalCloud_Frame10,
        .timer = 255
    },
    [11] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_HeavyDust[5] = {
    [0] = {
        .pFrame = sParticleOam_HeavyDust_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sParticleOam_HeavyDust_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sParticleOam_HeavyDust_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sParticleOam_HeavyDust_Frame3,
        .timer = 8
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_ExplosionSmoke[5] = {
    [0] = {
        .pFrame = sParticleOam_ExplosionSmoke_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sParticleOam_ExplosionSmoke_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sParticleOam_ExplosionSmoke_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sParticleOam_ExplosionSmoke_Frame3,
        .timer = 8
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_EnterOrExitWater[9] = {
    [0] = {
        .pFrame = sParticleOam_EnterOrExitWater_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sParticleOam_EnterOrExitWater_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sParticleOam_EnterOrExitWater_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sParticleOam_EnterOrExitWater_Frame3,
        .timer = 4
    },
    [4] = {
        .pFrame = sParticleOam_EnterOrExitWater_Frame4,
        .timer = 4
    },
    [5] = {
        .pFrame = sParticleOam_EnterOrExitWater_Frame5,
        .timer = 4
    },
    [6] = {
        .pFrame = sParticleOam_EnterOrExitWater_Frame6,
        .timer = 4
    },
    [7] = {
        .pFrame = sParticleOam_EnterOrExitWater_Frame7,
        .timer = 4
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sWaterDropOam_Spawning[6] = {
    [0] = {
        .pFrame = sWaterDropOam_Spawning_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sWaterDropOam_Spawning_Frame1,
        .timer = 10
    },
    [2] = {
        .pFrame = sWaterDropOam_Spawning_Frame2,
        .timer = 12
    },
    [3] = {
        .pFrame = sWaterDropOam_Spawning_Frame1,
        .timer = 4
    },
    [4] = {
        .pFrame = sWaterDropOam_Spawning_Frame0,
        .timer = 4
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sWaterDropOam_Falling[2] = {
    [0] = {
        .pFrame = sWaterDropOam_Falling_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sWaterDropOam_Splashing[6] = {
    [0] = {
        .pFrame = sWaterDropOam_Splashing_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sWaterDropOam_Splashing_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sWaterDropOam_Splashing_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sWaterDropOam_Splashing_Frame3,
        .timer = 6
    },
    [4] = {
        .pFrame = sWaterDropOam_Splashing_Frame4,
        .timer = 6
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sBubbles1Oam_Idle[9] = {
    [0] = {
        .pFrame = sBubbles1Oam_Idle_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sBubbles1Oam_Idle_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sBubbles1Oam_Idle_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sBubbles1Oam_Idle_Frame3,
        .timer = 8
    },
    [4] = {
        .pFrame = sBubbles1Oam_Idle_Frame4,
        .timer = 8
    },
    [5] = {
        .pFrame = sBubbles1Oam_Idle_Frame5,
        .timer = 8
    },
    [6] = {
        .pFrame = sBubbles1Oam_Idle_Frame6,
        .timer = 8
    },
    [7] = {
        .pFrame = sBubbles1Oam_Idle_Frame7,
        .timer = 8
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sBubbles2Oam_Idle[10] = {
    [0] = {
        .pFrame = sBubbles2Oam_Idle_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sBubbles2Oam_Idle_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sBubbles2Oam_Idle_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sBubbles2Oam_Idle_Frame3,
        .timer = 8
    },
    [4] = {
        .pFrame = sBubbles2Oam_Idle_Frame4,
        .timer = 8
    },
    [5] = {
        .pFrame = sBubbles2Oam_Idle_Frame5,
        .timer = 8
    },
    [6] = {
        .pFrame = sBubbles2Oam_Idle_Frame6,
        .timer = 8
    },
    [7] = {
        .pFrame = sBubbles2Oam_Idle_Frame7,
        .timer = 8
    },
    [8] = {
        .pFrame = sBubbles2Oam_Idle_Frame8,
        .timer = 8
    },
    [9] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_EnterOrExitWaterBig[9] = {
    [0] = {
        .pFrame = sParticleOam_EnterOrExitWaterBig_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sParticleOam_EnterOrExitWaterBig_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sParticleOam_EnterOrExitWaterBig_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sParticleOam_EnterOrExitWaterBig_Frame3,
        .timer = 4
    },
    [4] = {
        .pFrame = sParticleOam_EnterOrExitWaterBig_Frame4,
        .timer = 4
    },
    [5] = {
        .pFrame = sParticleOam_EnterOrExitWaterBig_Frame5,
        .timer = 4
    },
    [6] = {
        .pFrame = sParticleOam_EnterOrExitWaterBig_Frame6,
        .timer = 4
    },
    [7] = {
        .pFrame = sParticleOam_EnterOrExitWaterBig_Frame7,
        .timer = 4
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_SpriteEnterOrExitWater[11] = {
    [0] = {
        .pFrame = sParticleOam_SpriteEnterOrExitWater_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sParticleOam_SpriteEnterOrExitWater_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sParticleOam_SpriteEnterOrExitWater_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sParticleOam_SpriteEnterOrExitWater_Frame3,
        .timer = 4
    },
    [4] = {
        .pFrame = sParticleOam_SpriteEnterOrExitWater_Frame4,
        .timer = 5
    },
    [5] = {
        .pFrame = sParticleOam_SpriteEnterOrExitWater_Frame5,
        .timer = 5
    },
    [6] = {
        .pFrame = sParticleOam_SpriteEnterOrExitWater_Frame6,
        .timer = 5
    },
    [7] = {
        .pFrame = sParticleOam_SpriteEnterOrExitWater_Frame7,
        .timer = 5
    },
    [8] = {
        .pFrame = sParticleOam_SpriteEnterOrExitWater_Frame8,
        .timer = 5
    },
    [9] = {
        .pFrame = sParticleOam_SpriteEnterOrExitWater_Frame9,
        .timer = 5
    },
    [10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_OutwardIceExplosion[9] = {
    [0] = {
        .pFrame = sParticleOam_OutwardIceExplosion_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sParticleOam_OutwardIceExplosion_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sParticleOam_OutwardIceExplosion_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sParticleOam_OutwardIceExplosion_Frame3,
        .timer = 8
    },
    [4] = {
        .pFrame = sParticleOam_OutwardIceExplosion_Frame4,
        .timer = 9
    },
    [5] = {
        .pFrame = sParticleOam_OutwardIceExplosion_Frame5,
        .timer = 9
    },
    [6] = {
        .pFrame = sParticleOam_OutwardIceExplosion_Frame6,
        .timer = 10
    },
    [7] = {
        .pFrame = sParticleOam_OutwardIceExplosion_Frame7,
        .timer = 10
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_SpeedboosterKilled[9] = {
    [0] = {
        .pFrame = sParticleOam_SpeedboosterKilled_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sParticleOam_SpeedboosterKilled_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sParticleOam_SpeedboosterKilled_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sParticleOam_SpeedboosterKilled_Frame3,
        .timer = 4
    },
    [4] = {
        .pFrame = sParticleOam_SpeedboosterKilled_Frame4,
        .timer = 4
    },
    [5] = {
        .pFrame = sParticleOam_SpeedboosterKilled_Frame5,
        .timer = 4
    },
    [6] = {
        .pFrame = sParticleOam_SpeedboosterKilled_Frame6,
        .timer = 4
    },
    [7] = {
        .pFrame = sParticleOam_SpeedboosterKilled_Frame7,
        .timer = 4
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_PseudoScrewKilled[9] = {
    [0] = {
        .pFrame = sParticleOam_PseudoScrewKilled_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sParticleOam_PseudoScrewKilled_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sParticleOam_PseudoScrewKilled_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sParticleOam_PseudoScrewKilled_Frame3,
        .timer = 2
    },
    [4] = {
        .pFrame = sParticleOam_PseudoScrewKilled_Frame4,
        .timer = 3
    },
    [5] = {
        .pFrame = sParticleOam_PseudoScrewKilled_Frame5,
        .timer = 3
    },
    [6] = {
        .pFrame = sParticleOam_PseudoScrewKilled_Frame6,
        .timer = 4
    },
    [7] = {
        .pFrame = sParticleOam_PseudoScrewKilled_Frame7,
        .timer = 4
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_OutwardSmoke[9] = {
    [0] = {
        .pFrame = sParticleOam_OutwardSmoke_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sParticleOam_OutwardSmoke_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sParticleOam_OutwardSmoke_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sParticleOam_OutwardSmoke_Frame3,
        .timer = 6
    },
    [4] = {
        .pFrame = sParticleOam_OutwardSmoke_Frame4,
        .timer = 7
    },
    [5] = {
        .pFrame = sParticleOam_OutwardSmoke_Frame5,
        .timer = 7
    },
    [6] = {
        .pFrame = sParticleOam_OutwardSmoke_Frame6,
        .timer = 8
    },
    [7] = {
        .pFrame = sParticleOam_OutwardSmoke_Frame7,
        .timer = 8
    },
    [8] = FRAME_DATA_TERMINATOR
};

static const u16 sSamusEnvironmentalEffectOam_3ecba4_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 192, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecba4_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 193, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecba4_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 194, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecba4_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 195, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecba4_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 196, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecbd4_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 192, 3, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 192, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecbd4_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 193, 3, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 193, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecbd4_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 194, 3, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 194, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecbd4_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 195, 3, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 195, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecbd4_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 196, 3, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 196, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecc04_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 344, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecc04_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 345, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecc04_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 346, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecc04_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecc04_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ece84_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 344, 3, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 344, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ece84_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-10, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 345, 3, 0),
    OAM_ENTRY(2, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 345, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ece84_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-12, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 346, 3, 0),
    OAM_ENTRY(4, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 346, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ece84_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-14, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(6, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ece84_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecc74_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 344, 3, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 344, 3, 0),
    OAM_ENTRY(-4, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecc74_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-10, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 345, 3, 0),
    OAM_ENTRY(2, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 345, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecc74_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-12, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 346, 3, 0),
    OAM_ENTRY(4, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 346, 3, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 344, 3, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 344, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecc74_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-14, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(6, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(-10, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 345, 3, 0),
    OAM_ENTRY(2, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 345, 3, 0),
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 344, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecc74_Frame4[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-16, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
    OAM_ENTRY(-12, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 346, 3, 0),
    OAM_ENTRY(4, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 346, 3, 0),
    OAM_ENTRY(-4, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 345, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecc74_Frame5[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-14, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(6, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 346, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecc74_Frame6[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
    OAM_ENTRY(8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
    OAM_ENTRY(-4, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecc34_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(2, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 344, 3, 0),
    OAM_ENTRY(-2, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 345, 3, 0),
    OAM_ENTRY(-10, -6, OAM_DIMS_8x8, OAM_X_FLIP, 344, 3, 0),
    OAM_ENTRY(-6, -6, OAM_DIMS_8x8, OAM_X_FLIP, 345, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecc34_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(6, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 344, 3, 0),
    OAM_ENTRY(2, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 345, 3, 0),
    OAM_ENTRY(-2, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 346, 3, 0),
    OAM_ENTRY(-14, -6, OAM_DIMS_8x8, OAM_X_FLIP, 344, 3, 0),
    OAM_ENTRY(-10, -6, OAM_DIMS_8x8, OAM_X_FLIP, 345, 3, 0),
    OAM_ENTRY(-6, -6, OAM_DIMS_8x8, OAM_X_FLIP, 346, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecc34_Frame2[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(8, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 344, 3, 0),
    OAM_ENTRY(5, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 345, 3, 0),
    OAM_ENTRY(2, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 346, 3, 0),
    OAM_ENTRY(-2, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(-16, -7, OAM_DIMS_8x8, OAM_X_FLIP, 344, 3, 0),
    OAM_ENTRY(-13, -6, OAM_DIMS_8x8, OAM_X_FLIP, 345, 3, 0),
    OAM_ENTRY(-10, -6, OAM_DIMS_8x8, OAM_X_FLIP, 346, 3, 0),
    OAM_ENTRY(-6, -6, OAM_DIMS_8x8, OAM_X_FLIP, 347, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecc34_Frame3[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(2, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(6, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 346, 3, 0),
    OAM_ENTRY(9, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 345, 3, 0),
    OAM_ENTRY(-10, -7, OAM_DIMS_8x8, OAM_X_FLIP, 347, 3, 0),
    OAM_ENTRY(-14, -8, OAM_DIMS_8x8, OAM_X_FLIP, 346, 3, 0),
    OAM_ENTRY(-17, -9, OAM_DIMS_8x8, OAM_X_FLIP, 345, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecc34_Frame4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(8, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 346, 3, 0),
    OAM_ENTRY(6, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(2, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
    OAM_ENTRY(-16, -11, OAM_DIMS_8x8, OAM_X_FLIP, 346, 3, 0),
    OAM_ENTRY(-14, -9, OAM_DIMS_8x8, OAM_X_FLIP, 347, 3, 0),
    OAM_ENTRY(-10, -8, OAM_DIMS_8x8, OAM_X_FLIP, 348, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecc34_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(3, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
    OAM_ENTRY(7, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(-11, -9, OAM_DIMS_8x8, OAM_X_FLIP, 348, 3, 0),
    OAM_ENTRY(-15, -12, OAM_DIMS_8x8, OAM_X_FLIP, 347, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecc34_Frame6[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(7, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
    OAM_ENTRY(-15, -12, OAM_DIMS_8x8, OAM_X_FLIP, 348, 3, 0),
};

static const u16 sOam_3ec76e[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-6, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 376, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3eccb4_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-6, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 377, 3, 0),
    OAM_ENTRY(-2, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 376, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3eccb4_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-6, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 378, 3, 0),
    OAM_ENTRY(-2, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 377, 3, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 376, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3eccb4_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-6, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 379, 3, 0),
    OAM_ENTRY(-2, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 378, 3, 0),
    OAM_ENTRY(-4, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 377, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3eccb4_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-2, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 379, 3, 0),
    OAM_ENTRY(-4, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 378, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3eccb4_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 379, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3eccb4_Frame5[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 379, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecddc_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-7, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 376, 3, 0),
    OAM_ENTRY(-3, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 378, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecddc_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-7, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 377, 3, 0),
    OAM_ENTRY(-2, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 376, 3, 0),
    OAM_ENTRY(-4, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 376, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecddc_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 378, 3, 0),
    OAM_ENTRY(-2, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 377, 3, 0),
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 376, 3, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 377, 3, 0),
    OAM_ENTRY(-5, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 377, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecddc_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-9, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 379, 3, 0),
    OAM_ENTRY(-2, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 378, 3, 0),
    OAM_ENTRY(-4, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 377, 3, 0),
    OAM_ENTRY(-3, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 378, 3, 0),
    OAM_ENTRY(-5, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 378, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecddc_Frame4[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-1, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 379, 3, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 378, 3, 0),
    OAM_ENTRY(-2, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 379, 3, 0),
    OAM_ENTRY(-6, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 379, 3, 0),
    OAM_ENTRY(-3, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 377, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecddc_Frame5[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 379, 3, 0),
    OAM_ENTRY(-3, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 377, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecddc_Frame6[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-3, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 378, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecddc_Frame7[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-3, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 379, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecd5c_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecd5c_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecd5c_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(1, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecd5c_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(2, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(-17, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecd5c_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(3, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(-18, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecd5c_Frame5[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-19, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecd34_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecd34_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecd34_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecd34_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecd94_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-5, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 351, 3, 0),
    OAM_ENTRY(-3, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 351, 3, 0),
    OAM_ENTRY(-8, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecd94_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-6, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 351, 3, 0),
    OAM_ENTRY(-3, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 351, 3, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecd94_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -3, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(-6, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 351, 3, 0),
    OAM_ENTRY(-2, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 351, 3, 0),
    OAM_ENTRY(-6, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 383, 3, 0),
    OAM_ENTRY(-2, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 383, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecd94_Frame3[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-1, -16, OAM_DIMS_8x8, OAM_X_FLIP, 351, 3, 0),
    OAM_ENTRY(-7, -16, OAM_DIMS_8x8, OAM_X_FLIP, 351, 3, 0),
    OAM_ENTRY(-1, -8, OAM_DIMS_8x8, OAM_X_FLIP, 383, 3, 0),
    OAM_ENTRY(-7, -8, OAM_DIMS_8x8, OAM_X_FLIP, 383, 3, 0),
    OAM_ENTRY(-8, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(0, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(-8, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecd94_Frame4[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 383, 3, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 383, 3, 0),
    OAM_ENTRY(-8, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 351, 3, 0),
    OAM_ENTRY(0, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 351, 3, 0),
    OAM_ENTRY(0, -22, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(-8, -22, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(-8, -1, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecd94_Frame5[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(-9, -6, OAM_DIMS_8x8, OAM_X_FLIP, 383, 3, 0),
    OAM_ENTRY(1, -6, OAM_DIMS_8x8, OAM_X_FLIP, 383, 3, 0),
    OAM_ENTRY(-9, -11, OAM_DIMS_8x8, OAM_X_FLIP, 351, 3, 0),
    OAM_ENTRY(1, -11, OAM_DIMS_8x8, OAM_X_FLIP, 351, 3, 0),
    OAM_ENTRY(0, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(-8, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecd94_Frame6[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-9, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 351, 3, 0),
    OAM_ENTRY(1, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 351, 3, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
    OAM_ENTRY(-8, 1, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ecd94_Frame7[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, 2, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(-10, -4, OAM_DIMS_8x8, OAM_X_FLIP, 351, 3, 0),
    OAM_ENTRY(2, -4, OAM_DIMS_8x8, OAM_X_FLIP, 351, 3, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ece24_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 328, 6, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ece24_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-3, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 328, 6, 0),
    OAM_ENTRY(-5, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 328, 6, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ece24_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-3, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 328, 6, 0),
    OAM_ENTRY(-6, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 328, 6, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ece24_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-2, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 328, 6, 0),
    OAM_ENTRY(-7, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 328, 6, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ece24_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-1, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 328, 6, 0),
    OAM_ENTRY(-7, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 328, 6, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ece24_Frame5[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(0, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 328, 6, 0),
    OAM_ENTRY(-8, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 328, 6, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ece24_Frame6[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(1, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 328, 6, 0),
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 328, 6, 0),
    OAM_ENTRY(-9, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 328, 6, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ece24_Frame7[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(1, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 328, 6, 0),
    OAM_ENTRY(-4, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 328, 6, 0),
    OAM_ENTRY(-10, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 328, 6, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ece24_Frame8[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-5, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 328, 6, 0),
    OAM_ENTRY(2, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 328, 6, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ece24_Frame9[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 328, 6, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3ece24_Frame10[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 328, 6, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3eccec_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-6, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 376, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3eccec_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-7, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 377, 3, 0),
    OAM_ENTRY(-2, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 376, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3eccec_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-1, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 377, 3, 0),
    OAM_ENTRY(-8, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 378, 3, 0),
    OAM_ENTRY(-4, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 376, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3eccec_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-9, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 379, 3, 0),
    OAM_ENTRY(0, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 378, 3, 0),
    OAM_ENTRY(-5, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 377, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3eccec_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(1, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 379, 3, 0),
    OAM_ENTRY(-6, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 378, 3, 0),
    OAM_ENTRY(-1, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 377, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3eccec_Frame5[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-7, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 379, 3, 0),
    OAM_ENTRY(-1, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 378, 3, 0),
    OAM_ENTRY(2, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 379, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3eccec_Frame6[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-1, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 379, 3, 0),
    OAM_ENTRY(-8, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 379, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3eccec_Frame7[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-1, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 379, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3eceb4_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-1, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 192, 3, 0),
    OAM_ENTRY(-7, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 192, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3eceb4_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 193, 3, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 193, 3, 0),
    OAM_ENTRY(0, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(-8, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3eceb4_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 194, 3, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 194, 3, 0),
    OAM_ENTRY(0, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(-8, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3eceb4_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(0, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(-8, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 195, 3, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 195, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3eceb4_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(1, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(-9, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 196, 3, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 196, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3eceb4_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(2, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
    OAM_ENTRY(-10, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 196, 3, 0),
    OAM_ENTRY(0, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 196, 3, 0),
};

static const u16 sSamusEnvironmentalEffectOam_3eceb4_Frame6[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(2, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
    OAM_ENTRY(-10, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 196, 3, 0),
    OAM_ENTRY(0, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 196, 3, 0),
};

const struct FrameData sSamusEnvironmentalEffectOam_3ecba4[6] = {
    [0] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecba4_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecba4_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecba4_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecba4_Frame3,
        .timer = 6
    },
    [4] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecba4_Frame4,
        .timer = 6
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSamusEnvironmentalEffectOam_3ecbd4[6] = {
    [0] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecbd4_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecbd4_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecbd4_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecbd4_Frame3,
        .timer = 6
    },
    [4] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecbd4_Frame4,
        .timer = 6
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSamusEnvironmentalEffectOam_3ecc04[6] = {
    [0] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecc04_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecc04_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecc04_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecc04_Frame3,
        .timer = 6
    },
    [4] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecc04_Frame4,
        .timer = 6
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSamusEnvironmentalEffectOam_3ecc34[8] = {
    [0] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecc34_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecc34_Frame1,
        .timer = 5
    },
    [2] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecc34_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecc34_Frame3,
        .timer = 7
    },
    [4] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecc34_Frame4,
        .timer = 8
    },
    [5] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecc34_Frame5,
        .timer = 9
    },
    [6] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecc34_Frame6,
        .timer = 10
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSamusEnvironmentalEffectOam_3ecc74[8] = {
    [0] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecc74_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecc74_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecc74_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecc74_Frame3,
        .timer = 4
    },
    [4] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecc74_Frame4,
        .timer = 4
    },
    [5] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecc74_Frame5,
        .timer = 4
    },
    [6] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecc74_Frame6,
        .timer = 4
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSamusEnvironmentalEffectOam_3eccb4[7] = {
    [0] = {
        .pFrame = sSamusEnvironmentalEffectOam_3eccb4_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sSamusEnvironmentalEffectOam_3eccb4_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sSamusEnvironmentalEffectOam_3eccb4_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sSamusEnvironmentalEffectOam_3eccb4_Frame3,
        .timer = 6
    },
    [4] = {
        .pFrame = sSamusEnvironmentalEffectOam_3eccb4_Frame4,
        .timer = 6
    },
    [5] = {
        .pFrame = sSamusEnvironmentalEffectOam_3eccb4_Frame5,
        .timer = 6
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSamusEnvironmentalEffectOam_3eccec[9] = {
    [0] = {
        .pFrame = sSamusEnvironmentalEffectOam_3eccec_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sSamusEnvironmentalEffectOam_3eccec_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sSamusEnvironmentalEffectOam_3eccec_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sSamusEnvironmentalEffectOam_3eccec_Frame3,
        .timer = 6
    },
    [4] = {
        .pFrame = sSamusEnvironmentalEffectOam_3eccec_Frame4,
        .timer = 6
    },
    [5] = {
        .pFrame = sSamusEnvironmentalEffectOam_3eccec_Frame5,
        .timer = 6
    },
    [6] = {
        .pFrame = sSamusEnvironmentalEffectOam_3eccec_Frame6,
        .timer = 6
    },
    [7] = {
        .pFrame = sSamusEnvironmentalEffectOam_3eccec_Frame7,
        .timer = 6
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSamusEnvironmentalEffectOam_3ecd34[5] = {
    [0] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecd34_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecd34_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecd34_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecd34_Frame3,
        .timer = 6
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSamusEnvironmentalEffectOam_3ecd5c[7] = {
    [0] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecd5c_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecd5c_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecd5c_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecd5c_Frame3,
        .timer = 8
    },
    [4] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecd5c_Frame4,
        .timer = 8
    },
    [5] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecd5c_Frame5,
        .timer = 8
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSamusEnvironmentalEffectOam_3ecd94[9] = {
    [0] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecd94_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecd94_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecd94_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecd94_Frame3,
        .timer = 4
    },
    [4] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecd94_Frame4,
        .timer = 4
    },
    [5] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecd94_Frame5,
        .timer = 4
    },
    [6] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecd94_Frame6,
        .timer = 4
    },
    [7] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecd94_Frame7,
        .timer = 4
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSamusEnvironmentalEffectOam_3ecddc[9] = {
    [0] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecddc_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecddc_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecddc_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecddc_Frame3,
        .timer = 8
    },
    [4] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecddc_Frame4,
        .timer = 8
    },
    [5] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecddc_Frame5,
        .timer = 8
    },
    [6] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecddc_Frame6,
        .timer = 8
    },
    [7] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ecddc_Frame7,
        .timer = 8
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSamusEnvironmentalEffectOam_3ece24[12] = {
    [0] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ece24_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ece24_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ece24_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ece24_Frame3,
        .timer = 6
    },
    [4] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ece24_Frame4,
        .timer = 6
    },
    [5] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ece24_Frame5,
        .timer = 6
    },
    [6] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ece24_Frame6,
        .timer = 6
    },
    [7] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ece24_Frame7,
        .timer = 6
    },
    [8] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ece24_Frame8,
        .timer = 6
    },
    [9] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ece24_Frame9,
        .timer = 6
    },
    [10] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ece24_Frame10,
        .timer = 6
    },
    [11] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSamusEnvironmentalEffectOam_3ece84[6] = {
    [0] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ece84_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ece84_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ece84_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ece84_Frame3,
        .timer = 6
    },
    [4] = {
        .pFrame = sSamusEnvironmentalEffectOam_3ece84_Frame4,
        .timer = 6
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSamusEnvironmentalEffectOam_3eceb4[8] = {
    [0] = {
        .pFrame = sSamusEnvironmentalEffectOam_3eceb4_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sSamusEnvironmentalEffectOam_3eceb4_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sSamusEnvironmentalEffectOam_3eceb4_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sSamusEnvironmentalEffectOam_3eceb4_Frame3,
        .timer = 4
    },
    [4] = {
        .pFrame = sSamusEnvironmentalEffectOam_3eceb4_Frame4,
        .timer = 4
    },
    [5] = {
        .pFrame = sSamusEnvironmentalEffectOam_3eceb4_Frame5,
        .timer = 4
    },
    [6] = {
        .pFrame = sSamusEnvironmentalEffectOam_3eceb4_Frame6,
        .timer = 4
    },
    [7] = FRAME_DATA_TERMINATOR
};

static const u16 sParticleOam_GettingSuit_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 293, 3, 0),
};

static const u16 sParticleOam_GettingSuitBeams_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-52, -52, OAM_DIMS_8x8, OAM_NO_FLIP, 349, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
    OAM_ENTRY(52, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 447, 3, 0),
};

static const u16 sParticleOam_GettingSuitBeams_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-44, -44, OAM_DIMS_8x8, OAM_NO_FLIP, 350, 3, 0),
    OAM_ENTRY(48, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 349, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 447, 3, 0),
    OAM_ENTRY(-8, 52, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
};

static const u16 sParticleOam_GettingSuitBeams_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-36, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 413, 3, 0),
    OAM_ENTRY(40, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 382, 3, 0),
    OAM_ENTRY(-8, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 349, 3, 0),
    OAM_ENTRY(48, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
};

static const u16 sParticleOam_GettingSuitBeams_Frame3[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-20, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 413, 3, 0),
    OAM_ENTRY(44, -52, OAM_DIMS_8x8, OAM_NO_FLIP, 349, 3, 0),
    OAM_ENTRY(-8, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 381, 3, 0),
    OAM_ENTRY(48, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
    OAM_ENTRY(24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 444, 3, 0),
    OAM_ENTRY(32, -8, OAM_DIMS_8x8, OAM_X_FLIP, 444, 3, 0),
};

static const u16 sParticleOam_GettingSuitBeams_Frame4[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-12, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 350, 3, 0),
    OAM_ENTRY(36, -44, OAM_DIMS_8x8, OAM_X_FLIP, 350, 3, 0),
    OAM_ENTRY(44, 44, OAM_DIMS_8x8, OAM_NO_FLIP, 349, 3, 0),
    OAM_ENTRY(-60, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
    OAM_ENTRY(8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 444, 3, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_X_FLIP, 444, 3, 0),
    OAM_ENTRY(-8, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 412, 3, 0),
    OAM_ENTRY(-8, 32, OAM_DIMS_8x8, OAM_Y_FLIP, 412, 3, 0),
};

static const u16 sParticleOam_GettingSuitBeams_Frame5[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 382, 3, 0),
    OAM_ENTRY(20, -36, OAM_DIMS_16x16, OAM_X_FLIP, 413, 3, 0),
    OAM_ENTRY(36, 36, OAM_DIMS_8x8, OAM_NO_FLIP, 350, 3, 0),
    OAM_ENTRY(-56, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 349, 3, 0),
    OAM_ENTRY(-12, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 412, 3, 0),
    OAM_ENTRY(-8, 16, OAM_DIMS_8x8, OAM_Y_FLIP, 412, 3, 0),
};

static const u16 sParticleOam_GettingSuitBeams_Frame6[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(4, -20, OAM_DIMS_16x16, OAM_X_FLIP, 413, 3, 0),
    OAM_ENTRY(20, 20, OAM_DIMS_16x16, OAM_XY_FLIP, 413, 3, 0),
    OAM_ENTRY(-48, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 382, 3, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 381, 3, 0),
    OAM_ENTRY(8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 447, 3, 0),
};

static const u16 sParticleOam_GettingSuitBeams_Frame7[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(4, -12, OAM_DIMS_8x8, OAM_X_FLIP, 350, 3, 0),
    OAM_ENTRY(4, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 413, 3, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
    OAM_ENTRY(8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 447, 3, 0),
    OAM_ENTRY(-40, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 444, 3, 0),
    OAM_ENTRY(-32, 0, OAM_DIMS_8x8, OAM_X_FLIP, 444, 3, 0),
};

static const u16 sParticleOam_GettingSuitBeams_Frame8[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(4, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 350, 3, 0),
    OAM_ENTRY(4, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 447, 3, 0),
    OAM_ENTRY(-24, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 444, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_8x8, OAM_X_FLIP, 444, 3, 0),
};

static const u16 sParticleOam_GettingSuitBeams_Frame9[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-16, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 382, 3, 0),
    OAM_ENTRY(4, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
    OAM_ENTRY(-56, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
};

static const u16 sParticleOam_GettingSuit_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 472, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 472, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 472, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 472, 3, 0),
};

static const u16 sParticleOam_GettingSuit_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 474, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 474, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 474, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 474, 3, 0),
};

static const u16 sParticleOam_GettingSuit_Frame8[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 476, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 476, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 476, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 476, 3, 0),
};

static const u16 sParticleOam_GettingSuit_Frame12[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 478, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 478, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 478, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 478, 3, 0),
};

static const u16 sParticleOam_AbsorbingSuit_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-15, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 472, 3, 0),
    OAM_ENTRY(-1, -15, OAM_DIMS_16x16, OAM_X_FLIP, 472, 3, 0),
    OAM_ENTRY(-1, -1, OAM_DIMS_16x16, OAM_XY_FLIP, 472, 3, 0),
    OAM_ENTRY(-15, -1, OAM_DIMS_16x16, OAM_Y_FLIP, 472, 3, 0),
};

static const u16 sParticleOam_AbsorbingSuit_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-14, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 474, 3, 0),
    OAM_ENTRY(-2, -14, OAM_DIMS_16x16, OAM_X_FLIP, 474, 3, 0),
    OAM_ENTRY(-2, -2, OAM_DIMS_16x16, OAM_XY_FLIP, 474, 3, 0),
    OAM_ENTRY(-14, -2, OAM_DIMS_16x16, OAM_Y_FLIP, 474, 3, 0),
};

static const u16 sParticleOam_AbsorbingSuit_Frame8[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-14, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 476, 3, 0),
    OAM_ENTRY(-2, -13, OAM_DIMS_16x16, OAM_X_FLIP, 476, 3, 0),
    OAM_ENTRY(-2, -3, OAM_DIMS_16x16, OAM_XY_FLIP, 476, 3, 0),
    OAM_ENTRY(-14, -3, OAM_DIMS_16x16, OAM_Y_FLIP, 476, 3, 0),
};

static const u16 sParticleOam_AbsorbingSuit_Frame12[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-14, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 478, 3, 0),
    OAM_ENTRY(-2, -12, OAM_DIMS_16x16, OAM_X_FLIP, 478, 3, 0),
    OAM_ENTRY(-2, -4, OAM_DIMS_16x16, OAM_XY_FLIP, 478, 3, 0),
    OAM_ENTRY(-14, -4, OAM_DIMS_16x16, OAM_Y_FLIP, 478, 3, 0),
};

static const u16 sParticleOam_AbsorbingSuit_Frame16[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-29, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 444, 3, 0),
    OAM_ENTRY(-22, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 444, 3, 0),
    OAM_ENTRY(21, -4, OAM_DIMS_8x8, OAM_X_FLIP, 444, 3, 0),
    OAM_ENTRY(14, -4, OAM_DIMS_8x8, OAM_X_FLIP, 444, 3, 0),
    OAM_ENTRY(-15, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 444, 3, 0),
    OAM_ENTRY(7, -4, OAM_DIMS_8x8, OAM_X_FLIP, 444, 3, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_8x8, OAM_X_FLIP, 444, 3, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 444, 3, 0),
};

static const u16 sParticleOam_AbsorbingSuit_Frame18[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-16, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 471, 3, 0),
    OAM_ENTRY(-8, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 471, 3, 0),
    OAM_ENTRY(0, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 471, 3, 0),
    OAM_ENTRY(8, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 471, 3, 0),
    OAM_ENTRY(16, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 471, 3, 0),
    OAM_ENTRY(-24, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 471, 3, 0),
};

static const u16 sParticleOam_AbsorbingSuit_Frame22[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 471, 3, 0),
    OAM_ENTRY(0, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 471, 3, 0),
};

static const u16 sParticleOam_AbsorbingSuit_Frame26[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 471, 3, 0),
};

const struct FrameData sParticleOam_GettingSuitBeams[11] = {
    [0] = {
        .pFrame = sParticleOam_GettingSuitBeams_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sParticleOam_GettingSuitBeams_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sParticleOam_GettingSuitBeams_Frame2,
        .timer = 3
    },
    [3] = {
        .pFrame = sParticleOam_GettingSuitBeams_Frame3,
        .timer = 3
    },
    [4] = {
        .pFrame = sParticleOam_GettingSuitBeams_Frame4,
        .timer = 3
    },
    [5] = {
        .pFrame = sParticleOam_GettingSuitBeams_Frame5,
        .timer = 3
    },
    [6] = {
        .pFrame = sParticleOam_GettingSuitBeams_Frame6,
        .timer = 3
    },
    [7] = {
        .pFrame = sParticleOam_GettingSuitBeams_Frame7,
        .timer = 3
    },
    [8] = {
        .pFrame = sParticleOam_GettingSuitBeams_Frame8,
        .timer = 3
    },
    [9] = {
        .pFrame = sParticleOam_GettingSuitBeams_Frame9,
        .timer = 3
    },
    [10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_GettingSuit[17] = {
    [0] = {
        .pFrame = sParticleOam_GettingSuit_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sParticleOam_GettingSuit_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sParticleOam_GettingSuit_Frame0,
        .timer = 1
    },
    [3] = {
        .pFrame = sParticleOam_GettingSuit_Frame1,
        .timer = 1
    },
    [4] = {
        .pFrame = sParticleOam_GettingSuit_Frame4,
        .timer = 1
    },
    [5] = {
        .pFrame = sParticleOam_GettingSuit_Frame1,
        .timer = 1
    },
    [6] = {
        .pFrame = sParticleOam_GettingSuit_Frame4,
        .timer = 1
    },
    [7] = {
        .pFrame = sParticleOam_GettingSuit_Frame1,
        .timer = 1
    },
    [8] = {
        .pFrame = sParticleOam_GettingSuit_Frame8,
        .timer = 1
    },
    [9] = {
        .pFrame = sParticleOam_GettingSuit_Frame1,
        .timer = 1
    },
    [10] = {
        .pFrame = sParticleOam_GettingSuit_Frame8,
        .timer = 1
    },
    [11] = {
        .pFrame = sParticleOam_GettingSuit_Frame1,
        .timer = 1
    },
    [12] = {
        .pFrame = sParticleOam_GettingSuit_Frame12,
        .timer = 1
    },
    [13] = {
        .pFrame = sParticleOam_GettingSuit_Frame1,
        .timer = 1
    },
    [14] = {
        .pFrame = sParticleOam_GettingSuit_Frame12,
        .timer = 1
    },
    [15] = {
        .pFrame = sParticleOam_GettingSuit_Frame1,
        .timer = 1
    },
    [16] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_AbsorbingSuit[31] = {
    [0] = {
        .pFrame = sParticleOam_AbsorbingSuit_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sParticleOam_GettingSuit_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sParticleOam_AbsorbingSuit_Frame0,
        .timer = 1
    },
    [3] = {
        .pFrame = sParticleOam_GettingSuit_Frame1,
        .timer = 1
    },
    [4] = {
        .pFrame = sParticleOam_AbsorbingSuit_Frame4,
        .timer = 1
    },
    [5] = {
        .pFrame = sParticleOam_GettingSuit_Frame1,
        .timer = 1
    },
    [6] = {
        .pFrame = sParticleOam_AbsorbingSuit_Frame4,
        .timer = 1
    },
    [7] = {
        .pFrame = sParticleOam_GettingSuit_Frame1,
        .timer = 1
    },
    [8] = {
        .pFrame = sParticleOam_AbsorbingSuit_Frame8,
        .timer = 1
    },
    [9] = {
        .pFrame = sParticleOam_GettingSuit_Frame1,
        .timer = 1
    },
    [10] = {
        .pFrame = sParticleOam_AbsorbingSuit_Frame8,
        .timer = 1
    },
    [11] = {
        .pFrame = sParticleOam_GettingSuit_Frame1,
        .timer = 1
    },
    [12] = {
        .pFrame = sParticleOam_AbsorbingSuit_Frame12,
        .timer = 1
    },
    [13] = {
        .pFrame = sParticleOam_GettingSuit_Frame1,
        .timer = 1
    },
    [14] = {
        .pFrame = sParticleOam_AbsorbingSuit_Frame12,
        .timer = 1
    },
    [15] = {
        .pFrame = sParticleOam_GettingSuit_Frame1,
        .timer = 1
    },
    [16] = {
        .pFrame = sParticleOam_AbsorbingSuit_Frame16,
        .timer = 1
    },
    [17] = {
        .pFrame = sParticleOam_GettingSuit_Frame1,
        .timer = 1
    },
    [18] = {
        .pFrame = sParticleOam_AbsorbingSuit_Frame18,
        .timer = 1
    },
    [19] = {
        .pFrame = sParticleOam_GettingSuit_Frame1,
        .timer = 1
    },
    [20] = {
        .pFrame = sParticleOam_AbsorbingSuit_Frame18,
        .timer = 1
    },
    [21] = {
        .pFrame = sParticleOam_GettingSuit_Frame1,
        .timer = 1
    },
    [22] = {
        .pFrame = sParticleOam_AbsorbingSuit_Frame22,
        .timer = 1
    },
    [23] = {
        .pFrame = sParticleOam_GettingSuit_Frame1,
        .timer = 1
    },
    [24] = {
        .pFrame = sParticleOam_AbsorbingSuit_Frame22,
        .timer = 1
    },
    [25] = {
        .pFrame = sParticleOam_GettingSuit_Frame1,
        .timer = 1
    },
    [26] = {
        .pFrame = sParticleOam_AbsorbingSuit_Frame26,
        .timer = 1
    },
    [27] = {
        .pFrame = sParticleOam_GettingSuit_Frame1,
        .timer = 1
    },
    [28] = {
        .pFrame = sParticleOam_AbsorbingSuit_Frame26,
        .timer = 1
    },
    [29] = {
        .pFrame = sParticleOam_GettingSuit_Frame1,
        .timer = 1
    },
    [30] = FRAME_DATA_TERMINATOR
};

static const u16 sParticleOam_Smoke_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
};

static const u16 sParticleOam_Smoke_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
};

static const u16 sParticleOam_Smoke_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(1, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
};

static const u16 sParticleOam_Smoke_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(2, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(-17, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
};

static const u16 sParticleOam_Smoke_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(3, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(-18, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
};

static const u16 sParticleOam_Smoke_Frame5[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-19, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
};

static const u16 sParticleOam_Explosion9_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 3, 0),
};

static const u16 sParticleOam_Explosion9_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 402, 3, 0),
    OAM_ENTRY(-17, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 3, 0),
};

static const u16 sParticleOam_Explosion9_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 404, 3, 0),
    OAM_ENTRY(-18, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 402, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 3, 0),
};

static const u16 sParticleOam_Explosion9_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 406, 3, 0),
    OAM_ENTRY(-19, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 404, 3, 0),
    OAM_ENTRY(1, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 402, 3, 0),
};

static const u16 sParticleOam_Explosion9_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 406, 3, 0),
    OAM_ENTRY(2, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 404, 3, 0),
};

static const u16 sParticleOam_Explosion9_Frame5[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(3, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 406, 3, 0),
};

static const u16 sParticleOam_TailSmoke1_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(-8, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
};

static const u16 sParticleOam_TailSmoke1_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(-8, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
    OAM_ENTRY(-8, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
};

static const u16 sParticleOam_TailSmoke1_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(-8, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
};

static const u16 sParticleOam_TailSmoke1_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(-8, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(-8, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
};

static const u16 sParticleOam_TailSmoke1_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(-8, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
};

static const u16 sParticleOam_TailExplosion_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 3, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 406, 3, 0),
    OAM_ENTRY(-8, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 404, 3, 0),
};

static const u16 sParticleOam_TailExplosion_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 402, 3, 0),
    OAM_ENTRY(-8, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 3, 0),
    OAM_ENTRY(-8, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 406, 3, 0),
};

static const u16 sParticleOam_TailExplosion_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 404, 3, 0),
    OAM_ENTRY(-8, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 402, 3, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 3, 0),
};

static const u16 sParticleOam_TailExplosion_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 406, 3, 0),
    OAM_ENTRY(-8, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 404, 3, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 402, 3, 0),
    OAM_ENTRY(-8, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 3, 0),
};

static const u16 sParticleOam_TailExplosion_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 406, 3, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 404, 3, 0),
    OAM_ENTRY(-8, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 402, 3, 0),
};

static const u16 sParticleOam_3edd6c_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-18, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(3, -43, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 3, 0),
    OAM_ENTRY(-8, -41, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(3, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 406, 3, 0),
};

static const u16 sParticleOam_3edd6c_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-19, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(-4, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
    OAM_ENTRY(-8, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 402, 3, 0),
    OAM_ENTRY(-8, -42, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 3, 0),
};

static const u16 sParticleOam_3edd6c_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(0, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
    OAM_ENTRY(-4, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(-8, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 404, 3, 0),
    OAM_ENTRY(-8, -43, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(-17, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 402, 3, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 3, 0),
};

static const u16 sParticleOam_3edd6c_Frame3[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-16, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
    OAM_ENTRY(1, -41, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(-4, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(-8, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 406, 3, 0),
    OAM_ENTRY(-18, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 404, 3, 0),
    OAM_ENTRY(1, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 402, 3, 0),
};

static const u16 sParticleOam_3edd6c_Frame4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-17, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(-4, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(2, -42, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
    OAM_ENTRY(-19, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 406, 3, 0),
    OAM_ENTRY(2, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 404, 3, 0),
};

static const u16 sParticleOam_Explosion8_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(3, -43, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(-8, -41, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(-18, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(2, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 406, 3, 0),
};

static const u16 sParticleOam_Explosion8_Frame6[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -42, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(-19, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
};

static const u16 sParticleOam_Explosion8_Frame7[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -43, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
};

static const u16 sParticleOam_3edde4_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 344, 3, 0),
    OAM_ENTRY(-1, -23, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(-2, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 346, 3, 0),
};

static const u16 sParticleOam_3edde4_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 345, 3, 0),
    OAM_ENTRY(-4, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 344, 3, 0),
    OAM_ENTRY(0, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
};

static const u16 sParticleOam_3edde4_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 346, 3, 0),
    OAM_ENTRY(-4, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 345, 3, 0),
    OAM_ENTRY(-4, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 344, 3, 0),
};

static const u16 sParticleOam_3edde4_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(-4, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 346, 3, 0),
    OAM_ENTRY(-3, -21, OAM_DIMS_8x8, OAM_NO_FLIP, 345, 3, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 344, 3, 0),
};

static const u16 sParticleOam_3edde4_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(-2, -22, OAM_DIMS_8x8, OAM_NO_FLIP, 346, 3, 0),
    OAM_ENTRY(-3, -25, OAM_DIMS_8x8, OAM_NO_FLIP, 345, 3, 0),
};

static const u16 sParticleOam_3ede14_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 344, 3, 0),
    OAM_ENTRY(-1, 15, OAM_DIMS_8x8, OAM_Y_FLIP, 347, 3, 0),
    OAM_ENTRY(-2, 18, OAM_DIMS_8x8, OAM_Y_FLIP, 346, 3, 0),
};

static const u16 sParticleOam_3ede14_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 345, 3, 0),
    OAM_ENTRY(-4, 6, OAM_DIMS_8x8, OAM_Y_FLIP, 344, 3, 0),
    OAM_ENTRY(0, 20, OAM_DIMS_8x8, OAM_Y_FLIP, 347, 3, 0),
};

static const u16 sParticleOam_3ede14_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 346, 3, 0),
    OAM_ENTRY(-4, 6, OAM_DIMS_8x8, OAM_Y_FLIP, 345, 3, 0),
    OAM_ENTRY(-4, 12, OAM_DIMS_8x8, OAM_Y_FLIP, 344, 3, 0),
};

static const u16 sParticleOam_3ede14_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 347, 3, 0),
    OAM_ENTRY(-4, 6, OAM_DIMS_8x8, OAM_Y_FLIP, 346, 3, 0),
    OAM_ENTRY(-3, 13, OAM_DIMS_8x8, OAM_Y_FLIP, 345, 3, 0),
    OAM_ENTRY(-4, 16, OAM_DIMS_8x8, OAM_Y_FLIP, 344, 3, 0),
};

static const u16 sParticleOam_3ede14_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, 6, OAM_DIMS_8x8, OAM_Y_FLIP, 347, 3, 0),
    OAM_ENTRY(-2, 14, OAM_DIMS_8x8, OAM_Y_FLIP, 346, 3, 0),
    OAM_ENTRY(-3, 17, OAM_DIMS_8x8, OAM_Y_FLIP, 345, 3, 0),
};

static const u16 sParticleOam_3ede44_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 344, 3, 0),
    OAM_ENTRY(15, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(19, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 346, 3, 0),
};

static const u16 sParticleOam_3ede44_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 345, 3, 0),
    OAM_ENTRY(6, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 344, 3, 0),
    OAM_ENTRY(20, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
};

static const u16 sParticleOam_3ede44_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 346, 3, 0),
    OAM_ENTRY(6, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 345, 3, 0),
    OAM_ENTRY(12, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 344, 3, 0),
};

static const u16 sParticleOam_3ede44_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(0, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(6, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 346, 3, 0),
    OAM_ENTRY(13, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 345, 3, 0),
    OAM_ENTRY(16, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 344, 3, 0),
};

static const u16 sParticleOam_3ede44_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(6, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(14, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 346, 3, 0),
    OAM_ENTRY(17, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 345, 3, 0),
};

static const u16 sParticleOam_3ede74_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -4, OAM_DIMS_8x8, OAM_X_FLIP, 344, 3, 0),
    OAM_ENTRY(-23, -7, OAM_DIMS_8x8, OAM_X_FLIP, 347, 3, 0),
    OAM_ENTRY(-27, -9, OAM_DIMS_8x8, OAM_X_FLIP, 346, 3, 0),
};

static const u16 sParticleOam_3ede74_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -4, OAM_DIMS_8x8, OAM_X_FLIP, 345, 3, 0),
    OAM_ENTRY(-14, -4, OAM_DIMS_8x8, OAM_X_FLIP, 344, 3, 0),
    OAM_ENTRY(-28, -10, OAM_DIMS_8x8, OAM_X_FLIP, 347, 3, 0),
};

static const u16 sParticleOam_3ede74_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -4, OAM_DIMS_8x8, OAM_X_FLIP, 346, 3, 0),
    OAM_ENTRY(-14, -4, OAM_DIMS_8x8, OAM_X_FLIP, 345, 3, 0),
    OAM_ENTRY(-20, -4, OAM_DIMS_8x8, OAM_X_FLIP, 344, 3, 0),
};

static const u16 sParticleOam_3ede74_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -4, OAM_DIMS_8x8, OAM_X_FLIP, 347, 3, 0),
    OAM_ENTRY(-14, -4, OAM_DIMS_8x8, OAM_X_FLIP, 346, 3, 0),
    OAM_ENTRY(-21, -5, OAM_DIMS_8x8, OAM_X_FLIP, 345, 3, 0),
    OAM_ENTRY(-24, -6, OAM_DIMS_8x8, OAM_X_FLIP, 344, 3, 0),
};

static const u16 sParticleOam_3ede74_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-14, -4, OAM_DIMS_8x8, OAM_X_FLIP, 347, 3, 0),
    OAM_ENTRY(-22, -6, OAM_DIMS_8x8, OAM_X_FLIP, 346, 3, 0),
    OAM_ENTRY(-25, -7, OAM_DIMS_8x8, OAM_X_FLIP, 345, 3, 0),
};

static const u16 sParticleOam_TailSmoke2_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
    OAM_ENTRY(-4, -44, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(-1, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
};

static const u16 sParticleOam_TailSmoke2_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(-8, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
    OAM_ENTRY(-4, -52, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
};

static const u16 sParticleOam_TailSmoke2_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(-8, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(-7, -41, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
};

static const u16 sParticleOam_TailSmoke2_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(-8, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(-6, -42, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(-7, -49, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
};

static const u16 sParticleOam_TailSmoke2_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(-5, -43, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(-6, -50, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
};

static const u16 sParticleOam_TailSmoke2_Frame5[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -44, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(-5, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
};

static const u16 sParticleOam_TailSmoke2_Frame6[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -52, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
};

static const u16 sParticleOam_TailExplosionSmoke_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 3, 0),
    OAM_ENTRY(-4, -44, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(-5, -52, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
};

static const u16 sParticleOam_TailExplosionSmoke_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 402, 3, 0),
    OAM_ENTRY(-8, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 3, 0),
    OAM_ENTRY(-4, -56, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
};

static const u16 sParticleOam_TailExplosionSmoke_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 404, 3, 0),
    OAM_ENTRY(-8, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 402, 3, 0),
    OAM_ENTRY(-7, -41, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
};

static const u16 sParticleOam_TailExplosionSmoke_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 406, 3, 0),
    OAM_ENTRY(-8, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 404, 3, 0),
    OAM_ENTRY(-6, -42, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(-7, -53, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
};

static const u16 sParticleOam_TailExplosionSmoke_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 406, 3, 0),
    OAM_ENTRY(-5, -43, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(-6, -54, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
};

static const u16 sParticleOam_Explosion7_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 202, 3, 0),
};

static const u16 sParticleOam_Explosion7_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 229, 3, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 229, 3, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 229, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 229, 3, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 202, 3, 0),
};

static const u16 sParticleOam_Explosion7_Frame2[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-12, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 229, 3, 0),
    OAM_ENTRY(-12, -8, OAM_DIMS_8x8, OAM_Y_FLIP, 229, 3, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x8, OAM_X_FLIP, 229, 3, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_XY_FLIP, 229, 3, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 262, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 262, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 262, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 262, 3, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 202, 3, 0),
};

static const u16 sParticleOam_Explosion7_Frame3[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(0, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 229, 3, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_8x8, OAM_Y_FLIP, 229, 3, 0),
    OAM_ENTRY(8, -20, OAM_DIMS_8x8, OAM_X_FLIP, 229, 3, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_8x8, OAM_XY_FLIP, 229, 3, 0),
    OAM_ENTRY(-20, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 262, 3, 0),
    OAM_ENTRY(-20, -8, OAM_DIMS_16x16, OAM_Y_FLIP, 262, 3, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_16x16, OAM_X_FLIP, 262, 3, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_16x16, OAM_XY_FLIP, 262, 3, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 264, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 264, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 264, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 264, 3, 0),
};

static const u16 sParticleOam_Explosion7_Frame4[OAM_DATA_SIZE(13)] = {
    13,
    OAM_ENTRY(-4, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 3, 0),
    OAM_ENTRY(-8, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 262, 3, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_16x16, OAM_Y_FLIP, 262, 3, 0),
    OAM_ENTRY(8, -28, OAM_DIMS_16x16, OAM_X_FLIP, 262, 3, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_16x16, OAM_XY_FLIP, 262, 3, 0),
    OAM_ENTRY(-20, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 264, 3, 0),
    OAM_ENTRY(-20, -8, OAM_DIMS_16x16, OAM_Y_FLIP, 264, 3, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_16x16, OAM_X_FLIP, 264, 3, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_16x16, OAM_XY_FLIP, 264, 3, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 266, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 266, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 266, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 266, 3, 0),
};

static const u16 sParticleOam_Explosion7_Frame5[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-16, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
    OAM_ENTRY(-4, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 402, 3, 0),
    OAM_ENTRY(-8, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 264, 3, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_16x16, OAM_Y_FLIP, 264, 3, 0),
    OAM_ENTRY(8, -28, OAM_DIMS_16x16, OAM_X_FLIP, 264, 3, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_16x16, OAM_XY_FLIP, 264, 3, 0),
    OAM_ENTRY(-20, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 266, 3, 0),
    OAM_ENTRY(-20, -8, OAM_DIMS_16x16, OAM_Y_FLIP, 266, 3, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_16x16, OAM_X_FLIP, 266, 3, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_16x16, OAM_XY_FLIP, 266, 3, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 268, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 268, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 268, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 268, 3, 0),
};

static const u16 sParticleOam_Explosion7_Frame6[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-16, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 400, 3, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 404, 3, 0),
    OAM_ENTRY(-8, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 266, 3, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_16x16, OAM_Y_FLIP, 266, 3, 0),
    OAM_ENTRY(8, -28, OAM_DIMS_16x16, OAM_X_FLIP, 266, 3, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_16x16, OAM_XY_FLIP, 266, 3, 0),
    OAM_ENTRY(-20, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 268, 3, 0),
    OAM_ENTRY(-20, -8, OAM_DIMS_16x16, OAM_Y_FLIP, 268, 3, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_16x16, OAM_X_FLIP, 268, 3, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_16x16, OAM_XY_FLIP, 268, 3, 0),
};

static const u16 sParticleOam_Explosion7_Frame7[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-8, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
    OAM_ENTRY(-16, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(0, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(-8, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 402, 3, 0),
    OAM_ENTRY(-4, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 406, 3, 0),
    OAM_ENTRY(-8, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 268, 3, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_16x16, OAM_Y_FLIP, 268, 3, 0),
    OAM_ENTRY(8, -28, OAM_DIMS_16x16, OAM_X_FLIP, 268, 3, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_16x16, OAM_XY_FLIP, 268, 3, 0),
};

static const u16 sParticleOam_Explosion7_Frame8[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -42, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(-16, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(0, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(-8, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 404, 3, 0),
};

static const u16 sParticleOam_Explosion7_Frame9[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -44, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(0, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(-8, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 406, 3, 0),
};

static const u16 sParticleOam_Explosion7_Frame10[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -46, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
};

static const u16 sParticleOam_3edf74_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(0, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 344, 3, 0),
};

static const u16 sParticleOam_3edf74_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(0, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 345, 3, 0),
    OAM_ENTRY(6, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 344, 3, 0),
};

static const u16 sParticleOam_3edf74_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 346, 3, 0),
    OAM_ENTRY(6, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 345, 3, 0),
    OAM_ENTRY(12, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 344, 3, 0),
};

static const u16 sParticleOam_3edf74_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(2, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 346, 3, 0),
    OAM_ENTRY(10, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 345, 3, 0),
    OAM_ENTRY(17, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 344, 3, 0),
};

static const u16 sParticleOam_3edf74_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(15, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 345, 3, 0),
    OAM_ENTRY(24, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 344, 3, 0),
    OAM_ENTRY(5, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
};

static const u16 sParticleOam_3edf74_Frame5[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(28, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 344, 3, 0),
    OAM_ENTRY(7, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(18, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 346, 3, 0),
};

static const u16 sParticleOam_3edf74_Frame6[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(16, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(22, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 346, 3, 0),
    OAM_ENTRY(29, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 345, 3, 0),
    OAM_ENTRY(32, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 344, 3, 0),
};

static const u16 sParticleOam_3edf74_Frame7[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(22, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(30, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 346, 3, 0),
    OAM_ENTRY(33, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 345, 3, 0),
};

static const u16 sParticleOam_3edf74_Frame8[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(31, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
    OAM_ENTRY(35, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 346, 3, 0),
};

static const u16 sParticleOam_3edf74_Frame9[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(36, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
};

static const u16 sParticleOam_3edfcc_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -4, OAM_DIMS_8x8, OAM_X_FLIP, 344, 3, 0),
};

static const u16 sParticleOam_3edfcc_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -4, OAM_DIMS_8x8, OAM_X_FLIP, 345, 3, 0),
    OAM_ENTRY(-14, -4, OAM_DIMS_8x8, OAM_X_FLIP, 344, 3, 0),
};

static const u16 sParticleOam_3edfcc_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -4, OAM_DIMS_8x8, OAM_X_FLIP, 346, 3, 0),
    OAM_ENTRY(-14, -4, OAM_DIMS_8x8, OAM_X_FLIP, 345, 3, 0),
    OAM_ENTRY(-20, -4, OAM_DIMS_8x8, OAM_X_FLIP, 344, 3, 0),
};

static const u16 sParticleOam_3edfcc_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-10, -4, OAM_DIMS_8x8, OAM_X_FLIP, 346, 3, 0),
    OAM_ENTRY(-18, -4, OAM_DIMS_8x8, OAM_X_FLIP, 345, 3, 0),
    OAM_ENTRY(-25, -4, OAM_DIMS_8x8, OAM_X_FLIP, 344, 3, 0),
};

static const u16 sParticleOam_3edfcc_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-23, -4, OAM_DIMS_8x8, OAM_X_FLIP, 345, 3, 0),
    OAM_ENTRY(-32, -4, OAM_DIMS_8x8, OAM_X_FLIP, 344, 3, 0),
    OAM_ENTRY(-13, -4, OAM_DIMS_8x8, OAM_X_FLIP, 347, 3, 0),
};

static const u16 sParticleOam_3edfcc_Frame5[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-36, -4, OAM_DIMS_8x8, OAM_X_FLIP, 344, 3, 0),
    OAM_ENTRY(-15, -4, OAM_DIMS_8x8, OAM_X_FLIP, 347, 3, 0),
    OAM_ENTRY(-26, -4, OAM_DIMS_8x8, OAM_X_FLIP, 346, 3, 0),
};

static const u16 sParticleOam_3edfcc_Frame6[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-24, -4, OAM_DIMS_8x8, OAM_X_FLIP, 347, 3, 0),
    OAM_ENTRY(-30, -4, OAM_DIMS_8x8, OAM_X_FLIP, 346, 3, 0),
    OAM_ENTRY(-37, -5, OAM_DIMS_8x8, OAM_X_FLIP, 345, 3, 0),
    OAM_ENTRY(-40, -6, OAM_DIMS_8x8, OAM_X_FLIP, 344, 3, 0),
};

static const u16 sParticleOam_3edfcc_Frame7[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-30, -4, OAM_DIMS_8x8, OAM_X_FLIP, 347, 3, 0),
    OAM_ENTRY(-38, -6, OAM_DIMS_8x8, OAM_X_FLIP, 346, 3, 0),
    OAM_ENTRY(-41, -7, OAM_DIMS_8x8, OAM_X_FLIP, 345, 3, 0),
};

static const u16 sParticleOam_3edfcc_Frame8[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-39, -7, OAM_DIMS_8x8, OAM_X_FLIP, 347, 3, 0),
    OAM_ENTRY(-43, -9, OAM_DIMS_8x8, OAM_X_FLIP, 346, 3, 0),
};

static const u16 sParticleOam_3edfcc_Frame9[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-44, -10, OAM_DIMS_8x8, OAM_X_FLIP, 347, 3, 0),
};

static const u16 sParticleOam_3ee024_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
};

static const u16 sParticleOam_3ee024_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(13, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
};

static const u16 sParticleOam_3ee024_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(14, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(25, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
};

static const u16 sParticleOam_3ee024_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(14, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(26, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
    OAM_ENTRY(33, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 392, 3, 0),
};

static const u16 sParticleOam_3ee024_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(14, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(27, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
    OAM_ENTRY(34, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 394, 3, 0),
};

static const u16 sParticleOam_3ee024_Frame5[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(29, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
    OAM_ENTRY(36, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 396, 3, 0),
};

static const u16 sParticleOam_3ee024_Frame6[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(37, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
};

static const u16 sParticleOam_3ee024_Frame7[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(38, -13, OAM_DIMS_16x16, OAM_X_FLIP, 398, 3, 0),
};

static const u16 sParticleOam_3ee06c_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_16x16, OAM_X_FLIP, 392, 3, 0),
};

static const u16 sParticleOam_3ee06c_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -8, OAM_DIMS_16x16, OAM_X_FLIP, 394, 3, 0),
    OAM_ENTRY(-29, -8, OAM_DIMS_16x16, OAM_X_FLIP, 392, 3, 0),
};

static const u16 sParticleOam_3ee06c_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-16, -8, OAM_DIMS_16x16, OAM_X_FLIP, 396, 3, 0),
    OAM_ENTRY(-30, -8, OAM_DIMS_16x16, OAM_X_FLIP, 394, 3, 0),
    OAM_ENTRY(-41, -9, OAM_DIMS_16x16, OAM_X_FLIP, 392, 3, 0),
};

static const u16 sParticleOam_3ee06c_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -8, OAM_DIMS_16x16, OAM_X_FLIP, 398, 3, 0),
    OAM_ENTRY(-30, -8, OAM_DIMS_16x16, OAM_X_FLIP, 396, 3, 0),
    OAM_ENTRY(-42, -10, OAM_DIMS_16x16, OAM_X_FLIP, 394, 3, 0),
    OAM_ENTRY(-49, -9, OAM_DIMS_16x16, OAM_X_FLIP, 392, 3, 0),
};

static const u16 sParticleOam_3ee06c_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-30, -8, OAM_DIMS_16x16, OAM_X_FLIP, 398, 3, 0),
    OAM_ENTRY(-43, -11, OAM_DIMS_16x16, OAM_X_FLIP, 396, 3, 0),
    OAM_ENTRY(-50, -10, OAM_DIMS_16x16, OAM_X_FLIP, 394, 3, 0),
};

static const u16 sParticleOam_3ee06c_Frame5[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-45, -12, OAM_DIMS_16x16, OAM_X_FLIP, 398, 3, 0),
    OAM_ENTRY(-52, -11, OAM_DIMS_16x16, OAM_X_FLIP, 396, 3, 0),
};

static const u16 sParticleOam_3ee06c_Frame6[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-53, -12, OAM_DIMS_16x16, OAM_X_FLIP, 398, 3, 0),
};

static const u16 sParticleOam_3ee06c_Frame7[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-54, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 398, 3, 0),
};

const struct FrameData sParticleOam_Smoke[7] = {
    [0] = {
        .pFrame = sParticleOam_Smoke_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sParticleOam_Smoke_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sParticleOam_Smoke_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sParticleOam_Smoke_Frame3,
        .timer = 8
    },
    [4] = {
        .pFrame = sParticleOam_Smoke_Frame4,
        .timer = 8
    },
    [5] = {
        .pFrame = sParticleOam_Smoke_Frame5,
        .timer = 8
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_Explosion9[7] = {
    [0] = {
        .pFrame = sParticleOam_Explosion9_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sParticleOam_Explosion9_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sParticleOam_Explosion9_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sParticleOam_Explosion9_Frame3,
        .timer = 8
    },
    [4] = {
        .pFrame = sParticleOam_Explosion9_Frame4,
        .timer = 8
    },
    [5] = {
        .pFrame = sParticleOam_Explosion9_Frame5,
        .timer = 8
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_TailSmoke1[6] = {
    [0] = {
        .pFrame = sParticleOam_TailSmoke1_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sParticleOam_TailSmoke1_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sParticleOam_TailSmoke1_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sParticleOam_TailSmoke1_Frame3,
        .timer = 6
    },
    [4] = {
        .pFrame = sParticleOam_TailSmoke1_Frame4,
        .timer = 6
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_TailExplosion[6] = {
    [0] = {
        .pFrame = sParticleOam_TailExplosion_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sParticleOam_TailExplosion_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sParticleOam_TailExplosion_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sParticleOam_TailExplosion_Frame3,
        .timer = 6
    },
    [4] = {
        .pFrame = sParticleOam_TailExplosion_Frame4,
        .timer = 6
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_3edd6c[6] = {
    [0] = {
        .pFrame = sParticleOam_3edd6c_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sParticleOam_3edd6c_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sParticleOam_3edd6c_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sParticleOam_3edd6c_Frame3,
        .timer = 8
    },
    [4] = {
        .pFrame = sParticleOam_3edd6c_Frame4,
        .timer = 8
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_Explosion8[9] = {
    [0] = {
        .pFrame = sParticleOam_3edd6c_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sParticleOam_3edd6c_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sParticleOam_3edd6c_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sParticleOam_3edd6c_Frame3,
        .timer = 6
    },
    [4] = {
        .pFrame = sParticleOam_3edd6c_Frame4,
        .timer = 6
    },
    [5] = {
        .pFrame = sParticleOam_Explosion8_Frame5,
        .timer = 6
    },
    [6] = {
        .pFrame = sParticleOam_Explosion8_Frame6,
        .timer = 6
    },
    [7] = {
        .pFrame = sParticleOam_Explosion8_Frame7,
        .timer = 6
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_3edde4[6] = {
    [0] = {
        .pFrame = sParticleOam_3edde4_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sParticleOam_3edde4_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sParticleOam_3edde4_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sParticleOam_3edde4_Frame3,
        .timer = 6
    },
    [4] = {
        .pFrame = sParticleOam_3edde4_Frame4,
        .timer = 6
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_3ede14[6] = {
    [0] = {
        .pFrame = sParticleOam_3ede14_Frame0,
        .timer = 5
    },
    [1] = {
        .pFrame = sParticleOam_3ede14_Frame1,
        .timer = 5
    },
    [2] = {
        .pFrame = sParticleOam_3ede14_Frame2,
        .timer = 5
    },
    [3] = {
        .pFrame = sParticleOam_3ede14_Frame3,
        .timer = 5
    },
    [4] = {
        .pFrame = sParticleOam_3ede14_Frame4,
        .timer = 5
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_3ede44[6] = {
    [0] = {
        .pFrame = sParticleOam_3ede44_Frame0,
        .timer = 5
    },
    [1] = {
        .pFrame = sParticleOam_3ede44_Frame1,
        .timer = 5
    },
    [2] = {
        .pFrame = sParticleOam_3ede44_Frame2,
        .timer = 5
    },
    [3] = {
        .pFrame = sParticleOam_3ede44_Frame3,
        .timer = 5
    },
    [4] = {
        .pFrame = sParticleOam_3ede44_Frame4,
        .timer = 5
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_3ede74[6] = {
    [0] = {
        .pFrame = sParticleOam_3ede74_Frame0,
        .timer = 7
    },
    [1] = {
        .pFrame = sParticleOam_3ede74_Frame1,
        .timer = 7
    },
    [2] = {
        .pFrame = sParticleOam_3ede74_Frame2,
        .timer = 7
    },
    [3] = {
        .pFrame = sParticleOam_3ede74_Frame3,
        .timer = 7
    },
    [4] = {
        .pFrame = sParticleOam_3ede74_Frame4,
        .timer = 7
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_TailSmoke2[8] = {
    [0] = {
        .pFrame = sParticleOam_TailSmoke2_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sParticleOam_TailSmoke2_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sParticleOam_TailSmoke2_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sParticleOam_TailSmoke2_Frame3,
        .timer = 8
    },
    [4] = {
        .pFrame = sParticleOam_TailSmoke2_Frame4,
        .timer = 8
    },
    [5] = {
        .pFrame = sParticleOam_TailSmoke2_Frame5,
        .timer = 8
    },
    [6] = {
        .pFrame = sParticleOam_TailSmoke2_Frame6,
        .timer = 8
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_TailExplosionSmoke[6] = {
    [0] = {
        .pFrame = sParticleOam_TailExplosionSmoke_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sParticleOam_TailExplosionSmoke_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sParticleOam_TailExplosionSmoke_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sParticleOam_TailExplosionSmoke_Frame3,
        .timer = 6
    },
    [4] = {
        .pFrame = sParticleOam_TailExplosionSmoke_Frame4,
        .timer = 6
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_Explosion7[12] = {
    [0] = {
        .pFrame = sParticleOam_Explosion7_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sParticleOam_Explosion7_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sParticleOam_Explosion7_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sParticleOam_Explosion7_Frame3,
        .timer = 3
    },
    [4] = {
        .pFrame = sParticleOam_Explosion7_Frame4,
        .timer = 4
    },
    [5] = {
        .pFrame = sParticleOam_Explosion7_Frame5,
        .timer = 4
    },
    [6] = {
        .pFrame = sParticleOam_Explosion7_Frame6,
        .timer = 5
    },
    [7] = {
        .pFrame = sParticleOam_Explosion7_Frame7,
        .timer = 5
    },
    [8] = {
        .pFrame = sParticleOam_Explosion7_Frame8,
        .timer = 4
    },
    [9] = {
        .pFrame = sParticleOam_Explosion7_Frame9,
        .timer = 5
    },
    [10] = {
        .pFrame = sParticleOam_Explosion7_Frame10,
        .timer = 5
    },
    [11] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_3edf74[11] = {
    [0] = {
        .pFrame = sParticleOam_3edf74_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sParticleOam_3edf74_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sParticleOam_3edf74_Frame2,
        .timer = 1
    },
    [3] = {
        .pFrame = sParticleOam_3edf74_Frame3,
        .timer = 1
    },
    [4] = {
        .pFrame = sParticleOam_3edf74_Frame4,
        .timer = 1
    },
    [5] = {
        .pFrame = sParticleOam_3edf74_Frame5,
        .timer = 1
    },
    [6] = {
        .pFrame = sParticleOam_3edf74_Frame6,
        .timer = 2
    },
    [7] = {
        .pFrame = sParticleOam_3edf74_Frame7,
        .timer = 3
    },
    [8] = {
        .pFrame = sParticleOam_3edf74_Frame8,
        .timer = 4
    },
    [9] = {
        .pFrame = sParticleOam_3edf74_Frame9,
        .timer = 4
    },
    [10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_3edfcc[11] = {
    [0] = {
        .pFrame = sParticleOam_3edfcc_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sParticleOam_3edfcc_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sParticleOam_3edfcc_Frame2,
        .timer = 1
    },
    [3] = {
        .pFrame = sParticleOam_3edfcc_Frame3,
        .timer = 1
    },
    [4] = {
        .pFrame = sParticleOam_3edfcc_Frame4,
        .timer = 1
    },
    [5] = {
        .pFrame = sParticleOam_3edfcc_Frame5,
        .timer = 1
    },
    [6] = {
        .pFrame = sParticleOam_3edfcc_Frame6,
        .timer = 2
    },
    [7] = {
        .pFrame = sParticleOam_3edfcc_Frame7,
        .timer = 3
    },
    [8] = {
        .pFrame = sParticleOam_3edfcc_Frame8,
        .timer = 4
    },
    [9] = {
        .pFrame = sParticleOam_3edfcc_Frame9,
        .timer = 4
    },
    [10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_3ee024[9] = {
    [0] = {
        .pFrame = sParticleOam_3ee024_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sParticleOam_3ee024_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sParticleOam_3ee024_Frame2,
        .timer = 1
    },
    [3] = {
        .pFrame = sParticleOam_3ee024_Frame3,
        .timer = 2
    },
    [4] = {
        .pFrame = sParticleOam_3ee024_Frame4,
        .timer = 4
    },
    [5] = {
        .pFrame = sParticleOam_3ee024_Frame5,
        .timer = 4
    },
    [6] = {
        .pFrame = sParticleOam_3ee024_Frame6,
        .timer = 6
    },
    [7] = {
        .pFrame = sParticleOam_3ee024_Frame7,
        .timer = 6
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_3ee06c[9] = {
    [0] = {
        .pFrame = sParticleOam_3ee06c_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sParticleOam_3ee06c_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sParticleOam_3ee06c_Frame2,
        .timer = 1
    },
    [3] = {
        .pFrame = sParticleOam_3ee06c_Frame3,
        .timer = 2
    },
    [4] = {
        .pFrame = sParticleOam_3ee06c_Frame4,
        .timer = 4
    },
    [5] = {
        .pFrame = sParticleOam_3ee06c_Frame5,
        .timer = 4
    },
    [6] = {
        .pFrame = sParticleOam_3ee06c_Frame6,
        .timer = 6
    },
    [7] = {
        .pFrame = sParticleOam_3ee06c_Frame7,
        .timer = 6
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_Explosion10[12] = {
    [0] = {
        .pFrame = sParticleOam_Explosion7_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sParticleOam_Explosion7_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sParticleOam_Explosion7_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sParticleOam_Explosion7_Frame3,
        .timer = 4
    },
    [4] = {
        .pFrame = sParticleOam_Explosion7_Frame4,
        .timer = 4
    },
    [5] = {
        .pFrame = sParticleOam_Explosion7_Frame5,
        .timer = 4
    },
    [6] = {
        .pFrame = sParticleOam_Explosion7_Frame6,
        .timer = 6
    },
    [7] = {
        .pFrame = sParticleOam_Explosion7_Frame7,
        .timer = 7
    },
    [8] = {
        .pFrame = sParticleOam_Explosion7_Frame8,
        .timer = 8
    },
    [9] = {
        .pFrame = sParticleOam_Explosion7_Frame9,
        .timer = 9
    },
    [10] = {
        .pFrame = sParticleOam_Explosion7_Frame10,
        .timer = 10
    },
    [11] = FRAME_DATA_TERMINATOR
};

static const u16 sParticleOam_Dust1_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-14, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 344, 3, 0),
};

static const u16 sParticleOam_Dust1_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 345, 3, 0),
};

static const u16 sParticleOam_Dust1_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-19, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 346, 3, 0),
};

static const u16 sParticleOam_Dust1_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-20, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
};

static const u16 sParticleOam_Dust1_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-23, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
};

static const u16 sParticleOam_Dust2_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(6, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 344, 3, 0),
};

static const u16 sParticleOam_Dust2_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(8, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 345, 3, 0),
};

static const u16 sParticleOam_Dust2_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(11, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 346, 3, 0),
};

static const u16 sParticleOam_Dust2_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(12, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 347, 3, 0),
};

static const u16 sParticleOam_Dust2_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(15, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 348, 3, 0),
};

const struct FrameData sParticleOam_Dust1[6] = {
    [0] = {
        .pFrame = sParticleOam_Dust1_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sParticleOam_Dust1_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sParticleOam_Dust1_Frame2,
        .timer = 3
    },
    [3] = {
        .pFrame = sParticleOam_Dust1_Frame3,
        .timer = 3
    },
    [4] = {
        .pFrame = sParticleOam_Dust1_Frame4,
        .timer = 3
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_Dust2[6] = {
    [0] = {
        .pFrame = sParticleOam_Dust2_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sParticleOam_Dust2_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sParticleOam_Dust2_Frame2,
        .timer = 3
    },
    [3] = {
        .pFrame = sParticleOam_Dust2_Frame3,
        .timer = 3
    },
    [4] = {
        .pFrame = sParticleOam_Dust2_Frame4,
        .timer = 3
    },
    [5] = FRAME_DATA_TERMINATOR
};

static const u16 sOam_3ee1c4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 203, 2, 0),
};

static const u16 sOam_3ee1cc[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 323, 2, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 323, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 323, 2, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 323, 2, 0),
};

static const u16 sOam_3ee1e6[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 320, 2, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 320, 2, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 320, 2, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 320, 2, 0),
};

static const u16 sOam_3ee200[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 321, 2, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 321, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 321, 2, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 321, 2, 0),
};

static const u16 sOam_3ee21a[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 338, 2, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 338, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 338, 2, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 338, 2, 0),
};

static const u16 sOam_3ee234[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 340, 2, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 340, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 340, 2, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 340, 2, 0),
};

static const u16 sOam_3ee24e[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 342, 2, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 342, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 342, 2, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 342, 2, 0),
};

static const u16 sParticleOam_FlareHit_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(0, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 211, 3, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 243, 3, 0),
    OAM_ENTRY(32, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 247, 3, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_16x8, OAM_X_FLIP, 211, 3, 0),
    OAM_ENTRY(-32, -4, OAM_DIMS_16x8, OAM_X_FLIP, 243, 3, 0),
    OAM_ENTRY(-40, -4, OAM_DIMS_8x8, OAM_X_FLIP, 247, 3, 0),
};

static const u16 sParticleOam_FlareHit_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-4, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 211, 3, 0),
    OAM_ENTRY(12, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 243, 3, 0),
    OAM_ENTRY(20, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 247, 3, 0),
    OAM_ENTRY(-12, -4, OAM_DIMS_16x8, OAM_X_FLIP, 211, 3, 0),
    OAM_ENTRY(-20, -4, OAM_DIMS_8x8, OAM_X_FLIP, 243, 3, 0),
    OAM_ENTRY(-28, -4, OAM_DIMS_8x8, OAM_X_FLIP, 247, 3, 0),
};

static const u16 sParticleOam_FlareHit_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(0, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 211, 3, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 243, 3, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_8x8, OAM_X_FLIP, 211, 3, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_8x8, OAM_X_FLIP, 243, 3, 0),
};

static const u16 sParticleOam_FlareHit_Frame3[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 210, 3, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 213, 3, 0),
    OAM_ENTRY(-4, -40, OAM_DIMS_8x16, OAM_NO_FLIP, 214, 3, 0),
    OAM_ENTRY(-4, 8, OAM_DIMS_8x16, OAM_Y_FLIP, 210, 3, 0),
    OAM_ENTRY(-4, 24, OAM_DIMS_8x16, OAM_Y_FLIP, 213, 3, 0),
    OAM_ENTRY(-4, 40, OAM_DIMS_8x16, OAM_Y_FLIP, 214, 3, 0),
};

static const u16 sParticleOam_FlareHit_Frame4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x16, OAM_NO_FLIP, 210, 3, 0),
    OAM_ENTRY(-4, -12, OAM_DIMS_8x16, OAM_Y_FLIP, 210, 3, 0),
    OAM_ENTRY(-4, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 213, 3, 0),
    OAM_ENTRY(-4, 4, OAM_DIMS_8x16, OAM_Y_FLIP, 213, 3, 0),
    OAM_ENTRY(-4, -28, OAM_DIMS_8x16, OAM_NO_FLIP, 214, 3, 0),
    OAM_ENTRY(-4, 12, OAM_DIMS_8x16, OAM_Y_FLIP, 214, 3, 0),
};

static const u16 sParticleOam_FlareHit_Frame5[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 210, 3, 0),
    OAM_ENTRY(-4, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 213, 3, 0),
    OAM_ENTRY(-4, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 246, 3, 0),
    OAM_ENTRY(-4, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 210, 3, 0),
    OAM_ENTRY(-4, 6, OAM_DIMS_8x8, OAM_Y_FLIP, 213, 3, 0),
    OAM_ENTRY(-4, 12, OAM_DIMS_8x8, OAM_Y_FLIP, 246, 3, 0),
};

static const u16 sParticleOam_FlareHit_Frame6[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 208, 3, 0),
    OAM_ENTRY(-24, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 215, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 208, 3, 0),
    OAM_ENTRY(16, 16, OAM_DIMS_8x8, OAM_XY_FLIP, 215, 3, 0),
};

static const u16 sParticleOam_FlareHit_Frame7[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-14, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 208, 3, 0),
    OAM_ENTRY(-20, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 215, 3, 0),
    OAM_ENTRY(-2, -2, OAM_DIMS_16x16, OAM_XY_FLIP, 208, 3, 0),
    OAM_ENTRY(12, 12, OAM_DIMS_8x8, OAM_XY_FLIP, 215, 3, 0),
};

static const u16 sParticleOam_FlareHit_Frame8[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-7, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 241, 3, 0),
    OAM_ENTRY(-1, -1, OAM_DIMS_8x8, OAM_NO_FLIP, 241, 3, 0),
    OAM_ENTRY(-12, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 208, 3, 0),
    OAM_ENTRY(3, 3, OAM_DIMS_8x8, OAM_XY_FLIP, 208, 3, 0),
};

static const u16 sParticleOam_FlareHit_Frame9[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 208, 3, 0),
    OAM_ENTRY(16, -24, OAM_DIMS_8x8, OAM_X_FLIP, 215, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 208, 3, 0),
    OAM_ENTRY(-24, 16, OAM_DIMS_8x8, OAM_Y_FLIP, 215, 3, 0),
};

static const u16 sParticleOam_FlareHit_Frame10[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-2, -14, OAM_DIMS_16x16, OAM_X_FLIP, 208, 3, 0),
    OAM_ENTRY(12, -20, OAM_DIMS_8x8, OAM_X_FLIP, 215, 3, 0),
    OAM_ENTRY(-14, -2, OAM_DIMS_16x16, OAM_Y_FLIP, 208, 3, 0),
    OAM_ENTRY(-20, 12, OAM_DIMS_8x8, OAM_Y_FLIP, 215, 3, 0),
};

static const u16 sParticleOam_FlareHit_Frame11[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-2, -6, OAM_DIMS_8x8, OAM_X_FLIP, 241, 3, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_X_FLIP, 241, 3, 0),
    OAM_ENTRY(3, -11, OAM_DIMS_8x8, OAM_X_FLIP, 208, 3, 0),
    OAM_ENTRY(-12, 4, OAM_DIMS_8x8, OAM_X_FLIP, 208, 3, 0),
};

const struct FrameData sParticleOam_FlareHit[13] = {
    [0] = {
        .pFrame = sParticleOam_FlareHit_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sParticleOam_FlareHit_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sParticleOam_FlareHit_Frame2,
        .timer = 1
    },
    [3] = {
        .pFrame = sParticleOam_FlareHit_Frame3,
        .timer = 1
    },
    [4] = {
        .pFrame = sParticleOam_FlareHit_Frame4,
        .timer = 1
    },
    [5] = {
        .pFrame = sParticleOam_FlareHit_Frame5,
        .timer = 1
    },
    [6] = {
        .pFrame = sParticleOam_FlareHit_Frame6,
        .timer = 1
    },
    [7] = {
        .pFrame = sParticleOam_FlareHit_Frame7,
        .timer = 1
    },
    [8] = {
        .pFrame = sParticleOam_FlareHit_Frame8,
        .timer = 1
    },
    [9] = {
        .pFrame = sParticleOam_FlareHit_Frame9,
        .timer = 1
    },
    [10] = {
        .pFrame = sParticleOam_FlareHit_Frame10,
        .timer = 1
    },
    [11] = {
        .pFrame = sParticleOam_FlareHit_Frame11,
        .timer = 1
    },
    [12] = FRAME_DATA_TERMINATOR
};

static const u16 sParticleOam_NormalBeamHit_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 202, 2, 0),
};

static const u16 sParticleOam_NormalBeamHit_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 203, 2, 0),
};

static const u16 sParticleOam_NormalBeamHit_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 204, 2, 0),
};

static const u16 sParticleOam_NormalBeamHit_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 205, 2, 0),
};

const struct FrameData sParticleOam_NormalBeamHit[5] = {
    [0] = {
        .pFrame = sParticleOam_NormalBeamHit_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sParticleOam_NormalBeamHit_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sParticleOam_NormalBeamHit_Frame2,
        .timer = 1
    },
    [3] = {
        .pFrame = sParticleOam_NormalBeamHit_Frame3,
        .timer = 1
    },
    [4] = FRAME_DATA_TERMINATOR
};

static const u16 sParticleOam_ChargeBeamHit_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 202, 2, 0),
};

static const u16 sParticleOam_ChargeBeamHit_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 323, 2, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 323, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 323, 2, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 323, 2, 0),
};

static const u16 sParticleOam_ChargeBeamHit_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 324, 2, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 324, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 324, 2, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 324, 2, 0),
};

static const u16 sParticleOam_ChargeBeamHit_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 325, 2, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 325, 2, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 325, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 325, 2, 0),
};

static const u16 sParticleOam_ChargeBeamHit_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 326, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 326, 2, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 326, 2, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 326, 2, 0),
};

const struct FrameData sParticleOam_ChargeBeamHit[6] = {
    [0] = {
        .pFrame = sParticleOam_ChargeBeamHit_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sParticleOam_ChargeBeamHit_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sParticleOam_ChargeBeamHit_Frame2,
        .timer = 1
    },
    [3] = {
        .pFrame = sParticleOam_ChargeBeamHit_Frame3,
        .timer = 1
    },
    [4] = {
        .pFrame = sParticleOam_ChargeBeamHit_Frame4,
        .timer = 1
    },
    [5] = FRAME_DATA_TERMINATOR
};

static const u16 sParticleOam_WideBeamHit_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 203, 2, 0),
};

static const u16 sParticleOam_WideBeamHit_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 323, 2, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 323, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 323, 2, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 323, 2, 0),
};

static const u16 sParticleOam_WideBeamHit_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 320, 2, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 320, 2, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 320, 2, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 320, 2, 0),
};

static const u16 sParticleOam_WideBeamHit_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 321, 2, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 321, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 321, 2, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 321, 2, 0),
};

static const u16 sParticleOam_WideBeamHit_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 338, 2, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 338, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 338, 2, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 338, 2, 0),
};

static const u16 sParticleOam_WideBeamHit_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 340, 2, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 340, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 340, 2, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 340, 2, 0),
};

static const u16 sParticleOam_WideBeamHit_Frame6[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 342, 2, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 342, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 342, 2, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 342, 2, 0),
};

const struct FrameData sParticleOam_WideBeamHit[8] = {
    [0] = {
        .pFrame = sParticleOam_WideBeamHit_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sParticleOam_WideBeamHit_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sParticleOam_WideBeamHit_Frame2,
        .timer = 1
    },
    [3] = {
        .pFrame = sParticleOam_WideBeamHit_Frame3,
        .timer = 1
    },
    [4] = {
        .pFrame = sParticleOam_WideBeamHit_Frame4,
        .timer = 1
    },
    [5] = {
        .pFrame = sParticleOam_WideBeamHit_Frame5,
        .timer = 1
    },
    [6] = {
        .pFrame = sParticleOam_WideBeamHit_Frame6,
        .timer = 1
    },
    [7] = FRAME_DATA_TERMINATOR
};

static const u16 sOam_3ee610[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 202, 2, 0),
};

static const u16 sOam_3ee618[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 203, 2, 0),
};

static const u16 sOam_3ee620[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 320, 2, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 320, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 320, 2, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 320, 2, 0),
};

static const u16 sOam_3ee63a[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 321, 2, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 321, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 321, 2, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 321, 2, 0),
};

static const u16 sOam_3ee654[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 322, 2, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 322, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 322, 2, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 322, 2, 0),
};

static const u16 sParticleOam_PlasmaBeamHit_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 216, 2, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 216, 2, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 216, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 216, 2, 0),
};

static const u16 sOam_3ee688[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 237, 2, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 237, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 237, 2, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 237, 2, 0),
};

static const u16 sOam_3ee6a2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 236, 2, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 236, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 236, 2, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 236, 2, 0),
};

static const u16 sParticleOam_PlasmaBeamHit_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 235, 2, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 235, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 235, 2, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 235, 2, 0),
};

static const u16 sParticleOam_PlasmaBeamHit_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 238, 2, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 238, 2, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 238, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 238, 2, 0),
};

static const u16 sOam_3ee6f0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 324, 2, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 324, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 324, 2, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 324, 2, 0),
};

static const u16 sOam_3ee70a[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 325, 2, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 325, 2, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 325, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 325, 2, 0),
};

static const u16 sParticleOam_PlasmaBeamHit_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 326, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 326, 2, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 326, 2, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 326, 2, 0),
};

const struct FrameData sParticleOam_PlasmaBeamHit[7] = {
    [0] = {
        .pFrame = sParticleOam_PlasmaBeamHit_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sParticleOam_PlasmaBeamHit_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sParticleOam_PlasmaBeamHit_Frame2,
        .timer = 1
    },
    [3] = {
        .pFrame = sParticleOam_PlasmaBeamHit_Frame0,
        .timer = 1
    },
    [4] = {
        .pFrame = sParticleOam_PlasmaBeamHit_Frame1,
        .timer = 1
    },
    [5] = {
        .pFrame = sParticleOam_PlasmaBeamHit_Frame5,
        .timer = 1
    },
    [6] = FRAME_DATA_TERMINATOR
};

static const u16 sParticleOam_InvincibleHit_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 280, 3, 0),
};

static const u16 sParticleOam_InvincibleHit_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 281, 3, 0),
};

static const u16 sParticleOam_InvincibleHit_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 282, 3, 0),
};

static const u16 sParticleOam_InvincibleHit_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 92, 3, 0),
};

static const u16 sParticleOam_InvincibleHit_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 94, 3, 0),
};

const struct FrameData sParticleOam_InvincibleHit[6] = {
    [0] = {
        .pFrame = sParticleOam_InvincibleHit_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sParticleOam_InvincibleHit_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sParticleOam_InvincibleHit_Frame2,
        .timer = 1
    },
    [3] = {
        .pFrame = sParticleOam_InvincibleHit_Frame3,
        .timer = 2
    },
    [4] = {
        .pFrame = sParticleOam_InvincibleHit_Frame4,
        .timer = 2
    },
    [5] = FRAME_DATA_TERMINATOR
};

static const u16 sOam_3ee7d0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 232, 2, 0),
};

static const u16 sParticleOam_ChargingBeamBegin_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 233, 2, 0),
};

static const u16 sParticleOam_ChargingBeamBegin_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 234, 2, 0),
};

static const u16 sParticleOam_ChargingBeamBegin_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 359, 2, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 359, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 359, 2, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 359, 2, 0),
};

static const u16 sParticleOam_ChargingBeamBegin_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 235, 2, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 235, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 235, 2, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 235, 2, 0),
};

static const u16 sParticleOam_ChargingBeamBegin_Frame8[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 238, 2, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 238, 2, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 238, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 238, 2, 0),
};

static const u16 sParticleOam_ChargingBeamCharged_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 237, 2, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 237, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 237, 2, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 237, 2, 0),
};

static const u16 sParticleOam_ChargingBeamCharged_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 236, 2, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 236, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 236, 2, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 236, 2, 0),
};

static const u16 sParticleOam_ChargingBeamBegin_Frame11[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 235, 2, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 206, 2, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 239, 2, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 235, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 235, 2, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 235, 2, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x8, OAM_X_FLIP, 206, 2, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_8x8, OAM_X_FLIP, 239, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x8, OAM_XY_FLIP, 206, 2, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x8, OAM_XY_FLIP, 239, 2, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x8, OAM_Y_FLIP, 206, 2, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x8, OAM_Y_FLIP, 239, 2, 0),
};

static const u16 sParticleOam_ChargingBeamSparksCharged_Frame4[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(8, -16, OAM_DIMS_8x8, OAM_Y_FLIP, 355, 2, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 355, 2, 0),
    OAM_ENTRY(-16, 8, OAM_DIMS_8x8, OAM_X_FLIP, 355, 2, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_8x8, OAM_XY_FLIP, 355, 2, 0),
    OAM_ENTRY(-7, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 356, 2, 0),
    OAM_ENTRY(-1, -7, OAM_DIMS_8x8, OAM_X_FLIP, 356, 2, 0),
    OAM_ENTRY(-1, -1, OAM_DIMS_8x8, OAM_XY_FLIP, 356, 2, 0),
    OAM_ENTRY(-7, -1, OAM_DIMS_8x8, OAM_Y_FLIP, 356, 2, 0),
};

static const u16 sParticleOam_ChargingBeamSparksCharged_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-14, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 356, 2, 0),
    OAM_ENTRY(6, -14, OAM_DIMS_8x8, OAM_X_FLIP, 356, 2, 0),
    OAM_ENTRY(6, 6, OAM_DIMS_8x8, OAM_XY_FLIP, 356, 2, 0),
    OAM_ENTRY(-14, 6, OAM_DIMS_8x8, OAM_Y_FLIP, 356, 2, 0),
};

static const u16 sParticleOam_ChargingBeamSparksCharged_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-13, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 357, 2, 0),
    OAM_ENTRY(5, -13, OAM_DIMS_8x8, OAM_X_FLIP, 357, 2, 0),
    OAM_ENTRY(5, 5, OAM_DIMS_8x8, OAM_XY_FLIP, 357, 2, 0),
    OAM_ENTRY(-13, 5, OAM_DIMS_8x8, OAM_Y_FLIP, 357, 2, 0),
};

static const u16 sParticleOam_ChargingBeamSparksCharged_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-13, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 358, 2, 0),
    OAM_ENTRY(5, -13, OAM_DIMS_8x8, OAM_X_FLIP, 358, 2, 0),
    OAM_ENTRY(5, 5, OAM_DIMS_8x8, OAM_XY_FLIP, 358, 2, 0),
    OAM_ENTRY(-13, 5, OAM_DIMS_8x8, OAM_Y_FLIP, 358, 2, 0),
};

static const u16 sParticleOam_ChargingBeamSparksCharged_Frame3[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-10, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 360, 2, 0),
    OAM_ENTRY(2, -10, OAM_DIMS_8x8, OAM_X_FLIP, 360, 2, 0),
    OAM_ENTRY(2, 2, OAM_DIMS_8x8, OAM_XY_FLIP, 360, 2, 0),
    OAM_ENTRY(-10, 2, OAM_DIMS_8x8, OAM_Y_FLIP, 360, 2, 0),
    OAM_ENTRY(-18, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 355, 2, 0),
    OAM_ENTRY(10, -18, OAM_DIMS_8x8, OAM_X_FLIP, 355, 2, 0),
    OAM_ENTRY(10, 10, OAM_DIMS_8x8, OAM_XY_FLIP, 355, 2, 0),
    OAM_ENTRY(-18, 10, OAM_DIMS_8x8, OAM_Y_FLIP, 355, 2, 0),
};

static const u16 sOam_3ee966[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-12, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 329, 2, 0),
    OAM_ENTRY(9, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 329, 2, 0),
    OAM_ENTRY(-4, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 329, 2, 0),
};

static const u16 sParticleOam_ChargingBeamSparksBegin_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-11, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 328, 2, 0),
    OAM_ENTRY(6, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 328, 2, 0),
    OAM_ENTRY(-4, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 328, 2, 0),
};

static const u16 sParticleOam_ChargingBeamSparksBegin_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-9, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 328, 2, 0),
    OAM_ENTRY(4, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 328, 2, 0),
    OAM_ENTRY(-4, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 328, 2, 0),
};

static const u16 sParticleOam_ChargingBeamSparksBegin_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-15, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 329, 2, 0),
    OAM_ENTRY(12, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 329, 2, 0),
    OAM_ENTRY(-3, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 329, 2, 0),
    OAM_ENTRY(-7, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 328, 2, 0),
    OAM_ENTRY(2, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 328, 2, 0),
    OAM_ENTRY(-4, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 328, 2, 0),
};

static const u16 sParticleOam_ChargingBeamSparksBegin_Frame3[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-13, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 328, 2, 0),
    OAM_ENTRY(9, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 328, 2, 0),
    OAM_ENTRY(-4, 9, OAM_DIMS_8x8, OAM_NO_FLIP, 328, 2, 0),
    OAM_ENTRY(-6, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 328, 2, 0),
    OAM_ENTRY(1, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 328, 2, 0),
    OAM_ENTRY(-4, -1, OAM_DIMS_8x8, OAM_NO_FLIP, 328, 2, 0),
};

static const u16 sOam_3ee9ee[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 202, 2, 0),
};

static const u16 sOam_3ee9f6[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 323, 2, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 323, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 323, 2, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 323, 2, 0),
};

static const u16 sOam_3eea10[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 324, 2, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 324, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 324, 2, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 324, 2, 0),
};

static const u16 sOam_3eea2a[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 325, 2, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 325, 2, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 325, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 325, 2, 0),
};

static const u16 sOam_3eea44[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 326, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 326, 2, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 326, 2, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 326, 2, 0),
};

static const u16 sParticleOam_ChargingMissileBegin_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 232, 4, 0),
};

static const u16 sParticleOam_ChargingMissileBegin_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 233, 4, 0),
};

static const u16 sParticleOam_ChargingMissileBegin_Frame8[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 234, 4, 0),
};

static const u16 sParticleOam_ChargingMissileBegin_Frame15[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 235, 4, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 235, 4, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 235, 4, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 235, 4, 0),
};

static const u16 sParticleOam_ChargingMissileBegin_Frame22[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 238, 4, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 238, 4, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 238, 4, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 238, 4, 0),
};

static const u16 sParticleOam_ChargingMissileCharged_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 236, 4, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 236, 4, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 236, 4, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 236, 4, 0),
};

static const u16 sParticleOam_ChargingMissileCharged_Frame1[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 235, 4, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 235, 4, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 235, 4, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 235, 4, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 340, 4, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 340, 4, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 340, 4, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 340, 4, 0),
};

static const u16 sParticleOam_ChargingMissileCharged_Frame2[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 342, 4, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 342, 4, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 342, 4, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 342, 4, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 338, 4, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 338, 4, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 338, 4, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 338, 4, 0),
};

const struct FrameData sParticleOam_ChargingBeamBegin[19] = {
    [0] = {
        .pFrame = sParticleOam_ChargingBeamBegin_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sParticleOam_ChargingBeamBegin_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sParticleOam_ChargingBeamBegin_Frame0,
        .timer = 4
    },
    [3] = {
        .pFrame = sParticleOam_ChargingBeamBegin_Frame1,
        .timer = 4
    },
    [4] = {
        .pFrame = sParticleOam_ChargingBeamBegin_Frame4,
        .timer = 4
    },
    [5] = {
        .pFrame = sParticleOam_ChargingBeamBegin_Frame5,
        .timer = 4
    },
    [6] = {
        .pFrame = sParticleOam_ChargingBeamBegin_Frame4,
        .timer = 4
    },
    [7] = {
        .pFrame = sParticleOam_ChargingBeamBegin_Frame1,
        .timer = 4
    },
    [8] = {
        .pFrame = sParticleOam_ChargingBeamBegin_Frame8,
        .timer = 4
    },
    [9] = {
        .pFrame = sParticleOam_ChargingBeamBegin_Frame4,
        .timer = 4
    },
    [10] = {
        .pFrame = sParticleOam_ChargingBeamBegin_Frame8,
        .timer = 4
    },
    [11] = {
        .pFrame = sParticleOam_ChargingBeamBegin_Frame11,
        .timer = 4
    },
    [12] = {
        .pFrame = sParticleOam_ChargingBeamBegin_Frame8,
        .timer = 4
    },
    [13] = {
        .pFrame = sParticleOam_ChargingBeamBegin_Frame11,
        .timer = 4
    },
    [14] = {
        .pFrame = sParticleOam_ChargingBeamBegin_Frame8,
        .timer = 4
    },
    [15] = {
        .pFrame = sParticleOam_ChargingBeamBegin_Frame11,
        .timer = 4
    },
    [16] = {
        .pFrame = sParticleOam_ChargingBeamBegin_Frame8,
        .timer = 4
    },
    [17] = {
        .pFrame = sParticleOam_ChargingBeamBegin_Frame11,
        .timer = 4
    },
    [18] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_ChargingBeamCharged[5] = {
    [0] = {
        .pFrame = sParticleOam_ChargingBeamCharged_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sParticleOam_ChargingBeamCharged_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sParticleOam_ChargingBeamBegin_Frame11,
        .timer = 4
    },
    [3] = {
        .pFrame = sParticleOam_ChargingBeamBegin_Frame8,
        .timer = 4
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_ChargingBeamSparksCharged[6] = {
    [0] = {
        .pFrame = sParticleOam_ChargingBeamSparksCharged_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sParticleOam_ChargingBeamSparksCharged_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sParticleOam_ChargingBeamSparksCharged_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sParticleOam_ChargingBeamSparksCharged_Frame3,
        .timer = 2
    },
    [4] = {
        .pFrame = sParticleOam_ChargingBeamSparksCharged_Frame4,
        .timer = 2
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_ChargingBeamSparksBegin[5] = {
    [0] = {
        .pFrame = sParticleOam_ChargingBeamSparksBegin_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sParticleOam_ChargingBeamSparksBegin_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sParticleOam_ChargingBeamSparksBegin_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sParticleOam_ChargingBeamSparksBegin_Frame3,
        .timer = 4
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_ChargingMissileBegin[35] = {
    [0] = {
        .pFrame = sParticleOam_ChargingMissileBegin_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sParticleOam_ChargingMissileBegin_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sParticleOam_ChargingMissileBegin_Frame0,
        .timer = 4
    },
    [3] = {
        .pFrame = sParticleOam_ChargingMissileBegin_Frame1,
        .timer = 4
    },
    [4] = {
        .pFrame = sParticleOam_ChargingMissileBegin_Frame0,
        .timer = 4
    },
    [5] = {
        .pFrame = sParticleOam_ChargingMissileBegin_Frame1,
        .timer = 4
    },
    [6] = {
        .pFrame = sParticleOam_ChargingMissileBegin_Frame0,
        .timer = 4
    },
    [7] = {
        .pFrame = sParticleOam_ChargingMissileBegin_Frame1,
        .timer = 4
    },
    [8] = {
        .pFrame = sParticleOam_ChargingMissileBegin_Frame8,
        .timer = 4
    },
    [9] = {
        .pFrame = sParticleOam_ChargingMissileBegin_Frame1,
        .timer = 4
    },
    [10] = {
        .pFrame = sParticleOam_ChargingMissileBegin_Frame8,
        .timer = 4
    },
    [11] = {
        .pFrame = sParticleOam_ChargingMissileBegin_Frame1,
        .timer = 4
    },
    [12] = {
        .pFrame = sParticleOam_ChargingMissileBegin_Frame8,
        .timer = 4
    },
    [13] = {
        .pFrame = sParticleOam_ChargingMissileBegin_Frame1,
        .timer = 4
    },
    [14] = {
        .pFrame = sParticleOam_ChargingMissileBegin_Frame8,
        .timer = 4
    },
    [15] = {
        .pFrame = sParticleOam_ChargingMissileBegin_Frame15,
        .timer = 4
    },
    [16] = {
        .pFrame = sParticleOam_ChargingMissileBegin_Frame8,
        .timer = 4
    },
    [17] = {
        .pFrame = sParticleOam_ChargingMissileBegin_Frame15,
        .timer = 4
    },
    [18] = {
        .pFrame = sParticleOam_ChargingMissileBegin_Frame8,
        .timer = 4
    },
    [19] = {
        .pFrame = sParticleOam_ChargingMissileBegin_Frame15,
        .timer = 4
    },
    [20] = {
        .pFrame = sParticleOam_ChargingMissileBegin_Frame8,
        .timer = 4
    },
    [21] = {
        .pFrame = sParticleOam_ChargingMissileBegin_Frame15,
        .timer = 4
    },
    [22] = {
        .pFrame = sParticleOam_ChargingMissileBegin_Frame22,
        .timer = 4
    },
    [23] = {
        .pFrame = sParticleOam_ChargingMissileBegin_Frame15,
        .timer = 4
    },
    [24] = {
        .pFrame = sParticleOam_ChargingMissileBegin_Frame22,
        .timer = 4
    },
    [25] = {
        .pFrame = sParticleOam_ChargingMissileBegin_Frame15,
        .timer = 4
    },
    [26] = {
        .pFrame = sParticleOam_ChargingMissileBegin_Frame22,
        .timer = 4
    },
    [27] = {
        .pFrame = sParticleOam_ChargingMissileBegin_Frame15,
        .timer = 4
    },
    [28] = {
        .pFrame = sParticleOam_ChargingMissileBegin_Frame22,
        .timer = 4
    },
    [29] = {
        .pFrame = sParticleOam_ChargingMissileBegin_Frame15,
        .timer = 4
    },
    [30] = {
        .pFrame = sParticleOam_ChargingMissileBegin_Frame22,
        .timer = 4
    },
    [31] = {
        .pFrame = sParticleOam_ChargingMissileBegin_Frame15,
        .timer = 4
    },
    [32] = {
        .pFrame = sParticleOam_ChargingMissileBegin_Frame22,
        .timer = 4
    },
    [33] = {
        .pFrame = sParticleOam_ChargingMissileBegin_Frame15,
        .timer = 4
    },
    [34] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleOam_ChargingMissileCharged[4] = {
    [0] = {
        .pFrame = sParticleOam_ChargingMissileCharged_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sParticleOam_ChargingMissileCharged_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sParticleOam_ChargingMissileCharged_Frame2,
        .timer = 3
    },
    [3] = FRAME_DATA_TERMINATOR
};

static const u8 sBlob_3eed78_58b3cc[] = INCBIN_U8("data/Blob_3eed78_58b3cc.bin");
