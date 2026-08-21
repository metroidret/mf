#include "data/samus_data.h"
#include "macros.h"

#include "samus.h"

#include "data/particle_data.h"

const s16 sSamusDrawDistanceOffsets[8][4] = {
    [0] = {
        -30,
        -126,
        30,
        0
    },
    [1] = {
        -30,
        -120,
        30,
        0
    },
    [2] = {
        -30,
        -94,
        30,
        0
    },
    [3] = {
        -30,
        -78,
        30,
        0
    },
    [4] = {
        -30,
        -62,
        30,
        0
    },
    [5] = {
        -30,
        -96,
        30,
        0
    },
    [6] = {
        -30,
        -126,
        30,
        8
    },
    [7] = {
        -30,
        -60,
        30,
        0
    },
};

const s16 sSamusCollisionOffsets[7][SAMUS_HITBOX_END] = {
    [0] = {
        [SAMUS_HITBOX_LEFT] = -30,
        [SAMUS_HITBOX_RIGHT] = 30,
        [SAMUS_HITBOX_TOP] = -124
    },
    [1] = {
        [SAMUS_HITBOX_LEFT] = -30,
        [SAMUS_HITBOX_RIGHT] = 30,
        [SAMUS_HITBOX_TOP] = -112
    },
    [2] = {
        [SAMUS_HITBOX_LEFT] = -30,
        [SAMUS_HITBOX_RIGHT] = 30,
        [SAMUS_HITBOX_TOP] = -92
    },
    [3] = {
        [SAMUS_HITBOX_LEFT] = -32,
        [SAMUS_HITBOX_RIGHT] = 32,
        [SAMUS_HITBOX_TOP] = -124
    },
    [4] = {
        [SAMUS_HITBOX_LEFT] = -30,
        [SAMUS_HITBOX_RIGHT] = 30,
        [SAMUS_HITBOX_TOP] = -94
    },
    [5] = {
        [SAMUS_HITBOX_LEFT] = -30,
        [SAMUS_HITBOX_RIGHT] = 30,
        [SAMUS_HITBOX_TOP] = -60
    },
    [6] = {
        [SAMUS_HITBOX_LEFT] = -30,
        [SAMUS_HITBOX_RIGHT] = 30,
        [SAMUS_HITBOX_TOP] = -56
    },
};

#define ABOVE_COLLISION_FAR (HALF_BLOCK_SIZE - PIXEL_SIZE / 2)
#define ABOVE_COLLISION_NEAR (EIGHTH_BLOCK_SIZE + PIXEL_SIZE / 2)

const s16 sSamusCollisionOffsetsAbove[1][4] = {
    {
        [0] = -ABOVE_COLLISION_FAR,
        [1] = -ABOVE_COLLISION_NEAR,
        [2] = ABOVE_COLLISION_NEAR,
        [3] = ABOVE_COLLISION_FAR
    }
};

const SamusUpdate_T sSamusUpdateFunctionPointer[1] = {
    SamusUpdate
};

const SamusSetPose_T sSamusSetPoseFunctionPointer[1] = {
    SamusSetPose
};

const SamusUpdateVelocityPosition_T sSamusUpdateVelocityPositionFunctionPointer[1] = {
    SamusUpdateVelocityPosition
};

const SamusCheckCollision_T sSamusCheckCollisionFunctionPointer[1] = {
    SamusCheckCollisions
};

const SamusUpdateGraphics_T sSamusUpdateGraphicsFunctionPointer[1] = {
    SamusUpdateGraphics
};

const SamusPlayLowHealthSound_T sSamusPlayLowHealthSoundFunctionPointer[1] = {
    SamusCheckPlayLowHealthSound
};

const SamusUpdateDrawDistanceAndStandingStatus_T sSamusUpdateDrawDistanceAndStandingStatusFunctionPointer[1] = {
    SamusUpdateDrawDistanceAndStandingStatus
};

const SamusUpdateArmCannonOffset_T sSamusUpdateArmCannonOffsetFunctionPointer[1] = {
    SamusUpdateArmCannonOffset
};

