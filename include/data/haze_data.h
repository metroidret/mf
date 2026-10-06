#ifndef HAZE_DATA_H
#define HAZE_DATA_H

#include "types.h"
#include "structs/haze.h"

extern const u8 sHaze_3c94cc[4];
extern const s8 sEndingSamusPosingSineTable[128];

extern const s8 sHaze_Bg3_StrongEffect[48];
extern const s8 sHaze_Bg3Y[65][32];
extern const s8 sHaze_3c9da0[32];
extern const s8 sHaze_3c9dc0[16];

extern const s16* const sHaze_PowerBomb_WindowValuesPointers[161];

extern const s8 sHaze_3e3518[15][16];
extern const s8 sHaze_Bg3Bg2Bg1[9][32];
extern const s8 sHaze_Bg3_WeakOutside[16];
extern const s8 sHaze_Bg_WeakOutside[32];
extern const u8 sHaze_3e3758[2][2];

extern const struct HazeLoop sHazeLoop_Empty;

#endif /* HAZE_DATA_H */
