#include "data/event_data.h"
#include "macros.h"
#include "constants/connection.h"

const struct EventLocationAndNavigationInfo sEventLocationAndNavigationInfo[EVENT_END] = {
    [EVENT_NONE] = {
        .area = AREA_MAIN_DECK,
        .room = 1,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_GO_TO_QUARANTINE_BAY,
        .navRoom = NAV_ROOM_MAIN_DECK_ROOM_0,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_NAVIGATION_ROOM_BEFORE_QUARANTINE_BAY] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_QUARANTINE_BAY_IS_AHEAD,
        .navRoom = NAV_ROOM_MAIN_DECK_ROOM_16,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_QUARANTINE_BAY_HORNOAD_DEAD] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_3,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_NAVIGATION_ROOM_AFTER_QUARANTINE_BAY] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_UNLOCKED_LEVEL_0_HATCHES,
        .navRoom = NAV_ROOM_MAIN_DECK_ROOM_16,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_NAVIGATION_ROOM_BEFORE_ELEVATOR] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_GO_TO_MISSILES_DATA_ROOM,
        .navRoom = NAV_ROOM_MAIN_DECK_ROOM_9,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_1] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_MISSILES_DATA_ROOM_JUST_AHEAD,
        .navRoom = NAV_ROOM_MAIN_DECK_ROOM_32,
        .download = FALSE,
        .skippable = TRUE
    },
    [EVENT_ENTERED_MISSILE_DATA_ROOM] = {
        .area = AREA_MAIN_DECK,
        .room = 40,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_MISSILE_DATA_DOWNLOADED] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_7,
        .navRoom = NAV_ROOM_NONE,
        .download = TRUE,
        .skippable = FALSE
    },
    [EVENT_ENTERED_NAVIGATION_ROOM_POWER_OUTAGE] = {
        .area = AREA_MAIN_DECK,
        .room = 33,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_NAVIGATION_ROOM_AFTER_MISSILES] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_FIND_WAY_TO_ARACHNUS,
        .navRoom = NAV_ROOM_MAIN_DECK_ROOM_32,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_MORPH_BALL_ABILITY_RECOVERED] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_9,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_NAVIGATION_ROOM_AFTER_MORPH_BALL] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_GO_TO_SRX1,
        .navRoom = NAV_ROOM_ANY,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_ENTERED_ELEVATOR_ROOM] = {
        .area = AREA_MAIN_DECK,
        .room = 20,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_SA_X_ELEVATOR_CUTSCENE_ENDS] = {
        .area = AREA_MAIN_DECK,
        .room = 25,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_NAVIGATION_ROOM_ENTERING_SRX] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_CLEAR_ATMOSPHERIC_STABILIZERS,
        .navRoom = NAV_ROOM_SECTOR_1_ROOM_2,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_CHARGE_BEAM_ABILITY_RECOVERED] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_STILL_ONE_ATMOSPHERIC_STABILIZER_LEFT,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_ALL_STABILIZERS_ONLINE] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_NAVIGATION_ROOM_LEAVING_SRX] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_GO_TO_TRO1,
        .navRoom = NAV_ROOM_SECTOR_1_ROOM_2,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_NAVIGATION_ROOM_ENTERING_TRO] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_FIND_SECURITY_ROOM_AND_DOWNLOAD_BOMBS,
        .navRoom = NAV_ROOM_SECTOR_2_ROOM_2,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_SECURITY_LEVEL_1_UNLOCKED] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_2] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_LEVEL_1_UNLOCKED_GO_DOWNLOAD_BOMBS,
        .navRoom = NAV_ROOM_SECTOR_2_ROOM_2,
        .download = FALSE,
        .skippable = TRUE
    },
    [EVENT_ENTERING_BOMB_DATA_ROOM] = {
        .area = AREA_SECTOR_2,
        .room = 9,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_BOMB_DATA_DOWNLOADED] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_16,
        .navRoom = NAV_ROOM_NONE,
        .download = TRUE,
        .skippable = FALSE
    },
    [EVENT_SA_X_QUAKE] = {
        .area = AREA_SECTOR_2,
        .room = 32,
        .xStart = 9,
        .yStart = 2,
        .xEnd = 18,
        .yEnd = 12,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_LEFT_SA_X_QUAKE_ROOM] = {
        .area = AREA_SECTOR_2,
        .room = 10,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_HIGH_JUMP_ABILITY_RECOVERED] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_ESCAPED_TRO_1_SA_X] = {
        .area = AREA_SECTOR_2,
        .room = 47,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_NAVIGATION_ROOM_LEAVING_TRO] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_GO_TO_AQA1,
        .navRoom = NAV_ROOM_SECTOR_2_ROOM_2,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_NAVIGATION_ROOM_ENTERING_AQA] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_GO_DEFEAT_SERRIS,
        .navRoom = NAV_ROOM_SECTOR_4_ROOM_2,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_SPEED_BOOSTER_ABILITY_RECOVERED] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_19,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_3] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_EMPTY,
        .navRoom = NAV_ROOM_SECTOR_4_ROOM_2,
        .download = FALSE,
        .skippable = TRUE
    },
    [EVENT_ENTERED_PUMP_CONTROL_UNIT] = {
        .area = AREA_SECTOR_4,
        .room = 34,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_WATER_LEVEL_LOWERED] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_NAVIGATION_ROOM_LEAVING_AQA] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_GO_TO_PYR1,
        .navRoom = NAV_ROOM_SECTOR_4_ROOM_2,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_NAVIGATION_ROOM_ENTERING_PYR] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_FIND_SECURITY_ROOM_AND_DOWNLOAD_SUPER_MISSILES,
        .navRoom = NAV_ROOM_SECTOR_3_ROOM_2,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_SECURITY_LEVEL_2_UNLOCKED] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_4] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_LEVEL_2_UNLOCKED_GO_DOWNLOAD_SUPER_MISSILES,
        .navRoom = NAV_ROOM_SECTOR_3_ROOM_2,
        .download = FALSE,
        .skippable = TRUE
    },
    [EVENT_ENTERED_SUPER_MISSILE_DATA_ROOM] = {
        .area = AREA_SECTOR_3,
        .room = 22,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_SUPER_MISSILE_DATA_DOWNLOADED] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_24,
        .navRoom = NAV_ROOM_NONE,
        .download = TRUE,
        .skippable = FALSE
    },
    [EVENT_TRIGGERED_BOX_RUMBLE] = {
        .area = AREA_SECTOR_3,
        .room = 23,
        .xStart = 2,
        .yStart = 2,
        .xEnd = 11,
        .yEnd = 11,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_BOX_DEFEATED] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_NAVIGATION_ROOM_LEAVING_PYR] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_GO_TO_NOC1,
        .navRoom = NAV_ROOM_SECTOR_3_ROOM_2,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_LEFT_NAVIGATION_ROOM] = {
        .area = AREA_SECTOR_3,
        .room = 21,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_SECRET_CONVERSATION] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_FEDERATION_MONITOR_SAMUS,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = TRUE
    },
    [EVENT_SECRET_CONVERSATION_OVER] = {
        .area = AREA_MAIN_DECK,
        .room = 30,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_SKIPPED_BY_USING_NOC_NAVIGATION_ROOM] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_GO_TO_NOC1_AFTER_FEDERATION,
        .navRoom = NAV_ROOM_ANY,
        .download = FALSE,
        .skippable = TRUE
    },
    [EVENT_ENTERED_NOC_NAVIGATION_ROOM] = {
        .area = AREA_SECTOR_6,
        .room = 3,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_NAVIGATION_ROOM_ENTERING_NOC] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_GO_DOWNLOAD_VARIA_SUIT,
        .navRoom = NAV_ROOM_SECTOR_6_ROOM_2,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_NOC_SA_X_ENCOUNTER] = {
        .area = AREA_SECTOR_6,
        .room = 28,
        .xStart = 5,
        .yStart = 10,
        .xEnd = 9,
        .yEnd = 11,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_ESCAPED_NOC_SA_X] = {
        .area = AREA_SECTOR_6,
        .room = 11,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_NOC_DATA_ROOM_DESTROYED] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_29,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_VARIA_SUIT_ABILITY_RECOVERED] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_REACHED_TOP_OF_ROOM_AFTER_VARIA] = {
        .area = AREA_SECTOR_6,
        .room = 32,
        .xStart = 2,
        .yStart = 2,
        .xEnd = 16,
        .yEnd = 10,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_NAVIGATION_ROOM_LEAVING_NOC] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_GO_TO_ARC1,
        .navRoom = NAV_ROOM_SECTOR_6_ROOM_2,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_NAVIGATION_ROOM_ENTERING_ARC] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_FIND_SECURITY_ROOM_AND_DOWNLOAD_ICE_MISSILES,
        .navRoom = NAV_ROOM_SECTOR_5_ROOM_2,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_SECURITY_LEVEL_3_UNLOCKED] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_5] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_LEVEL_3_UNLOCKED_GO_DOWNLOAD_ICE_MISSILES,
        .navRoom = NAV_ROOM_SECTOR_5_ROOM_2,
        .download = FALSE,
        .skippable = TRUE
    },
    [EVENT_ENTERED_ICE_MISSILE_DATA_ROOM] = {
        .area = AREA_SECTOR_5,
        .room = 6,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_ICE_MISSILE_DATA_DOWNLOADED] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_33,
        .navRoom = NAV_ROOM_NONE,
        .download = TRUE,
        .skippable = FALSE
    },
    [EVENT_NAVIGATION_ROOM_LEAVING_ARC] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_GO_TO_THE_MAIN_BOILER,
        .navRoom = NAV_ROOM_SECTOR_5_ROOM_2,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_WIDE_BEAM_ABILITY_RECOVERED] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_COOLING_UNIT_OPERATIONAL] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_35,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_NAVIGATION_ROOM_LEAVING_PYR_2] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_GO_TO_THE_HABITATION_DECK,
        .navRoom = NAV_ROOM_SECTOR_3_ROOM_2,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_ANIMALS_RELEASED] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_37,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_NAVIGATION_ROOM_AFTER_ANIMALS] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_GO_TO_ARC2,
        .navRoom = NAV_ROOM_ANY,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_NAVIGATION_ROOM_ENTERING_ARC_2] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_GO_DOWNLOAD_POWER_BOMBS,
        .navRoom = NAV_ROOM_SECTOR_5_ROOM_2,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_POWER_BOMB_DATA_DOWNLOADED] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_40,
        .navRoom = NAV_ROOM_NONE,
        .download = TRUE,
        .skippable = FALSE
    },
    [EVENT_ARC_SA_X_ENCOUNTER] = {
        .area = AREA_SECTOR_5,
        .room = 44,
        .xStart = 36,
        .yStart = 2,
        .xEnd = 54,
        .yEnd = 11,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_ESCAPED_ARC_SA_X] = {
        .area = AREA_SECTOR_5,
        .room = 23,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_NAVIGATION_ROOM_LEAVING_ARC_2] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_RETURN_TO_YOUR_SHIP,
        .navRoom = NAV_ROOM_SECTOR_5_ROOM_2,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_POWER_OUTAGE] = {
        .area = AREA_MAIN_DECK,
        .room = 44,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_ENTERED_SHIP] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_REACTIVATE_THE_AUXILIARY_POWER_SYSTEM,
        .navRoom = NAV_ROOM_ANY,
        .download = FALSE,
        .skippable = TRUE
    },
    [EVENT_ENTERED_YAKUZA_ROOM] = {
        .area = AREA_MAIN_DECK,
        .room = 87,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_SPACE_JUMP_ABILITY_RECOVERED] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_AUXILARY_POWER_ENGAGED] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_43,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_NAVIGATION_ROOM_AFTER_YAKUZA] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_FIND_SOURCE_OF_VEGETATION,
        .navRoom = NAV_ROOM_ANY,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_ENGAGED_TRO_2_SA_X] = {
        .area = AREA_SECTOR_2,
        .room = 25,
        .xStart = 2,
        .yStart = 10,
        .xEnd = 10,
        .yEnd = 21,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_ESCAPED_TRO_2_SA_X] = {
        .area = AREA_SECTOR_2,
        .room = 33,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_PLASMA_BEAM_ABILITY_RECOVERED] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_NAVIGATION_ROOM_LEAVING_TRO_2] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_GO_TO_ARC3,
        .navRoom = NAV_ROOM_ANY,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_NAVIGATION_ROOM_ENTERING_ARC_3] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_DEFEAT_NIGHTMARE,
        .navRoom = NAV_ROOM_SECTOR_5_ROOM_2,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_GRAVITY_SUIT_ABILITY_RECOVERED] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_ENTERED_LEVEL_4_SECURITY_ROOM] = {
        .area = AREA_SECTOR_4,
        .room = 27,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_47,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = TRUE
    },
    [EVENT_SECURITY_LEVEL_4_UNLOCKED] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_SECRET_MESSAGE_2] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_SECRET_MESSAGE,
        .navRoom = NAV_ROOM_SECTOR_4_ROOM_2,
        .download = FALSE,
        .skippable = TRUE
    },
    [EVENT_ENTERED_DIFFUSION_MISSILE_DATA_ROOM] = {
        .area = AREA_SECTOR_4,
        .room = 5,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_DIFFUSION_MISSILE_DATA_DOWNLOADED] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = TRUE,
        .skippable = FALSE
    },
    [EVENT_NAVIGATION_ROOM_LEAVING_AQA_2] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_GO_TO_NOC2,
        .navRoom = NAV_ROOM_SECTOR_4_ROOM_2,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_NAVIGATION_ROOM_ENTERING_NOC_2] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_DEFEAT_BOX_2,
        .navRoom = NAV_ROOM_SECTOR_6_ROOM_2,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_RESTRICTED_ZONE_WARNING] = {
        .area = AREA_SECTOR_6,
        .room = 23,
        .xStart = 2,
        .yStart = 2,
        .xEnd = 15,
        .yEnd = 11,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_TRIGGERED_BOX_2_RUMBLE] = {
        .area = AREA_SECTOR_6,
        .room = 21,
        .xStart = 11,
        .yStart = 2,
        .xEnd = 16,
        .yEnd = 11,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_WAVE_BEAM_ABILITY_RECOVERED] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_RESTRICTED_LABORATORY_EXPLOSION] = {
        .area = AREA_MAIN_DECK,
        .room = 79,
        .xStart = 9,
        .yStart = 22,
        .xEnd = 16,
        .yEnd = 31,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_60_SECONDS_TO_DETACHMENT] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_ESCAPED_RESTRICTED_LABORATORY] = {
        .area = AREA_MAIN_DECK,
        .room = 78,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_NAVIGATION_ROOM_AFTER_RESTRICTED_LABORATORY] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_METROID_BREEDING_PROGRAM,
        .navRoom = NAV_ROOM_MAIN_DECK_ROOM_66,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_SCREW_ATTACK_ABILITY_RECOVERED] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_NAVIGATION_ROOM_LEAVING_SRX_2] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_FEDERATION_ON_THEIR_WAY,
        .navRoom = NAV_ROOM_ANY,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_END_OF_FIRST_CONVERSATION] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_SECOND_CONVERSATION] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_GO_TO_OPERATIONS_ROOM,
        .navRoom = NAV_ROOM_ANY,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_6] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_GO_TO_OPERATIONS_ROOM_2,
        .navRoom = NAV_ROOM_ANY,
        .download = FALSE,
        .skippable = TRUE
    },
    [EVENT_ENTERED_OPERATION_DECK] = {
        .area = AREA_MAIN_DECK,
        .room = 86,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_SA_X_DEFEATED] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_ORBIT_CHANGE_IMPLEMENTED] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_55,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_7] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_GET_OUT_BEFORE_IMPACT_UNUSED,
        .navRoom = NAV_ROOM_ANY,
        .download = FALSE,
        .skippable = TRUE
    },
    [EVENT_ENTERED_SHIP_ROOM] = {
        .area = AREA_MAIN_DECK,
        .room = 64,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_SA_X_KILLED_BY_OMEGA_METROID] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_ICE_BEAM_ABILITY_RECOVERED] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_OMEGA_METROID_DEFEATED] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_NONE,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
    [EVENT_ESCAPED_ON_SHIP] = {
        .area = UCHAR_MAX,
        .room = UCHAR_MAX,
        .xStart = UCHAR_MAX,
        .yStart = UCHAR_MAX,
        .xEnd = UCHAR_MAX,
        .yEnd = UCHAR_MAX,
        .navConversation = NAV_CONVO_THEY_LENT_ME_A_HAND,
        .navRoom = NAV_ROOM_NONE,
        .download = FALSE,
        .skippable = FALSE
    },
};

