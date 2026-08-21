#include "data/connection_data.h"
#include "constants/event.h"
#include "macros.h"

const u8 sDimLightingEvents[4][DIM_EVENT_FIELD_COUNT] = {
    {
        [DIM_EVENT_FIELD_EVENT] = EVENT_ENTERED_NAVIGATION_ROOM_POWER_OUTAGE,
        [DIM_EVENT_FIELD_FLAG] = TRUE
    },
    {
        [DIM_EVENT_FIELD_EVENT] = EVENT_MORPH_BALL_ABILITY_RECOVERED,
        [DIM_EVENT_FIELD_FLAG] = FALSE
    },
    {
        [DIM_EVENT_FIELD_EVENT] = EVENT_POWER_OUTAGE,
        [DIM_EVENT_FIELD_FLAG] = TRUE
    },
    {
        [DIM_EVENT_FIELD_EVENT] = EVENT_AUXILARY_POWER_ENGAGED,
        [DIM_EVENT_FIELD_FLAG] = FALSE
    }
};


#define NAV_HATCHES(flags)                 \
    .room1LeftHatch   = ((flags) >>  0) & 1, \
    .room1RightHatch  = ((flags) >>  1) & 1, \
    .room2LeftHatch   = ((flags) >>  2) & 1, \
    .room2RightHatch  = ((flags) >>  3) & 1, \
    .room3LeftHatch   = ((flags) >>  4) & 1, \
    .room3RightHatch  = ((flags) >>  5) & 1, \
    .room4LeftHatch   = ((flags) >>  6) & 1, \
    .room4RightHatch  = ((flags) >>  7) & 1, \
    .room5LeftHatch   = ((flags) >>  8) & 1, \
    .room5RightHatch  = ((flags) >>  9) & 1, \
    .room6LeftHatch   = ((flags) >> 10) & 1, \
    .room6RightHatch  = ((flags) >> 11) & 1, \
    .room7LeftHatch   = ((flags) >> 12) & 1, \
    .room7RightHatch  = ((flags) >> 13) & 1, \
    .room8LeftHatch   = ((flags) >> 14) & 1, \
    .room8RightHatch  = ((flags) >> 15) & 1, \
    .room9LeftHatch   = ((flags) >> 16) & 1, \
    .room9RightHatch  = ((flags) >> 17) & 1, \
    .room10LeftHatch  = ((flags) >> 18) & 1, \
    .room10RightHatch = ((flags) >> 19) & 1, \
    .room11LeftHatch  = ((flags) >> 20) & 1, \
    .room11RightHatch = ((flags) >> 21) & 1,

#define NAV_HATCH(room, side) (1 << ((room - 1) * 2 + side))

#define HATCH_LEFT 0
#define HATCH_RIGHT 1

