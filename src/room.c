#include "room.h"

#include "globals.h"
#include "macros.h"

#include "data/clipdata_data.h"
#include "data/clipdata_types_tilemap.h"
#include "data/common_bgs.h"
#include "data/common_pals.h"
#include "data/empty_data.h"
#include "data/rooms/test_rooms_data.h"
#include "data/rooms_data.h"

#include "constants/connection.h"
#include "constants/event.h"
#include "constants/room.h"
#include "constants/samus.h"

#include "structs/animated_graphics.h"
#include "structs/audio.h"
#include "structs/bg_clip.h"
#include "structs/block.h"
#include "structs/clipdata.h"
#include "structs/color_effects.h"
#include "structs/connection.h"
#include "structs/demo.h"
#include "structs/display.h"
#include "structs/event.h"
#include "structs/power_bomb.h"
#include "structs/room.h"
#include "structs/sa_x.h"
#include "structs/samus.h"
#include "structs/screen_shake.h"
#include "structs/scroll.h"

const struct Door* sAreaDoorPointers[AREA_END] = {
    [AREA_MAIN_DECK] = sMainDeckDoors,
    [AREA_SECTOR_1] = sSector1Doors,
    [AREA_SECTOR_2] = sSector2Doors,
    [AREA_SECTOR_3] = sSector3Doors,
    [AREA_SECTOR_4] = sSector4Doors,
    [AREA_SECTOR_5] = sSector5Doors,
    [AREA_SECTOR_6] = sSector6Doors,
    [AREA_TEST_1] = sTest1Doors,
    [AREA_TEST_2] = sTest2Doors,
    [AREA_TEST_3] = sTest3Doors
};

const struct RoomEntryRom* sAreaRoomEntryPointers[AREA_END] = {
    [AREA_MAIN_DECK] = sMainDeckRoomEntries,
    [AREA_SECTOR_1] = sSector1RoomEntries,
    [AREA_SECTOR_2] = sSector2RoomEntries,
    [AREA_SECTOR_3] = sSector3RoomEntries,
    [AREA_SECTOR_4] = sSector4RoomEntries,
    [AREA_SECTOR_5] = sSector5RoomEntries,
    [AREA_SECTOR_6] = sSector6RoomEntries,
    [AREA_TEST_1] = sTest1RoomEntries,
    [AREA_TEST_2] = sTest2RoomEntries,
    [AREA_TEST_3] = sTest3RoomEntries
};

/**
 * @brief 645c4 | 124 | Loads the current room
 *
 */
void RoomLoad(void)
{
    ClipdataSetupCode();
    RoomReset();
    RoomLoadEntry();
    RoomLoadTileset();
    RoomLoadScrollsAndEventBasedEffects();
    RoomLoadBackgrounds();
    RoomRemoveNeverReformBlocksAndCollectedTanks();

    gPreviousXPosition = gSamusData.xPosition;
    gPreviousYPosition = gSamusData.yPosition;

    RoomEffectSetTransparency();
    
    if (gPauseScreenFlag == PAUSE_SCREEN_NONE && !gIsLoadingFile)
    {
        ProcessGeneralScrolling();
        
        gBg1YPosition = gCamera.yPosition;
        gBg1XPosition = gCamera.xPosition;
        
        unk_6a7b4();
        ProcessGeneralScrolling();
        
        if (gCurrentRoomEntry.bg0Prop == BG_PROP_SA_X_ROOM)
            gBg0XPosition = BLOCK_TO_SUB_PIXEL(8);
    }
    
    RoomUpdateBackgroundPositions();
    RoomLoadDoors();
    RoomSetInitialTilemap(0);
    RoomSetInitialTilemap(1);
    RoomSetInitialTilemap(2);
    unk_6b890();
    LoadAnimatedGraphics();
    ResetTankAnimations();
    HazeSetBackgroundEffect();
    HazeProcess();
    MinimapCheckOnTransition();
    RoomEffectCheckSetCurrentEventBased();

    // Adjust spawn position if using an elevator
    if (!gIsLoadingFile && gUnk_3000be3 != 0 && gPauseScreenFlag == PAUSE_SCREEN_NONE &&
        gSamusData.pose == SPOSE_USING_ELEVATOR)
    {
        if (gSamusData.elevatorOrClimbingDirection == KEY_UP)
            gSamusData.yPosition += BLOCK_TO_SUB_PIXEL(3);
        else
            gSamusData.yPosition -= BLOCK_TO_SUB_PIXEL(3);

        gPreviousYPosition = gSamusData.yPosition;
    }
}

/**
 * @brief 646e8 | 138 | Loads the tileset of the current room
 *
 */
void RoomLoadTileset(void)
{
    struct TilesetEntry tileset;
    u32 bgGfxSize;

    tileset = sTilesetEntries[gCurrentRoomEntry.tilesetNumber];

    gTilemapAndClipPointers.pTilemap = (u16*)tileset.pTilemap + 1;

    if (gCurrentArea >= AREA_NORMAL_COUNT)
    {
        gTilemapAndClipPointers.pClipCollisions = sClipdataCollisionTypes_Test;
        gTilemapAndClipPointers.pClipBehaviors = sClipdataBehaviorTypes_Test;
    }
    else
    {
        gTilemapAndClipPointers.pClipCollisions = sClipdataCollisionTypes;
        gTilemapAndClipPointers.pClipBehaviors = sClipdataBehaviorTypes;
    }
    
    CallLZ77UncompVram(tileset.pTileGraphics, VRAM_BASE + 0x5800);
    WaitForDma3();
    
    DmaTransfer(3, sCommonTilesGfx, VRAM_BASE + 0x4800, ARRAY_SIZE(sCommonTilesGfx), 16);
    WaitForDma3();
    
    DMA3_COPY_16(tileset.pPalette, PALRAM_BASE + 2 * PAL_ROW_SIZE, 14 * PAL_ROW);
    WaitForDma3();

    DMA3_COPY_16(sCommonTilesPal, PALRAM_BASE, 3 * PAL_ROW);
    WaitForDma3();

    gTilesetTransparentColor.transparentColor = tileset.pPalette[0];
    WRITE_16(PALRAM_BASE, 0);
    gTilesetTransparentColor.field_2 = 0;

    bgGfxSize = C_16_2_8(((u8*)tileset.pBackgroundGraphics)[2],
        ((u8*)tileset.pBackgroundGraphics)[1]);
    CallLZ77UncompVram(tileset.pBackgroundGraphics, VRAM_BASE + 0xFDE0 - bgGfxSize);

    DMA3_FILL_32(0, VRAM_BASE + 0xFFE0, 32);

    if (gPauseScreenFlag == PAUSE_SCREEN_NONE)
    {
        gCurrentRoomEntry.animatedTileset = tileset.animatedTileset;
        gCurrentRoomEntry.animatedPalette = tileset.animatedPalette;
        gAnimatedPaletteAndTileset.animatedTileset = tileset.animatedTileset;
        gAnimatedPaletteAndTileset.animatedPalette = tileset.animatedPalette;
    }
}

/**
 * @brief 64820 | 158 | Loads the current room entry
 *
 */
