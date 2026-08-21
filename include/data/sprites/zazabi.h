#ifndef ZAZABI_DATA_H
#define ZAZABI_DATA_H

#include "types.h"
#include "oam.h"

#include "structs/sprite.h"

enum ZazabiOam {
    ZAZABI_OAM_LOWER_SHELL_IDLE,
    ZAZABI_OAM_LOWER_SHELL_EATING_SAMUS,
    ZAZABI_OAM_LOWER_SHELL_SWALLOWING_SAMUS,
    ZAZABI_OAM_372820,
    ZAZABI_OAM_MIDDLE_SHELL_IDLE,
    ZAZABI_OAM_MIDDLE_SHELL_EATING_SAMUS_3,
    ZAZABI_OAM_MIDDLE_SHELL_SWALLOWING_SAMUS,
    ZAZABI_OAM_MIDDLE_SHELL_EATING_SAMUS_2,
    ZAZABI_OAM_UPPER_SHELL_IDLE,
    ZAZABI_OAM_UPPER_SHELL_EATING_SAMUS_5,
    ZAZABI_OAM_UPPER_SHELL_SWALLOWING_SAMUS,
    ZAZABI_OAM_UPPER_SHELL_EATING_SAMUS_4,
    ZAZABI_OAM_EYE_SHELL_IDLE,
    ZAZABI_OAM_EYE_SHELL_SWALLOWING_SAMUS_LOW,
    ZAZABI_OAM_372950,
    ZAZABI_OAM_372970,
    ZAZABI_OAM_MOUTH_FRONT_IDLE,
    ZAZABI_OAM_MOUTH_FRONT_LANDING,
    ZAZABI_OAM_MOUTH_FRONT_CRAWLING_LOW,
    ZAZABI_OAM_MOUTH_FRONT_CRAWLING_HIGH,
    ZAZABI_OAM_MOUTH_FRONT_CRAWLING_HALTED,
    ZAZABI_OAM_MOUTH_FRONT_OPENING_1,
    ZAZABI_OAM_MOUTH_BACK_OPENING_1,
    ZAZABI_OAM_MOUTH_FRONT_OPENING_2,
    ZAZABI_OAM_MOUTH_BACK_OPENING_2,
    ZAZABI_OAM_MOUTH_FRONT_OPENED,
    ZAZABI_OAM_EYE_IDLE,
    ZAZABI_OAM_EYE_EATING_SAMUS,
    ZAZABI_OAM_PUPIL_BLINKING,
    ZAZABI_OAM_HAIR_MOVING,
    ZAZABI_OAM_HAIR_STILL,
    ZAZABI_OAM_HAIR_DOWN_LOW,
    ZAZABI_OAM_HAIR_DOWN_MID,
    ZAZABI_OAM_HAIR_DOWN_HIGH,
    ZAZABI_OAM_HAIR_EATING_SAMUS,
    ZAZABI_OAM_EYE_SHELL_JUMPING_RIGHT,
    ZAZABI_OAM_EYE_SHELL_JUMPING_SMALL_RIGHT,
    ZAZABI_OAM_EYE_SHELL_JUMPING_LEFT,
    ZAZABI_OAM_EYE_SHELL_JUMPING_SMALL_LEFT,
    ZAZABI_OAM_UPPER_SHELL_JUMPING_RIGHT,
    ZAZABI_OAM_UPPER_SHELL_JUMPING_LEFT,
    ZAZABI_OAM_HAIR_JUMPING_RIGHT_1,
    ZAZABI_OAM_HAIR_JUMPING_RIGHT_2,
    ZAZABI_OAM_HAIR_JUMPING_RIGHT_3,
    ZAZABI_OAM_HAIR_LANDING_LEFT_1,
    ZAZABI_OAM_HAIR_LANDING_LEFT_2,
    ZAZABI_OAM_HAIR_JUMPING_LEFT_1,
    ZAZABI_OAM_HAIR_JUMPING_LEFT_2,
    ZAZABI_OAM_HAIR_JUMPING_LEFT_3,
    ZAZABI_OAM_HAIR_LANDING_RIGHT_1,
    ZAZABI_OAM_HAIR_LANDING_RIGHT_2,
    ZAZABI_OAM_PUPIL_OPEN,
    ZAZABI_OAM_MOUTH_BACK_HIDDEN,
    ZAZABI_OAM_EYE_JUMPING_RIGHT,
    ZAZABI_OAM_EYE_LANDING_RIGHT,
    ZAZABI_OAM_EYE_JUMPING_LEFT,
    ZAZABI_OAM_EYE_LANDING_LEFT,

