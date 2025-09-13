#include "transparency.h"

#include "constants/event.h"

#include "structs/event.h"

/**
 * @brief 62dd8 | 18 | Checks if the room should be dark
 * 
 */
u8 CheckRoomShouldBeDark(void)
{
    if (gEventCounter > EVENT_MORPH_BALL_ABILITY_RECOVERED)
    {
        return FALSE;
    }
        return TRUE;
}