void RoomLoadEntry(void)
{
    struct RoomEntryRom entry;

    if (gPauseScreenFlag != PAUSE_SCREEN_NONE)
        return;

    entry = sAreaRoomEntryPointers[gCurrentArea][gCurrentRoom];

    gCurrentRoomEntry.tilesetNumber = entry.tileset;
    gCurrentRoomEntry.bg0Prop = entry.bg0Prop;
    gCurrentRoomEntry.bg1Prop = entry.bg1Prop;
    gCurrentRoomEntry.bg2Prop = entry.bg2Prop;
    gCurrentRoomEntry.bg3Prop = entry.bg3Prop;
    gCurrentRoomEntry.bg3Scroll = entry.bg3Scrolling;
    gCurrentRoomEntry.transparency = entry.transparency;
    gCurrentRoomEntry.mapX = entry.mapX;
    gCurrentRoomEntry.mapY = entry.mapY;
    gCurrentRoomEntry.visualEffect = entry.effect;
    gCurrentRoomEntry.musicTrack = entry.musicTrack;

    gCurrentRoomEntry.effectY = entry.effectY != UCHAR_MAX ?
        BLOCK_TO_SUB_PIXEL(entry.effectY) : USHORT_MAX;

    gSpritesetEntryUsed = 0;
    gCurrentRoomEntry.firstSpritesetEvent = entry.firstSpritesetEvent;
    gCurrentRoomEntry.secondSpritesetEvent = entry.secondSpritesetEvent;

    if (gEventCounter >= gCurrentRoomEntry.secondSpritesetEvent &&
        gCurrentRoomEntry.secondSpritesetEvent != 0)
    {
        gCurrentRoomEntry.pEnemyRoomData = entry.pSecondSpriteData;
        gSpritesetNumber = entry.secondSpriteset;
        gSpritesetEntryUsed = 2;
    }
    else if (gEventCounter >= gCurrentRoomEntry.firstSpritesetEvent &&
        gCurrentRoomEntry.firstSpritesetEvent != 0)
    {
        gCurrentRoomEntry.pEnemyRoomData = entry.pFirstSpriteData;
        gSpritesetNumber = entry.firstSpriteset;
        gSpritesetEntryUsed = 1;
    }
    else
    {
        gCurrentRoomEntry.pEnemyRoomData = entry.pDefaultSpriteData;
        gSpritesetNumber = entry.defaultSpriteset;
    }

    gCurrentRoomEntry.scrollsFlag = 2;
    gCurrentRoomEntry.damagingEffect = 0;
    gCurrentRoomEntry.bg0Size = 0;
    gCurrentRoomEntry.bg3Size = 0;

    if (gSpritesetEntryUsed != 0 && gCurrentRoomEntry.bg0Prop == BG_PROP_SA_X_ROOM)
    {
        gSaXSpawnPosition.x = 0x8000;
        gSaXSpawnPosition.y = 0x8000;
    }
}

/**
 * @brief 64978 | 164 | Loads the backgrounds of the current room
 *
 */
void RoomLoadBackgrounds(void)
{
    struct RoomEntryRom entry;
    const u8* src;
    u8* pBg3Data;

    entry = sAreaRoomEntryPointers[gCurrentArea][gCurrentRoom];

    if (gEventCounter >= EVENT_ICE_MISSILE_DATA_DOWNLOADED &&
        gEventCounter < EVENT_COOLING_UNIT_OPERATIONAL &&
        gCurrentArea == 0 && (gCurrentRoom >= 0x18 && gCurrentRoom <= 0x1E))
    {
        gCurrentRoomEntry.bg0Prop = BG_PROP_LZ77_COMPRESSED;
        entry.pBg0Data = (u8*)sBg0_MeltdownRedFlash;
        gCurrentRoomEntry.transparency = 0x24;
    }

    if (gCurrentRoomEntry.bg0Prop & BG_PROP_LZ77_COMPRESSED)
        gCurrentRoomEntry.bg0Size = entry.pBg0Data[0];

    pBg3Data = (u8*)entry.pBg3Data;
    gCurrentRoomEntry.bg3Size = *pBg3Data;
    src = pBg3Data + 4;
    CallLZ77UncompVram(src, gDecompBg3Map);
    
    if (gCurrentRoomEntry.bg0Prop & BG_PROP_RLE_COMPRESSED)
    {
        src = entry.pBg0Data;
        gBackgroundsData.backgrounds[0].pDecomp = gDecompBg0Map;
        gBackgroundsData.backgrounds[0].width = *src++;
        gBackgroundsData.backgrounds[0].height = *src++;
        RoomRleDecompress(TRUE, src, (u8*)gDecompBg0Map);
    }
    else if (gCurrentRoomEntry.bg0Prop & BG_PROP_LZ77_COMPRESSED)
    {
        src = entry.pBg0Data + 4;
        CallLZ77UncompVram(src, VRAM_BASE);
    }

    if (gPauseScreenFlag == PAUSE_SCREEN_NONE)
    {
        // Load clipdata
        src = entry.pClipData;
        gBackgroundsData.pClipDecomp = gDecompClipdataMap;
        gBackgroundsData.clipdataWidth = *src++;
        gBackgroundsData.clipdataHeight = *src++;
        RoomRleDecompress(TRUE, src, (u8*)gDecompClipdataMap);

        // Load BG1
        src = entry.pBg1Data;
        gBackgroundsData.backgrounds[1].pDecomp = gDecompBg1Map;
        gBackgroundsData.backgrounds[1].width = *src++;
        gBackgroundsData.backgrounds[1].height = *src++;
        RoomRleDecompress(TRUE, src, (u8*)gDecompBg1Map);

        // Load BG2
        if (gCurrentRoomEntry.bg2Prop & BG_PROP_RLE_COMPRESSED)
        {
            src = entry.pBg2Data;
            gBackgroundsData.backgrounds[2].pDecomp = gDecompBg2Map;
            gBackgroundsData.backgrounds[2].width = *src++;
            gBackgroundsData.backgrounds[2].height = *src++;
            RoomRleDecompress(TRUE, src, (u8*)gDecompBg2Map);
        }
    }
}

/**
 * @brief 64adc | 10 | Removes blocks that never reform and tanks that have already been collected
 *
 */
void RoomRemoveNeverReformBlocksAndCollectedTanks(void)
{
    RemoveNeverReformBlocks();
    RemoveCollectedTanks();
}

/**
 * @brief 64aec | 448 | Resets all the room related info during a transition
 *
 */
