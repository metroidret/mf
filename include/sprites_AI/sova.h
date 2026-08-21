#ifndef SOVA_AI_H
#define SOVA_AI_H

#include "types.h"

boolu8 SovaCheckCollidingWithAir(void);
void SovaUpdateHitbox(void);
void SovaSetCrawlingOam(void);
void SovaTurningIntoX(void);
void SovaInit(void);
void SovaIdleInit(void);
void SovaIdle(void);
void SovaTurningAroundInit(void);
void SovaTurningAround(void);
void SovaFallingInit(void);
void SovaFalling(void);
void SovaFireInit(void);
void SovaFireBig(void);
void SovaFireSmall(void);
void SovaFireDisappearing(void);
void SovaFireExplodingInit(void);
void SovaFireExploding(void);
void Sova(void);
void SovaFire(void);

#endif /* SOVA_AI_H */
