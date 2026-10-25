#include "menus/pause_screen.h"

#include "gba/display.h"
#include "gba/memory.h"
#include "globals.h"
#include "io.h"
#include "macros.h"
#include "oam.h"

#include "data/menus/pause_screen_data.h"
#include "data/menus/pause_screen_misc_data.h"

#include "constants/audio.h"
#include "constants/event.h"
#include "constants/game_state.h"
#include "constants/menus/pause_screen.h"
#include "constants/minimap.h"
#include "constants/samus.h"

#include "structs/connection.h"
#include "structs/display.h"
#include "structs/event.h"
#include "structs/menus/pause_screen.h"
#include "structs/minimap.h"
#include "structs/samus.h"

static const u32* sMinimapData[MINIMAP_COUNT] = {
    [MINIMAP_MAIN_DECK] = sMainDeckMinimap,
    [MINIMAP_SECTOR_1] = sSector1Minimap,
    [MINIMAP_SECTOR_2] = sSector2Minimap,
    [MINIMAP_SECTOR_3] = sSector3Minimap,
    [MINIMAP_SECTOR_4] = sSector4Minimap,
    [MINIMAP_SECTOR_5] = sSector5Minimap,
    [MINIMAP_SECTOR_6] = sSector6Minimap,
    [MINIMAP_7] = sMainDeckMinimap,
    [MINIMAP_8] = sMainDeckMinimap,
    [MINIMAP_MAIN_DECK_NO_LAB] = sMainDeckNoLabMinimap,
    [MINIMAP_BLANK] = sBlankMinimap
};

static struct PSD_28 sUnk_79be88 = {
    .unk_0 = 0,
    .unk_1 = 0,
    .unk_2 = 0,
    .unk_3 = 0,
};

static u8 sPauseScreenIgtAndTanksOamInfo[TANK_NUM_COUNT + 1][PAUSE_OAM_INFO_COUNT] = {
    [0] = {
        [PAUSE_OAM_INDEX] = PAUSE_OAM_IDX_IN_GAME_TIMER,
        [PAUSE_OAM_ID] = PAUSE_OAM_ID_IN_GAME_TIMER,
        [PAUSE_OAM_X_POSITION] = 36,
        [PAUSE_OAM_Y_POSITION] = 142
    },
    [TANK_NUM_ENERGY + 1] = {
        [PAUSE_OAM_INDEX] = PAUSE_OAM_IDX_COLLECTED_ENERGY_TANKS,
        [PAUSE_OAM_ID] = PAUSE_OAM_ID_COLLECTED_ENERGY_TANKS,
        [PAUSE_OAM_X_POSITION] = 36,
        [PAUSE_OAM_Y_POSITION] = 24
    },
    [TANK_NUM_MISSILE + 1] = {
        [PAUSE_OAM_INDEX] = PAUSE_OAM_IDX_COLLECTED_MISSILE_TANKS,
        [PAUSE_OAM_ID] = PAUSE_OAM_ID_COLLECTED_MISSILE_TANKS,
        [PAUSE_OAM_X_POSITION] = 36,
        [PAUSE_OAM_Y_POSITION] = 32
    },
    [TANK_NUM_POWER_BOMB + 1] = {
        [PAUSE_OAM_INDEX] = PAUSE_OAM_IDX_COLLECTED_POWER_BOMB_TANKS,
        [PAUSE_OAM_ID] = PAUSE_OAM_ID_COLLECTED_POWER_BOMB_TANKS,
        [PAUSE_OAM_X_POSITION] = 36,
        [PAUSE_OAM_Y_POSITION] = 40
    }
};

static u8 sPauseScreenTankCheckMarkOamInfo[TANK_NUM_COUNT][PAUSE_OAM_INFO_COUNT] = {
    [TANK_NUM_ENERGY] = {
        [PAUSE_OAM_INDEX] = PAUSE_OAM_IDX_ENERGY_TANK_CHECK_MARK,
        [PAUSE_OAM_ID] = PAUSE_OAM_ID_ENERGY_TANK_CHECK_MARK,
        [PAUSE_OAM_X_POSITION] = 50,
        [PAUSE_OAM_Y_POSITION] = 13
    },
    [TANK_NUM_MISSILE] = {
        [PAUSE_OAM_INDEX] = PAUSE_OAM_IDX_MISSILE_TANK_CHECK_MARK,
        [PAUSE_OAM_ID] = PAUSE_OAM_ID_MISSILE_TANK_CHECK_MARK,
        [PAUSE_OAM_X_POSITION] = 72,
        [PAUSE_OAM_Y_POSITION] = 13
    },
    [TANK_NUM_POWER_BOMB] = {
        [PAUSE_OAM_INDEX] = PAUSE_OAM_IDX_POWER_BOMB_TANK_CHECK_MARK,
        [PAUSE_OAM_ID] = PAUSE_OAM_ID_POWER_BOMB_TANK_CHECK_MARK,
        [PAUSE_OAM_X_POSITION] = 94,
        [PAUSE_OAM_Y_POSITION] = 13
    }
};

static const u8* sPauseDebugItemFlagsPointers[5] = {
    sPauseDebugBeamFlags,
    sPauseDebugMissileFlags,
    sPauseDebugBombFlags,
    sPauseDebugSuitFlags,
    sPauseDebugMiscFlags,
};

u8 sUnk_79bebc[4] = {
    PAUSE_OAM_IDX_DOWNLOAD_SCAN_LINE_TRAILING_1,
    PAUSE_OAM_IDX_DOWNLOAD_SCAN_LINE_TRAILING_2,
    PAUSE_OAM_IDX_DOWNLOAD_SCAN_LINE_TRAILING_3,
    7
};

