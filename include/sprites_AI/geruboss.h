#ifndef GERUBOSS_AI_H
#define GERUBOSS_AI_H

#include "types.h"

u8 GerubossYMovement(u16 movement);
u8 GerubossXMovement(u16 movement);
void GerubossTurningIntoX(void);
void GerubossInit(void);
void GerubossIdleInit(void);
void GerubossIdle(void);
void GerubossStalling(void);
void GerubossChargingInit(void);
void GerubossCharging(void);
void GerubossGoingDown(void);
void GerubossChangingDirection(void);
void GerubossGoingUp(void);
void GerubossGrabbingCeiling(void);
void Geruboss(void);

#endif /* GERUBOSS_AI_H */