const struct NavigationRoomHatchLockEvent sNavigationRoomHatchLockEvents[89] = {
    {
        .event = EVENT_NONE,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_16, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_16, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_NAVIGATION_ROOM_BEFORE_QUARANTINE_BAY,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_16, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_QUARANTINE_BAY_HORNOAD_DEAD,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_16, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_16, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_NAVIGATION_ROOM_AFTER_QUARANTINE_BAY,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_16, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_9, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_9, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_NAVIGATION_ROOM_BEFORE_ELEVATOR,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_16, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_32, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_1,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_16, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_32, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_ENTERED_MISSILE_DATA_ROOM,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_32, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_MISSILE_DATA_DOWNLOADED,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_32, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_32, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_ENTERED_NAVIGATION_ROOM_POWER_OUTAGE,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_32, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_32, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_MORPH_BALL_ABILITY_RECOVERED,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_16, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_9, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_NAVIGATION_ROOM_AFTER_MORPH_BALL,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_9, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_SA_X_ELEVATOR_CUTSCENE_ENDS,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_1_ROOM_2, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_SECTOR_1_ROOM_2, HATCH_RIGHT) |
            NAV_HATCH(NAV_ROOM_SECTOR_2_ROOM_2, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_NAVIGATION_ROOM_ENTERING_SRX,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_1_ROOM_2, HATCH_LEFT)
        )
    },
    {
        .event = EVENT_CHARGE_BEAM_ABILITY_RECOVERED,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_1_ROOM_2, HATCH_LEFT)
        )
    },
    {
        .event = EVENT_ALL_STABILIZERS_ONLINE,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_1_ROOM_2, HATCH_LEFT)
        )
    },
    {
        .event = EVENT_NAVIGATION_ROOM_LEAVING_SRX,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_2_ROOM_2, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_SECTOR_2_ROOM_2, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_NAVIGATION_ROOM_ENTERING_TRO,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_2_ROOM_2, HATCH_LEFT)
        )
    },
    {
        .event = EVENT_SECURITY_LEVEL_1_UNLOCKED,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_2_ROOM_2, HATCH_LEFT)
        )
    },
    {
        .event = EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_2,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_2_ROOM_2, HATCH_LEFT)
        )
    },
    {
        .event = EVENT_ENTERING_BOMB_DATA_ROOM,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_2_ROOM_2, HATCH_LEFT)
        )
    },
    {
        .event = EVENT_HIGH_JUMP_ABILITY_RECOVERED,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_2_ROOM_2, HATCH_LEFT)
        )
    },
    {
        .event = EVENT_ESCAPED_TRO_1_SA_X,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_2_ROOM_2, HATCH_LEFT)
        )
    },
    {
        .event = EVENT_NAVIGATION_ROOM_LEAVING_TRO,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_4_ROOM_2, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_SECTOR_4_ROOM_2, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_NAVIGATION_ROOM_ENTERING_AQA,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_4_ROOM_2, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_SPEED_BOOSTER_ABILITY_RECOVERED,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_4_ROOM_2, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_3,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_4_ROOM_2, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_ENTERED_PUMP_CONTROL_UNIT,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_4_ROOM_2, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_WATER_LEVEL_LOWERED,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_4_ROOM_2, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_NAVIGATION_ROOM_LEAVING_AQA,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_3_ROOM_2, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_SECTOR_3_ROOM_2, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_NAVIGATION_ROOM_ENTERING_PYR,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_3_ROOM_2, HATCH_LEFT)
        )
    },
    {
        .event = EVENT_SECURITY_LEVEL_2_UNLOCKED,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_3_ROOM_2, HATCH_LEFT)
        )
    },
    {
        .event = EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_4,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_3_ROOM_2, HATCH_LEFT)
        )
    },
    {
        .event = EVENT_ENTERED_SUPER_MISSILE_DATA_ROOM,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_3_ROOM_2, HATCH_LEFT)
        )
    },
    {
        .event = EVENT_TRIGGERED_BOX_RUMBLE,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_3_ROOM_2, HATCH_LEFT)
        )
    },
    {
        .event = EVENT_BOX_DEFEATED,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_3_ROOM_2, HATCH_LEFT)
        )
    },
    {
        .event = EVENT_NAVIGATION_ROOM_LEAVING_PYR,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_6_ROOM_2, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_SECTOR_6_ROOM_2, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_LEFT_NAVIGATION_ROOM,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_6_ROOM_2, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_SECTOR_6_ROOM_2, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_SECRET_CONVERSATION,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_6_ROOM_2, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_SECTOR_6_ROOM_2, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_SECRET_CONVERSATION_OVER,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_6_ROOM_2, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_SECTOR_6_ROOM_2, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_SKIPPED_BY_USING_NOC_NAVIGATION_ROOM,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_6_ROOM_2, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_SECTOR_6_ROOM_2, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_ENTERED_NOC_NAVIGATION_ROOM,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_6_ROOM_2, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_SECTOR_6_ROOM_2, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_NAVIGATION_ROOM_ENTERING_NOC,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_6_ROOM_2, HATCH_LEFT)
        )
    },
    {
        .event = EVENT_NOC_SA_X_ENCOUNTER,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_6_ROOM_2, HATCH_LEFT)
        )
    },
    {
        .event = EVENT_ESCAPED_NOC_SA_X,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_6_ROOM_2, HATCH_LEFT)
        )
    },
    {
        .event = EVENT_NOC_DATA_ROOM_DESTROYED,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_6_ROOM_2, HATCH_LEFT)
        )
    },
    {
        .event = EVENT_VARIA_SUIT_ABILITY_RECOVERED,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_6_ROOM_2, HATCH_LEFT)
        )
    },
    {
        .event = EVENT_REACHED_TOP_OF_ROOM_AFTER_VARIA,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_6_ROOM_2, HATCH_LEFT)
        )
    },
    {
        .event = EVENT_NAVIGATION_ROOM_LEAVING_NOC,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_5_ROOM_2, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_SECTOR_5_ROOM_2, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_NAVIGATION_ROOM_ENTERING_ARC,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_5_ROOM_2, HATCH_LEFT)
        )
    },
    {
        .event = EVENT_SECURITY_LEVEL_3_UNLOCKED,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_5_ROOM_2, HATCH_LEFT)
        )
    },
    {
        .event = EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_5,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_5_ROOM_2, HATCH_LEFT)
        )
    },
    {
        .event = EVENT_ENTERED_ICE_MISSILE_DATA_ROOM,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_5_ROOM_2, HATCH_LEFT)
        )
    },
    {
        .event = EVENT_ICE_MISSILE_DATA_DOWNLOADED,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_5_ROOM_2, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_SECTOR_5_ROOM_2, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_NAVIGATION_ROOM_LEAVING_ARC,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_1_ROOM_2, HATCH_RIGHT) |
            NAV_HATCH(NAV_ROOM_SECTOR_5_ROOM_2, HATCH_RIGHT) |
            NAV_HATCH(NAV_ROOM_SECTOR_2_ROOM_2, HATCH_RIGHT) |
            NAV_HATCH(NAV_ROOM_SECTOR_4_ROOM_2, HATCH_RIGHT) |
            NAV_HATCH(NAV_ROOM_SECTOR_3_ROOM_2, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_SECTOR_6_ROOM_2, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_COOLING_UNIT_OPERATIONAL,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_3_ROOM_2, HATCH_LEFT)
        )
    },
    {
        .event = EVENT_ANIMALS_RELEASED,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_16, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_9, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_NAVIGATION_ROOM_AFTER_ANIMALS,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_5_ROOM_2, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_SECTOR_5_ROOM_2, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_NAVIGATION_ROOM_ENTERING_ARC_2,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_5_ROOM_2, HATCH_LEFT)
        )
    },
    {
        .event = EVENT_POWER_BOMB_DATA_DOWNLOADED,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_5_ROOM_2, HATCH_LEFT)
        )
    },
    {
        .event = EVENT_ARC_SA_X_ENCOUNTER,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_5_ROOM_2, HATCH_LEFT)
        )
    },
    {
        .event = EVENT_ESCAPED_ARC_SA_X,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_5_ROOM_2, HATCH_LEFT)
        )
    },
    {
        .event = EVENT_NAVIGATION_ROOM_LEAVING_ARC_2,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_1_ROOM_2, HATCH_RIGHT) |
            NAV_HATCH(NAV_ROOM_SECTOR_5_ROOM_2, HATCH_RIGHT) |
            NAV_HATCH(NAV_ROOM_SECTOR_2_ROOM_2, HATCH_RIGHT) |
            NAV_HATCH(NAV_ROOM_SECTOR_4_ROOM_2, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_SECTOR_3_ROOM_2, HATCH_RIGHT) |
            NAV_HATCH(NAV_ROOM_SECTOR_6_ROOM_2, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_POWER_OUTAGE,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_16, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_56, HATCH_LEFT)
        )
    },
    {
        .event = EVENT_ENTERED_SHIP,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_16, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_56, HATCH_LEFT)
        )
    },
    {
        .event = EVENT_ENTERED_YAKUZA_ROOM,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_56, HATCH_LEFT)
        )
    },
    {
        .event = EVENT_SPACE_JUMP_ABILITY_RECOVERED,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_56, HATCH_LEFT)
        )
    },
    {
        .event = EVENT_AUXILARY_POWER_ENGAGED,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_56, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_56, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_NAVIGATION_ROOM_AFTER_YAKUZA,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_2_ROOM_2, HATCH_LEFT)
        )
    },
    {
        .event = EVENT_ENGAGED_TRO_2_SA_X,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_2_ROOM_2, HATCH_LEFT)
        )
    },
    {
        .event = EVENT_ESCAPED_TRO_2_SA_X,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_2_ROOM_2, HATCH_LEFT)
        )
    },
    {
        .event = EVENT_PLASMA_BEAM_ABILITY_RECOVERED,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_16, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_16, HATCH_RIGHT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_9, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_9, HATCH_RIGHT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_32, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_32, HATCH_RIGHT) |
            NAV_HATCH(NAV_ROOM_SECTOR_1_ROOM_2, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_SECTOR_1_ROOM_2, HATCH_RIGHT) |
            NAV_HATCH(NAV_ROOM_SECTOR_5_ROOM_2, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_SECTOR_5_ROOM_2, HATCH_RIGHT) |
            NAV_HATCH(NAV_ROOM_SECTOR_2_ROOM_2, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_SECTOR_2_ROOM_2, HATCH_RIGHT) |
            NAV_HATCH(NAV_ROOM_SECTOR_4_ROOM_2, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_SECTOR_4_ROOM_2, HATCH_RIGHT) |
            NAV_HATCH(NAV_ROOM_SECTOR_3_ROOM_2, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_SECTOR_3_ROOM_2, HATCH_RIGHT) |
            NAV_HATCH(NAV_ROOM_SECTOR_6_ROOM_2, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_SECTOR_6_ROOM_2, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_NAVIGATION_ROOM_LEAVING_TRO_2,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_5_ROOM_2, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_SECTOR_5_ROOM_2, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_NAVIGATION_ROOM_ENTERING_ARC_3,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_5_ROOM_2, HATCH_LEFT)
        )
    },
    {
        .event = EVENT_GRAVITY_SUIT_ABILITY_RECOVERED,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_5_ROOM_2, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_SECTOR_5_ROOM_2, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_ENTERED_LEVEL_4_SECURITY_ROOM,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_4_ROOM_2, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_SECURITY_LEVEL_4_UNLOCKED,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_4_ROOM_2, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_SECRET_MESSAGE_2,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_4_ROOM_2, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_ENTERED_DIFFUSION_MISSILE_DATA_ROOM,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_4_ROOM_2, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_DIFFUSION_MISSILE_DATA_DOWNLOADED,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_4_ROOM_2, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_SECTOR_4_ROOM_2, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_NAVIGATION_ROOM_LEAVING_AQA_2,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_6_ROOM_2, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_SECTOR_6_ROOM_2, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_NAVIGATION_ROOM_ENTERING_NOC_2,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_SECTOR_6_ROOM_2, HATCH_LEFT)
        )
    },
    {
        .event = EVENT_RESTRICTED_LABORATORY_EXPLOSION,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_66, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_66, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_60_SECONDS_TO_DETACHMENT,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_66, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_66, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_ESCAPED_RESTRICTED_LABORATORY,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_66, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_66, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_SCREW_ATTACK_ABILITY_RECOVERED,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_16, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_16, HATCH_RIGHT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_9, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_9, HATCH_RIGHT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_32, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_32, HATCH_RIGHT) |
            NAV_HATCH(NAV_ROOM_SECTOR_1_ROOM_2, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_SECTOR_1_ROOM_2, HATCH_RIGHT) |
            NAV_HATCH(NAV_ROOM_SECTOR_5_ROOM_2, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_SECTOR_5_ROOM_2, HATCH_RIGHT) |
            NAV_HATCH(NAV_ROOM_SECTOR_2_ROOM_2, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_SECTOR_2_ROOM_2, HATCH_RIGHT) |
            NAV_HATCH(NAV_ROOM_SECTOR_4_ROOM_2, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_SECTOR_4_ROOM_2, HATCH_RIGHT) |
            NAV_HATCH(NAV_ROOM_SECTOR_3_ROOM_2, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_SECTOR_3_ROOM_2, HATCH_RIGHT) |
            NAV_HATCH(NAV_ROOM_SECTOR_6_ROOM_2, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_SECTOR_6_ROOM_2, HATCH_RIGHT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_56, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_56, HATCH_RIGHT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_66, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_66, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_NAVIGATION_ROOM_LEAVING_SRX_2,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_16, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_16, HATCH_RIGHT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_9, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_9, HATCH_RIGHT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_32, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_32, HATCH_RIGHT) |
            NAV_HATCH(NAV_ROOM_SECTOR_1_ROOM_2, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_SECTOR_1_ROOM_2, HATCH_RIGHT) |
            NAV_HATCH(NAV_ROOM_SECTOR_5_ROOM_2, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_SECTOR_5_ROOM_2, HATCH_RIGHT) |
            NAV_HATCH(NAV_ROOM_SECTOR_2_ROOM_2, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_SECTOR_2_ROOM_2, HATCH_RIGHT) |
            NAV_HATCH(NAV_ROOM_SECTOR_4_ROOM_2, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_SECTOR_4_ROOM_2, HATCH_RIGHT) |
            NAV_HATCH(NAV_ROOM_SECTOR_3_ROOM_2, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_SECTOR_3_ROOM_2, HATCH_RIGHT) |
            NAV_HATCH(NAV_ROOM_SECTOR_6_ROOM_2, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_SECTOR_6_ROOM_2, HATCH_RIGHT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_56, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_56, HATCH_RIGHT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_66, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_66, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_END_OF_FIRST_CONVERSATION,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_16, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_16, HATCH_RIGHT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_9, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_9, HATCH_RIGHT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_32, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_32, HATCH_RIGHT) |
            NAV_HATCH(NAV_ROOM_SECTOR_1_ROOM_2, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_SECTOR_1_ROOM_2, HATCH_RIGHT) |
            NAV_HATCH(NAV_ROOM_SECTOR_5_ROOM_2, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_SECTOR_5_ROOM_2, HATCH_RIGHT) |
            NAV_HATCH(NAV_ROOM_SECTOR_2_ROOM_2, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_SECTOR_2_ROOM_2, HATCH_RIGHT) |
            NAV_HATCH(NAV_ROOM_SECTOR_4_ROOM_2, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_SECTOR_4_ROOM_2, HATCH_RIGHT) |
            NAV_HATCH(NAV_ROOM_SECTOR_3_ROOM_2, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_SECTOR_3_ROOM_2, HATCH_RIGHT) |
            NAV_HATCH(NAV_ROOM_SECTOR_6_ROOM_2, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_SECTOR_6_ROOM_2, HATCH_RIGHT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_56, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_56, HATCH_RIGHT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_66, HATCH_LEFT) |
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_66, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_ORBIT_CHANGE_IMPLEMENTED,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_9, HATCH_RIGHT)
        )
    },
    {
        .event = EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_7,
        NAV_HATCHES(
            NAV_HATCH(NAV_ROOM_MAIN_DECK_ROOM_9, HATCH_RIGHT)
        )
    }
};