const u8 sNumberOfTanksPerArea[AREA_NORMAL_COUNT + 1][TANK_COUNT] = {
    [AREA_MAIN_DECK] = {
        [TANK_ENERGY] = 3,
        [TANK_MISSILE] = 7,
        [TANK_POWER_BOMB] = 3
    },
    [AREA_SECTOR_1] = {
        [TANK_ENERGY] = 3,
        [TANK_MISSILE] = 6,
        [TANK_POWER_BOMB] = 3
    },
    [AREA_SECTOR_2] = {
        [TANK_ENERGY] = 3,
        [TANK_MISSILE] = 9,
        [TANK_POWER_BOMB] = 5
    },
    [AREA_SECTOR_3] = {
        [TANK_ENERGY] = 3,
        [TANK_MISSILE] = 7,
        [TANK_POWER_BOMB] = 6
    },
    [AREA_SECTOR_4] = {
        [TANK_ENERGY] = 2,
        [TANK_MISSILE] = 9,
        [TANK_POWER_BOMB] = 4
    },
    [AREA_SECTOR_5] = {
        [TANK_ENERGY] = 3,
        [TANK_MISSILE] = 4,
        [TANK_POWER_BOMB] = 8
    },
    [AREA_SECTOR_6] = {
        [TANK_ENERGY] = 3,
        [TANK_MISSILE] = 6,
        [TANK_POWER_BOMB] = 3
    },
    [AREA_NORMAL_COUNT] = {
        [TANK_ENERGY] = 20,
        [TANK_MISSILE] = 48,
        [TANK_POWER_BOMB] = 32
    },
};