void RoomReset(void)
{
    s32 i;
    const struct Door *pDoor;
    u16 *pBlocks;
    u16 xOffset;
    u16 yOffset;
    s32 tmp;

    // Needed to produce matching ASM. Any two variables will work. Without this,
    // gPreviousCutscene and gLastDoorUsed below will have their registers swapped
    if (gFrameCounter8Bit) {}
    if (gFrameCounter16Bit) {}

    gColorFading.unk_3 = 0;
    gColorFading.fadeTimer = 0;
    gColorFading.useSecondColorSet &= -0x10;
    gColorFading.status = 0;
    gColorFading.stage = 0;

    if (gCurrentPowerBomb.animationState != 0)
        gScreenShakeX = sScreenShake_Empty;

    gCurrentPowerBomb = sPowerBomb_Empty;

    gWrittenToBldcnt = 0;
    gScrollCounter = 0;

    if (gUnk_3000be3 == 0)
    {
        gColorFading.type = 2;
        
        gCurrentMusicTrack.number = 0;
        gCurrentMusicTrack.lowered = 0;
        
        gCurrentClipdataAffectingAction = 0;
        
        gPreviousArea = UCHAR_MAX;
        gDisableDoorsAndTanks = FALSE;
        gCurrentCutscene = CUTSCENE_NONE;
        gCurrentNavigationRoom = 0;
        gElevatorDirection = 0;

        if (!gIsLoadingFile)
        {
            for (i = 0; i < ARRAY_SIZE(gUseAlternateAnimatedTilesetFlags); i++)
                gUseAlternateAnimatedTilesetFlags[i] = 0;

            gPreviousCutscene = CUTSCENE_NONE;
            gLastDoorUsed = 0;

            if (gCurrentDemo & 0x80)
                DemoLoadRam(0);

            SetAbilityCount(gAbilityCount);
        }

        gDoorPositionStart.x = 0;
        gDoorPositionStart.y = 0;
        
        gSecurityHatchLevel = gEquipment.securityHatchLevel;
        
        SramWrite_MostRecentSaveFile();
    }

    if (gColorFading.type == 4 || gColorFading.type == 6)
        gWhichBgPositionIsWrittenToBg3Ofs = 4;
    else
        gWhichBgPositionIsWrittenToBg3Ofs = 3;
    
    if (gCurrentCutscene != 0)
        EventCheckUpdateAfterCutscene();

    if (gPauseScreenFlag != PAUSE_SCREEN_NONE)
        return;

    gDisableScrolling = FALSE;
    gCollectingTankFlag = FALSE;
    gUnk_3000050 = 0;
    gDisablePauseFlag = FALSE;
    gBackdropColor = 0;
    
    gQueuedEventBasedEffect = 0;
    gCurrentEventBasedEffect = 0;
    
    gEffectYPosition = 0;
    gLockedHatches = 0;
    gDoorUnlockTimer = 0;
    gUnk_3000047 = 0;
    
    pDoor = sAreaDoorPointers[gCurrentArea];
    pDoor += gLastDoorUsed;
    gCurrentRoom = pDoor->srcRoom;
    gLastDoorProperties = pDoor->type;
    gDisplayLocationName = (pDoor->type >> 6) & 1;
    gDoorPositionStart.x = pDoor->xStart;
    gDoorPositionStart.y = pDoor->yStart;
    
    gSaXSpawnPosition = sRawCoordsX_Empty;
    gUnk_3004e4c = sUnk_3c88e4;
    gUnk_3004e30 = sUnk_3c88dc;

    EventCheckRoomHasEventTrigger(gCurrentRoom + 1);

    for (i = 0; i < ARRAY_SIZE(gBrokenBlocks); i++)
        gBrokenBlocks[i] = sBrokenBlock_Empty;
    
    for (i = 0; i < ARRAY_SIZE(gUnk_3004ee0); i++)
        gUnk_3004ee0[i] = sBrokenBlock_Empty;

    for (i = 0; i < ARRAY_SIZE(gBombChains); i++)
        gBombChains[i] = sBombChain_Empty;

    gActiveBombChainTypes = 0;
    gDisableAnimatedGraphicsTimer = 0;

    pBlocks = EWRAM_BASE + 0x35D20; // gMakeSolidBlocks
    for (xOffset = ARRAY_SIZE(gMakeSolidBlocks); xOffset > 0; xOffset--)
        pBlocks[xOffset - 1] = 0;

    gScreenShakeY = sScreenShake_Empty;
    gScreenShakeX = sScreenShake_Empty;
    gScreenShakeXOffset = 0;
    gScreenShakeYOffset = 0;

    if (gIsLoadingFile)
    {
        if (gCurrentArea == AREA_MAIN_DECK && gCurrentRoom == 0)
        {
            gSamusData.xPosition = BLOCK_TO_SUB_PIXEL(25);
            gSamusData.yPosition = BLOCK_TO_SUB_PIXEL(11) - ONE_SUB_PIXEL;
        }
        
        return;
    }

    gCamera.xPosition = 0;
    gCamera.yPosition = 0;
    gCamera.xVelocity = 0;
    gCamera.yVelocity = 0;
    gCamera.unk_8 = 0;
    gCamera.unk_9 = 0;

    xOffset = pDoor->xStart;
    yOffset = pDoor->yEnd + 1;
    gSamusData.xPosition = BLOCK_TO_SUB_PIXEL(xOffset) + PIXEL_TO_SUB_PIXEL(pDoor->xExit + 8);
    gSamusData.yPosition = BLOCK_TO_SUB_PIXEL(yOffset) + PIXEL_TO_SUB_PIXEL(pDoor->yExit) - ONE_SUB_PIXEL;

    if (gCurrentDemo & 0x80)
        DemoLoadRam(TRUE);

    gSaXSpawnPosition.x = gSamusData.xPosition;
    gSaXSpawnPosition.y = gSamusData.yPosition;

    if (pDoor->xExit > 0)
        gSaXSpawnPosition.x = gSamusData.xPosition - BLOCK_TO_SUB_PIXEL(.5f);
    else if (pDoor->xExit < 0)
        gSaXSpawnPosition.x = gSamusData.xPosition + BLOCK_TO_SUB_PIXEL(.5f);
    
    if (gSamusDoorPositionOffset != 0)
    {
        if (gSamusDoorPositionOffset < 0)
        {
            gSamusDoorPositionOffset = 0;
        }
        else
        {
            tmp = gSamusData.drawDistanceTop;
            yOffset = -tmp;
            if (yOffset + gSamusDoorPositionOffset > UCHAR_MAX)
                gSamusDoorPositionOffset = UCHAR_MAX - yOffset;   
        }
        
        gSamusData.yPosition -= gSamusDoorPositionOffset;
        gSamusDoorPositionOffset = 0;
    }

    if (gSamusData.standingStatus == STANDING_ENEMY)
        gSamusData.standingStatus = STANDING_MID_AIR;

    gBg1YPosition = 0;
    gBg1XPosition = 0;
    gBg0XPosition = 0;
    gBg0YPosition = 0;

    if (gSamusData.pose == SPOSE_USING_ELEVATOR)
        gDisableDoorsAndTanks = 0x80;
}

/**
 * @brief 64f34 | 38C | Loads the scrolls and checks for event based effects
 *
 */
