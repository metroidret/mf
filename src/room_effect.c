#include "room_effect.h"

#include "gba.h"
#include "globals.h"
#include "macros.h"

#include "data/common_pals.h"
#include "data/connection_data.h"
#include "data/event_data.h"
#include "data/rooms_data.h"
#include "data/samus_data.h"

#include "constants/audio.h"
#include "constants/event.h"
#include "constants/particle.h"
#include "constants/room.h"
#include "constants/samus.h"

#include "structs/animated_graphics.h"
#include "structs/clipdata.h"
#include "structs/connection.h"
#include "structs/display.h"
#include "structs/escape.h"
#include "structs/event.h"
#include "structs/menus/pause_debug.h"
#include "structs/power_bomb.h"
#include "structs/room.h"
#include "structs/samus.h"
#include "structs/screen_shake.h"
#include "structs/sprite.h"

/**
 * @brief 626f4 | 594 | Sets the room transparency and backgrounds effects
 *
 */
void RoomEffectSetTransparency(void)
{
    u32 coef;
    u16 dcnt;
    u16 bgCnt[4];
    s32 i;
    u8 evb;
    u8 eva;
    u16 dispcnt;

    if (gPauseScreenFlag != PAUSE_SCREEN_NONE)
    {
        if (gQueuedEventBasedEffect == EVENT_EFFECT_NONE)
        {
            coef = unk_62cb4();
            if (coef != 0)
            {
                dcnt = DCNT_BG0 | gIoRegisters.dispcnt;
                gIoRegisters.dispcnt = dcnt & coef;
            }
        }

        WRITE_16(REG_BG1CNT, gIoRegisters.bg1Cnt);
        WRITE_16(REG_BG2CNT, gIoRegisters.bg2Cnt);

        WRITE_8(REG_WINOUT, gIoRegisters.winout_L);
        WRITE_8(REG_WININ + 1, gIoRegisters.winin_H);

        WRITE_16(REG_WIN1H, C_16_2_8(gWindow1Border.left, gWindow1Border.right));
        WRITE_16(REG_WIN1V, C_16_2_8(gWindow1Border.top, gWindow1Border.bottom));

        WRITE_16(REG_BLDALPHA, C_16_2_8(gIoRegisters.bldalpha_evb, gIoRegisters.bldalpha_eva));
        return;
    }

    for (i = 0; i < 4; i++)
        bgCnt[i] = 0;

    gSamusOnTopOfBackgrounds = FALSE;

    if (gCurrentRoomEntry.bg0Prop & BG_PROP_LZ77_COMPRESSED)
        bgCnt[0] = RoomEffectGetBgSizeFlag(gCurrentRoomEntry.bg0Size) | (2 << BGCNT_CHAR_BASE_BLOCK_SHIFT);
    else
        bgCnt[0] = CREATE_BGCNT(1, 0, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_512x256);

    bgCnt[1] = CREATE_BGCNT(1, 2, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_512x256);
    bgCnt[2] = CREATE_BGCNT(1, 4, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_512x256);
    bgCnt[3] = CREATE_BGCNT(0, 6, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256);

    switch (gCurrentRoomEntry.bg3Prop)
    {
        case 0: // The value of this case doesn't matter
            bgCnt[3] |= 2 << BGCNT_CHAR_BASE_BLOCK_SHIFT;
            break;

        default:
            bgCnt[3] |= 2 << BGCNT_CHAR_BASE_BLOCK_SHIFT;
            break;
    }

    bgCnt[3] = RoomEffectGetBgSizeFlag(gCurrentRoomEntry.bg3Size) | bgCnt[3];

    switch (gCurrentRoomEntry.transparency)
    {
        case 0x0:
        case 0x1:
        case 0x2:
        case 0x3:
        case 0x4:
        case 0x8:
        case 0xC:
        case 0x10:
        case 0x14:
        case 0x18:
        case 0x1C:
        case 0x20:
        case 0x24:
        case 0x28:
        case 0x2C:
        case 0x30:
        default:
            bgCnt[0] |= BGCNT_HIGH_PRIORITY;
            bgCnt[1] |= BGCNT_HIGH_MID_PRIORITY;
            bgCnt[2] |= BGCNT_LOW_MID_PRIORITY;
            break;

        case 0x5:
        case 0x9:
        case 0xD:
        case 0x11:
        case 0x15:
        case 0x19:
        case 0x1D:
        case 0x21:
        case 0x25:
        case 0x29:
        case 0x2D:
        case 0x31:
            bgCnt[0] |= BGCNT_HIGH_MID_PRIORITY;
            bgCnt[1] |= BGCNT_HIGH_PRIORITY;
            bgCnt[2] |= BGCNT_LOW_MID_PRIORITY;
            break;

        case 0x6:
        case 0xA:
        case 0xE:
        case 0x12:
        case 0x16:
        case 0x1A:
        case 0x1E:
        case 0x22:
        case 0x26:
        case 0x2A:
        case 0x2E:
        case 0x32:
            bgCnt[0] |= BGCNT_HIGH_MID_PRIORITY;
            bgCnt[1] |= BGCNT_HIGH_PRIORITY;
            bgCnt[2] |= BGCNT_LOW_MID_PRIORITY;
            gSamusOnTopOfBackgrounds = TRUE;
            break;

        case 0x7:
        case 0xB:
        case 0xF:
        case 0x13:
        case 0x17:
        case 0x1B:
        case 0x1F:
        case 0x23:
        case 0x27:
        case 0x2B:
        case 0x2F:
        case 0x33:
            bgCnt[0] |= BGCNT_LOW_MID_PRIORITY;
            bgCnt[1] |= BGCNT_HIGH_PRIORITY;
            bgCnt[2] |= BGCNT_HIGH_MID_PRIORITY;
            gSamusOnTopOfBackgrounds = TRUE;
            break;
    }

    eva = 0;
    evb = 0;

    switch (gCurrentRoomEntry.transparency)
    {
        case 0x18:
        case 0x19:
        case 0x1A:
        case 0x1B:
            evb = 0;
            break;

        case 0x1C:
        case 0x1D:
        case 0x1E:
        case 0x1F:
            evb = 3;
            break;

        case 0x20:
        case 0x21:
        case 0x22:
        case 0x23:
            evb = 6;
            break;

        case 0x24:
        case 0x25:
        case 0x26:
        case 0x27:
            evb = 9;
            break;

        case 0x28:
        case 0x29:
        case 0x2A:
        case 0x2B:
            evb = 11;
            break;

        case 0x2C:
        case 0x2D:
        case 0x2E:
        case 0x2F:
            evb = 13;
            break;

        case 0x30:
        case 0x31:
        case 0x32:
        case 0x33:
            evb = 16;
            break;

        case 0x8:
        case 0x9:
        case 0xA:
        case 0xB:
            eva = 7;
            break;

        case 0xC:
        case 0xD:
        case 0xE:
        case 0xF:
            eva = 10;
            break;

        case 0x10:
        case 0x11:
        case 0x12:
        case 0x13:
            eva = 13;
            break;

        case 0x14:
        case 0x15:
        case 0x16:
        case 0x17:
            eva = 16;
            break;
    }

    if (eva == 0)
    {
        gIoRegisters.bldalpha_evb = evb;
        gIoRegisters.bldalpha_eva = 16 - gIoRegisters.bldalpha_evb;

        gDefaultTransparency.unk_0 = 0;
    }
    else
    {
        gIoRegisters.bldalpha_evb = 16;
        gIoRegisters.bldalpha_eva = eva;

        gDefaultTransparency.unk_0 = 1;
    }

    gDefaultTransparency.evbCoef = gIoRegisters.bldalpha_evb;
    gDefaultTransparency.evaCoef = gIoRegisters.bldalpha_eva;

    WRITE_16(REG_BLDALPHA, C_16_2_8(gIoRegisters.bldalpha_evb, gIoRegisters.bldalpha_eva));

    gWrittenToBldalpha = 0;
    gUnk_3004e44.unk_0 = 0;
    gUnk_3004e44.unk_1 = 0;

    if (gCurrentRoomEntry.bg0Prop == BG_PROP_DISABLE_TRANSPARENCY)
        gUnk_3004e44.unk_0 = 1;

    if (gColorFading == 0xD)
    {
        gWindow1Border.left = DIV_SHIFT(gSamusData.xPosition - gBg1XPosition, 4);
        if (gWindow1Border.left > SCREEN_SIZE_X)
        {
            if (gSamusData.xPosition < gBg1XPosition)
                gWindow1Border.left = 0;
            else
                gWindow1Border.left = SCREEN_SIZE_X;
        }

        gWindow1Border.top = DIV_SHIFT(gSamusData.yPosition - (BLOCK_SIZE - 1) - gBg1YPosition, 4);
        if (gWindow1Border.top > SCREEN_SIZE_Y)
        {
            if (gSamusData.yPosition - (BLOCK_SIZE - 1) < gBg1YPosition)
                gWindow1Border.top = 0;
            else
                gWindow1Border.top = SCREEN_SIZE_Y;
        }

        gWindow1Border.right = gWindow1Border.left;
        gWindow1Border.bottom = gWindow1Border.top;
        gWindow1Border.timer = 0;
    }
    else
    {
        gWindow1Border.left = 0;
        gWindow1Border.right = SCREEN_SIZE_X;
        gWindow1Border.top = 0;
        gWindow1Border.bottom = SCREEN_SIZE_Y;
        gWindow1Border.timer = 0;
    }

    WRITE_8(REG_WININ, 0);
    WRITE_16(REG_WIN0H, 0);
    WRITE_16(REG_WIN0V, 0);

    gIoRegisters.winin_H = 0x3F;
    gIoRegisters.winout_L = 0x20;

    WRITE_8(REG_WINOUT, 0x20);
    WRITE_8(REG_WININ + 1, 0x3F);

    WRITE_16(REG_WIN1H, C_16_2_8(gWindow1Border.left, gWindow1Border.right));
    WRITE_16(REG_WIN1V, C_16_2_8(gWindow1Border.top, gWindow1Border.bottom));

    WRITE_16(REG_BG1CNT, bgCnt[1]);
    WRITE_16(REG_BG2CNT, bgCnt[2]);

    gIoRegisters.bg0Cnt = bgCnt[0];
    gIoRegisters.unk_10 = bgCnt[0];
    gIoRegisters.bg1Cnt = bgCnt[1];
    gIoRegisters.bg2Cnt = bgCnt[2];
    gIoRegisters.bg3Cnt = bgCnt[3];

    if (gCurrentRoomEntry.transparency < 8)
    {
        gIoRegisters.bldcnt = BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_SCREEN_SECOND_TARGET;
    }
    else
    {
        gIoRegisters.bldcnt =
            BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_SCREEN_SECOND_TARGET;
        gIoRegisters.bldcnt &= ~BLDCNT_BG0_SECOND_TARGET_PIXEL;
    }

    if (gCurrentRoomEntry.visualEffect == 0x9)
        gIoRegisters.bldcnt |= BLDCNT_BG3_FIRST_TARGET_PIXEL;
    else if (gCurrentRoomEntry.visualEffect == 0xa)
        gIoRegisters.bldcnt |= BLDCNT_BG2_FIRST_TARGET_PIXEL;

    if (gCurrentRoomEntry.bg0Prop == BG_PROP_14)
        gIoRegisters.bldcnt &= ~BLDCNT_BG0_FIRST_TARGET_PIXEL;

    dispcnt = DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3 | DCNT_OBJ | DCNT_WIN1;
    coef = unk_62cb4();
    if (coef)
        dispcnt &= coef;

    gIoRegisters.dispcnt = dispcnt;

    if (gDebugFlag)
    {
        if (gPauseDebugOptions.bld.whole.alpha != 0)
        {
            gIoRegisters.bldalpha_eva = gPauseDebugOptions.bld.split.alpha_eva;
            gIoRegisters.bldalpha_evb = gPauseDebugOptions.bld.split.alpha_evb;
            WRITE_16(REG_BLDALPHA, C_16_2_8(gIoRegisters.bldalpha_evb, gIoRegisters.bldalpha_eva));
        }

        if (gPauseDebugOptions.bld.whole.cnt != 0)
            gIoRegisters.bldcnt = gPauseDebugOptions.bld.whole.cnt;
    }
}

