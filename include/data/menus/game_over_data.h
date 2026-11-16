#ifndef GAME_OVER_DATA_H
#define GAME_OVER_DATA_H

#include "types.h"

#include "gba/memory.h"

extern const u8 sGameOverOamXFlipOffsets[12];

extern const u32 sGameOverBgGfx[5651];
extern const u32 sGameOverObjGfx[184];
extern const u32 sGameOverTextGfx_English[438];
extern const u32 sGameOverTextGfx_German[446];
extern const u32 sGameOverTextGfx_French[504];
extern const u32 sGameOverTextGfx_Italian[489];
extern const u32 sGameOverTextGfx_Spanish[475];

extern const struct FrameData sGameOverSamusHelmetOam_Idle[5];
extern const struct FrameData sGameOverSamusHelmetOam_Turning[9];

extern const u16 sGameOverBgPal[16 * PAL_ROW];
extern const u16 sGameOverObjPal[16 * PAL_ROW];

extern const u32 sGameOverBgTilemap[369];
extern const u32 sGameOverTextTilemap[193];


#endif /* GAME_OVER_DATA_H */
