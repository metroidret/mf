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

// FIXME temp
void Sram_QuickSave(u8);

/**
 * @brief 7d34c | 70 | Pause debug handler
 * 
 */
void PauseDebugHandler(void)
{
    if (gChangedInput & (KEY_B | KEY_L | KEY_R) && !PAUSE_SCREEN_DATA.pauseDebugEditingValue)
    {
        PAUSE_SCREEN_DATA.unk_28 = 0x7;
        PAUSE_SCREEN_DATA.timer = 0;
        PAUSE_SCREEN_DATA.pauseDebugEditingValue = FALSE;
        PAUSE_SCREEN_DATA.oam[0].oamId = 0;
        return;
    }

    if (gChangedInput != 0)
        PauseDebugModifyValues();

    if (PAUSE_SCREEN_DATA.unk_284 != gInGameTimer.minutes)
        PauseDebugDrawIgt();

    if (gInGameTimer.frames == 0)
        unk_7e224();
}

// BUG: return type should be void
/**
 * @brief 7d3bc | 778 | Handles modifying the values in the pause debug menu
 * 
 * @return u32 Nothing
 */
u32 PauseDebugModifyValues(void)
{
    s32 cursorY;
    s32 cursorX;
    s32 i;
    s32 j;
    s32 updateFlag;
    s32 editflag;
    u8 eventBackup;
    u8 ebeBackup;
    u8 ebeQueuedBackup;

    // Get cursor tile position
    cursorY = PAUSE_SCREEN_DATA.oam[0].yPosition / PAUSE_DEBUG_TILE_SIZE;
    cursorX = PAUSE_SCREEN_DATA.oam[0].xPosition / PAUSE_DEBUG_TILE_SIZE;

    updateFlag = PAUSE_DEBUG_EDIT_NONE;

    // Find which section is currently selected
    for (i = 0; i < PAUSE_DEBUG_SECTION_END; i++)
    {
        if (PAUSE_DEBUG_SECTION_INFO_TOP(i) > cursorY)
            continue;

        if (PAUSE_DEBUG_SECTION_INFO_BOTTOM(i) < cursorY)
            continue;

        if (PAUSE_DEBUG_SECTION_INFO_LEFT(i) > cursorX)
            continue;

        if (PAUSE_DEBUG_SECTION_INFO_RIGHT(i) < cursorX)
            continue;

        updateFlag = TRUE;
        break;
    }

    if (!updateFlag)
    {
        // No section selected, abort
        return;
    }

    // Check stop editing mode
    if (PAUSE_DEBUG_SECTION_INFO_SECTION(i) != PAUSE_DEBUG_SECTION_EVENT && gChangedInput & KEY_B && PAUSE_SCREEN_DATA.pauseDebugEditingValue)
    {
        // Reset cursor
        PAUSE_SCREEN_DATA.pauseDebugEditingValue = FALSE;
        UpdateMenuOamDataId(0, 0x1);

        if (PAUSE_DEBUG_SECTION_INFO_SECTION(i) == PAUSE_DEBUG_SECTION_IN_GAME_TIME)
            gMaxInGameTimeFlag = FALSE;

        return;
    }

    // Get the inner position of the cursor inside the current section
    // 0;0 is top right
    cursorY = cursorY - PAUSE_DEBUG_SECTION_INFO_TOP(i);
    cursorX = PAUSE_DEBUG_SECTION_INFO_RIGHT(i) - cursorX;

    switch (PAUSE_DEBUG_SECTION_INFO_SECTION(i))
    {
        case PAUSE_DEBUG_SECTION_BEAM:
            if (gChangedInput & KEY_A)
            {
                // Toggle selected beam and clear ability count
                gEquipment.beamStatus ^= sPauseDebugBeamFlags[cursorY];
                gAbilityCount = ABILITY_COUNT_NONE;
            }
            break;

        case PAUSE_DEBUG_SECTION_MISSILE:
            if (gChangedInput & KEY_A)
            {
                // Toggle selected missile and clear ability count
                gEquipment.weaponsStatus ^= sPauseDebugMissileFlags[cursorY];
                gAbilityCount = ABILITY_COUNT_NONE;
            }
            break;

        case PAUSE_DEBUG_SECTION_BOMB:
            if (gChangedInput & KEY_A)
            {
                // Toggle selected bomb and clear ability count
                gEquipment.weaponsStatus ^= sPauseDebugBombFlags[cursorY];
                gAbilityCount = ABILITY_COUNT_NONE;
            }
            break;

        case PAUSE_DEBUG_SECTION_SUIT:
            if (gChangedInput & KEY_A)
            {
                // Toggle selected suit and clear ability count
                gEquipment.suitMiscStatus ^= sPauseDebugSuitFlags[cursorY];
                gAbilityCount = ABILITY_COUNT_NONE;
            }
            break;

        case PAUSE_DEBUG_SECTION_MISC:
            if (gChangedInput & KEY_A)
            {
                // Toggle selected misc and clear ability count
                gEquipment.suitMiscStatus ^= sPauseDebugMiscFlags[cursorY];
                gAbilityCount = ABILITY_COUNT_NONE;
            }
            break;

        case PAUSE_DEBUG_SECTION_ENERGY_CURRENT:
        case PAUSE_DEBUG_SECTION_ENERGY_MAX:
        case PAUSE_DEBUG_SECTION_MISSILE_CURRENT:
        case PAUSE_DEBUG_SECTION_MISSILE_MAX:
        case PAUSE_DEBUG_SECTION_POWER_BOMB_CURRENT:
        case PAUSE_DEBUG_SECTION_POWER_BOMB_MAX:
            updateFlag = PAUSE_DEBUG_EDIT_NONE;

            if (gChangedInput & KEY_A)
            {
                // Set editing value
                PAUSE_SCREEN_DATA.oam[0].oamId = 0x9;
                PAUSE_SCREEN_DATA.pauseDebugEditingValue = TRUE;
            }

            if (!PAUSE_SCREEN_DATA.pauseDebugEditingValue)
                break;

            // Handle editing
            if (PauseDebugModifyHealthAndAmmo(cursorX, PAUSE_DEBUG_SECTION_INFO_SECTION(i)))
            {
                // If an edit was made, request a redraw
                updateFlag = PAUSE_DEBUG_EDIT_REDRAW_NUMBERED_SECTION;
            }
            break;

        case PAUSE_DEBUG_SECTION_ABILITY_COUNT:
            updateFlag = PAUSE_DEBUG_EDIT_NONE;

            if (gChangedInput & KEY_A)
            {
                // Set editing value
                PAUSE_SCREEN_DATA.oam[0].oamId = 0x9;
                PAUSE_SCREEN_DATA.pauseDebugEditingValue = TRUE;
            }

            if (!PAUSE_SCREEN_DATA.pauseDebugEditingValue)
                break;

            // Handle editing
            if (PauseDebugModifiyAbilityCount(cursorX))
            {
                // If an edit was made, request a of everything since this modifies the current equipment
                updateFlag = PAUSE_DEBUG_EDIT_REDRAW_ALL;
            }
            break;

        case PAUSE_DEBUG_SECTION_SECURITY:
            if (gChangedInput & KEY_A)
            {
                // Check is selecting level 0 and current level is already zero
                if (gEquipment.securityHatchLevel == SECURITY_LEVEL_END - 1 - cursorX)
                {
                    // This should result in 0xFF, or SECURITY_LEVEL_NO_HATCHES
                    gEquipment.securityHatchLevel = SECURITY_LEVEL_3 - cursorX;
                }
                else
                {
                    // Directly unlock security level
                    gEquipment.securityHatchLevel = SECURITY_LEVEL_4 - cursorX;
                }

                // Sync security hatch level
                gSecurityHatchLevel = gEquipment.securityHatchLevel;
                gPauseDebugOptions.securityHatchLevel = gSecurityHatchLevel;
            }
            break;

        case PAUSE_DEBUG_SECTION_MAP:
            if (gChangedInput & KEY_A)
            {
                // Toggle selected map
                gEquipment.downloadedMaps ^= 1 << (AREA_NORMAL_LAST - cursorX);

                // Clear previous area
                gPreviousArea = UCHAR_MAX;
            }

            // Sync downloaded maps
            gPauseDebugOptions.downloadedMaps = gEquipment.downloadedMaps;
            break;

        case PAUSE_DEBUG_SECTION_EVENT:
            updateFlag = PAUSE_DEBUG_EDIT_NONE;
            editflag = FALSE;

            if (!PAUSE_SCREEN_DATA.pauseDebugEditingValue)
            {
                if (gChangedInput & KEY_A)
                {
                    // Start edit mode
                    PAUSE_SCREEN_DATA.pauseDebugEditingValue = TRUE;
                    PAUSE_SCREEN_DATA.oam[0].oamId = 0x9;
    
                    updateFlag = PAUSE_DEBUG_EDIT_REDRAW_SECTION;

                    // Slightly crop debug menu window at the bottom to allow for the event text to be visible
                    WRITE_16(REG_WIN0V, C_16_2_8(0, SCREEN_SIZE_Y - SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE)));
                    WRITE_8(REG_WINOUT, WIN0_BG2);
    
                    // Enable text background
                    PAUSE_SCREEN_DATA.dispcnt |= DCNT_BG0;
    
                    editflag = 0x80;
                }

            }
            else
            {
                if (gChangedInput & (KEY_A | KEY_B))
                {
                    // Stop edit mode
                    PAUSE_SCREEN_DATA.pauseDebugEditingValue = FALSE;
                    UpdateMenuOamDataId(0, 0x1);

                    updateFlag = PAUSE_DEBUG_EDIT_REDRAW_SECTION;

                    // Set the debug menu window to take the entire screen again
                    WRITE_16(REG_WIN0V, C_16_2_8(0, SCREEN_SIZE_Y));
                    WRITE_8(REG_WINOUT, WIN0_BG0 | WIN0_BG2 | WIN0_OBJ | WIN0_COLOR_EFFECT);
                }
            }

            if (!PAUSE_SCREEN_DATA.pauseDebugEditingValue)
                break;

            if (!editflag)
            {
                if (gChangedInput & KEY_DOWN)
                {
                    // Increase value by powers of 10, also check and prevent overflow
                    if (gEventCounter + sPauseDebugNumbersIncrementValues[cursorX] >= EVENT_END)
                        gEventCounter = EVENT_END - 1;
                    else
                        gEventCounter += sPauseDebugNumbersIncrementValues[cursorX];

                    editflag = TRUE;
                }
                else if (gChangedInput & KEY_UP)
                {
                    // Decrease value by powers of 10, also check and prevent underflow
                    if (gEventCounter - sPauseDebugNumbersIncrementValues[cursorX] < EVENT_NONE)
                        gEventCounter = EVENT_NONE;
                    else
                        gEventCounter -= sPauseDebugNumbersIncrementValues[cursorX];

                    editflag = TRUE;
                }
                else if (gChangedInput & KEY_RIGHT)
                {
                    // Move cursor to the right
                    if (cursorX != 0)
                        PAUSE_SCREEN_DATA.oam[0].xPosition += PAUSE_DEBUG_TILE_SIZE;
                }
                else if (gChangedInput & KEY_LEFT)
                {
                    // Move cursor to the left
                    if (cursorX < 2)
                        PAUSE_SCREEN_DATA.oam[0].xPosition -= PAUSE_DEBUG_TILE_SIZE;
                }
                else
                {
                    PauseDebugCheckSetMaxHealthOrAmmo();
                }
            }

            if (!editflag)
                break;

            // Clear equipment
            gEquipment.beamStatus = 0;
            gEquipment.weaponsStatus = 0;
            gEquipment.suitMiscStatus = 0;

            // Backup event based effect
            ebeBackup = gCurrentEventBasedEffect;
            ebeQueuedBackup = gQueuedEventBasedEffect;
            editflag = gEventCounter;

            // Set every event starting from the beginning up to the current event, keeps the event sequence intact
            for (updateFlag = EVENT_NONE; updateFlag <= editflag; updateFlag++)
                EventSet(updateFlag);
            
#ifdef BUGFIX
            // Suits aren't equipped in EventSet, so equip them here
            if (gAbilityCount >= ABILITY_COUNT_VARIA_SUIT)
            {
                gEquipment.suitMiscStatus |= SMF_VARIA_SUIT;

                if (gAbilityCount >= ABILITY_COUNT_GRAVITY_SUIT)
                    gEquipment.suitMiscStatus |= SMF_GRAVITY_SUIT;
            }
#endif // BUGFIX

            // Restore event based effect
            gCurrentEventBasedEffect = ebeBackup;
            gQueuedEventBasedEffect = ebeQueuedBackup;

            // Redraw everything
            PauseDebugDrawSection(PAUSE_DEBUG_SECTION_ALL);
            PauseDebugDrawHealthAmmoAndEvent(PAUSE_DEBUG_SECTION_ALL);
            PauseDebugDrawAbilityCount();

            // Sync security hatch level
            gSecurityHatchLevel = gEquipment.securityHatchLevel;
            gPauseDebugOptions.securityHatchLevel = gEquipment.securityHatchLevel;

            PauseDebugDrawEventText(gEventCounter);

            // Set water lowered flag
            updateFlag = FALSE;
            if (gEventCounter > EVENT_WATER_LEVEL_LOWERED)
                updateFlag = TRUE;
            else if (gEventCounter == EVENT_WATER_LEVEL_LOWERED && gCurrentEventBasedEffect == 0x80)
                updateFlag = TRUE;

            gWaterLowered = updateFlag;

            updateFlag = PAUSE_DEBUG_EDIT_NONE;
            break;

        case PAUSE_DEBUG_SECTION_SOUND_EVENT:
            updateFlag = PAUSE_DEBUG_EDIT_NONE;
            editflag = FALSE;

            if (!PAUSE_SCREEN_DATA.pauseDebugEditingValue)
            {
                if (gChangedInput & KEY_A)
                {
                    // Start edit mode
                    PAUSE_SCREEN_DATA.pauseDebugEditingValue = TRUE;
                    PAUSE_SCREEN_DATA.oam[0].oamId = 0x9;
                }
            }
            else
            {
                if (gChangedInput & (KEY_A | KEY_B))
                {
                    // Stop edit mode
                    PAUSE_SCREEN_DATA.pauseDebugEditingValue = FALSE;
                    UpdateMenuOamDataId(0, 0x1);
                }
            }

            if (!PAUSE_SCREEN_DATA.pauseDebugEditingValue)
                break;

            if (editflag)
            {
                updateFlag = PAUSE_DEBUG_EDIT_REDRAW_NUMBERED_SECTION;
                break;
            }

            if (gChangedInput & KEY_DOWN)
            {
                // Increase value by powers of 10, also check and prevent overflow
                if (gSoundEventCounter + sPauseDebugNumbersIncrementValues[cursorX] >= SOUND_EVENT_END)
                    gSoundEventCounter = SOUND_EVENT_END - 1;
                else
                    gSoundEventCounter += sPauseDebugNumbersIncrementValues[cursorX];

                editflag = TRUE;
            }
            else if (gChangedInput & KEY_UP)
            {
                // Decrease value by powers of 10, also check and prevent underflow
                if (gSoundEventCounter - sPauseDebugNumbersIncrementValues[cursorX] < SOUND_EVENT_FIRST_CONVERSATION_STARTED)
                    gSoundEventCounter = SOUND_EVENT_FIRST_CONVERSATION_STARTED;
                else
                    gSoundEventCounter -= sPauseDebugNumbersIncrementValues[cursorX];

                editflag = TRUE;
            }
            else if (gChangedInput & KEY_RIGHT)
            {
                // Move cursor to the right
                if (cursorX != 0)
                    PAUSE_SCREEN_DATA.oam[0].xPosition += PAUSE_DEBUG_TILE_SIZE;
            }
            else if (gChangedInput & KEY_LEFT)
            {
                // Move cursor to the left
                if (cursorX < 2)
                    PAUSE_SCREEN_DATA.oam[0].xPosition -= PAUSE_DEBUG_TILE_SIZE;
            }

            if (editflag)
            {
                // Request a redraw of the sound event section
                updateFlag = PAUSE_DEBUG_EDIT_REDRAW_NUMBERED_SECTION;
            }
            break;

        case PAUSE_DEBUG_SECTION_IN_GAME_TIME:
            updateFlag = PAUSE_DEBUG_EDIT_NONE;

            if (!PAUSE_SCREEN_DATA.pauseDebugEditingValue)
            {
                if (gChangedInput & KEY_A)
                {
                    // Start edit mode
                    PAUSE_SCREEN_DATA.oam[0].oamId = 0x9;
                    PAUSE_SCREEN_DATA.pauseDebugEditingValue = TRUE;
                    gMaxInGameTimeFlag = TRUE;
                    gInGameTimer.seconds = 0;
                    gInGameTimer.frames = 0;
                }
                break;
            }

            editflag = FALSE;
            if (gChangedInput & KEY_DOWN)
            {
                // Increase value by powers of 10, also check and prevent overflow
                if (cursorX > 2)
                {
                    // Edit hours
                    cursorX -= 3;
                    if (gInGameTimer.hours + sPauseDebugNumbersIncrementValues[cursorX] > UCHAR_MAX)
                        gInGameTimer.hours = UCHAR_MAX;
                    else
                        gInGameTimer.hours += sPauseDebugNumbersIncrementValues[cursorX];

                    editflag = TRUE;
                }
                else if (cursorX < 2)
                {
                    // Edit minutes
                    if (gInGameTimer.minutes + sPauseDebugNumbersIncrementValues[cursorX] > 59)
                        gInGameTimer.minutes = 59;
                    else
                        gInGameTimer.minutes += sPauseDebugNumbersIncrementValues[cursorX];

                    editflag = TRUE;
                }
            }
            else if (gChangedInput & KEY_UP)
            {
                // Decrease value by powers of 10, also check and prevent underflow
                if (cursorX > 2)
                {
                    // Edit hours
                    cursorX -= 3;
                    if (gInGameTimer.hours - sPauseDebugNumbersIncrementValues[cursorX] < 0)
                        gInGameTimer.hours = 0;
                    else
                        gInGameTimer.hours -= sPauseDebugNumbersIncrementValues[cursorX];

                    editflag = TRUE;
                }
                else if (cursorX < 2)
                {
                    // Edit minutes
                    if (gInGameTimer.minutes - sPauseDebugNumbersIncrementValues[cursorX] < 0)
                        gInGameTimer.minutes = 0;
                    else
                        gInGameTimer.minutes -= sPauseDebugNumbersIncrementValues[cursorX];

                    editflag = TRUE;
                }
            }
            else if (gChangedInput & KEY_RIGHT)
            {
                // Move cursor to the right
                if (cursorX != 0)
                    PAUSE_SCREEN_DATA.oam[0].xPosition += PAUSE_DEBUG_TILE_SIZE;
            }
            else if (gChangedInput & KEY_LEFT)
            {
                // Move cursor to the left
                if (cursorX < 5)
                    PAUSE_SCREEN_DATA.oam[0].xPosition -= PAUSE_DEBUG_TILE_SIZE;
            }

            if (editflag)
            {
                // Redraw in game time
                PauseDebugDrawIgt();
            }
            break;

        case PAUSE_DEBUG_SECTION_QUICK_SAVE:
            // Can't save in main deck room 0 for some reason?
            if (gCurrentArea + gCurrentRoom == 0)
                break;

            if (gChangedInput & KEY_A)
            {
                // FIXME enum for stage and loop end
                for (editflag = 0; editflag < 4; editflag++)
                    Sram_QuickSave(editflag);
            }
            break;

        default:
            updateFlag = PAUSE_DEBUG_EDIT_NONE;
    }

    // Check for redraw requests
    if (updateFlag == PAUSE_DEBUG_EDIT_REDRAW_SECTION)
        PauseDebugDrawSection(PAUSE_DEBUG_SECTION_INFO_SECTION(i));
    else if (updateFlag == PAUSE_DEBUG_EDIT_REDRAW_NUMBERED_SECTION)
        PauseDebugDrawHealthAmmoAndEvent(PAUSE_DEBUG_SECTION_INFO_SECTION(i));
    else if (updateFlag == PAUSE_DEBUG_EDIT_REDRAW_ALL)
        PauseDebugDrawSection(PAUSE_DEBUG_SECTION_ALL);

    if (updateFlag != PAUSE_DEBUG_EDIT_NONE)
        PauseDebugDrawAbilityCount();
}

