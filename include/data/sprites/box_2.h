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

extern const struct MultiSpriteData sBox2MultiOam_Jumping[];
extern const struct MultiSpriteData sBox2MultiOam_Landing[];
extern const struct MultiSpriteData sBox2MultiOam_JumpWarning[];
extern const struct MultiSpriteData sBox2MultiOam_Idle[];
extern const struct MultiSpriteData sBox2MultiOam_Crawling_Left[];
extern const struct MultiSpriteData sBox2MultiOam_SlowRunning_Left[];
extern const struct MultiSpriteData sBox2MultiOam_FastRunning_Left[];
extern const struct MultiSpriteData sBox2MultiOam_Crawling_Right[];
extern const struct MultiSpriteData sBox2MultiOam_SlowRunning_Right[];
extern const struct MultiSpriteData sBox2MultiOam_FastRunning_Right[];
extern const struct MultiSpriteData sBox2MultiOam_StoppingToFireMissiles[];
extern const struct MultiSpriteData sBox2MultiOam_WaitingToRun[];
extern const struct MultiSpriteData sBox2MultiOam_Skidding_Left[];
extern const struct MultiSpriteData sBox2MultiOam_StopSkidding_Left[];
extern const struct MultiSpriteData sBox2MultiOam_Skidding_Right[];
extern const struct MultiSpriteData sBox2MultiOam_StopSkidding_Right[];
extern const struct MultiSpriteData sBox2MultiOam_LoweringToFireMissiles[];
extern const struct MultiSpriteData sBox2MultiOam_FiringMissiles[];
extern const struct MultiSpriteData sBox2MultiOam_DoneFiringMissiles[];

extern const u32 sBox2Gfx[512 * 7];
extern const u16 sBox2Pal[PAL_ROW * 7];

extern const struct FrameData sBox2PartOam_FrontLeftLegCover_Undamaged[];
extern const struct FrameData sBox2PartOam_FrontLeftLegCover_Shaking[];
extern const struct FrameData sBox2PartOam_FrontLeftLegCover_SlightlyDamaged[];
extern const struct FrameData sBox2PartOam_FrontLeftLegCover_ModeratelyDamaged[];
extern const struct FrameData sBox2PartOam_FrontLeftLegCover_SeverelyDamaged[];
extern const struct FrameData sBox2PartOam_FrontLeftLeg_Low[];
extern const struct FrameData sBox2PartOam_FrontLeftLeg_High[];
extern const struct FrameData sBox2PartOam_FrontLeftLeg_Middle[];
extern const struct FrameData sBox2PartOam_MiddleLeftLeg_Low[];
extern const struct FrameData sBox2PartOam_MiddleLeftLeg_High[];
extern const struct FrameData sBox2PartOam_MiddleLeftLeg_Middle[];
extern const struct FrameData sBox2PartOam_BackLeftLeg_Low[];
extern const struct FrameData sBox2PartOam_BackLeftLeg_High[];
extern const struct FrameData sBox2PartOam_FrontRightLegCover_Undamaged[];
extern const struct FrameData sBox2PartOam_FrontRightLegCover_Shaking[];
extern const struct FrameData sBox2PartOam_FrontRightLegCover_SlightlyDamaged[];
extern const struct FrameData sBox2PartOam_FrontRightLegCover_ModeratelyDamaged[];
extern const struct FrameData sBox2PartOam_FrontRightLegCover_SeverelyDamaged[];
extern const struct FrameData sBox2PartOam_FrontRightLeg_Low[];
extern const struct FrameData sBox2PartOam_FrontRightLeg_High[];
extern const struct FrameData sBox2PartOam_FrontRightLeg_Middle[];
extern const struct FrameData sBox2PartOam_MiddleRightLeg_Low[];
extern const struct FrameData sBox2PartOam_MiddleRightLeg_High[];
extern const struct FrameData sBox2PartOam_MiddleRightLeg_Middle[];
extern const struct FrameData sBox2PartOam_BackRightLeg_Low[];
extern const struct FrameData sBox2PartOam_BackRightLeg_High[];
extern const struct FrameData sBox2PartOam_Center_Exposed[];
extern const struct FrameData sBox2PartOam_Center_SlightlyDamaged[];
extern const struct FrameData sBox2PartOam_Center_ModeratelyDamaged[];
extern const struct FrameData sBox2PartOam_Center_SeverelyDamaged[];
extern const struct FrameData sBox2PartOam_Brain_Idle[];
extern const struct FrameData sBox2PartOam_Brain_Shaking[];
extern const struct FrameData sBox2PartOam_Brain_Pulsing[];
extern const struct FrameData sBox2PartOam_Bottom_Idle[];
extern const struct FrameData sBox2PartOam_Bottom_OpeningAndClosing[];
extern const struct FrameData sBox2PartOam_Jets_Small[];
extern const struct FrameData sBox2PartOam_Jets_Big[];
extern const struct FrameData sBox2PartOam_Launcher_Idle[];
extern const struct FrameData sBox2PartOam_Launcher_3Missiles[];
extern const struct FrameData sBox2PartOam_Launcher_2Missiles[];
extern const struct FrameData sBox2PartOam_Launcher_1Missile[];
extern const struct FrameData sBox2PartOam_Launcher_NoMissiles[];
extern const struct FrameData sBox2PartOam_Missile[];
extern const struct FrameData sBox2PartOam_Brain_Floating[];
extern const struct FrameData sBox2PartOam_Center_Undamaged[];
extern const struct FrameData sBox2PartOam_Center_NoBrain[];

extern const struct FrameData sBox2PartOam_BrainBottom[];

#endif /* BOX_2_DATA_H */
