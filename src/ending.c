#include "globals.h"
#include "init_helpers.h"
#include "macros.h"

#include "structs/ending.h"

extern void EndingDrawIgtAndCompletionPercentage();
extern void EndingImageDisplayLinePermanently(s32);
extern void EndingImageLoadTextOam(s32);
extern void EndingImageUpdateLettersSpawnDelay(s32);

boolu32 EndingImage(void) 
{
    boolu32 ended;
    s32 i;
    u16* src;
    u16* dst;
    u32 palette;
    s32 currSlot;
    s32 nextSlot;
    u16 part;
    
    ended = FALSE;
    
    switch (gLanguage) 
    {
        case 3:
        case 4:
        case 6:
            break;
        
        case 5:
        default:
            if (gNonGameplayRam.ending.timer == CONVERT_SECONDS(6.25f)) 
            {
                EndingImageDisplayLinePermanently(2);
            } 
            else if (gNonGameplayRam.ending.timer == CONVERT_SECONDS(6.34f)) 
            {
                EndingImageLoadTextOam(2);
            }
            break;
    }
    
    switch (gNonGameplayRam.ending.timer++) 
    {
        case 0:
            EndingDrawIgtAndCompletionPercentage();
            gNonGameplayRam.ending.unk_2 = 1;
            break;
        
        case CONVERT_SECONDS(0.5f):
            EndingImageLoadTextOam(0);
            gNonGameplayRam.ending.unk_97 = 1;
            break;
        
        case CONVERT_SECONDS(1.84f):
            EndingImageDisplayLinePermanently(0);
            break;
        
        case CONVERT_SECONDS(3):
            EndingImageDisplayLinePermanently(1);
            break;
        
        case CONVERT_SECONDS(5.5f):
            EndingImageLoadTextOam(1);
            break;
        
        case CONVERT_SECONDS(7.67f):
            EndingImageDisplayLinePermanently(3);
            break;
        
        case CONVERT_SECONDS(8.84f):
            EndingImageDisplayLinePermanently(4);
            break;
        
        case CONVERT_SECONDS(13):
            EndingImageDisplayLinePermanently(5);
            break;
        
        case CONVERT_SECONDS(22.94f):
            if (!(gChangedInput & (KEY_A | KEY_B | KEY_START)))
                gNonGameplayRam.ending.timer--;
            break;
        
        case CONVERT_SECONDS(27.74f):
            ended++;
            break;
    }
    
    if (gNonGameplayRam.ending.unk_2 == 1) 
    {
        if (gNonGameplayRam.ending.unk_8 > 0x7F) 
        {
            gNonGameplayRam.ending.unk_8 = MOD_AND(gNonGameplayRam.ending.unk_8, 0x80);
            gNonGameplayRam.ending.unk_8C = ((u16)-64 - gNonGameplayRam.ending.unk_4 * 64);
            gNonGameplayRam.ending.unk_90 = ((u16)-128 - gNonGameplayRam.ending.unk_4 * 64);
            gNonGameplayRam.ending.unk_4 = MOD_AND(gNonGameplayRam.ending.unk_4 + 1, 0x20);
            gNonGameplayRam.ending.unk_0++;
        }

        gBg0YPosition -= 6;
        gBg1YPosition -= 6;
        gNonGameplayRam.ending.unk_8 += 6;
        
        if (!gBg0YPosition || (gBg0YPosition & 0x8000))
        {
            gBg0YPosition = 0;
            gNonGameplayRam.ending.unk_2 = 0;
        }
    }
    
    if (gNonGameplayRam.ending.unk_97 == 1) 
    {
        for (currSlot = 6; currSlot < gNonGameplayRam.ending.unk_9B; currSlot++)
            EndingImageUpdateLettersSpawnDelay(currSlot);
    }

    if (gNonGameplayRam.ending.timer <= CONVERT_SECONDS(23) && (gNonGameplayRam.ending.timer < CONVERT_SECONDS(13.5f) || !(gButtonInput & (KEY_L | KEY_R))))  
    {
        dst = (u16*)&gOamData;
        dst += gNextOamSlot * sizeof(union OamData) / sizeof(*dst);
        
        currSlot = gNextOamSlot;
        nextSlot = currSlot;

        EMPTY_DO_WHILE
        
        for (i = 0; i < gNonGameplayRam.ending.unk_9B; i++) 
        {
            if (gNonGameplayRam.ending.unk_124[i] <= 1)
                continue;
            
            if (gNonGameplayRam.ending.unk_160[i] <= 0x3F)
                gNonGameplayRam.ending.unk_160[i]++;
                
            palette = 0;
            
            if (i > 5) 
            {                    
                if (gNonGameplayRam.ending.unk_160[i] < 4)
                    palette = 3;
                else if (gNonGameplayRam.ending.unk_160[i] < 8)
                    palette = 2;
                else if (gNonGameplayRam.ending.unk_160[i] < 12)
                    palette = 1;
            } 
            else if (i == 5) 
            {
                if (gNonGameplayRam.ending.unk_160[i] > 0x3F)
                    gNonGameplayRam.ending.unk_160[i] = palette;
                    
                switch (gNonGameplayRam.ending.unk_160[i] / 8)
                {
                    case 0:
                    case 7:
                        palette = 3;
                        break;
                        
                    case 1:
                    case 6:
                        palette = 2;
                        break;
                        
                    case 2:
                    case 5:    
                        palette = 1;
                        break;

                    case 3:
                    case 4:
                        break;  
                }
            }

            src = gNonGameplayRam.ending.oamFramePointers[i];
            part = *src++;
            nextSlot += (part & 0xFF);
            
            for (; currSlot < nextSlot; currSlot++)
            {
                part = *src++;
                *dst++ = part;

                gOamData[currSlot].split.y = part + gNonGameplayRam.ending.oamYPositions[i];

                part = *src++;
                *dst++ = part;

                gOamData[currSlot].split.x = MOD_AND(part + gNonGameplayRam.ending.oamXPositions[i], 0x200);

                *dst++ = *src++;
                
                gOamData[currSlot].split.priority = 0;
                gOamData[currSlot].split.paletteNum = palette;
                
                dst++;
            }
        }
        
        gNextOamSlot = nextSlot;
    }
                
    ResetFreeOam();
    
    return ended;
}

