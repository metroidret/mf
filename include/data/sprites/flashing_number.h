#ifndef FLASHING_NUMBER_DATA_H
#define FLASHING_NUMBER_DATA_H

#include "oam.h"

extern const u32 sBigFlashingNumberGfx[512];
extern const u16 sBigFlashingNumberPal[1 * 16];

extern const struct FrameData sBigFlashingNumberOam_Sector1[];
extern const struct FrameData sBigFlashingNumberOam_Sector2[];
extern const struct FrameData sBigFlashingNumberOam_Sector3[];
extern const struct FrameData sBigFlashingNumberOam_Sector4[];
extern const struct FrameData sBigFlashingNumberOam_Sector5[];
extern const struct FrameData sBigFlashingNumberOam_Sector6[];

extern const u32 sFlashingNumberGfx[512];
extern const u16 sFlashingNumberPal[1 * 16];

extern const struct FrameData sFlashingNumberOam_Sector1[];
extern const struct FrameData sFlashingNumberOam_Sector2[];
extern const struct FrameData sFlashingNumberOam_Sector3[];
extern const struct FrameData sFlashingNumberOam_Sector4[];
extern const struct FrameData sFlashingNumberOam_Sector5[];
extern const struct FrameData sFlashingNumberOam_Sector6[];

#endif /* FLASHING_NUMBER_DATA_H */
