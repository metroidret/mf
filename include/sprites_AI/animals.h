#ifndef DACHORA_H
#define DACHORA_H

#include "types.h"

boolu8 DachoraCheckDoHeadMovement(void);
void DachoraInit(void);
void DachoraIdleInit(void);
void DachoraIdle(void);
void DachoraStandingInit(void);
void DachoraStanding(void);
void DachoraHeadMovementInit(void);
void DachoraHeadMovement(void);
void DachoraTurningAroundInit(void);
void DachoraTurningAround(void);
void DachoraTurningAroundSecondPart(void);
void DachoraTurningAroundWhileLeavingInit(void);
void DachoraTurningAroundWhileLeaving(void);
void DachoraTurningAroundWhileLeavingSecondPart(void);
void DachoraLeavingEnclosureInit(void);
void DachoraLeavingEnclosure(void);
void DachoraWalkingToWaitingSpotInit(void);
void DachoraWalkingToWaitingSpot(void);
void DachoraWaitingForOthers(void);
void DachoraWaitingToSpawnBaby(void);
void DachoraWaitingForBaby(void);
void DachoraBowing(void);
void DachoraWaitingToRun(void);
void DachoraRunning(void);
void Dachora(void);

void BabyDachoraInit(void);
void BabyDachoraWalkingToGate(void);
void BabyDachoraLeavingEnclosure(void);
void BabyDachoraWalkingToWaitingSpot(void);
void BabyDachoraWaitingToRun(void);
void BabyDachoraRunning(void);
void BabyDachora(void);

#endif /* DACHORA_H */
