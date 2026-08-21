#ifndef ZEELA_AI_H
#define ZEELA_AI_H

#include "types.h"

boolu8 ZeelaCheckCollidingWithAir(void);
void ZeelaUpdateHitbox(void);
void ZeelaSetCrawlingOam(void);
void ZeelaSetFallingOam(void);
void ZeelaShootProjectiles(void);
void ZeelaTurningIntoX(void);
void ZeelaInit(void);
void ZeelaIdleInit(void);
void ZeelaIdle(void);
void ZeelaTurningAroundInit(void);
void ZeelaTurningAround(void);
void ZeelaFallingInit(void);
void ZeelaFalling(void);
void ZeelaProjectileInit(void);
void ZeelaProjectileMoving(void);
void ZeelaProjectileExplodingInit(void);
void ZeelaProjectileExploding(void);
void Zeela(void);
void ZeelaProjectile(void);

#endif /* ZEELA_AI_H */