    ZAZABI_OAM_END
};

extern const struct MultiSpriteData sZazabiMultiOam_Idle4[5];
extern const struct MultiSpriteData sZazabiMultiOam_Crawling4[9];
extern const struct MultiSpriteData sZazabiMultiOam_JumpWarning4[3];
extern const struct MultiSpriteData sZazabiMultiOam_JumpingSmall4[4];
extern const struct MultiSpriteData sZazabiMultiOam_JumpingBigRight4[4];
extern const struct MultiSpriteData sZazabiMultiOam_JumpingBigLeft4[4];
extern const struct MultiSpriteData sZazabiMultiOam_FallingSlow4[7];
extern const struct MultiSpriteData sZazabiMultiOam_FallingSlowMouthOpened4[7];
extern const struct MultiSpriteData sZazabiMultiOam_FallingLeft4[9];
extern const struct MultiSpriteData sZazabiMultiOam_FallingMouthOpenedLeft4[9];
extern const struct MultiSpriteData sZazabiMultiOam_FallingRight4[9];
extern const struct MultiSpriteData sZazabiMultiOam_FallingMouthOpenedRight4[9];
extern const struct MultiSpriteData sZazabiMultiOam_LandingMouthOpen4[7];
extern const struct MultiSpriteData sZazabiMultiOam_Landing4[3];
extern const struct MultiSpriteData sZazabiMultiOam_SpittingSamus4[7];
extern const struct MultiSpriteData sZazabiMultiOam_LandingAfterSpitting4[5];
extern const struct MultiSpriteData sZazabiMultiOam_EatingSamus1[5];
extern const struct MultiSpriteData sZazabiMultiOam_EatingSamus2[5];
extern const struct MultiSpriteData sZazabiMultiOam_EatingSamus3_4[5];
extern const struct MultiSpriteData sZazabiMultiOam_EatingSamus4_4[5];
extern const struct MultiSpriteData sZazabiMultiOam_EatingSamus5_4[5];

extern const struct MultiSpriteData sZazabiMultiOam_Idle3[5];
extern const struct MultiSpriteData sZazabiMultiOam_Crawling3[9];
extern const struct MultiSpriteData sZazabiMultiOam_JumpWarning3[3];
extern const struct MultiSpriteData sZazabiMultiOam_JumpingSmall3[4];
extern const struct MultiSpriteData sZazabiMultiOam_JumpingBigRight3[4];
extern const struct MultiSpriteData sZazabiMultiOam_JumpingBigLeft3[4];
extern const struct MultiSpriteData sZazabiMultiOam_FallingSlow3[7];
extern const struct MultiSpriteData sZazabiMultiOam_FallingSlowMouthOpened3[7];
extern const struct MultiSpriteData sZazabiMultiOam_FallingLeft3[9];
extern const struct MultiSpriteData sZazabiMultiOam_FallingMouthOpenedLeft3[9];
extern const struct MultiSpriteData sZazabiMultiOam_FallingRight3[9];
extern const struct MultiSpriteData sZazabiMultiOam_FallingMouthOpenedRight3[9];
extern const struct MultiSpriteData sZazabiMultiOam_LandingMouthOpen3[7];
extern const struct MultiSpriteData sZazabiMultiOam_Landing3[3];
extern const struct MultiSpriteData sZazabiMultiOam_SpittingSamus3[7];
extern const struct MultiSpriteData sZazabiMultiOam_LandingAfterSpitting3[5];
extern const struct MultiSpriteData sZazabiMultiOam_EatingSamus3_3[5];
extern const struct MultiSpriteData sZazabiMultiOam_EatingSamus4_3[5];
extern const struct MultiSpriteData sZazabiMultiOam_EatingSamus5_3[5];