/**
 * @brief 7db34 | 40 | Draws the name of an event
 * 
 * @param event Event id
 */
void PauseDebugDrawEventText(u8 event)
{
    u16* dst;
    s32 i;
    s32 character;

    dst = VRAM_BASE + 0x7800;

    for (i = 0; i < EVENT_NAME_SIZE; i++)
    {
        // Event names are stored in Shift JIS (https://en.wikipedia.org/wiki/Shift_JIS)
        // Converts a char from 0b12345678 to 0b1_23045678
        character = ((sPauseDebugEventNames[event][i] & 0xE0) << 1) | (sPauseDebugEventNames[event][i] & 0x1F);

        DrawCharacterPauseDebug(character, &dst[i * PAUSE_DEBUG_TILE_SIZE * 2], 0);
    }
}

/**
 * @brief 7db78 | 38c | Draws a section of the pause debug menu (only involves changing the palette)
 * 
 * @param section Section
 */
void PauseDebugDrawSection(u8 section)
{
    s32 drawAll;
    u32 i;
    s32 j;
    s32 palette;
    s32 max;
    u16* dst;
    u32 mapBit;

    if (section != PAUSE_DEBUG_SECTION_BEAM && section != PAUSE_DEBUG_SECTION_MISSILE && section != PAUSE_DEBUG_SECTION_BOMB && section != PAUSE_DEBUG_SECTION_SUIT)
        drawAll = TRUE;
    else
        drawAll = FALSE;

    if (section == PAUSE_DEBUG_SECTION_BEAM || drawAll)
    {
        for (i = 0; i < ARRAY_SIZE(sPauseDebugBeamFlags); i++)
        {
            dst = VRAM_BASE + 0xC800;
            dst = &dst[(PAUSE_DEBUG_SECTION_INFO_TOP(PAUSE_DEBUG_SECTION_BEAM) + i) * HALF_BLOCK_SIZE + PAUSE_DEBUG_SECTION_INFO_LEFT(PAUSE_DEBUG_SECTION_BEAM)];

            if (gEquipment.beamStatus & sPauseDebugBeamFlags[i])
                palette = 9;
            else
                palette = 3;

            for (j = 0; j <= PAUSE_DEBUG_SECTION_INFO_HSIZE(PAUSE_DEBUG_SECTION_BEAM); j++, dst++)
            {
                *dst = (*dst & 0xFFF) | palette << 12;
            }
        }
    }

    if (section == PAUSE_DEBUG_SECTION_MISSILE || drawAll)
    {
        for (i = 0; i < ARRAY_SIZE(sPauseDebugMissileFlags); i++)
        {
            dst = VRAM_BASE + 0xC800;
            dst = &dst[(PAUSE_DEBUG_SECTION_INFO_TOP(PAUSE_DEBUG_SECTION_MISSILE) + i) * HALF_BLOCK_SIZE + PAUSE_DEBUG_SECTION_INFO_LEFT(PAUSE_DEBUG_SECTION_MISSILE)];

            if (gEquipment.weaponsStatus & sPauseDebugMissileFlags[i])
                palette = 9;
            else
                palette = 3;

            for (j = 0; j <= PAUSE_DEBUG_SECTION_INFO_HSIZE(PAUSE_DEBUG_SECTION_MISSILE); j++, dst++)
            {
                *dst = (*dst & 0xFFF) | palette << 12;
            }
        }
    }

    if (section == PAUSE_DEBUG_SECTION_BOMB || drawAll)
    {
        for (i = 0; i < ARRAY_SIZE(sPauseDebugBombFlags); i++)
        {
            dst = VRAM_BASE + 0xC800;
            dst = &dst[(PAUSE_DEBUG_SECTION_INFO_TOP(PAUSE_DEBUG_SECTION_BOMB) + i) * HALF_BLOCK_SIZE + PAUSE_DEBUG_SECTION_INFO_LEFT(PAUSE_DEBUG_SECTION_BOMB)];

            if (gEquipment.weaponsStatus & sPauseDebugBombFlags[i])
                palette = 9;
            else
                palette = 3;

            for (j = 0; j <= PAUSE_DEBUG_SECTION_INFO_HSIZE(PAUSE_DEBUG_SECTION_BOMB); j++, dst++)
            {
                *dst = (*dst & 0xFFF) | palette << 12;
            }
        }
    }

    if (section == PAUSE_DEBUG_SECTION_SUIT || drawAll)
    {
        for (i = 0; i < ARRAY_SIZE(sPauseDebugSuitFlags); i++)
        {
            dst = VRAM_BASE + 0xC800;
            dst = &dst[(PAUSE_DEBUG_SECTION_INFO_TOP(PAUSE_DEBUG_SECTION_SUIT) + i) * HALF_BLOCK_SIZE + PAUSE_DEBUG_SECTION_INFO_LEFT(PAUSE_DEBUG_SECTION_SUIT)];

            if (gEquipment.suitMiscStatus & sPauseDebugSuitFlags[i])
                palette = 9;
            else
                palette = 3;

            for (j = 0; j <= PAUSE_DEBUG_SECTION_INFO_HSIZE(PAUSE_DEBUG_SECTION_SUIT); j++, dst++)
            {
                *dst = (*dst & 0xFFF) | palette << 12;
            }
        }
    }

    if (section == PAUSE_DEBUG_SECTION_MISC || drawAll)
    {
        for (i = 0; i < ARRAY_SIZE(sPauseDebugMiscFlags); i++)
        {
            dst = VRAM_BASE + 0xC800;
            dst = &dst[(PAUSE_DEBUG_SECTION_INFO_TOP(PAUSE_DEBUG_SECTION_MISC) + i) * HALF_BLOCK_SIZE + PAUSE_DEBUG_SECTION_INFO_LEFT(PAUSE_DEBUG_SECTION_MISC)];

            if (gEquipment.suitMiscStatus & sPauseDebugMiscFlags[i])
                palette = 9;
            else
                palette = 3;

            for (j = 0; j <= PAUSE_DEBUG_SECTION_INFO_HSIZE(PAUSE_DEBUG_SECTION_MISC); j++, dst++)
            {
                *dst = (*dst & 0xFFF) | palette << 12;
            }
        }
    }

    if (section == PAUSE_DEBUG_SECTION_SECURITY || drawAll)
    {
        dst = VRAM_BASE + 0xC800;
        dst = &dst[PAUSE_DEBUG_SECTION_INFO_TOP(PAUSE_DEBUG_SECTION_SECURITY) * HALF_BLOCK_SIZE + PAUSE_DEBUG_SECTION_INFO_LEFT(PAUSE_DEBUG_SECTION_SECURITY)];

        for (j = 0; j <= PAUSE_DEBUG_SECTION_INFO_HSIZE(PAUSE_DEBUG_SECTION_SECURITY); j++, dst++)
        {
            if (gEquipment.securityHatchLevel > SECURITY_LEVEL_4)
                palette = 3;
            else if (gEquipment.securityHatchLevel >= j)
                palette = 9;
            else
                palette = 3;

            *dst = (*dst & 0xFFF) | palette << 12;
        }
    }

    if (section == PAUSE_DEBUG_SECTION_MAP || drawAll)
    {
        dst = VRAM_BASE + 0xC800;
        dst = &dst[PAUSE_DEBUG_SECTION_INFO_TOP(PAUSE_DEBUG_SECTION_MAP) * HALF_BLOCK_SIZE + PAUSE_DEBUG_SECTION_INFO_LEFT(PAUSE_DEBUG_SECTION_MAP)];

        for (j = 0; j <= PAUSE_DEBUG_SECTION_INFO_HSIZE(PAUSE_DEBUG_SECTION_MAP); j++, dst++)
        {
            mapBit = (gEquipment.downloadedMaps >> j) & 1;
            if (mapBit)
                palette = 9;
            else
                palette = 3;

            *dst = (*dst & 0xFFF) | palette << 12;
        }
    }

    if (section == PAUSE_DEBUG_SECTION_EVENT)
    {
        dst = VRAM_BASE + 0xC800;
        dst = &dst[(PAUSE_DEBUG_SECTION_INFO_TOP(PAUSE_DEBUG_SECTION_EVENT)) * HALF_BLOCK_SIZE + PAUSE_DEBUG_SECTION_INFO_LEFT(PAUSE_DEBUG_SECTION_EVENT)];

        for (j = 0; j <= PAUSE_DEBUG_SECTION_INFO_HSIZE(PAUSE_DEBUG_SECTION_EVENT); j++, dst++)
        {
            if (PAUSE_SCREEN_DATA.pauseDebugEditingValue)
                palette = 9;
            else
                palette = 3;

            *dst = (*dst & 0xFFF) | palette << 12;
        }
    }
}

