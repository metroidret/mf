#ifndef SCISER_AI_H
#define SCISER_AI_H

#include "types.h"

u8 SciserCheckCollisions(void);
void SciserUpdateHitbox(void);
void SciserSetCrawlingGraphics(void);
void SciserSetIdleGraphics(void);
void SciserCheckSamusInRange(void);
void SciserShooting(void);
void SciserTurningIntoX(void);
void SciserInit(void);
void SciserCrawlingInit(void);
void SciserCrawling(void);
void SciserIdleInit(void);
void SciserIdle(void);
void SciserFallingInit(void);
void SciserFalling(void);
void SciserProjectileInit(void);
void SciserProjectileFalling(void);
void SciserProjectileExplodingInit(void);
void SciserProjectileExploding(void);
void Sciser(void);
void SciserProjectile(void);

#endif /* SCISER_AI_H */
