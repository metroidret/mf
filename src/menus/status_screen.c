#include "menus/status_screen.h"

#include "menus/pause_debug.h"
#include "globals.h"
#include "gba.h"
#include "macros.h"
#include "event.h"

#include "data/menus/pause_debug.h"
#include "data/event_data.h"

#include "constants/menus/pause_debug.h"
#include "constants/connection.h"
#include "constants/samus.h"

#include "structs/menus/pause_debug.h"
#include "structs/connection.h"
#include "structs/event.h"
#include "structs/samus.h"
#include "structs/sprite.h"

/*
 * Scaffold for the StatusScreen* cluster.
 * Decompiled functions land here, one at a time, in baserom
 * address order. Each function added must also be removed from
 * the corresponding asm/disasm_*.s and verified with
 * tools/agent/compile_and_view_assembly.py before commit.
 */

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

/**
 * @brief 7e6ac | a4 | Draws every stat on the status screen
 *
 */
void StatusScreenDrawEverything(void)
{
    StatusScreenDrawBeamOrSuit(0, gEquipment.beamStatus);
    StatusScreenDrawMissileOrBomb(1, gEquipment.weaponsStatus);
    StatusScreenDrawBeamOrSuit(3, gEquipment.suitMiscStatus);
    StatusScreenDrawMissileOrBomb(2, gEquipment.weaponsStatus);
    StatusScreenDrawMisc(4, gEquipment.suitMiscStatus);

    StatusScreenDrawNumber(5, gEquipment.currentEnergy, 6, FALSE);
    StatusScreenDrawNumber(6, gEquipment.maxEnergy, 3, TRUE);

    if (gEquipment.weaponsStatus & MBF_MISSILES)
    {
        StatusScreenDrawNumber(7, gEquipment.currentMissiles, 6, FALSE);
        StatusScreenDrawNumber(8, gEquipment.maxMissiles, 3, TRUE);
    }
    else
    {
        StatusScreenRemoveAmmoHeader(1);
    }

    if ((gEquipment.weaponsStatus & (MBF_BOMBS | MBF_POWER_BOMBS)) == (MBF_BOMBS | MBF_POWER_BOMBS))
    {
        StatusScreenDrawNumber(9, gEquipment.currentPowerBombs, 6, FALSE);
        StatusScreenDrawNumber(0xa, gEquipment.maxPowerBombs, 3, TRUE);
    }
    else
    {
        StatusScreenRemoveAmmoHeader(2);
    }
}