void RoomLoadScrollsAndEventBasedEffects(void)
{
    LoadScrolls();

    if (gPauseScreenFlag != PAUSE_SCREEN_NONE)
        return;

    gUnk_3004e10.unk_0 = 0x80;
    gUnk_3004e10.unk_2 = 0x80;
    gUnk_3004e10.unk_6 = 0x80;
    gUnk_3004e10.unk_4 = 0x80;

    if (gCurrentArea >= AREA_NORMAL_COUNT)
    {
        gUnk_3004e10.unk_0 = 0;
        gUnk_3004e10.unk_2 = 0;
        gUnk_3004e10.unk_6 = 0x80;
        gUnk_3004e10.unk_4 = 0x80;
    }

    gBg3Movement = sBg3Movement_Empty;

    switch (gCurrentRoomEntry.bg3Scroll)
    {
        case 7:
        case 8:
        case 10:
            if (gEventCounter >= EVENT_ORBIT_CHANGE_IMPLEMENTED)
                gBg3Movement.direction = 2;
            else
                gBg3Movement.direction = 1;
            break;
    }

    gUnk_3004e20 = sUnk_3c88cc;

    if (gCurrentRoomEntry.bg0Prop == BG_PROP_FOG)
    {
        gUnk_3004e20.unk_0 = 3;
    }
    else
    {
        if (gCurrentRoomEntry.visualEffect == EFFECT_WATER)
            gUnk_3004e20.unk_0 = 1;
        else if (gCurrentRoomEntry.visualEffect == EFFECT_SNOWFLAKES_COLD_KNOCKBACK)
            gUnk_3004e20.unk_0 = 4;
        else if (gCurrentRoomEntry.visualEffect == EFFECT_SNOWFLAKES_COLD)
            gUnk_3004e20.unk_0 = 4;
    }

    gQueuedEventBasedEffect = 0;

    if (gCurrentRoomEntry.bg0Prop == BG_PROP_FOG)
    {
        gQueuedEventBasedEffect = EVENT_EFFECT_ATMOSPHERIC_STABILIZER;
        return;
    }

    if (gCurrentRoomEntry.bg0Prop == BG_PROP_WATER_DRAIN_ROOM)
    {
        if (gEventCounter >= EVENT_WATER_LEVEL_LOWERED)
        {
            // Lower water by 10 blocks
            gCurrentRoomEntry.effectY += BLOCK_TO_SUB_PIXEL(10);
            gAnimatedPaletteAndTileset.animatedPalette = 0;
        }
        else
        {
            gQueuedEventBasedEffect = EVENT_EFFECT_ELECTRIFIED_WATER;
        }

        return;
    }

    switch (gCurrentRoomEntry.tilesetNumber)
    {
        case 14:
        case 41:
            // Sector 1
            gQueuedEventBasedEffect = EVENT_EFFECT_SECTOR_1_NON_STABILIZER;
            break;

        case 56:
            // Near Yakuza
            if (gCurrentArea == AREA_MAIN_DECK && gCurrentRoom == 54 &&
                gEventCounter < EVENT_AUXILARY_POWER_ENGAGED)
            {
                gAnimatedPaletteAndTileset.animatedPalette = 0;

                if (gEventCounter == EVENT_SPACE_JUMP_ABILITY_RECOVERED)
                    gQueuedEventBasedEffect = EVENT_EFFECT_AUX_POWER_INACTIVE;
            }
            break;

        case 17:
            // Main Deck elevators
            if (gEventCounter == EVENT_ENTERED_ELEVATOR_ROOM)
            {
                if (gCurrentArea == AREA_MAIN_DECK && gCurrentRoom == 34)
                {
                    gQueuedEventBasedEffect = EVENT_EFFECT_SA_X_ELEVATOR_EXPLOSION;
                    unk_6dec0();
                    SoundPlay(SOUND_FC);
                    gWhichBgPositionIsWrittenToBg3Ofs = 4;
                }
            }
            else if (gEventCounter == EVENT_POWER_OUTAGE)
            {
                if (gCurrentArea == AREA_MAIN_DECK && gCurrentRoom == 43 &&
                    gSamusData.pose == SPOSE_USING_ELEVATOR)
                {
                    gQueuedEventBasedEffect = EVENT_EFFECT_POWER_OUTAGE_YAKUZA;
                }
            }
            break;

        case 71:
            // Main Boiler
            gQueuedEventBasedEffect = EVENT_EFFECT_MAIN_BOILER_ROOM;
            break;

        case 93:
            // BOX 2
            gQueuedEventBasedEffect = EVENT_EFFECT_BOX2_ROOM;
            break;

        case 55:
            // Reactor Silo
            if (gCurrentArea == AREA_MAIN_DECK && gCurrentRoom == 59)
                gQueuedEventBasedEffect = EVENT_EFFECT_REACTOR_CORE_ACTIVE;
            break;

        case 80:
            // Restricted Lab
            gQueuedEventBasedEffect = EVENT_EFFECT_RESTRICTED_LAB;
            break;

        case 83:
            // Restricted Lab before SA-X
            if (gEventCounter < EVENT_RESTRICTED_LABORATORY_EXPLOSION)
                gAnimatedPaletteAndTileset.animatedPalette = 0;
            break;

        case 89:
            // Operations Room
            if (gEventCounter == EVENT_SA_X_DEFEATED)
            {
                gQueuedEventBasedEffect = EVENT_EFFECT_OPERATIONS_ROOM;
                gBg3Movement.direction = 3;
            }
            break;

        case 48:
            // Nightmare shadow
            if (gCurrentArea == AREA_SECTOR_5 && gCurrentRoom == 3)
                gQueuedEventBasedEffect = EVENT_EFFECT_NIGHTMARE_SHADOW;
            break;

        case 97:
            // Omega Metroid room
            gQueuedEventBasedEffect = EVENT_EFFECT_OMEGA_METROID_ROOM;
            break;

        case 7:
            // Yakuza room
            gQueuedEventBasedEffect = EVENT_EFFECT_YAKUZA_ROOM;
            break;

        case 57:
            // Nightmare room
            gQueuedEventBasedEffect = EVENT_EFFECT_NIGHTMARE_ROOM;
            break;
    }
}

/**
 * @brief 652c0 | 358 | Loads the doors for the current room
 *
 */
