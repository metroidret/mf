#ifndef FROZEN_RIDLEY_DATA_H
#define FROZEN_RIDLEY_DATA_H

#include "types.h"
#include "oam.h"

extern const s16 sFrozenRidleyXFlyingAwayYMovement[51];

extern const u32 sFrozenRidleyGfx[2 * 512];
extern const u16 sFrozenRidleyPal[2 * 16];

extern const struct FrameData sFrozenRidleyOam_Idle[2];
extern const struct FrameData sFrozenRidleyOam_OpeningEye[7];
extern const struct FrameData sFrozenRidleyOam_ClosingEye[4];
extern const struct FrameData sFrozenRidleyOam_Crumbling[10];
extern const struct FrameData sFrozenRidleyOam_Crumbled[2];

#endif /* FROZEN_RIDLEY_DATA_H */
