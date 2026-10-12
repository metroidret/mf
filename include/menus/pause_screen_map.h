#ifndef PAUSE_SCREEN_MAP_H
#define PAUSE_SCREEN_MAP_H

#include "types.h"

void PauseScreenMapHandler(void);
void PauseScreenMapSetSamusHeadPosition(void);
void MinimapSetVisitedTilesAndCollectedItems(u8 area);
void MinimapSetVisitedTiles(u8 area);
void MinimapSetCollectedItems(u8 area);
void MinimapCheckUpdateVisitedTile(void);
void unk_75988(boolu8 arg0);
void MinimapUpdateForCollectedItem(u8 xPosition, u8 yPosition);
s32 MinimapCheckIsTileVisited(u8 xPosition, u8 yPosition);
void PauseScreenMapCountTanks(void);
void PauseScreenMapDrawIgtAndTanks(boolu8 arg0);
bools32 PauseScreenMapDownload(void);

#endif /* PAUSE_SCREEN_MAP_H */
