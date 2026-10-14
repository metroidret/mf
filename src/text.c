#include "text.h"

#include "globals.h"
#include "new_file_intro.h"

#include "constants/text.h"

#include "data/event_data.h"
#include "data/text_data.h"
#include "data/menus/pause_debug.h"

#include "structs/event.h"
#include "structs/samus.h"

static u32 sArray_79c128[9] = {
    [0] = UINT_MAX ^ (UINT_MAX << 0 * sizeof(u32)),
    [1] = UINT_MAX ^ (UINT_MAX << 1 * sizeof(u32)),
    [2] = UINT_MAX ^ (UINT_MAX << 2 * sizeof(u32)),
    [3] = UINT_MAX ^ (UINT_MAX << 3 * sizeof(u32)),
    [4] = UINT_MAX ^ (UINT_MAX << 4 * sizeof(u32)),
    [5] = UINT_MAX ^ (UINT_MAX << 5 * sizeof(u32)),
    [6] = UINT_MAX ^ (UINT_MAX << 6 * sizeof(u32)),
    [7] = UINT_MAX ^ (UINT_MAX << 7 * sizeof(u32)),
    [8] = UINT_MAX
};

static u32 sArray_79c14c[9] = {
    [0] = UINT_MAX ^ (UINT_MAX >> 0 * sizeof(u32)),
    [1] = UINT_MAX ^ (UINT_MAX >> 1 * sizeof(u32)),
    [2] = UINT_MAX ^ (UINT_MAX >> 2 * sizeof(u32)),
    [3] = UINT_MAX ^ (UINT_MAX >> 3 * sizeof(u32)),
    [4] = UINT_MAX ^ (UINT_MAX >> 4 * sizeof(u32)),
    [5] = UINT_MAX ^ (UINT_MAX >> 5 * sizeof(u32)),
    [6] = UINT_MAX ^ (UINT_MAX >> 6 * sizeof(u32)),
    [7] = UINT_MAX ^ (UINT_MAX >> 7 * sizeof(u32)),
    [8] = UINT_MAX
};

static u8 sBlob_79c170_79c27c[] = INCBIN_U8("data/Blob_79c170_79c27c.bin");

 /**
 * @brief 79118 | 24 | Gets the width of a text character
 * 
 */
u32 TextGetCharacterWidth(u16 idx)
{
    if (idx >= ARRAY_SIZE(sCharacterWidths))
        return 10;
    return sCharacterWidths[idx];
}

 /**
 * @brief 7913c | 1cc | Draws a text character
 * 
 */
void TextDrawCharacter(u16 charId, u32* dst, u8 width, u8 indent, u8 color) 
{
    u32 pixel1;  
    u32 pixel2;
    u8* dstGfx;
    u32* dstGfx2;
    s32 pass;
    u32 passtmp;
    s32 i;
    s32 j;
    s32 size;
    u32* dest = dst;

    for (pass = 0; pass < 2; pass++)
    {
        dstGfx = pass ? EWRAM_BASE + 0x35DE0 : EWRAM_BASE + 0x35DA0;
        i = charId * 0x20 + pass * 0x400;
        size = (width > 8) ? 64 : 32;

        for (j = 0; j < size; j++, dstGfx++, i++)
        {
            passtmp = sCharactersGfx[i];
            
            if (color)
            {
                pixel1 = passtmp & 0xF;
                pixel2 = passtmp & 0xF0;

                if (pixel1 == 2 || pixel1 == 3)
                    pixel1 += color << 1;

                if (pixel2 == 0x20 || pixel2 == 0x30)
                    pixel2 += color << 5;

                *dstGfx = pixel2 | pixel1;
            }
            else
            {
                *dstGfx = passtmp;
            }
        }

        dstGfx2 = pass ? EWRAM_BASE + 0x35DE0 : EWRAM_BASE + 0x35DA0;

        if (width > 8)
        {
            for (i = 0; i < 8; i++)
                dstGfx2[i + 8] &= sArray_79c128[width - 8];
        }

        passtmp = pass * 0x100;

        if (indent)
        {
            for (i = 0; i < 8; i++)
            {
                dest[passtmp + i] |= (dstGfx2[i] << (indent * 4));
                dest[passtmp + i + 8] |= (dstGfx2[i] >> (0x20 - indent * 4));
            }

            if (width + indent > 16) 
            {
                for (i = 8; i < 16; i++)
                {
                    dest[passtmp + i] |= (dstGfx2[i] << (indent * 4));
                    dest[passtmp + i + 8] |= (dstGfx2[i] >> (0x20 - indent * 4));
                }
            } 
            else if (width > 8) 
            {
                for (i = 8; i < 16; i++)
                    dest[passtmp + i] |= (dstGfx2[i] << (indent * 4));
            }
        } 
        else 
        {
            size = (width > 8) ? 16 : 8;

            for (i = 0; i < size; i++)
                dest[passtmp + i] |= dstGfx2[i];
        }
    }
}

 /**
 * @brief 79308 | 130 | Draws a text character for a pause debug message
 * 
 */