void RoomLoadDoors(void)
{
    s32 currHatch;
    const struct Door *pDoor;
    s32 hatchCount;
    u32 currDoor;
    u32 position;
    s32 clipdata;
    s32 facingRight;
    s32 lockType;
    s32 hatchSlot;

    if (gPauseScreenFlag != PAUSE_SCREEN_NONE)
        return;

    for (hatchCount = 0; hatchCount < MAX_AMOUNT_OF_HATCHES; hatchCount++)
    {
        gHatchData[hatchCount] = sHatchData_Empty;
        gHatchDoorIds[hatchCount] = 0;
    }

    currHatch = UCHAR_MAX;
    pDoor = sAreaDoorPointers[gCurrentArea];

    for (hatchCount = 0, currDoor = 0; pDoor->type != DOOR_TYPE_NONE; pDoor++, currDoor++)
    {
        if (gCurrentRoom != pDoor->srcRoom)
            continue;
            
        if ((pDoor->type & DOOR_TYPE_NO_FLAGS) == DOOR_TYPE_HATCH_CAN_LOCK)
        {
            position = gBackgroundsData.clipdataWidth * pDoor->yStart + pDoor->xStart;
            clipdata = gBackgroundsData.pClipDecomp[position + 1];
            
            if (clipdata & 0x8000)
                lockType = sClipdataTilemapCollisionTypes[clipdata & 0x7FFF];
            else
                lockType = gTilemapAndClipPointers.pClipCollisions[clipdata];
            
            facingRight = TRUE;
            if (lockType != CLIPDATA_TYPE_DOOR)
            {
                facingRight = FALSE;
                position = gBackgroundsData.clipdataWidth * pDoor->yStart + pDoor->xStart;
                clipdata = gBackgroundsData.pClipDecomp[position - 1];
            }
            
            if (clipdata & 0x8000)
                clipdata = sClipdataTilemapBehaviorTypes[clipdata & 0x7FFF];
            else
                clipdata = gTilemapAndClipPointers.pClipBehaviors[clipdata];
            
            lockType = HATCH_LOCK_OPEN;
            if (clipdata >= CLIP_BEHAVIOR_GRAY_DOOR)
            {
                lockType = HATCH_LOCK_CAN_LOCK;
                if (clipdata != CLIP_BEHAVIOR_GRAY_DOOR)
                {
                    lockType = HATCH_LOCK_GRAY;
                    if (clipdata >= CLIP_BEHAVIOR_BLUE_DOOR_SLOT_0)
                    {
                        lockType = HATCH_LOCK_LEVEL_1;
                        if (clipdata >= CLIP_BEHAVIOR_GREEN_DOOR_SLOT_0)
                        {
                            lockType = HATCH_LOCK_LEVEL_2;
                            if (clipdata >= CLIP_BEHAVIOR_YELLOW_DOOR_SLOT_0)
                            {
                                lockType = HATCH_LOCK_LEVEL_3;
                                if (clipdata >= CLIP_BEHAVIOR_RED_DOOR_SLOT_0)
                                {
                                    if (clipdata <= CLIP_BEHAVIOR_RED_DOOR_SLOT_5)
                                        lockType = HATCH_LOCK_LEVEL_4;
                                    else
                                        lockType = HATCH_LOCK_OPEN;
                                }
                            }
                        }
                    }
                }
            }

            if (lockType < HATCH_LOCK_OPEN)
            {
                if (lockType == HATCH_LOCK_CAN_LOCK)
                {
                    hatchSlot = 0;

                    for (lockType = MAX_AMOUNT_OF_HATCHES - 1; lockType > -1; lockType--)
                    {
                        if (!gHatchData[lockType].exists)
                            hatchSlot = lockType;
                    }

                    lockType = HATCH_LOCK_CAN_LOCK;
                }
                else
                {
                    hatchSlot = clipdata - (CLIP_BEHAVIOR_WHITE_DOOR_SLOT_0 + (lockType * 6));
                }

                if (!gHatchData[hatchSlot].exists)
                {
                    gHatchData[hatchSlot].lockType = lockType;
                    gHatchData[hatchSlot].facingRight = facingRight;
                    gHatchData[hatchSlot].yPosition = pDoor->yStart;
                    gHatchData[hatchSlot].xPosition = pDoor->xStart;
                    
                    if (facingRight)
                        gHatchData[hatchSlot].xPosition++;
                    else
                        gHatchData[hatchSlot].xPosition--;

                    gHatchData[hatchSlot].exists = TRUE;
                    gHatchDoorIds[hatchSlot] = currDoor;
                    hatchCount++;
                }
                else
                {
                    gHatchData[hatchSlot].lockType = HATCH_LOCK_COUNT;
                }
            }
            else
            {   
                if (!gHatchData[MAX_AMOUNT_OF_HATCHES - 1].exists)
                    hatchSlot = MAX_AMOUNT_OF_HATCHES - 1;
                else if (!gHatchData[MAX_AMOUNT_OF_HATCHES - 2].exists)
                    hatchSlot = MAX_AMOUNT_OF_HATCHES - 2;
                else
                    hatchSlot = 0;
                
                if (hatchSlot != 0)
                {
                    gHatchData[hatchSlot].lockType = 6;
                    gHatchData[hatchSlot].yPosition = pDoor->yStart;
                    gHatchData[hatchSlot].xPosition = pDoor->xStart;
                    gHatchData[hatchSlot].exists = TRUE;
                    gHatchDoorIds[hatchSlot] = currDoor;

                    if (gBackgroundsData.clipdataWidth > pDoor->xStart * 2)
                    {
                        // Hatch is on left half of room
                        gHatchData[hatchSlot].xPosition++;
                        gHatchData[hatchSlot].facingRight = TRUE;
                    } 
                    else
                    {
                        // Hatch is on right half of room
                        gHatchData[hatchSlot].xPosition--;
                        gHatchData[hatchSlot].facingRight = FALSE;
                    }
                }
            }
            
            if (currHatch == UCHAR_MAX && currDoor == gLastDoorUsed)
                currHatch = hatchSlot;
        }

        // Check for overflow
        if (hatchCount == MAX_AMOUNT_OF_HATCHES)
            break;
    }

    if (currHatch != UCHAR_MAX && gUnk_3000be3 != 0)
    {
        if (gHatchData[currHatch].exists && gHatchData[currHatch].lockType <= 4)
        {
            gHatchData[currHatch].state = 1;
            gHatchData[currHatch].currentAnimation = 4;
            UpdateHatchAnimation(currHatch);
            gHatchData[currHatch].state = 3;
            gHatchData[currHatch].currentAnimation = 0;
        }
    }

    for (hatchSlot = 0; hatchSlot < MAX_AMOUNT_OF_HATCHES; hatchSlot++)
    {
        if (gHatchData[hatchSlot].lockType == HATCH_LOCK_CAN_LOCK)
        {
            gHatchData[hatchSlot].state = 1;
            gHatchData[hatchSlot].currentAnimation = 4;
            UpdateHatchAnimation(hatchSlot);
            gHatchData[hatchSlot].state = 2;
            gHatchData[hatchSlot].currentAnimation = 0;
        }
    }
}

/**
 * @brief 65618 | 3C | Gets which hatches are closed in a navigation room
 *
 * @return u32 Closed hatches
 */
u32 RoomGetClosedNavigationHatches(void)
{
    u32 result;

    result = 0;

    if (gCurrentNavigationRoom != NAV_ROOM_NONE)
    {
        // Right hatch
        if (gHatchData[0].state == HATCH_STATE_CLOSED)
            result |= 1;

        // Left hatch
        if (gHatchData[1].state == HATCH_STATE_CLOSED)
            result |= 2;
    }

    return result;
}

/**
 * @brief 65654 | 250 | Sets up the initial tilemap for the specified background
 *
 * @param bg Background
 */
void RoomSetInitialTilemap(u8 bg)
{
    s32 properties;
    u16 yPosition;
    u16 xPosition;
    s32 i;
    s32 j;
    s32 tmp;

    u16* pDecomp;
    u16 yPos;
    u16 xPos;

    u16 xSize;
    u16 ySize;

    s16 offset;
    u16 rowIdx;

    u16 tmpX;
    s32 tmpX2;
    u16 block;

    u16* dst;
    u32 tmpOffset;

    if (bg == 0)
    {
        properties = gCurrentRoomEntry.bg0Prop;
        yPosition = gBg0YPosition;
        xPosition = gBg0XPosition;
    }
    else if (bg == 1)
    {
        properties = gCurrentRoomEntry.bg1Prop;
        yPosition = gBg1YPosition;
        xPosition = gBg1XPosition;
    }
    else
    {
        properties = gCurrentRoomEntry.bg2Prop;
        yPosition = gBg2YPosition;
        xPosition = gBg2XPosition;
    }

    if (properties & BG_PROP_RLE_COMPRESSED)
    {
        tmp = SUB_PIXEL_TO_BLOCK(xPosition);
        xSize = 21;
        offset = tmp - 3;
        if (offset < 0)
            offset = 0;
        if (xSize > gBackgroundsData.backgrounds[bg].width - offset)
            xSize = gBackgroundsData.backgrounds[bg].width - offset;
        xPos = offset;

        tmp = SUB_PIXEL_TO_BLOCK(yPosition);
        ySize = 16;
        offset = tmp - 3;
        if (offset < 0)
            offset = 0;
        if (ySize > gBackgroundsData.backgrounds[bg].height - offset)
            ySize = gBackgroundsData.backgrounds[bg].height - offset;

        yPos = offset;
        pDecomp = &gBackgroundsData.backgrounds[bg]
            .pDecomp[xPos + (u16)(gBackgroundsData.backgrounds[bg].width * (u16)offset)];

        for (i = 0; i < ySize; i++, yPos++)
        {
            rowIdx = i * gBackgroundsData.backgrounds[bg].width;
            tmpX = xPos;
            for (j = 0; j < xSize; rowIdx++, j++, tmpX++)
            {
                dst = VRAM_BASE + bg * 0x1000;
                tmpX2 = tmpX & 0x1F;
                tmpOffset = 0x800;
                if (tmpX2 & 0x10)
                    dst = VRAM_BASE + tmpOffset + bg * 0x1000;
                tmpX2 = (tmpX2 & 0xF) * 2;
                dst += (yPos & 0xF) * 64 + tmpX2;

                block = pDecomp[rowIdx];
                if (block & 0x8000)
                {
                    block = (block & 0x7FFF) * 4;
                    dst[0] = sCommonTilemap[block++];
                    dst[1] = sCommonTilemap[block++];
                    dst[32] = sCommonTilemap[block++];
                    dst[33] = sCommonTilemap[block++];
                }
                else
                {
                    block *= 4;
                    dst[0] = gTilemapAndClipPointers.pTilemap[block++];
                    dst[1] = gTilemapAndClipPointers.pTilemap[block++];
                    dst[32] = gTilemapAndClipPointers.pTilemap[block++];
                    dst[33] = gTilemapAndClipPointers.pTilemap[block++];
                }
            }
        }
    }
    else if (properties == 0)
    {
        dst = VRAM_BASE + bg * 0x1000;
        for (block = 0; block < 0x800; block++, dst++)
            *dst = 0x40;
    }
}

