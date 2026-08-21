#ifndef ZEBESIAN_AQUA_AI_H
#define ZEBESIAN_AQUA_AI_H

#include "types.h"

boolu8 ZebesianAquaXMovement(u16 distance);
void ZebesianAquaTurningIntoX(void);
void ZebesianAquaInit(void);
void ZebesianAquaIdleInit(void);
void ZebesianAquaIdle(void);
void ZebesianAquaLungeInit(void);
void ZebesianAquaLunge(void);
void ZebesianAquaShootingInit(void);
void ZebesianAquaShooting(void);
void ZebesianAquaTurningAroundInit(void);
void ZebesianAquaTurningAround(void);

void ZebesianAquaProjectileInit(void);

void ZebesianAqua(void);
void ZebesianAquaProjectile(void);

#endif /* ZEBESIAN_AQUA_AI_H */