/**
 * @brief 62c88 | 2c | Gets the size of a background based on its property
 *
 * @param bgProp Background property
 * @return u16 Shifted background size
 */
u32 RoomEffectGetBgSizeFlag(u8 bgProp)
{
    u32 flag;

    flag = BGCNT_SIZE_256x256 << BGCNT_SCREEN_SIZE_SHIFT;

    switch (bgProp)
    {
        case BGCNT_SIZE_256x256:
            flag = BGCNT_SIZE_256x256 << BGCNT_SCREEN_SIZE_SHIFT;
            break;

        case BGCNT_SIZE_512x256:
        default:
            flag = BGCNT_SIZE_512x256 << BGCNT_SCREEN_SIZE_SHIFT;
            break;

        case BGCNT_SIZE_256x512:
            flag = BGCNT_SIZE_256x512 << BGCNT_SCREEN_SIZE_SHIFT;
            break;
    }

    return flag;
}

/**
 * @brief 62cb4 | 44 | To document
 *
 * @return u32
 */
u32 unk_62cb4(void)
{
    u32 dispcnt;

    dispcnt = 0;

    if (gCurrentRoomEntry.bg0Prop == BG_PROP_DISABLE_TRANSPARENCY)
        dispcnt = (RoomEffectCheckRoomIsDim() << 8) | (u16)~DCNT_BG0;
    else if (gCurrentRoomEntry.bg0Prop == BG_PROP_13)
        dispcnt = (RoomEffectCheckMainElevatorIsActive() << 8) | (u16)~DCNT_BG0;
    else if (gCurrentRoomEntry.bg0Prop == BG_PROP_MELTDOWN)
        dispcnt = (RoomEffectCheckSetMeltdownEffect() << 8) | (u16)~DCNT_BG0;
    else if (gCurrentRoomEntry.bg0Prop == BG_PROP_DIM_ROOM)
        dispcnt = (RoomEffectCheckRoomIsDark() << 8) | (u16)~DCNT_BG0;

    return dispcnt;
}

/**
 * @brief 62cf8 | 70 | Checks if the room should be dim
 *
 * @return s32 bool, room is dim
 */
bools32 RoomEffectCheckRoomIsDim(void)
{
    s32 size;
    bools32 makeDim;
    s32 i;

    if (gEventCounter == EVENT_ENTERED_NAVIGATION_ROOM_POWER_OUTAGE && gCurrentRoom == 32)
    {
        gQueuedEventBasedEffect = EVENT_EFFECT_POWER_OUTAGE_MISSILES;
        return TRUE;
    }

    size = ARRAY_SIZE(sDimLightingEvents);
    makeDim = sDimLightingEvents[size - 1][DIM_EVENT_FIELD_FLAG];

    for (i = 0; i < size; i++)
    {
        if (gEventCounter < sDimLightingEvents[i][DIM_EVENT_FIELD_EVENT])
        {
            makeDim = 1 ^ sDimLightingEvents[i][DIM_EVENT_FIELD_FLAG];
            break;
        }
    }

    return makeDim;
}

/**
 * @brief 62d68 | 48 | Checks if the main elevator is active
 *
 * @return s32 bool, elevator is active
 */
bools32 RoomEffectCheckMainElevatorIsActive(void)
{
    bools32 active;

    active = TRUE;

    if (gEventCounter >= EVENT_SA_X_ELEVATOR_CUTSCENE_ENDS && gEventCounter < EVENT_NAVIGATION_ROOM_LEAVING_PYR_2)
    {
        active = FALSE;

        if (gEventCounter == EVENT_SA_X_ELEVATOR_CUTSCENE_ENDS && gSamusData.pose == SPOSE_USING_ELEVATOR &&
            gLastElevatorUsed == ELEVATOR_MAIN_DECK_TO_LOBBY)
        {
            gQueuedEventBasedEffect = EVENT_EFFECT_SA_X_ELEVATOR_POWER;
            active = TRUE;
        }
    }

    return active;
}

/**
 * @brief 62db0 | 28 | Checks if the meltdown effect should be set
 *
 * @return s32 bool, meltdown effect should be set
 */
bools32 RoomEffectCheckSetMeltdownEffect(void)
{
    bools32 setEffect;

    setEffect = FALSE;

    if (gEventCounter >= EVENT_ICE_MISSILE_DATA_DOWNLOADED && gEventCounter < EVENT_COOLING_UNIT_OPERATIONAL)
    {
        setEffect = TRUE;
        gQueuedEventBasedEffect = EVENT_EFFECT_MELTDOWN;
    }

    return setEffect;
}

/**
 * @brief 62dd8 | 18 | Checks if the room should be dark
 *
 * @return s32 bool, room should be dark
 */
bools32 RoomEffectCheckRoomIsDark(void)
{
    return gEventCounter <= EVENT_SA_X_ELEVATOR_CUTSCENE_ENDS;
}

/**
 * @brief 62df0 | 218 | To document
 *
 * @return s32 bool
 */