const u8 sObtainItemEvents[ABILITY_COUNT_END + 1] = {
    [ABILITY_COUNT_NONE] = EVENT_NONE,
    [ABILITY_COUNT_MISSILES] = EVENT_MISSILE_DATA_DOWNLOADED,
    [ABILITY_COUNT_MORPH_BALL] = EVENT_MORPH_BALL_ABILITY_RECOVERED,
    [ABILITY_COUNT_CHARGE_BEAM] = EVENT_CHARGE_BEAM_ABILITY_RECOVERED,
    [ABILITY_COUNT_BOMBS] = EVENT_BOMB_DATA_DOWNLOADED,
    [ABILITY_COUNT_HIGH_JUMP] = EVENT_HIGH_JUMP_ABILITY_RECOVERED,
    [ABILITY_COUNT_SPEED_BOOSTER] = EVENT_SPEED_BOOSTER_ABILITY_RECOVERED,
    [ABILITY_COUNT_SUPER_MISSILES] = EVENT_SUPER_MISSILE_DATA_DOWNLOADED,
    [ABILITY_COUNT_VARIA_SUIT] = EVENT_VARIA_SUIT_ABILITY_RECOVERED,
    [ABILITY_COUNT_ICE_MISSILES] = EVENT_ICE_MISSILE_DATA_DOWNLOADED,
    [ABILITY_COUNT_WIDE_BEAM] = EVENT_WIDE_BEAM_ABILITY_RECOVERED,
    [ABILITY_COUNT_POWER_BOMBS] = EVENT_POWER_BOMB_DATA_DOWNLOADED,
    [ABILITY_COUNT_SPACE_JUMP] = EVENT_SPACE_JUMP_ABILITY_RECOVERED,
    [ABILITY_COUNT_PLASMA_BEAM] = EVENT_PLASMA_BEAM_ABILITY_RECOVERED,
    [ABILITY_COUNT_GRAVITY_SUIT] = EVENT_GRAVITY_SUIT_ABILITY_RECOVERED,
    [ABILITY_COUNT_DIFFUSION_MISSILES] = EVENT_DIFFUSION_MISSILE_DATA_DOWNLOADED,
    [ABILITY_COUNT_WAVE_BEAM] = EVENT_WAVE_BEAM_ABILITY_RECOVERED,
    [ABILITY_COUNT_SCREW_ATTACK] = EVENT_SCREW_ATTACK_ABILITY_RECOVERED,
    [ABILITY_COUNT_ICE_BEAM] = EVENT_ICE_BEAM_ABILITY_RECOVERED,
    [ABILITY_COUNT_END] = EVENT_NONE,
};

