#include "types.h"
#include "globals.h"

#include "constants/samus.h"

#include "structs/power_bomb.h"
#include "structs/samus.h"
#include "structs/demo.h"

/**
 * @brief 68870 | 104 | Processes a pause button press
 * 
 * @return u32 bool, doing something
 */
u32 ProcessPauseButtonPress(void)
{
    u32 doingSomething;
    u32 fade;

    doingSomething = TRUE;
    
    if (gPreventMovementTimer || (gCurrentPowerBomb.animationState | gCurrentPowerBomb.powerBombPlaced) || gDisablePauseFlag)
        doingSomething = FALSE;
    
    switch (gSamusData.pose)
    {
        case SPOSE_ON_SAVE_PAD:
        case SPOSE_ON_RECHARGE_OR_SECURITY_PAD:
        case SPOSE_TURNING_AROUND_TO_RECHARGE_OR_UNLOCK_DOORS:
        case SPOSE_UNLOCKING_SECURITY:
        case SPOSE_SAVING:
        case SPOSE_ON_NAVIGATION_PAD:
        case SPOSE_DOWNLOADING_ABILITY:
        case SPOSE_UNLOCKING_HABITATIONS_DECK:
        case SPOSE_LOADING_SAVE:
        case SPOSE_DYING:
            doingSomething = FALSE;
    }

    if (doingSomething == TRUE) // == TRUE is necessary for match
    {
        if (gDemoState)
        {
            if (gButtonInput)
                fade = 14;
            else 
                fade = 16; 
        }
        else
        {
            LowerMusicVolume();
            fade = 2;
        }

        StartColorFading(fade);
    }

    return doingSomething;
}