extern const struct MultiSpriteData sZazabiMultiOam_Idle2[5];
extern const struct MultiSpriteData sZazabiMultiOam_Crawling2[9];
extern const struct MultiSpriteData sZazabiMultiOam_JumpWarning2[3];
extern const struct MultiSpriteData sZazabiMultiOam_JumpingSmall2[4];
extern const struct MultiSpriteData sZazabiMultiOam_JumpingBigRight2[4];
extern const struct MultiSpriteData sZazabiMultiOam_JumpingBigLeft2[4];
extern const struct MultiSpriteData sZazabiMultiOam_FallingSlow2[7];
extern const struct MultiSpriteData sZazabiMultiOam_FallingSlowMouthOpened2[7];
extern const struct MultiSpriteData sZazabiMultiOam_FallingLeft2[9];
extern const struct MultiSpriteData sZazabiMultiOam_FallingMouthOpenedLeft2[9];
extern const struct MultiSpriteData sZazabiMultiOam_FallingRight2[9];
extern const struct MultiSpriteData sZazabiMultiOam_FallingMouthOpenedRight2[9];
extern const struct MultiSpriteData sZazabiMultiOam_LandingMouthOpen2[7];
extern const struct MultiSpriteData sZazabiMultiOam_Landing2[3];
extern const struct MultiSpriteData sZazabiMultiOam_SpittingSamus2[7];
extern const struct MultiSpriteData sZazabiMultiOam_LandingAfterSpitting2[5];
extern const struct MultiSpriteData sZazabiMultiOam_EatingSamus5_2[5];

extern const struct MultiSpriteData sZazabiMultiOam_Idle1[5];
extern const struct MultiSpriteData sZazabiMultiOam_Crawling1[9];
extern const struct MultiSpriteData sZazabiMultiOam_JumpWarning1[3];
extern const struct MultiSpriteData sZazabiMultiOam_JumpingSmall1[4];
extern const struct MultiSpriteData sZazabiMultiOam_JumpingBigRight1[4];
extern const struct MultiSpriteData sZazabiMultiOam_JumpingBigLeft1[4];
extern const struct MultiSpriteData sZazabiMultiOam_FallingSlowMouthOpened1[7];
extern const struct MultiSpriteData sZazabiMultiOam_FallingMouthOpenedLeft1[9];
extern const struct MultiSpriteData sZazabiMultiOam_FallingMouthOpenedRight1[9];
extern const struct MultiSpriteData sZazabiMultiOam_LandingMouthOpen1[7];
extern const struct MultiSpriteData sZazabiMultiOam_Landing1[3];

extern const s16 sZazabiJumpingSpeedMouthOpened[40];
extern const s16 sZazabiFallingSpeedMouthOpened[8];
extern const s16 sZazabiJumpingSpeed4[40];
extern const s16 sZazabiJumpingSpeed2[40];
extern const s16 sZazabiJumpingSpeed3[40];
extern const s16 sZazabiFallingSpeed[8];

extern const u32 sZazabiGfx[4096];
extern const u16 sZazabiPal[8 * 16];

