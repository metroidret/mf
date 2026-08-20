#ifndef POWAMP_AI_H
#define POWAMP_AI_H

#include "types.h"

void PowampInit(void);
void PowampIdleInit(void);
void PowampIdle(void);
void PowampExtendingInit(void);
void PowampExtending(void);
void PowampExtendedInit(void);
void PowampExtended(void);
void PowampRetractingInit(void);
void PowampRetracting(void);
void Powamp(void);

#endif /* POWAMP_AI_H */
