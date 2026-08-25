#ifndef SA_X_MONSTER_DATA_H
#define SA_X_MONSTER_DATA_H

#include "types.h"
#include "oam.h"
#include "gba/memory.h"
#include "structs/sprite.h"

enum SaXMonsterPart {
    SA_X_MONSTER_PART_CHEEK_SPIKE,
    SA_X_MONSTER_PART_SHOULDER_MOUTH,
    SA_X_MONSTER_PART_FRONT_ARM,
    SA_X_MONSTER_PART_HEAD,
    SA_X_MONSTER_PART_TONGUE,
    SA_X_MONSTER_PART_BACK_LEG,
    SA_X_MONSTER_PART_JAW,
    SA_X_MONSTER_PART_FRONT_LEG,
    SA_X_MONSTER_PART_BACK_TENTACLES,
    SA_X_MONSTER_PART_LOWER_BACK_TENTACLE,
    SA_X_MONSTER_PART_BACK_ARM,

    SA_X_MONSTER_PART_COUNT
};

enum SaXMonsterOam {
    SA_X_MONSTER_OAM_TONGUE_WHIPPING_LEFT,
    SA_X_MONSTER_OAM_TONGUE_SWAYING_LEFT,
    SA_X_MONSTER_OAM_TONGUE_SPINNING_LEFT,
    SA_X_MONSTER_OAM_TONGUE_CURLING_LEFT,
    SA_X_MONSTER_OAM_TONGUE_POPPING_OUT_LEFT,
    SA_X_MONSTER_OAM_CHEEK_SPIKE_LEFT,
    SA_X_MONSTER_OAM_HEAD_IDLE_LEFT,
    SA_X_MONSTER_OAM_HEAD_RETRACTING_LEFT,
    SA_X_MONSTER_OAM_SHOULDER_MOUTH_IDLE_LEFT,
    SA_X_MONSTER_OAM_SHOULDER_MOUTH_OPENING_LEFT,
    SA_X_MONSTER_OAM_SHOULDER_MOUTH_CLOSING_LEFT,
    SA_X_MONSTER_OAM_JAW_IDLE_LEFT,
    SA_X_MONSTER_OAM_JAW_EXTENDED_LEFT,
    SA_X_MONSTER_OAM_RIGHT_ARM_JUMPING_LEFT,
    SA_X_MONSTER_OAM_RIGHT_ARM_IDLE_LEFT,
    SA_X_MONSTER_OAM_LEFT_ARM_IDLE_LEFT,
    SA_X_MONSTER_OAM_LEFT_ARM_IDLE_RIGHT,
    SA_X_MONSTER_OAM_BACK_TENTACLES_IDLE_LEFT,
    SA_X_MONSTER_OAM_LOWER_BACK_TENTACLE_IDLE_LEFT,
    SA_X_MONSTER_OAM_FRONT_LEG_IDLE_LEFT,
    SA_X_MONSTER_OAM_FRONT_LEG_CROUCHING_LEFT,
    SA_X_MONSTER_OAM_FRONT_LEG_JUMPING_LEFT,
    SA_X_MONSTER_OAM_FRONT_LEG_LANDING_LEFT,
    SA_X_MONSTER_OAM_BACK_LEG_IDLE_LEFT,
    SA_X_MONSTER_OAM_BACK_LEG_CROUCHING_LEFT,
    SA_X_MONSTER_OAM_BACK_LEG_JUMPING_LEFT,
    SA_X_MONSTER_OAM_BACK_LEG_LANDING_LEFT,
    SA_X_MONSTER_OAM_38FE58,
    SA_X_MONSTER_OAM_TONGUE_WHIPPING_RIGHT,
    SA_X_MONSTER_OAM_TONGUE_SWAYING_RIGHT,
    SA_X_MONSTER_OAM_TONGUE_SPINNING_RIGHT,
    SA_X_MONSTER_OAM_TONGUE_POPPING_OUT_RIGHT,
    SA_X_MONSTER_OAM_CHEEK_SPIKE_RIGHT,
    SA_X_MONSTER_OAM_HEAD_IDLE_RIGHT,
    SA_X_MONSTER_OAM_HEAD_RETRACTING_RIGHT,
    SA_X_MONSTER_OAM_SHOULDER_MOUTH_IDLE_RIGHT,
    SA_X_MONSTER_OAM_SHOULDER_MOUTH_OPENING_RIGHT,
    SA_X_MONSTER_OAM_SHOULDER_MOUTH_CLOSING_RIGHT,
    SA_X_MONSTER_OAM_JAW_IDLE_RIGHT,
    SA_X_MONSTER_OAM_JAW_EXTENDED_RIGHT,
    SA_X_MONSTER_OAM_RIGHT_ARM_IDLE_RIGHT,
    SA_X_MONSTER_OAM_BACK_TENTACLES_IDLE_RIGHT,
    SA_X_MONSTER_OAM_LOWER_BACK_TENTACLE_IDLE_RIGHT,
    SA_X_MONSTER_OAM_FRONT_LEG_IDLE_RIGHT,
    SA_X_MONSTER_OAM_FRONT_LEG_CROUCHING_RIGHT,
    SA_X_MONSTER_OAM_FRONT_LEG_JUMPING_RIGHT,
    SA_X_MONSTER_OAM_FRONT_LEG_LANDING_RIGHT,
    SA_X_MONSTER_OAM_BACK_LEG_IDLE_RIGHT,
    SA_X_MONSTER_OAM_BACK_LEG_CROUCHING_RIGHT,
    SA_X_MONSTER_OAM_BACK_LEG_JUMPING_RIGHT,
    SA_X_MONSTER_OAM_BACK_LEG_LANDING_RIGHT,
    SA_X_MONSTER_OAM_TONGUE_CURLING_RIGHT,
    SA_X_MONSTER_OAM_BODY_TURNING_LEFT,
    SA_X_MONSTER_OAM_LEFT_ARM_LANDING_RIGHT,
    SA_X_MONSTER_OAM_390318,
    SA_X_MONSTER_OAM_BODY_TURNING_RIGHT,
    SA_X_MONSTER_OAM_LEFT_ARM_JUMPING_RIGHT,
    SA_X_MONSTER_OAM_BODY_GETTING_HIT_LEFT,
    SA_X_MONSTER_OAM_BODY_GETTING_HIT_RIGHT,
    SA_X_MONSTER_OAM_BODY_DYING_LEFT,
    SA_X_MONSTER_OAM_BODY_DYING_RIGHT,
    SA_X_MONSTER_OAM_BODY_GETTING_HIT_MIDAIR_LEFT,
    SA_X_MONSTER_OAM_BODY_GETTING_HIT_MIDAIR_RIGHT,
    SA_X_MONSTER_OAM_EMPTY,
    SA_X_MONSTER_OAM_BODY_STILL_LEFT,
    SA_X_MONSTER_OAM_BODY_STILL_RIGHT,

