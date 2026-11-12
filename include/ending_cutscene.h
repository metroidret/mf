#ifndef ENDING_CUTSCENE_H
#define ENDING_CUTSCENE_H

#include "types.h"

#include "constants/ending_cutscene.h"

#include "structs/cutscene.h"

boolu32 EndingHandler(void);
void EndingBslCrashingInit(void);
void EndingShipFrontViewInit(void);
boolu32 EndingBslCrashingProcess(void);
boolu32 EndingBslCrashing(void);
void EndingProcessFallingBsl(struct SpecialCutsceneOam* pOam);
void EndingProcessReentryDebris(struct SpecialCutsceneOam* pOam);
void EndingProcessLeavingSmallShip(struct SpecialCutsceneOam* pOam);
void EndingProcessLeavingBigShip(struct SpecialCutsceneOam* pOam);
void EndingProcessFrontFacingShipThrusters(struct SpecialCutsceneOam* pOam);
void EndingProcessFrontFacingShip(struct SpecialCutsceneOam* pOam);
u8 EndingBslCrashingSetupOam(EndingBslCrashingOamType type, s16 xPosition, s16 yPosition, u8 descendingSearch);
void EndingBslCrashingVblank(void);
void EndingShipFrontViewVblank(void);
u8 EndingGetPositionAndSlotOfOamByType(EndingBslCrashingOamType type, s16* pXPosition, s16* pYPosition);
void EndingProcessOam_Empty(struct SpecialCutsceneOam* pOam);
void EndingMonologueInit(void);
void EndingAdamConversationInit(void);
void EndingAnimalsInit(void);
boolu32 EndingInShipProcess(void);
boolu32 EndingInShip(void);
void EndingProcessMonologueCursor(struct SpecialCutsceneOam* pOam);
void unk_969e0(struct SpecialCutsceneOam* pOam);
void EndingProcessSr388RadarView(struct SpecialCutsceneOam* pOam);
void EndingProcessSamusViewRadarView(struct SpecialCutsceneOam* pOam);
void unk_96a70(struct SpecialCutsceneOam* pOam);
void EndingProcessAdamTextCursor(struct SpecialCutsceneOam* pOam);
void EndingProcessAdamPanel(struct SpecialCutsceneOam* pOam);
void EndingProcessAdamIcon(struct SpecialCutsceneOam* pOam);
void EndingProcessAnimalsScrolling(struct SpecialCutsceneOam* pOam);
void unk_96f00(struct SpecialCutsceneOam* pOam);
u8 EndingDialogueSetupOam(u8 type, s16 xPosition, s16 yPosition, u8 descendingSearch);
void EndingMonologueVblank(void);
void EndingConversationAndAnimalsVblank(void);
u8 EndingGetPositionAndSlotOfOamByType_2(u8 type, s16* pXPosition, s16* pYPosition);
void unk_97418(struct SpecialCutsceneOam* pOam);


#endif /* ENDING_CUTSCENE_H */
