#ifndef ANIMALS_H
#define ANIMALS_H

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
void DachoraWaitingToRunAway(void);
void DachoraRunningAway(void);

void BabyDachoraInit(void);
void BabyDachoraWalkingToGate(void);
void BabyDachoraLeavingEnclosure(void);
void BabyDachoraWalkingToWaitingSpot(void);
void BabyDachoraWaitingToRunAway(void);
void BabyDachoraRunningAway(void);

boolu8 EtecoonCheckGrabTireSwing(void);
boolu8 EtecoonCheckFaceForeground(void);
void EtecoonInit(void);
void EtecoonIdleInit(void);
void EtecoonIdle(void);
void EtecoonStandingInit(void);
void EtecoonStanding(void);
void EtecoonFacingForegroundInit(void);
void EtecoonFacingForeground(void);
void EtecoonTurningAroundInit(void);
void EtecoonTurningAround(void);
void EtecoonTurningAroundSecondPart(void);
void EtecoonJumpingToTire(void);
void EtecoonSwingingFromTire(void);
void EtecoonFallingFromTire(void);
void EtecoonTurningAroundWhileLeavingInit(void);
void EtecoonTurningAroundWhileLeaving(void);
void EtecoonTurningAroundWhileLeavingSecondPart(void);
void EtecoonLeavingEnclosureInit(void);
void EtecoonLeavingEnclosure(void);
void EtecoonWalkingToWaitingSpotInit(void);
void EtecoonWalkingToWaitingSpot(void);
void EtecoonWaitingForOthersInit(void);
void EtecoonWaitingForOthers(void);
void EtecoonRunningAway(void);

void TireSwingInit(void);
void TireSwingIdle(void);

void Dachora(void);
void BabyDachora(void);
void Etecoon(void);
void TireSwing(void);
void HabitationGateLight(void);
void HabitationGate(void);

#endif /* ANIMALS_H */
