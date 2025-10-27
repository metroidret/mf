#ifndef DESSGEEGA_AI_H
#define DESSGEEGA_AI_H

#include "types.h"

u8 DessgeegaCheckSamusInRange(void);
void DessgeegaInit(void);
void DessgeegaPreparingToJumpInit(void);
void DessgeegaJumpingInit(void);
void DessgeegaLandingInit(void);
void DessgeegaIdleInit(void);
void DessgeegaFallingInit(void);
void DessgeegaJumpWarningGround(void);
void DessgeegaJumpWarningCeiling(void);
void DessgeegaJumpingGround(void);
void DessgeegaJumpingCeiling(void);
void DessgeegaLanding(void);
void DessgeegaFallingGround(void);
void DessgeegaFallingCeiling(void);
void DessgeegaIdleGround(void);
void DessgeegaIdleCeiling(void);
void DessgeegaSpikeInit(void);
void DessgeegaSpikeMove(void);
void DessgeegaSpikeExplodingInit(void);
void DessgeegaSpikeExploding(void);
void Dessgeega(void);
void DessgeegaSpike(void);

#endif /* DESSGEEGA_AI_H */
