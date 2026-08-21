#ifndef BOX_DATA_H
#define BOX_DATA_H

#include "types.h"
#include "oam.h"

#include "structs/sprite.h"

enum BoxOam {
    BOX_OAM_PART_FRONT_LEFT_LEG_COVER_UNDAMAGED,
    BOX_OAM_3479B8,
    BOX_OAM_PART_FRONT_LEFT_LEG_COVER_DAMAGED,
    BOX_OAM_347A00,
    BOX_OAM_347A10,
    BOX_OAM_PART_FRONT_LEFT_LEG_0,
    BOX_OAM_PART_FRONT_LEFT_LEG_1,
    BOX_OAM_PART_FRONT_LEFT_LEG_2,
    BOX_OAM_347A50,
    BOX_OAM_347A60,
    BOX_OAM_347A70,
    BOX_OAM_347A80,
    BOX_OAM_347A90,
    BOX_OAM_PART_FRONT_RIGHT_LEG_COVER_UNDAMAGED,
    BOX_OAM_347AB0,
    BOX_OAM_347AE8,
    BOX_OAM_347AF8,
    BOX_OAM_347B08,
    BOX_OAM_347B18,
    BOX_OAM_347B28,
    BOX_OAM_347B38,
    BOX_OAM_347B48,
    BOX_OAM_347B58,
    BOX_OAM_347B68,
    BOX_OAM_347B78,
    BOX_OAM_347B88,
    BOX_OAM_PART_CENTER_UNDAMAGED,
    BOX_OAM_347BA8,
    BOX_OAM_347BB8,
    BOX_OAM_347BC8,
    BOX_OAM_PART_BRAIN,
    BOX_OAM_347C38,
    BOX_OAM_347C70,
    BOX_OAM_347C98,
    BOX_OAM_347CA8,
    BOX_OAM_347CD8,
    BOX_OAM_347CF8,
    BOX_OAM_347D18,
    BOX_OAM_347D28,
    BOX_OAM_347D38,
    BOX_OAM_347D48,
    BOX_OAM_347D58,
    BOX_OAM_347D68,
    BOX_OAM_347D88,
    BOX_OAM_347E58,
    BOX_OAM_347E80,
    BOX_OAM_347FA8,
    BOX_OAM_347FB8,
    BOX_OAM_347FC8,
    BOX_OAM_347FD8,
    BOX_OAM_347FE8,
    BOX_OAM_347FF8,
    BOX_OAM_348008,
    BOX_OAM_348018,
    BOX_OAM_348028,
    BOX_OAM_348038,
    BOX_OAM_348048,
    BOX_OAM_3480A8,

    BOX_OAM_END
};

enum BoxPart {
    BOX_PART_FRONT_LEFT_LEG_COVER,
    BOX_PART_FRONT_LEFT_LEG,
    BOX_PART_FRONT_RIGHT_LEG_COVER,
    BOX_PART_FRONT_RIGHT_LEG,
    BOX_PART_MIDDLE_LEFT_LEG,
    BOX_PART_MIDDLE_RIGHT_LEG,
    BOX_PART_CENTER,
    BOX_PART_BRAIN,
    BOX_PART_CENTER_BOTTOM,
    BOX_PART_LAUNCHER,
    BOX_PART_BACK_LEFT_LEG,
    BOX_PART_BACK_RIGHT_LEG,

    BOX_PART_END
};

extern const s16 sBoxFirstJumpSpeed[24];
extern const s16 sBoxJumpingSpeed[20];
extern const s16 sBoxBonkingSpeed[20];
extern const s16 sBoxBombSecondBounceSpeed[5];
extern const s16 sBoxBombFirstBounceSpeed[6];
extern const s16 sBoxBombLaunchingSpeed[11];
extern const s16 sBoxBombFallingSpeed[16];

extern const struct MultiSpriteData sBoxMultiSpriteData_Jumping[2];
extern const struct MultiSpriteData sBoxMultiSpriteData_Landing[4];
extern const struct MultiSpriteData sBoxMultiSpriteData_JumpWarning[5];
extern const struct MultiSpriteData sBoxMultiSpriteData_Idle[5];
extern const struct MultiSpriteData sBoxMultiSpriteData_Crawling_Left[6];
extern const struct MultiSpriteData sBoxMultiSpriteData_SlowRun_Left[6];
extern const struct MultiSpriteData sBoxMultiSpriteData_FastRun_Left[6];
extern const struct MultiSpriteData sBoxMultiSpriteData_Crawling_Right[6];
extern const struct MultiSpriteData sBoxMultiSpriteData_SlowRun_Right[6];
extern const struct MultiSpriteData sBoxMultiSpriteData_FastRun_Right[6];
extern const struct MultiSpriteData sBoxMultiSpriteData_FinishedCrawling[5];
extern const struct MultiSpriteData sBoxMultiSpriteData_WaitingToRun[9];
extern const struct MultiSpriteData sBoxMultiSpriteData_Skidding_Left[2];
extern const struct MultiSpriteData sBoxMultiSpriteData_StopSkidding_Left[2];
extern const struct MultiSpriteData sBoxMultiSpriteData_Skidding_Right[2];
extern const struct MultiSpriteData sBoxMultiSpriteData_StopSkidding_Right[2];
extern const struct MultiSpriteData sBoxMultiSpriteData_LoweringToFireBomb[8];
extern const struct MultiSpriteData sBoxMultiSpriteData_FiringBomb[4];
extern const struct MultiSpriteData sBoxMultiSpriteData_DoneFiringBomb[9];