bools32 RoomEffectFade(u8 arg0)
{
    // TODO: Remove goto statements

    bools32 result;
    s32 tmp;
    u8 eva;
    struct IoRegisters *pIR;
    struct DefaultTransparency *pDT;


    result = 0;

    if (gWrittenToBldalpha != 0 || gCurrentPowerBomb.animationState != 0)
        return 0;

    switch (arg0)
    {
        case 5:
            result = 1;

            if (gDefaultTransparency.evbCoef != gIoRegisters.bldalpha_evb)
            {
                if (gDefaultTransparency.evbCoef < gIoRegisters.bldalpha_evb)
                    gIoRegisters.bldalpha_evb--;
                else
                    gIoRegisters.bldalpha_evb++;

                result = 0;
            }

            if (gDefaultTransparency.evaCoef != gIoRegisters.bldalpha_eva)
            {
                if (gDefaultTransparency.evaCoef < gIoRegisters.bldalpha_eva)
                    gIoRegisters.bldalpha_eva--;
                else
                    gIoRegisters.bldalpha_eva++;

                result = 0;
            }

            gWrittenToBldalpha = C_16_2_8(gIoRegisters.bldalpha_evb, gIoRegisters.bldalpha_eva);
            break;

        case 4:
            if (gIoRegisters.bldalpha_evb <= 0xF)
            {
                gIoRegisters.bldalpha_evb++;
                goto block_21;
            }

            if (gIoRegisters.bldalpha_eva != 0)
            {
                gIoRegisters.bldalpha_evb = 0x10;
            block_21:
                if (gIoRegisters.bldalpha_eva != 0)
                    gIoRegisters.bldalpha_eva--;
                else
                    gIoRegisters.bldalpha_eva = 0;

                gWrittenToBldalpha = C_16_2_8(gIoRegisters.bldalpha_evb, gIoRegisters.bldalpha_eva);
                break;
            }

            result = 1;
            break;

        case 1:
            if (gIoRegisters.bldalpha_evb > 2)
            {
                gIoRegisters.bldalpha_evb -= 2;
                gIoRegisters.bldalpha_eva = 0x10 - gIoRegisters.bldalpha_evb;
                gWrittenToBldalpha = C_16_2_8(gIoRegisters.bldalpha_evb, gIoRegisters.bldalpha_eva);
            }

            break;

        case 2:
            if (gIoRegisters.bldalpha_evb <= 0xF)
            {
                gIoRegisters.bldalpha_evb++;
                gIoRegisters.bldalpha_eva = 0x10 - gIoRegisters.bldalpha_evb;
                gWrittenToBldalpha = C_16_2_8(gIoRegisters.bldalpha_evb, gIoRegisters.bldalpha_eva);
                break;
            }

            result = 1;
            break;

        case 3:
            if (gIoRegisters.bldalpha_evb <= 0xF)
            {
                gIoRegisters.bldalpha_evb++;
                goto block_34;
            }

            if (gIoRegisters.bldalpha_eva != 0)
            {
                gIoRegisters.bldalpha_evb = 0x10;
            block_34:
                if (gIoRegisters.bldalpha_eva != 0)
                    gIoRegisters.bldalpha_eva--;
                else
                    gIoRegisters.bldalpha_eva = 0;

                gWrittenToBldalpha = C_16_2_8(gIoRegisters.bldalpha_evb, gIoRegisters.bldalpha_eva);
                break;
            }

            result = 1;
            break;

        case 6:
            result = 1;

            if (gDefaultTransparency.evbCoef != gIoRegisters.bldalpha_evb)
            {
                if (gDefaultTransparency.evbCoef < gIoRegisters.bldalpha_evb)
                    gIoRegisters.bldalpha_evb--;
                else
                    gIoRegisters.bldalpha_evb++;

                result = 0;
            }

            if (gDefaultTransparency.evaCoef != gIoRegisters.bldalpha_eva)
            {
                if (gDefaultTransparency.evaCoef < gIoRegisters.bldalpha_eva)
                    gIoRegisters.bldalpha_eva--;
                else
                    gIoRegisters.bldalpha_eva++;

                result = 0;
            }

            gWrittenToBldalpha = C_16_2_8(gIoRegisters.bldalpha_evb, gIoRegisters.bldalpha_eva);
            break;

        case 7:
            if (gUnk_3004e42 != 0)
            {
                pIR = &gIoRegisters;
                pDT = &gDefaultTransparency;
                eva = pIR->bldalpha_eva;

                if (eva >= pDT->evaCoef)
                    break;

                tmp = eva + 1;
            }
            else
            {
                eva = gIoRegisters.bldalpha_eva;

                if (eva == 0)
                    break;

                tmp = eva - 1;
            }

            gIoRegisters.bldalpha_eva = tmp;
            gWrittenToBldalpha = C_16_2_8(gIoRegisters.bldalpha_evb, gIoRegisters.bldalpha_eva);

            break;
    }

    return result;
}

/**
 * @brief 63008 | 68 | To document
 *
 * @param hatch Hatch to lock
 * @param arg1 To document
 * @param newState New state for the hatch
 */
void RoomEffectStartHatchLockAnimation(u8 hatch, u8 arg1, u8 newState)
{
    u8 state;

    state = arg1 == 2 ? HATCH_STATE_1 : HATCH_STATE_3;

    gHatchData[hatch].state = state;
    gHatchData[hatch].currentAnimation = 4; // TODO: Enum

    UpdateHatchAnimation(hatch);

    gHatchData[hatch].state = newState;
    gHatchData[hatch].currentAnimation = 0; // TODO: Enum
}

/**
 * @brief 63070 | 90 | Locks the provided hatches
 *
 * @param hatchesToLock Bit flags of hatches to lock
 */
void RoomEffectLockHatches(u8 hatchesToLock)
{
    s32 i;

    gLockedHatches = 0;

    for (i = 0; i < MAX_AMOUNT_OF_HATCHES; i++)
    {
        if (gHatchData[i].exists && (hatchesToLock >> i) & 1)
        {
            gLockedHatches |= 1 << i;
            gHatchData[i].locked = TRUE;
            gHatchData[i].lockType = HATCH_LOCK_CAN_LOCK;

            if (gHatchDoorIds[i] != gLastDoorUsed)
                RoomEffectStartHatchLockAnimation(i, 0, HATCH_STATE_0);
            else
                RoomEffectStartHatchLockAnimation(i, 2, HATCH_STATE_3);
        }
    }
}

// TODO: Determine why this is the same as above
/**
 * @brief 63100 | 90 | Locks the provided hatches
 *
 * @param hatchesToLock Bit flags of hatches to lock
 */
void RoomEffectLockHatchesWithTimer(u8 hatchesToLock)
{
    s32 i;

    gLockedHatches = 0;

    for (i = 0; i < MAX_AMOUNT_OF_HATCHES; i++)
    {
        if (gHatchData[i].exists && (hatchesToLock >> i) & 1)
        {
            gLockedHatches |= 1 << i;
            gHatchData[i].locked = TRUE;
            gHatchData[i].lockType = HATCH_LOCK_CAN_LOCK;

            if (gHatchDoorIds[i] != gLastDoorUsed)
                RoomEffectStartHatchLockAnimation(i, 0, HATCH_STATE_0);
            else
                RoomEffectStartHatchLockAnimation(i, 2, HATCH_STATE_3);
        }
    }
}

/**
 * @brief 63190 | 40 | Initializes the recovering suit effect
 *
 */
void RoomEffectRecoveringSuitInit(void)
{
    bools32 flag;

    flag = FALSE;
    if (gCurrentEventBasedEffect != (0x80 | EVENT_EFFECT_NIGHTMARE_ROOM))
    {
        if (gCurrentEventBasedEffect == 0)
            flag = TRUE;

        if (flag == FALSE)
            return;
    }

    gCurrentEventBasedEffect = EVENT_EFFECT_RECOVERING_SUIT;
    gQueuedEventBasedEffect = EVENT_EFFECT_RECOVERING_SUIT;
    gEventBasedEffectInfo.stage = 0;
    gEventBasedEffectInfo.timer = 0;
    gDisablePauseFlag = TRUE;
}

/**
 * @brief 631d0 | 60 | Sets the current navigation room
 *
 * @param room Room ID
 */
void RoomEffectSetCurrentNavigationRoom(u8 room)
{
    gCurrentNavigationRoom = NAV_ROOM_MAIN_DECK_ROOM_0;

    while (TRUE)
    {
        if (sNavigationRoomLocations[gCurrentNavigationRoom][0] == UCHAR_MAX)
        {
            gCurrentNavigationRoom = NAV_ROOM_NONE;
            break;
        }

        if (gCurrentArea == sNavigationRoomLocations[gCurrentNavigationRoom][0] &&
            room == sNavigationRoomLocations[gCurrentNavigationRoom][1] - 1)
        {
            break;
        }

        gCurrentNavigationRoom++;
    }
}

