#ifndef OMEGA_METROID_DATA_H
#define OMEGA_METROID_DATA_H

#include "types.h"
#include "oam.h"
#include "gba/memory.h"
#include "structs/sprite.h"

enum OmegaMetroidPart {
    OMEGA_METROID_PART_HEAD,
    OMEGA_METROID_PART_LEFT_ARM,
    OMEGA_METROID_PART_LEFT_LEG,
    OMEGA_METROID_PART_TORSO,
    OMEGA_METROID_PART_RIGHT_ARM,
    OMEGA_METROID_PART_RIGHT_CLAW,
    OMEGA_METROID_PART_TAIL,
    OMEGA_METROID_PART_RIGHT_LEG,

    OMEGA_METROID_PART_COUNT
};

enum OmegaMetroidOam {
    OMEGA_METROID_OAM_RIGHT_LEG_IDLE,
    OMEGA_METROID_OAM_LEFT_LEG_IDLE,
    OMEGA_METROID_OAM_RIGHT_LEG_JUMP_WARNING,
    OMEGA_METROID_OAM_LEFT_LEG_JUMP_WARNING,
    OMEGA_METROID_OAM_RIGHT_LEG_JUMPING,
    OMEGA_METROID_OAM_LEFT_LEG_JUMPING,
    OMEGA_METROID_OAM_RIGHT_LEG_LANDING,
    OMEGA_METROID_OAM_LEFT_LEG_LANDING,
    OMEGA_METROID_OAM_RIGHT_LEG_DONE_SWIPING,
    OMEGA_METROID_OAM_LEFT_LEG_DONE_SWIPING,
    OMEGA_METROID_OAM_RIGHT_LEG_SWIPING_MIDAIR,
    OMEGA_METROID_OAM_LEFT_LEG_SWIPING_MIDAIR,
    OMEGA_METROID_OAM_RIGHT_LEG_SCREAMING_HEAD_SHAKE,
    OMEGA_METROID_OAM_LEFT_LEG_SCREAMING_HEAD_SHAKE,
    OMEGA_METROID_OAM_HEAD_STILL,
    OMEGA_METROID_OAM_HEAD_MOUTH_MOVING_FAST,
    OMEGA_METROID_OAM_HEAD_MOUTH_MOVING_SLOW,
    OMEGA_METROID_OAM_HEAD_DROOLING,
    OMEGA_METROID_OAM_DROOL,
    OMEGA_METROID_OAM_TAIL_IDLE,
    OMEGA_METROID_OAM_TAIL_WIGGLING,
    OMEGA_METROID_OAM_RIGHT_LEG_WALKING_SLOW,
    OMEGA_METROID_OAM_LEFT_LEG_WALKING_SLOW,
    OMEGA_METROID_OAM_RIGHT_LEG_WALK_AGAIN_SLOW,
    OMEGA_METROID_OAM_LEFT_LEG_WALK_AGAIN_SLOW,
    OMEGA_METROID_OAM_RIGHT_LEG_DONE_WALKING_SLOW,
    OMEGA_METROID_OAM_LEFT_LEG_DONE_WALKING_SLOW,
    OMEGA_METROID_OAM_RIGHT_LEG_WALKING,
    OMEGA_METROID_OAM_LEFT_LEG_WALKING,
    OMEGA_METROID_OAM_RIGHT_LEG_WALK_AGAIN,
    OMEGA_METROID_OAM_LEFT_LEG_WALK_AGAIN,
    OMEGA_METROID_OAM_RIGHT_LEG_DONE_WALKING,
    OMEGA_METROID_OAM_LEFT_LEG_DONE_WALKING,
    OMEGA_METROID_OAM_TORSO,
    OMEGA_METROID_OAM_LEFT_ARM,
    OMEGA_METROID_OAM_RIGHT_CLAW,
    OMEGA_METROID_OAM_RIGHT_ARM,
    OMEGA_METROID_OAM_HEAD_TURNING_1,
    OMEGA_METROID_OAM_HEAD_TURNING_2,
    OMEGA_METROID_OAM_HEAD_TURNING_3,
    OMEGA_METROID_OAM_HEAD_TURNING_4,
    OMEGA_METROID_OAM_RIGHT_LEG_ABOUT_TO_SCREAM,
    OMEGA_METROID_OAM_LEFT_LEG_ABOUT_TO_SCREAM,
    OMEGA_METROID_OAM_RIGHT_LEG_SCREAMING,
    OMEGA_METROID_OAM_LEFT_LEG_SCREAMING,
    OMEGA_METROID_OAM_HEAD_MOUTH_OPEN,
    OMEGA_METROID_OAM_HEAD_MOUTH_MOVING_VERY_FAST,
    OMEGA_METROID_OAM_RIGHT_LEG_WALKING_BACKWARD,
    OMEGA_METROID_OAM_LEFT_LEG_WALKING_BACKWARD,
    OMEGA_METROID_OAM_RIGHT_LEG_DONE_WALKING_BACKWARD,
    OMEGA_METROID_OAM_LEFT_LEG_DONE_WALKING_BACKWARD,
    OMEGA_METROID_OAM_RIGHT_LEG_SWIPING,
    OMEGA_METROID_OAM_LEFT_LEG_SWIPING,