    SA_X_MONSTER_OAM_COUNT
};

extern const s16 sSaXMonsterJumpingYSpeeds[40];
extern const s16 sSaXMonsterFallingYSpeeds[12];

extern const struct MultiSpriteData sSaXMonsterMultiOam_Idle_Left[5];
extern const struct MultiSpriteData sSaXMonsterMultiOam_JumpWarning_Left[5];
extern const struct MultiSpriteData sSaXMonsterMultiOam_Jumping_Left[5];
extern const struct MultiSpriteData sSaXMonsterMultiOam_Landing_Left[4];
extern const struct MultiSpriteData sSaXMonsterMultiOam_Idle_Right[5];
extern const struct MultiSpriteData sSaXMonsterMultiOam_JumpWarning_Right[5];
extern const struct MultiSpriteData sSaXMonsterMultiOam_Jumping_Right[5];
extern const struct MultiSpriteData sSaXMonsterMultiOam_Landing_Right[4];
extern const struct MultiSpriteData sSaXMonsterMultiOam_TurningAround_Left[2];
extern const struct MultiSpriteData sSaXMonsterMultiOam_TurningAround_Right[2];
extern const struct MultiSpriteData sSaXMonsterMultiOam_ScreamingGrounded_Left[2];
extern const struct MultiSpriteData sSaXMonsterMultiOam_ScreamingGrounded_Right[2];
extern const struct MultiSpriteData sSaXMonsterMultiOam_Panting_Left[2];
extern const struct MultiSpriteData sSaXMonsterMultiOam_Panting_Right[2];
extern const struct MultiSpriteData sSaXMonsterMultiOam_ScreamingAirborne_Left[2];
extern const struct MultiSpriteData sSaXMonsterMultiOam_ScreamingAirborne_Right[2];
extern const struct MultiSpriteData sSaXMonsterMultiOam_Still_Left[2];
extern const struct MultiSpriteData sSaXMonsterMultiOam_Still_Right[2];

extern const u32 sSaXMonsterGfx[512 * 8];
extern const u16 sSaXMonsterPal[PAL_ROW * 8];