/**
 * @brief 63230 | 1cc | Determines if any navigation room hatches should be locked
 *
 * @return s32 bool, true if not in a navigation room
 */
bools32 RoomEffectDetermineNavigationRoomHatchesToLock(void)
{
    bools32 leftHatch;
    bools32 rightHatch;
    s32 i;
    bools32 hatch;

    if (gCurrentNavigationRoom == 0)
        return TRUE;

    DMA3_COPY_16(sCommonTilesPal + 3 * PAL_ROW_SIZE, PALRAM_BASE + 2 * PAL_ROW_SIZE, PAL_ROW);

    leftHatch = FALSE;
    rightHatch = FALSE;

    for (i = 0; i < (u32)ARRAY_SIZE(sNavigationRoomHatchLockEvents); i++)
    {
        if (gEventCounter == sNavigationRoomHatchLockEvents[i].event)
        {
            if (gCurrentNavigationRoom == NAV_ROOM_MAIN_DECK_ROOM_16)
            {
                leftHatch = sNavigationRoomHatchLockEvents[i].room1LeftHatch;
                rightHatch = sNavigationRoomHatchLockEvents[i].room1RightHatch;
            }
            else if (gCurrentNavigationRoom == NAV_ROOM_MAIN_DECK_ROOM_9)
            {
                leftHatch = sNavigationRoomHatchLockEvents[i].room2LeftHatch;
                rightHatch = sNavigationRoomHatchLockEvents[i].room2RightHatch;
            }
            else if (gCurrentNavigationRoom == NAV_ROOM_MAIN_DECK_ROOM_32)
            {
                leftHatch = sNavigationRoomHatchLockEvents[i].room3LeftHatch;
                rightHatch = sNavigationRoomHatchLockEvents[i].room3RightHatch;
            }
            else if (gCurrentNavigationRoom == NAV_ROOM_SECTOR_1_ROOM_2)
            {
                leftHatch = sNavigationRoomHatchLockEvents[i].room4LeftHatch;
                rightHatch = sNavigationRoomHatchLockEvents[i].room4RightHatch;
            }
            else if (gCurrentNavigationRoom == NAV_ROOM_SECTOR_5_ROOM_2)
            {
                leftHatch = sNavigationRoomHatchLockEvents[i].room5LeftHatch;
                rightHatch = sNavigationRoomHatchLockEvents[i].room5RightHatch;
            }
            else if (gCurrentNavigationRoom == NAV_ROOM_SECTOR_2_ROOM_2)
            {
                leftHatch = sNavigationRoomHatchLockEvents[i].room6LeftHatch;
                rightHatch = sNavigationRoomHatchLockEvents[i].room6RightHatch;
            }
            else if (gCurrentNavigationRoom == NAV_ROOM_SECTOR_4_ROOM_2)
            {
                leftHatch = sNavigationRoomHatchLockEvents[i].room7LeftHatch;
                rightHatch = sNavigationRoomHatchLockEvents[i].room7RightHatch;
            }
            else if (gCurrentNavigationRoom == NAV_ROOM_SECTOR_3_ROOM_2)
            {
                leftHatch = sNavigationRoomHatchLockEvents[i].room8LeftHatch;
                rightHatch = sNavigationRoomHatchLockEvents[i].room8RightHatch;
            }
            else if (gCurrentNavigationRoom == NAV_ROOM_SECTOR_6_ROOM_2)
            {
                leftHatch = sNavigationRoomHatchLockEvents[i].room9LeftHatch;
                rightHatch = sNavigationRoomHatchLockEvents[i].room9RightHatch;
            }
            else if (gCurrentNavigationRoom == NAV_ROOM_MAIN_DECK_ROOM_56)
            {
                leftHatch = sNavigationRoomHatchLockEvents[i].room10LeftHatch;
                rightHatch = sNavigationRoomHatchLockEvents[i].room10RightHatch;
            }
            else if (gCurrentNavigationRoom == NAV_ROOM_MAIN_DECK_ROOM_66)
            {
                leftHatch = sNavigationRoomHatchLockEvents[i].room11LeftHatch;
                rightHatch = sNavigationRoomHatchLockEvents[i].room11RightHatch;
            }

            break;
        }
    }

    if (leftHatch || rightHatch || gPauseScreenFlag != PAUSE_SCREEN_NONE)
    {
        gLockedHatches = 0;

        for (i = 0; i < MAX_AMOUNT_OF_HATCHES; i++)
        {
            if (gHatchData[i].exists)
            {
                hatch = gHatchData[i].facingRight ? leftHatch : rightHatch;

                if (gPauseScreenFlag != 0)
                {
                    if (gHatchData[i].locked && hatch == 0)
                    {
                        gLockedHatches |= 1 << i;
                        gDoorUnlockTimer = 1;
                    }
                }
                else if (hatch)
                {
                    gLockedHatches |= 1 << i;
                    gHatchData[i].locked = TRUE;

                    if (gHatchDoorIds[i] != gLastDoorUsed)
                    {
                        RoomEffectStartHatchLockAnimation(i, 0, HATCH_STATE_0);
                    }
                    else
                    {
                        gHatchData[i].state = HATCH_STATE_3;
                        gHatchData[i].currentAnimation = 0;
                    }
                }
            }
        }
    }

    return FALSE;
}

/**
 * @brief 633fc | 30 | Checks if the current event based effect should be set
 *
 */
void RoomEffectCheckSetCurrentEventBased(void)
{
    s8 pauseFlag;

    pauseFlag = gPauseScreenFlag;

    if (pauseFlag == PAUSE_SCREEN_NONE)
    {
        gEventBasedEffectInfo.stage = pauseFlag;

        if (gQueuedEventBasedEffect != EVENT_EFFECT_NONE &&
            gQueuedEventBasedEffect != EVENT_EFFECT_SECTOR_1_NON_STABILIZER)
        {
            RoomEffectSetCurrentEventBased(gQueuedEventBasedEffect);
        }
    }
}

/**
 * @brief 6342c | 18 | Sets the current event based effect
 *
 * @param effect Event based effect to set
 */
void RoomEffectSetCurrentEventBased(u8 effect)
{
    if (gCurrentEventBasedEffect != effect)
        gCurrentEventBasedEffect = effect;
}

/**
 * @brief 63444 | 248 | Initializes the current event based effect
 *
 */
void RoomEffectSetupCurrentEventBased(void)
{
    if (RoomEffectDetermineNavigationRoomHatchesToLock() && gPauseScreenFlag == PAUSE_SCREEN_NONE)
        RoomEffectCheckHatchLockEvents();

    if (gPauseScreenFlag != PAUSE_SCREEN_NONE)
    {
        if (gAnimatedPaletteAndTileset.animatedPalette != 0)
        {
            DMA3_COPY_16(&gBackgroundPalette + 15 * PAL_ROW_SIZE, PALRAM_BASE + 15 * PAL_ROW_SIZE, PAL_ROW);
        }
        else if (gQueuedEventBasedEffect == EVENT_EFFECT_OMEGA_METROID_ROOM)
        {
            DMA3_COPY_16(&gBackgroundPalette + 4 * PAL_ROW_SIZE, PALRAM_BASE + 4 * PAL_ROW_SIZE, PAL_ROW);
        }

        return;
    }

    gEventBasedEffectInfo.stage = 0;
    gEventBasedEffectInfo.timer = 0;

    switch (gQueuedEventBasedEffect)
    {
        case EVENT_EFFECT_ATMOSPHERIC_STABILIZER:
            if (!AtmosphericStabilizerCheckIsInfected())
            {
                HazeSetupCode(0);
                gIoRegisters.dispcnt &= ~DCNT_BG0;
                gAnimatedPaletteAndTileset.animatedPalette = 0;
                gCurrentEventBasedEffect = EVENT_EFFECT_NONE;
                gDoorUnlockTimer = 1;
            }
            else
            {
                RoomEffectLockHatches((1 << 8) - 1);
            }
            break;

        case EVENT_EFFECT_MELTDOWN:
            if (gCurrentRoomEntry.tilesetNumber == 0x52)
                SoundPlay(SOUND_11F);
            break;

        case EVENT_EFFECT_SA_X_ELEVATOR_EXPLOSION:
            unk_6cf0c();
            break;

        case EVENT_EFFECT_POWER_OUTAGE_MISSILES:
            gUnk_3004e44.unk_0 &= -0x10;

        case EVENT_EFFECT_POWER_OUTAGE_YAKUZA:
            gIoRegisters.bldalpha_evb = 0x10;
            gIoRegisters.bldalpha_eva = 0;
            WRITE_16(REG_BLDALPHA, C_16_2_8(gIoRegisters.bldalpha_evb, gIoRegisters.bldalpha_eva));
            gWrittenToBldalpha = 0;
            break;

        case EVENT_EFFECT_MAIN_BOILER_ROOM:
            SoundPlay(SOUND_120);
            gCurrentEventBasedEffect = 0;
            break;

        case EVENT_EFFECT_BOX2_ROOM:
            if (gEventCounter == EVENT_TRIGGERED_BOX_2_RUMBLE)
                break;

        case EVENT_EFFECT_SECTOR_1_NON_STABILIZER:
        case EVENT_EFFECT_AUX_POWER_INACTIVE:
            gAnimatedPaletteAndTileset.animatedPalette = 0;
            break;

        case EVENT_EFFECT_REACTOR_CORE_ACTIVE:
            SoundPlay(SOUND_126);
            break;

        case EVENT_EFFECT_RESTRICTED_LAB:
            SoundPlay(SOUND_12C);
            gCurrentEventBasedEffect = 0;
            break;

        case EVENT_EFFECT_YAKUZA_ROOM:
            if (gEventCounter >= EVENT_SPACE_JUMP_ABILITY_RECOVERED)
            {
                gIoRegisters.dispcnt &= ~DCNT_BG0;
                gCurrentEventBasedEffect = 0;
            }
            break;

        case EVENT_EFFECT_NIGHTMARE_ROOM:
            gUnk_3004e42 = 0;
            gIoRegisters.bldalpha_eva = 0;
            WRITE_16(REG_BLDALPHA, C_16_2_8(gIoRegisters.bldalpha_evb, gIoRegisters.bldalpha_eva));
            gWrittenToBldalpha = 0;
            break;

        case EVENT_EFFECT_OMEGA_METROID_ROOM:
            RoomEffectProcessOmegaMetroidRoom();
            gUnk_3000050 = 0x900;
            break;
    }

    CheckDisableAnimatedPalette();
}