#undef NAV_HATCHES
#undef NAV_HATCH
#undef HATCH_LEFT
#undef HATCH_RIGHT


const struct HatchLockEvent sHatchLockEvents[75] = {
    {
        .event = EVENT_NAVIGATION_ROOM_BEFORE_QUARANTINE_BAY,
        .area = AREA_MAIN_DECK,
        .room = 71 + 1,
        .hatch0 = TRUE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_NAVIGATION_ROOM_AFTER_MISSILES,
        .area = AREA_MAIN_DECK,
        .room = 38 + 1,
        .hatch0 = TRUE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_NAVIGATION_ROOM_ENTERING_SRX,
        .area = AREA_SECTOR_1,
        .room = 40 + 1,
        .hatch0 = TRUE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_LEFT_SA_X_QUAKE_ROOM,
        .area = AREA_SECTOR_2,
        .room = 18 + 1,
        .hatch0 = TRUE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_NAVIGATION_ROOM_ENTERING_AQA,
        .area = AREA_SECTOR_4,
        .room = 42 + 1,
        .hatch0 = TRUE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_TRIGGERED_BOX_RUMBLE,
        .area = AREA_SECTOR_3,
        .room = 23 + 1,
        .hatch0 = TRUE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_ESCAPED_NOC_SA_X,
        .area = AREA_SECTOR_6,
        .room = 25 + 1,
        .hatch0 = TRUE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_NOC_DATA_ROOM_DESTROYED,
        .area = AREA_SECTOR_6,
        .room = 13 + 1,
        .hatch0 = TRUE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_ENTERED_ICE_MISSILE_DATA_ROOM,
        .area = AREA_SECTOR_5,
        .room = 5 + 1,
        .hatch0 = FALSE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_ICE_MISSILE_DATA_DOWNLOADED,
        .area = AREA_SECTOR_5,
        .room = 0 + 1,
        .hatch0 = FALSE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_NAVIGATION_ROOM_LEAVING_ARC,
        .area = AREA_MAIN_DECK,
        .room = 29 + 1,
        .hatch0 = TRUE,
        .hatch1 = FALSE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_NAVIGATION_ROOM_LEAVING_ARC,
        .area = AREA_SECTOR_3,
        .room = 25 + 1,
        .hatch0 = TRUE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_WIDE_BEAM_ABILITY_RECOVERED,
        .area = AREA_SECTOR_3,
        .room = 25 + 1,
        .hatch0 = TRUE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_NAVIGATION_ROOM_ENTERING_ARC_2,
        .area = AREA_SECTOR_5,
        .room = 5 + 1,
        .hatch0 = FALSE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_ENTERED_YAKUZA_ROOM,
        .area = AREA_MAIN_DECK,
        .room = 86 + 1,
        .hatch0 = TRUE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_ESCAPED_TRO_2_SA_X,
        .area = AREA_SECTOR_2,
        .room = 22 + 1,
        .hatch0 = FALSE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_NAVIGATION_ROOM_ENTERING_ARC_3,
        .area = AREA_SECTOR_5,
        .room = 20 + 1,
        .hatch0 = TRUE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_NAVIGATION_ROOM_ENTERING_ARC_3,
        .area = AREA_SECTOR_5,
        .room = 34 + 1,
        .hatch0 = TRUE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_TRIGGERED_BOX_2_RUMBLE,
        .area = AREA_SECTOR_6,
        .room = 16 + 1,
        .hatch0 = TRUE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_RESTRICTED_LABORATORY_EXPLOSION,
        .area = AREA_MAIN_DECK,
        .room = 79 + 1,
        .hatch0 = FALSE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_RESTRICTED_LABORATORY_EXPLOSION,
        .area = AREA_MAIN_DECK,
        .room = 80 + 1,
        .hatch0 = TRUE,
        .hatch1 = FALSE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_RESTRICTED_LABORATORY_EXPLOSION,
        .area = AREA_MAIN_DECK,
        .room = 77 + 1,
        .hatch0 = TRUE,
        .hatch1 = FALSE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_NAVIGATION_ROOM_AFTER_RESTRICTED_LABORATORY,
        .area = AREA_SECTOR_1,
        .room = 27 + 1,
        .hatch0 = TRUE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_NAVIGATION_ROOM_AFTER_RESTRICTED_LABORATORY,
        .area = AREA_SECTOR_1,
        .room = 53 + 1,
        .hatch0 = TRUE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_SCREW_ATTACK_ABILITY_RECOVERED,
        .area = AREA_MAIN_DECK,
        .room = 6 + 1,
        .hatch0 = FALSE,
        .hatch1 = FALSE,
        .hatch2 = FALSE,
        .hatch3 = FALSE,
        .hatch4 = FALSE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_SECOND_CONVERSATION,
        .area = AREA_MAIN_DECK,
        .room = 6 + 1,
        .hatch0 = FALSE,
        .hatch1 = FALSE,
        .hatch2 = FALSE,
        .hatch3 = FALSE,
        .hatch4 = FALSE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_SECOND_CONVERSATION,
        .area = AREA_MAIN_DECK,
        .room = 18 + 1,
        .hatch0 = TRUE,
        .hatch1 = FALSE,
        .hatch2 = FALSE,
        .hatch3 = TRUE,
        .hatch4 = FALSE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_SECOND_CONVERSATION,
        .area = AREA_MAIN_DECK,
        .room = 38 + 1,
        .hatch0 = TRUE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_SECOND_CONVERSATION,
        .area = AREA_SECTOR_1,
        .room = 11 + 1,
        .hatch0 = TRUE,
        .hatch1 = FALSE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_SECOND_CONVERSATION,
        .area = AREA_SECTOR_2,
        .room = 37 + 1,
        .hatch0 = FALSE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_SECOND_CONVERSATION,
        .area = AREA_SECTOR_3,
        .room = 23 + 1,
        .hatch0 = TRUE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_SECOND_CONVERSATION,
        .area = AREA_SECTOR_3,
        .room = 26 + 1,
        .hatch0 = FALSE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_SECOND_CONVERSATION,
        .area = AREA_SECTOR_4,
        .room = 29 + 1,
        .hatch0 = FALSE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_SECOND_CONVERSATION,
        .area = AREA_SECTOR_5,
        .room = 32 + 1,
        .hatch0 = FALSE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_SECOND_CONVERSATION,
        .area = AREA_SECTOR_6,
        .room = 29 + 1,
        .hatch0 = TRUE,
        .hatch1 = FALSE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_6,
        .area = AREA_MAIN_DECK,
        .room = 6 + 1,
        .hatch0 = FALSE,
        .hatch1 = FALSE,
        .hatch2 = FALSE,
        .hatch3 = FALSE,
        .hatch4 = FALSE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_6,
        .area = AREA_MAIN_DECK,
        .room = 18 + 1,
        .hatch0 = TRUE,
        .hatch1 = FALSE,
        .hatch2 = FALSE,
        .hatch3 = TRUE,
        .hatch4 = FALSE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_6,
        .area = AREA_MAIN_DECK,
        .room = 38 + 1,
        .hatch0 = TRUE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_6,
        .area = AREA_SECTOR_1,
        .room = 11 + 1,
        .hatch0 = TRUE,
        .hatch1 = FALSE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_6,
        .area = AREA_SECTOR_2,
        .room = 37 + 1,
        .hatch0 = FALSE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_6,
        .area = AREA_SECTOR_3,
        .room = 23 + 1,
        .hatch0 = TRUE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_6,
        .area = AREA_SECTOR_3,
        .room = 26 + 1,
        .hatch0 = FALSE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_6,
        .area = AREA_SECTOR_4,
        .room = 29 + 1,
        .hatch0 = FALSE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_6,
        .area = AREA_SECTOR_5,
        .room = 32 + 1,
        .hatch0 = FALSE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_6,
        .area = AREA_SECTOR_6,
        .room = 29 + 1,
        .hatch0 = TRUE,
        .hatch1 = FALSE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_ENTERED_OPERATION_DECK,
        .area = AREA_MAIN_DECK,
        .room = 85 + 1,
        .hatch0 = TRUE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_SA_X_DEFEATED,
        .area = AREA_MAIN_DECK,
        .room = 61 + 1,
        .hatch0 = TRUE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_SA_X_DEFEATED,
        .area = AREA_MAIN_DECK,
        .room = 81 + 1,
        .hatch0 = FALSE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_ORBIT_CHANGE_IMPLEMENTED,
        .area = AREA_MAIN_DECK,
        .room = 4 + 1,
        .hatch0 = FALSE,
        .hatch1 = FALSE,
        .hatch2 = FALSE,
        .hatch3 = FALSE,
        .hatch4 = FALSE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_ORBIT_CHANGE_IMPLEMENTED,
        .area = AREA_MAIN_DECK,
        .room = 6 + 1,
        .hatch0 = TRUE,
        .hatch1 = FALSE,
        .hatch2 = FALSE,
        .hatch3 = FALSE,
        .hatch4 = TRUE,
        .hatch5 = FALSE,
    },
    {
        .event = EVENT_ORBIT_CHANGE_IMPLEMENTED,
        .area = AREA_MAIN_DECK,
        .room = 7 + 1,
        .hatch0 = FALSE,
        .hatch1 = FALSE,
        .hatch2 = FALSE,
        .hatch3 = FALSE,
        .hatch4 = FALSE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_ORBIT_CHANGE_IMPLEMENTED,
        .area = AREA_MAIN_DECK,
        .room = 12 + 1,
        .hatch0 = FALSE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_ORBIT_CHANGE_IMPLEMENTED,
        .area = AREA_MAIN_DECK,
        .room = 18 + 1,
        .hatch0 = TRUE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = FALSE,
    },
    {
        .event = EVENT_ORBIT_CHANGE_IMPLEMENTED,
        .area = AREA_MAIN_DECK,
        .room = 23 + 1,
        .hatch0 = TRUE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_ORBIT_CHANGE_IMPLEMENTED,
        .area = AREA_MAIN_DECK,
        .room = 21 + 1,
        .hatch0 = FALSE,
        .hatch1 = TRUE,
        .hatch2 = FALSE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_ORBIT_CHANGE_IMPLEMENTED,
        .area = AREA_MAIN_DECK,
        .room = 33 + 1,
        .hatch0 = FALSE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_ORBIT_CHANGE_IMPLEMENTED,
        .area = AREA_MAIN_DECK,
        .room = 38 + 1,
        .hatch0 = TRUE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_ORBIT_CHANGE_IMPLEMENTED,
        .area = AREA_MAIN_DECK,
        .room = 60 + 1,
        .hatch0 = TRUE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_ORBIT_CHANGE_IMPLEMENTED,
        .area = AREA_MAIN_DECK,
        .room = 63 + 1,
        .hatch0 = TRUE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_ORBIT_CHANGE_IMPLEMENTED,
        .area = AREA_MAIN_DECK,
        .room = 70 + 1,
        .hatch0 = FALSE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_ORBIT_CHANGE_IMPLEMENTED,
        .area = AREA_MAIN_DECK,
        .room = 85 + 1,
        .hatch0 = TRUE,
        .hatch1 = FALSE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_7,
        .area = AREA_MAIN_DECK,
        .room = 4 + 1,
        .hatch0 = FALSE,
        .hatch1 = FALSE,
        .hatch2 = FALSE,
        .hatch3 = FALSE,
        .hatch4 = FALSE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_7,
        .area = AREA_MAIN_DECK,
        .room = 6 + 1,
        .hatch0 = TRUE,
        .hatch1 = FALSE,
        .hatch2 = FALSE,
        .hatch3 = FALSE,
        .hatch4 = TRUE,
        .hatch5 = FALSE,
    },
    {
        .event = EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_7,
        .area = AREA_MAIN_DECK,
        .room = 7 + 1,
        .hatch0 = FALSE,
        .hatch1 = FALSE,
        .hatch2 = FALSE,
        .hatch3 = FALSE,
        .hatch4 = FALSE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_7,
        .area = AREA_MAIN_DECK,
        .room = 12 + 1,
        .hatch0 = FALSE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_7,
        .area = AREA_MAIN_DECK,
        .room = 18 + 1,
        .hatch0 = TRUE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = FALSE,
    },
    {
        .event = EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_7,
        .area = AREA_MAIN_DECK,
        .room = 21 + 1,
        .hatch0 = FALSE,
        .hatch1 = TRUE,
        .hatch2 = FALSE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_7,
        .area = AREA_MAIN_DECK,
        .room = 23 + 1,
        .hatch0 = TRUE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_7,
        .area = AREA_MAIN_DECK,
        .room = 33 + 1,
        .hatch0 = FALSE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_7,
        .area = AREA_MAIN_DECK,
        .room = 38 + 1,
        .hatch0 = TRUE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_7,
        .area = AREA_MAIN_DECK,
        .room = 60 + 1,
        .hatch0 = TRUE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_7,
        .area = AREA_MAIN_DECK,
        .room = 63 + 1,
        .hatch0 = TRUE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_7,
        .area = AREA_MAIN_DECK,
        .room = 70 + 1,
        .hatch0 = FALSE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_SKIPPED_BY_NOT_TALKING_TO_COMPUTER_7,
        .area = AREA_MAIN_DECK,
        .room = 70 + 1,
        .hatch0 = TRUE,
        .hatch1 = FALSE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    },
    {
        .event = EVENT_ENTERED_SHIP_ROOM,
        .area = AREA_MAIN_DECK,
        .room = 63 + 1,
        .hatch0 = TRUE,
        .hatch1 = TRUE,
        .hatch2 = TRUE,
        .hatch3 = TRUE,
        .hatch4 = TRUE,
        .hatch5 = TRUE,
    }
};

