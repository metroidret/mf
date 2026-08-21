#ifndef OMEGA_METROID_HUSK_AI_H
#define OMEGA_METROID_HUSK_AI_H

#include "types.h"

void OmegaMetroidHuskSetInvisibleWallCollision(u8 caa);
void OmegaMetroidHuskInit(void);
void OmegaMetroidHuskWaitingForSamus(void);
void OmegaMetroidHuskWaitForOmegaMetroidToSpawn(void);
void OmegaMetroidHuskGettingCrushedInit(void);
void OmegaMetroidHuskGettingCrushed(void);
void OmegaMetroidHuskWaiting(void);
void OmegaMetroidHuskDisappearing(void);
void OmegaMetroidHusk(void);

#endif /* OMEGA_METROID_HUSK_AI_H */
