#ifndef SKULTERA_AI_H
#define SKULTERA_AI_H

#include "types.h"

void SkulteraSetSidesHitboxes(void);
u8 SkulteraXMovement(u16 movement);
void SkulteraTurningIntoX(void);
void SkulteraInit(void);
void SkulteraIdleInit(void);
void SkulteraIdle(void);
void SkulteraChasingSamusInit(void);
void SkulteraChasingSamus(void);
void SkulteraTurningAroundInit(void);
void SkulteraTurningAround(void);
void Skultera(void);

#endif /* SKULTERA_AI_H */
