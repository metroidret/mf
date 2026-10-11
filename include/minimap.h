#ifndef MINIMAP_H
#define MINIMAP_H

#include "types.h"

void MinimapLoadInitial(void);
void MinimapUpdate(void);
void MinimapSetTileAsExplored(void);
void MinimapCheckPositionChanged(void);
void MinimapCheckOnTransition(void);
void MinimapHudDraw(void);
void MinimapCopyTileGfx(u8** dst, u32* pTile, u8 palette);
void MinimapCopyTileXFlippedGfx(u8** dst, u32* pTile, u8 palette);
void MinimapCopyTileYFlippedGfx(u8** dst, u32* pTile, u8 palette);
void MinimapCopyTileXYFlippedGfx(u8** dst, u32* pTile, u8 palette);

// TODO: Move to menus/pause_screen_map.h
s32 MinimapCheckIsTileExplored(u8, u8);

#endif /* MINIMAP_H */
