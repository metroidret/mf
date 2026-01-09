#ifndef DACHORA_H
#define DACHORA_H

#include "constants/sprite.h"
#include "data/samus_data.h"
#include "event_checks.h"
#include "globals.h"
#include "samus.h"
#include "structs/sprite.h"
#include "sprite_util.h"
#include "sprite.h"

boolu32 DachoraCheckDoHeadMovement(void);
void DachoraInit(void);
void DachoraIdleInit(void);
void DachoraIdle(void);
void DachoraStandingIdle(void);
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

void BabyDachoraInit(void);
void BabyDachoraWalkingToGate(void);
void BabyDachoraLeavingEnclosure(void);
void BabyDachoraWalkingToWaitingSpot(void);
void BabyDachoraWaitingToRun(void);
void BabyDachoraRunning(void);

extern const s16 sArray_838188c[];
extern const s16 sArray_0x0838188c[];
extern u8 sVar_0x030006ea[];

#endif /* DACHORA_H */
