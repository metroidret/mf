#ifndef POWAMP_DATA_H
#define POWAMP_DATA_H

#include "types.h"
#include "oam.h"
#include "gba/memory.h"

extern const u32 sPowampGfx[512 * 1];
extern const u16 sPowampPal[PAL_ROW * 1];

extern const struct FrameData sPowampOam_Idle[4];
extern const struct FrameData sPowampOam_Extended[4];
extern const struct FrameData sPowampOam_Extending[7];
extern const struct FrameData sPowampOam_Retracting[7];
extern const struct FrameData sPowampOam_Unused_3866e8[4];
extern const struct FrameData sPowampOam_Unused_386708[2];

#endif /* POWAMP_DATA_H */
