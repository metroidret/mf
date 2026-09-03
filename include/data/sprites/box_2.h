#ifndef BOX_2_DATA_H
#define BOX_2_DATA_H

#include "types.h"
#include "oam.h"
#include "gba/memory.h"
#include "structs/sprite.h"

enum Box2Part {
    BOX_2_PART_FRONT_LEFT_LEG_COVER,
    BOX_2_PART_FRONT_LEFT_LEG,
    BOX_2_PART_FRONT_RIGHT_LEG_COVER,
    BOX_2_PART_FRONT_RIGHT_LEG,
    BOX_2_PART_MIDDLE_LEFT_LEG,
    BOX_2_PART_MIDDLE_RIGHT_LEG,
    BOX_2_PART_CENTER,
    BOX_2_PART_BRAIN,
    BOX_2_PART_BOTTOM,
    BOX_2_PART_LAUNCHER,
    BOX_2_PART_BACK_LEFT_LEG,
    BOX_2_PART_BACK_RIGHT_LEG,

    BOX_2_PART_COUNT
};

enum Box2Oam {
    BOX_2_OAM_FRONT_LEFT_LEG_COVER_UNDAMAGED,
    BOX_2_OAM_FRONT_LEFT_LEG_COVER_SHAKING,
    BOX_2_OAM_FRONT_LEFT_LEG_COVER_SLIGHTLY_DAMAGED,
    BOX_2_OAM_FRONT_LEFT_LEG_COVER_MODERATELY_DAMAGED,
    BOX_2_OAM_FRONT_LEFT_LEG_COVER_SEVERELY_DAMAGED,
    BOX_2_OAM_FRONT_LEFT_LEG_LOW,
    BOX_2_OAM_FRONT_LEFT_LEG_HIGH,
    BOX_2_OAM_FRONT_LEFT_LEG_MIDDLE,
    BOX_2_OAM_MIDDLE_LEFT_LEG_LOW,
    BOX_2_OAM_MIDDLE_LEFT_LEG_HIGH,
    BOX_2_OAM_MIDDLE_LEFT_LEG_MIDDLE,
    BOX_2_OAM_BACK_LEFT_LEG_LOW,
    BOX_2_OAM_BACK_LEFT_LEG_HIGH,
    BOX_2_OAM_FRONT_RIGHT_LEG_COVER_UNDAMAGED,
    BOX_2_OAM_FRONT_RIGHT_LEG_COVER_SHAKING,
    BOX_2_OAM_FRONT_RIGHT_LEG_COVER_SLIGHTLY_DAMAGED,
    BOX_2_OAM_FRONT_RIGHT_LEG_COVER_MODERATELY_DAMAGED,
    BOX_2_OAM_FRONT_RIGHT_LEG_COVER_SEVERELY_DAMAGED,
    BOX_2_OAM_FRONT_RIGHT_LEG_LOW,
    BOX_2_OAM_FRONT_RIGHT_LEG_HIGH,
    BOX_2_OAM_FRONT_RIGHT_LEG_MIDDLE,
    BOX_2_OAM_MIDDLE_RIGHT_LEG_LOW,
    BOX_2_OAM_MIDDLE_RIGHT_LEG_HIGH,
    BOX_2_OAM_MIDDLE_RIGHT_LEG_MIDDLE,
    BOX_2_OAM_BACK_RIGHT_LEG_LOW,
    BOX_2_OAM_BACK_RIGHT_LEG_HIGH,
    BOX_2_OAM_CENTER_EXPOSED,
    BOX_2_OAM_CENTER_SLIGHTLY_DAMAGED,
    BOX_2_OAM_CENTER_MODERATELY_DAMAGED,
    BOX_2_OAM_CENTER_SEVERELY_DAMAGED,
    BOX_2_OAM_BRAIN_IDLE,
    BOX_2_OAM_BRAIN_SHAKING,
    BOX_2_OAM_BRAIN_PULSING,
    BOX_2_OAM_BOTTOM_IDLE,
    BOX_2_OAM_BOTTOM_OPENING_AND_CLOSING,
    BOX_2_OAM_JETS_SMALL,
    BOX_2_OAM_JETS_BIG,
    BOX_2_OAM_LAUNCHER_IDLE,
    BOX_2_OAM_LAUNCHER_3MISSILES,
    BOX_2_OAM_LAUNCHER_2MISSILES,
    BOX_2_OAM_LAUNCHER_1MISSILE,
    BOX_2_OAM_LAUNCHER_NO_MISSILES,
    BOX_2_OAM_MISSILE,
    BOX_2_OAM_BRAIN_FLOATING,
    BOX_2_OAM_CENTER_UNDAMAGED,
    BOX_2_OAM_CENTER_NO_BRAIN,

    BOX_2_OAM_COUNT
};

extern const s16 sBox2JumpingYSpeeds[28];
extern const s16 sBox2BonkingYSpeeds[20];
extern const s16 sBox2BrainYSpeeds[65];