/**
 * @brief 7df04 | 60 | Sets the current ability count
 * 
 * @param abilityCount Ability count
 */
void SetAbilityCount(u8 abilityCount)
{
    s32 i;
    s32 j;
    u32 status[3];

    // Set ability count
    gAbilityCount = abilityCount;

    status[0] = 0;
    status[1] = 0;
    status[2] = 0;

    // Get equipment status up to the current ability count
    for (j = 0, i = gAbilityCount; i != ABILITY_COUNT_NONE; j++, i--)
    {
        status[0] |= sAbilityRamValues[j + 1].beamStatus;
        status[1] |= sAbilityRamValues[j + 1].weaponStatus;
        status[2] |= sAbilityRamValues[j + 1].suitStatus;
    }

    gEquipment.beamStatus = status[0];
    gEquipment.weaponsStatus = status[1];
    gEquipment.suitMiscStatus = status[2];
}

/**
 * @brief 7df64 | f8 | Modifies the ability count
 * 
 * @param cursorX Cursor X
 * @return u32 bool, modified
 */
u32 PauseDebugModifiyAbilityCount(u8 cursorX)
{
    s32 increment;
    s32 modified;
    s32 i;
    u32 status[3];

    modified = FALSE;
    increment = sPauseDebugNumbersIncrementValues[cursorX];

    if (gChangedInput & KEY_DOWN)
    {
        if (gAbilityCount + increment >= ABILITY_COUNT_END - 1)
            gAbilityCount = ABILITY_COUNT_END - 1;
        else
            gAbilityCount += increment;

        modified = TRUE;
        // Needed to produce matching ASM
        i = 0;
    }
    else if (gChangedInput & KEY_UP)
    {
        if (gAbilityCount - increment <= 0)
            gAbilityCount = 0;
        else
            gAbilityCount -= increment;

        modified = TRUE;
    }
    else if (gChangedInput & KEY_RIGHT)
    {
        if (cursorX != 0)
            PAUSE_SCREEN_DATA.oam[0].xPosition += PAUSE_DEBUG_TILE_SIZE;
    }
    else if (gChangedInput & KEY_LEFT)
    {
        if (cursorX == 0)
            PAUSE_SCREEN_DATA.oam[0].xPosition -= PAUSE_DEBUG_TILE_SIZE;
    }
    else
    {
        PauseDebugCheckSetMaxHealthOrAmmo();
    }

    if (modified)
    {
        status[0] = 0;
        status[1] = 0;
        status[2] = 0;
    
        // Get equipment status up to the current ability count
        for (i = 0; i <= gAbilityCount; i++)
        {
            status[0] |= sAbilityRamValues[i].beamStatus;
            status[1] |= sAbilityRamValues[i].weaponStatus;
            status[2] |= sAbilityRamValues[i].suitStatus;
        }
    
        gEquipment.beamStatus = status[0];
        gEquipment.weaponsStatus = status[1];
        gEquipment.suitMiscStatus = status[2];
    }

    return modified;
}