static const struct FrameData* sPauseScreenOamPointers[PAUSE_OAM_ID_COUNT] = {
    [PAUSE_OAM_ID_NONE] = sPauseScreenOam_BlinkingSquare,
    [PAUSE_OAM_ID_BLINKING_SQUARE] = sPauseScreenOam_BlinkingSquare,
    [PAUSE_OAM_ID_YES_NO_CURSOR] = sPauseScreenOam_YesNoCursor,
    [PAUSE_OAM_ID_NAV_TEXT_ARROW] = sPauseScreenOam_NavTextArrow,
    [PAUSE_OAM_ID_MAP_PREVIEW_POINT] = sPauseScreenOam_MapPreviewPoint,
    [PAUSE_OAM_ID_MAP_UP_ARROW] = sPauseScreenOam_MapUpArrow,
    [PAUSE_OAM_ID_MAP_DOWN_ARROW] = sPauseScreenOam_MapDownArrow,
    [PAUSE_OAM_ID_MAP_LEFT_ARROW] = sPauseScreenOam_MapLeftArrow,
    [PAUSE_OAM_ID_MAP_RIGHT_ARROW] = sPauseScreenOam_MapRightArrow,
    [PAUSE_OAM_ID_PAUSE_DEBUG_CURSOR_ARROWS] = sPauseScreenOam_PauseDebugCursorArrows,
    [PAUSE_OAM_ID_PAUSE_DEBUG_CURSOR_DOWN_ARROW] = sPauseScreenOam_PauseDebugCursorDownArrow,
    [PAUSE_OAM_ID_NAV_TEXT_CURSOR] = sPauseScreenOam_NavTextCursor,
    [PAUSE_OAM_ID_NAV_TEXT_CURSOR_BLINKING] = sPauseScreenOam_NavTextCursorBlinking,
    [PAUSE_OAM_ID_UNK_13] = sPauseScreenOam_Unk13,
    [PAUSE_OAM_ID_MAP_ELEVATOR_UP_ARROWS] = sPauseScreenOam_MapElevatorUpArrows,
    [PAUSE_OAM_ID_MAP_ELEVATOR_DOWN_ARROWS] = sPauseScreenOam_MapElevatorDownArrows,
    [PAUSE_OAM_ID_DOWNLOAD_SCAN_LINE_TRAILING] = sPauseScreenOam_DownloadScanLineTrailing,
    [PAUSE_OAM_ID_DOWNLOAD_SCAN_LINE_LEADING] = sPauseScreenOam_DownloadScanLineLeading,
    [PAUSE_OAM_ID_MAP_TARGET_ABOVE] = sPauseScreenOam_MapTargetAbove,
    [PAUSE_OAM_ID_MAP_TARGET_BELOW] = sPauseScreenOam_MapTargetBelow,
    [PAUSE_OAM_ID_MAP_TARGET_LEFT] = sPauseScreenOam_MapTargetLeft,
    [PAUSE_OAM_ID_MAP_TARGET_RIGHT] = sPauseScreenOam_MapTargetRight,
    [PAUSE_OAM_ID_BSL_DIAGRAM_TARGET_ABOVE] = sPauseScreenOam_BslDiagramTargetAbove,
    [PAUSE_OAM_ID_BSL_DIAGRAM_TARGET_BELOW] = sPauseScreenOam_BslDiagramTargetBelow,
    [PAUSE_OAM_ID_BSL_DIAGRAM_START_ABOVE] = sPauseScreenOam_BslDiagramStartAbove,
    [PAUSE_OAM_ID_BSL_DIAGRAM_START_BELOW] = sPauseScreenOam_BslDiagramStartBelow,
    [PAUSE_OAM_ID_MAIN_DECK_TEXT] = sPauseScreenOam_MainDeckText,
    [PAUSE_OAM_ID_MAIN_DECK_TEXT_APPEARING] = sPauseScreenOam_AreaTextAppearing,
    [PAUSE_OAM_ID_SECTOR_1_TEXT] = sPauseScreenOam_Sector1Text,
    [PAUSE_OAM_ID_SECTOR_1_TEXT_APPEARING] = sPauseScreenOam_AreaTextAppearing,
    [PAUSE_OAM_ID_SECTOR_2_TEXT] = sPauseScreenOam_Sector2Text,
    [PAUSE_OAM_ID_SECTOR_2_TEXT_APPEARING] = sPauseScreenOam_AreaTextAppearing,
    [PAUSE_OAM_ID_SECTOR_3_TEXT] = sPauseScreenOam_Sector3Text,
    [PAUSE_OAM_ID_SECTOR_3_TEXT_APPEARING] = sPauseScreenOam_AreaTextAppearing,
    [PAUSE_OAM_ID_SECTOR_4_TEXT] = sPauseScreenOam_Sector4Text,
    [PAUSE_OAM_ID_SECTOR_4_TEXT_APPEARING] = sPauseScreenOam_AreaTextAppearing,
    [PAUSE_OAM_ID_SECTOR_5_TEXT] = sPauseScreenOam_Sector5Text,
    [PAUSE_OAM_ID_SECTOR_5_TEXT_APPEARING] = sPauseScreenOam_AreaTextAppearing,
    [PAUSE_OAM_ID_SECTOR_6_TEXT] = sPauseScreenOam_Sector6Text,
    [PAUSE_OAM_ID_SECTOR_6_TEXT_APPEARING] = sPauseScreenOam_AreaTextAppearing,
    [PAUSE_OAM_ID_STATUS_BUTTON] = sPauseScreenOam_StatusButton,
    [PAUSE_OAM_ID_STATUS_BUTTON_SELECTED] = sPauseScreenOam_StatusButtonSelected,
    [PAUSE_OAM_ID_SLEEP_BUTTON] = sPauseScreenOam_SleepButton,
    [PAUSE_OAM_ID_SLEEP_BUTTON_SELECTED] = sPauseScreenOam_SleepButtonSelected,
    [PAUSE_OAM_ID_L1_LOCK] = sPauseScreenOam_L1Lock,
    [PAUSE_OAM_ID_L1_OPEN] = sPauseScreenOam_L1Open,
    [PAUSE_OAM_ID_L2_LOCK] = sPauseScreenOam_L2Lock,
    [PAUSE_OAM_ID_L2_OPEN] = sPauseScreenOam_L2Open,
    [PAUSE_OAM_ID_L3_LOCK] = sPauseScreenOam_L3Lock,
    [PAUSE_OAM_ID_L3_OPEN] = sPauseScreenOam_L3Open,
    [PAUSE_OAM_ID_L4_LOCK] = sPauseScreenOam_L4Lock,
    [PAUSE_OAM_ID_L4_OPEN] = sPauseScreenOam_L4Open,
    [PAUSE_OAM_ID_OBJECTIVE_BUTTON] = sPauseScreenOam_ObjectiveButton,
    [PAUSE_OAM_ID_UNK_53] = sPauseScreenOam_AreaTextAppearing,
    [PAUSE_OAM_ID_IN_GAME_TIMER] = sPauseScreenOam_InGameTimer,
    [PAUSE_OAM_ID_COLLECTED_ENERGY_TANKS] = sPauseScreenOam_CollectedEnergyTanks,
    [PAUSE_OAM_ID_COLLECTED_MISSILE_TANKS] = sPauseScreenOam_CollectedMissileTanks,
    [PAUSE_OAM_ID_COLLECTED_POWER_BOMB_TANKS] = sPauseScreenOam_CollectedPowerBombTanks,
    [PAUSE_OAM_ID_ENERGY_TANK_CHECK_MARK] = sPauseScreenOam_EnergyTankCheckMark,
    [PAUSE_OAM_ID_MISSILE_TANK_CHECK_MARK] = sPauseScreenOam_MissileTankCheckMark,
    [PAUSE_OAM_ID_POWER_BOMB_TANK_CHECK_MARK] = sPauseScreenOam_PowerBombTankCheckMark,
    [PAUSE_OAM_ID_NAVIGATION_PAD] = sPauseScreenOam_NavigationPad,
    [PAUSE_OAM_ID_NAVIGATION_PAD_WITH_SAMUS] = sPauseScreenOam_NavigationPadWithSamus,
    [PAUSE_OAM_ID_LOCKED_HATCH_LEFT] = sPauseScreenOam_LockedHatchLeft,
    [PAUSE_OAM_ID_LOCKED_HATCH_RIGHT] = sPauseScreenOam_LockedHatchRight,
    [PAUSE_OAM_ID_POP_UP_WINDOW] = sPauseScreenOam_PopUpWindow,
    [PAUSE_OAM_ID_POP_UP_WINDOW_CLOSING] = sPauseScreenOam_PopUpWindowClosing,
    [PAUSE_OAM_ID_ADAM_TEXT_BOX_OUTLINE] = sPauseScreenOam_AdamTextBoxOutline,
    [PAUSE_OAM_ID_ADAM_TEXT_BOX_OUTLINE_SHORT] = sPauseScreenOam_AdamTextBoxOutline,
    [PAUSE_OAM_ID_ADAM_TEXT_BOX_OUTLINE_CLOSING] = sPauseScreenOam_AdamTextBoxOutlineClosing,
    [PAUSE_OAM_ID_ADAM_TEXT_BOX_BACKGROUND] = sPauseScreenOam_AdamTextBoxBackground,
    [PAUSE_OAM_ID_ADAM_TEXT_BOX_BACKGROUND_SHORT] = sPauseScreenOam_AdamTextBoxBackground,
    [PAUSE_OAM_ID_ADAM_TEXT_BOX_BACKGROUND_CLOSING] = sPauseScreenOam_AdamTextBoxBackgroundClosing,
    [PAUSE_OAM_ID_ADAM_TEXT_BOX_LIGHT_OPENING] = sPauseScreenOam_AdamTextBoxLightOpening,
    [PAUSE_OAM_ID_ADAM_TEXT_BOX_LIGHT_CLOSING] = sPauseScreenOam_AdamTextBoxLightClosing,
    [PAUSE_OAM_ID_ADAM_TEXT_BOX_LIGHT_OFF] = sPauseScreenOam_AdamTextBoxLightOff,
    [PAUSE_OAM_ID_ADAM_TEXT_BOX_LIGHT_FLASHING] = sPauseScreenOam_AdamTextBoxLightFlashing,
    [PAUSE_OAM_ID_SAMUS_TEXT_BOX] = sPauseScreenOam_SamusTextBox,
    [PAUSE_OAM_ID_SAMUS_TEXT_BOX_EDGE] = sPauseScreenOam_SamusTextBox,
    [PAUSE_OAM_ID_SAMUS_TEXT_BOX_CLOSING] = sPauseScreenOam_SamusTextBoxClosing,
    [PAUSE_OAM_ID_SAMUS_TEXT_BOX_BACKGROUND] = sPauseScreenOam_SamusTextBoxBackground,
    [PAUSE_OAM_ID_UNK_81] = sPauseScreenOam_SamusTextBoxBackground,
    [PAUSE_OAM_ID_SAMUS_TEXT_BOX_BACKGROUND_CLOSING] = sPauseScreenOam_SamusTextBoxBackgroundClosing,
    [PAUSE_OAM_ID_FED_TEXT_BOX_OUTLINE] = sPauseScreenOam_FedTextBoxOutline,
    [PAUSE_OAM_ID_FED_TEXT_BOX_EDGE] = sPauseScreenOam_FedTextBoxOutline,
    [PAUSE_OAM_ID_FED_TEXT_BOX_CLOSING] = sPauseScreenOam_FedTextBoxClosing,
    [PAUSE_OAM_ID_FED_TEXT_BOX_BACKGROUND] = sPauseScreenOam_FedTextBoxBackground,
    [PAUSE_OAM_ID_UNK_87] = sPauseScreenOam_FedTextBoxBackground,
    [PAUSE_OAM_ID_FED_TEXT_BOX_BACKGROUND_CLOSING] = sPauseScreenOam_FedTextBoxBackgroundClosing,
    [PAUSE_OAM_ID_OBJECTIVE_TEXT_BOX] = sPauseScreenOam_SamusTextBox,
    [PAUSE_OAM_ID_OBJECTIVE_TEXT_BOX_EDGE] = sPauseScreenOam_SamusTextBox,
    [PAUSE_OAM_ID_OBJECTIVE_TEXT_BOX_CLOSING] = sPauseScreenOam_SamusTextBoxClosing,
    [PAUSE_OAM_ID_OBJECTIVE_TEXT_BOX_BACKGROUND] = sPauseScreenOam_SamusTextBoxBackground,
    [PAUSE_OAM_ID_UNK_93] = sPauseScreenOam_SamusTextBoxBackground,
    [PAUSE_OAM_ID_OBJECTIVE_TEXT_BOX_BACKGROUND_CLOSING] = sPauseScreenOam_SamusTextBoxBackgroundClosing,
    [PAUSE_OAM_ID_SAMUS_PORTRAIT_OPENING] = sPauseScreenOam_SamusPortraitOpening,
    [PAUSE_OAM_ID_SAMUS_PORTRAIT_ANIMATED] = sPauseScreenOam_SamusPortraitAnimated,
    [PAUSE_OAM_ID_SAMUS_PORTRAIT_STILL] = sPauseScreenOam_SamusPortraitStill,
    [PAUSE_OAM_ID_SAMUS_PORTRAIT_CLOSING] = sPauseScreenOam_SamusPortraitClosing,
    [PAUSE_OAM_ID_FEDERATION_PORTRAIT_OPENING] = sPauseScreenOam_FederationPortraitOpening,
    [PAUSE_OAM_ID_FEDERATION_PORTRAIT_STILL] = sPauseScreenOam_FederationPortraitStill,
    [PAUSE_OAM_ID_FEDERATION_PORTRAIT_ANIMATING] = sPauseScreenOam_FederationPortraitAnimating,
    [PAUSE_OAM_ID_FEDERATION_PORTRAIT_CLOSING] = sPauseScreenOam_FederationPortraitClosing,
    [PAUSE_OAM_ID_FEDERATION_PORTRAIT_FLICKERING] = sPauseScreenOam_FederationPortraitFlickering,
    [PAUSE_OAM_ID_BSL_DIAGRAM_0_DEGREES] = sPauseScreenOam_BslDiagram0Degrees,
    [PAUSE_OAM_ID_BSL_DIAGRAM_10_DEGREES] = sPauseScreenOam_BslDiagram10Degrees,
    [PAUSE_OAM_ID_BSL_DIAGRAM_20_DEGREES] = sPauseScreenOam_BslDiagram20Degrees,
    [PAUSE_OAM_ID_BSL_DIAGRAM_30_DEGREES] = sPauseScreenOam_BslDiagram30Degrees,
    [PAUSE_OAM_ID_BSL_DIAGRAM_40_DEGREES] = sPauseScreenOam_BslDiagram40Degrees,
    [PAUSE_OAM_ID_BSL_DIAGRAM_50_DEGREES] = sPauseScreenOam_BslDiagram50Degrees,
    [PAUSE_OAM_ID_BSL_DIAGRAM_60_DEGREES] = sPauseScreenOam_BslDiagram60Degrees,
    [PAUSE_OAM_ID_BSL_DIAGRAM_70_DEGREES] = sPauseScreenOam_BslDiagram70Degrees,
    [PAUSE_OAM_ID_BSL_DIAGRAM_80_DEGREES] = sPauseScreenOam_BslDiagram80Degrees,
    [PAUSE_OAM_ID_BSL_DIAGRAM_90_DEGREES] = sPauseScreenOam_BslDiagram90Degrees,
    [PAUSE_OAM_ID_BSL_DIAGRAM_100_DEGREES] = sPauseScreenOam_BslDiagram100Degrees,
    [PAUSE_OAM_ID_BSL_DIAGRAM_110_DEGREES] = sPauseScreenOam_BslDiagram110Degrees,
    [PAUSE_OAM_ID_BSL_DIAGRAM_120_DEGREES] = sPauseScreenOam_BslDiagram120Degrees,
    [PAUSE_OAM_ID_BSL_DIAGRAM_130_DEGREES] = sPauseScreenOam_BslDiagram130Degrees,
    [PAUSE_OAM_ID_BSL_DIAGRAM_140_DEGREES] = sPauseScreenOam_BslDiagram140Degrees,
    [PAUSE_OAM_ID_BSL_DIAGRAM_150_DEGREES] = sPauseScreenOam_BslDiagram150Degrees,
    [PAUSE_OAM_ID_BSL_DIAGRAM_160_DEGREES] = sPauseScreenOam_BslDiagram160Degrees,
    [PAUSE_OAM_ID_BSL_DIAGRAM_170_DEGREES] = sPauseScreenOam_BslDiagram170Degrees,
    [PAUSE_OAM_ID_BSL_DIAGRAM_180_DEGREES] = sPauseScreenOam_BslDiagram180Degrees,
    [PAUSE_OAM_ID_BSL_DIAGRAM_190_DEGREES] = sPauseScreenOam_BslDiagram190Degrees,
    [PAUSE_OAM_ID_BSL_DIAGRAM_200_DEGREES] = sPauseScreenOam_BslDiagram200Degrees,
    [PAUSE_OAM_ID_BSL_DIAGRAM_210_DEGREES] = sPauseScreenOam_BslDiagram210Degrees,
    [PAUSE_OAM_ID_BSL_DIAGRAM_220_DEGREES] = sPauseScreenOam_BslDiagram220Degrees,
    [PAUSE_OAM_ID_BSL_DIAGRAM_230_DEGREES] = sPauseScreenOam_BslDiagram230Degrees,
    [PAUSE_OAM_ID_BSL_DIAGRAM_240_DEGREES] = sPauseScreenOam_BslDiagram240Degrees,
    [PAUSE_OAM_ID_BSL_DIAGRAM_250_DEGREES] = sPauseScreenOam_BslDiagram250Degrees,
    [PAUSE_OAM_ID_BSL_DIAGRAM_260_DEGREES] = sPauseScreenOam_BslDiagram260Degrees,
    [PAUSE_OAM_ID_BSL_DIAGRAM_270_DEGREES] = sPauseScreenOam_BslDiagram270Degrees,
    [PAUSE_OAM_ID_BSL_DIAGRAM_280_DEGREES] = sPauseScreenOam_BslDiagram280Degrees,
    [PAUSE_OAM_ID_BSL_DIAGRAM_290_DEGREES] = sPauseScreenOam_BslDiagram290Degrees,
    [PAUSE_OAM_ID_BSL_DIAGRAM_300_DEGREES] = sPauseScreenOam_BslDiagram300Degrees,
    [PAUSE_OAM_ID_BSL_DIAGRAM_310_DEGREES] = sPauseScreenOam_BslDiagram310Degrees,
    [PAUSE_OAM_ID_BSL_DIAGRAM_320_DEGREES] = sPauseScreenOam_BslDiagram320Degrees,
    [PAUSE_OAM_ID_BSL_DIAGRAM_330_DEGREES] = sPauseScreenOam_BslDiagram330Degrees,
    [PAUSE_OAM_ID_BSL_DIAGRAM_340_DEGREES] = sPauseScreenOam_BslDiagram340Degrees,
    [PAUSE_OAM_ID_BSL_DIAGRAM_350_DEGREES] = sPauseScreenOam_BslDiagram350Degrees,
};

static u16** sNavConversationTextPointers[LANGUAGE_COUNT] = {
    [LANGUAGE_JAPANESE] = (u16**)0x879CE10,
    [LANGUAGE_HIRAGANA] = (u16**)0x879D194,
    [LANGUAGE_ENGLISH] = (u16**)0x879D50C,
    [LANGUAGE_GERMAN] = (u16**)0x879D890,
    [LANGUAGE_FRENCH] = (u16**)0x879DC14,
    [LANGUAGE_ITALIAN] = (u16**)0x879DF98,
    [LANGUAGE_SPANISH] = (u16**)0x879E31C
};

static u16** sPauseScreenTextPointers[LANGUAGE_COUNT] = {
    [LANGUAGE_JAPANESE] = (u16**)0x879CFD8,
    [LANGUAGE_HIRAGANA] = (u16**)0x879D35C,
    [LANGUAGE_ENGLISH] = (u16**)0x879D6D4,
    [LANGUAGE_GERMAN] = (u16**)0x879DA58,
    [LANGUAGE_FRENCH] = (u16**)0x879DDDC,
    [LANGUAGE_ITALIAN] = (u16**)0x879E160,
    [LANGUAGE_SPANISH] = (u16**)0x879E4E4
};

/**
 * @brief 765f8 | 2ac | Main handler for the pause screen
 * 
 * @return s32 bool, leaving pause screen
*/
bools32 PauseScreenHandler(void)
{
    bools32 leaving;
    s32 unk_0;
    s32 evaDiff;

    gNextOamSlot = 0;
    leaving = FALSE;

    switch (gUnk_3000b85)
    {
        case 0:
            gUnk_3000b85 = PauseScreenInit();
            break;

        case 1:
            unk_0 = PAUSE_SCREEN_DATA.unk_0;
            if (unk_0 != 0)
            {
                if (gPauseScreenFlag == 4)
                {
                    if (C_16_2_8(gWrittenToBldalpha_Evb, gWrittenToBldalpha_Eva) != C_16_2_8(5, 8))
                    {
                        if (gWrittenToBldalpha_Eva != 8)
                        {
                            gWrittenToBldalpha_Eva++;
                            if (gWrittenToBldalpha_Eva > 8)
                                gWrittenToBldalpha_Eva = 8;
                        }

                        if (gWrittenToBldalpha_Evb != 5)
                            gWrittenToBldalpha_Evb++;
                    }
                    else
                    {
                        gUnk_3000b85++;
                        WRITE_16(REG_BLDCNT, BLDCNT_BG2_FIRST_TARGET_PIXEL |
                            BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_SCREEN_SECOND_TARGET);
                    }
                }
                else
                {
                    if (C_16_2_8(gWrittenToBldalpha_Evb, gWrittenToBldalpha_Eva) != C_16_2_8(5, 8))
                    {
                        if (gWrittenToBldalpha_Eva != 8)
                        {
                            gWrittenToBldalpha_Eva += 2;
                            if (gWrittenToBldalpha_Eva > 8)
                                gWrittenToBldalpha_Eva = 8;
                        }
    
                        if (gWrittenToBldalpha_Evb != 5)
                            gWrittenToBldalpha_Evb++;
                    }
                    else
                    {
                        gUnk_3000b85++;
                        WRITE_16(REG_BLDCNT, BLDCNT_BG2_FIRST_TARGET_PIXEL |
                            BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_SCREEN_SECOND_TARGET);
                    }
                }

                WRITE_16(REG_BLDALPHA, C_16_2_8(gWrittenToBldalpha_Evb, gWrittenToBldalpha_Eva));
            }
            else if (gWrittenToBldy != 0)
            {
                if (gWrittenToBldy > 4)
                    gWrittenToBldy -= 4;
                else
                    gWrittenToBldy = unk_0;
            }
            else
            {
                gUnk_3000b85++;
                WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_SECOND_TARGET);
                WRITE_16(REG_BLDALPHA, C_16_2_8(4, 12));
            }
            break;

        case 2:
            if (PauseScreenCallCurrentHandler())
            {
                if (PAUSE_SCREEN_DATA.unk_0 != 0)
                {
                    WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET |
                        BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_SCREEN_SECOND_TARGET);
                    gWrittenToBldalpha_Eva = READ_16(REG_BLDALPHA);
                    gWrittenToBldalpha_Evb = HIGH_BYTE(gWrittenToBldalpha_Eva);
                    gWrittenToBldalpha_Eva = LOW_BYTE(gWrittenToBldalpha_Eva);
                }
                else
                {
                    gWrittenToBldy = 0;
                    WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET |
                        BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BRIGHTNESS_INCREASE_EFFECT);
                }

                gUnk_3000b85++;
            }

            if (PAUSE_SCREEN_DATA.unk_264 == 0)
            {
                unk_7c440();
                unk_7cfb0();
            }
            break;

        case 3:
            if (PAUSE_SCREEN_DATA.unk_0 != 0)
            {
                if (gPauseScreenFlag == 4)
                    evaDiff = 1;
                else
                    evaDiff = 2;

                if ((gWrittenToBldalpha_Evb | gWrittenToBldalpha_Eva) != 0)
                {
                    if (gWrittenToBldalpha_Eva >= evaDiff)
                        gWrittenToBldalpha_Eva -= evaDiff;
                    else
                        gWrittenToBldalpha_Eva = 0;

                    if (gWrittenToBldalpha_Evb != 0)
                        gWrittenToBldalpha_Evb--;
                }
                else
                {
                    gUnk_3000b85++;
                }

                WRITE_16(REG_BLDALPHA, C_16_2_8(gWrittenToBldalpha_Evb, gWrittenToBldalpha_Eva));
            }
            else if (gWrittenToBldy < BLDY_MAX_VALUE)
            {
                gWrittenToBldy += 4;
                if (gWrittenToBldy > BLDY_MAX_VALUE)
                    gWrittenToBldy = BLDY_MAX_VALUE;
            }
            else
            {
                gUnk_3000b85++;
            }
            break;

        case 4:
            if (gPauseScreenFlag == 3 && gEventCounter == EVENT_NAVIGATION_ROOM_LEAVING_SRX_2 &&
                gPreviousCutscene != CUTSCENE_MONOLOGUE_FEDERATION)
            {
                gPauseScreenFlag = 5;
                gCurrentCutscene = CUTSCENE_MONOLOGUE_FEDERATION;
                DmaTransfer(3, EWRAM_BASE + 0x1C000, VRAM_BASE + 0x10000, 0x8000, 32);
            }

            leaving = TRUE;
            gUnk_3000b85 = 0;
            break;
    }

    PauseScreenMapUpdateArrowsAndBlinkingSquare();
    PauseScreenProcessOam();
    ResetFreeOam();

    return leaving;
}

