#ifndef HUD_DATA_H
#define HUD_DATA_H

#include "types.h"
#include "oam.h"
#include "macros.h"

extern const u16 sCommonSpritesPal[6 * 16];
extern const u8 sCommonSpritesGfx[14 * 32 * 32];

extern const u8 sMissileIconGfx[4 * 32];
extern const u8 sPowerBombIconGfx[4 * 32];
extern const u8 sAmmoDigitsGfx[36 * 32];
extern const u8 sEnergyDigitsGfx[10 * 32];
extern const u8 sEnergyTanksGfx_Full[5 * 256];
extern const u8 sEnergyTanksGfx_Empty[11 * 256];
extern const u8 sEnergyTankGfx_OneFull[1 * 32];
extern const u8 sEnergyTankGfx_OneFullOneEmpty[1 * 32];

extern const u16 sEscapeDigitsPal[3 * 16];
extern const u8 sEscapeDigitsGfx[2048];
extern const u16 sEscapeDigitsOam[OAM_DATA_SIZE(8)];
extern const struct FrameData sEscapeTimerFrameData[2];

#endif /* HUD_DATA_H */
