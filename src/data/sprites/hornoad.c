#include "data/sprites/hornoad.h"
#include "macros.h"

const s16 sHornoadSpitYMovement[21] = {
    -4, -4, -3, -3
    -2, -2, -1, -1,
     0,  0,  0,  0,
     1,  1,  2,  2,
     4,  4,  8,  8,
     SHORT_MAX
};

const s16 sHornoadJumpVelocityHigh[10] = {
    -6, -12, -6, -3,
     0,   4,  8,  12,
    16,  16
};

const s16 sHornoadJumpVelocityLow[10] = {
    -4,  -8, -4, -3,
     0,   4,  8, 16,
    16,  16
};

const u32 sHornoadGfx[1536] = INCBIN_U32("data/sprites/hornoad.gfx");
const u16 sHornoadPal[16 * 3] = INCBIN_U16("data/sprites/hornoad.pal");

static const u16 sHornoadOam_TiltingHeadHidden_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 567, 8, 0),
    OAM_ENTRY(-4, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-16, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 525, 8, 0),
    OAM_ENTRY(0, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 527, 8, 0),
};

static const u16 sHornoadOam_TiltingHeadHidden_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 567, 8, 0),
    OAM_ENTRY(-4, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-16, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 618, 8, 0),
    OAM_ENTRY(-16, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(0, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 514, 8, 0),
};

static const u16 sHornoadOam_TiltingHeadHidden_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 567, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-16, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(0, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 530, 8, 0),
};

static const u16 sHornoadOam_MunchingHidden_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 567, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-16, -13, OAM_DIMS_16x8, OAM_NO_FLIP, 618, 8, 0),
    OAM_ENTRY(-16, -21, OAM_DIMS_16x8, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(0, -21, OAM_DIMS_8x16, OAM_NO_FLIP, 514, 8, 0),
};

static const u16 sHornoadOam_MunchingHidden_Frame4[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 567, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-17, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(-17, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-1, -21, OAM_DIMS_8x16, OAM_NO_FLIP, 514, 8, 0),
};

static const u16 sHornoadOam_MunchingHidden_Frame5[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 567, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-16, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 611, 8, 0),
    OAM_ENTRY(-16, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(0, -21, OAM_DIMS_8x16, OAM_NO_FLIP, 514, 8, 0),
};

static const u16 sHornoadOam_MouthHangingOpenHidden_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 567, 8, 0),
    OAM_ENTRY(-4, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-16, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 618, 8, 0),
    OAM_ENTRY(-16, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(0, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 514, 8, 0),
};

static const u16 sHornoadOam_MouthHangingOpenHidden_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-10, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 599, 8, 0),
    OAM_ENTRY(-2, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 568, 8, 0),
    OAM_ENTRY(-4, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-16, -10, OAM_DIMS_16x8, OAM_NO_FLIP, 618, 8, 0),
    OAM_ENTRY(-16, -18, OAM_DIMS_16x8, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(0, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 514, 8, 0),
};

static const u16 sHornoadOam_TurningAroundHidden_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(2, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 585, 8, 0),
    OAM_ENTRY(-12, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 576, 8, 0),
    OAM_ENTRY(4, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 578, 8, 0),
    OAM_ENTRY(-11, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 585, 8, 0),
};

static const u16 sHornoadOam_2eabe0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-10, -16, OAM_DIMS_8x16, OAM_X_FLIP, 585, 8, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_16x16, OAM_X_FLIP, 576, 8, 0),
    OAM_ENTRY(-12, -24, OAM_DIMS_8x16, OAM_X_FLIP, 578, 8, 0),
    OAM_ENTRY(3, -16, OAM_DIMS_8x16, OAM_X_FLIP, 585, 8, 0),
};

static const u16 sHornoadOam_2eabfa[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_X_FLIP, 567, 8, 0),
    OAM_ENTRY(-4, -15, OAM_DIMS_8x8, OAM_X_FLIP, 536, 8, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_16x8, OAM_X_FLIP, 618, 8, 0),
    OAM_ENTRY(0, -20, OAM_DIMS_16x8, OAM_X_FLIP, 512, 8, 0),
    OAM_ENTRY(-8, -20, OAM_DIMS_8x16, OAM_X_FLIP, 514, 8, 0),
};

