#ifndef RIDLEY_AI_H
#define RIDLEY_AI_H

#include "types.h"

void RidleyMove(u16 dstY, u16 dstX, u8 ySpeedCap, u8 xSpeedCap, u8 speedDivisor);
void SpriteUtilUpdateSubSpriteData2Animation(void);
void RidleyTailSyncSubSpritesPosition(void);
void RidleySyncSubSprites(void);
void RidleyTailSyncSubSprites(void);
void RidleyUpdatePalette(void);
void RidleySetBackgroundPriority(void);
void RidleyUpdateClawOam(void);
void RidleyTailStrikingCheckPlayEffects(void);
void RidleyTailStrikeYMovement(u16 movement);
void RidleyFloatingMovement(void);
void RidleyUpdateHealthThreshold(void);
void RidleyWaveBeamCollision(void);
boolu32 RidleyCheckGrabSamusLeft(u16 yPosition, u16 xPosition);
boolu32 RidleyCheckGrabSamusRight(u16 yPosition, u16 xPosition);
void RidleySamusGrabbed(void);
void RidleySetSideHitboxes(void);
boolu8 RidleyXMovement_Unused(u16 movement);
boolu8 RidleyTailXMovement(u16 movement);
void RidleyScreamingInit(void);
void RidleyScreaming(void);
void RidleyTurningIntoCoreX(void);
void RidleyForming(void);
void RidleyScreamingAfterSpawn(void);
void RidleyRisingAfterSpawn(void);
void RidleyInit(void);
void RidleyIdleInit(void);
void RidleyIdle(void);
void RidleyTurningAroundInit(void);
void RidleyTurningAround(void);
void RidleyTurningAroundSecondPart(void);
void RidleyFlyingBackwardsInit(void);
void RidleyFlyingBackwards(void);
void RidleyPreparingTailAttack(void);
void RidleyTailAttack(void);
void RidleyShootingFireInit(void);
void RidleyShootingFire(void);
void RidleyPartInit(void);
void RidleyPartIdle(void);
void RidleyTailPartInit(void);
void RidleyTailPartTipHandleRotation(void);
void RidleyTailPartIdle(void);
void RidleyTailPartWaitingToWindUp(void);
void RidleyTailPartWindingUp1(void);
void RidleyTailPartWindingUp2(void);
void RidleyTailPartStrikingDown1(void);
void RidleyTailPartStrikingDown2(void);
void RidleyTailPartStrikingDown3(void);
void RidleyTailPartStrikingForward(void);
void RidleyTailPartDoneStriking(void);
void RidleyFireInit(void);
void RidleyFireMoving(void);
void RidleyFireMovingTowardsSamus(void);
void RidleyFireExploding(void);
void Ridley(void);
void RidleyPart(void);
void RidleyTailPart(void);
void RidleyFire(void);

#endif /* RIDLEY_AI_H */
