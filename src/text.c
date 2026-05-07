#include "globals.h"

/**
 * @brief 79a38 | c4 | To document
 * 
 */
void ClearTextGraphics(u8 action)
{
    if (action == 1)
    {
        if (PAUSE_SCREEN_DATA.unk_18)
            action = 5;
        else 
            action = 3;
    }
    else if (action == 2)
    {
        if (PAUSE_SCREEN_DATA.unk_18)
            action = 6;
        else 
            action = 4;
    }

    if (action == 3)
    {
        BitFill(3, 0, VRAM_BASE + 0x7000, 0x1000, 32);
    }
    else if (action == 4)
    {
        DmaTransfer(3, VRAM_BASE + 0x7800, VRAM_BASE + 0x7000, 0x800, 32);
        BitFill(3, 0, VRAM_BASE + 0x7800, 0x800, 32);
    }
    else if (action == 5)
    {
        BitFill(3, 0, VRAM_BASE + 0x6000, 0x1000, 32);
    }
    else if (action == 6)
    {
        DmaTransfer(3, VRAM_BASE + 0x6800, VRAM_BASE + 0x6000, 0x800, 32);
        BitFill(3, 0, VRAM_BASE + 0x6800, 0x800, 32);
    }
    else
        BitFill(3, 0, VRAM_BASE + 0x6000, 0x2000, 32);
}