/**
 * @brief 768a4 | 84 | Pause screen V-blank
 * 
*/
void PauseScreenVBlank(void)
{
    DMA3_COPY_32(gOamData, OAM_BASE, OAM_SIZE / sizeof(u32));

    WRITE_16(REG_DISPCNT, PAUSE_SCREEN_DATA.dispcnt);
    WRITE_16(REG_BLDY, gWrittenToBldy);
    WRITE_16(REG_MOSAIC, gWrittenToMosaic_L);

    WRITE_16(REG_BG0HOFS, gBackgroundPositions.bg[0].x);
    WRITE_16(REG_BG0VOFS, gBackgroundPositions.bg[0].y);
    WRITE_16(REG_BG1HOFS, gBackgroundPositions.bg[1].x);
    WRITE_16(REG_BG1VOFS, gBackgroundPositions.bg[1].y);
    WRITE_16(REG_BG2HOFS, gBackgroundPositions.bg[2].x);
    WRITE_16(REG_BG2VOFS, gBackgroundPositions.bg[2].y);
    WRITE_16(REG_BG3HOFS, gBackgroundPositions.bg[3].x);
    WRITE_16(REG_BG3VOFS, gBackgroundPositions.bg[3].y);
}

/**
 * @brief 76928 | 5c | Pause screen V-blank (unused)
 * 
*/
void PauseScreenVBlank_Unused(void)
{
    WRITE_16(REG_BG3HOFS, 0);
    WRITE_16(REG_BG3VOFS, 0);

    WRITE_16(REG_DISPCNT, PAUSE_SCREEN_DATA.dispcnt);
    
    if (gWrittenToBg3cnt != 0)
    {
        WRITE_16(REG_BG3CNT, gWrittenToBg3cnt);
        gWrittenToBg3cnt = 0;
    }
    
    WRITE_16(REG_BLDALPHA, C_16_2_8(gWrittenToBldalpha_Evb, gWrittenToBldalpha_Eva));
}

/**
 * @brief 76984 | c | V-blank during PauseScreenInit
 * 
*/
void PauseScreenInitVBlank(void)
{
    UpdateAudio();
}

/**
 * @brief 76990 | 6f4 | Initializes the pause screen
 * 
 * @return s32 bool, always true
*/
bools32 PauseScreenInit(void)
{
    bools32 result;
    s32 i;

    CallbackSetVBlank(PauseScreenInitVBlank);

    result = TRUE;
    
    WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET |
        BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BRIGHTNESS_INCREASE_EFFECT);
    WRITE_16(REG_BLDY, gWrittenToBldy = BLDY_MAX_VALUE);
    WRITE_16(REG_DISPCNT, 0);
    PAUSE_SCREEN_DATA.dispcnt = 0;

    gNextOamSlot = 0;
    BitFill(3, 0, &gNonGameplayRam, sizeof(gNonGameplayRam), 32);
    ResetFreeOam();

    DMA3_COPY_32(gOamData, OAM_BASE, OAM_SIZE / sizeof(u32));

    if (gPauseScreenFlag != 4)
    {
        DmaTransfer(3, VRAM_OBJ, gSpriteGfxBackup, sizeof(gSpriteGfxBackup), 16);
    }

    PAUSE_SCREEN_DATA.currentArea = gCurrentArea;
    PAUSE_SCREEN_DATA.mapX = gMinimapX;
    PAUSE_SCREEN_DATA.mapY = gMinimapY;
    PAUSE_SCREEN_DATA.enableDebug = FALSE;
    PAUSE_SCREEN_DATA.unk_0 = 1;

    if (gPauseScreenFlag == 3)
    {
        if (gCurrentArea == AREA_MAIN_DECK && gCurrentRoom == 0)
        {
            PAUSE_SCREEN_DATA.unk_0 = 2;
        }
    }
    else if (gPauseScreenFlag == 1)
    {
        PAUSE_SCREEN_DATA.unk_0 = 2;
        unk_36c4();
    }
    else if (gPauseScreenFlag != 4)
    {        
        PAUSE_SCREEN_DATA.unk_0 = 0;
    }

    DMA3_COPY_16(sMinimapTilesPal, PALRAM_BASE, 3 * PAL_ROW);

    CallLZ77UncompVram(sPauseScreenObjGfx, VRAM_OBJ);
    DmaTransfer(3, sMinimapTilesGfx, VRAM_BASE + 0x8000, 0x3800, 16);

    DMA3_COPY_16(sPauseScreenObjPal_565b48, PALRAM_OBJ, COLORS_IN_PAL);

    if (PAUSE_SCREEN_DATA.unk_0 == 0)
    {
        CallLZ77UncompVram(sPauseScreenBgGfx, VRAM_BASE);
        DMA3_COPY_16(sPauseScreenBgPal_565808, PALRAM_BASE + 3 * PAL_ROW_SIZE, 13 * PAL_ROW);
    }
    else if (PAUSE_SCREEN_DATA.unk_0 == 1)
    {
        CallLZ77UncompVram(sNavConversationRoomGfx, VRAM_BASE);

        if (gEquipment.suitMiscStatus & SMF_GRAVITY_SUIT)
            i = 2;
        else if (gEquipment.suitMiscStatus & SMF_VARIA_SUIT)
            i = 1;
        else
            i = 0;

        if (i != 0)
        {
            DMA3_COPY_16(sNavConversationSamusPal + i * PAL_ROW_SIZE, PALRAM_OBJ, 1 * PAL_ROW);
        }
    }
    else
    {
        CallLZ77UncompVram(sNavConversationShipGfx, VRAM_BASE);
    }

    if (PAUSE_SCREEN_DATA.unk_0 != 0)
    {
        DMA3_COPY_16(VRAM_BASE + 0x9800, VRAM_BASE + 0x9400, 0x200);
        DMA3_COPY_16(sPauseScreenBgPal_5659a8, PALRAM_BASE + 3 * PAL_ROW_SIZE, 13 * PAL_ROW);
    }

    SET_BACKDROP_COLOR(COLOR_BLACK);

    MinimapGetData(MINIMAP_BLANK, gMinimapData);

    DMA3_COPY_16(gMinimapData, VRAM_BASE + 0xE800, MINIMAP_SIZE);
    DMA3_COPY_16(gMinimapData, VRAM_BASE + 0xF000, MINIMAP_SIZE);
    DMA3_COPY_16(gMinimapData, VRAM_BASE + 0xF800, MINIMAP_SIZE);
    // Written this way to produce matching ASM
    i = gCurrentArea;
    if (i > UCHAR_MAX)
        i = UCHAR_MAX;
    DMA3_COPY_16(gMinimapData_Visited, VRAM_BASE + 0xE000, MINIMAP_SIZE);
    
    CallLZ77UncompVram(sNavConversationTextBoxesTilemap, EWRAM_BASE + 0x0F800);

    DMA3_COPY_16(gPauseScreenBg0, VRAM_BASE + 0xC000, ARRAY_SIZE(gPauseScreenBg0));
    
    if (PAUSE_SCREEN_DATA.unk_0 == 0)
    {
        if (PAUSE_SCREEN_DATA.enableDebug)
            CallLZ77UncompVram(sPauseDebugTilemap, gMinimapData);
        else
            CallLZ77UncompVram(sStatusScreenTilemap, gMinimapData);

        DMA3_COPY_16(gMinimapData, VRAM_BASE + 0xC800, MINIMAP_SIZE);
    }
    else if (PAUSE_SCREEN_DATA.unk_0 == 1)
    {
        CallLZ77UncompVram(sNavConversationRoomTilemap, gMinimapData);
        DMA3_COPY_16(gMinimapData, VRAM_BASE + 0xD800, MINIMAP_SIZE);
    }
    else
    {
        CallLZ77UncompVram(sNavConversationShipTilemap, gMinimapData);
        DMA3_COPY_16(gMinimapData, VRAM_BASE + 0xD800, MINIMAP_SIZE);
    }

    if (PAUSE_SCREEN_DATA.unk_0 == 0)
    {
        CallLZ77UncompVram(sMapScreenOutlineTilemap, gMinimapData);
        DMA3_COPY_16(gMinimapData, VRAM_BASE + 0xD000, MINIMAP_SIZE);
        CallLZ77UncompVram(sPauseScreenSleepTilemap, gPauseScreenSleepTilemap);
    }
    else
    {
        if (gPauseScreenFlag != 4)
            CallLZ77UncompVram(sUnk_573da4, gMinimapData);
        else
            CallLZ77UncompVram(sUnk_573da4, gMinimapData);

        DMA3_COPY_16(gMinimapData, VRAM_BASE + 0xD000, MINIMAP_SIZE);
    }

    MinimapGetData(gCurrentArea, gMinimapData);

    for (i = 0; i < ARRAY_SIZE(gBackgroundPositions.bg); i++)
    {
        gBackgroundPositions.bg[i].x = 0;
        gBackgroundPositions.bg[i].y = 0;
    }

    PAUSE_SCREEN_DATA.subMenuStage = 0;
    PAUSE_SCREEN_DATA.unk_9 = 0;
    PAUSE_SCREEN_DATA.timer = 0;
    PAUSE_SCREEN_DATA.unk_8 = 0;
    PAUSE_SCREEN_DATA.unk_28 = sUnk_79be88;
    gBackgroundPositions.bg[1].y = 0x100;
    PAUSE_SCREEN_DATA.unk_1 = 3;

    if (PAUSE_SCREEN_DATA.unk_0 != 0)
        PAUSE_SCREEN_DATA.unk_1 = 1;
    else if (gPauseScreenFlag == 2)
        PAUSE_SCREEN_DATA.unk_1 = 0;
    else
        PAUSE_SCREEN_DATA.unk_1 = 2;

    if (PAUSE_SCREEN_DATA.unk_0 != 0)
    {
        if (EventCheckSetNavigationRoomEvent())
        {
            PAUSE_SCREEN_DATA.unk_28.unk_0 = 4;
            MinimapGetData(gCurrentArea, gMinimapData_Visited);
            MinimapSetVisitedTilesAndCollectedItems(gCurrentArea);
        }
        else
        {
            PAUSE_SCREEN_DATA.unk_28.unk_0 = 0xA;
        }

        if (gEventCounter < EVENT_RESTRICTED_LABORATORY_EXPLOSION)
        {
            DMA3_FILL_32(0, VRAM_OBJ + 0x7C00, 0x40);
        }
    }

    if (PAUSE_SCREEN_DATA.enableDebug)
        PauseDebugDrawEverything();
    else
        StatusScreenDrawEverything();

    unk_75988(0);
    ProcessPauseScreenText();
    ProcessEasySleepText();
    PauseScreenSetupOam();

    NavigationConversationGetCurrentConversation();
    NavigationConversationLoadPopUpGraphics();
    NavigationConversationLoadSpecialGraphics();
    PauseScreenUpdateObjectiveTextBox(UCHAR_MAX);
    unk_7ce6c();

    WRITE_16(REG_BG0HOFS, gBackgroundPositions.bg[0].x);
    WRITE_16(REG_BG0VOFS, gBackgroundPositions.bg[0].y);
    WRITE_16(REG_BG1HOFS, gBackgroundPositions.bg[1].x);
    WRITE_16(REG_BG1VOFS, gBackgroundPositions.bg[1].y);
    WRITE_16(REG_BG2HOFS, gBackgroundPositions.bg[2].x);
    WRITE_16(REG_BG2VOFS, gBackgroundPositions.bg[2].y);
    WRITE_16(REG_BG3HOFS, gBackgroundPositions.bg[3].x);
    WRITE_16(REG_BG3VOFS, gBackgroundPositions.bg[3].y);

    gWrittenToBldy = 0;
    gWrittenToBldalpha_Evb = 0;
    gWrittenToBldalpha_Eva = BLDALPHA_MAX_VALUE;

    if (PAUSE_SCREEN_DATA.unk_0 != 0)
    {
        gWrittenToBldalpha_Evb = 0;
        gWrittenToBldalpha_Eva = 0;
        WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET |
            BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_SCREEN_SECOND_TARGET);
        WRITE_16(REG_BLDALPHA, C_16_2_8(gWrittenToBldalpha_Evb, gWrittenToBldalpha_Eva));
    }
    else
    {
        gWrittenToBldy = BLDY_MAX_VALUE;
        WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET |
            BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BRIGHTNESS_INCREASE_EFFECT);
    }

    WRITE_16(REG_WIN0H, SCREEN_SIZE_X);

    if (PAUSE_SCREEN_DATA.unk_0 != 0)
    {
        WRITE_8(REG_WINOUT, WIN0_BG0 | WIN0_BG1 | WIN0_BG2 | WIN0_OBJ | WIN0_COLOR_EFFECT);
        WRITE_8(REG_WININ + 1, WIN0_ALL);
    }
    else
    {
        WRITE_8(REG_WINOUT, WIN0_BG0 | WIN0_BG2 | WIN0_OBJ | WIN0_COLOR_EFFECT);
        WRITE_8(REG_WININ + 1, WIN0_BG0 | WIN0_BG2 | WIN0_BG3 | WIN0_OBJ | WIN0_COLOR_EFFECT);
    }

    WRITE_8(REG_WININ, WIN0_ALL);

    if (PAUSE_SCREEN_DATA.unk_28.unk_0 != 1)
        i = SCREEN_SIZE_Y;
    else
        i = 0;

    WRITE_16(REG_WIN0V, C_16_2_8(i, SCREEN_SIZE_Y));
    WRITE_16(REG_WIN1H, SCREEN_SIZE_X);
    WRITE_16(REG_WIN1V, SCREEN_SIZE_Y);
    gWrittenToMosaic_L = 0;
    WRITE_16(REG_MOSAIC, 0);

    if (PAUSE_SCREEN_DATA.unk_0 != 0)
    {
        WRITE_16(REG_BG1CNT, CREATE_BGCNT(0, 27, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256));
        WRITE_16(REG_BG3CNT, CREATE_BGCNT(2, 28, BGCNT_HIGH_MID_PRIORITY, 3) | BGCNT_MOSAIC);
        WRITE_16(REG_BG0CNT, CREATE_BGCNT(0, 24, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
        PAUSE_SCREEN_DATA.dispcnt = DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3 | DCNT_OBJ | DCNT_WIN1;

        if (gPauseScreenFlag == 4)
        {
            WRITE_16(REG_BG2CNT, CREATE_BGCNT(2, 26, BGCNT_LOW_MID_PRIORITY, BGCNT_SIZE_256x256));
            PAUSE_SCREEN_DATA.dispcnt ^= DCNT_BG3;
        }
        else
        {
            WRITE_16(REG_BG2CNT, CREATE_BGCNT(2, 26, BGCNT_LOW_MID_PRIORITY, BGCNT_SIZE_256x256));
        }
    }
    else
    {
        WRITE_16(REG_BG3CNT, CREATE_BGCNT(2, 28, BGCNT_LOW_PRIORITY, 3) | BGCNT_MOSAIC);
        WRITE_16(REG_BG2CNT, CREATE_BGCNT(0, 26, BGCNT_LOW_MID_PRIORITY, BGCNT_SIZE_256x256));
        WRITE_16(REG_BG0CNT, CREATE_BGCNT(0, 24, BGCNT_HIGH_MID_PRIORITY, BGCNT_SIZE_256x256));
        WRITE_16(REG_BG1CNT, CREATE_BGCNT(0, 25, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
        PAUSE_SCREEN_DATA.dispcnt = DCNT_BG1 | DCNT_BG2 | DCNT_BG3 | DCNT_OBJ | DCNT_WIN0 | DCNT_WIN1;
    }

    CallbackSetVBlank(PauseScreenVBlank);
    WRITE_16(REG_DISPCNT, PAUSE_SCREEN_DATA.dispcnt);

    return result;
}

/**
 * @brief 77084 | 30 | Decompresses minimap data to the provided address
 * 
 * @param index Minimap index
 * @param dst Destination pointer
*/
void MinimapGetData(u8 index, void* dst)
{
    if (index == MINIMAP_MAIN_DECK && gEventCounter >= EVENT_ESCAPED_RESTRICTED_LABORATORY)
        index = MINIMAP_MAIN_DECK_NO_LAB;

    CallLZ77UncompVram(sMinimapData[index], dst);
}

/**
 * @brief 770b4 | 1bc | Calls the handler for the current state of the pause screen
 * 
 * @return s32 bool, close pause screen
*/
bools32 PauseScreenCallCurrentHandler(void)
{
    bools32 close;

    close = FALSE;

    if (PAUSE_SCREEN_DATA.unk_28.unk_0 != 2 && PAUSE_SCREEN_DATA.unk_28.unk_0 != 3)
        CheckForMaintainedInput();
    
    APPLY_DELTA_TIME_INC(PAUSE_SCREEN_DATA.timer);

    switch (PAUSE_SCREEN_DATA.unk_28.unk_0)
    {
        case 0:
            if (gChangedInput & (gButtonAssignments.pause | KEY_B))
                close = TRUE;
            else
                PauseScreenMapHandler();
            break;
        
        case 1:
            if (PAUSE_SCREEN_DATA.enableDebug)
            {
                PauseDebugMoveCursor();
                PauseDebugHandler();
            }
            else
            {
                StatusScreenHandler();
            }
            break;

        case 2:
            close = TRUE;
            break;
        
        case 3:
            if (PAUSE_SCREEN_DATA.unk_264 != 0)
            {
                unk_7c630();
            }
            else
            {
                NavigationConversationUpdatePopUp();
                
                if (NavigationConversationHandler() != 0)
                    PAUSE_SCREEN_DATA.unk_28.unk_0 = 9;
            }
            break;
        
        case 4:
            if (PauseScreenMapDownload())
                PAUSE_SCREEN_DATA.unk_28.unk_0 = 8;
            break;
        
        case 5:
            if (EasySleepMenuHandler() != 0)
                PAUSE_SCREEN_DATA.unk_28.unk_0 = 0xC;
            break;
        
        case 6:
            if (PauseDebugScreenAppearing())
            {
                PAUSE_SCREEN_DATA.unk_28.unk_0 = 1;
                PAUSE_SCREEN_DATA.subMenuStage = 0;
                PAUSE_SCREEN_DATA.timer = 0;
            }
            break;
        
        case 7:
            if (PauseDebugWindowDisappearing())
            {
                PAUSE_SCREEN_DATA.unk_28.unk_0 = 0;
                PAUSE_SCREEN_DATA.subMenuStage = 0;
                PAUSE_SCREEN_DATA.timer = 0;
            }
            break;
        
        case 8:
        case 10:
            PAUSE_SCREEN_DATA.unk_28.unk_0 = 3;
            PAUSE_SCREEN_DATA.unk_C = 0;
            PAUSE_SCREEN_DATA.unk_E[0] = 0;
            PAUSE_SCREEN_DATA.unk_E[1] = 0;
            PAUSE_SCREEN_DATA.unk_E[2] = 0;
            PAUSE_SCREEN_DATA.unk_E[3] = 0;
            PAUSE_SCREEN_DATA.unk_8 = 0;
            PAUSE_SCREEN_DATA.unk_9 = 0;
            PAUSE_SCREEN_DATA.unk_A = 0;
            PAUSE_SCREEN_DATA.unk_B = 0;
            
            PAUSE_SCREEN_DATA.subMenuStage = 0;
            PAUSE_SCREEN_DATA.timer = 0;
            break;
        
        case 9:
            if (PAUSE_SCREEN_DATA.unk_0 != 0)
            {
                PAUSE_SCREEN_DATA.unk_28.unk_0 = 2;
            }
            else
            {
                PAUSE_SCREEN_DATA.unk_28.unk_0 = 0;
                PauseScreenUpdateObjectiveTextBox(4);
            }
            break;
        
        case 11:
            if (PauseScreenEasySleepMenuInit())
            {
                PAUSE_SCREEN_DATA.unk_28.unk_0 = 5;
                PAUSE_SCREEN_DATA.subMenuStage = 0;
                PAUSE_SCREEN_DATA.timer = 0;
            }
            break;

        case 12:
            if (PauseScreenEasySleepMenuQuit())
            {
                PAUSE_SCREEN_DATA.unk_28.unk_0 = 0;
                PAUSE_SCREEN_DATA.subMenuStage = 0;
                PAUSE_SCREEN_DATA.timer = 0;
            }
            break;
    }

    return close;
}

/**
 * @brief 77270 | a8 | Handles moving the cursor on the pause debug screen
 * 
*/
void PauseDebugMoveCursor(void)
{
    bools32 notEditing;

    notEditing = !(gButtonInput & KEY_A) && PAUSE_SCREEN_DATA.subMenuStage == 0;

    if (notEditing)
    {
        if (gChangedInput & KEY_UP)
        {
            if (PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_PAUSE_DEBUG_CURSOR].yPosition != 0)
                PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_PAUSE_DEBUG_CURSOR].yPosition -= TILE_DIM;
        }
        else if (gChangedInput & KEY_DOWN)
        {
            if (PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_PAUSE_DEBUG_CURSOR].yPosition < 18 * TILE_DIM)
                PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_PAUSE_DEBUG_CURSOR].yPosition += TILE_DIM;
        }

        if (gChangedInput & KEY_RIGHT)
        {
            if (PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_PAUSE_DEBUG_CURSOR].xPosition < 29 * TILE_DIM)
                PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_PAUSE_DEBUG_CURSOR].xPosition += TILE_DIM;
        }
        else if (gChangedInput & KEY_LEFT)
        {
            if (PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_PAUSE_DEBUG_CURSOR].xPosition != 0)
                PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_PAUSE_DEBUG_CURSOR].xPosition -= TILE_DIM;
        }
    }
}

