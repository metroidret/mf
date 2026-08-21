#ifndef GERUTA_AI_H
#define GERUTA_AI_H

#include "types.h"

u8 GerutaYMovement(u16 movement);
u8 GerutaXMovement(u16 movement);
void GerutaSetIdleHitboxes(void);
void GerutaSetAttackingHitboxes(void);
void GerutaUpdateLungingAnimation(void);
void GerutaInit(void);
void GerutaIdleInit(void);
void GerutaIdle(void);
void GerutaTurningAroundInit(void);
void GerutaTurningAround(void);
void GerutaAttackWarningInit(void);
void GerutaAttackWarning(void);
void GerutaAttacking(void);
void Geruta(void);

#endif /* GERUTA_AI_H */
