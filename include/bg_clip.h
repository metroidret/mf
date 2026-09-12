#ifndef BG_CLIP_H
#define BG_CLIP_H

#include "types.h"

// TODO: Add remaining functions

void BgClipSetBg1BlockValue(u16 value, u16 yPosition, u16 xPosition);
void BgClipSetBg1BlockValueCommon(u16 value, u16 yPosition, u16 xPosition);
void BgClipSetBg1TilemapValue(u16 value, u16 yPosition, u16 xPosition);

#endif /* BG_CLIP_H */