/**
 * @brief 77318 | 6c | Moves a background to the provided X position
 * 
 * @return s32 bool, target reached
*/
bools32 PauseScreenMoveBackgroundToXPosition(u8 bg, u16 target)
{
    bools32 reached;
    s32 direction;
    s32 timer;
    s32 xPosition;

    reached = FALSE;

    if (gBackgroundPositions.bg[bg].x > target)
        direction = -1;
    else
        direction = 1;

    if (PAUSE_SCREEN_DATA.timer + 4 < 32)
    {
        timer = PAUSE_SCREEN_DATA.timer + 4;
        gBackgroundPositions.bg[bg].x += direction * timer;
    }
    else
    {
        gBackgroundPositions.bg[bg].x += direction * 32;
    }

    if (direction > 0)
    {
        if (gBackgroundPositions.bg[bg].x >= target)
        {
            gBackgroundPositions.bg[bg].x = target;
            reached = TRUE;
        }
    }
    else
    {
        xPosition = (s16)gBackgroundPositions.bg[bg].x;
        if (xPosition <= target)
        {
            direction = target;
            gBackgroundPositions.bg[bg].x += direction - xPosition;
            reached = TRUE;
        }
    }

    return reached;
}

/**
 * @brief 77384 | 74 | Moves a background to the provided Y position
 * 
 * @return s32 bool, target reached
*/
bools32 PauseScreenMoveBackgroundToYPosition(u8 bg, u16 target)
{
    bools32 reached;
    s32 direction;
    s32 yPosition;

    reached = FALSE;

    if (gBackgroundPositions.bg[bg].y > target)
        direction = -1;
    else
        direction = 1;

    if (PAUSE_SCREEN_DATA.timer + 4 < 32)
        gBackgroundPositions.bg[bg].y += direction * (PAUSE_SCREEN_DATA.timer + 4);
    else
        gBackgroundPositions.bg[bg].y += direction * 32;

    if (direction > 0)
    {
        if (gBackgroundPositions.bg[bg].y >= target)
            reached = TRUE;
    }
    else
    {
        yPosition = (s16)gBackgroundPositions.bg[bg].y;
        if (yPosition <= target)
            reached = TRUE;
    }

    if (reached)
        gBackgroundPositions.bg[bg].y = target;

    return reached;
}

/**
 * @brief 773f8 | 28 | Sets the window for the pause debug screen
 * 
*/
void PauseDebugSetWindow(void)
{
    s32 yPosition;

    yPosition = 0x200 - gBackgroundPositions.bg[1].y;
    if (yPosition > SCREEN_SIZE_Y)
        yPosition = SCREEN_SIZE_Y;

    WRITE_16(REG_WIN0V, C_16_2_8(yPosition, SCREEN_SIZE_Y));
}

/**
 * @brief 77420 | 80 | Handles the pause debug screen appearing
 * 
 * @return s32 bool, done appearing
*/
bools32 PauseDebugScreenAppearing(void)
{
    bools32 done;

    done = FALSE;

    switch (PAUSE_SCREEN_DATA.subMenuStage)
    {
        case 0:
            SoundPlay(SOUND_200);
            UpdateMenuOamDataId(PAUSE_OAM_IDX_STATUS_BUTTON, PAUSE_OAM_ID_STATUS_BUTTON_SELECTED);
            PAUSE_SCREEN_DATA.subMenuStage = 2;
            PAUSE_SCREEN_DATA.timer = 0;
            break;

        case 1:
            if (PAUSE_SCREEN_DATA.timer > CONVERT_SECONDS(4/15.f))
            {
                PAUSE_SCREEN_DATA.subMenuStage = 2;
                PAUSE_SCREEN_DATA.timer = 0;
            }
            break;

        case 2:
            if (PauseScreenMoveBackgroundToYPosition(1, 0x200))
            {
                UpdateMenuOamDataId(PAUSE_OAM_IDX_STATUS_BUTTON, PAUSE_OAM_ID_STATUS_BUTTON);
                UpdateMenuOamDataId(PAUSE_OAM_IDX_SLEEP_BUTTON, PAUSE_OAM_ID_SLEEP_BUTTON);
                PauseScreenUpdateObjectiveTextBox(3);
                
                if (PAUSE_SCREEN_DATA.enableDebug != 0)
                    PauseDebugSetupCursor();
                
                done = TRUE;
            }
            
            PauseDebugSetWindow();
            break;
    }

    return done;
}

/**
 * @brief 774a0 | 60 | Handles the pause debug screen disappearing
 * 
 * @return s32 bool, done appearing
*/
bools32 PauseDebugWindowDisappearing(void)
{
    bools32 done;

    done = FALSE;

    switch (PAUSE_SCREEN_DATA.subMenuStage)
    {
        case 0:
            SoundPlay(SOUND_201);
            PauseScreenUpdateObjectiveTextBox(4);
            PAUSE_SCREEN_DATA.subMenuStage = 2;
            PAUSE_SCREEN_DATA.timer = 0;
            break;

        case 1:
            if (PAUSE_SCREEN_DATA.timer > CONVERT_SECONDS(1/15.f))
            {
                PAUSE_SCREEN_DATA.subMenuStage = 2;
                PAUSE_SCREEN_DATA.timer = 0;
            }
            break;

        case 2:
            if (PauseScreenMoveBackgroundToYPosition(1, 0x100))
                done = TRUE;

            PauseDebugSetWindow();
            break;
    }

    return done;
}

