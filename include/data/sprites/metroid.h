#ifndef METROID_DATA_H
#define METROID_DATA_H

#include "types.h"
#include "oam.h"
#include "gba/memory.h"

extern const s16 sMetroidBackgroundFloatingYSpeeds[32];
extern const s16 sMetroidBackgroundFloatingXSpeeds[40];
extern const s16 sMetroidFloatingYSpeeds[32];
extern const s16 sMetroidFloatingXSpeeds[40];

extern const s16 sMetroidSwayingYSpeeds[64];
extern const s16 sMetroidSwayingXSpeeds[80];

extern const u32 sMetroidGfx[512 * 1];
extern const u16 sMetroidPal[PAL_ROW * 1];

extern const struct FrameData sMetroidOam_Unused_385294[5];
extern const struct FrameData sMetroidOam_Idle[5];
extern const struct FrameData sMetroidOam_Background[5];
extern const struct FrameData sMetroidOam_Unused_38530c[2];
extern const struct FrameData sMetroidOam_Unused_38531c[5];
extern const struct FrameData sMetroidOam_Unused_385344[5];
extern const struct FrameData sMetroidOam_Unused_38536c[2];

#endif /* METROID_DATA_H */
