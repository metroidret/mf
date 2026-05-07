#include "oam_id.h"
#include "globals.h"

/**
 * @brief 7486c | 24 | Updates the OAM ID of menu OAM data and resets its animation
 * 
 */
void UpdateMenuOamDataId(u8 oamIndex, u8 oamId)
{    
    PAUSE_SCREEN_DATA.oam[oamIndex].oamId = oamId;
    PAUSE_SCREEN_DATA.oam[oamIndex].animationDurationCounter = 0;
    PAUSE_SCREEN_DATA.oam[oamIndex].currentAnimationFrame = 0;
}
