#include "connection.h"
#include "globals.h"
#include "macros.h"

#include "data/connection_data.h"

#include "constants/connection.h"

#include "structs/bg_clip.h"
#include "structs/block.h"
#include "structs/color_effects.h"
#include "structs/connection.h"
#include "structs/event.h"
#include "structs/samus.h"

extern const struct Door* sAreaDoorPointers[AREA_END];

/**
 * @brief 69184 | 1f8 | Tries to find a door
 * 
 * @param yPosition Y position
 * @param xPosition X position
 * @return u32 bool, found door
 */
u32 ConnectionCheckEnterDoor(u16 yPosition, u16 xPosition)
{
    const struct Door* pDoor;
    u8 foundDoor;
    s32 found;
    s32 door;
    s32 i;

    found = FALSE;

    if (gSubGameMode1 != SUB_GAME_MODE_PLAYING)
        return;

    pDoor = sAreaDoorPointers[gCurrentArea];

    foundDoor = FALSE;

    for (i = 0; pDoor->type != DOOR_TYPE_NONE; pDoor++, i++)
    {
        if (pDoor->srcRoom != gCurrentRoom)
            continue;

        if ((pDoor->type & DOOR_TYPE_NO_FLAGS) <= (DOOR_TYPE_NONE | DOOR_TYPE_AREA_CONNECTION))
            continue;

        if (pDoor->xStart <= xPosition && xPosition <= pDoor->xEnd && pDoor->yStart <= yPosition && yPosition <= pDoor->yEnd)
        {
            gDoorPositionStart.x = 0;
            gDoorPositionStart.y = 0;

            if (pDoor->type & DOOR_TYPE_LOAD_EVENT_BASED_ROOM)
            {
                i = ConnectionFindEventBasedDoor(i);

                if (i != UCHAR_MAX)
                    gLastDoorUsed = i;
                else
                    gLastDoorUsed = pDoor->dstDoor;
            }
            else
            {
                gLastDoorUsed = pDoor->dstDoor;
            }

            gSubGameMode1 = SUB_GAME_MODE_LOADING_ROOM;

            if ((pDoor->type & DOOR_TYPE_NO_FLAGS) >= DOOR_TYPE_OPEN_HATCH)
            {
                if (pDoor->xStart > SUB_PIXEL_TO_BLOCK(gBg1XPosition) + (s32)(SCREEN_SIZE_X_BLOCKS / 1.75f))
                    gDoorPositionStart.x = 1;

                gDoorPositionStart.y = pDoor->yStart;
                gSamusDoorPositionOffset = BLOCK_TO_SUB_PIXEL(pDoor->yEnd + 1) - gSamusData.yPosition - 1;
            }
            else
            {
                gSamusDoorPositionOffset = 0;
            }

            ConnectionProcessDoorType(pDoor->type);

            for (i = 0; i < ARRAY_SIZE(gHatchData); i++)
            {
                gHatchData[i].unk_1_3 = 0;

                if (!gHatchData[i].exists)
                    continue;

                if (gHatchData[i].facingRight)
                    found = -1;
                else
                    found = 1;

                found += gHatchData[i].xPosition;

                if (found == pDoor->xStart && pDoor->yStart >= gHatchData[i].yPosition && pDoor->yStart <= gHatchData[i].yPosition + 3)
                {
                    gHatchData[i].currentAnimation = 7;
                }
            }

            found = TRUE;

            pDoor = sAreaDoorPointers[gCurrentArea];
            pDoor = &pDoor[gLastDoorUsed];

            i = EventCheckPlayCutsceneDuringTransition(pDoor->srcRoom);

            if (i != 0x0)
            {
                gColorFading.type = 0x2;

                if (i == 0x2)
                {
                    gSubGameMode1 = SUB_GAME_MODE_SA_X_ELEVATOR;
                    found = FALSE;
                }
                else if (i == 0x3)
                {
                    gColorFading.type = 0xA;
                }
            }

            RoomEffectSetCurrentNavigationRoom(pDoor->srcRoom);
            PlayRoomMusicTrack(gCurrentArea, pDoor->srcRoom);
            break;
        }
    }

    return found;
}

/**
 * @brief 6937c | 14c | Tries to find an area connection
 * 
 * @param yPosition Y position
 * @param xPosition X position
 * @return u32 bool, found transition
 */
