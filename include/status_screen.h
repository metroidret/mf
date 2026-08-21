#ifndef STATUSSCREEN_H
#define STATUSSCREEN_H

#include "types.h"

void StatusScreenHandler(void);
void StatusScreenDrawEverything(void);
void StatusScreenDrawNumber(u8 section, u16 value, u8 palette, boolu8 isMax);
void StatusScreenDrawBeamOrSuit(u8 section, u8 value);
void StatusScreenDrawMissileOrBomb(u8 section, u8 value);
void StatusScreenDrawMisc(u8 section, u8 value);
void StatusScreenRemoveAmmoHeader(u8 position);

#endif /* STATUSSCREEN_H */