/**
 * @brief 6368c | 28 | To document
 *
 * @param effect Event based effect
 */
void RoomEffectStartStopEventBased(u8 effect)
{
    if (gCurrentEventBasedEffect == effect)
    {
        gEventBasedEffectInfo.stage = 0;
        gEventBasedEffectInfo.timer = 0;
        gCurrentEventBasedEffect |= 0x80;
    }
}

/**
 * @brief 636b4 | 28 | Updates the current event based effect
 *
 */
void RoomEffectUpdateEventBased(void)
{
    if (gCurrentEventBasedEffect != EVENT_EFFECT_NONE)
    {
        if (gCurrentEventBasedEffect & 0x80)
            RoomEffectProcessEventBased();
        else
            RoomEffectCheckStopEventBased();
    }

    RoomEffectCheckUnlockHatches();
}

/**
 * @brief 636dc | 144 | Checks if the current event based effect should be stopped
 *
 */
void RoomEffectCheckStopEventBased(void)
{
    bools32 stop;

    stop = FALSE;

    switch (gCurrentEventBasedEffect)
    {
        case EVENT_EFFECT_2:
        case EVENT_EFFECT_REACTOR_CORE_ACTIVE:
        case EVENT_EFFECT_YAKUZA_ROOM:
        case EVENT_EFFECT_NIGHTMARE_ROOM:
        case EVENT_EFFECT_OMEGA_METROID_ROOM:
        case EVENT_EFFECT_POWER_OUTAGE_MISSILES:
            stop = TRUE;
            break;

        case EVENT_EFFECT_ELECTRIFIED_WATER:
            if (gEventCounter >= EVENT_WATER_LEVEL_LOWERED)
                stop = TRUE;
            break;

        case EVENT_EFFECT_MELTDOWN:
            if (gEventCounter >= EVENT_COOLING_UNIT_OPERATIONAL)
                stop = TRUE;
            break;

        case EVENT_EFFECT_AUX_POWER_INACTIVE:
            if (gEventCounter >= EVENT_AUXILARY_POWER_ENGAGED)
                stop = TRUE;
            break;

        case EVENT_EFFECT_SA_X_ELEVATOR_EXPLOSION:
            if (gSamusData.yPosition >= BLOCK_TO_SUB_PIXEL(6.f))
                stop = TRUE;
            break;

        case EVENT_EFFECT_SA_X_ELEVATOR_POWER:
            if (gSamusData.pose != SPOSE_USING_ELEVATOR)
            {
                SoundPlay_3b1c(MUSIC_OPERATIONS_DECK_ELEVATOR_OFFLINE_SOUND);
                stop = TRUE;
            }
            break;

        case EVENT_EFFECT_POWER_OUTAGE_YAKUZA:
            if (gSamusData.pose != SPOSE_USING_ELEVATOR)
                stop = TRUE;
            break;

        case EVENT_EFFECT_12:
            if (gSamusData.pose == SPOSE_FACING_FOREGROUND)
                stop = TRUE;
            break;

        case EVENT_EFFECT_OPERATIONS_ROOM:
            if (gEventCounter >= EVENT_ORBIT_CHANGE_IMPLEMENTED)
                stop = TRUE;
            break;

        case EVENT_EFFECT_RECOVERING_SUIT:
            if (gCurrentPowerBomb.animationState == 0 && gCurrentPowerBomb.powerBombPlaced == 0)
            {
                SAMUS_SET_POSE(SPOSE_F8);
                stop = TRUE;
            }
            break;
    }

    if (stop)
        RoomEffectStartStopEventBased(gCurrentEventBasedEffect);
}

/**
 * @brief 63820 | 46C | Processes the current event based effect
 *
 */
