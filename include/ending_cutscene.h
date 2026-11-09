#ifndef ENDING_CUTSCENE_H
#define ENDING_CUTSCENE_H

#include "types.h"

#include "structs/cutscene.h"

boolu32 EndingHandler(void);
void EndingBslCrashingInit(void);
void EndingShipFrontViewInit(void);
boolu32 EndingBslCrashingProcess(void);
boolu32 EndingBslCrashing(void);
void EndingProcessFallingBsl(struct SpecialCutsceneOam* pOam);
void unk_9579c(struct SpecialCutsceneOam* pOam);
void EndingProcessLeavingSmallShip(struct SpecialCutsceneOam* pOam);
void EndingProcessLeavingBigShip(struct SpecialCutsceneOam* pOam);
void EndingProcessFrontFacingShipThrusters(struct SpecialCutsceneOam* pOam);
void EndingProcessFrontFacingShip(struct SpecialCutsceneOam* pOam);
u8 EndingBslCrashingSetupOam(u8 type, s16 xPosition, s16 yPosition, u8 descendingSearch);
void EndingBslCrashingVblank(void);
void EndingShipFrontViewVblank(void);
u8 EndingGetPositionAndSlotOfOamByType(u8 type, s16* pXPosition, s16* pYPosition);
void unk_95e20(struct SpecialCutsceneOam* pOam);

// TODO: sort
boolu32 EndingInShip(void);

#endif /* ENDING_CUTSCENE_H */
