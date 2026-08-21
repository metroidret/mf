#ifndef PUYO_AI_H
#define PUYO_AI_H

#include "types.h"

void PuyoInit(void);
void PuyoFallingInit(void);
void PuyoIdleInit(void);
void PuyoIdle(void);
void PuyoWaitingInit(void);
void PuyoWaiting(void);
void PuyoJumpWarningInit(void);
void PuyoJumpWarning(void);
void PuyoJumpingUp(void);
void PuyoJumpingDown(void);
void PuyoLanding(void);
void Puyo(void);

#endif /* PUYO_AI_H */