void RoomEffectProcessEventBased(void)
{
    s32 frames;
    s32 action;
    u16 dispcnt;

    APPLY_DELTA_TIME_INC(gEventBasedEffectInfo.timer);
    // 0: None
    // 1: Next stage
    // 2: Unlock door and stop?
    // 3: Stop?
    action = 0;

    switch (gCurrentEventBasedEffect & 0x7F)
    {
        case EVENT_EFFECT_ATMOSPHERIC_STABILIZER:
            if (gEventBasedEffectInfo.stage == 0)
            {
                RoomEffectFade(1);
                gUnk_3004e3a = 1;
                action = 1;
            }
            else if (gEventBasedEffectInfo.stage == 1)
            {
                if (gAnimatedPaletteAndTileset.animatedPalette == 0)
                {
                    DMA3_COPY_16(PALRAM_BASE, gBackgroundPalette, COLORS_IN_PAL);
                    action = 1;
                }
            }
            else if (gEventBasedEffectInfo.stage == 2)
            {
                if (gEventBasedEffectInfo.timer > CONVERT_SECONDS(2.f / 15))
                {
                    gEventBasedEffectInfo.timer = 0;

                    if (RoomEffectFade(2) != 0)
                    {
                        gDoorUnlockTimer = CONVERT_SECONDS(.5f);
                        action = 2;
                    }
                }
            }
            break;

        case EVENT_EFFECT_ELECTRIFIED_WATER:
            if (gEventBasedEffectInfo.stage == 0)
            {
                if (gPreventMovementTimer == 0)
                {
                    SoundPlay(SOUND_11E);
                    SoundStop(SOUND_ELECTRIC_WATER);
                    action = 1;
                }
            }
            else if (gEventBasedEffectInfo.stage == 1)
            {
                if (++gUnk_3004e4c.unk_8 > 0x27F)
                {
                    SoundStop(SOUND_11E);
                    gWaterLowered = 1;
                    gUnk_3004e3a = 1;
                    gUnk_3004e4c.unk_8 = 0x280;
                    action = 2;
                }

                if (gScreenShakeY.timer == 0)
                    ScreenShakeStartVertical(CONVERT_SECONDS(1.f / 3), 0x81);
            }
            break;

        case EVENT_EFFECT_MELTDOWN:
            if (gEventBasedEffectInfo.stage == 0)
            {
                if (gPreventMovementTimer == 0)
                {
                    SoundEventUpdate(SOUND_EVENT_COOLING_UNIT_OPERATIONAL, SEVENT_TTYPE_ROOM_EVENT);
                    action = 1;
                }
            }
            else if (gEventBasedEffectInfo.stage == 1)
            {
                if (gEventBasedEffectInfo.timer > CONVERT_SECONDS(2.f / 15))
                {
                    gEventBasedEffectInfo.timer = 0;

                    if (RoomEffectFade(3) != 0)
                        action = 2;
                }
            }
            break;

        case EVENT_EFFECT_2:
            if (gEventBasedEffectInfo.stage == 0)
            {
                if (gPreventMovementTimer != 0)
                    action = 1;
            }
            else if (gEventBasedEffectInfo.stage == 1)
            {
                if (gPreventMovementTimer == 0)
                {
                    gSecurityHatchLevel = gEquipment.securityHatchLevel;
                    action = 2;
                }
            }
            break;

        case EVENT_EFFECT_AUX_POWER_INACTIVE:
            if (gEventBasedEffectInfo.stage == 0)
            {
                if (gPreventMovementTimer != 0)
                {
                    SoundEventUpdate(SOUND_EVENT_AUXILIARY_POWER_MESSAGE_STARTED, SEVENT_TTYPE_ROOM_EVENT);
                    action = 1;
                }
            }
            else if (gEventBasedEffectInfo.stage == 1)
            {
                if (gPreventMovementTimer == 0)
                {
                    SoundEventUpdate(SOUND_EVENT_AUXILIARY_POWER_MESSAGE_ENDED, SEVENT_TTYPE_ROOM_EVENT);
                    gAnimatedPaletteAndTileset.animatedPalette = gCurrentRoomEntry.animatedPalette;
                    action = 2;
                }
            }
            break;

        case EVENT_EFFECT_SA_X_ELEVATOR_EXPLOSION:
            if (gEventBasedEffectInfo.stage == 0)
            {
                SoundEventUpdate(SOUND_EVENT_SA_X_ELEVATOR_CUTSCENE_RUMBLE_1, SEVENT_TTYPE_ROOM_EVENT);
                ScreenShakeStartHorizontal(CONVERT_SECONDS(.5f), 1);
                action = 1;
            }
            else if (gEventBasedEffectInfo.stage == 1)
            {
                if (gEventBasedEffectInfo.timer > CONVERT_SECONDS(1.f / 3))
                {
                    SoundEventUpdate(SOUND_EVENT_SA_X_ELEVATOR_CUTSCENE_RUMBLE_2, SEVENT_TTYPE_ROOM_EVENT);
                    action = 2;
                }
            }
            break;

        case EVENT_EFFECT_SA_X_ELEVATOR_POWER:
            if (gEventBasedEffectInfo.timer > CONVERT_SECONDS(2.f / 15))
            {
                gEventBasedEffectInfo.timer = 0;

                if (RoomEffectFade(4) != 0)
                    action = 2;
            }
            break;

        case EVENT_EFFECT_POWER_OUTAGE_MISSILES:
            if (gEventBasedEffectInfo.timer > CONVERT_SECONDS(2.f / 15))
            {
                gEventBasedEffectInfo.timer = 0;

                if (RoomEffectFade(5) != 0)
                {
                    gUnk_3004e44.unk_0 = (-0x10 & gUnk_3004e44.unk_0) | 1;
                    action = 3;
                }
            }
            break;

        case EVENT_EFFECT_POWER_OUTAGE_YAKUZA:
            if (gEventBasedEffectInfo.stage == 0)
            {
                ScreenShakeStartVertical(CONVERT_SECONDS(4.f / 15), 1);
                SoundPlay(SOUND_233);
                SoundEventUpdate(SOUND_EVENT_ELEVATOR_POWER_OUTAGE, SEVENT_TTYPE_ROOM_EVENT);
                action = 1;
            }
            else if (gEventBasedEffectInfo.stage == 1)
            {
                if (gEventBasedEffectInfo.timer > CONVERT_SECONDS(1.f / 6))
                    action = 1;
            }
            else if (gEventBasedEffectInfo.timer > CONVERT_SECONDS(2.f / 15))
            {
                gEventBasedEffectInfo.timer = 0;

                if (RoomEffectFade(6) != 0)
                    action = 3;
            }
            break;

        case EVENT_EFFECT_BOX2_ROOM:
            gUnk_3004e3a = 1;
            action = 3;
            break;

        case EVENT_EFFECT_REACTOR_CORE_ACTIVE:
            if (gSamusData.yPosition > BLOCK_TO_SUB_PIXEL(44 + 59.f / 64))
            {
                if (MOD_AND(gEventBasedEffectInfo.timer, 16) == 0)
                    SoundPlay(SOUND_127);
            }
            else
            {
                gEventBasedEffectInfo.timer = 0;
            }
            break;

        case EVENT_EFFECT_12:
            if (gSoundEventCounter == SOUND_EVENT_POWER_OUTAGE_LEAVING_SHIP_ENDED)
                SoundEventUpdate(SOUND_EVENT_POWER_OUTAGE_LEAVING_SHIP_ENDED, SEVENT_TTYPE_ROOM_EVENT);
            action = 3;
            break;

        case EVENT_EFFECT_YAKUZA_ROOM:
            if (gEventCounter >= EVENT_SPACE_JUMP_ABILITY_RECOVERED)
            {
                dispcnt = gIoRegisters.dispcnt & ~DCNT_BG0;
                gIoRegisters.dispcnt = dispcnt;
                gWrittenToDispcnt = dispcnt;
                action = 3;
            }
            break;

        case EVENT_EFFECT_NIGHTMARE_ROOM:
            if (gSamusPhysics.slowed == 0x80)
            {
                if (gUnk_3004e42 == 0)
                {
                    if (gEventBasedEffectInfo.timer > CONVERT_SECONDS(1))
                    {
                        gUnk_3004e42 = 1;
                        gEventBasedEffectInfo.timer = 0;
                    }
                }
                else
                {
                    gEventBasedEffectInfo.timer = 0;
                }
            }
            else if (gUnk_3004e42 != 0)
            {
                if (gEventBasedEffectInfo.timer > CONVERT_SECONDS(1))
                {
                    gUnk_3004e42 = 0;
                    gEventBasedEffectInfo.timer = 0;
                }
            }
            else
            {
                gEventBasedEffectInfo.timer = 0;
            }

            frames = gUnk_3004e42 == 1 ? 0x1F : 0xF;
            if (MOD_AND(gFrameCounter8Bit, frames + 1) == 0)
                RoomEffectFade(7);

            break;

        case EVENT_EFFECT_OPERATIONS_ROOM:
            if (RoomEffectProcessOperationsRoom() != 0)
                action = 3;
            break;

        case EVENT_EFFECT_OMEGA_METROID_ROOM:
            RoomEffectProcessOmegaMetroidRoom();
            break;

        case EVENT_EFFECT_RECOVERING_SUIT:
            if (RoomEffectRecoveringSuitCutscene() != 0)
            {
                gDisablePauseFlag = 0;
                gCurrentEventBasedEffect = 0;
            }
            break;
    }

    if (action != 0)
    {
        if (action == 2)
        {
            if (gDoorUnlockTimer == 0)
                gDoorUnlockTimer = 1;

            gCurrentEventBasedEffect = 0x80;
            gEventBasedEffectInfo.stage = 0;
        }
        else if (action == 3)
        {
            gCurrentEventBasedEffect = 0x80;
            gEventBasedEffectInfo.stage = 0;
        }
        else
        {
            gEventBasedEffectInfo.stage++;
        }

        gEventBasedEffectInfo.timer = 0;
    }
}

/**
 * @brief 63c8c | b4 | Checks if the hatches should be unlocked
 *
 */
void RoomEffectCheckUnlockHatches(void)
{
    s32 i;

    if (gDoorUnlockTimer > 0)
    {
        APPLY_DELTA_TIME_DEC(gDoorUnlockTimer);
        if (gDoorUnlockTimer == 0)
        {
            gDoorUnlockTimer = -1;

            if (gLockedHatches != 0 && gCurrentNavigationRoom != 0)
            {
                for (i = 0; i < MAX_AMOUNT_OF_HATCHES; i++)
                {
                    if (gHatchData[i].exists && gHatchData[i].locked && (gLockedHatches >> i) & 1)
                    {
                        gHatchData[i].state = 1;
                        gHatchData[i].currentAnimation = 0;
                        gHatchData[i].locked = 0;
                        gLockedHatches ^= 1 << i;
                    }
                }
            }
        }
    }
    else if (gDoorUnlockTimer < 0)
    {
        RoomEffectCheckUnlockProximityHatches();
    }
}

/**
 * @brief 63d40 | a8 | Checks if a hatch lock event applies
 *
 * @return s32 bool, hatch lock event found
 */
