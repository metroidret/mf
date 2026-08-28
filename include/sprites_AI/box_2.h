#ifndef BOX_2_AI_H
#define BOX_2_AI_H

#include "types.h"

void Box2SyncSubSprites(void);
boolu8 Box2XMovement(u16 speed, u8 collidedPose);
void Box2Init(void);
void Box2WaitingToRunInit(void);
void Box2WaitingToRun(void);
void Box2SlowRunningInit(void);
void Box2SlowRunning(void);
void Box2FastRunningInit(void);
void Box2FastRunning(void);
void Box2SkiddingInit(void);
void Box2Skidding(void);
void Box2StopSkiddingInit(void);
void Box2StopSkidding(void);
void Box2BonkingInit(void);
void Box2Bonking(void);
void Box2LandingFromBonkInit(void);
void Box2LandingFromBonk(void);
void Box2LandingInit(void);
void Box2Landing(void);
void Box2FinishedCrawlingInit(void);
void Box2FinishCrawling(void);
void Box2JumpWarningInit(void);
void Box2JumpWarning(void);
void Box2JumpingInit(void);
void Box2Jumping(void);
void Box2StoppingToFireMissilesInit(void);
void Box2StoppingToFireMissiles(void);
void Box2LoweringToFireMissilesInit(void);
void Box2LoweringToFireMissiles(void);
void Box2FiringMissiles(void);
void Box2DoneFiringMissiles(void);
void Box2DyingInit(void);
void Box2Dying(void);
void Box2ExplodingInit(void);
void Box2Exploding(void);
void Box2BrainRisingInit(void);
void Box2BrainRising(void);
void Box2BrainFloating(void);
void Box2CrawlingInit(void);
void Box2Crawling(void);

void Box2PartSetBoxJumpCounter(u8 slot, u8 jumps);
void Box2PartCenterUpdateImmunity(u8 slot);
void Box2PartLegRemoveIgnoreProjectiles(u8 ramSlot);
void Box2PartInit(void);
void Box2PartFrontLeftLeg(void);
void Box2PartFrontRightLeg(void);
void Box2PartCenter(void);
void Box2PartBottom(void);
void Box2PartDefault(void);

void Box2MissileInit(void);
void Box2MissileLaunching(void);
void Box2MissileMoving(void);
void Box2MissileExploding(void);

void Box2BrainTopInit(void);
void Box2BrainTopRising(void);
void Box2BrainTopFloating(void);
void Box2BrainTopTransformingInit(void);
void Box2BrainTopTransforming(void);

void Box2BrainBottomInit(void);
void Box2BrainBottomIdle(void);

void Box2(void);
void Box2Part(void);
void Box2Missile(void);
void Box2BrainTop(void);
void Box2BrainBottom(void);

#endif /* BOX_2_AI_H */
