#include "types.h"
#include "structs/in_game_timer.h"

/**
 * @brief 68660 | 80 | Updates the in game timer
 * 
 */
void InGameTimerUpdate(void) 
{
    if (gMaxInGameTimeFlag)
        return;

    gInGameTimer.frames++;

    while (gInGameTimer.frames >= SIMULATED_FPS)
    {
        gInGameTimer.frames = 0;
        gInGameTimer.seconds++;

        if (gInGameTimer.seconds < 60)
            break;

        gInGameTimer.seconds = 0;
        gInGameTimer.minutes++;

        if (gInGameTimer.minutes < 60)
            break;

        gInGameTimer.minutes = 0;

        if (gInGameTimer.hours < 100)
            gInGameTimer.hours++;

        gInGameTimer.frames++;
    }

    if (gInGameTimer.hours > 99)
    {
        gMaxInGameTimeFlag = TRUE;
        gInGameTimer.hours = 99;
        gInGameTimer.minutes = 59;
        gInGameTimer.seconds = 59;
        gInGameTimer.frames = 59;
    }
}