u32 ConnectionCheckAreaConnection(u16 yPosition, u16 xPosition)
{
    const struct Door* pDoor;
    u8 foundDoor;
    s32 door;
    s32 i;

    if (gSubGameMode1 != SUB_GAME_MODE_PLAYING)
        return FALSE;

    pDoor = sAreaDoorPointers[gCurrentArea];

    foundDoor = 0;

    for (i = 0; pDoor->type != DOOR_TYPE_NONE; pDoor++, i++)
    {
        if (pDoor->srcRoom != gCurrentRoom)
            continue;

        if ((pDoor->type & DOOR_TYPE_NO_FLAGS) != (DOOR_TYPE_NONE | DOOR_TYPE_AREA_CONNECTION))
            continue;

        if (pDoor->xStart <= xPosition && xPosition <= pDoor->xEnd && pDoor->yStart <= yPosition && yPosition <= pDoor->yEnd)
        {
            door = i;
            gLastDoorUsed = pDoor->dstDoor;
            foundDoor = 1;
            break;
        }
    }

    if (!foundDoor)
        return FALSE;

    for (i = 0; sAreaConnections[i][AREA_CONNECTION_FIELD_SOURCE_AREA] != UCHAR_MAX; i++)
    {
        if (sAreaConnections[i][AREA_CONNECTION_FIELD_SOURCE_AREA] != gCurrentArea)
            continue;

        if (sAreaConnections[i][AREA_CONNECTION_FIELD_SOURCE_DOOR] == door)
        {
            gCurrentArea = sAreaConnections[i][AREA_CONNECTION_FIELD_DESTINATION_AREA];
            foundDoor = 2;
            break;
        }
    }

    if (foundDoor != 2)
    {
        gLastDoorUsed = 0;
        return FALSE;
    }

    gSubGameMode1 = SUB_GAME_MODE_LOADING_ROOM;

    StartColorFading(0x6);
    unk_6cf0c();

    pDoor = sAreaDoorPointers[gCurrentArea];
    pDoor = &pDoor[gLastDoorUsed];

    if (EventCheckPlayCutsceneDuringTransition(pDoor->srcRoom))
        gColorFading.type = 0x2;

    RoomEffectSetCurrentNavigationRoom(pDoor->srcRoom);
    PlayRoomMusicTrack(gCurrentArea, pDoor->srcRoom);
    return TRUE;
}

/**
 * @brief 694c8 | 40 | Processes a door type
 * 
 * @param type Door type
 */
void ConnectionProcessDoorType(u8 type)
{
    u8 transition;

    switch (type & DOOR_TYPE_NO_FLAGS)
    {
        case DOOR_TYPE_NO_HATCH:
            transition = 0x6;
            break;

        default:
            if (!gSkipDoorTransition)
                transition = 0x4;
            else
                transition = 0x6;

            gWhichBgPositionIsWrittenToBg3Ofs = 4;
    }

    unk_6cf0c();
    StartColorFading(transition);
}

/**
 * @brief 69508 | 64 | Tries to find an event based connection for a door
 * 
 * @param srcDoor Source door
 * @return u32 Destination door
 */
u32 ConnectionFindEventBasedDoor(u8 srcDoor)
{
    s32 i;

    for (i = ARRAY_SIZE(sEventBasedConnections) - 1; i >= 0; i--)
    {
        // Check area
        if (gCurrentArea != sEventBasedConnections[i][EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA])
            continue;

        // Check correct door
        if (srcDoor != sEventBasedConnections[i][EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR])
            continue;

        // Check on or after event
        if (gEventCounter >= sEventBasedConnections[i][EVENT_BASED_CONNECTION_FIELD_EVENT])
            return sEventBasedConnections[i][EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR];
    }

    return UCHAR_MAX;
}

/**
 * @brief 6956c | 48 | Unused function (related to make solid blocks)
 * 
 * @param value Clipdata value
 */
void unk_6956c(u16 value)
{
    u16* pMSB;
    s32 i;

    pMSB = gMakeSolidBlocks;

    // BUG: i is decremented twice
    for (i = MAX_AMOUNT_OF_MAKE_SOLID_BLOCKS; i > 0; i--)
    {
        if (pMSB[--i] != 0)
        {
            SET_CLIP_BLOCK_(value, pMSB[i] >> 8, pMSB[i] & 0xFF);
        }
    }
}