bools32 RoomEffectCheckHatchLockEvents(void)
{
    u32 i;
    bools32 hasEventLock;
    bools32 beforeEndGame;
    u32 hatches;

    hasEventLock = FALSE;

    for (i = 0; i < ARRAY_SIZE(sHatchLockEvents); i++)
    {
        if (gEventCounter == sHatchLockEvents[i].event)
        {
            if (gCurrentArea == sHatchLockEvents[i].area && gCurrentRoom == sHatchLockEvents[i].room - 1)
            {
                hasEventLock = TRUE;
                break;
            }
            continue;
        }
        if (gEventCounter < sHatchLockEvents[i].event)
            break;
    }

    if (hasEventLock)
    {
        beforeEndGame = TRUE;
        if (gGameCompletion.completedGame && gEventCounter >= EVENT_SECOND_CONVERSATION &&
            gEventCounter < EVENT_ENTERED_OPERATION_DECK)
        {
            beforeEndGame = FALSE;
        }

        if (beforeEndGame)
        {
            hatches = (sHatchLockEvents[i].hatch0 << 0) | (sHatchLockEvents[i].hatch1 << 1) |
                (sHatchLockEvents[i].hatch2 << 2) | (sHatchLockEvents[i].hatch3 << 3) |
                (sHatchLockEvents[i].hatch4 << 4) | (sHatchLockEvents[i].hatch5 << 5);
            RoomEffectLockHatches(hatches);
        }
    }

    return hasEventLock;
}

/**
 * @brief 63de8 | 18 | To document
 *
 */
void RoomEffectCheckLockHatchesWithTimer(void)
{
    RoomEffectLockHatchesWithTimer((1 << MAX_AMOUNT_OF_HATCHES) - 1);
    gUnk_3000047 = 2;
}

/**
 * @brief 63e00 | e8 | Checks if Samus is near to any unlocked hatches that should open
 *
 */
void RoomEffectCheckUnlockProximityHatches(void)
{
    s32 idx;
    bools32 nearHatch;
    s32 hatchRight;
    s32 hatchLeft;
    s32 hatchTop;
    s32 hatchBottom;
    s32 samusX;
    s32 samusY;

    idx = gFrameCounter8Bit & 7;
    if (idx < MAX_AMOUNT_OF_HATCHES)
    {
        if (gHatchData[idx].exists && gHatchData[idx].locked && (gLockedHatches >> idx) & 1)
        {
            nearHatch = FALSE;
            hatchRight = gHatchData[idx].xPosition;
            hatchLeft = hatchRight;

            if (gHatchData[idx].facingRight)
                hatchRight += 2;
            else
                hatchLeft = hatchRight - 2;

            hatchTop = gHatchData[idx].yPosition - 1;
            hatchBottom = gHatchData[idx].yPosition + 4;
            samusX = DIV_SHIFT(gSamusData.xPosition, BLOCK_SIZE);
            samusY = DIV_SHIFT(gSamusData.yPosition + ONE_SUB_PIXEL + (gSamusData.drawDistanceTop / 2), BLOCK_SIZE);

            if (samusX >= hatchLeft && hatchRight >= samusX && samusY >= hatchTop && hatchBottom >= samusY)
            {
                nearHatch = TRUE;
            }

            if (nearHatch)
            {
                gHatchData[idx].state = HATCH_STATE_1;
                gHatchData[idx].currentAnimation = 0;
                gHatchData[idx].locked = 0;
                gLockedHatches ^= 1 << idx;
            }
        }
    }
}

/**
 * @brief 63ee8 | 588 | Handles the recovering suit cutscene
 *
 * @return s32 bool, Cutscene ended
 */