/**
 * @brief 77500 | 220 | Initializes the easy sleep menu
 * 
 * @return s32 bool, done initializing
*/
bools32 PauseScreenEasySleepMenuInit(void)
{
    bools32 done;
    bools32 update;

    done = FALSE;
    update = FALSE;

    switch (PAUSE_SCREEN_DATA.subMenuStage)
    {
        case 0:
            SoundPlay(SOUND_202);
            UpdateMenuOamDataId(PAUSE_OAM_IDX_SLEEP_BUTTON, PAUSE_OAM_ID_SLEEP_BUTTON_SELECTED);
            PauseScreenUpdateObjectiveTextBox(3);
            update = TRUE;
            break;

        case 1:
            DMA3_COPY_16(EWRAM_BASE + 0x10000, VRAM_BASE + 0xC000, 0x400);
            update = TRUE;
            break;

        case 2:
            WRITE_16(REG_BLDCNT, BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_BG2_FIRST_TARGET_PIXEL |
                BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL | BLDCNT_BACKDROP_FIRST_TARGET_PIXEL |
                BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BRIGHTNESS_INCREASE_EFFECT | BLDCNT_SCREEN_SECOND_TARGET);
            WRITE_16(REG_BLDALPHA, BLDALPHA_MAX_VALUE);
            update = TRUE;
            break;

        case 3:
            DMA3_COPY_16(EWRAM_BASE + 0xF000, EWRAM_BASE + 0xD380, 0x40);
            DMA3_COPY_16(EWRAM_BASE + 0xF400, EWRAM_BASE + 0xD780, 0x40);
            DMA3_COPY_16(EWRAM_BASE + 0xF080, EWRAM_BASE + 0xDB80, 0x40);
            DMA3_COPY_16(EWRAM_BASE + 0xF480, EWRAM_BASE + 0xDF80, 0x40);
            update = TRUE;
            break;

        case 4:
            DMA3_COPY_16(EWRAM_BASE + 0xF1C0, EWRAM_BASE + 0xE380, 0x40);
            DMA3_COPY_16(EWRAM_BASE + 0xF5C0, EWRAM_BASE + 0xE780, 0x40);
            DMA3_COPY_16(EWRAM_BASE + 0xF240, EWRAM_BASE + 0xEB80, 0x40);
            DMA3_COPY_16(EWRAM_BASE + 0xF640, EWRAM_BASE + 0xEF80, 0x40);
            update = TRUE;
            break;

        case 5:
            DmaTransfer(3, EWRAM_BASE + 0xD000, VRAM_BASE + 0x6000, 0x1000, 16);
            update = TRUE;
            break;

        case 6:
            DmaTransfer(3, EWRAM_BASE + 0xE000, VRAM_BASE + 0x7000, 0x1000, 16);
            update = TRUE;
            break;

        case 7:
            if (PAUSE_SCREEN_DATA.timer > 1 * DELTA_TIME)
            {
                PAUSE_SCREEN_DATA.timer = 0;

                if (gWrittenToBldy < 12)
                {
                    gWrittenToBldy++;
                    if (gWrittenToBldy == 6)
                    {
                        PAUSE_SCREEN_DATA.dispcnt |= DCNT_BG0;
                        UpdateMenuOamDataId(PAUSE_OAM_IDX_CURSOR, PAUSE_OAM_ID_YES_NO_CURSOR);
                        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_CURSOR].xPosition = 0x8C;
                        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_CURSOR].yPosition = 0x44;
                        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_CURSOR].objMode = 1;
                    }
                }
                else
                {
                    UpdateMenuOamDataId(PAUSE_OAM_IDX_STATUS_BUTTON, PAUSE_OAM_ID_STATUS_BUTTON);
                    UpdateMenuOamDataId(PAUSE_OAM_IDX_SLEEP_BUTTON, PAUSE_OAM_ID_SLEEP_BUTTON);
                    update = TRUE;
                }
            }
            break;

        case 8:
            gDisableSoftReset = 1;
            done = TRUE;
            PAUSE_SCREEN_DATA.subMenuStage = 0;
            PAUSE_SCREEN_DATA.timer = 0;
            break;
    }

    if (update)
    {
        PAUSE_SCREEN_DATA.subMenuStage++;
        PAUSE_SCREEN_DATA.timer = 0;
    }
    
    return done;
}

/**
 * @brief 77720 | 120 | Quits the easy sleep menu
 * 
 * @return s32 bool, done quitting
*/
bools32 PauseScreenEasySleepMenuQuit(void)
{
    bools32 done;
    bools32 update;

    done = FALSE;
#ifdef BUGFIX
    update = FALSE;
#endif // BUGFIX
    
    switch (PAUSE_SCREEN_DATA.subMenuStage)
    {
        case 0:
            gDisableSoftReset = 0;
            update = TRUE;
            break;

        case 1:
            if (PAUSE_SCREEN_DATA.timer > 1 * DELTA_TIME)
            {
                PAUSE_SCREEN_DATA.timer = 0;

                if (gWrittenToBldy > 0)
                {
                    gWrittenToBldy--;
                    if (gWrittenToBldy == 6)
                    {
                        PAUSE_SCREEN_DATA.dispcnt &= ~DCNT_BG0;
                        UpdateMenuOamDataId(PAUSE_OAM_IDX_CURSOR, PAUSE_OAM_ID_NONE);
                        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_CURSOR].objMode = 0;
                    }
                    break;
                }

                update = TRUE;
            }
            break;

        case 2:
            update = TRUE;
            break;

        case 3:
            BitFill(3, 0, VRAM_BASE + 0x6000, 0x1000, 32);
            update = TRUE;
            break;
        
        case 4:
            DMA3_COPY_16(EWRAM_BASE + 0xF800, VRAM_BASE + 0xC000, 0x400);
            update = TRUE;
            break;
        
        case 5:
            WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_SECOND_TARGET);
            WRITE_16(REG_BLDALPHA, C_16_2_8(4, 12));
            PauseScreenUpdateObjectiveTextBox(4);
            update = TRUE;
            break;
        
        case 6:
            done = TRUE;
            PAUSE_SCREEN_DATA.subMenuStage = 0;
            PAUSE_SCREEN_DATA.timer = 0;
            break;
    }

    if (update)
    {
        PAUSE_SCREEN_DATA.subMenuStage++;
        PAUSE_SCREEN_DATA.timer = 0;
    }

    return done;
}

/**
 * @brief 77840 | 43c | Updates the OAM for the objective text box
 * 
 * @param action Transition action
*/
void PauseScreenUpdateObjectiveTextBox(u8 action)
{
    s32 update;

    update = 0;
    
    switch (PAUSE_SCREEN_DATA.unk_1)
    {
        case 0:
            update = 5;
            DmaTransfer(3, EWRAM_BASE + 0xC000, VRAM_BASE + 0x7000, 0x1000, 16);
            PAUSE_SCREEN_DATA.unk_1 = 8;
            break;

        case 3:
            update = 1;
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_OBJECTIVE].currentAnimationFrame = 9;
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_OBJECTIVE_TEXT_BOX_BACKGROUND].currentAnimationFrame = 9;
            DmaTransfer(3, EWRAM_BASE + 0xC000, VRAM_BASE + 0x7000, 0x1000, 16);
            PAUSE_SCREEN_DATA.unk_1 = 4;
            break;

        case 4:
            if (action == 1)
            {
                update = 2;
                PAUSE_SCREEN_DATA.dispcnt ^= DCNT_BG0;
                PAUSE_SCREEN_DATA.unk_1 = 5;
            }
            else if (action == 3)
            {
                update = 2;
                PAUSE_SCREEN_DATA.dispcnt &= ~DCNT_BG0;
                PAUSE_SCREEN_DATA.unk_1 = 6;
            }
            else if (action == 5)
            {
                update = 3;
                PAUSE_SCREEN_DATA.dispcnt &= ~DCNT_BG0;
                PAUSE_SCREEN_DATA.unk_1 = 6;
            }
            break;

        case 5:
            if (action == 2)
            {
                update = 1;
                PAUSE_SCREEN_DATA.dispcnt |= DCNT_BG0;
                PAUSE_SCREEN_DATA.unk_1 = 4;
                SoundPlay(SOUND_203);
            }
            else if (action == 3)
            {
                PAUSE_SCREEN_DATA.unk_1 = 7;
            }
            break;

        case 6:
            if (action == 4)
            {
                update = 1;
                PAUSE_SCREEN_DATA.dispcnt |= DCNT_BG0;
                DmaTransfer(3, EWRAM_BASE + 0xC000, VRAM_BASE + 0x7000, 0x1000, 16);
                PAUSE_SCREEN_DATA.unk_1 = 4;
            }
            break;

        case 7:
            if (action == 4)
            {
                PAUSE_SCREEN_DATA.dispcnt &= ~DCNT_BG0;
                DmaTransfer(3, EWRAM_BASE + 0xC000, VRAM_BASE + 0x7000, 0x1000, 16);
                PAUSE_SCREEN_DATA.unk_1 = 5;
            }
            break;

        case 8:
            if (action == 2)
            {
                update = 4;
                PAUSE_SCREEN_DATA.dispcnt |= DCNT_BG0;
                PAUSE_SCREEN_DATA.unk_1 = 9;
                SoundPlay(SOUND_203);
            }
            else if (action == 3 || action == 5)
            {
                update = 6;
                PAUSE_SCREEN_DATA.dispcnt &= ~DCNT_BG0;
                PAUSE_SCREEN_DATA.unk_1 = 0xB;
            }
            break;

        case 9:
            if (action == 1)
            {
                update = 5;
                PAUSE_SCREEN_DATA.dispcnt &= ~DCNT_BG0;
                PAUSE_SCREEN_DATA.unk_1 = 8;
            }
            else if (action == 3)
            {
                update = 6;
                PAUSE_SCREEN_DATA.dispcnt &= ~DCNT_BG0;
                PAUSE_SCREEN_DATA.unk_1 = 0xA;
            }
            else if (action == 5)
            {
                update = 6;
                PAUSE_SCREEN_DATA.dispcnt &= ~DCNT_BG0;
                PAUSE_SCREEN_DATA.unk_1 = 0xA;
            }
            break;

        case 10:
            if (action == 4)
            {
                update = 4;
                PAUSE_SCREEN_DATA.dispcnt |= DCNT_BG0;
                DmaTransfer(3, EWRAM_BASE + 0xC000, VRAM_BASE + 0x7000, 0x1000, 16);
                PAUSE_SCREEN_DATA.unk_1 = 9;
            }
            break;

        case 11:
            if (action == 4)
            {
                update = 5;
                PAUSE_SCREEN_DATA.dispcnt &= ~DCNT_BG0;
                DmaTransfer(3, EWRAM_BASE + 0xC000, VRAM_BASE + 0x7000, 0x1000, 16);
                PAUSE_SCREEN_DATA.unk_1 = 8;
            }
            break;
    }

    switch (update)
    {
        case 1:
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_OBJECTIVE].oamId = PAUSE_OAM_ID_OBJECTIVE_TEXT_BOX;
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_OBJECTIVE].priority = 2;
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_OBJECTIVE].objMode = 0;
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_OBJECTIVE_TEXT_BOX_BACKGROUND].oamId = PAUSE_OAM_ID_OBJECTIVE_TEXT_BOX_BACKGROUND;
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_OBJECTIVE_TEXT_BOX_BACKGROUND].priority = 2;
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_OBJECTIVE_TEXT_BOX_BACKGROUND].objMode = 1;

            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_OBJECTIVE].xPosition = 0x74;
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_OBJECTIVE].yPosition = 0x84;
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_OBJECTIVE_TEXT_BOX_BACKGROUND].xPosition = 0x74;
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_OBJECTIVE_TEXT_BOX_BACKGROUND].yPosition = 0x84;
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_BSL_DIAGRAM].xPosition = 0x1C;
            break;
        
        case 2:
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_OBJECTIVE].oamId = PAUSE_OAM_ID_NONE;
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_OBJECTIVE_TEXT_BOX_BACKGROUND].oamId = PAUSE_OAM_ID_NONE;
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_BSL_DIAGRAM].xPosition = -0x64;
            break;
        
        case 3:
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_OBJECTIVE].oamId = PAUSE_OAM_ID_NONE;
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_OBJECTIVE_TEXT_BOX_BACKGROUND].oamId = PAUSE_OAM_ID_NONE;
            break;
        
        case 4:
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_OBJECTIVE].oamId = PAUSE_OAM_ID_OBJECTIVE_TEXT_BOX;
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_OBJECTIVE].priority = 2;
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_OBJECTIVE].objMode = 0;
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_OBJECTIVE_TEXT_BOX_BACKGROUND].oamId = PAUSE_OAM_ID_OBJECTIVE_TEXT_BOX_BACKGROUND;
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_OBJECTIVE_TEXT_BOX_BACKGROUND].priority = 2;
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_OBJECTIVE_TEXT_BOX_BACKGROUND].objMode = 1;

            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_OBJECTIVE].xPosition = 0x74;
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_OBJECTIVE].yPosition = 0x84;
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_OBJECTIVE_TEXT_BOX_BACKGROUND].xPosition = 0x74;
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_OBJECTIVE_TEXT_BOX_BACKGROUND].yPosition = 0x84;

            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_OBJECTIVE].currentAnimationFrame = 9;
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_OBJECTIVE_TEXT_BOX_BACKGROUND].currentAnimationFrame = 9;
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_OBJECTIVE].animationDurationCounter = 0;
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_OBJECTIVE_TEXT_BOX_BACKGROUND].animationDurationCounter = 0;
            break;
        
        case 5:
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_OBJECTIVE_TEXT_BOX_BACKGROUND].oamId = PAUSE_OAM_ID_NONE;

            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_OBJECTIVE].oamId = PAUSE_OAM_ID_OBJECTIVE_BUTTON;
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_OBJECTIVE].xPosition = 0xCA;
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_OBJECTIVE].yPosition = 0x8E;
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_OBJECTIVE].currentAnimationFrame = 0;
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_OBJECTIVE].animationDurationCounter = 0;
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_OBJECTIVE].priority = 2;
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_OBJECTIVE].objMode = 0;
            break;
        
        case 6:
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_OBJECTIVE_TEXT_BOX_BACKGROUND].oamId = PAUSE_OAM_ID_NONE;
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_OBJECTIVE].oamId = PAUSE_OAM_ID_NONE;
            break;
    }
}