    OMEGA_METROID_OAM_COUNT
};

extern const s16 sOmegaMetroidFirstJumpYSpeeds[36];
extern const s16 sOmegaMetroidJumpingYSpeeds[24];
extern const s16 sOmegaMetroidFallingYSpeeds[12];
extern const s16 sOmegaMetroidVerticalJumpYSpeeds[16];
extern const s16 sOmegaMetroidSpeeds_3959b0[28];
extern const s16 sOmegaMetroidSpeeds_3959e8[16];

extern const struct MultiSpriteData sOmegaMetroidMultiOam_Idle_MouthMovingFast[5];
extern const struct MultiSpriteData sOmegaMetroidMultiOam_Idle_MouthStill[5];
extern const struct MultiSpriteData sOmegaMetroidMultiOam_Screaming_HeadShake[7];
extern const struct MultiSpriteData sOmegaMetroidMultiOam_Idle_Drooling[5];
extern const struct MultiSpriteData sOmegaMetroidMultiOam_JumpWarning[3];
extern const struct MultiSpriteData sOmegaMetroidMultiOam_Jumping[3];
extern const struct MultiSpriteData sOmegaMetroidMultiOam_Landing[4];
extern const struct MultiSpriteData sOmegaMetroidMultiOam_DoneSwiping[6];
extern const struct MultiSpriteData sOmegaMetroidMultiOam_Swiping_Midair[5]; // Unused
extern const struct MultiSpriteData sOmegaMetroidMultiOam_Idle_MouthMovingSlow[5];
extern const struct MultiSpriteData sOmegaMetroidMultiOam_Walking_Slow[11];
extern const struct MultiSpriteData sOmegaMetroidMultiOam_WalkAgain_Slow[3];
extern const struct MultiSpriteData sOmegaMetroidMultiOam_DoneWalking_Slow[2];
extern const struct MultiSpriteData sOmegaMetroidMultiOam_Walking[11];
extern const struct MultiSpriteData sOmegaMetroidMultiOam_WalkAgain[3];
extern const struct MultiSpriteData sOmegaMetroidMultiOam_DoneWalking[2];
extern const struct MultiSpriteData sOmegaMetroidMultiOam_AboutToScream[3];
extern const struct MultiSpriteData sOmegaMetroidMultiOam_Screaming[5];
extern const struct MultiSpriteData sOmegaMetroidMultiOam_DoneScreaming[3];
extern const struct MultiSpriteData sOmegaMetroidMultiOam_WalkingBackward[11];
extern const struct MultiSpriteData sOmegaMetroidMultiOam_DoneWalkingBackward[2];
extern const struct MultiSpriteData sOmegaMetroidMultiOam_Swiping[6];

extern const u32 sOmegaMetroidGfx[512 * 5];
extern const u16 sOmegaMetroidPal[PAL_ROW * 5];