// TODO: Use enum for messageNumber
const struct AbilityRamValue sAbilityRamValues[ABILITY_COUNT_END] = {
    [ABILITY_COUNT_NONE] = {
        .beamStatus = 0,
        .weaponStatus = 0,
        .suitStatus = 0,
        .isSuit = FALSE,
        .messageNumber = 0,
        .soundEvent = SOUND_EVENT_FIRST_CONVERSATION_STARTED
    },
    [ABILITY_COUNT_MISSILES] = {
        .beamStatus = 0,
        .weaponStatus = MBF_MISSILES,
        .suitStatus = 0,
        .isSuit = FALSE,
        .messageNumber = 4,
        .soundEvent = SOUND_EVENT_DOWNLOADED_MISSILES
    },
    [ABILITY_COUNT_MORPH_BALL] = {
        .beamStatus = 0,
        .weaponStatus = 0,
        .suitStatus = SMF_MORPH_BALL,
        .isSuit = FALSE,
        .messageNumber = 10,
        .soundEvent = SOUND_EVENT_MORPH_BALL_ABILITY_RECOVERED
    },
    [ABILITY_COUNT_CHARGE_BEAM] = {
        .beamStatus = BF_CHARGE_BEAM,
        .weaponStatus = 0,
        .suitStatus = 0,
        .isSuit = FALSE,
        .messageNumber = 17,
        .soundEvent = SOUND_EVENT_CHARGE_BEAM_ABILITY_RECOVERED
    },
    [ABILITY_COUNT_BOMBS] = {
        .beamStatus = 0,
        .weaponStatus = MBF_BOMBS,
        .suitStatus = 0,
        .isSuit = FALSE,
        .messageNumber = 6,
        .soundEvent = SOUND_EVENT_DOWNLOADED_BOMBS
    },
    [ABILITY_COUNT_HIGH_JUMP] = {
        .beamStatus = 0,
        .weaponStatus = 0,
        .suitStatus = SMF_HIGH_JUMP,
        .isSuit = FALSE,
        .messageNumber = 11,
        .soundEvent = SOUND_EVENT_HI_JUMP_ABILITY_RECOVERED
    },
    [ABILITY_COUNT_SPEED_BOOSTER] = {
        .beamStatus = 0,
        .weaponStatus = 0,
        .suitStatus = SMF_SPEED_BOOSTER,
        .isSuit = FALSE,
        .messageNumber = 14,
        .soundEvent = SOUND_EVENT_SPEED_BOOSTER_ABILITY_RECOVERED
    },
    [ABILITY_COUNT_SUPER_MISSILES] = {
        .beamStatus = 0,
        .weaponStatus = MBF_SUPER_MISSILES,
        .suitStatus = 0,
        .isSuit = FALSE,
        .messageNumber = 5,
        .soundEvent = SOUND_EVENT_DOWNLOADED_SUPER_MISSILES
    },
    [ABILITY_COUNT_VARIA_SUIT] = {
        .beamStatus = 0,
        .weaponStatus = 0,
        .suitStatus = SMF_VARIA_SUIT,
        .isSuit = TRUE,
        .messageNumber = 15,
        .soundEvent = SOUND_EVENT_VARIA_SUIT_RECOVERED
    },
    [ABILITY_COUNT_ICE_MISSILES] = {
        .beamStatus = 0,
        .weaponStatus = MBF_ICE_MISSILES,
        .suitStatus = 0,
        .isSuit = FALSE,
        .messageNumber = 8,
        .soundEvent = SOUND_EVENT_DOWNLOADED_ICE_MISSILES
    },
    [ABILITY_COUNT_WIDE_BEAM] = {
        .beamStatus = BF_WIDE_BEAM,
        .weaponStatus = 0,
        .suitStatus = 0,
        .isSuit = FALSE,
        .messageNumber = 18,
        .soundEvent = SOUND_EVENT_WIDE_BEAM_ABILITY_RECOVERED
    },
    [ABILITY_COUNT_POWER_BOMBS] = {
        .beamStatus = 0,
        .weaponStatus = MBF_POWER_BOMBS,
        .suitStatus = 0,
        .isSuit = FALSE,
        .messageNumber = 7,
        .soundEvent = SOUND_EVENT_DOWNLOADED_POWER_BOMBS
    },
    [ABILITY_COUNT_SPACE_JUMP] = {
        .beamStatus = 0,
        .weaponStatus = 0,
        .suitStatus = SMF_SPACE_JUMP,
        .isSuit = FALSE,
        .messageNumber = 13,
        .soundEvent = SOUND_EVENT_SPACE_JUMP_ABILITY_RECOVERED
    },
    [ABILITY_COUNT_PLASMA_BEAM] = {
        .beamStatus = BF_PLASMA_BEAM,
        .weaponStatus = 0,
        .suitStatus = 0,
        .isSuit = FALSE,
        .messageNumber = 20,
        .soundEvent = SOUND_EVENT_PLASMA_BEAM_ABILITY_RECOVERED
    },
    [ABILITY_COUNT_GRAVITY_SUIT] = {
        .beamStatus = 0,
        .weaponStatus = 0,
        .suitStatus = SMF_GRAVITY_SUIT,
        .isSuit = TRUE,
        .messageNumber = 16,
        .soundEvent = SOUND_EVENT_GRAVITY_SUIT_RECOVERED
    },
    [ABILITY_COUNT_DIFFUSION_MISSILES] = {
        .beamStatus = 0,
        .weaponStatus = MBF_DIFFUSION_MISSILES,
        .suitStatus = 0,
        .isSuit = FALSE,
        .messageNumber = 9,
        .soundEvent = SOUND_EVENT_DOWNLOADED_DIFFUSION_MISSILES
    },
    [ABILITY_COUNT_WAVE_BEAM] = {
        .beamStatus = BF_WAVE_BEAM,
        .weaponStatus = 0,
        .suitStatus = 0,
        .isSuit = FALSE,
        .messageNumber = 19,
        .soundEvent = SOUND_EVENT_WAVE_BEAM_ABILITY_RECOVERED
    },
    [ABILITY_COUNT_SCREW_ATTACK] = {
        .beamStatus = 0,
        .weaponStatus = 0,
        .suitStatus = SMF_SCREW_ATTACK,
        .isSuit = FALSE,
        .messageNumber = 12,
        .soundEvent = SOUND_EVENT_SCREW_ATTACK_ABILITY_RECOVERED
    },
    [ABILITY_COUNT_ICE_BEAM] = {
        .beamStatus = BF_ICE_BEAM,
        .weaponStatus = 0,
        .suitStatus = 0,
        .isSuit = FALSE,
        .messageNumber = 21,
        .soundEvent = SOUND_EVENT_FIRST_CONVERSATION_STARTED
    },
};