extern const struct MultiSpriteData sBox2MultiOam_Jumping[2];
extern const struct MultiSpriteData sBox2MultiOam_Landing[4];
extern const struct MultiSpriteData sBox2MultiOam_JumpWarning[5];
extern const struct MultiSpriteData sBox2MultiOam_Idle[5];
extern const struct MultiSpriteData sBox2MultiOam_Crawling_Left[6];
extern const struct MultiSpriteData sBox2MultiOam_SlowRunning_Left[6];
extern const struct MultiSpriteData sBox2MultiOam_FastRunning_Left[6];
extern const struct MultiSpriteData sBox2MultiOam_Crawling_Right[6];
extern const struct MultiSpriteData sBox2MultiOam_SlowRunning_Right[6];
extern const struct MultiSpriteData sBox2MultiOam_FastRunning_Right[6];
extern const struct MultiSpriteData sBox2MultiOam_StoppingToFireMissiles[5];
extern const struct MultiSpriteData sBox2MultiOam_WaitingToRun[9];
extern const struct MultiSpriteData sBox2MultiOam_Skidding_Left[2];
extern const struct MultiSpriteData sBox2MultiOam_StopSkidding_Left[2];
extern const struct MultiSpriteData sBox2MultiOam_Skidding_Right[2];
extern const struct MultiSpriteData sBox2MultiOam_StopSkidding_Right[2];
extern const struct MultiSpriteData sBox2MultiOam_LoweringToFireMissiles[8];
extern const struct MultiSpriteData sBox2MultiOam_FiringMissiles[13];
extern const struct MultiSpriteData sBox2MultiOam_DoneFiringMissiles[9];

extern const u32 sBox2Gfx[512 * 7];
extern const u16 sBox2Pal[PAL_ROW * 7];

extern const struct FrameData sBox2PartOam_FrontLeftLegCover_Undamaged[16];
extern const struct FrameData sBox2PartOam_FrontLeftLegCover_Shaking[7];
extern const struct FrameData sBox2PartOam_FrontLeftLegCover_SlightlyDamaged[2];
extern const struct FrameData sBox2PartOam_FrontLeftLegCover_ModeratelyDamaged[2];
extern const struct FrameData sBox2PartOam_FrontLeftLegCover_SeverelyDamaged[2];
extern const struct FrameData sBox2PartOam_FrontLeftLeg_Low[2];
extern const struct FrameData sBox2PartOam_FrontLeftLeg_High[2];
extern const struct FrameData sBox2PartOam_FrontLeftLeg_Middle[2];
extern const struct FrameData sBox2PartOam_MiddleLeftLeg_Low[2];
extern const struct FrameData sBox2PartOam_MiddleLeftLeg_High[2];
extern const struct FrameData sBox2PartOam_MiddleLeftLeg_Middle[2];
extern const struct FrameData sBox2PartOam_BackLeftLeg_Low[2];
extern const struct FrameData sBox2PartOam_BackLeftLeg_High[2];
extern const struct FrameData sBox2PartOam_FrontRightLegCover_Undamaged[16];
extern const struct FrameData sBox2PartOam_FrontRightLegCover_Shaking[7];
extern const struct FrameData sBox2PartOam_FrontRightLegCover_SlightlyDamaged[2];
extern const struct FrameData sBox2PartOam_FrontRightLegCover_ModeratelyDamaged[2];
extern const struct FrameData sBox2PartOam_FrontRightLegCover_SeverelyDamaged[2];
extern const struct FrameData sBox2PartOam_FrontRightLeg_Low[2];
extern const struct FrameData sBox2PartOam_FrontRightLeg_High[2];
extern const struct FrameData sBox2PartOam_FrontRightLeg_Middle[2];
extern const struct FrameData sBox2PartOam_MiddleRightLeg_Low[2];
extern const struct FrameData sBox2PartOam_MiddleRightLeg_High[2];
extern const struct FrameData sBox2PartOam_MiddleRightLeg_Middle[2];
extern const struct FrameData sBox2PartOam_BackRightLeg_Low[2];
extern const struct FrameData sBox2PartOam_BackRightLeg_High[2];
extern const struct FrameData sBox2PartOam_Center_Exposed[2];
extern const struct FrameData sBox2PartOam_Center_SlightlyDamaged[2];
extern const struct FrameData sBox2PartOam_Center_ModeratelyDamaged[2];
extern const struct FrameData sBox2PartOam_Center_SeverelyDamaged[2];
extern const struct FrameData sBox2PartOam_Brain_Idle[12];
extern const struct FrameData sBox2PartOam_Brain_Shaking[7];
extern const struct FrameData sBox2PartOam_Brain_Pulsing[5];
extern const struct FrameData sBox2PartOam_Bottom_Idle[2];
extern const struct FrameData sBox2PartOam_Bottom_OpeningAndClosing[6];
extern const struct FrameData sBox2PartOam_Jets_Small[4];
extern const struct FrameData sBox2PartOam_Jets_Big[4];
extern const struct FrameData sBox2PartOam_Launcher_Idle[2];
extern const struct FrameData sBox2PartOam_Launcher_3Missiles[2];
extern const struct FrameData sBox2PartOam_Launcher_2Missiles[2];
extern const struct FrameData sBox2PartOam_Launcher_1Missile[2];
extern const struct FrameData sBox2PartOam_Launcher_NoMissiles[2];
extern const struct FrameData sBox2PartOam_Missile[4];
extern const struct FrameData sBox2PartOam_Brain_Floating[12];
extern const struct FrameData sBox2PartOam_Center_Undamaged[12];
extern const struct FrameData sBox2PartOam_Center_NoBrain[2];

extern const struct FrameData sBox2PartOam_BrainBottom[5];

#endif /* BOX_2_DATA_H */
