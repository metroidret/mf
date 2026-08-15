#ifndef ROOM_H
#define ROOM_H

#include "types.h"

void RoomLoad(void);
void RoomLoadTileset(void);
void RoomLoadEntry(void);
void RoomLoadBackgrounds(void);
void RoomRemoveNeverReformBlocksAndCollectedTanks(void);
void RoomReset(void);
void RoomLoadScrollsAndEventBasedEffects(void);
void RoomLoadDoors(void);
u32 RoomGetClosedNavigationHatches(void);
void RoomSetInitialTilemap(u8 bg);
u32 RoomRleDecompress(u8 type, const u8* src, u8* dst);
void unk_659a0(void);
void unk_659e0(void);
void RoomCheckElevatorRideEnded(void);
void unk_65a1c(void);
void RoomUpdateAnimatedGraphicsAndPalette(void);
void RoomUpdateHatchFlashingAnimation(void);
void RoomUpdate(void);
void RoomUpdateBackgroundPositions(void);
void RoomUpdateVerticalTilemap(s32 offset);
void RoomCopyVerticalTilemap(void);
void RoomUpdateHorizontalTilemap(s32 offset);
void RoomCopyHorizontalTilemap(void);

void WaitForDma3(void);

#endif /* ROOM_H */
