#include "status_screen.h"
#include "globals.h"
#include "types.h"

#include "constants/samus.h"
#include "constants/status_screen.h"

#include "gba/keys.h"

#include "structs/samus.h"

/**
 * @brief 7e678 | 34 | Handler for the status screen
 * 
 */
void StatusScreenHandler(void)
{
    if ((gChangedInput & (KEY_B | KEY_L | KEY_R)) && !gNonGameplayRam.pauseScreen.pauseDebugEditingValue) 
    {
        gNonGameplayRam.pauseScreen.unk_28 = 7;
        gNonGameplayRam.pauseScreen.timer = gNonGameplayRam.pauseScreen.pauseDebugEditingValue;
        gNonGameplayRam.pauseScreen.pauseDebugEditingValue = gNonGameplayRam.pauseScreen.pauseDebugEditingValue;
    }
}

/**
 * @brief 7e6ac | a8 | Draws everything on the status screen menu
 * 
 */
void StatusScreenDrawEverything(void)
{
    StatusScreenDrawBeamOrSuit(STATUS_SECTION_BEAM, gEquipment.beamStatus);
    StatusScreenDrawMissileOrBomb(STATUS_SECTION_MISSILE, gEquipment.weaponsStatus);
    StatusScreenDrawBeamOrSuit(STATUS_SECTION_SUIT, gEquipment.suitMiscStatus);
    StatusScreenDrawMissileOrBomb(STATUS_SECTION_BOMB, gEquipment.weaponsStatus);
    StatusScreenDrawMisc(STATUS_SECTION_MISC, gEquipment.suitMiscStatus);
    StatusScreenDrawNumber(STATUS_SECTION_ENERGY_CURRENT, gEquipment.currentEnergy, 6, FALSE);
    StatusScreenDrawNumber(STATUS_SECTION_ENERGY_MAX, gEquipment.maxEnergy, 3, TRUE);

    if (gEquipment.weaponsStatus & MBF_MISSILES)
    {
        StatusScreenDrawNumber(STATUS_SECTION_MISSILES_CURRENT, gEquipment.currentMissiles, 6, FALSE);
        StatusScreenDrawNumber(STATUS_SECTION_MISSILES_MAX, gEquipment.maxMissiles, 3, TRUE);
    } 
    else
    {
        StatusScreenRemoveAmmoHeader(1);
    }

    if ((gEquipment.weaponsStatus & (MBF_BOMBS | MBF_POWER_BOMBS)) == (MBF_BOMBS | MBF_POWER_BOMBS))
    {
        StatusScreenDrawNumber(STATUS_SECTION_POWER_BOMBS_CURRENT, gEquipment.currentPowerBombs, 6, FALSE);
        StatusScreenDrawNumber(STATUS_SECTION_POWER_BOMBS_MAX, gEquipment.maxPowerBombs, 3, TRUE);
        return;
    }

    StatusScreenRemoveAmmoHeader(2);
}

/**
 * @brief 7e754 | e0 | Draws a number on the status screen
 * 
 * @param section section
 * @param value value
 * @param palette palette slot
 * @param is_max bool for current vs max ammo count
 */
void StatusScreenDrawNumber(u8 section, u16 value, u8 palette, boolu8 isMax)
{

}

/**
 * @brief 7e834 | 148 | Draws the beam or suit status
 * 
 * @param section section
 * @param value suit misc status
 */
void StatusScreenDrawBeamOrSuit(u8 section, u8 value)
{

}

/**
 * @brief 7e97c | 15c | Draws the missile or bomb status
 * 
 * @param section section
 * @param value weapon status
 */
void StatusScreenDrawMissileOrBomb(u8 section, u8 value)
{

}

/**
 * @brief 7ead8 | 1b4 | Draws the misc status
 * 
 * @param section section
 * @param value misc status
 */
void StatusScreenDrawMisc(u8 section, u8 value)
{

}

/**
 * @brief 7ec8c | 94 | Removes an ammo header from the status screen
 * 
 * @param position 1 for missiles 2 for power bombs
 */
void StatusScreenRemoveAmmoHeader(u8 position)
{

}