/**
 * @brief 7e05c | 54 | Draws the ability count
 * 
 */
void PauseDebugDrawAbilityCount(void)
{
    s32 value;
    s32 i;
    s32 position;
    u16* dst;

    position = PAUSE_DEBUG_SECTION_INFO_TOP(PAUSE_DEBUG_SECTION_ABILITY_COUNT) * HALF_BLOCK_SIZE + PAUSE_DEBUG_SECTION_INFO_LEFT(PAUSE_DEBUG_SECTION_ABILITY_COUNT);
    
    dst = VRAM_BASE + 0xC800;
    dst = &dst[position];

    for (i = 0, value = 10; value > 0; value /= 10, i++)
    {
        dst[i] = 0x3080 + gAbilityCount / value % 10;
    }
}

/**
 * @brief 7e0b0 | a8 | Draws the current room and last door used
 * 
 */
void PauseDebugDrawMenuAndDoor(void)
{
    s32 value;
    u16* dst;
    s32 position;
    s32 i;

    dst = VRAM_BASE + 0xC800;
    position = sDebugLocationSectionInfo[0][0] * HALF_BLOCK_SIZE + sDebugLocationSectionInfo[0][1];
    position += 2;

    for (i = position, value = 100; value > 0; value /= 10, i++)
    {
        dst[i] = 0x3080 + (gCurrentRoom + 1) / value % 10;
    }

    position = sDebugLocationSectionInfo[1][0] * HALF_BLOCK_SIZE + sDebugLocationSectionInfo[1][1];
    position += 2;

    for (i = position, value = 100; value > 0; value /= 10, i++)
    {
        dst[i] = 0x3080 + gLastDoorUsed / value % 10;
    }
}

