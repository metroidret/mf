#ifndef BOX2_H
#define BOX2_H

#include "types.h"

/**
 * Pose values for the Box2 sprite's primary state machine. Each value is the
 * argument to the main Box2 dispatcher's pose switch — `pose = X` means the
 * next tick will run the handler indexed by X. Names describe the handler the
 * value dispatches to (so e.g. `BOX2_POSE_SLOW_RUNNING_INIT = 0x19` because
 * setting pose to 0x19 makes Box2SlowRunningInit run next tick).
 */
enum Box2Pose {
    /* Idle / crawl */
    BOX2_POSE_IDLE_INIT = 0x1,
    BOX2_POSE_CRAWLING = 0x2,
    BOX2_POSE_FINISHED_CRAWLING_INIT = 0x7,
    BOX2_POSE_FINISH_CRAWLING = 0x8,

    /* Running sequence */
    BOX2_POSE_WAITING_TO_RUN_INIT = 0x17,
    BOX2_POSE_WAITING_TO_RUN = 0x18,
    BOX2_POSE_SLOW_RUNNING_INIT = 0x19,
    BOX2_POSE_SLOW_RUNNING = 0x1a,
    BOX2_POSE_FAST_RUNNING_INIT = 0x1b,
    BOX2_POSE_FAST_RUNNING = 0x1c,
    BOX2_POSE_SKIDDING_INIT = 0x1d,
    BOX2_POSE_SKIDDING = 0x1e,
    BOX2_POSE_STOP_SKIDDING_INIT = 0x1f,
    BOX2_POSE_STOP_SKIDDING = 0x20,

    /* Missile-firing sequence */
    BOX2_POSE_STOPPING_TO_FIRE_MISSILES_INIT = 0x27,
    BOX2_POSE_STOPPING_TO_FIRE_MISSILES = 0x28,
    BOX2_POSE_LOWERING_TO_FIRE_MISSILES_INIT = 0x29,
    BOX2_POSE_LOWERING_TO_FIRE_MISSILES = 0x2a,
    BOX2_POSE_FIRING_MISSILES = 0x2c,
    BOX2_POSE_DONE_FIRING_MISSILES = 0x2e,

    /* Bonking / jumping sequence */
    BOX2_POSE_BONKING_INIT = 0x37,
    BOX2_POSE_BONKING = 0x38,
    BOX2_POSE_LANDING_INIT = 0x39,
    BOX2_POSE_LANDING = 0x3a,
    BOX2_POSE_JUMP_WARNING_INIT = 0x3b,
    BOX2_POSE_JUMP_WARNING = 0x3c,
    BOX2_POSE_JUMPING_INIT = 0x3d,
    BOX2_POSE_JUMPING = 0x3e,

    /* Dying / brain reveal sequence */
    BOX2_POSE_DYING_INIT = 0x43,
    BOX2_POSE_DYING = 0x44,
    BOX2_POSE_EXPLODING_INIT = 0x45,
    BOX2_POSE_EXPLODING = 0x46,
    BOX2_POSE_BRAIN_RISING_INIT = 0x47,
    BOX2_POSE_BRAIN_RISING = 0x48,
    BOX2_POSE_BRAIN_FLOATING = 0x49,

    /* Bonk landing (taken when Bonking hits the floor mid-flight) */
    BOX2_POSE_LANDING_FROM_BONK_INIT = 0x4b,
    BOX2_POSE_LANDING_FROM_BONK = 0x4c
};

extern void Box2SyncSubSprites(void);
extern u8 Box2XMovement(u16 movement, u8 collidedPose);
extern void Box2Init(void);
extern void Box2WaitingToRunInit(void);
extern void Box2WaitingToRun(void);
extern void Box2SlowRunningInit(void);
extern void Box2SlowRunning(void);
extern void Box2FastRunningInit(void);
extern void Box2FastRunning(void);
extern void Box2SkiddingInit(void);
extern void Box2Skidding(void);
extern void Box2StopSkiddingInit(void);
extern void Box2StopSkidding(void);
extern void Box2BonkingInit(void);
extern void Box2Bonking(void);
extern void Box2LandingFromBonkInit(void);
extern void Box2LandingFromBonk(void);
extern void Box2LandingInit(void);
extern void Box2Landing(void);
extern void Box2FinishedCrawlingInit(void);
extern void Box2FinishCrawling(void);
extern void Box2JumpWarningInit(void);
extern void Box2JumpWarning(void);
extern void Box2JumpingInit(void);
extern void Box2Jumping(void);
extern void Box2StoppingToFireMissilesInit(void);
extern void Box2StoppingToFireMissiles(void);
extern void Box2LoweringToFireMissilesInit(void);
extern void Box2LoweringToFireMissiles(void);
extern void Box2FiringMissiles(void);
extern void Box2DoneFiringMissiles(void);
extern void Box2DyingInit(void);
extern void Box2Dying(void);
extern void Box2ExplodingInit(void);
extern void Box2Exploding(void);
extern void Box2BrainRisingInit(void);
extern void Box2BrainRising(void);
extern void Box2BrainFloating(void);
extern void Box2IdleInit(void);
extern void Box2Crawling(void);
extern void Box2PartSetBoxWorkVar2(u8 slot, u8 value);
extern void Box2PartCenterSetImmunity(u8 slot);
extern void Box2PartRemoveIgnoreProjectiles(void);
extern void Box2PartInit(void);
// extern <return_type> Box2PartFrontLeftLeg(<params>);
// extern <return_type> Box2PartFrontRightLeg(<params>);
// extern <return_type> Box2PartTopShell(<params>);
// extern <return_type> Box2PartBottomShell(<params>);
// extern <return_type> Box2PartDefault(<params>);
// extern <return_type> Box2MissileInit(<params>);
// extern <return_type> Box2MissileLaunching(<params>);
// extern <return_type> Box2MissileMoving(<params>);
// extern <return_type> Box2MissileExploding(<params>);
// extern <return_type> Box2BrainTopInit(<params>);
// extern <return_type> Box2BrainTopRising(<params>);
// extern <return_type> Box2BrainTopFloating(<params>);
// extern <return_type> Box2BrainTopTransformingInit(<params>);
// extern <return_type> Box2BrainTopTransforming(<params>);
// extern <return_type> Box2BrainBottomInit(<params>);
// extern <return_type> Box2BrainBottomIdle(<params>);
// extern <return_type> Box2(<params>);
// extern <return_type> Box2Part(<params>);
// extern <return_type> Box2Missile(<params>);
// extern <return_type> Box2BrainTop(<params>);
// extern <return_type> Box2BrainBottom(<params>);

#endif // BOX2_H