static const u8 sUnk_3c8b88[2] = {0xF0, 0xF0};

const struct EscapeDigits sEscapeDigits_9Minutes = {
    .hundredths = 0,
    .tenths = 0,
    .secondsOnes = 0,
    .secondsTens = 0,
    .minutesOnes = 9,
    .minutesTens = 0
};

const u8 sAreaConnections[36][AREA_CONNECTION_FIELD_COUNT] = {
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_MAIN_DECK,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 0x43,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_SECTOR_1,
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_MAIN_DECK,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 0x44,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_SECTOR_2,
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_MAIN_DECK,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 0x7F,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_SECTOR_2,
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_MAIN_DECK,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 0x9C,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_SECTOR_2,
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_MAIN_DECK,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 0x45,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_SECTOR_3,
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_MAIN_DECK,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 0x46,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_SECTOR_4,
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_MAIN_DECK,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 0x47,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_SECTOR_5,
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_MAIN_DECK,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 0x48,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_SECTOR_6,
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_MAIN_DECK,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 0x8F,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_SECTOR_6,
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_MAIN_DECK,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 0x9A,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_SECTOR_1,
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_1,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 0x00,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_MAIN_DECK,
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_1,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 0x41,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_MAIN_DECK,
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_1,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 0x68,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_SECTOR_2,
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_1,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 0x6B,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_SECTOR_3,
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_2,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 0x00,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_MAIN_DECK,
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_2,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 0x37,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_MAIN_DECK,
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_2,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 0x53,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_MAIN_DECK,
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_2,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 0x7F,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_SECTOR_1,
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_2,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 0x82,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_SECTOR_4,
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_3,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 0x00,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_MAIN_DECK,
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_3,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 0x56,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_SECTOR_1,
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_3,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 0x59,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_SECTOR_5,
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_4,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 0x00,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_MAIN_DECK,
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_4,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 0x4D,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_SECTOR_5,
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_4,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 0x6A,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_SECTOR_6,
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_4,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 0x6C,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_SECTOR_2,
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_5,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 0x00,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_MAIN_DECK,
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_5,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 0x7B,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_SECTOR_4,
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_5,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 0x02,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_SECTOR_6,
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_5,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 0x53,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_SECTOR_3,
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_6,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 0x00,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_MAIN_DECK,
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_6,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 0x2D,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_MAIN_DECK,
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_6,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 0x51,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_SECTOR_4,
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_6,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 0x54,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_SECTOR_5,
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = UCHAR_MAX,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = UCHAR_MAX,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = UCHAR_MAX,
    },
};

