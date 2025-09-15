#include "transparency.h"

#include "constants/event.h"

#include "structs/event.h"

/**
 * @brief 62dd8 | 18 | Checks if the room should be dark
 * 
 */
u8 CheckRoomShouldBeDark(void)
{
    return gEventCounter <= EVENT_SA_X_ELEVATOR_CUTSCENE_ENDS;
}
