#ifndef ZEBESIAN_GROUND_AI_H
#define ZEBESIAN_GROUND_AI_H

#include "types.h"

u8 ZebesianGroundCheckInRange(void);
boolu8 ZebesianGroundCheckCollidingWithAir(void);
void ZebesianGroundSetIdleHitbox(void);
void ZebesianGroundSetShootingHitbox(void);
void ZebesianGroundInit(void);
void ZebesianGroundSpawningFromX(void);
void ZebesianPreAquaTurningintoX(void);
void ZebesianGroundTurningIntoX(void);
void ZebesianGroundFallingInit(void);
void ZebesianGroundIdleInit(void);
void ZebesianGroundIdle(void);
void ZebesianGroundTurningAroundInit(void);
void ZebesianGroundTurningAround(void);
void ZebesianGroundTurningAroundSecondPart(void);
void ZebesianGroundJumpWarningInit(void);
void ZebesianGroundJumpWarning(void);
void ZebesianGroundJumping(void);
void ZebesianGroundLandingInit(void);
void ZebesianGroundLanding(void);
void ZebesianGroundWaitingInit(void);
void ZebesianGroundWaiting(void);
void ZebesianGroundStandingInit(void);
void ZebesianGroundStanding(void);
void ZebesianGroundShootingInit(void);
void ZebesianGroundShooting(void);
void ZebesianGroundShootingEndInit(void);
void ZebesianGroundShootingEnd(void);
void ZebesianGroundBeamInit(void);
void ZebesianGroundBeamSpawning(void);
void ZebesianGroundBeamExtending(void);
boolu8 ZebesianGroundCheckSkipMovement(void);
void ZebesianGround(void);
void ZebesianGroundBeam(void);

#endif /* ZEBESIAN_GROUND_AI_H */