void PauseDebugDrawIgt(void)
{
    u32 position;
    u16* dst;
    s32 power;
    s32 value;
    // Needed to produce matching ASM
    unsigned long long baseTile;

    dst = VRAM_BASE + 0xC800;
    position = PAUSE_DEBUG_SECTION_INFO_TOP(PAUSE_DEBUG_SECTION_IN_GAME_TIME) * HALF_BLOCK_SIZE + PAUSE_DEBUG_SECTION_INFO_LEFT(PAUSE_DEBUG_SECTION_IN_GAME_TIME);

    for (power = 100; power > 0; power /= 10, position++)
    {
        baseTile = 0x3080;
        value = gInGameTimer.hours / power % 10;

        if (power == 100 && value == 0)
            dst[position] = 0x3080 + 12;
        else
            do { dst[position] = value + baseTile; } while (0);
    }

    position++;

    for (power = 10; power > 0; power /= 10, position++)
    {
        dst[position] = 0x3080 + gInGameTimer.minutes / power % 10;
    }

    PAUSE_SCREEN_DATA.unk_284 = gInGameTimer.minutes;
}

/**
 * @brief 7e224 | 54 | To document
 * 
 */
void unk_7e224(void)
{
    u16* dst;
    u32 position;

    dst = VRAM_BASE + 0xC800;
    position = PAUSE_DEBUG_SECTION_INFO_TOP(PAUSE_DEBUG_SECTION_IN_GAME_TIME) * HALF_BLOCK_SIZE + PAUSE_DEBUG_SECTION_INFO_LEFT(PAUSE_DEBUG_SECTION_IN_GAME_TIME) + 3;

    if (MOD_AND(gInGameTimer.seconds, 2))
        dst[position] = 0x308C;
    else
        dst[position] = 0x307B;
}

