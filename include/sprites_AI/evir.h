#ifndef EVIR_AI_H
#define EVIR_AI_H

#include "types.h"

u8 EvirCheckInShootingRange(void);
void EvirSpawningFromX(void);
void EvirTurningIntoX(void);
void EvirInit(void);
void EvirShootingInit(void);
void EvirShooting(void);
void EvirIdleInit(void);
void EvirIdle(void);
void EvirTurningAroundInit(void);
void EvirTurningAround(void);
void EvirTurningAroundSecondPart(void);
void EvirCollisionInit(void);
void EvirCollisionIdle(void);
void EvirProjectileInit(void);
void EvirProjectileMovingInit(void);
void EvirProjectileMoving(void);
void EvirProjectileExplodingInit(void);
void EvirProjectileExploding(void);
void Evir(void);
void EvirCollision(void);
void EvirProjectile(void);

#endif /* EVIR_AI_H */