void TextDrawCharacterPauseDebug(u16 charId, u32* dst, u8 color)
{
    s32 pass;
    u32 pixel1;
    u32 pixel2;
    s32 i;
    u32 j; 
    u8* dstGfx;

    if (color)
    {
        for (pass = 0; pass < 2; pass++)
        {
            j = charId * 0x20 + pass * 0x400;
            dstGfx = EWRAM_BASE + 0x35DA0;

            for (i = 0; i < 32; i++, dstGfx++, j++)
            {
                pixel1 = 0xF & sCharactersGfx[j];
                if (pixel1 == 2 || pixel1 == 3)
                    pixel1 += color << 1;
                else if (pixel1 == 0) 
                    pixel1 = 0xF;
                
                pixel2 = 0xF0 & sCharactersGfx[j];
                if (pixel2 == 0x20 || pixel2 == 0x30)
                    pixel2 += color << 5;
                else if (pixel2 == 0)
                    pixel2 = 0xF0;
                
                *dstGfx = pixel2 | pixel1;
            }

            DMA3_COPY_32(EWRAM_BASE + 0x35DA0, (dst + pass * 0x100), 8);
        }
    }
    else
    {
        for (pass = 0; pass < 2; pass++)
        {
            j = charId * 0x20 + pass * 0x400;
            dstGfx = EWRAM_BASE + 0x35DA0;

            for (i = 0; i < 32; i++, dstGfx++, j++)
            {
                pixel1 = 0xF & sCharactersGfx[j];
                if (pixel1 == 0)
                    pixel1 = 0xF;
                
                pixel2 = 0xF0 & sCharactersGfx[j];
                if (pixel2 == 0)
                    pixel2 = 0xF0;
                
                *dstGfx = pixel2 | pixel1;
            }

            DMA3_COPY_32(EWRAM_BASE + 0x35DA0, (dst + pass * 0x100), 8);
        }
    }
}

 /**
 * @brief 79438 | 21c | Draws a text character for a message
 * 
 */
static void TextDrawCharacterForMessage(u16 charID, u32* dst, u8 width, u8 indent, u8 color)
{
    u32 passtmp;
    u32 pixel1;
    u32 pixel2;
    s32 size;
    s32 pass;
    s32 i;
    u8* dstGfx;
    s32 j;
    u32* srcGfx;
    u32* dest = dst;

    for (pass = 0; pass < 2; pass++)
    {
        dstGfx = pass ? EWRAM_BASE + 0x35DE0 : EWRAM_BASE + 0x35DA0;
        i = charID * 0x20 + pass * 0x400;
        size = (width > 8) ? 64 : 32;

        for (j = 0; j < size; j++, dstGfx++, i++)
        {
            passtmp = sCharactersGfx[i];
            
            if (color != 0)
            {
                pixel1 = passtmp & 0xF;
                pixel2 = passtmp & 0xF0;
                
                if (pixel1 == 2 || pixel1 == 3)
                    pixel1 += color << 1;
                else if (pixel1 == 0)
                    pixel1 = 0xF;
                
                if (pixel2 == 0x20 || pixel2 == 0x30)
                    pixel2 += color << 5;
                else if (pixel2 == 0)
                    pixel2 = 0xF0;
            } 
            else
            {
                pixel1 = passtmp & 0xF;
                pixel2 = passtmp & 0xF0;
                
                if (pixel1 == 0)
                    pixel1 = 0xF;
                
                if (pixel2 == 0)
                    pixel2 = 0xF0;
            }
            
            *dstGfx = pixel2 | pixel1;
        }

        srcGfx = pass ? EWRAM_BASE + 0x35DE0 : EWRAM_BASE + 0x35DA0;
        passtmp = pass * 0x100;

        if (indent)
        {
            for (i = 0; i < 8; i++)
            {
                dest[passtmp + i] &= (srcGfx[i] << (indent * 4)) | sArray_79c128[indent];
                dest[passtmp + i + 8] &= (srcGfx[i] >> (32 - (indent * 4))) | sArray_79c14c[8 - indent];
            }

            if (width + indent > 16)
            {
                for (i = 8; i < 16; i++)
                {
                    dest[passtmp + i] &= (srcGfx[i] << (indent * 4)) | sArray_79c128[indent];
                    dest[passtmp + i + 8] &= (srcGfx[i] >> (32 - (indent * 4))) | sArray_79c14c[8 - indent];
                }
            }
            else if (width > 8)
            {
                for (i = 8; i < 16; i++)
                    dest[passtmp + i] &= (srcGfx[i] << (indent * 4)) | sArray_79c128[indent];
            }
        }
        else
        {
            size = (width > 8) ? 16 : 8;
            
            for (i = 0; i < size; i++)
                dest[passtmp + i] &= srcGfx[i];
        }
    }
}

 /**
 * @brief 79654 | ec | Draws text characters for a location text banner
 * 
 */