/**
 * @brief 7e278 | 200 | Handles modifying health and ammo
 * 
 * @param cursorX Cursor inside section X
 * @param section Section
 * @return u32 bool, modified
 */
u32 PauseDebugModifyHealthAndAmmo(u8 cursorX, u8 section)
{
    s32 modified;

    u16* pModified16;
    u16* pMax16;
    u8* pModified8;
    u8* pMax8;

    s32 length;
    s32 type;
    s32 valueType;
    s32 ceiling;
    s32 increment;

    modified = FALSE;

    // Get pointer to current modified value, its counterpart (max or current depending on what's modified)
    // Also get the length (in powers of ten), the type and value type
    if (section == PAUSE_DEBUG_SECTION_ENERGY_CURRENT)
    {
        pModified16 = &gEquipment.currentEnergy;
        pMax16 = &gEquipment.maxEnergy;

        length = 3;
        type = 0x1;
        valueType = PAUSE_DEBUG_AMMO_TYPE_HEALTH;
    }
    else if (section == PAUSE_DEBUG_SECTION_ENERGY_MAX)
    {
        pModified16 = &gEquipment.maxEnergy;
        pMax16 = &gEquipment.currentEnergy;

        length = 3;
        type = 0x2;
        valueType = PAUSE_DEBUG_AMMO_TYPE_HEALTH;
    }
    else if (section == PAUSE_DEBUG_SECTION_MISSILE_CURRENT)
    {
        pModified16 = &gEquipment.currentMissiles;
        pMax16 = &gEquipment.maxMissiles;

        length = 2;
        type = 0x1;
        valueType = PAUSE_DEBUG_AMMO_TYPE_MISSILES;
    }
    else if (section == PAUSE_DEBUG_SECTION_MISSILE_MAX)
    {
        pModified16 = &gEquipment.maxMissiles;
        pMax16 = &gEquipment.currentMissiles;

        length = 2;
        type = 0x2;
        valueType = PAUSE_DEBUG_AMMO_TYPE_MISSILES;
    }
    else if (section == PAUSE_DEBUG_SECTION_POWER_BOMB_CURRENT)
    {
        pModified8 = &gEquipment.currentPowerBombs;
        pMax8 = &gEquipment.maxPowerBombs;

        length = 2;
        type = 0x3;
        valueType = PAUSE_DEBUG_AMMO_TYPE_POWER_BOMBS;
    }
    else if (section == PAUSE_DEBUG_SECTION_POWER_BOMB_MAX)
    {
        pModified8 = &gEquipment.maxPowerBombs;
        pMax8 = &gEquipment.currentPowerBombs;

        length = 2;
        type = 0x4;
        valueType = PAUSE_DEBUG_AMMO_TYPE_POWER_BOMBS;
    }
    else
    {
        // Invalid section, abort
        return FALSE;
    }

    if (gChangedInput & KEY_RIGHT)
    {
        // Check move right
        if (cursorX != 0)
            PAUSE_SCREEN_DATA.oam[0].xPosition += PAUSE_DEBUG_TILE_SIZE;

        return FALSE;
    }

    if (gChangedInput & KEY_LEFT)
    {
        // Check move left
        if (cursorX < length)
            PAUSE_SCREEN_DATA.oam[0].xPosition -= PAUSE_DEBUG_TILE_SIZE;

        return FALSE;
    }

    ceiling = sPauseDebugNumbersIncrementValues[PAUSE_DEBUG_SECTION_INFO_HSIZE(section) + 1] - 1;

    if (ceiling > sPauseDebugNumbersMaxValues[valueType])
        ceiling = sPauseDebugNumbersMaxValues[valueType];

    increment = sPauseDebugNumbersIncrementValues[cursorX];

    if (type <= 0x2)
    {
        if (gChangedInput & KEY_DOWN)
        {
            // Try to increment value
            if (*pModified16 + increment > ceiling)
                *pModified16 = ceiling;
            else
                *pModified16 += increment;

            modified = TRUE;
        }
        else if (gChangedInput & KEY_UP)
        {
            // Try to decrement value
            if (*pModified16 - increment < 0)
                *pModified16 = 0;
            else
                *pModified16 -= increment;

            modified = TRUE;
        }

        if (type == 0x1)
        {
            // Sync max if the current exceded it
            if (*pModified16 >= *pMax16)
                *pMax16 = *pModified16;
        }
        else if (type == 0x2)
        {
            // Sync current if max was below
            if (*pModified16 <= *pMax16)
                *pMax16 = *pModified16;
        }
    }
    else
    {
        // Try to increment value
        if (gChangedInput & KEY_DOWN)
        {
            if (*pModified8 + increment > ceiling)
                *pModified8 = ceiling;
            else
                *pModified8 += increment;

            modified = TRUE;
        }
        else if (gChangedInput & KEY_UP)
        {
            // Try to decrement value
            if (*pModified8 - increment < 0)
                *pModified8 = 0;
            else
                *pModified8 -= increment;

            modified = TRUE;
        }

        if (type == 0x3)
        {
            // Sync max if the current exceded it
            if (*pModified8 >= *pMax8)
                *pMax8 = *pModified8;
        }
        else if (type == 0x4)
        {
            // Sync current if max was below
            if (*pModified8 <= *pMax8)
                *pMax8 = *pModified8;
        }
    }

    return modified;
}