/**
 * @brief 658a4 | FC | RLE decompression algorithm
 *
 * @param type Type
 * @param src Source address
 * @param dst Destination address
 * @return u32 Size
 */
u32 RoomRleDecompress(u8 type, const u8* src, u8* dst)
{
    u32 size;
    u8 *dstStart;
    s32 pass;
    u32 value;

    size = 0;

    if (type == 0)
    {
        size = *src++;
        
        if (size == 0)
            size = 0x800;
        else if (size == 1)
            size = 0x1000;
        else if (size == 2)
            size = 0x1000;
        else
            size = 0x2000;
    }
    else if (type != 1)
    {
        *dst++ = *src++;
        *dst++ = 0;
        *dst++ = *src++;
        *dst++ = 0;
    }

    dstStart = dst;
    for (pass = 0; pass < 2; pass++)
    {
        if (*src++ == 1)
        {
            value = *src++;

            while (value != 0)
            {
                if (value & 0x80)
                {
                    value &= 0x7F;

                    for (; value > 0; value--)
                    {
                        *dst = *src;
                        dst += 2;
                    }

                    src++;
                }
                else
                {
                    for (; value > 0; value--)
                    {
                        *dst = *src++;
                        dst += 2;
                    }
                }

                value = *src++;
            }
        }
        else
        {
            value = *src++;
            value <<= 8;
            value |= *src++;

            while (value != 0)
            {
                if (value & 0x8000)
                {
                    value &= 0x7FFF;

                    for (; value > 0; value--)
                    {
                        *dst = *src;
                        dst += 2;
                    }

                    src++;
                }
                else
                {
                    for (; value > 0; value--)
                    {
                        *dst = *src++;
                        dst += 2;
                    }
                }

                value = *src++;
                value <<= 8;
                value |= *src++;
            }
        }

        dst = dstStart;
        dst++;
    }

    return size;
}

/**
 * @brief 659a0 | 40 | ?
 *
 */
void unk_659a0(void)
{
    if (gMonochromeFading != 0)
        ColorFadingApplyMonochrome();
    
    MinimapUpdate();
    
    if (gUnk_3004e44.unk_0_L)
        unk_65a1c();

    if (gElevatorDirection != 0)
        RoomCheckElevatorRideEnded();
}

/**
 * @brief 659e0 | 4 | Empty function
 *
 */
void unk_659e0(void)
{
    // Empty
}

/**
 * @brief 659e4 | 38 | Checks if an elevator ride has ended
 *
 */
void RoomCheckElevatorRideEnded(void)
{
    if (gSamusData.pose != SPOSE_USING_ELEVATOR)
    {
        if (gElevatorDirection == 1)
            SoundEventUpdateMusic(SEVENT_TTYPE_ENDING_ELEVATOR_RIDE_UP);
        else
            SoundEventUpdateMusic(SEVENT_TTYPE_ENDING_ELEVATOR_RIDE_DOWN);

        gElevatorDirection = 0;
    }
}

/**
 * @brief 65a1c | F0 | ?
 *
 */
void unk_65a1c(void)
{
    s32 animState;
    s32 coef;
    s32 evb;
    s32 eva;

    if (gWrittenToBldalpha != 0)
        return;

    animState = gCurrentPowerBomb.animationState;
    switch (animState)
    {
        case 1:
            gUnk_3004e44.unk_1 = gWrittenToBldalpha;
            gUnk_3004e44.unk_0_H = 2;
            coef = gIoRegisters.bldalpha_evb + 2;
            gWrittenToBldalpha = C_16_2_8(coef, 16 - coef);
            break;

        case 0:
            gUnk_3004e44.unk_1++;

            if (gUnk_3004e44.unk_1 > 19)
            {
                gUnk_3004e44.unk_1 = animState;
                gUnk_3004e44.unk_0_H++;
                gUnk_3004e44.unk_0_H &= 7;
                
                coef = gUnk_3004e44.unk_0_H & 3;
                if (coef != 0)
                {
                    if (coef & 1)
                        coef = 1;
                    else
                        coef = 2;
                }

                if (gUnk_3004e44.unk_0_H & 4)
                    coef = -coef;

                eva = gIoRegisters.bldalpha_eva;
                evb = gIoRegisters.bldalpha_evb;
                
                evb += coef;
                if (evb < 0)
                    evb = 0;
                else if (evb > 16)
                    evb = 16;

                eva -= coef;
                if (eva < 0)
                    eva = 0;
                else if (eva > 16)
                    eva = 16;

                gWrittenToBldalpha = C_16_2_8(evb, eva);
            }
            break;
    }
}

/**
 * @brief 65b0c | 58 | Checks if the animated graphics and palette should be updated
 *
 */
void RoomUpdateAnimatedGraphicsAndPalette(void)
{
    u32 flag;

    flag = FALSE;

    if (gSubGameMode1 != 1 && gSubGameMode1 != 3)
        flag = gSubGameMode1 != 2;

    if (gPreventMovementTimer != 0)
        flag = TRUE;

    if (!flag)
    {
        if (gDisableAnimatedGraphicsTimer == 0)
        {
            UpdateAnimatedGraphics();
            UpdateTankAnimations();
            UpdateAnimatedPalette();
            RoomUpdateHatchFlashingAnimation();
        }
        else
        {
            gDisableAnimatedGraphicsTimer--;
        }
    }
}

/**
 * @brief 65b64 | E4 | Updates the hatches flashing animation
 *
 */
void RoomUpdateHatchFlashingAnimation(void)
{
    if (gSubGameMode1 != 2)
        return;

    if (gSecurityHatchLevel <= 4)
    {
        gHatchFlashAnimation.coloredAnimTimer++;

        if (gHatchFlashAnimation.coloredAnimTimer > 7)
        {
            gHatchFlashAnimation.coloredAnimTimer = 0;
            gHatchFlashAnimation.coloredAnimState++;

            if (gHatchFlashAnimation.coloredAnimState > 5)
                gHatchFlashAnimation.coloredAnimState = 0;
            
            DMA3_COPY_16(&sHatchFlashingPal[gHatchFlashAnimation.coloredAnimState * PAL_ROW + 6],
                PALRAM_BASE + (PAL_ROW_SIZE * 1) + (6 * 2), (gSecurityHatchLevel + 1) * 2);
        }
    }

    if (gCurrentNavigationRoom == NAV_ROOM_NONE &&
        gLockedHatches != 0 && gDoorUnlockTimer < 0)
    {
        gHatchFlashAnimation.unlockedAnimTimer++;
        
        if (gHatchFlashAnimation.unlockedAnimTimer > 7)
        {
            gHatchFlashAnimation.unlockedAnimTimer = 0;
            gHatchFlashAnimation.unlockedAnimState++;

            if (gHatchFlashAnimation.unlockedAnimState > 7)
                gHatchFlashAnimation.unlockedAnimState = 0;
            
            DMA3_COPY_16(&sUnlockedHatchFlashingPal[gHatchFlashAnimation.unlockedAnimState * PAL_ROW + 13],
                PALRAM_BASE + (PAL_ROW_SIZE * 2) + (13 * 2), 3);
        }
    }
}

/**
 * @brief 65c48 | 108 | Updates the hatches flashing animation
 *
 */