const struct FrameData* const sEnvEffectOamPointers[ENV_EFFECT_END - 1] = {
    [ENV_EFFECT_WALKING_ON_WET_GROUND - 1] = sSamusEnvironmentalEffectOam_3ecba4,
    [ENV_EFFECT_WALKING_ON_BUBBLY_GROUND - 1] = sSamusEnvironmentalEffectOam_3eccb4,
    [ENV_EFFECT_WALKING_ON_DUSTY_GROUND - 1] = sSamusEnvironmentalEffectOam_3ecc04,
    [ENV_EFFECT_WALKING_ON_VERY_DUSTY_GROUND - 1] = sSamusEnvironmentalEffectOam_3ecd34,
    [ENV_EFFECT_JUMPING_IN_OR_OUT_OF_WATER - 1] = sSamusEnvironmentalEffectOam_3ecd94,
    [ENV_EFFECT_WALKING_IN_OR_OUT_OF_WATER - 1] = sSamusEnvironmentalEffectOam_3eceb4,
    [ENV_EFFECT_TAKING_DAMAGE_IN_LAVA - 1] = sSamusEnvironmentalEffectOam_3ecc74,
    [ENV_EFFECT_LANDING_ON_WET_GROUND - 1] = sSamusEnvironmentalEffectOam_3ecbd4,
    [ENV_EFFECT_LANDING_ON_BUBBLY_GROUND - 1] = sSamusEnvironmentalEffectOam_3eccec,
    [ENV_EFFECT_LANDING_ON_DUSTY_GROUND - 1] = sSamusEnvironmentalEffectOam_3ecc34,
    [ENV_EFFECT_LANDING_ON_VERY_DUSTY_GROUND - 1] = sSamusEnvironmentalEffectOam_3ecd5c,
    [ENV_EFFECT_SKIDDING_ON_WET_GROUND - 1] = sSamusEnvironmentalEffectOam_3ecbd4,
    [ENV_EFFECT_SKIDDING_ON_DUSTY_GROUND - 1] = sSamusEnvironmentalEffectOam_3ecc34,
    [ENV_EFFECT_BREATHING_BUBBLES - 1] = sSamusEnvironmentalEffectOam_3ecddc,
};

const SamusFunc_T sSamusPoseFunctionsPointers[SPOSE_END] = {
    [SPOSE_STANDING] = SamusStanding,
    [SPOSE_TURNING_AROUND] = SamusTurningAround,
    [SPOSE_SHOOTING] = SamusStanding,
    [SPOSE_RUNNING] = SamusRunning,
    [SPOSE_MID_AIR] = SamusMidAir,
    [SPOSE_TURNING_AROUND_MID_AIR] = SamusTurningAroundMidAir,
    [SPOSE_LANDING] = SamusStanding,
    [SPOSE_CROUCHING] = SamusCrouching,
    [SPOSE_TURNING_AROUND_AND_CROUCHING] = SamusTurningAroundAndCrouching,
    [SPOSE_SHOOTING_AND_CROUCHING] = SamusCrouching,
    [SPOSE_STARTING_SPIN_JUMP] = SamusSpinning,
    [SPOSE_SPINNING] = SamusSpinning,
    [SPOSE_MORPHING] = SamusMorphing,
    [SPOSE_MORPH_BALL] = SamusMorphBall,
    [SPOSE_ROLLING] = SamusRolling,
    [SPOSE_UNMORPHING] = SamusUnmorphing,
    [SPOSE_MORPH_BALL_MID_AIR] = SamusMorphBallMidAir,
    [SPOSE_GETTING_HURT] = SamusInactivity,
    [SPOSE_GETTING_HURT_IN_MORPH_BALL] = SamusInactivity,
    [SPOSE_GETTING_KNOCKED_BACK] = SamusInactivity,
    [SPOSE_GETTING_KNOCKED_BACK_IN_MORPH_BALL] = SamusInactivity,
    [SPOSE_STARTING_WALL_JUMP] = SamusInactivity,
    [SPOSE_WALL_JUMPING] = SamusWallJumping,
    [SPOSE_USING_ELEVATOR] = SamusUsingElevator,
    [SPOSE_HANGING_ON_LEDGE] = SamusHangingOnLedge,
    [SPOSE_PULLING_UP_FROM_HANGING] = SamusPullingUpFromHanging,
    [SPOSE_PULLING_FORWARD_FROM_HANGING] = SamusPullingForwardFromHanging,
    [SPOSE_PULLING_INTO_MORPH_FROM_HANGING] = SamusPullingIntoMorphFromHanging,
    [SPOSE_LOWERING_DOWN_TO_START_HANGING] = SamusLoweringDownToStartHanging_Unused,
    [SPOSE_SPACE_JUMPING] = SamusSpinning,
    [SPOSE_SCREW_ATTACKING] = SamusSpinning,
    [SPOSE_SKIDDING] = SamusSkidding,
    [SPOSE_ON_SAVE_PAD] = SamusInactivity,
    [SPOSE_ON_RECHARGE_OR_SECURITY_PAD] = SamusInactivity,
    [SPOSE_TURNING_AROUND_TO_RECHARGE_OR_UNLOCK_DOORS] = SamusInactivity,
    [SPOSE_DELAY_BEFORE_SHINESPARKING] = SamusInactivity,
    [SPOSE_SHINESPARKING] = SamusShinesparking,
    [SPOSE_DELAY_AFTER_SHINESPARKING] = SamusInactivity,
    [SPOSE_HANGING_FROM_VERTICAL_LADDER] = SamusHangingOnVerticalLadder,
    [SPOSE_STARTING_TO_HOLD_ARM_OUT_ON_VERTICAL_LADDER] = SamusStartingToHoldArmOutOnVerticalLadder,
    [SPOSE_HOLDING_ARM_OUT_ON_VERTICAL_LADDER] = SamusHoldingArmOutOnVerticalLadder,
    [SPOSE_SHOOTING_ON_VERTICAL_LADDER] = SamusInactivity,
    [SPOSE_STARTING_TO_PUT_ARM_AWAY_ON_VERTICAL_LADDER] = SamusStartingToPutArmAwayOnVerticalLadder,
    [SPOSE_HANGING_ON_HORIZONTAL_LADDER] = SamusHangingOnHorizontalLadder,
    [SPOSE_MOVING_ON_HORIZONTAL_LADDER] = SamusMovingOnHorizontalLadder,
    [SPOSE_TURNING_AROUND_ON_HORIZONTAL_LADDER] = SamusTurningAroundOnHorizontalLadder,
    [SPOSE_DELAY_AFTER_SHOOTING_ON_HORIZONTAL_LADDER] = SamusDelayAfterShootingOnHorizontalLadder,
    [SPOSE_SHOOTING_ON_HORIZONTAL_LADDER] = SamusInactivity,
    [SPOSE_FROZEN] = SamusInactivity,
    [SPOSE_FROZEN_AND_FALLING] = SamusInactivity,
    [SPOSE_FROZEN_IN_MORPH_BALL] = SamusInactivity,
    [SPOSE_FROZEN_IN_MORPH_BALL_AND_FALLING] = SamusInactivity,
    [SPOSE_UNLOCKING_SECURITY] = SamusInactivity,
    [SPOSE_SAVING] = SamusInactivity,
    [SPOSE_ON_NAVIGATION_PAD] = SamusInactivity,
    [SPOSE_DOWNLOADING_ABILITY] = SamusInactivity,
    [SPOSE_BEING_RECHARGED] = SamusInactivity,
    [SPOSE_FACING_FOREGROUND] = SamusFacingForeground,
    [SPOSE_FACING_BACKGROUND] = SamusFacingForeground,
    [SPOSE_UNLOCKING_HABITATIONS_DECK] = SamusInactivity,
    [SPOSE_GRABBED_BY_ZAZABI] = SamusInactivity,
    [SPOSE_LOADING_SAVE] = SamusLoadingSave,
    [SPOSE_DYING] = SamusDying,
    [SPOSE_HIT_BY_OMEGA_METROID] = SamusHitByOmegaMetroid,
    [SPOSE_GRABBED_BY_YAKUZA] = SamusGrabbedByYakuza
};

