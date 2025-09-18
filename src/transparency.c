#include "transparency.h"
#include "globals.h"

#include "constants/event.h"

#include "structs/event.h"

/**
 * @brief 62db0 | 28 | Checks if the meltdown effect should be set
 * 
 * @return bool, meltdown effect should be set
 */
boolu8 CheckSetMeltdownEffect(void) 
{
    u8 setMeltdownEffect;

    setMeltdownEffect = FALSE;
    
    if (gEventCounter >= EVENT_ICE_MISSILE_DATA_DOWNLOADED &&
       gEventCounter <= EVENT_WIDE_BEAM_ABILITY_RECOVERED) 
    {
        setMeltdownEffect = TRUE;
        gCurrentEventBasedEffectCopy = EVENT_EFFECT_MELTDOWN;
    }
    
    return setMeltdownEffect;
}

/**
 * @brief 62dd8 | 18 | Checks if the room should be dark
 * 
 * @return bool, room should be dark
 */
boolu8 CheckRoomShouldBeDark(void)
{
    return gEventCounter <= EVENT_SA_X_ELEVATOR_CUTSCENE_ENDS;
}