extern const struct FrameData sSaXMonsterPartOam_Tongue_Whipping_Left[13];
extern const struct FrameData sSaXMonsterPartOam_Tongue_Swaying_Left[25];
extern const struct FrameData sSaXMonsterPartOam_Tongue_Spinning_Left[5];
extern const struct FrameData sSaXMonsterPartOam_Tongue_Curling_Left[5];
extern const struct FrameData sSaXMonsterPartOam_Tongue_PoppingOut_Left[5];
extern const struct FrameData sSaXMonsterPartOam_CheekSpike_Left[2];
extern const struct FrameData sSaXMonsterPartOam_Head_Idle_Left[5];
extern const struct FrameData sSaXMonsterPartOam_Head_Retracting_Left[5];
extern const struct FrameData sSaXMonsterPartOam_ShoulderMouth_Idle_Left[5];
extern const struct FrameData sSaXMonsterPartOam_ShoulderMouth_Opening_Left[8];
extern const struct FrameData sSaXMonsterPartOam_ShoulderMouth_Closing_Left[7];
extern const struct FrameData sSaXMonsterPartOam_Jaw_Idle_Left[2];
extern const struct FrameData sSaXMonsterPartOam_Jaw_Extended_Left[2];
extern const struct FrameData sSaXMonsterPartOam_RightArm_Jumping_Left[2];
extern const struct FrameData sSaXMonsterPartOam_RightArm_Idle_Left[2];
extern const struct FrameData sSaXMonsterPartOam_LeftArm_Idle_Left[7];
extern const struct FrameData sSaXMonsterPartOam_LeftArm_Idle_Right[2];
extern const struct FrameData sSaXMonsterPartOam_BackTentacles_Idle_Left[5];
extern const struct FrameData sSaXMonsterPartOam_LowerBackTentacle_Idle_Left[6];
extern const struct FrameData sSaXMonsterPartOam_FrontLeg_Idle_Left[5];
extern const struct FrameData sSaXMonsterPartOam_FrontLeg_Crouching_Left[5];
extern const struct FrameData sSaXMonsterPartOam_FrontLeg_Jumping_Left[5];
extern const struct FrameData sSaXMonsterPartOam_FrontLeg_Landing_Left[3];
extern const struct FrameData sSaXMonsterPartOam_BackLeg_Idle_Left[5];
extern const struct FrameData sSaXMonsterPartOam_BackLeg_Crouching_Left[5];
extern const struct FrameData sSaXMonsterPartOam_BackLeg_Jumping_Left[5];
extern const struct FrameData sSaXMonsterPartOam_BackLeg_Landing_Left[3];
extern const struct FrameData sSaXMonsterPartOam_38fe58[2];
extern const struct FrameData sSaXMonsterPartOam_Tongue_Whipping_Right[13];
extern const struct FrameData sSaXMonsterPartOam_Tongue_Swaying_Right[25];
extern const struct FrameData sSaXMonsterPartOam_Tongue_Spinning_Right[5];
extern const struct FrameData sSaXMonsterPartOam_Tongue_PoppingOut_Right[5];
extern const struct FrameData sSaXMonsterPartOam_CheekSpike_Right[2];
extern const struct FrameData sSaXMonsterPartOam_Head_Idle_Right[5];
extern const struct FrameData sSaXMonsterPartOam_Head_Retracting_Right[5];
extern const struct FrameData sSaXMonsterPartOam_ShoulderMouth_Idle_Right[5];
extern const struct FrameData sSaXMonsterPartOam_ShoulderMouth_Opening_Right[8];
extern const struct FrameData sSaXMonsterPartOam_ShoulderMouth_Closing_Right[7];
extern const struct FrameData sSaXMonsterPartOam_Jaw_Idle_Right[2];
extern const struct FrameData sSaXMonsterPartOam_Jaw_Extended_Right[2];
extern const struct FrameData sSaXMonsterPartOam_RightArm_Idle_Right[7];
extern const struct FrameData sSaXMonsterPartOam_BackTentacles_Idle_Right[5];
extern const struct FrameData sSaXMonsterPartOam_LowerBackTentacle_Idle_Right[6];
extern const struct FrameData sSaXMonsterPartOam_FrontLeg_Idle_Right[5];
extern const struct FrameData sSaXMonsterPartOam_FrontLeg_Crouching_Right[5];
extern const struct FrameData sSaXMonsterPartOam_FrontLeg_Jumping_Right[5];
extern const struct FrameData sSaXMonsterPartOam_FrontLeg_Landing_Right[3];
extern const struct FrameData sSaXMonsterPartOam_BackLeg_Idle_Right[5];
extern const struct FrameData sSaXMonsterPartOam_BackLeg_Crouching_Right[5];
extern const struct FrameData sSaXMonsterPartOam_BackLeg_Jumping_Right[5];
extern const struct FrameData sSaXMonsterPartOam_BackLeg_Landing_Right[3];
extern const struct FrameData sSaXMonsterPartOam_Tongue_Curling_Right[5];
extern const struct FrameData sSaXMonsterPartOam_Body_Turning_Left[5];
extern const struct FrameData sSaXMonsterPartOam_LeftArmLanding_Right[2];
extern const struct FrameData sSaXMonsterPartOam_390318[9];
extern const struct FrameData sSaXMonsterPartOam_Body_Turning_Right[5];
extern const struct FrameData sSaXMonsterPartOam_LeftArm_Jumping_Right[2];
extern const struct FrameData sSaXMonsterPartOam_Body_GettingHit_Left[7];
extern const struct FrameData sSaXMonsterPartOam_Body_GettingHit_Right[7];
extern const struct FrameData sSaXMonsterPartOam_Body_Dying_Left[10];
extern const struct FrameData sSaXMonsterPartOam_Body_Dying_Right[10];
extern const struct FrameData sSaXMonsterPartOam_Body_GettingHitMidair_Left[4];
extern const struct FrameData sSaXMonsterPartOam_Body_GettingHitMidair_Right[4];
extern const struct FrameData sSaXMonsterPartOam_Empty[2];
extern const struct FrameData sSaXMonsterPartOam_Body_Still_Left[2];
extern const struct FrameData sSaXMonsterPartOam_Body_Still_Right[2];

#endif /* SA_X_MONSTER_DATA_H */
