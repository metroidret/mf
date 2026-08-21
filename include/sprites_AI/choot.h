#ifndef CHOOT_AI_H
#define CHOOT_AI_H

#include "types.h"

void ChootSetOpenHitbox(void);
void ChootSetClosedHitbox(void);
void ChootInit(void);
void ChootIdleInit(void);
void ChootIdle(void);
void ChootLaunchingInit(void);
void ChootLaunching(void);
void ChootGoingUpInit(void);
void ChootGoingUp(void);
void ChootOpeningInit(void);
void ChootOpening(void);
void ChootGoingDownInit(void);
void ChootGoingDown(void);
void ChootSpitInit(void);
void ChootSpitSpawning(void);
void ChootSpitExplodingInit(void);
void ChootSpitExploding(void);
void Choot(void);
void ChootSpit(void);

#endif /* CHOOT_AI_H */
