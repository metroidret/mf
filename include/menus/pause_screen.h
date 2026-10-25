#ifndef PAUSE_SCREEN_H
#define PAUSE_SCREEN_H

#include "types.h"

s32 PauseScreenHandler(void);
void PauseScreenVBlank(void);
void PauseScreenVBlank_Unused(void);
void PauseScreenInitVBlank(void);
bools32 PauseScreenInit(void);
void MinimapGetData(u8 index, void* dst);
bools32 PauseScreenCallCurrentHandler(void);
void PauseDebugMoveCursor(void);
bools32 PauseScreenMoveBackgroundToXPosition(u8 bg, u16 target);
bools32 PauseScreenMoveBackgroundToYPosition(u8 bg, u16 target);
void PauseDebugSetWindow(void);
bools32 PauseDebugScreenAppearing(void);
bools32 PauseDebugScreenDisappearing(void);
bools32 PauseScreenEasySleepMenuInit(void);
bools32 PauseScreenEasySleepMenuQuit(void);
void PauseScreenUpdateObjectiveTextBox(u8 arg0);
void PauseScreenMapUpdateArrowsAndBlinkingSquare(void);
void PauseScreenMapDrawSpecialOam(u8 action);
void PauseScreenSetupOam(void);
void PauseScreenProcessOam(void);
void CheckForMaintainedInput(void);
void NavConversationSetTopTextBoxOam(u8 state);
void NavConversationSetBottomTextBoxOam(u8 state);
void NavConversationUpdateTopTextBoxOam(void);
void NavConversationUpdateBottomTextBoxOam(void);

#endif /* PAUSE_SCREEN_H */