const struct ElevatorRoomPair sElevatorRoomPairs[ELEVATOR_END] = {
    [ELEVATOR_MAIN_DECK_TO_OPERATIONS_DECK] = {
        .area1 = AREA_MAIN_DECK,
        .room1 = 0x3C,
        .area2 = AREA_MAIN_DECK,
        .room2 = 0x3D
    },
    [ELEVATOR_MAIN_DECK_TO_LOBBY] = {
        .area1 = AREA_MAIN_DECK,
        .room1 = 0x13,
        .area2 = AREA_MAIN_DECK,
        .room2 = 0x18
    },
    [ELEVATOR_MAIN_DECK_TO_SECTOR_1] = {
        .area1 = AREA_MAIN_DECK,
        .room1 = 0x1C,
        .area2 = AREA_SECTOR_1,
        .room2 = 0x29
    },
    [ELEVATOR_MAIN_DECK_TO_SECTOR_2] = {
        .area1 = AREA_MAIN_DECK,
        .room1 = 0x19,
        .area2 = AREA_SECTOR_2,
        .room2 = 0x1D
    },
    [ELEVATOR_MAIN_DECK_TO_SECTOR_4] = {
        .area1 = AREA_MAIN_DECK,
        .room1 = 0x1A,
        .area2 = AREA_SECTOR_4,
        .room2 = 0x1B
    },
    [ELEVATOR_MAIN_DECK_TO_SECTOR_5] = {
        .area1 = AREA_MAIN_DECK,
        .room1 = 0x1E,
        .area2 = AREA_SECTOR_5,
        .room2 = 0x19
    },
    [ELEVATOR_MAIN_DECK_TO_SECTOR_6] = {
        .area1 = AREA_MAIN_DECK,
        .room1 = 0x1B,
        .area2 = AREA_SECTOR_6,
        .room2 = 0x11
    },
    [ELEVATOR_MAIN_DECK_TO_SECTOR_3] = {
        .area1 = AREA_MAIN_DECK,
        .room1 = 0x1D,
        .area2 = AREA_SECTOR_3,
        .room2 = 0x14
    },
    [ELEVATOR_MAIN_DECK_TO_LOBBY_POWER_OUTAGE] = {
        .area1 = AREA_MAIN_DECK,
        .room1 = 0x2B,
        .area2 = AREA_MAIN_DECK,
        .room2 = 0x18
    },
    [ELEVATOR_MAIN_DECK_TO_HABITATIONS_DECK] = {
        .area1 = AREA_MAIN_DECK,
        .room1 = 0x4B,
        .area2 = AREA_MAIN_DECK,
        .room2 = 0x4C
    },
    [ELEVATOR_RESTRICTED_ZONE_TO_SECTOR_1] = {
        .area1 = AREA_MAIN_DECK,
        .room1 = 0x43,
        .area2 = AREA_SECTOR_1,
        .room2 = 0x1F
    },
};

