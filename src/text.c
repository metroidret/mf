#include "globals.h"
#include "new_file_intro.h"

#include "structs/event.h"
#include "structs/samus.h"

#include "data/event_data.h"

extern void DrawLocationTextCharacters(u8 param_1, u16** ppText);

/**
 * @brief 79740 | 90 | Draws a location text
 * 
 * @param locationText Location text
 * @param gfxSlot Graphics slot
 */
void DrawLocationText(u8 locationText, u8 gfxSlot) 
{
    u16* pText;

    DMA3_FILL_16(0xFFFF, EWRAM_BASE, 0x800);

    pText = sLocationTextPointers[gLanguage][locationText];
    DrawLocationTextCharacters(1, &pText);

    DMA3_COPY_32(EWRAM_BASE, VRAM_OBJ + 0x4000 + gfxSlot * 0x800, 0xE0);
    DMA3_COPY_32(EWRAM_BASE + 0x400, VRAM_OBJ + 0x4400 + gfxSlot * 0x800, 0xE0);
}

/**
 * @brief 797d0 | 110 | To document
 * 
 */
void TextDrawMessageBanner(u8 messageId, u8 gfxSlot, u8 stage) 
{
    s32 index;
    u16* pText;

    if ((u8)(stage - 4) < 2)
    {
        index = messageId;
        if (index > 21)
            index = 21;
        
        index += 21;
        pText = sMessageTextPointers[gLanguage][index];
    }

    if (stage == 7)
    {
        BitFill(3, 0xFFFF, EWRAM_BASE, 0x800, 16);
    } 
    else if (stage == 6)
    {
        BitFill(3, 0xFFFF, EWRAM_BASE + 0x800, 0x800, 16);
    }
    else if (stage == 5)
    {
        DrawLocationTextCharacters(1, &pText);
    }
    else if (stage == 4)
    {
        DrawLocationTextCharacters(2, &pText);
    }
    else if (stage == 3)
    {
        DMA3_COPY_32(EWRAM_BASE, VRAM_OBJ + 0x4000 + gfxSlot * 0x800, 0xE0);
    }
    else if (stage == 2)
    {
        DMA3_COPY_32(EWRAM_BASE + 0x400, VRAM_OBJ + 0x4400 + gfxSlot * 0x800, 0xE0);
    }
    else if (stage == 1)
    {
        DMA3_COPY_32(EWRAM_BASE + 0x800, VRAM_OBJ + 0x4800 + gfxSlot * 0x800, 0xE0);
    }
    else if (stage == 0)
    {
        DMA3_COPY_32(EWRAM_BASE + 0xC00, VRAM_OBJ + 0x4C00 + gfxSlot * 0x800, 0xE0);
    }
}

/**
 * @brief 798e0 | 158 | To document
 * 
 */
void DisplayMessage(u8 gfxSlot, u8 stage) 
{
    u32 index;
    u16* pText;

    if ((u8)(stage - 4) < 2)
    {
        for (index = 18; index != 0; --index)
        {
            if (gEventCounter == sObtainItemEvents[index])
                break;
        }   
        
        if (index)
            index = sAbilityRamValues[index].messageNumber;
        else
            if ((u8)(gEquipment.securityHatchLevel - 1) < 4)
                index = gEquipment.securityHatchLevel - 1;
        
        pText = sMessageTextPointers[gLanguage][index];
    }
    
    if (stage == 7)
    {
        BitFill(3, 0xFFFF, EWRAM_BASE, 0x800, 16);
    }
    else if (stage == 6)
    {
        BitFill(3, 0xFFFF, EWRAM_BASE + 0x800, 0x800, 16);
    }
    else if (stage == 5)
    {
        DrawLocationTextCharacters(1, &pText);
    }
    else if (stage == 4)
    {
        DrawLocationTextCharacters(2, &pText);
    }
    else if (stage == 3)
    {
        DMA3_COPY_32(EWRAM_BASE, VRAM_OBJ + 0x4000 + gfxSlot * 0x800, 0xE0);
    }
    else if (stage == 2)
    {
        DMA3_COPY_32(EWRAM_BASE + 0x400, VRAM_OBJ + 0x4400 + gfxSlot * 0x800, 0xE0);
    }
    else if (stage == 1)
    {
        DMA3_COPY_32(EWRAM_BASE + 0x800, VRAM_OBJ + 0x4800 + gfxSlot * 0x800, 0xE0);
    }
    else if (stage == 0)
    {
        DMA3_COPY_32(EWRAM_BASE + 0xC00, VRAM_OBJ + 0x4C00 + gfxSlot * 0x800, 0xE0);
    }
}

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
