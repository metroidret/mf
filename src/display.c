#include "display.h"
#include "gba.h"
#include "globals.h"

#include "structs/display.h"

/**
 * @brief 686e0 | b0 | Writes to the IO registers using the WrittenToXXX globals
 * 
 */
void IoWriteRegisters(void)
{
    if (gWrittenToDispcnt)
    {
        WRITE_16(REG_DISPCNT, gWrittenToDispcnt);
        gWrittenToDispcnt = 0;
    }

    if (gWrittenToBldalpha)
    {
        WRITE_16(REG_BLDALPHA, gWrittenToBldalpha);
        gWrittenToBldalpha = 0;
    }

    if (gWrittenToWinin_H)
    {
        WRITE_8(REG_WININ + 1, gWrittenToWinin_H);
        gWrittenToWinin_H = 0;
    }

    if (gWrittenToWinout_L)
    {
        WRITE_8(REG_WINOUT, gWrittenToWinout_L);
        gWrittenToWinout_L = 0;
    }

    if (gWrittenToWin1H | gWrittenToWin1V)
    {
        WRITE_16(REG_WIN1H, gWrittenToWin1H);
        WRITE_16(REG_WIN1V, gWrittenToWin1V);
        gWrittenToWin1H = 0;
        gWrittenToWin1V = 0;
    }

    if (gWrittenToBldcnt_Special)
    {
        WRITE_16(REG_BLDCNT, gWrittenToBldcnt_Special);
        gWrittenToBldcnt_Special = 0;
    }

    CheckTransferFadedPalette();
    TransferAnimatedGraphics();
}

/**
 * @brief 68790 | e0 | Writes to the IO registers using the WrittenToXXX globals during a transition
 * 
 */
void IoWriteRegistersDuringTransition(void)
{
    if (gWrittenToDispcnt)
    {
        WRITE_16(REG_DISPCNT, gWrittenToDispcnt);
        gWrittenToDispcnt = 0;
    }

    if (gWrittenToBldalpha)
    {
        WRITE_16(REG_BLDALPHA, gWrittenToBldalpha);
        gWrittenToBldalpha = 0;
    }

    if (gWrittenToWinin_H)
    {
        WRITE_8(REG_WININ + 1, gWrittenToWinin_H);
        gWrittenToWinin_H = 0;
    }

    if (gWrittenToWinout_L)
    {
        WRITE_8(REG_WINOUT, gWrittenToWinout_L);
        gWrittenToWinout_L = 0;
    }

    if (gWrittenToWin1H | gWrittenToWin1V)
    {
        WRITE_16(REG_WIN1H, gWrittenToWin1H);
        WRITE_16(REG_WIN1V, gWrittenToWin1V);
        gWrittenToWin1H = 0;
        gWrittenToWin1V = 0;
    }

    if (gWrittenToBldcnt_Special)
    {
        WRITE_16(REG_BLDCNT, gWrittenToBldcnt_Special);
        gWrittenToBldcnt_Special = 0;
    }

    if (gBg1CntDuringDoorTransition)
    {
        WRITE_16(REG_BG1CNT, gBg1CntDuringDoorTransition);
        gBg1CntDuringDoorTransition = 0;
    }

    if (gBg3CntDuringDoorTransition)
    {
        WRITE_16(REG_BG3CNT, gBg3CntDuringDoorTransition);
        gBg3CntDuringDoorTransition = 0;
    }
    
    CheckTransferFadedPalette();
    TransferAnimatedGraphics();
}