static void TextDrawLocationTextCharacters(u8 param_1, const u16** ppText) 
{
    void* dst;
    s32 indent;
    u32 indentClamped;
    boolu32 drawFlag;
    u32 width;

    if (param_1 == 1)
    {
        dst = EWRAM_BASE;
    }
    else if (param_1 == 2)
    {
        dst = EWRAM_BASE + 0x800;

        while (**ppText != CHAR_NEW_LINE)
            *ppText += 1;

        *ppText += 1;
    }
    else
    {
        return;
    }

    indent = 0;

    while (**ppText != CHAR_TERMINATOR && **ppText != CHAR_NEW_LINE)
    {
        drawFlag = TRUE;

        if ((**ppText & CHAR_MASK) == CHAR_WIDTH_MASK)
        {
            width = **ppText & 0xFF;
            drawFlag = FALSE;
        }
        else if ((**ppText & CHAR_MASK) == CHAR_INDENT_MASK)
        {
            drawFlag = FALSE;
            width = 0;
            indent = **ppText & 0xFF;
        }

        if (drawFlag)
        {
            width = TextGetCharacterWidth(**ppText);
            drawFlag = (indent >> 3) * 32;
            indentClamped = MOD_AND(indent, 8);
            TextDrawCharacterForMessage(**ppText, dst + drawFlag, width, indentClamped, 0);
        }
        
        *ppText += 1;
        indent += width;
    }
}

/**
 * @brief 79740 | 90 | Draws a location text
 * 
 * @param locationText Location text
 * @param gfxSlot Graphics slot
 */
void TextDrawLocationText(u8 locationText, u8 gfxSlot) 
{
    const u16* pText;

    DMA3_FILL_16(0xFFFF, EWRAM_BASE, 0x800);

    pText = sLocationTextPointers[gLanguage][locationText];
    TextDrawLocationTextCharacters(1, &pText);

    DMA3_COPY_32(EWRAM_BASE, VRAM_OBJ + 0x4000 + gfxSlot * 0x800, 0xE0);
    DMA3_COPY_32(EWRAM_BASE + 0x400, VRAM_OBJ + 0x4400 + gfxSlot * 0x800, 0xE0);
}

/**
 * @brief 797d0 | 110 | Draws a message banner
 * 
 * @param messageId Message ID
 * @param gfxSlot Graphics slot
 * @param stage Stage
 */
void TextDrawMessageBanner(u8 messageId, u8 gfxSlot, u8 stage) 
{
    s32 index;
    const u16* pText;

    if (stage == 4 || stage == 5)
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
        TextDrawLocationTextCharacters(1, &pText);
    }
    else if (stage == 4)
    {
        TextDrawLocationTextCharacters(2, &pText);
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
 * @brief 798e0 | 158 | Displays an event message
 * 
 * @param gfxSlot Graphics slot 
 * @param stage Stage
 */
void TextDisplayMessage(u8 gfxSlot, u8 stage) 
{
    u32 index;
    const u16* pText;

    if (stage == 4 || stage == 5)
    {
        for (index = 18; index != 0; --index)
        {
            if (gEventCounter == sObtainItemEvents[index])
                break;
        }   
        
        if (index)
            index = sAbilityRamValues[index].messageNumber;
        else if (gEquipment.securityHatchLevel >= 1 && gEquipment.securityHatchLevel <= 4)
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
        TextDrawLocationTextCharacters(1, &pText);
    }
    else if (stage == 4)
    {
        TextDrawLocationTextCharacters(2, &pText);
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
 * @brief 79a38 | c4 | Clears text graphics in VRAM in one of multiple ways
 * 
 * @param action Type of clearing action
 */
void TextClearGraphics(u8 action)
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
    {
        BitFill(3, 0, VRAM_BASE + 0x6000, 0x2000, 32);
    }
}