/**
 * @brief 77c7c | 1c4 | Updates the OAM for the scroll arrows and blinking square on the map
 * 
*/
void PauseScreenMapUpdateArrowsAndBlinkingSquare(void)
{
    bools32 isTarget;

    PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_BLINKING_SQUARE].xPosition = PAUSE_SCREEN_DATA.mapX * 8 - gBackgroundPositions.bg[3].x;
    PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_BLINKING_SQUARE].yPosition = PAUSE_SCREEN_DATA.mapY * 8 - gBackgroundPositions.bg[3].y;

    isTarget = TRUE;

    if (PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_MAP_TARGET].oamId != PAUSE_OAM_ID_MAP_TARGET_ABOVE)
    {
        if (PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_MAP_TARGET].oamId != PAUSE_OAM_ID_MAP_TARGET_BELOW)
        {
            if (PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_MAP_TARGET].oamId != PAUSE_OAM_ID_MAP_TARGET_LEFT)
            {
                if (PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_MAP_TARGET].oamId != PAUSE_OAM_ID_MAP_TARGET_RIGHT)
                {
                    if (PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_MAP_TARGET].oamId != PAUSE_OAM_ID_MAP_ELEVATOR_UP_ARROWS)
                    {
                        if (PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_MAP_TARGET].oamId != PAUSE_OAM_ID_MAP_ELEVATOR_DOWN_ARROWS)
                            isTarget = FALSE;
                    }
                }
            }
        }
    }
    
    if (isTarget)
    {
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_MAP_TARGET].xPosition = PAUSE_SCREEN_DATA.navTargetX * 8 - gBackgroundPositions.bg[3].x;
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_MAP_TARGET].yPosition = PAUSE_SCREEN_DATA.navTargetY * 8 - gBackgroundPositions.bg[3].y;
    }

    if (gPauseScreenFlag != 2)
        return;

    if (PAUSE_SCREEN_DATA.unk_28.unk_0 != 0)
    {
        PAUSE_SCREEN_DATA.oam[sPauseScreenMapArrowOamInfo[0][PAUSE_OAM_INDEX]].xPosition = 0x100;
        PAUSE_SCREEN_DATA.oam[sPauseScreenMapArrowOamInfo[1][PAUSE_OAM_INDEX]].xPosition = 0x100;
        PAUSE_SCREEN_DATA.oam[sPauseScreenMapArrowOamInfo[2][PAUSE_OAM_INDEX]].xPosition = 0x100;
        PAUSE_SCREEN_DATA.oam[sPauseScreenMapArrowOamInfo[3][PAUSE_OAM_INDEX]].xPosition = 0x100;
        return;
    }

    PAUSE_SCREEN_DATA.oam[sPauseScreenMapArrowOamInfo[0][PAUSE_OAM_INDEX]].xPosition =
        PAUSE_SCREEN_DATA.unk_25A - PAUSE_SCREEN_DATA.mapViewX > 13 ?
        sPauseScreenMapArrowOamInfo[0][PAUSE_OAM_X_POSITION] : 0x100;

    PAUSE_SCREEN_DATA.oam[sPauseScreenMapArrowOamInfo[1][PAUSE_OAM_INDEX]].xPosition =
        PAUSE_SCREEN_DATA.mapViewX - PAUSE_SCREEN_DATA.unk_25B > 14 ?
        sPauseScreenMapArrowOamInfo[1][PAUSE_OAM_X_POSITION] : 0x100;

    PAUSE_SCREEN_DATA.oam[sPauseScreenMapArrowOamInfo[2][PAUSE_OAM_INDEX]].xPosition =
        PAUSE_SCREEN_DATA.mapViewY - PAUSE_SCREEN_DATA.unk_25C > 8 ?
        sPauseScreenMapArrowOamInfo[2][PAUSE_OAM_X_POSITION] : 0x100;

    PAUSE_SCREEN_DATA.oam[sPauseScreenMapArrowOamInfo[3][PAUSE_OAM_INDEX]].xPosition =
        PAUSE_SCREEN_DATA.unk_25D - PAUSE_SCREEN_DATA.mapViewY > 8 ?
        sPauseScreenMapArrowOamInfo[3][PAUSE_OAM_X_POSITION] : 0x100;
}

/**
 * @brief 77e40 | 2cc | Draws security levels, in-game timer, and collected tanks on the map screen
 * 
 * @param action Determines how OAM is updated
*/
void PauseScreenMapDrawSpecialOam(u8 action)
{
    s32 priority;
    u32 i;
    s32 securityLevel;
    u32 j;
    u8 index;

    if (gPauseScreenFlag == 4)
        return;

    switch (action)
    {
        case 0:
            priority = PAUSE_SCREEN_DATA.unk_0 != 0 ? 1 : 3;

            for (i = 0; i < ARRAY_SIZE(sPauseScreenSecurityLevelOamInfo); i++)
            {
                securityLevel = i + 1;
                j = gEquipment.securityHatchLevel != UCHAR_MAX &&
                    gEquipment.securityHatchLevel >= securityLevel ? 1 : 0;

                index = sPauseScreenSecurityLevelOamInfo[i][PAUSE_OAM_INDEX];
                PAUSE_SCREEN_DATA.oam[index].oamId = sPauseScreenSecurityLevelOamInfo[i][PAUSE_OAM_ID] + j;
                PAUSE_SCREEN_DATA.oam[index].yPosition = 0x24;
                PAUSE_SCREEN_DATA.oam[index].xPosition = 0xD4;
                PAUSE_SCREEN_DATA.oam[index].priority = priority;
            }
            break;

        case 1:
            for (i = 0; i < ARRAY_SIZE(sPauseScreenSecurityLevelOamInfo); i++)
            {
                securityLevel = i + 1;
                j = gEquipment.securityHatchLevel != UCHAR_MAX &&
                    gEquipment.securityHatchLevel >= securityLevel ? 1 : 0;
                
                PAUSE_SCREEN_DATA.oam[sPauseScreenSecurityLevelOamInfo[i][PAUSE_OAM_INDEX]].oamId =
                    sPauseScreenSecurityLevelOamInfo[i][PAUSE_OAM_ID] + j;
            }
            break;

        case 2:
            for (i = 0; i < ARRAY_SIZE(sPauseScreenSecurityLevelOamInfo); i++)
            {
                PAUSE_SCREEN_DATA.oam[sPauseScreenSecurityLevelOamInfo[i][PAUSE_OAM_INDEX]].oamId = PAUSE_OAM_ID_NONE;
            }
            break;
    }

    i = FALSE;

    if (gGameCompletion.completedGame == 0)
        i = TRUE;

    if (PAUSE_SCREEN_DATA.unk_0 != 0)
        i = TRUE;

    if (i)
    {
        PAUSE_SCREEN_DATA.unk_274 = 0;
        return;
    }

    if (action != 0)
        return;

    i = PAUSE_SCREEN_DATA.unk_0 != 0 ? 1 : 3;

    PauseScreenMapCountTanks();
    PauseScreenMapDrawIgtAndTanks(FALSE);

    for (j = 0; j < ARRAY_SIZE(sPauseScreenIgtAndTanksOamInfo); j++)
    {
        PAUSE_SCREEN_DATA.oam[sPauseScreenIgtAndTanksOamInfo[j][PAUSE_OAM_INDEX]].oamId =
            sPauseScreenIgtAndTanksOamInfo[j][PAUSE_OAM_ID];
        PAUSE_SCREEN_DATA.oam[sPauseScreenIgtAndTanksOamInfo[j][PAUSE_OAM_INDEX]].priority = i;
        PAUSE_SCREEN_DATA.oam[sPauseScreenIgtAndTanksOamInfo[j][PAUSE_OAM_INDEX]].xPosition =
            sPauseScreenIgtAndTanksOamInfo[j][PAUSE_OAM_X_POSITION];
        PAUSE_SCREEN_DATA.oam[sPauseScreenIgtAndTanksOamInfo[j][PAUSE_OAM_INDEX]].yPosition =
            sPauseScreenIgtAndTanksOamInfo[j][PAUSE_OAM_Y_POSITION];
    }

    for (j = 0; j < ARRAY_SIZE(sPauseScreenTankCheckMarkOamInfo); j++)
    {
        PAUSE_SCREEN_DATA.oam[sPauseScreenTankCheckMarkOamInfo[j][PAUSE_OAM_INDEX]].priority = i;
        PAUSE_SCREEN_DATA.oam[sPauseScreenTankCheckMarkOamInfo[j][PAUSE_OAM_INDEX]].xPosition =
            sPauseScreenTankCheckMarkOamInfo[j][PAUSE_OAM_X_POSITION];
        PAUSE_SCREEN_DATA.oam[sPauseScreenTankCheckMarkOamInfo[j][PAUSE_OAM_INDEX]].yPosition =
            sPauseScreenTankCheckMarkOamInfo[j][PAUSE_OAM_Y_POSITION];
    }

    if (PAUSE_SCREEN_DATA.maxEnergyTanks == PAUSE_SCREEN_DATA.currentEnergyTanks)
    {
        PAUSE_SCREEN_DATA.oam[sPauseScreenTankCheckMarkOamInfo[TANK_NUM_ENERGY][PAUSE_OAM_INDEX]].oamId =
            sPauseScreenTankCheckMarkOamInfo[TANK_NUM_ENERGY][PAUSE_OAM_ID];
    }

    if (PAUSE_SCREEN_DATA.maxMissileTanks == PAUSE_SCREEN_DATA.currentMissileTanks)
    {
        PAUSE_SCREEN_DATA.oam[sPauseScreenTankCheckMarkOamInfo[TANK_NUM_MISSILE][PAUSE_OAM_INDEX]].oamId =
            sPauseScreenTankCheckMarkOamInfo[TANK_NUM_MISSILE][PAUSE_OAM_ID];
    }

    if (PAUSE_SCREEN_DATA.maxPowerBombTanks == PAUSE_SCREEN_DATA.currentPowerBombTanks)
    {
        PAUSE_SCREEN_DATA.oam[sPauseScreenTankCheckMarkOamInfo[TANK_NUM_POWER_BOMB][PAUSE_OAM_INDEX]].oamId =
            sPauseScreenTankCheckMarkOamInfo[TANK_NUM_POWER_BOMB][PAUSE_OAM_ID];
    }
}

/**
 * @brief 7810c | 2e4 | Sets up all OAM for the pause screen
 * 
*/
void PauseScreenSetupOam(void)
{
    s32 i;

    PAUSE_SCREEN_DATA.unk_C = 0;
    PAUSE_SCREEN_DATA.unk_E[0] = 0;
    PAUSE_SCREEN_DATA.unk_E[1] = 0;
    PAUSE_SCREEN_DATA.unk_E[2] = 0;
    PAUSE_SCREEN_DATA.unk_E[3] = 0;
    PAUSE_SCREEN_DATA.unk_17 = 0;
    PAUSE_SCREEN_DATA.unk_18 = 0;


    // Clear all OAM data
    for (i = 0; i < ARRAY_SIZE(PAUSE_SCREEN_DATA.oam); i++)
    {
        PAUSE_SCREEN_DATA.oam[i].oamId = PAUSE_OAM_ID_NONE;
        PAUSE_SCREEN_DATA.oam[i].animationDurationCounter = 0;
        PAUSE_SCREEN_DATA.oam[i].currentAnimationFrame = 0;
        PAUSE_SCREEN_DATA.oam[i].xPosition = 0;
        PAUSE_SCREEN_DATA.oam[i].yPosition = 0;
        PAUSE_SCREEN_DATA.oam[i].priority = 0;
        PAUSE_SCREEN_DATA.oam[i].objMode = 0;
    }

    if (PAUSE_SCREEN_DATA.unk_28.unk_0 != 4 && gPauseScreenFlag != 4)
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_BLINKING_SQUARE].oamId = PAUSE_OAM_ID_BLINKING_SQUARE;

    if (PAUSE_SCREEN_DATA.unk_0 != 0)
    {
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_BLINKING_SQUARE].priority = 1;
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_MAP_TARGET].priority = 1;
    }
    else
    {
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_BLINKING_SQUARE].priority = 3;
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_MAP_TARGET].priority = 3;
    }

    PauseScreenMapUpdateArrowsAndBlinkingSquare();

    if (PAUSE_SCREEN_DATA.unk_28.unk_0 == 1)
    {
        if (PAUSE_SCREEN_DATA.enableDebug != 0)
            PauseDebugSetupCursor();
    }
    else
    {
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_PAUSE_DEBUG_CURSOR].oamId = PAUSE_OAM_ID_NONE;
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_PAUSE_DEBUG_CURSOR].yPosition = 0;
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_PAUSE_DEBUG_CURSOR].xPosition = 0;
    }

    if (PAUSE_SCREEN_DATA.unk_0 == 0)
    {
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_STATUS_BUTTON].oamId = PAUSE_OAM_ID_STATUS_BUTTON;
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_STATUS_BUTTON].yPosition = 2;
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_STATUS_BUTTON].xPosition = 0xD6;
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_STATUS_BUTTON].priority = 2;

        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_SLEEP_BUTTON].oamId = PAUSE_OAM_ID_SLEEP_BUTTON;
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_SLEEP_BUTTON].yPosition = 2;
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_SLEEP_BUTTON].xPosition = 0x12;
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_SLEEP_BUTTON].priority = 2;

        if (gCurrentArea < AREA_NORMAL_COUNT)
            UpdateMenuOamDataId(PAUSE_OAM_IDX_AREA_NAME, sPauseScreenAreaNameOamIds[gCurrentArea][1]);
        else
            UpdateMenuOamDataId(PAUSE_OAM_IDX_AREA_NAME, PAUSE_OAM_ID_NONE);

        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_AREA_NAME].yPosition = 0;
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_AREA_NAME].xPosition = 0x74;
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_AREA_NAME].priority = 2;
    }

    PauseScreenMapDrawSpecialOam(0);

    PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_POP_UP_WINDOW].yPosition = 0x20;
    PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_POP_UP_WINDOW].xPosition = 0xC0;
    PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_POP_UP_WINDOW].oamId = PAUSE_OAM_ID_NONE;

    for (i = ARRAY_SIZE(sPauseScreenMapArrowOamInfo); i > 0;)
    {
        i--;

        if (PAUSE_SCREEN_DATA.unk_0 == 0)
        {
            PAUSE_SCREEN_DATA.oam[sPauseScreenMapArrowOamInfo[i][PAUSE_OAM_INDEX]].oamId =
                sPauseScreenMapArrowOamInfo[i][PAUSE_OAM_ID];
        }

        PAUSE_SCREEN_DATA.oam[sPauseScreenMapArrowOamInfo[i][PAUSE_OAM_INDEX]].xPosition = 0x100;
        PAUSE_SCREEN_DATA.oam[sPauseScreenMapArrowOamInfo[i][PAUSE_OAM_INDEX]].yPosition =
            sPauseScreenMapArrowOamInfo[i][PAUSE_OAM_Y_POSITION];
        PAUSE_SCREEN_DATA.oam[sPauseScreenMapArrowOamInfo[i][PAUSE_OAM_INDEX]].priority = 2;
    }

    if (PAUSE_SCREEN_DATA.unk_0 == 1)
    {
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_NAVIGATION_PAD].yPosition = 0x7C;
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_NAVIGATION_PAD].xPosition = 0x74;
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_NAVIGATION_PAD].oamId = PAUSE_OAM_ID_NAVIGATION_PAD_WITH_SAMUS;
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_NAVIGATION_PAD].priority = 3;

        i = RoomGetClosedNavigationHatches();

        if (gPauseScreenFlag == 4)
        {
            i = 1 | 2;
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_NAVIGATION_PAD].oamId = PAUSE_OAM_ID_NAVIGATION_PAD;
        }

        if (i & 2)
        {
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_LOCKED_HATCH_LEFT].yPosition = 0x4C;
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_LOCKED_HATCH_LEFT].xPosition = 0x18;
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_LOCKED_HATCH_LEFT].oamId = PAUSE_OAM_ID_LOCKED_HATCH_LEFT;
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_LOCKED_HATCH_LEFT].priority = 3;
        }

        if (i & 1)
        {
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_LOCKED_HATCH_RIGHT].yPosition = 0x4C;
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_LOCKED_HATCH_RIGHT].xPosition = 0xD0;
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_LOCKED_HATCH_RIGHT].oamId = PAUSE_OAM_ID_LOCKED_HATCH_RIGHT;
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_LOCKED_HATCH_RIGHT].priority = 3;
        }
    }
}

