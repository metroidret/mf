#include "status_screen.h"
#include "globals.h"
#include "types.h"

#include "constants/samus.h"
#include "constants/status_screen.h"

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
    StatusScreenDrawBeamOrSuit(BEAM_UPGRADES, gEquipment.beamStatus); // draws the beam box
    StatusScreenDrawMissileOrBomb(MISSILE_UPGRADES, gEquipment.weaponsStatus); // draws the missile box
    StatusScreenDrawBeamOrSuit(SUIT_UPGRADES, gEquipment.suitMiscStatus); // draws the suit box
    StatusScreenDrawMissileOrBomb(BOMB_UPGRADES, gEquipment.weaponsStatus); // draws the bomb box
    StatusScreenDrawMisc(MISC_UPGRADES, gEquipment.suitMiscStatus); // draws the misc box
    StatusScreenDrawNumber(ENERGY_CURRENT, gEquipment.currentEnergy, 6, FALSE);
    StatusScreenDrawNumber(ENERGY_MAX, gEquipment.maxEnergy, 3, TRUE);
    if (gEquipment.weaponsStatus & MBF_MISSILES)
    {
        StatusScreenDrawNumber(MISSILES_CURRENT, gEquipment.currentMissiles, 6, FALSE);
        StatusScreenDrawNumber(MISSILES_MAX, gEquipment.maxMissiles, 3, TRUE);
    } 
    else
    {
        StatusScreenRemoveAmmoHeader(1);
    }
    if ((gEquipment.weaponsStatus & (MBF_BOMBS | MBF_POWER_BOMBS)) == (MBF_BOMBS | MBF_POWER_BOMBS))
    {
        StatusScreenDrawNumber(POWERBOMBS_CURRENT, gEquipment.currentPowerBombs, 6, FALSE);
        StatusScreenDrawNumber(POWERBOMBS_MAX, gEquipment.maxPowerBombs, 3, TRUE);
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