#include "sa_x_close_up.h"

#include "callbacks.h"
#include "gba.h"
#include "globals.h"
#include "macros.h"

#include "data/sa_x_close_up.h"

#include "constants/event.h"

#include "structs/display.h"
#include "structs/event.h"

boolu32 SaXCloseUpHandler(void)
{
    boolu32 ended;

    gNextOamSlot = 0;
    ended = FALSE;

    switch (gUnk_3000b85)
    {
        case 0:
            SaXCloseUpInit();
            gUnk_3000b85++;
            break;

        case 1:
            gWrittenToBldy = 0;
            gUnk_3000b85++;
            break;

        case 2:
            if (SaXCloseUp())
                gUnk_3000b85++;
            break;

        case 3:
            if (gWrittenToBldy < BLDY_MAX_VALUE)
            {
                gWrittenToBldy = BLDY_MAX_VALUE;
            }
            else
            {
                ended = TRUE;
                gUnk_3000b85 = 0;
            }
            break;
    }

    ResetFreeOam();

    return ended;
}

void SaXCloseUpInit(void)
{
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IME, TRUE);

    CallbackSetVBlank(SaXCloseUpLoadingVblank);

    WRITE_16(REG_BLDCNT,
        BLDCNT_BRIGHTNESS_DECREASE_EFFECT | BLDCNT_BACKDROP_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL |
            BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL |
            BLDCNT_BG0_FIRST_TARGET_PIXEL);
    WRITE_16(REG_BLDY, gWrittenToBldy = BLDY_MAX_VALUE);
    WRITE_16(REG_DISPCNT, 0);

    DMA3_FILL_32(0, &gNonGameplayRam, sizeof(gNonGameplayRam));

    DMA3_COPY_32(gOamData, OAM_BASE, OAM_SIZE / 4);

    DMA3_COPY_16(VRAM_OBJ, gCommonSpriteGfxBackup, ARRAY_SIZE(gCommonSpriteGfxBackup));
    CallLZ77UncompVram(sSaXCloseUpGfx, BGCNT_TO_VRAM_CHAR_BASE(0));

    DMA3_COPY_16(sSaXCloseUpPal, PALRAM_BASE, sizeof(sSaXCloseUpPal) / 2);
    WRITE_16(PALRAM_BASE, COLOR_BLACK);

    CallLZ77UncompVram(sSaXCloseUpTileTable1, BGCNT_TO_VRAM_TILE_BASE(0x18));
    CallLZ77UncompVram(sSaXCloseUpTileTable2, BGCNT_TO_VRAM_TILE_BASE(0x1a));

    WRITE_16(REG_BG0HOFS, 0);
    WRITE_16(REG_BG0VOFS, 0);
    WRITE_16(REG_BG1HOFS, 0);
    WRITE_16(REG_BG1VOFS, 0);
    WRITE_16(REG_BG2HOFS, 0);
    WRITE_16(REG_BG2VOFS, 0);
    WRITE_16(REG_BG3HOFS, 0);
    WRITE_16(REG_BG3VOFS, 0);

    gWrittenToBldy = BLDY_MAX_VALUE;
    if (gEventCounter == EVENT_ENTERED_ELEVATOR_ROOM)
        gWrittenToBldy = 0;

    gWrittenToBldalpha_Eva = BLDALPHA_MAX_VALUE;
    gWrittenToBldalpha_Evb = 0;

    WRITE_16(REG_BG0CNT, CREATE_BGCNT(0, 0x18, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG1CNT, CREATE_BGCNT(0, 0x1a, BGCNT_HIGH_MID_PRIORITY, BGCNT_SIZE_256x256));

    CallbackSetVBlank(SaXCloseUpVblank);
    SaXCloseUpVblank();

    gWrittenToDispcnt = DCNT_BG1 | DCNT_BG0;
}

void SaXCloseUpVblank(void)
{
    WRITE_16(REG_BLDY, gWrittenToBldy);
    WRITE_16(REG_BLDALPHA, C_16_2_8(gWrittenToBldalpha_Evb, gWrittenToBldalpha_Eva));

    if (gWrittenToDispcnt != 0)
    {
        WRITE_16(REG_DISPCNT, gWrittenToDispcnt);
        gWrittenToDispcnt = 0;
    }
}

void SaXCloseUpLoadingVblank(void)
{
    UpdateAudio();
}

boolu32 SaXCloseUp(void)
{
    boolu32 ended;

    ended = FALSE;

    SA_X_CLOSE_UP_DATA.timer++;
    if (SA_X_CLOSE_UP_DATA.unk_0 == 0 && SaXCloseUpProcess())
        ended = TRUE;

    return ended;
}

boolu32 SaXCloseUpProcess(void)
{
    boolu32 ended = FALSE;

    switch (SA_X_CLOSE_UP_DATA.stage)
    {
        case 0:
            WRITE_16(REG_BLDCNT,
                BLDCNT_BACKDROP_SECOND_TARGET_PIXEL | BLDCNT_OBJ_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL |
                    BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG1_SECOND_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
                    BLDCNT_BG0_FIRST_TARGET_PIXEL);
            SA_X_CLOSE_UP_DATA.stage++;
            SA_X_CLOSE_UP_DATA.timer = 0;
            break;

        case 1:
            if (SA_X_CLOSE_UP_DATA.timer > sSaXCloseUpDurations[0])
            {
                SA_X_CLOSE_UP_DATA.stage++;
                SA_X_CLOSE_UP_DATA.timer = 0;
            }
            break;

        case 2:
            if (gWrittenToBldalpha_Eva == 0)
            {
                WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) ^ DCNT_BG0);
                SA_X_CLOSE_UP_DATA.stage++;
                SA_X_CLOSE_UP_DATA.timer = 0;
            }
            else
            {
                gWrittenToBldalpha_Eva--;
                gWrittenToBldalpha_Evb = BLDALPHA_MAX_VALUE - gWrittenToBldalpha_Eva;
            }
            break;

        case 3:
            if (SA_X_CLOSE_UP_DATA.timer > sSaXCloseUpDurations[1])
            {
                SA_X_CLOSE_UP_DATA.stage++;
                SA_X_CLOSE_UP_DATA.timer = 0;
            }
            break;

        case 4:
        default:
            WRITE_16(REG_BLDCNT,
                BLDCNT_BRIGHTNESS_DECREASE_EFFECT | BLDCNT_BACKDROP_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL |
                    BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL |
                    BLDCNT_BG0_FIRST_TARGET_PIXEL);
            gWrittenToBldy = BLDY_MAX_VALUE;
            SA_X_CLOSE_UP_DATA.stage = 0;
            SA_X_CLOSE_UP_DATA.timer = 0;
            ended = TRUE;
            break;
    }

    return ended;
}