/**
 * @brief 783f0 | 684 | Processes all OAM for the pause screen
 * 
*/
void PauseScreenProcessOam(void)
{
    s32 nextSlot;
    s32 currSlot;
    s16 yPosition;
    s16 xPosition;
    u16* dst;
    const u16* src;
    u16 part;
    const struct FrameData* pFrame;
    s32 i;
    u8 priority;
    u8 objMode;

    dst = (u16*)(&gOamData);
    dst += gNextOamSlot * 4;
    nextSlot = gNextOamSlot;
    currSlot = nextSlot;

    for (i = 0; i < ARRAY_SIZE(PAUSE_SCREEN_DATA.oam); i++)
    {
        if (PAUSE_SCREEN_DATA.oam[i].oamId == PAUSE_OAM_ID_NONE)
            continue;
        
        PAUSE_SCREEN_DATA.oam[i].ended = FALSE;
    
        switch (PAUSE_SCREEN_DATA.oam[i].oamId)
        {
            case PAUSE_OAM_ID_COUNT - 1:
            default:
                pFrame = sPauseScreenOamPointers[PAUSE_SCREEN_DATA.oam[i].oamId];
                PAUSE_SCREEN_DATA.oam[i].animationDurationCounter = 0;
                break;
            
            case PAUSE_OAM_ID_NONE:
                break;

            case PAUSE_OAM_ID_BLINKING_SQUARE:
            case PAUSE_OAM_ID_YES_NO_CURSOR:
            case PAUSE_OAM_ID_NAV_TEXT_ARROW:
            case PAUSE_OAM_ID_MAP_PREVIEW_POINT:
            case PAUSE_OAM_ID_MAP_UP_ARROW:
            case PAUSE_OAM_ID_MAP_DOWN_ARROW:
            case PAUSE_OAM_ID_MAP_LEFT_ARROW:
            case PAUSE_OAM_ID_MAP_RIGHT_ARROW:
            case PAUSE_OAM_ID_PAUSE_DEBUG_CURSOR_ARROWS:
            case PAUSE_OAM_ID_NAV_TEXT_CURSOR:
            case PAUSE_OAM_ID_NAV_TEXT_CURSOR_BLINKING:
            case PAUSE_OAM_ID_MAP_ELEVATOR_UP_ARROWS:
            case PAUSE_OAM_ID_MAP_ELEVATOR_DOWN_ARROWS:
            case PAUSE_OAM_ID_BSL_DIAGRAM_TARGET_ABOVE:
            case PAUSE_OAM_ID_BSL_DIAGRAM_TARGET_BELOW:
            case PAUSE_OAM_ID_BSL_DIAGRAM_START_ABOVE:
            case PAUSE_OAM_ID_BSL_DIAGRAM_START_BELOW:
            case PAUSE_OAM_ID_STATUS_BUTTON:
            case PAUSE_OAM_ID_STATUS_BUTTON_SELECTED:
            case PAUSE_OAM_ID_SLEEP_BUTTON:
            case PAUSE_OAM_ID_SLEEP_BUTTON_SELECTED:
            case PAUSE_OAM_ID_NAVIGATION_PAD:
            case PAUSE_OAM_ID_NAVIGATION_PAD_WITH_SAMUS:
            case PAUSE_OAM_ID_ADAM_TEXT_BOX_LIGHT_OFF:
            case PAUSE_OAM_ID_ADAM_TEXT_BOX_LIGHT_FLASHING:
            case PAUSE_OAM_ID_SAMUS_PORTRAIT_ANIMATED:
            case PAUSE_OAM_ID_FEDERATION_PORTRAIT_FLICKERING:
                pFrame = sPauseScreenOamPointers[PAUSE_SCREEN_DATA.oam[i].oamId];

                if (PAUSE_SCREEN_DATA.oam[i].animationDurationCounter >= pFrame[PAUSE_SCREEN_DATA.oam[i].currentAnimationFrame].timer)
                {
                    PAUSE_SCREEN_DATA.oam[i].animationDurationCounter = 0;
                    PAUSE_SCREEN_DATA.oam[i].currentAnimationFrame++;

                    if (pFrame[PAUSE_SCREEN_DATA.oam[i].currentAnimationFrame].timer == 0)
                        PAUSE_SCREEN_DATA.oam[i].currentAnimationFrame = 0;
                }
                break;
            
            case PAUSE_OAM_ID_MAP_TARGET_ABOVE:
            case PAUSE_OAM_ID_MAP_TARGET_BELOW:
            case PAUSE_OAM_ID_MAP_TARGET_LEFT:
            case PAUSE_OAM_ID_MAP_TARGET_RIGHT:
                pFrame = sPauseScreenOamPointers[PAUSE_SCREEN_DATA.oam[i].oamId];

                if (PAUSE_SCREEN_DATA.oam[i].animationDurationCounter >=
                    pFrame[PAUSE_SCREEN_DATA.oam[i].currentAnimationFrame].timer)
                {
                    PAUSE_SCREEN_DATA.oam[i].animationDurationCounter = 0;
                    PAUSE_SCREEN_DATA.oam[i].currentAnimationFrame++;

                    if (pFrame[PAUSE_SCREEN_DATA.oam[i].currentAnimationFrame].timer == 0)
                    {
                        PAUSE_SCREEN_DATA.oam[i].currentAnimationFrame = 0;

                        if (PAUSE_SCREEN_DATA.unk_28.unk_0 != 1)
                        {
                            if (PAUSE_SCREEN_DATA.unk_0 != 0)
                                SoundPlay(SOUND_11A);
                            else
                                SoundPlay(SOUND_12B);
                        }
                    }
                }
                break;
            
            case PAUSE_OAM_ID_POP_UP_WINDOW:
            case PAUSE_OAM_ID_ADAM_TEXT_BOX_OUTLINE:
            case PAUSE_OAM_ID_ADAM_TEXT_BOX_OUTLINE_CLOSING:
            case PAUSE_OAM_ID_ADAM_TEXT_BOX_BACKGROUND:
            case PAUSE_OAM_ID_ADAM_TEXT_BOX_BACKGROUND_CLOSING:
            case PAUSE_OAM_ID_ADAM_TEXT_BOX_LIGHT_OPENING:
            case PAUSE_OAM_ID_ADAM_TEXT_BOX_LIGHT_CLOSING:
            case PAUSE_OAM_ID_SAMUS_TEXT_BOX:
            case PAUSE_OAM_ID_SAMUS_TEXT_BOX_BACKGROUND:
            case PAUSE_OAM_ID_FED_TEXT_BOX_OUTLINE:
            case PAUSE_OAM_ID_FED_TEXT_BOX_BACKGROUND:
            case PAUSE_OAM_ID_OBJECTIVE_TEXT_BOX:
            case PAUSE_OAM_ID_OBJECTIVE_TEXT_BOX_BACKGROUND:
                pFrame = sPauseScreenOamPointers[PAUSE_SCREEN_DATA.oam[i].oamId];

                if (pFrame[PAUSE_SCREEN_DATA.oam[i].currentAnimationFrame + 1].timer == 0)
                    PAUSE_SCREEN_DATA.oam[i].ended = TRUE;

                if (PAUSE_SCREEN_DATA.oam[i].animationDurationCounter >=
                    pFrame[PAUSE_SCREEN_DATA.oam[i].currentAnimationFrame].timer)
                {
                    PAUSE_SCREEN_DATA.oam[i].animationDurationCounter = 0;
                    PAUSE_SCREEN_DATA.oam[i].currentAnimationFrame++;

                    if (pFrame[PAUSE_SCREEN_DATA.oam[i].currentAnimationFrame].timer == 0)
                        PAUSE_SCREEN_DATA.oam[i].currentAnimationFrame--;
                }
                break;
            
            case PAUSE_OAM_ID_DOWNLOAD_SCAN_LINE_TRAILING:
            case PAUSE_OAM_ID_POP_UP_WINDOW_CLOSING:
            case PAUSE_OAM_ID_SAMUS_TEXT_BOX_CLOSING:
            case PAUSE_OAM_ID_SAMUS_TEXT_BOX_BACKGROUND_CLOSING:
            case PAUSE_OAM_ID_FED_TEXT_BOX_CLOSING:
            case PAUSE_OAM_ID_FED_TEXT_BOX_BACKGROUND_CLOSING:
            case PAUSE_OAM_ID_OBJECTIVE_TEXT_BOX_CLOSING:
            case PAUSE_OAM_ID_OBJECTIVE_TEXT_BOX_BACKGROUND_CLOSING:
            case PAUSE_OAM_ID_SAMUS_PORTRAIT_CLOSING:
            case PAUSE_OAM_ID_FEDERATION_PORTRAIT_CLOSING:
                pFrame = sPauseScreenOamPointers[PAUSE_SCREEN_DATA.oam[i].oamId];

                if (PAUSE_SCREEN_DATA.oam[i].animationDurationCounter < pFrame[PAUSE_SCREEN_DATA.oam[i].currentAnimationFrame].timer)
                    break;

                PAUSE_SCREEN_DATA.oam[i].animationDurationCounter = 0;
                PAUSE_SCREEN_DATA.oam[i].currentAnimationFrame++;

                if (pFrame[PAUSE_SCREEN_DATA.oam[i].currentAnimationFrame].timer != 0)
                    break;

                PAUSE_SCREEN_DATA.oam[i].oamId = PAUSE_OAM_ID_NONE;
                PAUSE_SCREEN_DATA.oam[i].currentAnimationFrame = 0;
                continue;

            case PAUSE_OAM_ID_SAMUS_PORTRAIT_OPENING:
                pFrame = sPauseScreenOamPointers[PAUSE_SCREEN_DATA.oam[i].oamId];

                if (PAUSE_SCREEN_DATA.oam[i].animationDurationCounter >=
                    pFrame[PAUSE_SCREEN_DATA.oam[i].currentAnimationFrame].timer)
                {
                    PAUSE_SCREEN_DATA.oam[i].animationDurationCounter = 0;
                    PAUSE_SCREEN_DATA.oam[i].currentAnimationFrame++;

                    if (pFrame[PAUSE_SCREEN_DATA.oam[i].currentAnimationFrame].timer == 0)
                    {
                        PAUSE_SCREEN_DATA.oam[i].oamId++;
                        pFrame = sPauseScreenOamPointers[PAUSE_SCREEN_DATA.oam[i].oamId];
                        PAUSE_SCREEN_DATA.oam[i].animationDurationCounter = 0;
                        PAUSE_SCREEN_DATA.oam[i].currentAnimationFrame = 0;
                    }
                }
                break;

            case PAUSE_OAM_ID_FEDERATION_PORTRAIT_OPENING:
                pFrame = sPauseScreenOamPointers[PAUSE_SCREEN_DATA.oam[i].oamId];

                if (PAUSE_SCREEN_DATA.oam[i].animationDurationCounter >=
                    pFrame[PAUSE_SCREEN_DATA.oam[i].currentAnimationFrame].timer)
                {
                    PAUSE_SCREEN_DATA.oam[i].animationDurationCounter = 0;
                    PAUSE_SCREEN_DATA.oam[i].currentAnimationFrame++;

                    if (pFrame[PAUSE_SCREEN_DATA.oam[i].currentAnimationFrame].timer == 0)
                    {
                        PAUSE_SCREEN_DATA.oam[i].oamId++;
                        pFrame = sPauseScreenOamPointers[PAUSE_SCREEN_DATA.oam[i].oamId];
                        PAUSE_SCREEN_DATA.oam[i].animationDurationCounter = 0;
                        PAUSE_SCREEN_DATA.oam[i].currentAnimationFrame = 0;

                        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_FED_PORTRAIT_FLICKERING].oamId = PAUSE_OAM_ID_FEDERATION_PORTRAIT_FLICKERING;
                        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_FED_PORTRAIT_FLICKERING].animationDurationCounter = 0;
                        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_FED_PORTRAIT_FLICKERING].currentAnimationFrame = 0;
                    }
                }
                break;
    
            case PAUSE_OAM_ID_MAIN_DECK_TEXT_APPEARING:
            case PAUSE_OAM_ID_SECTOR_1_TEXT_APPEARING:
            case PAUSE_OAM_ID_SECTOR_2_TEXT_APPEARING:
            case PAUSE_OAM_ID_SECTOR_3_TEXT_APPEARING:
            case PAUSE_OAM_ID_SECTOR_4_TEXT_APPEARING:
            case PAUSE_OAM_ID_SECTOR_5_TEXT_APPEARING:
            case PAUSE_OAM_ID_SECTOR_6_TEXT_APPEARING:
            case PAUSE_OAM_ID_UNK_53:
            case PAUSE_OAM_ID_FEDERATION_PORTRAIT_ANIMATING:
                pFrame = sPauseScreenOamPointers[PAUSE_SCREEN_DATA.oam[i].oamId];

                if (PAUSE_SCREEN_DATA.oam[i].animationDurationCounter >=
                    pFrame[PAUSE_SCREEN_DATA.oam[i].currentAnimationFrame].timer)
                {
                    PAUSE_SCREEN_DATA.oam[i].animationDurationCounter = 0;
                    PAUSE_SCREEN_DATA.oam[i].currentAnimationFrame++;

                    if (pFrame[PAUSE_SCREEN_DATA.oam[i].currentAnimationFrame].timer == 0)
                    {
                        PAUSE_SCREEN_DATA.oam[i].oamId--;
                        pFrame = sPauseScreenOamPointers[PAUSE_SCREEN_DATA.oam[i].oamId];
                        PAUSE_SCREEN_DATA.oam[i].animationDurationCounter = 0;
                        PAUSE_SCREEN_DATA.oam[i].currentAnimationFrame = 0;
                    }
                }
                break;
        }

        PAUSE_SCREEN_DATA.oam[i].animationDurationCounter++;

        yPosition = (u16)(PAUSE_SCREEN_DATA.oam[i].yPosition + 4);
        xPosition = (u16)(PAUSE_SCREEN_DATA.oam[i].xPosition + 4);

        // Offset by current frame
        pFrame += PAUSE_SCREEN_DATA.oam[i].currentAnimationFrame;

        // Get raw data pointer
        src = pFrame->pFrame;

        priority = PAUSE_SCREEN_DATA.oam[i].priority;
        objMode = PAUSE_SCREEN_DATA.oam[i].objMode;
        
        // Check for buffer overflow
        if (nextSlot + *src > 0x7F)
            break;

        // Add part count
        nextSlot += *src++;

        for (; currSlot < nextSlot; currSlot++)
        {
            // Copy raw contents and implement positions
            part = *src++;
            *dst++ = part;

            gOamData[currSlot].split.y = part + yPosition;
            
            part = *src++;
            *dst++ = part;

            gOamData[currSlot].split.x = (part + xPosition) & 0x1FF;
            *dst++ = *src++;

            // Write special parameters
            gOamData[currSlot].split.priority = priority;
            gOamData[currSlot].split.objMode = objMode;
            
            dst++;
        }
    }

    gNextOamSlot = nextSlot;
}

