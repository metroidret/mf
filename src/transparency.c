#include "transparency.h"
#include "globals.h"

#include "constants/event.h"

#include "structs/event.h"

/**
 * @brief 62db0 | 28 | Checks if the meltdown effect should be set
 * 
 */
u8 CheckSetMeltdownEffect(void) {
    u8 SetMeltdownEffect = FALSE;

    if ((u32) (u8) (gEventCounter - EVENT_ICE_MISSILE_DATA_DOWNLOADED) <= 2) 
    {
        SetMeltdownEffect = TRUE;
        gCurrentEventBasedEffectCopy = EVENT_EFFECT_MELTDOWN;
    }

    return SetMeltdownEffect;
}

/**
 * @brief 62dd8 | 18 | Checks if the room should be dark
 * 
 */
u8 CheckRoomShouldBeDark(void)
{
    return gEventCounter <= EVENT_SA_X_ELEVATOR_CUTSCENE_ENDS;
}
