#ifndef MONOLOGUE_CUTSCENE_H
#define MONOLOGUE_CUTSCENE_H

#include "macros.h"

#include "structs/monologue.h"

MAKE_ENUM(u8, ElevatorMonologueOamType) {
	ELEVATOR_MONOLOGUE_OAM_TYPE_NONE,
	ELEVATOR_MONOLOGUE_OAM_TYPE_CURSOR,
	ELEVATOR_MONOLOGUE_OAM_TYPE_SAMUS,
	ELEVATOR_MONOLOGUE_OAM_TYPE_SAMUS_OBJ_WINDOW,
	ELEVATOR_MONOLOGUE_OAM_TYPE_SCROLLER_UP,
	ELEVATOR_MONOLOGUE_OAM_TYPE_SCROLLER_DOWN
};

MAKE_ENUM(u8, InternalMonologueOamType) {
	INTERNAL_MONOLOGUE_OAM_TYPE_NONE,
	INTERNAL_MONOLOGUE_OAM_TYPE_CURSOR
};

MAKE_ENUM(u8, FederationMonologueOamType) {
	FEDERATION_MONOLOGUE_OAM_TYPE_NONE,
	FEDERATION_MONOLOGUE_OAM_TYPE_CURSOR
};

boolu32 CutsceneHandler(void);
void CutsceneInit(void);
void CutsceneVBlank(void);
void CutsceneInitVBlank(void);
boolu32 CutsceneProcess(void);
boolu32 CutsceneElevatorMonologue(boolu8 movingDown);
void CutsceneElevatorMonologueInit(boolu8 movingDown);
boolu32 CutsceneElevatorMonologueProcess(void);
u8 CutsceneElevatorMonologueSetupOam(ElevatorMonologueOamType type, s16 xPosition, s16 yPosition);
void CutsceneProcessElevatorScrollingUp(struct MonologueOam* pOam);
void CutsceneProcessElevatorScrollingDown(struct MonologueOam* pOam);
void CutsceneElevatorMonologueVBlank(void);
void CutsceneElevatorMonologueInitVBlank(void);
boolu32 CutsceneInternalMonologue(u8 arg0);
void CutsceneInternalMonologueInit(u8 arg0);
boolu32 CutsceneInternalMonologueProcess(void);
u8 CutsceneInternalMonologueSetupOam(InternalMonologueOamType type, s16 xPosition, s16 yPosition);
void CutsceneInternalMonologueVBlank(void);
void unk_9a63c(void);
boolu32 CutsceneFederationMonologue(u8 arg0);
void CutsceneFederationMonologueInit(u8 arg0);
boolu32 CutsceneFederationMonologueProcess(void);
u8 CutsceneFederationMonologueSetupOam(FederationMonologueOamType type, s16 xPosition, s16 yPosition);
void CutsceneFederationMonologueVBlank(void);
void CutsceneFederationMonologueInitVBlank(void);

#endif /* MONOLOGUE_CUTSCENE_H */