const u8 sNavigationRoomLocations[NAV_ROOM_COUNT][2] = {
    [NAV_ROOM_MAIN_DECK_ROOM_0] = {
        AREA_MAIN_DECK,
        0 + 1
    },
    [NAV_ROOM_MAIN_DECK_ROOM_16] = {
        AREA_MAIN_DECK,
        16 + 1
    },
    [NAV_ROOM_MAIN_DECK_ROOM_9] = {
        AREA_MAIN_DECK,
        9 + 1
    },
    [NAV_ROOM_MAIN_DECK_ROOM_32] = {
        AREA_MAIN_DECK,
        32 + 1
    },
    [NAV_ROOM_SECTOR_1_ROOM_2] = {
        AREA_SECTOR_1,
        2 + 1
    },
    [NAV_ROOM_SECTOR_5_ROOM_2] = {
        AREA_SECTOR_5,
        2 + 1
    },
    [NAV_ROOM_SECTOR_2_ROOM_2] = {
        AREA_SECTOR_2,
        2 + 1
    },
    [NAV_ROOM_SECTOR_4_ROOM_2] = {
        AREA_SECTOR_4,
        2 + 1
    },
    [NAV_ROOM_SECTOR_3_ROOM_2] = {
        AREA_SECTOR_3,
        2 + 1
    },
    [NAV_ROOM_SECTOR_6_ROOM_2] = {
        AREA_SECTOR_6,
        2 + 1
    },
    [NAV_ROOM_MAIN_DECK_ROOM_56] = {
        AREA_MAIN_DECK,
        56 + 1
    },
    [NAV_ROOM_MAIN_DECK_ROOM_66] = {
        AREA_MAIN_DECK,
        66 + 1
    },
    [NAV_ROOM_ANY] = {
        UCHAR_MAX,
        UCHAR_MAX
    },
};