const SamusFunc_T sSamusPoseGfxFunctionsPointers[SPOSE_END] = {
    [SPOSE_STANDING] = SamusStandingGfx,
    [SPOSE_TURNING_AROUND] = SamusTurningAroundGfx,
    [SPOSE_SHOOTING] = SamusShootingGfx,
    [SPOSE_RUNNING] = SamusRunningGfx,
    [SPOSE_MID_AIR] = SamusMidAirGfx,
    [SPOSE_TURNING_AROUND_MID_AIR] = SamusTurningAroundMidAirGfx,
    [SPOSE_LANDING] = SamusLandingGfx,
    [SPOSE_CROUCHING] = SamusInactivity,
    [SPOSE_TURNING_AROUND_AND_CROUCHING] = SamusTurningAroundAndCrouchingGfx,
    [SPOSE_SHOOTING_AND_CROUCHING] = SamusShootingAndCrouchingGfx,
    [SPOSE_STARTING_SPIN_JUMP] = SamusStartingSpinJumpGfx,
    [SPOSE_SPINNING] = SamusSpinningGfx,
    [SPOSE_MORPHING] = SamusMorphingGfx,
    [SPOSE_MORPH_BALL] = SamusMorphBallGfx,
    [SPOSE_ROLLING] = SamusMorphBallGfx,
    [SPOSE_UNMORPHING] = SamusUnmorphingGfx,
    [SPOSE_MORPH_BALL_MID_AIR] = SamusMorphBallGfx,
    [SPOSE_GETTING_HURT] = SamusGettingHurtGfx,
    [SPOSE_GETTING_HURT_IN_MORPH_BALL] = SamusGettingHurtGfx,
    [SPOSE_GETTING_KNOCKED_BACK] = SamusGettingKnockedBackGfx,
    [SPOSE_GETTING_KNOCKED_BACK_IN_MORPH_BALL] = SamusGettingKnockedBackGfx,
    [SPOSE_STARTING_WALL_JUMP] = SamusStartingWallJumpGfx,
    [SPOSE_WALL_JUMPING] = SamusSpinningGfx,
    [SPOSE_USING_ELEVATOR] = SamusUsingElevatorGfx,
    [SPOSE_HANGING_ON_LEDGE] = SamusHangingOnLedgeGfx,
    [SPOSE_PULLING_UP_FROM_HANGING] = SamusPullingUpFromHangingGfx,
    [SPOSE_PULLING_FORWARD_FROM_HANGING] = SamusPullingForwardFromHangingGfx,
    [SPOSE_PULLING_INTO_MORPH_FROM_HANGING] = SamusPullingIntoMorphFromHangingGfx,
    [SPOSE_LOWERING_DOWN_TO_START_HANGING] = SamusLoweringDownToStartHanging_UnusedGfx,
    [SPOSE_SPACE_JUMPING] = SamusSpaceJumpingGfx,
    [SPOSE_SCREW_ATTACKING] = SamusScrewAttackingGfx,
    [SPOSE_SKIDDING] = SamusInactivity,
    [SPOSE_ON_SAVE_PAD] = SamusOnSavePadGfx,
    [SPOSE_ON_RECHARGE_OR_SECURITY_PAD] = SamusInactivity,
    [SPOSE_TURNING_AROUND_TO_RECHARGE_OR_UNLOCK_DOORS] = SamusTurningAroundToRechargeOrUnlockSecurityGfx,
    [SPOSE_DELAY_BEFORE_SHINESPARKING] = SamusDelayBeforeShinesparkingGfx,
    [SPOSE_SHINESPARKING] = SamusShinesparkingGfx,
    [SPOSE_DELAY_AFTER_SHINESPARKING] = SamusDelayAfterShinesparkingGfx,
    [SPOSE_HANGING_FROM_VERTICAL_LADDER] = SamusHangingOnVerticalLadderGfx,
    [SPOSE_STARTING_TO_HOLD_ARM_OUT_ON_VERTICAL_LADDER] = SamusStartingToHoldArmOutOnVerticalLadderGfx,
    [SPOSE_HOLDING_ARM_OUT_ON_VERTICAL_LADDER] = SamusInactivity,
    [SPOSE_SHOOTING_ON_VERTICAL_LADDER] = SamusShootingOnVerticalLadderGfx,
    [SPOSE_STARTING_TO_PUT_ARM_AWAY_ON_VERTICAL_LADDER] = SamusStartingToPutArmAwayOnVerticalLadderGfx,
    [SPOSE_HANGING_ON_HORIZONTAL_LADDER] = SamusInactivity,
    [SPOSE_MOVING_ON_HORIZONTAL_LADDER] = SamusMovingOnHorizontalLadderGfx,
    [SPOSE_TURNING_AROUND_ON_HORIZONTAL_LADDER] = SamusTurningAroundOnHorizontalLadderGfx,
    [SPOSE_DELAY_AFTER_SHOOTING_ON_HORIZONTAL_LADDER] = SamusInactivity,
    [SPOSE_SHOOTING_ON_HORIZONTAL_LADDER] = SamusShootingOnHorizontalLadderGfx,
    [SPOSE_FROZEN] = SamusFrozenGfx,
    [SPOSE_FROZEN_AND_FALLING] = SamusFrozenGfx,
    [SPOSE_FROZEN_IN_MORPH_BALL] = SamusFrozenInMorphBallGfx,
    [SPOSE_FROZEN_IN_MORPH_BALL_AND_FALLING] = SamusFrozenInMorphBallGfx,
    [SPOSE_UNLOCKING_SECURITY] = SamusUnlockingSecurityGfx,
    [SPOSE_SAVING] = SamusSavingGfx,
    [SPOSE_ON_NAVIGATION_PAD] = SamusOnNavigationPadGfx,
    [SPOSE_DOWNLOADING_ABILITY] = SamusDownloadingAbilityGfx,
    [SPOSE_BEING_RECHARGED] = SamusBeingRechargedGfx,
    [SPOSE_FACING_FOREGROUND] = SamusFacingForegroundGfx,
    [SPOSE_FACING_BACKGROUND] = SamusFacingForegroundGfx,
    [SPOSE_UNLOCKING_HABITATIONS_DECK] = SamusUnlockingHabitationsDeckGfx,
    [SPOSE_GRABBED_BY_ZAZABI] = SamusMorphBallGfx,
    [SPOSE_LOADING_SAVE] = SamusLoadingSaveGfx,
    [SPOSE_DYING] = SamusDyingGfx,
    [SPOSE_HIT_BY_OMEGA_METROID] = SamusHitByOmegaMetroidGfx,
    [SPOSE_GRABBED_BY_YAKUZA] = SamusInactivity
};