extern const struct FrameData sZAZABI_OAM_LOWER_SHELL_IDLE[2];
extern const struct FrameData sZazabiPartOam_LowerShellEatingSamus[5];
extern const struct FrameData sZazabiPartOam_LowerShellSwallowingSamus[4];
extern const struct FrameData sZazabi_372820[3];
extern const struct FrameData sZazabiPartOam_MiddleShellIdle[2];
extern const struct FrameData sZazabiPartOam_MiddleShellEatingSamus3[5];
extern const struct FrameData sZazabiPartOam_MiddleShellSwallowingSamus[4];
extern const struct FrameData sZazabiPartOam_MiddleShellEatingSamus2[3];
extern const struct FrameData sZazabiPartOam_UpperShellIdle[2];
extern const struct FrameData sZazabiPartOam_UpperShellEatingSamus5[5];
extern const struct FrameData sZazabiPartOam_UpperShellSwallowingSamus[4];
extern const struct FrameData sZazabiPartOam_UpperShellEatingSamus4[3];
extern const struct FrameData sZazabiPartOam_EyeShellIdle[2];
extern const struct FrameData sZazabiPartOam_EyeShellSwallowingSamusLow[5];
extern const struct FrameData sZazabi_372950[4];
extern const struct FrameData sZazabi_372970[3];
extern const struct FrameData sZazabiPartOam_MouthFrontIdle[2];
extern const struct FrameData sZazabiPartOam_MouthFrontLanding[2];
extern const struct FrameData sZazabiPartOam_MouthFrontCrawlingLow[2];
extern const struct FrameData sZazabiPartOam_MouthFrontCrawlingHigh[2];
extern const struct FrameData sZazabiPartOam_MouthFrontCrawlingHalted[2];
extern const struct FrameData sZazabiPartOam_MouthFrontOpening_1[2];
extern const struct FrameData sZazabiPartOam_MouthBackOpening_1[2];
extern const struct FrameData sZazabiPartOam_MouthFrontOpening_2[2];
extern const struct FrameData sZazabiPartOam_MouthBackOpening_2[2];
extern const struct FrameData sZazabiPartOam_MouthFrontOpened[2];
extern const struct FrameData sZazabiPartOam_EyeIdle[2];
extern const struct FrameData sZazabiPartOam_EyeEatingSamus[5];
extern const struct FrameData sZazabiPartOam_PupilBlinking[8];
extern const struct FrameData sZazabiPartOam_HairMoving[13];
extern const struct FrameData sZazabiPartOam_HairStill[2];
extern const struct FrameData sZazabiPartOam_HairDownLow[2];
extern const struct FrameData sZazabiPartOam_HairDownMid[2];
extern const struct FrameData sZazabiPartOam_HairDownHigh[2];
extern const struct FrameData sZazabiPartOam_HairEatingSamus[5];
extern const struct FrameData sZazabiPartOam_EyeShellJumpingRight[2];
extern const struct FrameData sZazabiPartOam_EyeShellJumpingSmallRight[2];
extern const struct FrameData sZazabiPartOam_EyeShellJumpingLeft[2];
extern const struct FrameData sZazabiPartOam_EyeShellJumpingSmallLeft[2];
extern const struct FrameData sZazabiPartOam_UpperShellJumpingRight[2];
extern const struct FrameData sZazabiPartOam_UpperShellJumpingLeft[2];
extern const struct FrameData sZazabiPartOam_HairJumpingRight_1[2];
extern const struct FrameData sZazabiPartOam_HairJumpingRight_2[2];
extern const struct FrameData sZazabiPartOam_HairJumpingRight_3[2];
extern const struct FrameData sZazabiPartOam_HairLandingLeft_1[2];
extern const struct FrameData sZazabiPartOam_HairLandingLeft_2[2];
extern const struct FrameData sZazabiPartOam_HairJumpingLeft_1[2];
extern const struct FrameData sZazabiPartOam_HairJumpingLeft_2[2];
extern const struct FrameData sZazabiPartOam_HairJumpingLeft_3[2];
extern const struct FrameData sZazabiPartOam_HairLandingRight_1[2];
extern const struct FrameData sZazabiPartOam_HairLandingRight_2[2];
extern const struct FrameData sZazabiPartOam_PupilOpen[2];
extern const struct FrameData sZazabiPartOam_MouthBackHidden[2];
extern const struct FrameData sZazabiPartOam_EyeJumpingRight[2];
extern const struct FrameData sZazabiPartOam_EyeLandingRight[2];
extern const struct FrameData sZazabiPartOam_EyeJumpingLeft[2];
extern const struct FrameData sZazabiPartOam_EyeLandingLeft[2];

#endif /* ZAZABI_DATA_H */
