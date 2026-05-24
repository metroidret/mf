#ifndef BOX_2_DATA_H
#define BOX_2_DATA_H

#include "types.h"
#include "oam.h"

#include "structs/sprite.h"

/**
 * Sprite-part indices for the Box2 boss. Used as `roomSlot` in
 * `SpriteSpawnSecondary(SSPRITE_BOX_2_PART, N, ...)` from Box2Init,
 * and dispatched on by the still-in-asm Box2Part handler:
 *   0 -> Box2PartFrontLeftLeg
 *   2 -> Box2PartFrontRightLeg
 *   6 -> Box2PartTopShell
 *   8 -> Box2PartBottomShell
 *   default -> Box2PartDefault
 * Slot 7 (BOX2_PART_BRAIN) is the primary Box2 sprite itself; not spawned
 * via SpriteSpawnSecondary because gCurrentSprite already exists as the
 * dispatcher. The MultiSpriteData pData arrays still populate slot 7 —
 * that's how the brain's per-frame y/x offset and OAM index are looked
 * up by Box2SyncSubSprites indirectly.
 */
enum Box2Part {
    BOX2_PART_FRONT_LEFT_LEG = 0,
    BOX2_PART_DEFAULT_1 = 1,
    BOX2_PART_FRONT_RIGHT_LEG = 2,
    BOX2_PART_DEFAULT_3 = 3,
    BOX2_PART_DEFAULT_4 = 4,
    BOX2_PART_DEFAULT_5 = 5,
    BOX2_PART_TOP_SHELL = 6,
    BOX2_PART_BRAIN = 7,
    BOX2_PART_BOTTOM_SHELL = 8,
    BOX2_PART_DEFAULT_9 = 9,
    BOX2_PART_DEFAULT_10 = 10,
    BOX2_PART_DEFAULT_11 = 11,

    BOX2_PART_END = 12
};

extern const s16 sBox2JumpingSpeed[28];
extern const s16 sBox2BonkingSpeed[20];
extern const s16 sBox2BrainTopRisingSpeed[65];

extern const struct MultiSpriteData sBox2MultiSpriteData_Bonking[2];
extern const struct MultiSpriteData sBox2MultiSpriteData_Landing[4];
extern const struct MultiSpriteData sBox2MultiSpriteData_JumpWarning[5];
extern const struct MultiSpriteData sBox2MultiSpriteData_Idle[5];
extern const struct MultiSpriteData sBox2MultiSpriteData_Crawling_Left[6];
extern const struct MultiSpriteData sBox2MultiSpriteData_SlowRunning_Left[6];
extern const struct MultiSpriteData sBox2MultiSpriteData_FastRunning_Left[6];
extern const struct MultiSpriteData sBox2MultiSpriteData_Crawling_Right[6];
extern const struct MultiSpriteData sBox2MultiSpriteData_SlowRunning_Right[6];
extern const struct MultiSpriteData sBox2MultiSpriteData_FastRunning_Right[6];
extern const struct MultiSpriteData sBox2MultiSpriteData_FinishedCrawling[5];
extern const struct MultiSpriteData sBox2MultiSpriteData_WaitingToRun[9];
extern const struct MultiSpriteData sBox2MultiSpriteData_Skidding_Left[2];
extern const struct MultiSpriteData sBox2MultiSpriteData_StopSkidding_Left[2];
extern const struct MultiSpriteData sBox2MultiSpriteData_Skidding_Right[2];
extern const struct MultiSpriteData sBox2MultiSpriteData_StopSkidding_Right[2];
extern const struct MultiSpriteData sBox2MultiSpriteData_LoweringToFireMissiles[8];
extern const struct MultiSpriteData sBox2MultiSpriteData_FiringMissiles[13];
extern const struct MultiSpriteData sBox2MultiSpriteData_DoneFiringMissiles[9];