void RoomUpdate(void)
{
    if (!gDisableScrolling && gColorFading.stage == 0)
    {
        RoomUpdateBackgroundPositions();
        gScrollCounter++;

        if (gScrollCounter & 1 || gCamera.xVelocity < -28 || gCamera.xVelocity > 28)
        {
            RoomUpdateHorizontalTilemap(16);
            RoomCopyHorizontalTilemap();
            RoomUpdateHorizontalTilemap(-2);
            RoomCopyHorizontalTilemap();
        }

        if (!(gScrollCounter & 1) || gCamera.yVelocity < -28 || gCamera.yVelocity > 28)
        {
            RoomUpdateVerticalTilemap(11);
            RoomCopyVerticalTilemap();
            RoomUpdateVerticalTilemap(-2);
            RoomCopyVerticalTilemap();
        }
    }
    else if (gDisableScrolling == 2)
    {
        RoomUpdateBackgroundPositions();
    }
    
    if (gSubGameMode1 == 2)
    {
        CheckTouchingSpecialClipdata();
        UpdateBrokenBlocks();
        UpdateNonReformBlocksAnimation();
        UpdateBombChains();
        RoomEffectUpdateEventBased();
        UpdateHatches();

        if (gRoomEventTrigger != 0)
            EventCheckRoomEventTrigger();
    }

    if (HazeProcess())
    {
        HazeProcess();

        if (gHazeInfo.enabled)
            gHazeInfo.active = TRUE;
    }

    PowerBombExplosionProcess();
}

/**
 * @brief 65d50 | 128 | Updates the positions of the backgrounds
 *
 */
void RoomUpdateBackgroundPositions(void)
{
    s32 xOffset;
    s32 yOffset;
    u16 xPosition;
    u16 yPosition;
    u16 bg3Y;
    u16 bg3X;

    yOffset = ScreenShakeUpdateVertical();
    xOffset = ScreenShakeUpdateHorizontal();

    xPosition = (gBg1XPosition / 4) & 0x1FF;
    yPosition = (gBg1YPosition / 4) & 0x1FF;
    gBackgroundPositions.bg[1].x = xPosition + xOffset;
    gBackgroundPositions.bg[1].y = yPosition + yOffset;
    xPosition = (gBg2XPosition / 4) & 0x1FF;
    gBackgroundPositions.bg[2].x = xPosition + xOffset;
    yPosition = (gBg2YPosition / 4) & 0x1FF;
    gBackgroundPositions.bg[2].y = yPosition + yOffset;

    if (gUnk_3000050 & 0x100)
    {
        gBackgroundPositions.bg[0].x = ((gBg0XPosition / 4) + gUnk_3004e20.unk_4) & 0x1FF;
        gBackgroundPositions.bg[0].y = ((gBg0YPosition / 4) + gUnk_3004e20.unk_6) & 0x1FF;
    }
    else
    {
        gBackgroundPositions.bg[0].x = (((gBg0XPosition / 4) + gUnk_3004e20.unk_4) & 0x1FF) + xOffset;
        gBackgroundPositions.bg[0].y = (((gBg0YPosition / 4) + gUnk_3004e20.unk_6) & 0x1FF) + yOffset;
    }

    bg3X = ((gBg3XPosition / 4) + gBg3Movement.xOffset) & 0x1FF;
    bg3Y = (gBg3YPosition / 4) & 0x1FF;

    if (gUnk_3000050 & 0x800)
    {
        gBackgroundPositions.bg[3].x = bg3X;
        gBackgroundPositions.bg[3].y = bg3Y;
    }
    else
    {
        gBackgroundPositions.bg[3].x = bg3X + (xOffset >> 1);
        gBackgroundPositions.bg[3].y = bg3Y + (yOffset >> 1);
    }
}

#define SET_TILES_VERT \
    block = gBackgroundsData.backgrounds[bg].pDecomp[blockIdx]; \
    if (block & 0x8000) \
    { \
        block = (block & 0x7FFF) * 4; \
        pTilemap->unk_6[srcTile++] = sCommonTilemap[block++]; \
        pTilemap->unk_6[srcTile++] = sCommonTilemap[block++]; \
        pTilemap->unk_6[srcTile++] = sCommonTilemap[block++]; \
        pTilemap->unk_6[srcTile++] = sCommonTilemap[block]; \
    } \
    else \
    { \
        block *= 4; \
        pTilemap->unk_6[srcTile++] = gTilemapAndClipPointers.pTilemap[block++]; \
        pTilemap->unk_6[srcTile++] = gTilemapAndClipPointers.pTilemap[block++]; \
        pTilemap->unk_6[srcTile++] = gTilemapAndClipPointers.pTilemap[block++]; \
        pTilemap->unk_6[srcTile++] = gTilemapAndClipPointers.pTilemap[block]; \
    } \
    blockIdx++; \
    if (srcTile >= tileCount) \
        break;

/**
 * @brief 65e78 | DEC | Updates the vertical tilemap of the room
 *
 * @param offset Movement offset
 */
void RoomUpdateVerticalTilemap(s32 offset)
{
    struct VerticalTilemap* pTilemap;
    s32 bg;
    u16 yPosition;
    u16 xPosition;
    s16 blockPos;
    s32 tileCount;
    s32 blockIdx;
    s32 srcTile;
    s32 block;

    u8 bgProps[3] = {
        gCurrentRoomEntry.bg0Prop,
        gCurrentRoomEntry.bg1Prop,
        gCurrentRoomEntry.bg2Prop
    };

    pTilemap = gVerticalTilemap;

    for (bg = 0; bg < 3; bg++, pTilemap++)
    {
        pTilemap->tileCount = 0;

        if (!(bgProps[bg] & 0x10))
            continue;

        if (bg == 0)
        {
            yPosition = gBg0YPosition;
            xPosition = gBg0XPosition;
        }
        else if (bg == 1)
        {
            yPosition = gBg1YPosition;
            xPosition = gBg1XPosition;
        }
        else
        {
            yPosition = gBg2YPosition;
            xPosition = gBg2XPosition;
        }

        blockPos = offset;
        blockPos += yPosition / 64;
        
        if (blockPos < 0 || blockPos > gBackgroundsData.backgrounds[bg].height)
            continue;

        pTilemap->blockY = blockPos;

        blockPos = (xPosition / 64) - 2;
        if (blockPos < 0)
            blockPos = 0;
        pTilemap->blockX = blockPos;

        tileCount = (SCREEN_SIZE_X / PIXEL_PER_BLOCK) + 4;
        if (gBackgroundsData.backgrounds[bg].width < tileCount)
            tileCount = gBackgroundsData.backgrounds[bg].width;
        tileCount *= 4;
        pTilemap->tileCount = tileCount;

        blockIdx = (gBackgroundsData.backgrounds[bg].width * pTilemap->blockY) + pTilemap->blockX;
        srcTile = 0;

        while (srcTile < tileCount)
        {
            // Repeat 19 (screen block width + 4) times
            SET_TILES_VERT
            SET_TILES_VERT
            SET_TILES_VERT
            SET_TILES_VERT
            SET_TILES_VERT
            SET_TILES_VERT
            SET_TILES_VERT
            SET_TILES_VERT
            SET_TILES_VERT
            SET_TILES_VERT
            SET_TILES_VERT
            SET_TILES_VERT
            SET_TILES_VERT
            SET_TILES_VERT
            SET_TILES_VERT
            SET_TILES_VERT
            SET_TILES_VERT
            SET_TILES_VERT
            SET_TILES_VERT
        }
    }
}

#define COPY_TILES_VERT \
    tileOffset = (blockX & 0xF) * 2; \
    if (blockX & 0x10) \
        tileOffset += 0x400; \
    dst[tileOffset] = pTilemap->unk_6[srcTile++]; \
    dst[tileOffset + 1] = pTilemap->unk_6[srcTile++]; \
    dst[tileOffset + 32] = pTilemap->unk_6[srcTile++]; \
    dst[tileOffset + 33] = pTilemap->unk_6[srcTile++]; \
    blockX++; \
    if (srcTile >= tileCount) \
        break;