const u8 sNavigationTargetLocationAreas[NAV_TARGET_LOC_END] = {
    [NAV_TARGET_LOC_NONE] = AREA_MAIN_DECK,
    [NAV_TARGET_LOC_OPERATIONS_DECK] = AREA_MAIN_DECK,
    [NAV_TARGET_LOC_DOCKING_BAYS] = AREA_MAIN_DECK,
    [NAV_TARGET_LOC_HABITATION_DECK] = AREA_MAIN_DECK,
    [NAV_TARGET_LOC_MAIN_DECK] = AREA_MAIN_DECK,
    [NAV_TARGET_LOC_REACTOR_SILO] = AREA_MAIN_DECK,
    [NAV_TARGET_LOC_RESTRICTED_LAB] = AREA_MAIN_DECK,
    [NAV_TARGET_LOC_SECTOR_1] = AREA_SECTOR_1,
    [NAV_TARGET_LOC_SECTOR_2] = AREA_SECTOR_2,
    [NAV_TARGET_LOC_SECTOR_3] = AREA_SECTOR_3,
    [NAV_TARGET_LOC_SECTOR_4] = AREA_SECTOR_4,
    [NAV_TARGET_LOC_SECTOR_5] = AREA_SECTOR_5,
    [NAV_TARGET_LOC_SECTOR_6] = AREA_SECTOR_6,
};

