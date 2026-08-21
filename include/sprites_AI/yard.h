#ifndef YARD_AI_H
#define YARD_AI_H

#include "types.h"

boolu8 YardCheckShouldStartle(void);
boolu8 YardCheckCollidingWithAir(void);
void YardUpdateHitbox(void);
void YardSetCrawlingOam(void);
void YardSetTurningAroundOam(void);
void YardSetTurningAroundSecondPartOam(void);
void YardSetChargingOam(void);
void YardSetShootingOam(void);
void YardSetRecoilOam(void);
void YardCheckShoot(void);
void YardCharging(void);
void YardShooting(void);
void YardRecoil(void);
void YardTurningIntoX(void);
void YardInit(void);
void YardCheckRoll(void);
void YardRolling(void);
void YardStartled(void);
void YardIdleInit(void);
void YardIdle(void);
void YardTurningAroundInit(void);
void YardTurningAround(void);
void YardTurningAroundSecondPart(void);
void YardFallingInit(void);
void YardFalling(void);
void YardProjectileInit(void);
void YardProjectileMoving(void);
void YardProjectileExplodingInit(void);
void YardProjectileExploding(void);
void Yard(void);
void YardProjectile(void);

#endif /* YARD_AI_H */
