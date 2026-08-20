#ifndef POWAMP_DATA_H
#define POWAMP_DATA_H

#include "types.h"
#include "oam.h"
#include "gba/memory.h"

extern const u32 sPowampGfx[512 * 1];
extern const u16 sPowampPal[PAL_ROW * 1];

extern const struct FrameData sPowampOam_Idle[];
extern const struct FrameData sPowampOam_Extended[];
extern const struct FrameData sPowampOam_Extending[];
extern const struct FrameData sPowampOam_Retracting[];

#endif /* POWAMP_DATA_H */
