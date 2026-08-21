#ifndef OWTCH_AI_H
#define OWTCH_AI_H

#include "types.h"

boolu8 OwtchCheckCollidingWithAir(void);
void OwtchUpdateHitbox(void);
void OwtchSetCrawlingOam(void);
void OwtchSetFallingOam(void);
void OwtchTurningIntoX(void);
void OwtchInit(void);
void OwtchIdleInit(void);
void OwtchIdle(void);
void OwtchTurningAroundInit(void);
void OwtchTurningAround(void);
void OwtchLandingInit(void);
void OwtchLanding(void);
void OwtchFallingInit(void);
void OwtchFalling(void);
void Owtch(void);

#endif /* OWTCH_AI_H */
