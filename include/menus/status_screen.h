#ifndef STATUS_SCREEN_H
#define STATUS_SCREEN_H

#include "types.h"

// Forward declarations for the StatusScreen* cluster.
// Uncomment and fill in the correct signature as each function is
// decompiled into the matching .c file.
extern void StatusScreenHandler(void);
extern void StatusScreenDrawEverything(void);
extern void StatusScreenDrawNumber(u8 section, u16 value, u8 palette, boolu8 isMax);
extern void StatusScreenDrawBeamOrSuit(u8 section, u8 value);
extern void StatusScreenDrawMissileOrBomb(u8 section, u8 value);
extern void StatusScreenDrawMisc(u8 section, u8 value);
extern void StatusScreenRemoveAmmoHeader(u8 position);

#endif // STATUS_SCREEN_H