enum Box2Oam {
    Box2Oam_FrontLeftLeg,
    Box2Oam_3953c8,
    Box2Oam_FrontLeftLegCoverHeavilyDamaged,
    Box2Oam_FrontLeftLegCoverModeratelyDamaged,
    Box2Oam_FrontLeftLegCoverSlightlyDamaged,
    Box2Oam_Default1_Frame0,
    Box2Oam_Default1_Frame1,
    Box2Oam_Default1_Frame2,
    Box2Oam_Default4_Frame0,
    Box2Oam_Default4_Frame1,
    Box2Oam_Default4_Frame2,
    Box2Oam_Default10_Frame0,
    Box2Oam_Default10_Frame1,
    Box2Oam_FrontRightLeg,
    Box2Oam_395530,
    Box2Oam_FrontRightLegCoverHeavilyDamaged,
    Box2Oam_FrontRightLegCoverModeratelyDamaged,
    Box2Oam_FrontRightLegCoverSlightlyDamaged,
    Box2Oam_Default3_Frame0,
    Box2Oam_Default3_Frame1,
    Box2Oam_Default3_Frame2,
    Box2Oam_Default5_Frame0,
    Box2Oam_Default5_Frame1,
    Box2Oam_Default5_Frame2,
    Box2Oam_Default11_Frame0,
    Box2Oam_Default11_Frame1,
    Box2Oam_CenterCriticallyDamaged,
    Box2Oam_CenterHeavilyDamaged,
    Box2Oam_CenterModeratelyDamaged,
    Box2Oam_CenterSlightlyDamaged,
    Box2Oam_BrainIdle,
    Box2Oam_BrainExploding,
    Box2Oam_3956f0,
    Box2Oam_CenterBottomIdle,
    Box2Oam_CenterBottomOpeningAndClosingRapidly,
    Box2Oam_395758,
    Box2Oam_395778,
    Box2Oam_Default9_Frame0,
    Box2Oam_Default9_Frame1,
    Box2Oam_Default9_Frame2,
    Box2Oam_Default9_Frame3,
    Box2Oam_Default9_Frame4,
    Box2Oam_Missile,
    Box2Oam_BrainTopRising,
    Box2Oam_CenterUndamaged,
    Box2Oam_BrainRising,

    BOX_2_OAM_END
};

extern const struct FrameData sBox2Oam_FrontLeftLeg[16];
extern const struct FrameData sBox2Oam_3953c8[7];
extern const struct FrameData sBox2Oam_FrontLeftLegCoverHeavilyDamaged[2];
extern const struct FrameData sBox2Oam_FrontLeftLegCoverModeratelyDamaged[2];
extern const struct FrameData sBox2Oam_FrontLeftLegCoverSlightlyDamaged[2];
extern const struct FrameData sBox2Oam_Default1_Frame0[2];
extern const struct FrameData sBox2Oam_Default1_Frame1[2];
extern const struct FrameData sBox2Oam_Default1_Frame2[2];
extern const struct FrameData sBox2Oam_Default4_Frame0[2];
extern const struct FrameData sBox2Oam_Default4_Frame1[2];
extern const struct FrameData sBox2Oam_Default4_Frame2[2];
extern const struct FrameData sBox2Oam_Default10_Frame0[2];
extern const struct FrameData sBox2Oam_Default10_Frame1[2];
extern const struct FrameData sBox2Oam_FrontRightLeg[16];
extern const struct FrameData sBox2Oam_395530[7];
extern const struct FrameData sBox2Oam_FrontRightLegCoverHeavilyDamaged[2];
extern const struct FrameData sBox2Oam_FrontRightLegCoverModeratelyDamaged[2];
extern const struct FrameData sBox2Oam_FrontRightLegCoverSlightlyDamaged[2];
extern const struct FrameData sBox2Oam_Default3_Frame0[2];
extern const struct FrameData sBox2Oam_Default3_Frame1[2];
extern const struct FrameData sBox2Oam_Default3_Frame2[2];
extern const struct FrameData sBox2Oam_Default5_Frame0[2];
extern const struct FrameData sBox2Oam_Default5_Frame1[2];
extern const struct FrameData sBox2Oam_Default5_Frame2[2];
extern const struct FrameData sBox2Oam_Default11_Frame0[2];
extern const struct FrameData sBox2Oam_Default11_Frame1[2];
extern const struct FrameData sBox2Oam_CenterCriticallyDamaged[2];
extern const struct FrameData sBox2Oam_CenterHeavilyDamaged[2];
extern const struct FrameData sBox2Oam_CenterModeratelyDamaged[2];
extern const struct FrameData sBox2Oam_CenterSlightlyDamaged[2];
extern const struct FrameData sBox2Oam_BrainIdle[12];
extern const struct FrameData sBox2Oam_BrainExploding[7];
extern const struct FrameData sBox2Oam_3956f0[5];
extern const struct FrameData sBox2Oam_CenterBottomIdle[2];
extern const struct FrameData sBox2Oam_CenterBottomOpeningAndClosingRapidly[6];
extern const struct FrameData sBox2Oam_395758[4];
extern const struct FrameData sBox2Oam_395778[4];
extern const struct FrameData sBox2Oam_Default9_Frame0[2];
extern const struct FrameData sBox2Oam_Default9_Frame1[2];
extern const struct FrameData sBox2Oam_Default9_Frame2[2];
extern const struct FrameData sBox2Oam_Default9_Frame3[2];
extern const struct FrameData sBox2Oam_Default9_Frame4[2];
extern const struct FrameData sBox2Oam_Missile[4];
extern const struct FrameData sBox2Oam_BrainTopRising[12];
extern const struct FrameData sBox2Oam_CenterUndamaged[12];
extern const struct FrameData sBox2Oam_BrainRising[2];
extern const struct FrameData sBox2Oam_BrainBottomInit[5];

#endif /* BOX_2_DATA_H */