const u8 sEvent_576073[AREA_END] = {
    [AREA_MAIN_DECK] = 0,
    [AREA_SECTOR_1] = 7,
    [AREA_SECTOR_2] = 8,
    [AREA_SECTOR_3] = 9,
    [AREA_SECTOR_4] = 10,
    [AREA_SECTOR_5] = 11,
    [AREA_SECTOR_6] = 12,
    [AREA_TEST_1] = 0,
    [AREA_TEST_2] = 0,
    [AREA_TEST_3] = 0,
};

const u8 sEvent_57607D[13] = {
    UCHAR_MAX,
    UCHAR_MAX,
    UCHAR_MAX,
    UCHAR_MAX,
    UCHAR_MAX,
    UCHAR_MAX,
    UCHAR_MAX,
    0x12,
    0x0C,
    0x18,
    0x06,
    0x1E,
    0x00,
};

const u8 sEvent_57608A[13] = {
    UCHAR_MAX,
    UCHAR_MAX,
    UCHAR_MAX,
    UCHAR_MAX,
    UCHAR_MAX,
    UCHAR_MAX,
    UCHAR_MAX,
    0x12,
    0x18,
    0x0C,
    0x1E,
    0x06,
    0x00,
};

// TODO: Use enum for cutscene 
const struct MonologueEvent sMonologueEvents[6] = {
    {
        .event = EVENT_NAVIGATION_ROOM_BEFORE_ELEVATOR,
        .elevatorRoomPair = ELEVATOR_MAIN_DECK_TO_OPERATIONS_DECK,
        .side = 0,
        .cutscene = 2,
        .soundEventAtStart = SOUND_EVENT_OPERATIONS_DECK_ELEVATOR_MONOLOGUE_STARTED,
        .soundEventAtEnd = SOUND_EVENT_OPERATIONS_DECK_ELEVATOR_MONOLOGUE_ENDED
    },
    {
        .event = EVENT_NAVIGATION_ROOM_LEAVING_SRX,
        .elevatorRoomPair = ELEVATOR_MAIN_DECK_TO_SECTOR_1,
        .side = 0,
        .cutscene = 3,
        .soundEventAtStart = SOUND_EVENT_FIRST_CONVERSATION_STARTED,
        .soundEventAtEnd = SOUND_EVENT_FIRST_CONVERSATION_STARTED
    },
    {
        .event = EVENT_NAVIGATION_ROOM_LEAVING_TRO,
        .elevatorRoomPair = ELEVATOR_MAIN_DECK_TO_SECTOR_2,
        .side = 0,
        .cutscene = 4,
        .soundEventAtStart = SOUND_EVENT_LEAVING_TRO1_ELEVATOR_MONOLOGUE_STARTED,
        .soundEventAtEnd = SOUND_EVENT_LEAVING_TRO1_ELEVATOR_MONOLOGUE_ENDED
    },
    {
        .event = EVENT_ANIMALS_RELEASED,
        .elevatorRoomPair = ELEVATOR_MAIN_DECK_TO_HABITATIONS_DECK,
        .side = 0,
        .cutscene = 5,
        .soundEventAtStart = SOUND_EVENT_LEAVING_HABITATION_DECK_MONOLOGUE_STARTED,
        .soundEventAtEnd = SOUND_EVENT_87
    },
    {
        .event = EVENT_NAVIGATION_ROOM_AFTER_RESTRICTED_LABORATORY,
        .elevatorRoomPair = ELEVATOR_RESTRICTED_ZONE_TO_SECTOR_1,
        .side = 1,
        .cutscene = 6,
        .soundEventAtStart = SOUND_EVENT_RESTRICTED_LAB_ELEVATOR_MONOLOGUE_STARTED,
        .soundEventAtEnd = SOUND_EVENT_RESTRICTED_LAB_ELEVATOR_MONOLOGUE_ENDED
    },
    {
        .event = EVENT_LEFT_NAVIGATION_ROOM,
        .elevatorRoomPair = ELEVATOR_MAIN_DECK_TO_SECTOR_3,
        .side = 0,
        .cutscene = 9,
        .soundEventAtStart = SOUND_EVENT_LEAVING_PYR1_FEDERATION_CONVERSATION_STARTED,
        .soundEventAtEnd = SOUND_EVENT_LEAVING_PYR1_FEDERATION_CONVERSATION_ENDED
    },
};

