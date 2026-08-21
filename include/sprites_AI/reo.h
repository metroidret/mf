#ifndef REO_AI_H
#define REO_AI_H

#include "types.h"

void ReoPlaySound(void);
u8 ReoCheckFall(void);
u8 ReoXMovement(u16 movement);
void ReoInit(void);
void ReoFallInit(void);
void ReoFalling(void);
void ReoLanding(void);
void ReoIdleInit(void);
void ReoIdle(void);
void ReoGoingDownInit(void);
void ReoGoingDown(void);
void ReoSlidingInit(void);
void ReoSliding(void);
void ReoGoingUpInit(void);
void ReoGoingUp(void);
void ReoWingsInit(void);
void ReoWingsIdle(void);
void Reo(void);
void ReoWings(void);

#endif /* REO_AI_H */