const struct ElevatorDisabledEvent sElevatorDisabledEvents[4] = {
    {
        .eventStart = EVENT_ENTERED_NAVIGATION_ROOM_POWER_OUTAGE,
        .eventEnd = EVENT_SA_X_ELEVATOR_CUTSCENE_ENDS,
        .disabledElevators = {
            [ELEVATOR_MAIN_DECK_TO_OPERATIONS_DECK] = TRUE,
            [ELEVATOR_MAIN_DECK_TO_LOBBY] = FALSE,
            [ELEVATOR_MAIN_DECK_TO_SECTOR_1] = FALSE,
            [ELEVATOR_MAIN_DECK_TO_SECTOR_2] = FALSE,
            [ELEVATOR_MAIN_DECK_TO_SECTOR_4] = FALSE,
            [ELEVATOR_MAIN_DECK_TO_SECTOR_5] = FALSE,
            [ELEVATOR_MAIN_DECK_TO_SECTOR_6] = FALSE,
            [ELEVATOR_MAIN_DECK_TO_SECTOR_3] = FALSE,
            [ELEVATOR_MAIN_DECK_TO_LOBBY_POWER_OUTAGE] = FALSE,
            [ELEVATOR_MAIN_DECK_TO_HABITATIONS_DECK] = FALSE,
            [ELEVATOR_RESTRICTED_ZONE_TO_SECTOR_1] = FALSE
        }
    },
    {
        .eventStart = EVENT_SA_X_ELEVATOR_CUTSCENE_ENDS,
        .eventEnd = EVENT_COOLING_UNIT_OPERATIONAL,
        .disabledElevators = {
            [ELEVATOR_MAIN_DECK_TO_OPERATIONS_DECK] = FALSE,
            [ELEVATOR_MAIN_DECK_TO_LOBBY] = TRUE,
            [ELEVATOR_MAIN_DECK_TO_SECTOR_1] = FALSE,
            [ELEVATOR_MAIN_DECK_TO_SECTOR_2] = FALSE,
            [ELEVATOR_MAIN_DECK_TO_SECTOR_4] = FALSE,
            [ELEVATOR_MAIN_DECK_TO_SECTOR_5] = FALSE,
            [ELEVATOR_MAIN_DECK_TO_SECTOR_6] = FALSE,
            [ELEVATOR_MAIN_DECK_TO_SECTOR_3] = FALSE,
            [ELEVATOR_MAIN_DECK_TO_LOBBY_POWER_OUTAGE] = FALSE,
            [ELEVATOR_MAIN_DECK_TO_HABITATIONS_DECK] = FALSE,
            [ELEVATOR_RESTRICTED_ZONE_TO_SECTOR_1] = FALSE
        }
    },
    {
        .eventStart = EVENT_NAVIGATION_ROOM_LEAVING_ARC,
        .eventEnd = EVENT_COOLING_UNIT_OPERATIONAL,
        .disabledElevators = {
            [ELEVATOR_MAIN_DECK_TO_OPERATIONS_DECK] = FALSE,
            [ELEVATOR_MAIN_DECK_TO_LOBBY] = FALSE,
            [ELEVATOR_MAIN_DECK_TO_SECTOR_1] = TRUE,
            [ELEVATOR_MAIN_DECK_TO_SECTOR_2] = TRUE,
            [ELEVATOR_MAIN_DECK_TO_SECTOR_4] = TRUE,
            [ELEVATOR_MAIN_DECK_TO_SECTOR_5] = FALSE,
            [ELEVATOR_MAIN_DECK_TO_SECTOR_6] = TRUE,
            [ELEVATOR_MAIN_DECK_TO_SECTOR_3] = FALSE,
            [ELEVATOR_MAIN_DECK_TO_LOBBY_POWER_OUTAGE] = FALSE,
            [ELEVATOR_MAIN_DECK_TO_HABITATIONS_DECK] = FALSE,
            [ELEVATOR_RESTRICTED_ZONE_TO_SECTOR_1] = FALSE
        }
    },
    {
        .eventStart = EVENT_POWER_OUTAGE,
        .eventEnd = EVENT_PLASMA_BEAM_ABILITY_RECOVERED,
        .disabledElevators = {
            [ELEVATOR_MAIN_DECK_TO_OPERATIONS_DECK] = TRUE,
            [ELEVATOR_MAIN_DECK_TO_LOBBY] = TRUE,
            [ELEVATOR_MAIN_DECK_TO_SECTOR_1] = TRUE,
            [ELEVATOR_MAIN_DECK_TO_SECTOR_2] = TRUE,
            [ELEVATOR_MAIN_DECK_TO_SECTOR_4] = TRUE,
            [ELEVATOR_MAIN_DECK_TO_SECTOR_5] = TRUE,
            [ELEVATOR_MAIN_DECK_TO_SECTOR_6] = TRUE,
            [ELEVATOR_MAIN_DECK_TO_SECTOR_3] = TRUE,
            [ELEVATOR_MAIN_DECK_TO_LOBBY_POWER_OUTAGE] = TRUE,
            [ELEVATOR_MAIN_DECK_TO_HABITATIONS_DECK] = FALSE,
            [ELEVATOR_RESTRICTED_ZONE_TO_SECTOR_1] = FALSE
        }
    },
};

