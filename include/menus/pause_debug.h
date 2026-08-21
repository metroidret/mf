#ifndef PAUSE_DEBUG_H
#define PAUSE_DEBUG_H

#include "types.h"

void PauseDebugHandler(void);
u32 PauseDebugModifyValues(void);
void PauseDebugDrawEventText(u8 event);
void PauseDebugDrawSection(u8 section);
void SetAbilityCount(u8 abilityCount);
u32 PauseDebugModifiyAbilityCount(u8 cursorX);
void PauseDebugDrawAbilityCount(void);
void PauseDebugDrawMenuAndDoor(void);
void PauseDebugDrawIgt(void);
void unk_7e224(void);
u32 PauseDebugModifyHealthAndAmmo(u8 cursorX, u8 section);
void PauseDebugDrawHealthAmmoAndEvent(u8 section);
void PauseDebugDrawNumber(u16 value, u8 section);
void PauseDebugCheckSetMaxHealthOrAmmo(void);
void PauseDebugDrawEverything(void);
void PauseDebugSetupCursor(void);

#endif /* PAUSE_DEBUG_H */
