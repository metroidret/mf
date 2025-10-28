#ifndef NAVIGATION_PAD_AI_H
#define NAVIGATION_PAD_AI_H

#include "types.h"

u8 NavPadDetectSamus(void);
u8 NavPadDetectSamus_Unused(void);
void NavPadInit(void);
void NavPadIdleInit(void);
void NavPadIdle(void);
void NavPadPressingSwitch(void);
void NavPadSwitchPressed(void);
void NavPadReleasingSwitch(void);
void NavPadAfterConversationInit(void);
void NavPadAfterConversation(void);
void NavPadUsingConsole(void);
void NavPadStartConversation(void);
void NavConsoleInit(void);
void NavConsoleIdle(void);
void NavConsoleScreenInit(void);
void NavConsoleScreenIdle(void);
void NavScreenInit(void);
void NavScreenTurningOn(void);
void NavScreenIdle(void);
void NavScreenTurningOff(void);
void NavPad(void);
void NavConsole(void);
void NavConsoleScreen(void);
void NavScreen(void);

#endif /* NAVIGATION_PAD_AI_H */