bools32 RoomEffectRecoveringSuitCutscene(void)
{
    bools32 ended;
    s32 nextStage;

    s32 xOffset;
    s32 yOffset;
    s32 left;
    s32 right;
    s32 top;
    s32 bottom;

    s32 increment;
    u32 offsets;
    u16 newStart;
    u16 newEnd;

    ended = FALSE;
    nextStage = FALSE;

    xOffset = gSamusData.xPosition - gBg1XPosition;
    if (xOffset < 0)
    {
        left = 0;
    }
    else
    {
        if (xOffset > BLOCK_TO_SUB_PIXEL(14 + 7.f / 8))
            left = SCREEN_SIZE_X - 2;
        else
            left = DIV_SHIFT(xOffset, 4);
    }

    right = left + 2;

    bottom = gSamusData.yPosition - BLOCK_TO_SUB_PIXEL(1.5f);
    yOffset = bottom - gBg1YPosition;
    if (yOffset < 0)
    {
        top = 0;
    }
    else
    {
        if (yOffset > BLOCK_TO_SUB_PIXEL(9 + 7.f / 8))
            top = SCREEN_SIZE_Y - 2;
        else
            top = DIV_SHIFT(yOffset, 4);
    }

    bottom = top + 2;

    if (gWindow1Border.timer != UCHAR_MAX)
        APPLY_DELTA_TIME_INC(gWindow1Border.timer);

    switch (gEventBasedEffectInfo.stage)
    {
        case 0:
            if (gPoseLock == 2)
                nextStage = TRUE;
            break;

        case 1:
            gWrittenToBldalpha_Evb = gIoRegisters.bldalpha_evb;
            gWrittenToBldalpha_Eva = gIoRegisters.bldalpha_eva;
            nextStage = TRUE;
            break;

        case 2:
            if (MOD_AND(gEventBasedEffectInfo.timer, 2) == 0)
            {
                if (gWrittenToBldalpha_Evb != 0x10)
                {
                    if (++gWrittenToBldalpha_Evb > 0x10)
                        gWrittenToBldalpha_Evb = 0x10;
                }
                else
                {
                    nextStage++;
                }

                if (gWrittenToBldalpha_Eva == 0)
                {
                    nextStage++;
                }
                else
                {
                    if (gWrittenToBldalpha_Eva - 1 < 0)
                        gWrittenToBldalpha_Eva = 0;
                    else
                        gWrittenToBldalpha_Eva--;
                }

                gWrittenToBldalpha = C_16_2_8(gWrittenToBldalpha_Evb, gWrittenToBldalpha_Eva);
                nextStage = DIV_SHIFT(nextStage, 2);
            }
            break;

        case 3:
            gWrittenToDispcnt = gIoRegisters.dispcnt & ~DCNT_BG0;
            DMA3_COPY_16(VRAM_BASE + 0x800, gCommonSpriteGfxBackup, 0x400);
            nextStage = TRUE;
            break;

        case 4:
            // Fill BG0 tilemap with tile 0xC0, palette 9
            DMA3_FILL_16(0x90C0, VRAM_BASE + 0x800, 0x800);
            WRITE_16(REG_BG0CNT, CREATE_BGCNT(1, 1, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
            nextStage = TRUE;
            break;

        case 5:
            ParticleSet(gSamusData.yPosition + (gSamusData.drawDistanceTop / 2), gSamusData.xPosition,
                PE_GETTING_SUIT_BEAMS);
            ParticleSet(gSamusData.yPosition + (gSamusData.drawDistanceTop / 2), gSamusData.xPosition, PE_GETTING_SUIT);
            SoundPlay_3b1c(MUSIC_4D);
            nextStage = TRUE;
            break;

        case 6:
            if (gEventBasedEffectInfo.timer > CONVERT_SECONDS(.5f))
                nextStage = TRUE;
            break;

        case 7:
            gWrittenToDispcnt = gIoRegisters.dispcnt;
            gWrittenToWinin_H = HIGH_BYTE(WIN1_ALL);
            gWrittenToWinout_L = WIN0_BG1 | WIN0_BG2 | WIN0_BG3 | WIN0_OBJ;
            gWrittenToBldalpha = C_16_2_8(8, 8);
            gWrittenToBldcnt_Special =
                BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_SCREEN_SECOND_TARGET;

            gWindow1Border.left = left;
            gWindow1Border.right = right;
            gWindow1Border.top = top;
            gWindow1Border.bottom = bottom;
            gWindow1Border.timer = 0;

            nextStage = TRUE;

            break;

        case 8:
            // Handle suit flash growing vertically
            increment = SCREEN_SIZE_Y / 40;
            if (gWindow1Border.top != 0)
            {
                if (gWindow1Border.top > increment)
                    gWindow1Border.top -= increment;
                else
                    gWindow1Border.top = 0;
            }
            else
            {
                nextStage++;
            }

            if (gWindow1Border.bottom < SCREEN_SIZE_Y)
            {
                gWindow1Border.bottom += increment;
                if (gWindow1Border.bottom > SCREEN_SIZE_Y)
                    gWindow1Border.bottom = SCREEN_SIZE_Y;
            }
            else
            {
                nextStage++;
            }

            nextStage = DIV_SHIFT(nextStage, 2);
            break;

        case 9:
            // Handle suit flash growing horizontally
            increment = SCREEN_SIZE_X / 30 - 1;
            if (gWindow1Border.left != 0)
            {
                if (gWindow1Border.left > increment)
                    gWindow1Border.left -= increment;
                else
                    gWindow1Border.left = 0;
            }
            else
            {
                nextStage++;
            }

            if (gWindow1Border.right < SCREEN_SIZE_X)
            {
                gWindow1Border.right += increment;
                if (gWindow1Border.right > SCREEN_SIZE_X)
                    gWindow1Border.right = SCREEN_SIZE_X;
            }
            else
            {
                nextStage++;
            }

            nextStage = DIV_SHIFT(nextStage, 2);
            break;

        case 10:
            if (gEventBasedEffectInfo.timer > CONVERT_SECONDS(1.f / 12))
                nextStage = TRUE;
            break;

        case 11:
            if (gEventCounter == EVENT_VARIA_SUIT_ABILITY_RECOVERED)
                nextStage = ABILITY_COUNT_VARIA_SUIT;
            else if (gEventCounter == EVENT_GRAVITY_SUIT_ABILITY_RECOVERED)
                nextStage = ABILITY_COUNT_GRAVITY_SUIT;
            else
                nextStage = ABILITY_COUNT_NONE;

            gEquipment.suitMiscStatus |= sAbilityRamValues[nextStage].suitStatus;
            gPreventMovementTimer = SAMUS_ITEM_PMT;
            nextStage = TRUE;
            break;

        case 12:
            if (gEventBasedEffectInfo.timer > CONVERT_SECONDS(1.f / 12))
                nextStage = TRUE;
            break;

        case 13:
            // Handle suit flash shrinking vertically
            offsets = RoomEffectCalculateSuitFlashOffset(3, top - gWindow1Border.top, gWindow1Border.bottom - bottom);
            newStart = offsets % 256;
            newEnd = HIGH_BYTE(offsets);

            if (gWindow1Border.top < top)
            {
                gWindow1Border.top += newEnd;
                if (gWindow1Border.top > top)
                    gWindow1Border.top = top;
            }
            else
            {
                nextStage++;
            }

            if (gWindow1Border.bottom > bottom)
            {
                gWindow1Border.bottom -= newStart;
                if (gWindow1Border.bottom < bottom)
                    gWindow1Border.bottom = bottom;
            }
            else
            {
                nextStage++;
            }

            nextStage = DIV_SHIFT(nextStage, 2);
            break;

        case 14:
            // Handle suit flash shrinking horizontally
            offsets = RoomEffectCalculateSuitFlashOffset(9, left - gWindow1Border.left, gWindow1Border.right - right);
            newStart = offsets % 256;
            newEnd = HIGH_BYTE(offsets);

            if (gWindow1Border.left < left)
            {
                gWindow1Border.left += newEnd;
                if (gWindow1Border.left > left)
                    gWindow1Border.left = left;
            }
            else
            {
                nextStage++;
            }

            if (gWindow1Border.right > right)
            {
                gWindow1Border.right -= newStart;
                if (gWindow1Border.right < right)
                    gWindow1Border.right = right;
            }
            else
            {
                nextStage++;
            }

            nextStage = DIV_SHIFT(nextStage, 2);
            break;

        case 15:
            gWrittenToDispcnt = gIoRegisters.dispcnt & ~DCNT_BG0;
            gWrittenToWinout_L = gIoRegisters.winout_L;
            gWrittenToWinin_H = gIoRegisters.winin_H;
            gWrittenToBldalpha = C_16_2_8(gWrittenToBldalpha_Evb, gWrittenToBldalpha_Eva);
            gWrittenToBldcnt_Special = gIoRegisters.bldcnt;

            gWindow1Border.left = 0;
            gWindow1Border.right = SCREEN_SIZE_X;
            gWindow1Border.top = 0;
            gWindow1Border.bottom = SCREEN_SIZE_Y;

            gPoseLock = 0;
            gPreventMovementTimer = SAMUS_ITEM_PMT;
            nextStage = TRUE;

            break;

        case 16:
            DMA3_COPY_16(gCommonSpriteGfxBackup, VRAM_BASE + 0x800, 0x400);
            WRITE_16(REG_BG0CNT, gIoRegisters.bg0Cnt);
            nextStage = TRUE;
            break;

        case 17:
            gWrittenToDispcnt = gIoRegisters.dispcnt;
            nextStage = TRUE;
            break;

        case 18:
            if (MOD_AND(gEventBasedEffectInfo.timer, 2) == 0)
            {
                if (gWrittenToBldalpha_Evb != gIoRegisters.bldalpha_evb)
                {
                    if (gWrittenToBldalpha_Evb > gIoRegisters.bldalpha_evb)
                        gWrittenToBldalpha_Evb--;
                    else if (gWrittenToBldalpha_Evb < gIoRegisters.bldalpha_evb)
                        gWrittenToBldalpha_Evb++;
                }
                else
                {
                    nextStage++;
                }

                if (gWrittenToBldalpha_Eva != gIoRegisters.bldalpha_eva)
                {
                    if (gWrittenToBldalpha_Eva > gIoRegisters.bldalpha_eva)
                        gWrittenToBldalpha_Eva--;
                    else if (gWrittenToBldalpha_Eva < gIoRegisters.bldalpha_eva)
                        gWrittenToBldalpha_Eva++;
                }
                else
                {
                    nextStage++;
                }

                gWrittenToBldalpha = C_16_2_8(gWrittenToBldalpha_Evb, gWrittenToBldalpha_Eva);
                nextStage = DIV_SHIFT(nextStage, 2);
            }
            break;

        case 19:
            gPreventMovementTimer = 0;
            ended = TRUE;
            break;
    }

    if (nextStage)
    {
        gEventBasedEffectInfo.stage++;
        gEventBasedEffectInfo.timer = 0;
    }

    gWrittenToWin1H = C_16_2_8(gWindow1Border.left, gWindow1Border.right);
    gWrittenToWin1V = C_16_2_8(gWindow1Border.top, gWindow1Border.bottom);

    return ended;
}

/**
 * @brief 64470 | 50 | To document
 *
 * @return u16 Distance 1 in high byte, distance 2 in low byte
 */
u16 RoomEffectCalculateSuitFlashOffset(u8 maxDist, u8 pos1, u8 pos2)
{
    u8 dist1;
    u8 dist2;

    dist1 = 0;
    dist2 = 0;

    if (pos1 > pos2)
    {
        if (pos2 > pos1 - maxDist)
            dist2 = pos2 - (pos1 - maxDist);

        dist1 = maxDist;
    }
    else if (pos1 < pos2)
    {
        if (pos1 > pos2 - maxDist)
            dist1 = pos1 - (pos2 - maxDist);

        dist2 = maxDist;
    }
    else
    {
        dist2 = maxDist;
        dist1 = maxDist;
    }

    return C_16_2_8(dist1, dist2);
}

/**
 * @brief 644c0 | 88 | Processes the effect for the operations room
 *
 * @return s32 bool, Effect ended
 */
bools32 RoomEffectProcessOperationsRoom(void)
{
    bools32 ended;

    ended = FALSE;

    switch (gEventBasedEffectInfo.stage)
    {
        case 0:
            if (gPreventMovementTimer != 0)
            {
                SoundEventUpdate(SOUND_EVENT_ORBIT_CHANGE_IMPLEMENTED, SEVENT_TTYPE_ROOM_EVENT);
                gEventBasedEffectInfo.stage++;
            }
            break;

        case 1:
            if (gPreventMovementTimer == 0)
            {
                gBg3Movement.leftToRightStage = 1;
                ScreenShakeStartHorizontal(CONVERT_SECONDS(4), 1);
                SoundPlay(SOUND_242);
                gEventBasedEffectInfo.stage++;
                gEventBasedEffectInfo.timer = 0;
            }
            break;

        case 2:
            if (gEventBasedEffectInfo.timer >= CONVERT_SECONDS(4))
            {
                ScreenShakeStartHorizontal(CONVERT_SECONDS(4), 0);
                ended = TRUE;
            }
            break;
    }

    return ended;
}

/**
 * @brief 64548 | 7c | Processes the effect for the Omega Metroid room
 *
 */
void RoomEffectProcessOmegaMetroidRoom(void)
{
    bools32 animate;

    if (gAnimatedPaletteTiming.timer2 == 0)
    {
        animate = gEscapeTimerDigits.minutesOnes < sEscapeDigits_9Minutes.minutesOnes;

        if (animate)
            gAnimatedPaletteTiming.timer2 = 8;
        else
            return;
    }

    if (gAnimatedPaletteTiming.timer2 >= 8)
    {
        gAnimatedPaletteTiming.timer2 = 0;

        if (++gAnimatedPaletteTiming.row2 > 5)
            gAnimatedPaletteTiming.row2 = 0;

        DMA3_COPY_16(sDestroyedDockingBayAnimatedPal + gAnimatedPaletteTiming.row2 * PAL_ROW_SIZE,
            PALRAM_BASE + 4 * PAL_ROW_SIZE, PAL_ROW);
    }

    APPLY_DELTA_TIME_INC(gAnimatedPaletteTiming.timer2);
}
