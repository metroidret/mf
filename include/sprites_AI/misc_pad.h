#ifndef MISC_PAD_AI_H
#define MISC_PAD_AI_H

#include "types.h"

void MiscPadInit(void);
void MiscPadIdleInit(void);
void MiscPadIdle(void);
void MiscPadPressingSwitch(void);
void MiscPadSwitchPressed(void);
void MiscPadReleasingSwitch(void);
void MiscPadSamusInteracting(void);
void MiscPadSpawnMessageBanner(void);
void MiscPadAfterInteraction(void);
void MiscPadInactive(void);
void MiscPadWaitForWideBeamCoreX(void);
void MiscPadConsoleInit(void);
void MiscPadConsoleIdle(void);
void MiscPad(void);
void MiscPadConsole(void);

#endif /* MISC_PAD_AI_H */