const struct SecurityUnlockEvent sSecurityUnlockEvents[SECURITY_LEVEL_END - 1] = {
    {
        .securityLevel = 1,
        .area = AREA_SECTOR_2,
        .previousEvent = EVENT_NAVIGATION_ROOM_ENTERING_TRO,
        .nextEvent = EVENT_SECURITY_LEVEL_1_UNLOCKED,
        .soundEvent = SOUND_EVENT_UNLOCKED_SECURITY_LEVEL_1
    },
    {
        .securityLevel = 2,
        .area = AREA_SECTOR_3,
        .previousEvent = EVENT_NAVIGATION_ROOM_ENTERING_PYR,
        .nextEvent = EVENT_SECURITY_LEVEL_2_UNLOCKED,
        .soundEvent = SOUND_EVENT_UNLOCKED_SECURITY_LEVEL_2
    },
    {
        .securityLevel = 3,
        .area = AREA_SECTOR_5,
        .previousEvent = EVENT_NAVIGATION_ROOM_ENTERING_ARC,
        .nextEvent = EVENT_SECURITY_LEVEL_3_UNLOCKED,
        .soundEvent = SOUND_EVENT_UNLOCKED_LEVEL_3_SECURITY
    },
    {
        .securityLevel = 4,
        .area = AREA_SECTOR_4,
        .previousEvent = EVENT_ENTERED_LEVEL_4_SECURITY_ROOM,
        .nextEvent = EVENT_SECURITY_LEVEL_4_UNLOCKED,
        .soundEvent = SOUND_EVENT_UNLOCKED_SECURITY_LEVEL_4
    },
};

static const u8 sBlob_5760e8_576168[] = INCBIN_U8("data/Blob_5760e8_576168.bin");