/**
 * @brief 78a74 | 7c | Checks for maintained directional inputs
 * 
*/
void CheckForMaintainedInput(void)
{
    u8 inputDelays[ARRAY_SIZE(sMaintainedInputDelays)];

    memcpy(inputDelays, sMaintainedInputDelays, sizeof(sMaintainedInputDelays));

    if (gButtonInput & KEY_ALL_DIRECTIONS)
    {
        gMaintainedInput.delay++;
    }
    else
    {
        gMaintainedInput.delay = 0;
        gMaintainedInput.set = 0;
    }

    if (gMaintainedInput.delay >= inputDelays[gMaintainedInput.set])
    {
        gChangedInput |= gButtonInput & KEY_ALL_DIRECTIONS;
        gMaintainedInput.delay = 0;
        
        if (gMaintainedInput.set < ARRAY_SIZE(sMaintainedInputDelays) - 1)
            gMaintainedInput.set++;
    }
}

/**
 * @brief 78af0 | b4 | Sets the OAM for the top text box during navigation conversations
 * 
 * @param state The current state of the text box
*/
void NavConversationSetTopTextBoxOam(u8 state)
{
    s32 index;
    s32 offset;

    if (state != 0)
    {
        index = 0;
        if (PAUSE_SCREEN_DATA.typeFlags & 4)
            index = 3;

        if (state == 1)
        {
            offset = 0;
        }
        else if (state == 2)
        {
            SoundPlay(SOUND_20A);
            offset = 1;
        }
        else if (state == 3)
        {
            SoundPlay(SOUND_20B);
            offset = 2;
        }

        index += offset;
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_TOP_TEXT_BOX_OUTLINE].oamId = sNavConversationPortraitOamIds[index][0];
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_TOP_TEXT_BOX_BACKGROUND].oamId = sNavConversationPortraitOamIds[index][1];
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_PORTRAIT].oamId = sNavConversationPortraitOamIds[index][2];

        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_TOP_TEXT_BOX_OUTLINE].animationDurationCounter = 0;
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_TOP_TEXT_BOX_OUTLINE].currentAnimationFrame = 0;
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_TOP_TEXT_BOX_BACKGROUND].animationDurationCounter = 0;
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_TOP_TEXT_BOX_BACKGROUND].currentAnimationFrame = 0;
    }

    PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_TOP_TEXT_BOX_BACKGROUND].xPosition =
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_TOP_TEXT_BOX_OUTLINE].xPosition;
    PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_TOP_TEXT_BOX_BACKGROUND].yPosition =
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_TOP_TEXT_BOX_OUTLINE].yPosition;
}

/**
 * @brief 78ba4 | a0 | Sets the OAM for the bottom text box during navigation conversations
 * 
 * @param state The current state of the text box
*/
void NavConversationSetBottomTextBoxOam(u8 state)
{
    if (state == 1)
    {
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_ADAM_TEXT_BOX_OUTLINE].oamId = PAUSE_OAM_ID_ADAM_TEXT_BOX_OUTLINE_SHORT;
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_ADAM_TEXT_BOX_BACKGROUND].oamId = PAUSE_OAM_ID_ADAM_TEXT_BOX_BACKGROUND_SHORT;
    }
    else if (state == 2)
    {
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_ADAM_TEXT_BOX_OUTLINE].oamId = PAUSE_OAM_ID_ADAM_TEXT_BOX_OUTLINE;
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_ADAM_TEXT_BOX_BACKGROUND].oamId = PAUSE_OAM_ID_ADAM_TEXT_BOX_BACKGROUND;
        SoundPlay(SOUND_20A);
    }
    else if (state == 3)
    {
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_ADAM_TEXT_BOX_OUTLINE].oamId = PAUSE_OAM_ID_ADAM_TEXT_BOX_OUTLINE_CLOSING;
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_ADAM_TEXT_BOX_BACKGROUND].oamId = PAUSE_OAM_ID_ADAM_TEXT_BOX_BACKGROUND_CLOSING;
        SoundPlay(SOUND_20B);
    }

    if (state != 0)
    {
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_ADAM_TEXT_BOX_OUTLINE].animationDurationCounter = 0;
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_ADAM_TEXT_BOX_OUTLINE].currentAnimationFrame = 0;

        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_ADAM_TEXT_BOX_BACKGROUND].animationDurationCounter = 0;
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_ADAM_TEXT_BOX_BACKGROUND].currentAnimationFrame = 0;
    }

    PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_ADAM_TEXT_BOX_BACKGROUND].xPosition =
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_ADAM_TEXT_BOX_OUTLINE].xPosition;
    PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_ADAM_TEXT_BOX_BACKGROUND].yPosition =
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_ADAM_TEXT_BOX_OUTLINE].yPosition;
    
    PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_ADAM_TEXT_BOX_LIGHT].xPosition =
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_ADAM_TEXT_BOX_OUTLINE].xPosition;
    PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_ADAM_TEXT_BOX_LIGHT].yPosition =
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_ADAM_TEXT_BOX_OUTLINE].yPosition;
}

/**
 * @brief 78c44 | 260 | Updates the OAM for the top text box during navigation conversations
 * 
*/
void NavConversationUpdateTopTextBoxOam(void)
{
    if (!(PAUSE_SCREEN_DATA.typeFlags & 6))
    {
        PAUSE_SCREEN_DATA.unk_23C = 0;
        PAUSE_SCREEN_DATA.unk_23D = 0;
        return;
    }

    PAUSE_SCREEN_DATA.unk_23D++;

    switch (PAUSE_SCREEN_DATA.unk_23C)
    {
        case 0:
            if (PAUSE_SCREEN_DATA.unk_23D > 0x10)
            {
                PAUSE_SCREEN_DATA.unk_23C++;
                PAUSE_SCREEN_DATA.unk_23D = 0;
            }
            break;

        case 1:
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_TOP_TEXT_BOX_OUTLINE].xPosition = 0x74;
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_TOP_TEXT_BOX_OUTLINE].yPosition = 0x1C;

            NavConversationSetTopTextBoxOam(2);
            PauseScreenMapDrawSpecialOam(2);
            
            PAUSE_SCREEN_DATA.unk_23C++;
            PAUSE_SCREEN_DATA.unk_23D = 0;
            break;
        
        case 2:
            if (PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_TOP_TEXT_BOX_OUTLINE].ended &&
                PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_TOP_TEXT_BOX_BACKGROUND].ended)
            {
                PAUSE_SCREEN_DATA.unk_23C++;
                PAUSE_SCREEN_DATA.unk_23D = 0;
            }
            break;
        
        case 3:
            if (PAUSE_SCREEN_DATA.unk_23D > 0x10)
            {
                PAUSE_SCREEN_DATA.typeFlags |= 0x10;
                PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_TOP_TEXT_BOX_CURSOR].xPosition = 8;
                PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_TOP_TEXT_BOX_CURSOR].yPosition =
                    sNavConversationTextBoxCursorYPositions[NAV_TEXT_BOX_TOP][0];
                PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_TOP_TEXT_BOX_CURSOR].oamId = PAUSE_OAM_ID_NAV_TEXT_CURSOR;
                PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_TOP_TEXT_BOX_CURSOR].animationDurationCounter = 0;
                PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_TOP_TEXT_BOX_CURSOR].currentAnimationFrame = 0;
                PAUSE_SCREEN_DATA.unk_23C++;
                PAUSE_SCREEN_DATA.unk_23D = 0;
            }
            break;
        
        case 4:
            if (!(PAUSE_SCREEN_DATA.typeFlags & 0x10))
            {
                PAUSE_SCREEN_DATA.unk_23C++;
                PAUSE_SCREEN_DATA.unk_23D = 0;
            }
            break;
        
        case 5:
            NavConversationSetTopTextBoxOam(3);
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_TOP_TEXT_BOX_CURSOR].oamId = PAUSE_OAM_ID_NONE;
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_FED_PORTRAIT_FLICKERING].oamId = PAUSE_OAM_ID_NONE;
            PAUSE_SCREEN_DATA.unk_23C++;
            PAUSE_SCREEN_DATA.unk_23D = 0;
            break;
        
        case 6:
            if (PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_TOP_TEXT_BOX_OUTLINE].oamId == PAUSE_OAM_ID_NONE &&
                PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_TOP_TEXT_BOX_BACKGROUND].oamId == PAUSE_OAM_ID_NONE)
            {
                PAUSE_SCREEN_DATA.unk_23C++;
                PAUSE_SCREEN_DATA.unk_23D = 0;
                PauseScreenMapDrawSpecialOam(1);
            }
            break;
        
        case 7:
            if (PAUSE_SCREEN_DATA.unk_23D > 0x10)
            {
                PAUSE_SCREEN_DATA.unk_23C++;
                PAUSE_SCREEN_DATA.unk_23D = 0;

                if (PAUSE_SCREEN_DATA.typeFlags & 2)
                    PAUSE_SCREEN_DATA.typeFlags ^= 2;
                else if (PAUSE_SCREEN_DATA.typeFlags & 4)
                    PAUSE_SCREEN_DATA.typeFlags ^= 4;
            }
            break;

        case 8:
            break;
    }

    if (PAUSE_SCREEN_DATA.unk_1B > 1 &&
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_PORTRAIT].oamId == PAUSE_OAM_ID_FEDERATION_PORTRAIT_STILL)
    {
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_PORTRAIT].oamId++;
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_PORTRAIT].animationDurationCounter = 0;
        PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_PORTRAIT].currentAnimationFrame = 0;
    }
}

/**
 * @brief 78ea4 | 274 | Updates the OAM for the bottom text box during navigation conversations
 * 
*/
void NavConversationUpdateBottomTextBoxOam(void)
{
    if (!(PAUSE_SCREEN_DATA.typeFlags & 1))
    {
        PAUSE_SCREEN_DATA.unk_238 = 0;
        PAUSE_SCREEN_DATA.unk_239 = 0;
        return;
    }

    PAUSE_SCREEN_DATA.unk_239++;

    switch (PAUSE_SCREEN_DATA.unk_238)
    {
        case 0:
            if (PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_ADAM_TEXT_BOX_OUTLINE].yPosition == 0x7C)
            {
                PAUSE_SCREEN_DATA.unk_238++;
                PAUSE_SCREEN_DATA.unk_239 = 0;
            }
            else
            {
                PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_ADAM_TEXT_BOX_OUTLINE].yPosition -= 8;
                NavConversationSetBottomTextBoxOam(0);
            }
            break;
        
        case 1:
            if (PAUSE_SCREEN_DATA.unk_239 > 8)
            {
                PAUSE_SCREEN_DATA.unk_238++;
                PAUSE_SCREEN_DATA.unk_239 = 0;
            }
            break;
        
        case 2:
            NavConversationSetBottomTextBoxOam(2);
            PAUSE_SCREEN_DATA.unk_238++;
            PAUSE_SCREEN_DATA.unk_239 = 0;
            break;

        case 3:
            if (PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_ADAM_TEXT_BOX_OUTLINE].ended)
            {
                PAUSE_SCREEN_DATA.unk_238++;
                PAUSE_SCREEN_DATA.unk_239 = 0;
            }
            break;

        case 4:
            UpdateMenuOamDataId(PAUSE_OAM_IDX_ADAM_TEXT_BOX_LIGHT, PAUSE_OAM_ID_ADAM_TEXT_BOX_LIGHT_OPENING);
            PAUSE_SCREEN_DATA.unk_238++;
            PAUSE_SCREEN_DATA.unk_239 = 0;
            break;
        
        case 5:
            if (PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_ADAM_TEXT_BOX_LIGHT].ended)
            {
                PAUSE_SCREEN_DATA.typeFlags |= 8;
                PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_CURSOR].xPosition = 8;
                PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_CURSOR].yPosition =
                    sNavConversationTextBoxCursorYPositions[NAV_TEXT_BOX_BOTTOM][0];
                PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_CURSOR].animationDurationCounter = 0;
                PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_CURSOR].currentAnimationFrame = 0;

                if (PAUSE_SCREEN_DATA.unk_1C != 5)
                    PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_CURSOR].oamId = PAUSE_OAM_ID_NAV_TEXT_CURSOR;

                PAUSE_SCREEN_DATA.unk_238++;
                PAUSE_SCREEN_DATA.unk_239 = 0;
            }
            break;
        
        case 6:
            if (!(PAUSE_SCREEN_DATA.typeFlags & 8))
            {
                PAUSE_SCREEN_DATA.unk_238++;
                PAUSE_SCREEN_DATA.unk_239 = 0;
            }
            else if (PAUSE_SCREEN_DATA.unk_239 == 0x10)
            {
                UpdateMenuOamDataId(PAUSE_OAM_IDX_ADAM_TEXT_BOX_LIGHT, PAUSE_OAM_ID_ADAM_TEXT_BOX_LIGHT_FLASHING);
            }

            if (PAUSE_SCREEN_DATA.unk_239 > 0x3C)
                PAUSE_SCREEN_DATA.unk_239 = 0x3C;
            break;
        
        case 7:
            UpdateMenuOamDataId(PAUSE_OAM_IDX_ADAM_TEXT_BOX_LIGHT, PAUSE_OAM_ID_ADAM_TEXT_BOX_LIGHT_CLOSING);
            PAUSE_SCREEN_DATA.unk_238++;
            PAUSE_SCREEN_DATA.unk_239 = 0;
            break;
        
        case 8:
            if (PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_ADAM_TEXT_BOX_LIGHT].ended)
            {
                PAUSE_SCREEN_DATA.unk_238++;
                PAUSE_SCREEN_DATA.unk_239 = 0;
            }
            break;
        
        case 9:
            PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_CURSOR].oamId = PAUSE_OAM_ID_NONE;
            NavConversationSetBottomTextBoxOam(3);
            PAUSE_SCREEN_DATA.unk_238++;
            PAUSE_SCREEN_DATA.unk_239 = 0;
            break;
        
        case 10:
            if (PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_ADAM_TEXT_BOX_OUTLINE].ended)
            {
                PAUSE_SCREEN_DATA.unk_238++;
                PAUSE_SCREEN_DATA.unk_239 = 0;
            }
            break;
        
        case 11:
            if (PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_ADAM_TEXT_BOX_OUTLINE].yPosition != 0xCC)
            {
                PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_ADAM_TEXT_BOX_OUTLINE].yPosition += 8;
                NavConversationSetBottomTextBoxOam(0);
            }
            else
            {
                PAUSE_SCREEN_DATA.unk_238++;
                PAUSE_SCREEN_DATA.unk_239 = 0;
            }
            break;
        
        case 12:
            if (PAUSE_SCREEN_DATA.unk_239 > 8)
            {
                PAUSE_SCREEN_DATA.typeFlags ^= 1;
                PAUSE_SCREEN_DATA.unk_238++;
                PAUSE_SCREEN_DATA.unk_239 = 0;
            }
            break;

        case 13:
            break;
    }
}