static const u16 sHornoadOam_2eac1a[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_X_FLIP, 567, 8, 0),
    OAM_ENTRY(-4, -14, OAM_DIMS_8x8, OAM_X_FLIP, 536, 8, 0),
    OAM_ENTRY(-1, -10, OAM_DIMS_16x8, OAM_X_FLIP, 618, 8, 0),
    OAM_ENTRY(-1, -18, OAM_DIMS_16x8, OAM_X_FLIP, 512, 8, 0),
    OAM_ENTRY(-9, -18, OAM_DIMS_8x16, OAM_X_FLIP, 514, 8, 0),
};

static const u16 sHornoadOam_2eac2a[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_X_FLIP, 567, 8, 0),
    OAM_ENTRY(-4, -14, OAM_DIMS_8x8, OAM_X_FLIP, 536, 8, 0),
    OAM_ENTRY(0, -11, OAM_DIMS_16x8, OAM_X_FLIP, 618, 8, 0),
    OAM_ENTRY(0, -19, OAM_DIMS_16x8, OAM_X_FLIP, 512, 8, 0),
    OAM_ENTRY(-8, -19, OAM_DIMS_8x16, OAM_X_FLIP, 514, 8, 0),
};

static const u16 sHornoadOam_IdleHidden_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 567, 8, 0),
    OAM_ENTRY(-5, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-16, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-16, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 579, 8, 0),
    OAM_ENTRY(0, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 514, 8, 0),
};

static const u16 sHornoadOam_IdleHidden_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 567, 8, 0),
    OAM_ENTRY(-5, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-16, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 603, 8, 0),
    OAM_ENTRY(-16, -18, OAM_DIMS_16x8, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(0, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 514, 8, 0),
};

static const u16 sHornoadOam_IdleHidden_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 567, 8, 0),
    OAM_ENTRY(-5, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-16, -9, OAM_DIMS_16x8, OAM_NO_FLIP, 579, 8, 0),
    OAM_ENTRY(-16, -17, OAM_DIMS_16x8, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(0, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 514, 8, 0),
};








const struct FrameData sHornoadOam_TiltingHeadHidden[5];
const struct FrameData sHornoadOam_MunchingHidden[9];
const struct FrameData sHornoadOam_MouthHangingOpenHidden[5];
const struct FrameData sHornoadOam_TurningAroundHidden[3];
const struct FrameData sHornoadOam_TurninSecondPartHidden[3];
const struct FrameData sHornoadOam_IdleHidden[5];
const struct FrameData sHornoadOam_JumpingHidden[5];
const struct FrameData sHornoadOam_LandingHidden[3];
const struct FrameData sHornoadOam_FallingHidden[3];
const struct FrameData sHornoadOam_2eb594[3];

const struct FrameData sHornoadSpawnerOam_Idle[4];
const struct FrameData sHornoadSpawnerOam_BeforeSpawning[7];

const struct FrameData sHornoadOam_TiltingHead[5];
const struct FrameData sHornoadOam_Munching[9];
const struct FrameData sHornoadOam_MouthHangingOpen[5];
const struct FrameData sHornoadOam_TurningAround[3];
const struct FrameData sHornoadOam_TurninSecondPart[3];
const struct FrameData sHornoadOam_Idle[5];
const struct FrameData sHornoadOam_Jumping[5];
const struct FrameData sHornoadOam_Landing[3];
const struct FrameData sHornoadOam_Spitting[7];

const struct FrameData sHornoadSpitOam_Idle[3];
const struct FrameData sHornoadSpitOam_2eb784[4];
const struct FrameData sHornoadSpitOam_2eb7a4[4];
const struct FrameData sHornoadSpitOam_Exploding[4];
const struct FrameData sHornoadSpitOam_2eb7e4[2];

const struct FrameData sHornoadSpawnerOam_Spawning[4];

const struct FrameData sHornoadOam_Falling[3];
const struct FrameData sHornoadOam_2eb82c[3];
const struct FrameData sHornoadOam_2eb844[3];