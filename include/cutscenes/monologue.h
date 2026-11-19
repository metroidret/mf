#ifndef MONOLOGUE_CUTSCENE_H
#define MONOLOGUE_CUTSCENE_H

#include "types.h"

#include "structs/monologue.h"

boolu32 CutsceneHandler(void);
void CutsceneInit(void);
void CutsceneVblank(void);
void unk_99af8(void);
boolu32 CutsceneProcess(void);
boolu32 CutsceneElevatorMonologue(u8 arg0);
void CutsceneElevatorMonologueInit(u8 arg0);
boolu32 CutsceneElevatorMonologueProcess(void);
u8 CutsceneElevatorMonologueSetupOam(u8 type, s16 xPosition, s16 yPosition);
void CutsceneProcessElevatorScrolling(struct MonologueOam* pOam);
void unk_9a1a8(struct MonologueOam* pOam);
void CutsceneElevatorMonologueVblank(void);
void unk_9a31c(void);
boolu32 CutsceneInternalMonologue(u8 arg0);
void CutsceneInternalMonologueInit(u8 arg0);
boolu32 CutsceneInternalMonologueProcess(void);
u8 CutsceneInternalMonologueSetupOam(u8 type, s16 xPosition, s16 yPosition);
void CutsceneInternalMonologueVblank(void);
void unk_9a63c(void);
boolu32 CutsceneFederationMonologue(u8 arg0);
void CutsceneFederationMonologueInit(u8 arg0);
boolu32 CutsceneFederationMonologueProcess(void);
u8 CutsceneFederationMonologueSetupOam(u8 type, s16 xPosition, s16 yPosition);
void CutsceneFederationMonologueVblank(void);
void unk_9a99c(void);

#endif /* MONOLOGUE_CUTSCENE_H */