/**
 * @brief 66c64 | 644 | Copies the vertical tilemap to VRAM
 *
 */
void RoomCopyVerticalTilemap(void)
{
    struct VerticalTilemap* pTilemap;
    s32 bg;
    s32 tileCount;
    u16* dst;
    s32 blockX;
    s32 srcTile;
    s32 tileOffset;

    pTilemap = gVerticalTilemap;

    for (bg = 0; bg < 3; bg++, pTilemap++)
    {
        tileCount = pTilemap->tileCount;

        if (tileCount == 0)
            continue;

        dst = VRAM_BASE + (bg * 0x1000);
        dst += (pTilemap->blockY & 0xF) * 0x40;
        blockX = pTilemap->blockX;
        srcTile = 0;

        while (srcTile < tileCount)
        {
            // Repeat 19 (screen block width + 4) times
            COPY_TILES_VERT
            COPY_TILES_VERT
            COPY_TILES_VERT
            COPY_TILES_VERT
            COPY_TILES_VERT
            COPY_TILES_VERT
            COPY_TILES_VERT
            COPY_TILES_VERT
            COPY_TILES_VERT
            COPY_TILES_VERT
            COPY_TILES_VERT
            COPY_TILES_VERT
            COPY_TILES_VERT
            COPY_TILES_VERT
            COPY_TILES_VERT
            COPY_TILES_VERT
            COPY_TILES_VERT
            COPY_TILES_VERT
            COPY_TILES_VERT
        }
    }
}

#define SET_TILES_HORI \
    block = gBackgroundsData.backgrounds[bg].pDecomp[blockIdx]; \
    if (block & 0x8000) \
    { \
        block = (block & 0x7FFF) * 4; \
        pTilemap->unk_6[srcTile++] = sCommonTilemap[block++]; \
        pTilemap->unk_6[srcTile++] = sCommonTilemap[block++]; \
        pTilemap->unk_6[srcTile++] = sCommonTilemap[block++]; \
        pTilemap->unk_6[srcTile++] = sCommonTilemap[block]; \
    } \
    else \
    { \
        block *= 4; \
        pTilemap->unk_6[srcTile++] = gTilemapAndClipPointers.pTilemap[block++]; \
        pTilemap->unk_6[srcTile++] = gTilemapAndClipPointers.pTilemap[block++]; \
        pTilemap->unk_6[srcTile++] = gTilemapAndClipPointers.pTilemap[block++]; \
        pTilemap->unk_6[srcTile++] = gTilemapAndClipPointers.pTilemap[block]; \
    } \
    blockIdx += gBackgroundsData.backgrounds[bg].width; \
    if (srcTile >= tileCount) \
        break;

/**
 * @brief 672a8 | AFC | Updates the horizontal tilemap of the room
 *
 * @param offset Movement offset
 */
void RoomUpdateHorizontalTilemap(s32 offset)
{
    struct HorizontalTilemap* pTilemap;
    s32 bg;
    u16 yPosition;
    u16 xPosition;
    s16 blockPos;
    s32 tileCount;
    s32 blockIdx;
    s32 srcTile;
    s32 block;

    u8 bgProps[3] = {
        gCurrentRoomEntry.bg0Prop,
        gCurrentRoomEntry.bg1Prop,
        gCurrentRoomEntry.bg2Prop
    };

    pTilemap = gHorizontalTilemap;

    for (bg = 0; bg < 3; bg++, pTilemap++)
    {
        pTilemap->tileCount = 0;

        if (!(bgProps[bg] & 0x10))
            continue;

        if (bg == 0)
        {
            yPosition = gBg0YPosition;
            xPosition = gBg0XPosition;
        }
        else if (bg == 1)
        {
            yPosition = gBg1YPosition;
            xPosition = gBg1XPosition;
        }
        else
        {
            yPosition = gBg2YPosition;
            xPosition = gBg2XPosition;
        }

        blockPos = offset;
        blockPos += xPosition / 64;
        
        if (blockPos < 0 || blockPos > gBackgroundsData.backgrounds[bg].width)
            continue;

        pTilemap->blockX = blockPos;

        blockPos = (yPosition / 64) - 2;
        if (blockPos < 0)
            blockPos = 0;
        pTilemap->blockY = blockPos;

        tileCount = (SCREEN_SIZE_Y / PIXEL_PER_BLOCK) + 4;
        if (gBackgroundsData.backgrounds[bg].height < tileCount)
            tileCount = gBackgroundsData.backgrounds[bg].height;
        tileCount *= 4;
        pTilemap->tileCount = tileCount;

        blockIdx = (gBackgroundsData.backgrounds[bg].width * pTilemap->blockY) + pTilemap->blockX;
        srcTile = 0;

        while (srcTile < tileCount)
        {
            // Repeat 14 (screen block height + 4) times
            SET_TILES_HORI
            SET_TILES_HORI
            SET_TILES_HORI
            SET_TILES_HORI
            SET_TILES_HORI
            SET_TILES_HORI
            SET_TILES_HORI
            SET_TILES_HORI
            SET_TILES_HORI
            SET_TILES_HORI
            SET_TILES_HORI
            SET_TILES_HORI
            SET_TILES_HORI
            SET_TILES_HORI
        }
    }
}

#define COPY_TILES_HORI \
    tileOffset = (blockY & 0xF) * 0x40; \
    dst[tileOffset] = pTilemap->unk_6[srcTile++]; \
    dst[tileOffset + 1] = pTilemap->unk_6[srcTile++]; \
    dst[tileOffset + 32] = pTilemap->unk_6[srcTile++]; \
    dst[tileOffset + 33] = pTilemap->unk_6[srcTile++]; \
    blockY++; \
    if (srcTile >= tileCount) \
        break;

/**
 * @brief 67da4 | 31C | Copies the horizontal tilemap to VRAM
 *
 */
void RoomCopyHorizontalTilemap(void)
{
    struct HorizontalTilemap* pTilemap;
    s32 bg;
    s32 tileCount;
    u16* dst;
    s32 blockX;
    s32 blockY;
    s32 srcTile;
    s32 tileOffset;

    pTilemap = gHorizontalTilemap;

    for (bg = 0; bg < 3; bg++, pTilemap++)
    {
        tileCount = pTilemap->tileCount;

        if (tileCount == 0)
            continue;

        dst = VRAM_BASE + (bg * 0x1000);
        blockX = pTilemap->blockX;
        if (blockX & 0x10)
            dst = VRAM_BASE + 0x800 + (bg * 0x1000);
        dst += (blockX & 0xF) * 2;
        blockY = pTilemap->blockY;
        srcTile = 0;

        while (srcTile < tileCount)
        {
            // Repeat 14 (screen block height + 4) times
            COPY_TILES_HORI
            COPY_TILES_HORI
            COPY_TILES_HORI
            COPY_TILES_HORI
            COPY_TILES_HORI
            COPY_TILES_HORI
            COPY_TILES_HORI
            COPY_TILES_HORI
            COPY_TILES_HORI
            COPY_TILES_HORI
            COPY_TILES_HORI
            COPY_TILES_HORI
            COPY_TILES_HORI
            COPY_TILES_HORI
        }
    }
}

/**
 * @brief 680c0 | 20 | Waits for DMA3 to finish
 *
 */
void WaitForDma3(void)
{
    vu32* dma;
    
    dma = (vu32*)REG_DMA3;

    while (dma[2] & (DMA_ENABLE << 16));
}
