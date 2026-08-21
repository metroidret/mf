#ifndef NIGHTMARE_AI_H
#define NIGHTMARE_AI_H

#include "types.h"

void NightmareMoveToPosition(u16 dstY, u16 dstX, u8 ySpeedCap, u8 xSpeedCap, u8 speedDivisor);
void NightmareSyncSubSprites(void);
void NightmarePlaySound(void);
void NightmareMakeMissilesFall(void);
void NightmareReduceSamusXVelocity(void);
void NightmareInit(void);
void NightmareWaitingToAppear(void);
void NightmareAppearing(void);
void NightmarePhase1Init(void);
void NightmarePhase1(void);
void NightmarePhase2ResettingPosition(void);
void NightmarePhase2MovementInit(void);
void NightmarePhase2Movement(void);
void NightmareMovingToPhase3Init(void);
void NightmareMovingToPhase3(void);
void NightmareReachedPhase3Position(void);
void NightmarePhase3SlowMovementInit(void);
void NightmarePhase3SlowMovement(void);
void NightmarePhase3FastMovementInit(void);
void NightmarePhase3FastMovement(void);
void NightmareDeathFlash(void);
void NightmareMovingToDeathPosition(void);
void NightmareTurningIntoCoreX(void);
void NightmarePartInit(void);
void NightmarePartDying(u8 primaryRamSlot);
void NightmarePartSpawnBeam(void);
void NightmarePartRightArmTop(void);
void NightmarePartRightArmBottom(void);
void NightmarePartRightTurret1(void);
void NightmarePartRightTurret2(void);
void NightmarePartRightTurret3(void);
void NightmarePartLeftTurret1(void);
void NightmarePartLeftTurret2(void);
void NightmarePartLeftTurret3(void);
void NightmarePartEye(void);
void NightmarePartMouth(void);
void NightmarePartEyeSludge(void);
void NightmarePartChinSludge(void);
void NightmarePartGeneratorUpdateGlowingPalette(void);
void NightmarePartGeneratorUpdateDyingPalette(void);
void NightmarePartGenerator(void);
void NightmareBeamInit(void);
void NightmareBeamMoving(void);
void NightmareFallingArmInit(void);
void NightmareFallingArmMoving(void);
void Nightmare(void);
void NightmarePart(void);
void NightmareBeam(void);
void NightmareFallingArm(void);

#endif /* NIGHTMARE_AI_H */