const u8 sEventBasedConnections[60][EVENT_BASED_CONNECTION_FIELD_COUNT] = {
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_MAIN_DECK,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x14,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_ENTERED_NAVIGATION_ROOM_POWER_OUTAGE,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0xAC
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_MAIN_DECK,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x63,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_ENTERED_NAVIGATION_ROOM_POWER_OUTAGE,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0xAD
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_MAIN_DECK,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x4F,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_ENTERED_NAVIGATION_ROOM_POWER_OUTAGE,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0xAF
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_MAIN_DECK,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x8B,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_ENTERED_NAVIGATION_ROOM_POWER_OUTAGE,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0xAE
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_MAIN_DECK,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x4A,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_SA_X_ELEVATOR_CUTSCENE_ENDS,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x61
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_MAIN_DECK,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x14,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_SA_X_ELEVATOR_CUTSCENE_ENDS,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x1B
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_MAIN_DECK,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x63,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_SA_X_ELEVATOR_CUTSCENE_ENDS,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x41
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_MAIN_DECK,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x4F,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_SA_X_ELEVATOR_CUTSCENE_ENDS,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x16
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_MAIN_DECK,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x8B,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_SA_X_ELEVATOR_CUTSCENE_ENDS,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x8D
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_2,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x13,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_BOMB_DATA_DOWNLOADED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x45
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_2,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x02,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_BOMB_DATA_DOWNLOADED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x44
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_2,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x1B,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_HIGH_JUMP_ABILITY_RECOVERED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x68
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_2,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x23,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_HIGH_JUMP_ABILITY_RECOVERED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x69
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_2,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x2A,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_HIGH_JUMP_ABILITY_RECOVERED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x64
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_2,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x5F,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_HIGH_JUMP_ABILITY_RECOVERED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x6A
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_2,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x6E,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_HIGH_JUMP_ABILITY_RECOVERED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x70
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_3,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x0C,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_SUPER_MISSILE_DATA_DOWNLOADED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x2F
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_3,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x14,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_SUPER_MISSILE_DATA_DOWNLOADED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x30
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_3,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x24,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_SUPER_MISSILE_DATA_DOWNLOADED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x2D
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_3,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x2D,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_TRIGGERED_BOX_RUMBLE,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x2E
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_6,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x10,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_VARIA_SUIT_ABILITY_RECOVERED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x48
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_6,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x13,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_VARIA_SUIT_ABILITY_RECOVERED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x49
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_6,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x2F,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_VARIA_SUIT_ABILITY_RECOVERED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x4A
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_3,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x21,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_COOLING_UNIT_OPERATIONAL,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x48
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_3,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x32,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_COOLING_UNIT_OPERATIONAL,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x49
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_5,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x28,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_POWER_BOMB_DATA_DOWNLOADED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x6C
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_5,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x2D,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_POWER_BOMB_DATA_DOWNLOADED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x62
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_MAIN_DECK,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x32,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_NAVIGATION_ROOM_LEAVING_ARC_2,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x62
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_MAIN_DECK,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x32,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_POWER_OUTAGE,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x4C
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_MAIN_DECK,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x6F,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_PLASMA_BEAM_ABILITY_RECOVERED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x86
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_MAIN_DECK,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x72,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_PLASMA_BEAM_ABILITY_RECOVERED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x88
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_MAIN_DECK,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x77,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_PLASMA_BEAM_ABILITY_RECOVERED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x89
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_MAIN_DECK,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x85,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_PLASMA_BEAM_ABILITY_RECOVERED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x8A
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_2,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x31,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_PLASMA_BEAM_ABILITY_RECOVERED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x4E
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_2,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x34,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_PLASMA_BEAM_ABILITY_RECOVERED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x4D
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_2,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x46,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_PLASMA_BEAM_ABILITY_RECOVERED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x50
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_2,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x77,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_PLASMA_BEAM_ABILITY_RECOVERED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x79
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_2,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x74,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_PLASMA_BEAM_ABILITY_RECOVERED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x7A
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_2,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x8C,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_PLASMA_BEAM_ABILITY_RECOVERED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x8D
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_5,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x0A,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_NAVIGATION_ROOM_LEAVING_TRO_2,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x0C
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_5,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x24,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_NAVIGATION_ROOM_LEAVING_TRO_2,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x1C
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_5,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x15,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_NAVIGATION_ROOM_LEAVING_TRO_2,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x1D
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_5,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x37,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_NAVIGATION_ROOM_LEAVING_TRO_2,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x39
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_5,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x64,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_NAVIGATION_ROOM_LEAVING_TRO_2,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x46
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_5,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x17,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_NAVIGATION_ROOM_LEAVING_TRO_2,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x5E
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_5,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x30,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_NAVIGATION_ROOM_LEAVING_TRO_2,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x5F
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_5,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x55,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_NAVIGATION_ROOM_LEAVING_TRO_2,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x1F
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_5,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x56,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_NAVIGATION_ROOM_LEAVING_TRO_2,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x5C
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_5,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x03,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_NAVIGATION_ROOM_LEAVING_TRO_2,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x0B
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_5,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x4D,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_NAVIGATION_ROOM_LEAVING_TRO_2,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x50
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_SECTOR_5,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x2F,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_NAVIGATION_ROOM_LEAVING_TRO_2,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x60
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_MAIN_DECK,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0xBC,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_RESTRICTED_LABORATORY_EXPLOSION,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0xBE
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_MAIN_DECK,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x98,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_NAVIGATION_ROOM_AFTER_RESTRICTED_LABORATORY,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x20
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_MAIN_DECK,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x96,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_NAVIGATION_ROOM_AFTER_RESTRICTED_LABORATORY,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x22
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_MAIN_DECK,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0xC2,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_SECOND_CONVERSATION,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x92
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_MAIN_DECK,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x8B,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_SECOND_CONVERSATION,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0xCC
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_MAIN_DECK,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x0F,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_ORBIT_CHANGE_IMPLEMENTED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0xC5
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_MAIN_DECK,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x0D,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_ORBIT_CHANGE_IMPLEMENTED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0xC7
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_MAIN_DECK,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x86,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_ORBIT_CHANGE_IMPLEMENTED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0xC6
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_MAIN_DECK,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 0x08,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_ORBIT_CHANGE_IMPLEMENTED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 0x09
    },
};