/**
 * @brief 7e478 | a8 | Draws a numbered section of the pause debug menu (health, ammo or events)
 * 
 * @param section Section
 */
void PauseDebugDrawHealthAmmoAndEvent(u8 section)
{
    u8 drawAll;

    // Check draw all
    if (section == PAUSE_DEBUG_SECTION_ALL)
        drawAll = TRUE;
    else
        drawAll = FALSE;

    // Energy, draw both
    if (section == PAUSE_DEBUG_SECTION_ENERGY_CURRENT || section == PAUSE_DEBUG_SECTION_ENERGY_MAX || drawAll)
    {
        PauseDebugDrawNumber(gEquipment.currentEnergy, PAUSE_DEBUG_SECTION_ENERGY_CURRENT);
        PauseDebugDrawNumber(gEquipment.maxEnergy, PAUSE_DEBUG_SECTION_ENERGY_MAX);
    }

    // Missile, draw both
    if (section == PAUSE_DEBUG_SECTION_MISSILE_CURRENT || section == PAUSE_DEBUG_SECTION_MISSILE_MAX || drawAll)
    {
        PauseDebugDrawNumber(gEquipment.currentMissiles, PAUSE_DEBUG_SECTION_MISSILE_CURRENT);
        PauseDebugDrawNumber(gEquipment.maxMissiles, PAUSE_DEBUG_SECTION_MISSILE_MAX);
    }

    // Power bomb, draw both
    if (section == PAUSE_DEBUG_SECTION_POWER_BOMB_CURRENT || section == PAUSE_DEBUG_SECTION_POWER_BOMB_MAX || drawAll)
    {
        PauseDebugDrawNumber(gEquipment.currentPowerBombs, PAUSE_DEBUG_SECTION_POWER_BOMB_CURRENT);
        PauseDebugDrawNumber(gEquipment.maxPowerBombs, PAUSE_DEBUG_SECTION_POWER_BOMB_MAX);
    }

    // Event
    if (section == PAUSE_DEBUG_SECTION_EVENT || drawAll)
        PauseDebugDrawNumber(gEventCounter, PAUSE_DEBUG_SECTION_EVENT);

    // Sound event
    if (section == PAUSE_DEBUG_SECTION_SOUND_EVENT || drawAll)
        PauseDebugDrawNumber(gSoundEventCounter, PAUSE_DEBUG_SECTION_SOUND_EVENT);
}

