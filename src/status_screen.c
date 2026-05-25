#include "status_screen.h"
#include "globals.h"
#include "macros.h"

#include "constants/samus.h"
#include "constants/status_screen.h"

#include "gba/keys.h"

#include "structs/menus/pause_screen.h"
#include "structs/samus.h"

/**
 * @brief 7e678 | 38 | Status screen handler
 *
 */
void StatusScreenHandler(void)
{
    if (gChangedInput & (KEY_B | KEY_L | KEY_R) && !PAUSE_SCREEN_DATA.pauseDebugEditingValue)
    {
        PAUSE_SCREEN_DATA.unk_28 = 0x7;
        PAUSE_SCREEN_DATA.timer = 0;
        PAUSE_SCREEN_DATA.pauseDebugEditingValue = FALSE;
    }
}
