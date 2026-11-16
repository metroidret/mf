#ifndef GAME_OVER_DATA_H
#define GAME_OVER_DATA_H

#include "types.h"

#include "gba/memory.h"

extern const u8 sData_734220[12];

extern const u32 sGameOverBgGfx[5651];
extern const u32 sGameOverObjGfx[184];

extern const struct FrameData sOam_73c274[5];
extern const struct FrameData sOam_73c29c[9];

extern const u16 sGameOverBgPal[16 * PAL_ROW];
extern const u16 sGameOverObjPal[16 * PAL_ROW];

extern const u32 sGameOverBgTilemap[369];
extern const u32 sGameOverTextTilemap[193];


#endif /* GAME_OVER_DATA_H */