/**
 * @brief 7e520 | 70 | Draws a number
 * 
 * @param value Value
 * @param section Section
 */
void PauseDebugDrawNumber(u16 value, u8 section)
{
    u16* dst;
    u32 position;
    s32 power;

    // Get position
    position = PAUSE_DEBUG_SECTION_INFO_TOP(section) * HALF_BLOCK_SIZE + PAUSE_DEBUG_SECTION_INFO_LEFT(section);

    dst = VRAM_BASE + 0xC800;
    dst = &dst[position];

    // Get maximum power of ten for the number
    power = sPauseDebugNumbersIncrementValues[PAUSE_DEBUG_SECTION_INFO_HSIZE(section)];

    // Draw each digit
    while (power > 0)
    {
        *dst = 0x3080 + value / power % 10;

        power /= 10;
        dst++;
    }
}

/**
 * @brief 7e590 | 9c | Checks to set health/ammo to maximum or minimum
 * 
 */
void PauseDebugCheckSetMaxHealthOrAmmo(void)
{
    if (gChangedInput & (KEY_START | KEY_R))
    {
        // Set max value, update current, max then re-draw
        gEquipment.currentEnergy = sPauseDebugNumbersMaxValues[PAUSE_DEBUG_AMMO_TYPE_HEALTH];
        gEquipment.maxEnergy = sPauseDebugNumbersMaxValues[PAUSE_DEBUG_AMMO_TYPE_HEALTH];
        PauseDebugDrawHealthAmmoAndEvent(sDebugSectionInfo[PAUSE_DEBUG_SECTION_ENERGY_CURRENT][4]);

        gEquipment.currentMissiles = sPauseDebugNumbersMaxValues[PAUSE_DEBUG_AMMO_TYPE_MISSILES];
        gEquipment.maxMissiles = sPauseDebugNumbersMaxValues[PAUSE_DEBUG_AMMO_TYPE_MISSILES];
        PauseDebugDrawHealthAmmoAndEvent(sDebugSectionInfo[PAUSE_DEBUG_SECTION_MISSILE_CURRENT][4]);

        gEquipment.currentPowerBombs = sPauseDebugNumbersMaxValues[PAUSE_DEBUG_AMMO_TYPE_POWER_BOMBS];
        gEquipment.maxPowerBombs = sPauseDebugNumbersMaxValues[PAUSE_DEBUG_AMMO_TYPE_POWER_BOMBS];
        PauseDebugDrawHealthAmmoAndEvent(sDebugSectionInfo[PAUSE_DEBUG_SECTION_POWER_BOMB_CURRENT][4]);

        return;
    }

    if (gChangedInput & (KEY_SELECT | KEY_L))
    {
        // Set min value, update current, max then re-draw
        gEquipment.currentEnergy = 99;
        gEquipment.maxEnergy = 99;
        PauseDebugDrawHealthAmmoAndEvent(sDebugSectionInfo[PAUSE_DEBUG_SECTION_ENERGY_CURRENT][4]);

        gEquipment.currentMissiles = 10;
        gEquipment.maxMissiles = 10;
        PauseDebugDrawHealthAmmoAndEvent(sDebugSectionInfo[PAUSE_DEBUG_SECTION_MISSILE_CURRENT][4]);

        gEquipment.currentPowerBombs = 10;
        gEquipment.maxPowerBombs = 10;
        PauseDebugDrawHealthAmmoAndEvent(sDebugSectionInfo[PAUSE_DEBUG_SECTION_POWER_BOMB_CURRENT][4]);
    }
}

/**
 * @brief 7e62c | 20 | Draws everything on the pause debug menu
 * 
 */
void PauseDebugDrawEverything(void)
{
    PauseDebugDrawSection(PAUSE_DEBUG_SECTION_ALL);
    PauseDebugDrawHealthAmmoAndEvent(PAUSE_DEBUG_SECTION_ALL);
    PauseDebugDrawAbilityCount();
    PauseDebugDrawMenuAndDoor();
    PauseDebugDrawIgt();
}

/**
 * @brief 7e64c | 2c | Sets up the pause debug menu cursor
 * 
 */
void PauseDebugSetupCursor(void)
{
    UpdateMenuOamDataId(0, 0x1);

    // Start at the ability count section
    PAUSE_SCREEN_DATA.oam[0].yPosition = PAUSE_DEBUG_SECTION_INFO_TOP(PAUSE_DEBUG_SECTION_ABILITY_COUNT) * PAUSE_DEBUG_TILE_SIZE;
    PAUSE_SCREEN_DATA.oam[0].xPosition = PAUSE_DEBUG_SECTION_INFO_RIGHT(PAUSE_DEBUG_SECTION_ABILITY_COUNT) * PAUSE_DEBUG_TILE_SIZE;
}