extern const u32 sBoxGfx[512 * 8];
extern const u16 sBoxPal[16 * 8];

extern const struct FrameData sBoxPartOam_FrontLeftLegCoverUndamaged[2];
extern const struct FrameData sBoxPartOam_FrontLeftLegCoverShaking[7];
extern const struct FrameData sBoxPartOam_FrontLeftLegCoverSlightlyDamaged[2];
extern const struct FrameData sBoxPartOam_FrontLeftLegCoverModeratelyDamaged[2];
extern const struct FrameData sBoxPartOam_FrontLeftLegCoverHeavilyDamaged[2];
extern const struct FrameData sBoxPartOam_FrontLeftLeg_0[2];
extern const struct FrameData sBoxPartOam_FrontLeftLeg_1[2];
extern const struct FrameData sBoxPartOam_FrontLeftLeg_2[2];
extern const struct FrameData sBoxPartOam_MiddleLeftLeg_0[2];
extern const struct FrameData sBoxPartOam_MiddleLeftLeg_1[2];
extern const struct FrameData sBoxPartOam_MiddleLeftLeg_2[2];
extern const struct FrameData sBoxPartOam_BackLeftLeg_0[2];
extern const struct FrameData sBoxPartOam_BackLeftLeg_1[2];
extern const struct FrameData sBoxPartOam_FrontRightLegCoverUndamaged[2];
extern const struct FrameData sBoxPartOam_FrontRightLegCoverShaking[7];
extern const struct FrameData sBoxPartOam_FrontRightLegCoverSlightlyDamaged[2];
extern const struct FrameData sBoxPartOam_FrontRightLegCoverModeratelyDamaged[2];
extern const struct FrameData sBoxPartOam_FrontRightLegCoverHeavilyDamaged[2];
extern const struct FrameData sBoxPartOam_FrontRightLeg_0[2];
extern const struct FrameData sBoxPartOam_FrontRightLeg_1[2];
extern const struct FrameData sBoxPartOam_FrontRightLeg_2[2];
extern const struct FrameData sBoxPartOam_MiddleRightLeg_0[2];
extern const struct FrameData sBoxPartOam_MiddleRightLeg_1[2];
extern const struct FrameData sBoxPartOam_MiddleRightLeg_2[2];
extern const struct FrameData sBoxPartOam_BackRightLeg_0[2];
extern const struct FrameData sBoxPartOam_BackRightLeg_1[2];
extern const struct FrameData sBoxPartOam_CenterUndamaged[2];
extern const struct FrameData sBoxPartOam_CenterSlightlyDamaged[2];
extern const struct FrameData sBoxPartOam_CenterModeratelyDamaged[2];
extern const struct FrameData sBoxPartOam_CenterHeavilyDamaged[2];
extern const struct FrameData sBoxPartOam_BrainIdle[12];
extern const struct FrameData sBoxPartOam_BrainShaking[7];
extern const struct FrameData sBoxPartOam_BrainFlashingFaster[5];
extern const struct FrameData sBoxPartOam_CenterBottomIdle[2];
extern const struct FrameData sBoxPartOam_CenterBottomOpeningAndClosingRapidly[6];
extern const struct FrameData sBoxJetsOam_Small[4];
extern const struct FrameData sBoxJetsOam_Big[4];
extern const struct FrameData sBoxPartOam_LauncherIdle[2];
extern const struct FrameData sBoxPartOam_LauncherOpening_0[2];
extern const struct FrameData sBoxPartOam_LauncherOpening_1[2];
extern const struct FrameData sBoxPartOam_LauncherOpening_2[2];
extern const struct FrameData sBoxPartOam_LauncherOpening_3[2];
extern const struct FrameData sBoxMissileOam[4];
extern const struct FrameData sBoxBombOam_MovingUnused[26];
extern const struct FrameData sBoxBombOam_Detonating[5];
extern const struct FrameData sBoxFireOam_MovingHigh[37];
extern const struct FrameData sBoxDebrisOam[2];
extern const struct FrameData sBoxFallingDebrisOam_0[2];
extern const struct FrameData sBoxFallingDebrisOam_1[2];
extern const struct FrameData sBoxFallingDebrisOam_2[2];
extern const struct FrameData sBoxFallingDebrisOam_3[2];
extern const struct FrameData sBoxFallingDebrisOam_4[2];
extern const struct FrameData sBoxFallingDebrisOam_5[2];
extern const struct FrameData sBoxFallingDebrisOam_6[2];
extern const struct FrameData sBoxFallingDebrisOam_7[2];
extern const struct FrameData sBoxFallingDebrisOam_8[2];
extern const struct FrameData sBoxPartOam_BrainAndCenterBottom_Idle[12];
extern const struct FrameData sBoxFireOam_MovingLow[4];

#endif /* BOX_DATA_H */
