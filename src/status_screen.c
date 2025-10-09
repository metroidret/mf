#include "status_screen.h"
#include "globals.h"
#include "types.h"

#include "constants/samus.h"

#include "gba/keys.h"

#include "structs/samus.h"

/**
 * @brief 7e678 | 34 | Subroutine for the status screen
 * 
 * 
 */
void StatusScreenSubroutine(void)
{
    if ((gChangedInput & (KEY_B | KEY_L | KEY_R)) && (gNonGameplayRam.pauseScreen.debugMenuEditingValue == 0)) 
    {
        gNonGameplayRam.pauseScreen.unk_28 = 7;
        gNonGameplayRam.pauseScreen.timer = gNonGameplayRam.pauseScreen.debugMenuEditingValue;
        gNonGameplayRam.pauseScreen.debugMenuEditingValue = gNonGameplayRam.pauseScreen.debugMenuEditingValue;
    }
}

/**
 * @brief 7e6ac | a8 | Draws everything on the status screen menu
 * 
 * 
 */
void StatusScreenDrawEverything(void)
{
    StatusScreenDrawBeamOrSuit(0, gEquipment.beamStatus); // draws the beam box
    StatusScreenDrawMissileOrBomb(1, gEquipment.weaponsStatus); // draws the missile box
    StatusScreenDrawBeamOrSuit(3, gEquipment.suitMiscStatus); // draws the suit box
    StatusScreenDrawMissileOrBomb(2, gEquipment.weaponsStatus); // draws the bomb box
    StatusScreenDrawMisc(4, gEquipment.suitMiscStatus); // draws the misc box
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
        StatusScreenDrawNumber(10, gEquipment.maxPowerBombs, 3, TRUE);
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
void StatusScreenDrawNumber(u8 section, u16 value, u8 palette, boolu8 is_max)
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