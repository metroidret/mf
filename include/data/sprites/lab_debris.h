#ifndef LAB_DEBRIS_DATA_H
#define LAB_DEBRIS_DATA_H

#include "types.h"
#include "oam.h"
#include "gba/memory.h"

extern const u32 sLabDebrisGfx[512 * 1];
extern const u16 sLabDebrisPal[PAL_ROW * 1];

extern const struct FrameData sLabDebrisOam_Left[2];
extern const struct FrameData sLabDebrisOam_Middle[2];
extern const struct FrameData sLabDebrisOam_Right[2];

#endif /* LAB_DEBRIS_DATA_H */