extern const struct FrameData sOmegaMetroidPartOam_RightLeg_Idle[5];
extern const struct FrameData sOmegaMetroidPartOam_LeftLeg_Idle[5];
extern const struct FrameData sOmegaMetroidPartOam_RightLeg_JumpWarning[3];
extern const struct FrameData sOmegaMetroidPartOam_LeftLeg_JumpWarning[3];
extern const struct FrameData sOmegaMetroidPartOam_RightLeg_Jumping[3];
extern const struct FrameData sOmegaMetroidPartOam_LeftLeg_Jumping[3];
extern const struct FrameData sOmegaMetroidPartOam_RightLeg_Landing[4];
extern const struct FrameData sOmegaMetroidPartOam_LeftLeg_Landing[4];
extern const struct FrameData sOmegaMetroidPartOam_RightLeg_DoneSwiping[6];
extern const struct FrameData sOmegaMetroidPartOam_LeftLeg_DoneSwiping[6];
extern const struct FrameData sOmegaMetroidPartOam_RightLeg_Swiping_Midair[5]; // Unused
extern const struct FrameData sOmegaMetroidPartOam_LeftLeg_Swiping_Midair[5]; // Unused
extern const struct FrameData sOmegaMetroidPartOam_RightLeg_Screaming_HeadShake[7];
extern const struct FrameData sOmegaMetroidPartOam_LeftLeg_Screaming_HeadShake[7];
extern const struct FrameData sOmegaMetroidPartOam_Head_Still[2];
extern const struct FrameData sOmegaMetroidPartOam_Head_MouthMoving_Fast[5];
extern const struct FrameData sOmegaMetroidPartOam_Head_MouthMoving_Slow[10];
extern const struct FrameData sOmegaMetroidPartOam_Head_Drooling[15];
extern const struct FrameData sOmegaMetroidPartOam_Drool[2];
extern const struct FrameData sOmegaMetroidPartOam_Tail_Idle[15];
extern const struct FrameData sOmegaMetroidPartOam_Tail_Wiggling[8];
extern const struct FrameData sOmegaMetroidPartOam_RightLeg_Walking_Slow[11];
extern const struct FrameData sOmegaMetroidPartOam_LeftLeg_Walking_Slow[11];
extern const struct FrameData sOmegaMetroidPartOam_RightLeg_WalkAgain_Slow[3];
extern const struct FrameData sOmegaMetroidPartOam_LeftLeg_WalkAgain_Slow[3];
extern const struct FrameData sOmegaMetroidPartOam_RightLeg_DoneWalking_Slow[2];
extern const struct FrameData sOmegaMetroidPartOam_LeftLeg_DoneWalking_Slow[2];
extern const struct FrameData sOmegaMetroidPartOam_RightLeg_Walking[11];
extern const struct FrameData sOmegaMetroidPartOam_LeftLeg_Walking[11];
extern const struct FrameData sOmegaMetroidPartOam_RightLeg_WalkAgain[3];
extern const struct FrameData sOmegaMetroidPartOam_LeftLeg_WalkAgain[3];
extern const struct FrameData sOmegaMetroidPartOam_RightLeg_DoneWalking[2];
extern const struct FrameData sOmegaMetroidPartOam_LeftLeg_DoneWalking[2];
extern const struct FrameData sOmegaMetroidPartOam_Torso[2];
extern const struct FrameData sOmegaMetroidPartOam_LeftArm[2];
extern const struct FrameData sOmegaMetroidPartOam_RightClaw[2];
extern const struct FrameData sOmegaMetroidPartOam_RightArm[2];
extern const struct FrameData sOmegaMetroidPartOam_Head_Turning_1[2];
extern const struct FrameData sOmegaMetroidPartOam_Head_Turning_2[2];
extern const struct FrameData sOmegaMetroidPartOam_Head_Turning_3[2];
extern const struct FrameData sOmegaMetroidPartOam_Head_Turning_4[2];
extern const struct FrameData sOmegaMetroidPartOam_RightLeg_AboutToScream[2];
extern const struct FrameData sOmegaMetroidPartOam_LeftLeg_AboutToScream[2];
extern const struct FrameData sOmegaMetroidPartOam_RightLeg_Screaming[5];
extern const struct FrameData sOmegaMetroidPartOam_LeftLeg_Screaming[5];
extern const struct FrameData sOmegaMetroidPartOam_Head_MouthOpen[2];
extern const struct FrameData sOmegaMetroidPartOam_Head_MouthMoving_VeryFast[5];
extern const struct FrameData sOmegaMetroidPartOam_RightLeg_WalkingBackward[11];
extern const struct FrameData sOmegaMetroidPartOam_LeftLeg_WalkingBackward[11];
extern const struct FrameData sOmegaMetroidPartOam_RightLeg_DoneWalkingBackward[2];
extern const struct FrameData sOmegaMetroidPartOam_LeftLeg_DoneWalkingBackward[2];
extern const struct FrameData sOmegaMetroidPartOam_RightLeg_Swiping[6];
extern const struct FrameData sOmegaMetroidPartOam_LeftLeg_Swiping[6];

#endif /* OMEGA_METROID_DATA_H */
