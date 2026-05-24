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

/**
 * @brief 7e754 | e0 | Draw a decimal number to a status-screen field
 *
 * @param section Which status-screen field (indexes sBlob_58217b_58225c)
 * @param value The number to draw
 * @param palette OAM palette index (low 4 bits of the tile attribute high nybble)
 * @param isMax When true, leading zeros render as blank tiles instead of dashes
 */
void StatusScreenDrawNumber(u8 section, u16 value, u8 palette, boolu8 isMax)
{
    register u16 *dst asm("r9");
    const u8 *base;
    const u8 *base2;
    s32 sec5;
    s32 yTile;
    s32 startX;
    s32 i;
    s32 width;
    s32 hasNonZero;
    s32 tile;
    s32 divisor;

    base = &sBlob_58217b_58225c[1];
    sec5 = section * 5;

    yTile = *(sec5 + base) << 5;
    base2 = base + 2;
    startX = *(base2 + sec5);
    dst = (u16 *)0x0600C800 + (yTile + startX);
    base += 3;
    width = *(sec5 + base) - startX;

    divisor = sPauseDebugNumbersIncrementValues[width];
    width++;
    hasNonZero = 0;
    i = 0;

    while (divisor > 0)
    {
        tile = (value / divisor) % 10;
        if (tile == 0)
        {
            if (hasNonZero == 0)
            {
                tile = 0x8c;
                if (isMax)
                    tile = 0;
            }
            else
            {
                tile = 0x80;
            }
        }
        else
        {
            hasNonZero = 1;
            tile += 0x80;
        }

        if (tile != 0)
            dst[i] = (palette << 12) | tile;
        else
            i--;

        divisor /= 10;
        i++;
    }

    if (width != i)
    {
        u16 *p;
        tile = (palette << 12) | 0x8c;
        p = &dst[i];
        do {
            *p = tile;
            p++;
            i++;
        } while (width != i);
    }
}
