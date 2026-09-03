#include "sprites_AI/omega_metroid.h"
#include "data/sprites/omega_metroid.h"

#include "globals.h"
#include "macros.h"

#include "data/sprite_data.h"
#include "data/frame_data_pointers.h"

#include "constants/audio.h"
#include "constants/event.h"
#include "constants/particle.h"
#include "constants/samus.h"
#include "constants/sprite_debris.h"

#include "structs/samus.h"
#include "structs/sprite.h"

#define OMEGA_METROID_JUMP_X_SPEED 20

enum OmegaMetroidPose {
    OMEGA_METROID_POSE_WALKING_BEFORE_SA_X_INIT = 1,
    OMEGA_METROID_POSE_WALKING_BEFORE_SA_X = 2,
    OMEGA_METROID_POSE_WAITING_FOR_SA_X_INIT = 7,
    OMEGA_METROID_POSE_WAITING_FOR_SA_X = 8,
    OMEGA_METROID_POSE_WALKING_BACKWARDS_FROM_SA_X = 9,
    OMEGA_METROID_POSE_DAMAGED_BY_SA_X_2 = 0xa,
    OMEGA_METROID_POSE_WATCHING_SA_X = 0xb,
    OMEGA_METROID_POSE_DAMAGED_BY_SA_X = 0xc,
    OMEGA_METROID_POSE_WAITING_TO_SWIPE_SA_X = 0xd,
    OMEGA_METROID_POSE_SWIPING_SA_X = 0xe,
    OMEGA_METROID_POSE_KILLED_SA_X = 0xf,
    OMEGA_METROID_POSE_SCREAMING_AFTER_ICE_BEAM_OBTAINED = 0x10,
    OMEGA_METROID_POSE_JUMP_WARNING_INIT = 0x17,
    OMEGA_METROID_POSE_JUMP_WARNING = 0x18,
    OMEGA_METROID_POSE_JUMPING = 0x1a,
    OMEGA_METROID_POSE_FALLING = 0x1c,
    OMEGA_METROID_POSE_LANDING_INIT = 0x1d,
    OMEGA_METROID_POSE_LANDING = 0x1e,
    OMEGA_METROID_POSE_IDLE_INIT = 0x1f,
    OMEGA_METROID_POSE_IDLE = 0x20,
    OMEGA_METROID_POSE_SLOW_WALKING_INIT = 0x21,
    OMEGA_METROID_POSE_SLOW_WALKING = 0x22,
    OMEGA_METROID_POSE_WALKING_INIT = 0x23,
    OMEGA_METROID_POSE_WALKING = 0x24,
    OMEGA_METROID_POSE_WALKING_BACKWARD_INIT = 0x25,
    OMEGA_METROID_POSE_WALKING_BACKWARD = 0x26,
    OMEGA_METROID_POSE_SWIPING_INIT = 0x29,
    OMEGA_METROID_POSE_SWIPING = 0x2a,
    OMEGA_METROID_POSE_VERTICAL_JUMP_INIT = 0x2b,
    OMEGA_METROID_POSE_VERTICAL_JUMP = 0x2c,
    OMEGA_METROID_POSE_WAITING_TO_APPEAR = 0x37,
    OMEGA_METROID_POSE_FIRST_JUMP = 0x38,
    OMEGA_METROID_POSE_LANDING_FROM_FIRST_JUMP = 0x3a,
    OMEGA_METROID_POSE_LANDED_AFTER_FIRST_JUMP = 0x3c,
    OMEGA_METROID_POSE_SCREAMING_AFTER_FIRST_JUMP = 0x3e,
    OMEGA_METROID_POSE_FINISHED_SCREAMING_AFTER_FIRST_JUMP = 0x40,
    OMEGA_METROID_POSE_DYING_INIT = 0x44,
    OMEGA_METROID_POSE_DYING_1 = 0x46,
    OMEGA_METROID_POSE_DYING_2 = 0x48,
    OMEGA_METROID_POSE_DYING_3 = 0x4a,
};

#define OMEGA_METROID_POSE_STAGE work0

enum OmegaMetroidWaitingForSaXStage {
    OMEGA_METROID_SA_X_STAGE_LOAD_GFX,
    OMEGA_METROID_SA_X_STAGE_WAIT_TO_SCREAM,
    OMEGA_METROID_SA_X_STAGE_SCREAM,
    OMEGA_METROID_SA_X_STAGE_SPAWN_SA_X,
    OMEGA_METROID_SA_X_STAGE_WAIT_TO_MOVE,
    OMEGA_METROID_SA_X_STAGE_MOVE,
    OMEGA_METROID_SA_X_STAGE_STAND,
};

#define OMEGA_METROID_WALK_ACTION work0

enum OmegaMetroidWalkAction {
    OMEGA_METROID_WALK_START,
    OMEGA_METROID_WALK_FORWARD,
    OMEGA_METROID_WALK_FINISH,
    OMEGA_METROID_WALK_STOP,
};

#define OMEGA_METROID_IDLE_ANIM work0

enum OmegaMetroidIdleAnim {
    OMEGA_METROID_IDLE_MOUTH_MOVING_FAST,
    OMEGA_METROID_IDLE_MOUTH_STILL,
    OMEGA_METROID_IDLE_MOUTH_MOVING_SLOW
};

#define OMEGA_METROID_SWIPE_SA_X_TIMER work0
#define OMEGA_METROID_BACKWARD_STEPS work0

#define OMEGA_METROID_TIMER work1
#define OMEGA_METROID_SWIPE_COUNT work1

#define OMEGA_METROID_HUSK_SLOT work2
#define OMEGA_METROID_SA_X_SLOT work2
#define OMEGA_METROID_FLASH_TIMER work2

#define OMEGA_METROID_X_SPEED work3

#define OMEGA_METROID_JUMP_Y_SPEED_IDX work4
#define OMEGA_METROID_FIRST_JUMP_FLAG work4

#define OMEGA_METROID_HEART_PAL_TIMER rotation
#define OMEGA_METROID_RIGHT_CLAW_SLOT numberOfXToForm

#define OMEGA_METROID_HEALTH_STAGE gBossWork1
#define OMEGA_METROID_HEALTH_STAGE_DAMAGE gBossWork5


/**
 * @brief 53d38 | 68 | Syncs all the parts of Omega Metroid
 *
 */
void OmegaMetroidSyncSubSprites(void)
{
    MultiSpriteDataInfo_T msdi;
    u16 oamIdx;

    msdi = gSubSpriteData1.pMultiOam[gSubSpriteData1.currentAnimationFrame].pData;
    oamIdx = msdi[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX];
    
    if (gCurrentSprite.pOam != sOmegaMetroidFrameDataPointers[oamIdx])
    {
        gCurrentSprite.pOam = sOmegaMetroidFrameDataPointers[oamIdx];
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }

    gCurrentSprite.yPosition = gSubSpriteData1.yPosition +
        msdi[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET];
    gCurrentSprite.xPosition = gSubSpriteData1.xPosition +
        msdi[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_X_OFFSET];
}

/**
 * @brief 53da0 | 5c | Sets the draw order for Omega Metroid parts
 *
 */
void OmegaMetroidPartSetDrawOrder(void)
{
    switch (gCurrentSprite.roomSlot)
    {
        case OMEGA_METROID_PART_HEAD:
        case OMEGA_METROID_PART_LEFT_ARM:
        case OMEGA_METROID_PART_LEFT_LEG:
            gCurrentSprite.drawOrder = 3;
            break;

        case OMEGA_METROID_PART_RIGHT_CLAW:
            gCurrentSprite.drawOrder = 5;
            break;

        case OMEGA_METROID_PART_RIGHT_ARM:
        case OMEGA_METROID_PART_TAIL:
        case OMEGA_METROID_PART_RIGHT_LEG:
            gCurrentSprite.drawOrder = 12;
            break;
    }
}

/**
 * @brief 53dfc | 2c | Sets the draw order for Omega Metroid parts during the SA-X cutscene
 *
 */
void OmegaMetroidPartSetDrawOrder_SaXCutscene(void)
{
    switch (gCurrentSprite.roomSlot)
    {
        case OMEGA_METROID_PART_HEAD:
        case OMEGA_METROID_PART_LEFT_ARM:
        case OMEGA_METROID_PART_LEFT_LEG:
            gCurrentSprite.drawOrder = 11;
            break;

        case OMEGA_METROID_PART_RIGHT_ARM:
        case OMEGA_METROID_PART_RIGHT_CLAW:
        case OMEGA_METROID_PART_TAIL:
        case OMEGA_METROID_PART_RIGHT_LEG:
            gCurrentSprite.drawOrder = 13;
            break;
    }
}

/**
 * @brief 53e28 | a4 | Updates Omega Metroid's palette based on its health
 *
 */
void OmegaMetroidUpdatePalette(void)
{
    bools32 updatePalette;
    u16 health;
    u16 maxHealth;
    const u16* pPalette;

    updatePalette = FALSE;
    health = gCurrentSprite.health;
    maxHealth = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    
    switch (OMEGA_METROID_HEALTH_STAGE)
    {
        case 0:
            if (health <= maxHealth * 2 / 3)
            {
                pPalette = sOmegaMetroidPal + PAL_ROW * 1;
                OMEGA_METROID_HEALTH_STAGE = 1;
                updatePalette = TRUE;
            }
            break;

        case 1:
            if (health <= maxHealth / 3)
            {
                pPalette = sOmegaMetroidPal + PAL_ROW * 2;
                OMEGA_METROID_HEALTH_STAGE = 2;
                updatePalette = TRUE;
            }
            break;
    }

    if (updatePalette)
    {
        DMA3_COPY_16(pPalette, PALRAM_OBJ + PAL_ROW_SIZE * 10, 11);
        DMA3_COPY_16(pPalette, PALRAM_OBJ + PAL_ROW_SIZE * 13, 11);
        DMA3_COPY_16(pPalette, PALRAM_OBJ + PAL_ROW_SIZE * 14, 11);
    }
}

/**
 * @brief 53ecc | dc | Handles the SA-X's ice beam collision with Omega Metroid
 *
 */
void OmegaMetroidSaXIceBeamCollision(void)
{
    u16 spriteY;
    u16 spriteX;
    u16 spriteTop;
    u16 spriteBottom;
    u16 spriteLeft;
    u16 spriteRight;

    u8 i;
    u16 beamY;
    u16 beamX;
    u16 beamTop;
    u16 beamBottom;
    u16 beamLeft;
    u16 beamRight;

    spriteY = gCurrentSprite.yPosition;
    spriteX = gCurrentSprite.xPosition;
    spriteTop = spriteY + gCurrentSprite.hitboxTop;
    spriteBottom = spriteY + gCurrentSprite.hitboxBottom;
    spriteLeft = spriteX + gCurrentSprite.hitboxLeft;
    spriteRight = spriteX + gCurrentSprite.hitboxRight;

    for (i = 0; i < MAX_AMOUNT_OF_SPRITES; i++)
    {
        if (!(gSpriteData[i].status & SPRITE_STATUS_EXISTS))
            continue;

        if (!(gSpriteData[i].properties & SP_SECONDARY_SPRITE))
            continue;

        if (gSpriteData[i].spriteId != SSPRITE_SA_X_ICE_BEAM)
            continue;

        beamY = gSpriteData[i].yPosition;
        beamX = gSpriteData[i].xPosition;
        beamTop = beamY + gSpriteData[i].hitboxTop;
        beamBottom = beamY + gSpriteData[i].hitboxBottom;
        beamLeft = beamX + gSpriteData[i].hitboxLeft;
        beamRight = beamX + gSpriteData[i].hitboxRight;

        if (SpriteUtilCheckObjectsTouching(
            spriteTop, spriteBottom, spriteLeft, spriteRight,
            beamTop, beamBottom, beamLeft, beamRight))
        {
            gSpriteData[i].status = 0;
            ProjectileRandomSpriteDebris(DEBRIS_CLOUD_TYPE_ICE, 0x11, beamY, beamX);
            break;
        }
    }
}

/**
 * @brief 53fa8 | 4c | Updates Omega Metroid's heart palette
 *
 */
void OmegaMetroidUpdateHeartPalette(void)
{
    if (gCurrentSprite.health > 0)
    {
        gCurrentSprite.OMEGA_METROID_HEART_PAL_TIMER++;

        if (gCurrentSprite.OMEGA_METROID_HEART_PAL_TIMER == CONVERT_SECONDS(28/30.f))
        {
            gCurrentSprite.OMEGA_METROID_HEART_PAL_TIMER = 1;
            gCurrentSprite.paletteRow = 0;
        }
        else if (gCurrentSprite.OMEGA_METROID_HEART_PAL_TIMER == CONVERT_SECONDS(7/30.f))
        {
            gCurrentSprite.paletteRow = 3;
        }
        else if (gCurrentSprite.OMEGA_METROID_HEART_PAL_TIMER == CONVERT_SECONDS(14/30.f))
        {
            gCurrentSprite.paletteRow = 0;
        }
        else if (gCurrentSprite.OMEGA_METROID_HEART_PAL_TIMER == CONVERT_SECONDS(21/30.f))
        {
            gCurrentSprite.paletteRow = 4;
        }
    }
}

/**
 * @brief 53ff4 | bc | Updates Omega Metroid's health threshold
 *
 */
void OmegaMetroidUpdateHealthThreshold(void)
{
    u8 flashTimer;
    u16 health;

    if (EventCheckAfter_IceBeamRecovered())
    {
        flashTimer = gCurrentSprite.invincibilityStunFlashTimer & 0x7F;
        if (flashTimer == 16)
            SoundPlayNotAlreadyPlaying(SOUND_222);
        else if (flashTimer == 14)
            SoundPlayNotAlreadyPlaying(SOUND_21B);

        // Compare current health to previous health
        health = gCurrentSprite.health;
        if (health == 0 && gSubSpriteData1.health > 0)
        {
            gCurrentSprite.paletteRow = 0;
            gCurrentSprite.pose = OMEGA_METROID_POSE_WALKING_BACKWARD_INIT;
            OMEGA_METROID_HEALTH_STAGE_DAMAGE = 0;
            EventCheckAdvance(EVENT_OMEGA_METROID_DEFEATED);
            ParticleSet(gCurrentSprite.yPosition, gCurrentSprite.xPosition, PE_0x3A);
        }
        else
        {
            OMEGA_METROID_HEALTH_STAGE_DAMAGE += gSubSpriteData1.health - gCurrentSprite.health;
            if (OMEGA_METROID_HEALTH_STAGE_DAMAGE > 300)
            {
#ifdef BUGFIX
                if (gCurrentSprite.pose != OMEGA_METROID_POSE_JUMPING)
#endif // BUGFIX
                {
                    // BUG: If this happens while jumping, it will be standing midair
                    gCurrentSprite.pose = OMEGA_METROID_POSE_WALKING_BACKWARD_INIT;
                }
                OMEGA_METROID_HEALTH_STAGE_DAMAGE = 0;
            }
        }

        gSubSpriteData1.health = gCurrentSprite.health;
    }
}

/**
 * @brief 540b0 | 28 | Checks if Samus is crouched in the corner with low health
 *
 * @return bool u8, Samus crouched in the corner with low health
 */
boolu8 OmegaMetroidCheckSamusOnLowHealth(void)
{
    if (gSamusData.pose == SPOSE_HIT_BY_OMEGA_METROID && gEquipment.currentEnergy < 99)
        return TRUE;
    else
        return FALSE;
}

/**
 * @brief 540d8 | 48 | Updates Omega Metroid's palette to flash during the SA-X cutscene
 *
 */
void OmegaMetroidBodyFlashing_SaXCutscene(void)
{
    u8 timer;

    gCurrentSprite.OMEGA_METROID_TIMER++;
    timer = gCurrentSprite.OMEGA_METROID_TIMER;
    if (!(timer & 3))
    {
        if (timer & 4)
            gCurrentSprite.paletteRow = 13 - (gCurrentSprite.spritesetGfxSlot + gCurrentSprite.frozenPaletteRowOffset);
        else
            gCurrentSprite.paletteRow = 0;
    }

    gCurrentSprite.OMEGA_METROID_HEART_PAL_TIMER = 0;
}

/**
 * @brief 54120 | 48 | Updates Omega Metroid's palette to flash
 *
 */
void OmegaMetroidBodyFlashing(void)
{
    u8 timer;

    gCurrentSprite.OMEGA_METROID_FLASH_TIMER++;
    timer = gCurrentSprite.OMEGA_METROID_FLASH_TIMER;
    if (!(timer & 3))
    {
        if (timer & 4)
            gCurrentSprite.paletteRow = 13 - (gCurrentSprite.spritesetGfxSlot + gCurrentSprite.frozenPaletteRowOffset);
        else
            gCurrentSprite.paletteRow = 0;
    }

    gCurrentSprite.OMEGA_METROID_HEART_PAL_TIMER = 0;
}

/**
 * @brief 54168 | 34 | Checks if Samus is nearby in front of Omega Metroid
 *
 * @return u8 bool, Samus nearby in front of Omega Metroid
 */
boolu8 OmegaMetroidCheckSamusInFrontRange(void)
{
    if (SpriteUtilCheckSamusNearSpriteLeftRight(
        BLOCK_TO_SUB_PIXEL(7), BLOCK_TO_SUB_PIXEL(5.9375)) != NSLR_OUT_OF_RANGE &&
        gSubSpriteData1.xPosition > gSamusData.xPosition)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/**
 * @brief 5419c | 2c | Checks if Omega Metroid is behind a trigger on the right side of the screen
 *
 * @return u8 bool, Omega Metroid behind trigger
 */
boolu8 OmegaMetroidCheckBehindRightTrigger(void)
{
    u16 screenX;

    screenX = SUB_PIXEL_TO_PIXEL(gSubSpriteData1.xPosition) - SUB_PIXEL_TO_PIXEL(gBg1XPosition);
    
    if (screenX > 204)
        return TRUE;
    else
        return FALSE;
}

/**
 * @brief 541c8 | 2c | Checks if Omega Metroid is in front of a trigger in the middle of the screen
 *
 * @return u8 bool, Omega Metroid in front of trigger
 */
boolu8 OmegaMetroidCheckInFrontOfMiddleTrigger(void)
{
    u16 screenX;

    screenX = SUB_PIXEL_TO_PIXEL(gSubSpriteData1.xPosition) - SUB_PIXEL_TO_PIXEL(gBg1XPosition);
    
    if (screenX <= SCREEN_X_MIDDLE)
        return TRUE;
    else
        return FALSE;
}

/**
 * @brief 541f4 | 2c | Checks if Omega Metroid is in front of a trigger on the left side of the screen
 *
 * @return u8 bool, Omega Metroid in front of trigger
 */
boolu8 OmegaMetroidCheckInFrontOfLeftTrigger(void)
{
    u16 screenX;

    screenX = SUB_PIXEL_TO_PIXEL(gSubSpriteData1.xPosition) - SUB_PIXEL_TO_PIXEL(gBg1XPosition);
    
    if (screenX <= 80)
        return TRUE;
    else
        return FALSE;
}

/**
 * @brief 54220 | 54 | Moves Omega Metroid horizontally
 *
 * @return u8 bool, Omega Metroid reached trigger
 */
boolu8 OmegaMetroidXMovement(void)
{
    u16 xSpeed;
    boolu8 reachedTrigger;

    xSpeed = gCurrentSprite.OMEGA_METROID_X_SPEED;
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        reachedTrigger = OmegaMetroidCheckBehindRightTrigger();
        if (!reachedTrigger)
            gSubSpriteData1.xPosition += xSpeed;
    }
    else
    {
        reachedTrigger = OmegaMetroidCheckInFrontOfLeftTrigger();
        if (!reachedTrigger)
            gSubSpriteData1.xPosition -= xSpeed;
    }
    
    return reachedTrigger;
}

/**
 * @brief 54274 | 94 | Handles Omega Metroid moving backward
 *
 * @return u8 bool, Omega Metroid reached trigger
 */
boolu8 OmegaMetroidBackwardMovement(void)
{
    u8 xSpeed;

    switch (gSubSpriteData1.currentAnimationFrame)
    {
        case 1:
        case 5:
            xSpeed = 2;
            break;

        case 2:
        case 6:
            xSpeed = 3;
            break;

        case 3:
            if (gSubSpriteData1.animationDurationCounter == 1)
            {
                ScreenShakeStartVertical(CONVERT_SECONDS(2/3.f), 0x80 | 1);
                SoundPlay(SOUND_21D);
            }

        case 7:
            xSpeed = 4;
            break;

        case 8:
            if (gSubSpriteData1.animationDurationCounter == 1)
            {
                ScreenShakeStartVertical(CONVERT_SECONDS(2/3.f), 0x80 | 1);
                SoundPlay(SOUND_21D);
            }

        default:
            xSpeed = 0;
            break;
    }

    gCurrentSprite.OMEGA_METROID_X_SPEED = xSpeed;

    return OmegaMetroidXMovement();
}

/**
 * @brief 54308 | b8 | Handles Omega Metroid moving forward
 *
 * @return u8 bool, Omega Metroid should stop
 */
boolu8 OmegaMetroidForwardMovement(void)
{
    u16 xSpeed;
    boolu8 stop;

    switch (gSubSpriteData1.currentAnimationFrame)
    {
        case 1:
            if (gSubSpriteData1.animationDurationCounter == 1)
            {
                ScreenShakeStartVertical(CONVERT_SECONDS(2/3.f), 0x80 | 1);
                SoundPlay(SOUND_21D);
            }
        
        case 0:
        case 4:
            xSpeed = 2;
            break;

        case 5:
            xSpeed = 3;
            break;

        case 6:
            xSpeed = 4;
            break;

         case 7:
            if (gSubSpriteData1.animationDurationCounter == 1)
            {
                ScreenShakeStartVertical(CONVERT_SECONDS(2/3.f), 0x80 | 1);
                SoundPlay(SOUND_21D);
            }

        default:
            xSpeed = 0;
            break;
    }

    if (gCurrentSprite.pose != OMEGA_METROID_POSE_WALKING && xSpeed > 0)
        xSpeed--;
    gCurrentSprite.OMEGA_METROID_X_SPEED = xSpeed;

    stop = OmegaMetroidXMovement();
    if (!stop)
        stop = OmegaMetroidCheckSamusInFrontRange();

    return stop;
}

/**
 * @brief 543c0 | 44 | Handles Omega Metroid starting to walk
 *
 * @return u8 bool, Omega Metroid should stop
 */
boolu8 OmegaMetroidStartWalking(void)
{
    u8 xSpeed;
    boolu8 stop;

    if (gCurrentSprite.pose != OMEGA_METROID_POSE_WALKING)
        xSpeed = 0;
    else
        xSpeed = gSubSpriteData1.currentAnimationFrame > 0 ? 1 : 0;
    gCurrentSprite.OMEGA_METROID_X_SPEED = xSpeed;

    stop = OmegaMetroidXMovement();
    if (!stop)
        stop = OmegaMetroidCheckSamusInFrontRange();

    return stop;
}

/**
 * @brief 54404 | 34 | Handles Omega Metroid's standing movement
 *
 * @return u8 Result (2 if Samus in range, 1 if reached trigger, 0 otherwise)
 */
u8 OmegaMetroidStandingMovement(void)
{
    u8 result;

    gCurrentSprite.OMEGA_METROID_X_SPEED = 1;
    
    result = 0;
    if (OmegaMetroidCheckSamusInFrontRange())
        result = 2;
    else if (OmegaMetroidXMovement())
        result = 1;

    return result;
}

/**
 * @brief 54438 | 1d8 | Initializes Omega Metroid
 *
 */
void OmegaMetroidInit(void)
{
    u16 xPosition;
    u16 yPosition;
    u16 health;

    OMEGA_METROID_HEALTH_STAGE = 0;

    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;
    gCurrentSprite.workY = yPosition;
    gCurrentSprite.workX = xPosition;
    gAbilityRestingYPosition = yPosition - BLOCK_TO_SUB_PIXEL(6);
    gAbilityRestingXPosition = xPosition - BLOCK_TO_SUB_PIXEL(9);
    gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(7);
    gSubSpriteData1.yPosition = gCurrentSprite.yPosition;
    gSubSpriteData1.xPosition = gCurrentSprite.xPosition;

    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(2.5f);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(2.5f);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(2);

    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(1.75f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(1);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(1.5f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(1);

    gCurrentSprite.drawOrder = 4;
    gCurrentSprite.roomSlot = OMEGA_METROID_PART_TORSO;
    health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.health = health;
    gSubSpriteData1.health = health;
    OMEGA_METROID_HEALTH_STAGE_DAMAGE = 0;

    gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_Jumping;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    gCurrentSprite.samusCollision = SSC_OMEGA_METROID_BODY;
    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
    gCurrentSprite.pose = OMEGA_METROID_POSE_WAITING_TO_APPEAR;
    gCurrentSprite.OMEGA_METROID_FIRST_JUMP_FLAG = TRUE;
    gCurrentSprite.OMEGA_METROID_TIMER = CONVERT_SECONDS(.5f);
    gCurrentSprite.OMEGA_METROID_IDLE_ANIM = OMEGA_METROID_IDLE_MOUTH_MOVING_FAST;
    gCurrentSprite.OMEGA_METROID_HEART_PAL_TIMER = 0;

    SpriteSpawnSecondary(SSPRITE_OMEGA_METROID_PART, OMEGA_METROID_PART_HEAD, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_OMEGA_METROID_PART, OMEGA_METROID_PART_LEFT_ARM, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_OMEGA_METROID_PART, OMEGA_METROID_PART_LEFT_LEG, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_OMEGA_METROID_PART, OMEGA_METROID_PART_RIGHT_ARM, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
    gCurrentSprite.OMEGA_METROID_RIGHT_CLAW_SLOT = SpriteSpawnSecondary(SSPRITE_OMEGA_METROID_PART, OMEGA_METROID_PART_RIGHT_CLAW,
        gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_OMEGA_METROID_PART, OMEGA_METROID_PART_TAIL, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_OMEGA_METROID_PART, OMEGA_METROID_PART_RIGHT_LEG, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);

    gCurrentSprite.OMEGA_METROID_HUSK_SLOT = SpriteSpawnNewXParasite(PSPRITE_OMEGA_METROID_HUSK, 0, 0,
        gCurrentSprite.primarySpriteRamSlot, SSP_UNINFECTED_OR_BOSS, yPosition, xPosition, 0);
}

/**
 * @brief 54610 | 40 | Handles Omega Metroid waiting to appear
 *
 */
void OmegaMetroidWaitingToAppear(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    if (!gCurrentSprite.OMEGA_METROID_FIRST_JUMP_FLAG)
    {
        gCurrentSprite.OMEGA_METROID_TIMER--;
        if (gCurrentSprite.OMEGA_METROID_TIMER == 0)
        {
            gCurrentSprite.pose = OMEGA_METROID_POSE_FIRST_JUMP;
            gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
        }
    }
}

/**
 * @brief 54650 | c8 | Handles Omega Metroid's first jump
 *
 */
void OmegaMetroidFirstJump(void)
{
    u8 index;
    s16 ySpeed;

    gSubSpriteData1.xPosition -= BLOCK_TO_SUB_PIXEL(.25f);

    index = gCurrentSprite.OMEGA_METROID_JUMP_Y_SPEED_IDX;
    ySpeed = sOmegaMetroidFirstJumpYSpeeds[index];
    if (ySpeed == SHORT_MAX)
    {
        ySpeed = sOmegaMetroidFirstJumpYSpeeds[index - 1];
        gSubSpriteData1.yPosition += ySpeed;
    }
    else
    {
        gCurrentSprite.OMEGA_METROID_JUMP_Y_SPEED_IDX = index + 1;
        gSubSpriteData1.yPosition += ySpeed;
    }

    if (gSubSpriteData1.yPosition > gCurrentSprite.workY)
    {
        gSubSpriteData1.yPosition = gCurrentSprite.workY;
        gCurrentSprite.pose = OMEGA_METROID_POSE_LANDING_FROM_FIRST_JUMP;
        gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_Landing;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;
        ScreenShakeStartVertical(CONVERT_SECONDS(1), 0x80 | 1);
        SoundPlay(SOUND_21F);
    }
    else if (gSubSpriteData1.yPosition > gCurrentSprite.workY - BLOCK_TO_SUB_PIXEL(1.875f) &&
        gCurrentSprite.OMEGA_METROID_JUMP_Y_SPEED_IDX > 16)
    {
        if (gSpriteData[gCurrentSprite.OMEGA_METROID_HUSK_SLOT].pose == 8) // TODO: OmegaMetroidHuskPose enum
            gSpriteData[gCurrentSprite.OMEGA_METROID_HUSK_SLOT].pose = 0x17;
    }
}

/**
 * @brief 54718 | 30 | Handles Omega Metroid landing from first jump
 *
 */
void OmegaMetroidLandingFromFirstJump(void)
{
    if (SpriteUtilHasSubSprite1AnimationEnded())
    {
        gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_AboutToScream;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;
        gCurrentSprite.pose = OMEGA_METROID_POSE_LANDED_AFTER_FIRST_JUMP;
    }
}

/**
 * @brief 54748 | 40 | Handles Omega Metroid after landing from first jump
 *
 */
void OmegaMetroidLandedAfterFirstJump(void)
{
    if (SpriteUtilHasSubSprite1AnimationEnded())
    {
        gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_Screaming;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;
        gCurrentSprite.pose = OMEGA_METROID_POSE_SCREAMING_AFTER_FIRST_JUMP;
        gCurrentSprite.OMEGA_METROID_TIMER = CONVERT_SECONDS(1 + 2/3.f);

        SoundPlay(SOUND_219);
    }
}

/**
 * @brief 54788 | 38 | Handles Omega Metroid screaming after first jump
 *
 */
void OmegaMetroidScreamingAfterFirstJump(void)
{
    gCurrentSprite.OMEGA_METROID_TIMER--;
    if (gCurrentSprite.OMEGA_METROID_TIMER == 0)
    {
        gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_DoneScreaming;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;
        gCurrentSprite.pose = OMEGA_METROID_POSE_FINISHED_SCREAMING_AFTER_FIRST_JUMP;
    }
}

/**
 * @brief 547c0 | 40 | Handles Omega Metroid after screaming after first jump
 *
 */
void OmegaMetroidFinishedScreamingAfterFirstJump(void)
{
    if (SpriteUtilHasSubSprite1AnimationNearlyEnded())
    {
        SpriteUtilMakeSpriteFaceSamusDirection();

        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            gCurrentSprite.pose = OMEGA_METROID_POSE_VERTICAL_JUMP_INIT;
        }
        else
        {
            gCurrentSprite.pose = OMEGA_METROID_POSE_IDLE_INIT;
            gCurrentSprite.OMEGA_METROID_IDLE_ANIM = OMEGA_METROID_IDLE_MOUTH_MOVING_FAST;
        }
    }
}

/**
 * @brief 54800 | 30 | Initializes Omega Metroid to do a jump warning
 *
 */
void OmegaMetroidJumpWarningInit(void)
{
    gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_JumpWarning;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = OMEGA_METROID_POSE_JUMP_WARNING;

    SoundPlay(SOUND_21E);
}

/**
 * @brief 54830 | 38 | Handles Omega Metroid doing a jump warning
 *
 */
void OmegaMetroidJumpWarning(void)
{
    if (SpriteUtilHasSubSprite1AnimationEnded())
    {
        gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_Jumping;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;
        gCurrentSprite.OMEGA_METROID_JUMP_Y_SPEED_IDX = 0;
        gCurrentSprite.pose = OMEGA_METROID_POSE_JUMPING;
    }
}

/**
 * @brief 54868 | 54 | Handles Omega Metroid jumping
 *
 */
void OmegaMetroidJumping(void)
{
    u8 index;
    s16 ySpeed;

    index = gCurrentSprite.OMEGA_METROID_JUMP_Y_SPEED_IDX;
    ySpeed = sOmegaMetroidJumpingYSpeeds[index];
    if (ySpeed == SHORT_MAX)
    {
        gCurrentSprite.pose = OMEGA_METROID_POSE_FALLING;
        gCurrentSprite.OMEGA_METROID_JUMP_Y_SPEED_IDX = 0;

    }
    else
    {
        gCurrentSprite.OMEGA_METROID_JUMP_Y_SPEED_IDX++;
        gSubSpriteData1.yPosition += ySpeed;
        OmegaMetroidXMovement();
    }
}

/**
 * @brief 548bc | 98 | Handles Omega Metroid falling
 *
 */
void OmegaMetroidFalling(void)
{
    u8 index;
    s16 ySpeed;
    u32 blockTop;

    index = gCurrentSprite.OMEGA_METROID_JUMP_Y_SPEED_IDX;
    ySpeed = sOmegaMetroidFallingYSpeeds[index];
    if (ySpeed == SHORT_MAX)
    {
        do {
        ySpeed = sOmegaMetroidFallingYSpeeds[index - 1];
        gSubSpriteData1.yPosition += ySpeed;
        } while (0);
    }
    else
    {
        gCurrentSprite.OMEGA_METROID_JUMP_Y_SPEED_IDX++;
        gSubSpriteData1.yPosition += ySpeed;
    }

    blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gSubSpriteData1.yPosition, gSubSpriteData1.xPosition);
    if (gPreviousVerticalCollisionCheck & 0xF)
    {
        gSubSpriteData1.yPosition = blockTop;
        gCurrentSprite.pose = OMEGA_METROID_POSE_LANDING_INIT;
        ScreenShakeStartVertical(CONVERT_SECONDS(1), 0x80 | 1);
        SoundPlay(SOUND_21F);
    }

    OmegaMetroidXMovement();
}

/**
 * @brief 54954 | 24 | Initializes Omega Metroid to land
 *
 */
void OmegaMetroidLandingInit(void)
{
    gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_Landing;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = OMEGA_METROID_POSE_LANDING;
}

/**
 * @brief 54978 | 6c | Handles Omega Metroid landing
 *
 */
void OmegaMetroidLanding(void)
{
    if (SpriteUtilHasSubSprite1AnimationNearlyEnded())
    {
        if (!EventCheckAfter_SaXKilledByOmega() && OmegaMetroidCheckSamusOnLowHealth())
        {
            gCurrentSprite.pose = OMEGA_METROID_POSE_WAITING_FOR_SA_X_INIT;
            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
        }
        else
        {
            SpriteUtilMakeSpriteFaceSamusDirection();

            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                gCurrentSprite.pose = OMEGA_METROID_POSE_VERTICAL_JUMP_INIT;
            }
            else
            {
                gCurrentSprite.pose = OMEGA_METROID_POSE_IDLE_INIT;
                gCurrentSprite.OMEGA_METROID_IDLE_ANIM = OMEGA_METROID_IDLE_MOUTH_MOVING_FAST;
            }
        }
    }
}

/**
 * @brief 549e4 | 58 | Initializes Omega Metroid to be idle
 *
 */
void OmegaMetroidIdleInit(void)
{
    if (gCurrentSprite.OMEGA_METROID_IDLE_ANIM == OMEGA_METROID_IDLE_MOUTH_STILL)
        gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_Idle_MouthStill;
    else if (gCurrentSprite.OMEGA_METROID_IDLE_ANIM == OMEGA_METROID_IDLE_MOUTH_MOVING_SLOW)
        gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_Idle_MouthMovingSlow;
    else // OMEGA_METROID_IDLE_MOUTH_MOVING_FAST
        gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_Idle_MouthMovingFast;
    
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = OMEGA_METROID_POSE_IDLE;
}

/**
 * @brief 54a3c | bc | Handles Omega Metroid being idle
 *
 */
void OmegaMetroidIdle(void)
{
    if (gCurrentSprite.OMEGA_METROID_IDLE_ANIM == OMEGA_METROID_IDLE_MOUTH_MOVING_FAST &&
        gSubSpriteData1.currentAnimationFrame == 0 && gSubSpriteData1.animationDurationCounter == 1)
    {
        SoundPlay(SOUND_223);
    }

    if (SpriteUtilHasSubSprite1AnimationNearlyEnded())
    {
        if (!EventCheckAfter_SaXKilledByOmega() && OmegaMetroidCheckSamusOnLowHealth())
        {
            gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
            gCurrentSprite.pose = OMEGA_METROID_POSE_JUMP_WARNING_INIT;
            gCurrentSprite.OMEGA_METROID_X_SPEED = OMEGA_METROID_JUMP_X_SPEED;
        }
        else
        {
            SpriteUtilMakeSpriteFaceSamusDirection();

            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                gCurrentSprite.pose = OMEGA_METROID_POSE_JUMP_WARNING_INIT;
                gCurrentSprite.OMEGA_METROID_X_SPEED = OMEGA_METROID_JUMP_X_SPEED;
            }
            else if (OmegaMetroidCheckSamusInFrontRange())
            {
                gCurrentSprite.pose = OMEGA_METROID_POSE_SWIPING_INIT;
            }
            else if (EventCheckAfter_SaXKilledByOmega())
            {
                gCurrentSprite.pose = OMEGA_METROID_POSE_WALKING_INIT;
            }
            else
            {
                gCurrentSprite.pose = OMEGA_METROID_POSE_WALKING_BEFORE_SA_X_INIT;
            }
        }
    }
}

/**
 * @brief 54af8 | 28 | Initializes Omega Metroid to walking before SA-X
 *
 */
void OmegaMetroidWalkingBeforeSaXInit(void)
{
    gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_Walking_Slow;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = OMEGA_METROID_POSE_WALKING_BEFORE_SA_X;
    gCurrentSprite.OMEGA_METROID_WALK_ACTION = OMEGA_METROID_WALK_FINISH;
}

/**
 * @brief 54b20 | 98 | Handles Omega Metroid walking before SA-X
 *
 */
void OmegaMetroidWalkingBeforeSaX(void)
{
    u8 moveResult;

    gCurrentSprite.OMEGA_METROID_X_SPEED = 0;

    if (gCurrentSprite.OMEGA_METROID_WALK_ACTION == OMEGA_METROID_WALK_FINISH)
    {
        OmegaMetroidForwardMovement();

        if (SpriteUtilHasSubSprite1AnimationEnded())
        {
            gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_DoneWalking_Slow;
            gSubSpriteData1.animationDurationCounter = 0;
            gSubSpriteData1.currentAnimationFrame = 0;
            gCurrentSprite.OMEGA_METROID_WALK_ACTION = OMEGA_METROID_WALK_STOP;
        }
    }
    else
    {
        moveResult = OmegaMetroidStandingMovement();

        if (SpriteUtilHasSubSprite1AnimationNearlyEnded())
        {
            if (moveResult == 2)
            {
                gCurrentSprite.pose = OMEGA_METROID_POSE_SWIPING_INIT;
            }
            else if (moveResult == 1)
            {
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = OMEGA_METROID_POSE_JUMP_WARNING_INIT;
                gCurrentSprite.OMEGA_METROID_X_SPEED = OMEGA_METROID_JUMP_X_SPEED;
            }
            else
            {
                gCurrentSprite.pose = OMEGA_METROID_POSE_IDLE_INIT;
                gCurrentSprite.OMEGA_METROID_IDLE_ANIM = OMEGA_METROID_IDLE_MOUTH_MOVING_FAST;
            }
        }
    }
}

/**
 * @brief 54bb8 | 2c | Initializes Omega Metroid to slow walk
 *
 */
void OmegaMetroidSlowWalkingInit(void)
{
    gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_Walking_Slow;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = OMEGA_METROID_POSE_SLOW_WALKING;
    gCurrentSprite.OMEGA_METROID_WALK_ACTION = OMEGA_METROID_WALK_FORWARD;
}

/**
 * @brief 54be4 | 124 | Handles Omega Metroid slow walking
 *
 */
void OmegaMetroidSlowWalking()
{
    u8 stop;

    gCurrentSprite.OMEGA_METROID_X_SPEED = 0;

    switch (gCurrentSprite.OMEGA_METROID_WALK_ACTION)
    {
        case OMEGA_METROID_WALK_START:
            stop = OmegaMetroidStartWalking();

            if (SpriteUtilHasSubSprite1AnimationEnded())
            {
                gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_Walking_Slow;
                gSubSpriteData1.animationDurationCounter = 0;
                gSubSpriteData1.currentAnimationFrame = 0;

                if (stop)
                    gCurrentSprite.OMEGA_METROID_WALK_ACTION = OMEGA_METROID_WALK_FINISH;
                else
                    gCurrentSprite.OMEGA_METROID_WALK_ACTION = OMEGA_METROID_WALK_FORWARD;
            }
            break;
    
        case OMEGA_METROID_WALK_FORWARD:
            stop = OmegaMetroidForwardMovement();

            if (SpriteUtilHasSubSprite1AnimationEnded())
            {
                if (stop)
                {
                    gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_DoneWalking_Slow;
                    gCurrentSprite.OMEGA_METROID_WALK_ACTION = OMEGA_METROID_WALK_STOP;
                }
                else
                {
                    gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_WalkAgain_Slow;
                    gCurrentSprite.OMEGA_METROID_WALK_ACTION = OMEGA_METROID_WALK_START;
                }

                gSubSpriteData1.animationDurationCounter = 0;
                gSubSpriteData1.currentAnimationFrame = 0;
            }
            break;
    
        case OMEGA_METROID_WALK_FINISH:
            OmegaMetroidForwardMovement();

            if (SpriteUtilHasSubSprite1AnimationEnded())
            {
                gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_DoneWalking_Slow;
                gSubSpriteData1.animationDurationCounter = 0;
                gSubSpriteData1.currentAnimationFrame = 0;
                gCurrentSprite.OMEGA_METROID_WALK_ACTION = OMEGA_METROID_WALK_STOP;
            }
            break;
    
        case OMEGA_METROID_WALK_STOP:
            stop = OmegaMetroidStandingMovement();

            if (SpriteUtilHasSubSprite1AnimationNearlyEnded())
            {
                if (stop == 2)
                {
                    gCurrentSprite.pose = OMEGA_METROID_POSE_SWIPING_INIT;
                }
                else if (stop == 1)
                {
                    gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                    gCurrentSprite.pose = OMEGA_METROID_POSE_JUMP_WARNING_INIT;
                    gCurrentSprite.OMEGA_METROID_X_SPEED = OMEGA_METROID_JUMP_X_SPEED;
                }
                else
                {
                    gCurrentSprite.pose = OMEGA_METROID_POSE_IDLE_INIT;
                    gCurrentSprite.OMEGA_METROID_IDLE_ANIM = OMEGA_METROID_IDLE_MOUTH_MOVING_FAST;
                }
            }
            break;
    }
}

/**
 * @brief 54d08 | 2c | Initializes Omega Metroid to walk
 *
 */
void OmegaMetroidWalkingInit(void)
{
    gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_Walking;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = OMEGA_METROID_POSE_WALKING;
    gCurrentSprite.OMEGA_METROID_WALK_ACTION = OMEGA_METROID_WALK_FORWARD;
}

/**
 * @brief 54d34 | 124 | Handles Omega Metroid walking
 *
 */
void OmegaMetroidWalking()
{
    u8 stop;

    gCurrentSprite.OMEGA_METROID_X_SPEED = 0;

    switch (gCurrentSprite.OMEGA_METROID_WALK_ACTION)
    {
        case OMEGA_METROID_WALK_START:
            stop = OmegaMetroidStartWalking();

            if (SpriteUtilHasSubSprite1AnimationEnded())
            {
                gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_Walking;
                gSubSpriteData1.animationDurationCounter = 0;
                gSubSpriteData1.currentAnimationFrame = 0;

                if (stop)
                    gCurrentSprite.OMEGA_METROID_WALK_ACTION = OMEGA_METROID_WALK_FINISH;
                else
                    gCurrentSprite.OMEGA_METROID_WALK_ACTION = OMEGA_METROID_WALK_FORWARD;
            }
            break;
    
        case OMEGA_METROID_WALK_FORWARD:
            stop = OmegaMetroidForwardMovement();

            if (SpriteUtilHasSubSprite1AnimationEnded())
            {
                if (stop)
                {
                    gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_DoneWalking;
                    gCurrentSprite.OMEGA_METROID_WALK_ACTION = OMEGA_METROID_WALK_STOP;
                }
                else
                {
                    gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_WalkAgain;
                    gCurrentSprite.OMEGA_METROID_WALK_ACTION = OMEGA_METROID_WALK_START;
                }

                gSubSpriteData1.animationDurationCounter = 0;
                gSubSpriteData1.currentAnimationFrame = 0;
            }
            break;
    
        case OMEGA_METROID_WALK_FINISH:
            OmegaMetroidForwardMovement();

            if (SpriteUtilHasSubSprite1AnimationEnded())
            {
                gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_DoneWalking;
                gSubSpriteData1.animationDurationCounter = 0;
                gSubSpriteData1.currentAnimationFrame = 0;
                gCurrentSprite.OMEGA_METROID_WALK_ACTION = OMEGA_METROID_WALK_STOP;
            }
            break;
    
        case OMEGA_METROID_WALK_STOP:
            stop = OmegaMetroidStandingMovement();

            if (SpriteUtilHasSubSprite1AnimationNearlyEnded())
            {
                if (stop == 2)
                {
                    gCurrentSprite.pose = OMEGA_METROID_POSE_SWIPING_INIT;
                }
                else if (stop == 1)
                {
                    gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                    gCurrentSprite.pose = OMEGA_METROID_POSE_JUMP_WARNING_INIT;
                    gCurrentSprite.OMEGA_METROID_X_SPEED = OMEGA_METROID_JUMP_X_SPEED;
                }
                else
                {
                    gCurrentSprite.pose = OMEGA_METROID_POSE_IDLE_INIT;
                    gCurrentSprite.OMEGA_METROID_IDLE_ANIM = OMEGA_METROID_IDLE_MOUTH_MOVING_FAST;
                }
            }
            break;
    }
}

/**
 * @brief 54e58 | 84 | Initializes Omega Metroid to swipe
 *
 */
void OmegaMetroidSwipingInit(void)
{
    u8 swipeCount;
    u8 slot;

    gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_Swiping;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = OMEGA_METROID_POSE_SWIPING;

    if (EventCheckAfter_SaXKilledByOmega())
    {
        // 1-3 swipes
        swipeCount = gSpriteRandomNumber / 4;
        if (swipeCount == 0)
            swipeCount = 1;

        gCurrentSprite.OMEGA_METROID_SWIPE_COUNT = swipeCount;
    }
    else
    {
        gCurrentSprite.OMEGA_METROID_SWIPE_COUNT = 3;
    }

    slot = gCurrentSprite.OMEGA_METROID_RIGHT_CLAW_SLOT;
    gSpriteData[slot].samusCollision = SSC_OMEGA_METROID_SWIPING;
    gSpriteData[slot].hitboxBottom = BLOCK_TO_SUB_PIXEL(1);
    gSpriteData[slot].hitboxRight = BLOCK_TO_SUB_PIXEL(2.25f);

    SoundPlay(SOUND_220);
}

/**
 * @brief 54edc | 10c | Handles Omega Metroid swiping
 *
 */
void OmegaMetroidSwiping(void)
{
    u8 slot;

    if (SpriteUtilHasSubSprite1AnimationNearlyEnded())
    {
        if (gSubSpriteData1.pMultiOam == sOmegaMetroidMultiOam_Swiping)
            gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_DoneSwiping;

        if (!EventCheckAfter_SaXKilledByOmega() &&
            gEquipment.currentEnergy < 99 && gPoseLock == 0x80)
        {
            gCurrentSprite.OMEGA_METROID_SWIPE_COUNT = 0;
        }

        if (!OmegaMetroidCheckSamusInFrontRange())
            gCurrentSprite.OMEGA_METROID_SWIPE_COUNT = 0;

        if (gCurrentSprite.OMEGA_METROID_SWIPE_COUNT == 0)
        {
            slot = gCurrentSprite.OMEGA_METROID_RIGHT_CLAW_SLOT;
            gSpriteData[slot].samusCollision = SSC_OMEGA_METROID_BODY;
            gSpriteData[slot].hitboxBottom = BLOCK_TO_SUB_PIXEL(.75f);
            gSpriteData[slot].hitboxRight = BLOCK_TO_SUB_PIXEL(1);

            if (OmegaMetroidCheckInFrontOfMiddleTrigger())
            {
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = OMEGA_METROID_POSE_JUMP_WARNING_INIT;
                gCurrentSprite.OMEGA_METROID_X_SPEED = OMEGA_METROID_JUMP_X_SPEED;
            }
            else
            {
                gCurrentSprite.pose = OMEGA_METROID_POSE_IDLE_INIT;
                gCurrentSprite.OMEGA_METROID_IDLE_ANIM = OMEGA_METROID_IDLE_MOUTH_STILL;
            }
        }
    }
    else
    {
        if (gSubSpriteData1.currentAnimationFrame == 0 && gSubSpriteData1.animationDurationCounter == 1)
            gCurrentSprite.OMEGA_METROID_SWIPE_COUNT--;
        else if (gSubSpriteData1.currentAnimationFrame == 2 && gSubSpriteData1.animationDurationCounter == 1)
            SoundPlay(SOUND_221);
    }
}

/**
 * @brief 54fe8 | 34 | Initializes Omega Metroid to do a vertical jump
 *
 */
void OmegaMetroidVerticalJumpInit(void)
{
    gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_Landing;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    gCurrentSprite.pose = OMEGA_METROID_POSE_VERTICAL_JUMP;
    gCurrentSprite.OMEGA_METROID_JUMP_Y_SPEED_IDX = 0;
    gCurrentSprite.samusCollision = SSC_17;
}

/**
 * @brief 5501c | b0 | Handles Omega Metroid doing a vertical jump
 *
 */
void OmegaMetroidVerticalJump(void)
{
    u8 index;
    s16 ySpeed;
    u32 blockTop;

    index = gCurrentSprite.OMEGA_METROID_JUMP_Y_SPEED_IDX;
    ySpeed = sOmegaMetroidVerticalJumpYSpeeds[index];
    if (ySpeed == SHORT_MAX)
    {
        do {
        ySpeed = sOmegaMetroidVerticalJumpYSpeeds[index - 1];
        gSubSpriteData1.yPosition += ySpeed;
        } while (0);
    }
    else
    {
        gCurrentSprite.OMEGA_METROID_JUMP_Y_SPEED_IDX++;
        gSubSpriteData1.yPosition += ySpeed;
    }

    blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gSubSpriteData1.yPosition, gSubSpriteData1.xPosition);
    if (gPreviousVerticalCollisionCheck & 0xF)
    {
        gSubSpriteData1.yPosition = blockTop;
        ScreenShakeStartVertical(CONVERT_SECONDS(1), 0x80 | 1);
        SoundPlay(SOUND_21F);

        if (gCurrentSprite.xPosition < gSamusData.xPosition)
        {
            gCurrentSprite.OMEGA_METROID_JUMP_Y_SPEED_IDX = 0;
        }
        else
        {
            gCurrentSprite.pose = OMEGA_METROID_POSE_LANDING_INIT;
            gCurrentSprite.samusCollision = SSC_OMEGA_METROID_BODY;
        }
    }
}

/**
 * @brief 550cc | 54 | Handles Omega Metroid spawning SA-X
 *
 */
void OmegaMetroidSpawnSaX(void)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.workY - BLOCK_TO_SUB_PIXEL(6);
    xPosition = gCurrentSprite.workX - BLOCK_TO_SUB_PIXEL(14);
    
    gCurrentSprite.OMEGA_METROID_SA_X_SLOT = SpriteSpawnNewXParasite(PSPRITE_ICE_BEAM_ABILITY,
        0, 0, gCurrentSprite.primarySpriteRamSlot, SSP_UNINFECTED_OR_BOSS,
        yPosition, xPosition - BLOCK_TO_SUB_PIXEL(.5f), 0);
}

/**
 * @brief 55120 | 34 | Initializes Omega Metroid to wait for SA-X
 *
 */
void OmegaMetroidWaitingForSaXInit(void)
{
    gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_Idle_MouthMovingFast;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    gCurrentSprite.pose = OMEGA_METROID_POSE_WAITING_FOR_SA_X;
    gCurrentSprite.OMEGA_METROID_POSE_STAGE = OMEGA_METROID_SA_X_STAGE_LOAD_GFX;
    gCurrentSprite.OMEGA_METROID_TIMER = 9;
}

/**
 * @brief 55154 | 204 | Handles Omega Metroid waiting for SA-X
 *
 */
void OmegaMetroidWaitingForSaX(void)
{
    SpriteUtilCheckCollisionAtPosition(gSamusData.yPosition - BLOCK_TO_SUB_PIXEL(.5f),
        gSamusData.drawDistanceLeft + gSamusData.xPosition - BLOCK_TO_SUB_PIXEL(.25f));

    if (gPreviousCollisionCheck == 0)
        gSamusData.xPosition -= BLOCK_TO_SUB_PIXEL(.125f);

    switch (gCurrentSprite.OMEGA_METROID_POSE_STAGE)
    {
        case OMEGA_METROID_SA_X_STAGE_LOAD_GFX:
            gCurrentSprite.OMEGA_METROID_TIMER--;
            if (gCurrentSprite.OMEGA_METROID_TIMER < 8)
                SpriteLoadGfx(PSPRITE_ICE_BEAM_ABILITY, 0, gCurrentSprite.OMEGA_METROID_TIMER);
            else if (gCurrentSprite.OMEGA_METROID_TIMER == 8)
                SpriteLoadPal(PSPRITE_ICE_BEAM_ABILITY, 0, 2);

            if (gCurrentSprite.OMEGA_METROID_TIMER == 0)
            {
                gCurrentSprite.OMEGA_METROID_POSE_STAGE = OMEGA_METROID_SA_X_STAGE_WAIT_TO_SCREAM;
                gCurrentSprite.OMEGA_METROID_TIMER = CONVERT_SECONDS(1 + 2/3.f);
            }
            break;

        case OMEGA_METROID_SA_X_STAGE_WAIT_TO_SCREAM:
            if (gCurrentSprite.OMEGA_METROID_TIMER > 0)
            {
                gCurrentSprite.OMEGA_METROID_TIMER--;
            }
            else if (SpriteUtilHasSubSprite1AnimationEnded())
            {
                gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_AboutToScream;
                gSubSpriteData1.animationDurationCounter = 0;
                gSubSpriteData1.currentAnimationFrame = 0;
                gCurrentSprite.OMEGA_METROID_POSE_STAGE = OMEGA_METROID_SA_X_STAGE_SCREAM;
            }
            break;

        case OMEGA_METROID_SA_X_STAGE_SCREAM:
            if (SpriteUtilHasSubSprite1AnimationEnded())
            {
                gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_Screaming;
                gSubSpriteData1.animationDurationCounter = 0;
                gSubSpriteData1.currentAnimationFrame = 0;
                gCurrentSprite.OMEGA_METROID_POSE_STAGE = OMEGA_METROID_SA_X_STAGE_SPAWN_SA_X;
                gCurrentSprite.OMEGA_METROID_TIMER = CONVERT_SECONDS(1 + 2/3.f);
                
                SoundPlay(SOUND_219);
            }
            break;

        case OMEGA_METROID_SA_X_STAGE_SPAWN_SA_X:
            if (gCurrentSprite.OMEGA_METROID_TIMER > 0)
            {
                gCurrentSprite.OMEGA_METROID_TIMER--;
            }
            else if (SpriteUtilHasSubSprite1AnimationEnded())
            {
                gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_DoneScreaming;
                gSubSpriteData1.animationDurationCounter = 0;
                gSubSpriteData1.currentAnimationFrame = 0;
                gCurrentSprite.OMEGA_METROID_POSE_STAGE = OMEGA_METROID_SA_X_STAGE_WAIT_TO_MOVE;
                gCurrentSprite.drawOrder = 12;

                OmegaMetroidSpawnSaX();
            }
            break;

        case OMEGA_METROID_SA_X_STAGE_WAIT_TO_MOVE:
            if (SpriteUtilHasSubSprite1AnimationEnded())
            {
                gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_Walking_Slow;
                gSubSpriteData1.animationDurationCounter = 0;
                gSubSpriteData1.currentAnimationFrame = 0;
                gCurrentSprite.OMEGA_METROID_POSE_STAGE = OMEGA_METROID_SA_X_STAGE_MOVE;
            }
            break;

        case OMEGA_METROID_SA_X_STAGE_MOVE:
            gCurrentSprite.OMEGA_METROID_X_SPEED = 0;
            OmegaMetroidForwardMovement();

            if (SpriteUtilHasSubSprite1AnimationEnded())
            {
                gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_DoneWalking_Slow;
                gSubSpriteData1.animationDurationCounter = 0;
                gSubSpriteData1.currentAnimationFrame = 0;
                gCurrentSprite.OMEGA_METROID_POSE_STAGE = OMEGA_METROID_SA_X_STAGE_STAND;
            }
            break;

        case OMEGA_METROID_SA_X_STAGE_STAND:
            gCurrentSprite.OMEGA_METROID_X_SPEED = 0;
            OmegaMetroidStandingMovement();

            if (SpriteUtilHasSubSprite1AnimationEnded())
            {
                gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_Idle_MouthStill;
                gSubSpriteData1.animationDurationCounter = 0;
                gSubSpriteData1.currentAnimationFrame = 0;
                gCurrentSprite.pose = OMEGA_METROID_POSE_WATCHING_SA_X;
            }
            break;
    }
}

/**
 * @brief 55358 | 5c | Handles Omega Metroid watching SA-X
 *
 */
void OmegaMetroidWatchingSaX(void)
{
    OmegaMetroidSaXIceBeamCollision();

    if (gSpriteData[gCurrentSprite.OMEGA_METROID_SA_X_SLOT].pose == 0x45) // TODO: SaXOmegaPose enum
    {
        gCurrentSprite.pose = OMEGA_METROID_POSE_DAMAGED_BY_SA_X;
        gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_Screaming_HeadShake;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;
        gCurrentSprite.OMEGA_METROID_TIMER = 0;

        SoundPlay(SOUND_21A);
    }
}

/**
 * @brief 553b4 | 4c | Handles Omega Metroid getting damaged by SA-X (part 1)
 *
 */
void OmegaMetroidDamagedBySaX(void)
{
    OmegaMetroidSaXIceBeamCollision();
    OmegaMetroidBodyFlashing_SaXCutscene();

    if (SpriteUtilHasSubSprite1AnimationEnded())
    {
        gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_WalkingBackward;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;

        gCurrentSprite.pose = OMEGA_METROID_POSE_WALKING_BACKWARDS_FROM_SA_X;
        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
        gCurrentSprite.OMEGA_METROID_POSE_STAGE = 0;
    }
}

/**
 * @brief 55400 | a0 | Handles Omega Metroid walking backward from SA-X
 *
 */
void OmegaMetroidWalkingBackwardFromSaX(void)
{
    OmegaMetroidSaXIceBeamCollision();
    OmegaMetroidBodyFlashing_SaXCutscene();

    switch (gCurrentSprite.OMEGA_METROID_POSE_STAGE)
    {
        case 0:
            gCurrentSprite.OMEGA_METROID_X_SPEED = 0;
            OmegaMetroidBackwardMovement();

            if (SpriteUtilHasSubSprite1AnimationEnded())
            {
                gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_DoneWalkingBackward;
                gSubSpriteData1.animationDurationCounter = 0;
                gSubSpriteData1.currentAnimationFrame = 0;

                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.OMEGA_METROID_POSE_STAGE = 1;
                gSpriteData[gCurrentSprite.OMEGA_METROID_SA_X_SLOT].work4 = 0x1A; // TODO: SaXOmegaPose enum
            }
            break;

        case 1:
            if (SpriteUtilHasSubSprite1AnimationEnded())
            {
                gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_Screaming_HeadShake;
                gSubSpriteData1.animationDurationCounter = 0;
                gSubSpriteData1.currentAnimationFrame = 0;

                gCurrentSprite.OMEGA_METROID_SWIPE_SA_X_TIMER = CONVERT_SECONDS(1);
                gCurrentSprite.pose = OMEGA_METROID_POSE_DAMAGED_BY_SA_X_2;
            }
            break;
    }
}

/**
 * @brief 554a0 | 68 | Handles Omega Metroid getting damaged by SA-X (part 2)
 *
 */
void OmegaMetroidDamagedBySaX2(void)
{
    OmegaMetroidSaXIceBeamCollision();
    OmegaMetroidBodyFlashing_SaXCutscene();

    if (gSubSpriteData1.currentAnimationFrame == 0 && gSubSpriteData1.animationDurationCounter == 1)
        SoundPlay(SOUND_21A);

    if (gCurrentSprite.OMEGA_METROID_SWIPE_SA_X_TIMER > 0)
    {
        gCurrentSprite.OMEGA_METROID_SWIPE_SA_X_TIMER--;
    }
    else if (SpriteUtilHasSubSprite1AnimationEnded())
    {
        gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_Idle_MouthMovingFast;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;
        gCurrentSprite.pose = OMEGA_METROID_POSE_WAITING_TO_SWIPE_SA_X;
    }
}

/**
 * @brief 55508 | 40 | Handles Omega Metroid waiting to swipe SA-X
 *
 */
void OmegaMetroidWaitingToSwipeSaX(void)
{
    OmegaMetroidSaXIceBeamCollision();
    OmegaMetroidBodyFlashing_SaXCutscene();

    if (SpriteUtilHasSubSprite1AnimationEnded())
    {
        gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_Swiping;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;
        gCurrentSprite.pose = OMEGA_METROID_POSE_SWIPING_SA_X;

        SoundPlay(SOUND_220);
    }
}

/**
 * @brief 55548 | a4 | Handles Omega Metroid swiping SA-X
 *
 */
void OmegaMetroidSwipingSaX(void)
{
    OmegaMetroidSaXIceBeamCollision();
    OmegaMetroidBodyFlashing_SaXCutscene();

    if (SpriteUtilHasSubSprite1AnimationEnded())
    {
        gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_Idle_Drooling;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;
        gCurrentSprite.pose = OMEGA_METROID_POSE_KILLED_SA_X;
        gCurrentSprite.paletteRow = 0;
        gCurrentSprite.drawOrder = 4;
        return;
    }

    if (gSubSpriteData1.currentAnimationFrame == 2)
    {
        if (gSubSpriteData1.animationDurationCounter == 1)
            SoundPlay(SOUND_221);
    }
    else if (gSubSpriteData1.currentAnimationFrame == 3)
    {
        if (gSubSpriteData1.animationDurationCounter == 1)
        {
            gSpriteData[gCurrentSprite.OMEGA_METROID_SA_X_SLOT].pose = 0x47; // TODO: SaXOmegaPose enum
            ScreenShakeStartVertical(CONVERT_SECONDS(2/3.f), 0x80 | 1);
            SoundPlay(SOUND_OMEGA_METROID_SWIPED_SAMUS);
        }
    }
}

/**
 * @brief 555ec | 6c | Handles Omega Metroid after killing SA-X
 *
 */
void OmegaMetroidKilledSaX(void)
{
    if (gSubSpriteData1.currentAnimationFrame == 0 && gSubSpriteData1.animationDurationCounter == 1)
        SoundPlay(SOUND_224);

    if (EventCheckAfter_IceBeamRecovered())
    {
        gCurrentSprite.properties &= ~SP_IMMUNE_TO_PROJECTILES;
        gCurrentSprite.pose = OMEGA_METROID_POSE_SCREAMING_AFTER_ICE_BEAM_OBTAINED;
        gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_AboutToScream;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;
        gCurrentSprite.OMEGA_METROID_POSE_STAGE = 0;

        PlayMusic(MUSIC_HEADING_TO_NIGHTMARE_RIDLEY, 7);
    }
}

/**
 * @brief 55658 | a8 | Handles Omega Metroid screaming after ice beam obtained
 *
 */
void OmegaMetroidScreamingAfterIceBeamObtained(void)
{
    if ((gCurrentSprite.invincibilityStunFlashTimer & 0x7F) == 16)
    {
        // Swipe if hit while screaming
        gCurrentSprite.pose = OMEGA_METROID_POSE_SWIPING_INIT;
        return;
    }

    if (gCurrentSprite.OMEGA_METROID_POSE_STAGE == 0)
    {
        if (SpriteUtilHasSubSprite1AnimationEnded())
        {
            gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_Screaming;
            gSubSpriteData1.animationDurationCounter = 0;
            gSubSpriteData1.currentAnimationFrame = 0;
            gCurrentSprite.OMEGA_METROID_POSE_STAGE = 1;
            gCurrentSprite.OMEGA_METROID_TIMER = CONVERT_SECONDS(1 + 2/3.f);

            SoundPlay(SOUND_219);
        }
    }
    else if (gCurrentSprite.OMEGA_METROID_POSE_STAGE == 1)
    {
        gCurrentSprite.OMEGA_METROID_TIMER--;
        if (gCurrentSprite.OMEGA_METROID_TIMER == 0)
        {
            gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_DoneScreaming;
            gSubSpriteData1.animationDurationCounter = 0;
            gSubSpriteData1.currentAnimationFrame = 0;
            gCurrentSprite.OMEGA_METROID_POSE_STAGE = 2;
        }
    }
    else // OMEGA_METROID_POSE_STAGE == 2
    {
        if (SpriteUtilHasSubSprite1AnimationNearlyEnded())
        {
            gCurrentSprite.pose = OMEGA_METROID_POSE_IDLE_INIT;
            gCurrentSprite.OMEGA_METROID_IDLE_ANIM = OMEGA_METROID_IDLE_MOUTH_MOVING_FAST;
        }
    }   
}

/**
 * @brief 55700 | 90 | Initializes Omega Metroid to walk backward
 *
 */
void OmegaMetroidWalkingBackwardInit(void)
{
    u16 screenX;
    u8 slot;

    gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_WalkingBackward;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = OMEGA_METROID_POSE_WALKING_BACKWARD;
    gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
    
    screenX = SUB_PIXEL_TO_PIXEL(gSubSpriteData1.xPosition) - SUB_PIXEL_TO_PIXEL(gBg1XPosition);
    if (screenX <= SCREEN_X_MIDDLE && gSubSpriteData1.health > 0)
        gCurrentSprite.OMEGA_METROID_BACKWARD_STEPS = 2;
    else
        gCurrentSprite.OMEGA_METROID_BACKWARD_STEPS = 1;

    slot = gCurrentSprite.OMEGA_METROID_RIGHT_CLAW_SLOT;
    if (gSpriteData[slot].samusCollision == SSC_OMEGA_METROID_SWIPING)
    {
        gSpriteData[slot].samusCollision = SSC_OMEGA_METROID_BODY;
        gSpriteData[slot].hitboxBottom = BLOCK_TO_SUB_PIXEL(.75f);
        gSpriteData[slot].hitboxRight = BLOCK_TO_SUB_PIXEL(1);
    }
}

/**
 * @brief 55790 | b4 | Handles Omega Metroid walking backward
 *
 */
void OmegaMetroidWalkingBackward(void)
{
    gCurrentSprite.OMEGA_METROID_X_SPEED = 0;

    if (gCurrentSprite.OMEGA_METROID_BACKWARD_STEPS > 0)
    {
        OmegaMetroidBackwardMovement();

        if (SpriteUtilHasSubSprite1AnimationEnded())
        {
            gCurrentSprite.OMEGA_METROID_BACKWARD_STEPS--;
            if (gCurrentSprite.OMEGA_METROID_BACKWARD_STEPS == 0)
            {
                gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_DoneWalkingBackward;
                gSubSpriteData1.animationDurationCounter = 0;
                gSubSpriteData1.currentAnimationFrame = 0;
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
            }
        }
    }
    else
    {
        if (SpriteUtilHasSubSprite1AnimationNearlyEnded())
        {
            if (gSubSpriteData1.health == 0)
            {
                gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_AboutToScream;
                gSubSpriteData1.animationDurationCounter = 0;
                gSubSpriteData1.currentAnimationFrame = 0;
                gCurrentSprite.OMEGA_METROID_FLASH_TIMER = 0;
                gCurrentSprite.pose = OMEGA_METROID_POSE_DYING_INIT;
            }
            else if (gSamusData.chargeBeamCounter < CHARGE_BEAM_THRESHOLD)
            {
                if (OmegaMetroidCheckSamusInFrontRange())
                    gCurrentSprite.pose = OMEGA_METROID_POSE_SWIPING_INIT;
                else
                    gCurrentSprite.pose = OMEGA_METROID_POSE_WALKING_INIT;
            }
            else
            {
                gCurrentSprite.pose = OMEGA_METROID_POSE_WALKING_INIT;
            }
        }
    }
}

/**
 * @brief 55844 | 50 | Initializes Omega Metroid to die
 *
 */
void OmegaMetroidDyingInit(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    OmegaMetroidBodyFlashing();

    if (SpriteUtilHasSubSprite1AnimationEnded())
    {
        gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_Screaming;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;
        gCurrentSprite.pose = OMEGA_METROID_POSE_DYING_1;
        gCurrentSprite.OMEGA_METROID_TIMER = CONVERT_SECONDS(1 + 2/3.f);

        SoundPlay(SOUND_219);
    }
}

/**
 * @brief 55894 | 50 | Handles Omega Metroid dying (part 1)
 *
 */
void OmegaMetroidDying1(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    OmegaMetroidBodyFlashing();

    gCurrentSprite.OMEGA_METROID_TIMER--;
    if (gCurrentSprite.OMEGA_METROID_TIMER == 0)
    {
        gSubSpriteData1.pMultiOam = sOmegaMetroidMultiOam_Screaming_HeadShake;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;
        gCurrentSprite.pose = OMEGA_METROID_POSE_DYING_2;
        gCurrentSprite.OMEGA_METROID_TIMER = CONVERT_SECONDS(2);

        FadeMusic(0);
    }
}

/**
 * @brief 558e4 | 1a4 | Handles Omega Metroid dying (part 2)
 *
 */
void OmegaMetroidDying2(void)
{
    u16 yPosition;
    u16 xPosition;

    gCurrentSprite.ignoreSamusCollisionTimer = 1;
    gCurrentSprite.OMEGA_METROID_TIMER--;

    if (gCurrentSprite.OMEGA_METROID_TIMER < CONVERT_SECONDS(1))
    {
        if (gCurrentSprite.OMEGA_METROID_TIMER & 1)
            gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;
    }
    else
    {
        OmegaMetroidBodyFlashing();

        if (gCurrentSprite.OMEGA_METROID_TIMER == CONVERT_SECONDS(1))
            gCurrentSprite.paletteRow = 0;
    }

    if (gCurrentSprite.OMEGA_METROID_TIMER == 0)
    {
        gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.pose = OMEGA_METROID_POSE_DYING_3;
        gCurrentSprite.OMEGA_METROID_TIMER = CONVERT_SECONDS(29/60.f);
    }

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;
    switch (gCurrentSprite.OMEGA_METROID_TIMER)
    {
        case CONVERT_SECONDS(1 + 58/60.f):
            ParticleSet(yPosition - BLOCK_TO_SUB_PIXEL(.5f), xPosition + BLOCK_TO_SUB_PIXEL(.4375f), PE_0x25);
            ParticleSet(yPosition + BLOCK_TO_SUB_PIXEL(1), xPosition + BLOCK_TO_SUB_PIXEL(.8125f), PE_0x22);
            SoundPlay_3b1c(SOUND_21C);
            break;
        
        case CONVERT_SECONDS(1 + 47/60.f):
            ParticleSet(yPosition - BLOCK_TO_SUB_PIXEL(.5f), xPosition - BLOCK_TO_SUB_PIXEL(.5625f), PE_0x21);
            ParticleSet(yPosition + BLOCK_TO_SUB_PIXEL(1), xPosition - BLOCK_TO_SUB_PIXEL(1.1875f), PE_0x25);
            break;
        
        case CONVERT_SECONDS(1 + 36/60.f):
            ParticleSet(yPosition - BLOCK_TO_SUB_PIXEL(1), xPosition + BLOCK_TO_SUB_PIXEL(1.375f), PE_0x25);
            ParticleSet(yPosition + BLOCK_TO_SUB_PIXEL(.5f), xPosition + BLOCK_TO_SUB_PIXEL(.5f), PE_0x2F);
            break;
        
        case CONVERT_SECONDS(1 + 20/60.f):
            ParticleSet(yPosition - BLOCK_TO_SUB_PIXEL(1.125f), xPosition - BLOCK_TO_SUB_PIXEL(1.125f), PE_0x21);
            ParticleSet(yPosition, xPosition + BLOCK_TO_SUB_PIXEL(15/32.f), PE_0x2F);
            break;
        
        case CONVERT_SECONDS(1 + 4/60.f):
            ParticleSet(yPosition - BLOCK_TO_SUB_PIXEL(1), xPosition + BLOCK_TO_SUB_PIXEL(.25f), PE_0x2F);
            ParticleSet(yPosition + BLOCK_TO_SUB_PIXEL(1), xPosition - BLOCK_TO_SUB_PIXEL(.8125f), PE_0x22);
            break;
        
        case CONVERT_SECONDS(48/60.f):
            ParticleSet(yPosition - BLOCK_TO_SUB_PIXEL(.5f), xPosition - BLOCK_TO_SUB_PIXEL(.4375f), PE_0x21);
            ParticleSet(yPosition + BLOCK_TO_SUB_PIXEL(1 + 3/32.f), xPosition, PE_0x22);
            break;
        
        case CONVERT_SECONDS(32/60.f):
            ParticleSet(yPosition - BLOCK_TO_SUB_PIXEL(.5f), xPosition + BLOCK_TO_SUB_PIXEL(.5625f), PE_0x21);
            ParticleSet(yPosition + BLOCK_TO_SUB_PIXEL(1), xPosition - BLOCK_TO_SUB_PIXEL(1.375f), PE_0x2F);
            break;
        
        case CONVERT_SECONDS(16/60.f):
            ParticleSet(yPosition + BLOCK_TO_SUB_PIXEL(.75f), xPosition - BLOCK_TO_SUB_PIXEL(1.1875f), PE_0x2F);
            ParticleSet(yPosition - BLOCK_TO_SUB_PIXEL(1), xPosition, PE_0x2F);
            break;

        case 0:
            ParticleSet(yPosition - BLOCK_TO_SUB_PIXEL(1.125f), xPosition - BLOCK_TO_SUB_PIXEL(21/32.f), PE_0x2F);
            ParticleSet(yPosition, xPosition + BLOCK_TO_SUB_PIXEL(15/32.f), PE_0x21);
            break;
    }
}

/**
 * @brief 55a88 | 7c | Handles Omega Metroid dying (part 3)
 *
 */
void OmegaMetroidDying3(void)
{
    u16 yPosition;
    u16 xPosition;
    
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    gCurrentSprite.OMEGA_METROID_TIMER--;
    if (gCurrentSprite.OMEGA_METROID_TIMER < CONVERT_SECONDS(7/15.f))
        SpriteLoadGfx(PSPRITE_GUNSHIP_END, 0, gCurrentSprite.OMEGA_METROID_TIMER);
    else if (gCurrentSprite.OMEGA_METROID_TIMER == CONVERT_SECONDS(7/15.f))
        SpriteLoadPal(PSPRITE_GUNSHIP_END, 0, 7);

    if (gCurrentSprite.OMEGA_METROID_TIMER == 0)
    {
        yPosition = gCurrentSprite.workY;
        xPosition = gCurrentSprite.workX - BLOCK_TO_SUB_PIXEL(5);
        SpriteSpawnPrimary(PSPRITE_GUNSHIP_END, 0, 0, SSP_UNINFECTED_OR_BOSS, yPosition, xPosition, 0);
        gCurrentSprite.status = 0;
    }
}

/**
 * @brief 55b04 | 1f0 | Initializes an Omega Metroid part
 *
 */
void OmegaMetroidPartInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
    gCurrentSprite.health = 1;
    gCurrentSprite.samusCollision = SSC_OMEGA_METROID_BODY;
    gCurrentSprite.pose = SPRITE_POSE_IDLE;

    OmegaMetroidPartSetDrawOrder();

    switch (gCurrentSprite.roomSlot)
    {
        case OMEGA_METROID_PART_HEAD:
            gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(2);
            gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(4);
            gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(2.5f);

            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(1.5f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(1);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(.625f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(1);
            break;
        
        case OMEGA_METROID_PART_LEFT_ARM:
            gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1.5f);
            gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(1.5f);
            gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1);

            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(1);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(1);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(.5f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(.5f);
            break;
        
        case OMEGA_METROID_PART_LEFT_LEG:
            gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(4.5f);
            gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(.5f);
            gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(2.5f);

            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(3.5f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(.0625f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(.5f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(1.5f);
            break;
        
        case OMEGA_METROID_PART_RIGHT_ARM:
            gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1);
            gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(1);
            gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(.5f);

            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(.5f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(.625f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(.5f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(.5f);

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            break;
        
        case OMEGA_METROID_PART_RIGHT_CLAW:
            gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1);
            gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(1);
            gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1.5f);

            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(.625f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(.75f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(1.5f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(1);
            break;
        
        case OMEGA_METROID_PART_TAIL:
            gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(2);
            gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(.5f);
            gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(2);

            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(1.5f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(.5f);
            gCurrentSprite.hitboxLeft = BLOCK_TO_SUB_PIXEL(0);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(2);
            break;
        
        case OMEGA_METROID_PART_RIGHT_LEG:
            gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(4);
            gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(.5f);
            gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(2.5f);

            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(2);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(.0625f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(1.375f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(.0625f);
            break;
    
        default:
            gCurrentSprite.status = 0;
            break;
    }

    OmegaMetroidSyncSubSprites();
}

/**
 * @brief 55cf4 | 1e4 | Handles an Omega Metroid part being idle
 *
 */
void OmegaMetroidPartIdle(void)
{
    u8 primarySlot;

    primarySlot = gCurrentSprite.primarySpriteRamSlot;

    if (gSpriteData[primarySlot].status == 0)
    {
        gCurrentSprite.status = 0;
        return;
    }

    if (gSpriteData[primarySlot].status & SPRITE_STATUS_NOT_DRAWN)
    {
        gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.ignoreSamusCollisionTimer = 1;
    }
    else
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    }

    if (gSpriteData[primarySlot].health == 0)
    {
        gCurrentSprite.health = 0;
        gCurrentSprite.ignoreSamusCollisionTimer = 1;
    }

    switch (gSpriteData[primarySlot].pose)
    {
        case OMEGA_METROID_POSE_WAITING_FOR_SA_X:
            if (gSpriteData[primarySlot].OMEGA_METROID_POSE_STAGE == OMEGA_METROID_SA_X_STAGE_WAIT_TO_MOVE)
                OmegaMetroidPartSetDrawOrder_SaXCutscene();
            break;
        
        case OMEGA_METROID_POSE_KILLED_SA_X:
            OmegaMetroidPartSetDrawOrder();
            break;

        case OMEGA_METROID_POSE_WAITING_TO_APPEAR:
            gCurrentSprite.status |= SPRITE_STATUS_HIDDEN;
            break;
        
        case OMEGA_METROID_POSE_FIRST_JUMP:
            gCurrentSprite.status &= ~SPRITE_STATUS_HIDDEN;
            break;
        
        case OMEGA_METROID_POSE_DYING_INIT:
        case OMEGA_METROID_POSE_DYING_1:
        case OMEGA_METROID_POSE_DYING_2:
        case OMEGA_METROID_POSE_DYING_3:
            gCurrentSprite.paletteRow = gSpriteData[primarySlot].paletteRow;
            break;
    }
}

/**
 * @brief 55ed8 | 244 | Omega Metroid AI
 *
 */
void OmegaMetroid(void)
{
    OmegaMetroidUpdateHeartPalette();
    OmegaMetroidUpdateHealthThreshold();

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            OmegaMetroidInit();
            break;
        
        case OMEGA_METROID_POSE_WAITING_TO_APPEAR:
            OmegaMetroidWaitingToAppear();
            break;
        
        case OMEGA_METROID_POSE_FIRST_JUMP:
            OmegaMetroidFirstJump();
            break;
        
        case OMEGA_METROID_POSE_LANDING_FROM_FIRST_JUMP:
            OmegaMetroidLandingFromFirstJump();
            break;
        
        case OMEGA_METROID_POSE_LANDED_AFTER_FIRST_JUMP:
            OmegaMetroidLandedAfterFirstJump();
            break;
        
        case OMEGA_METROID_POSE_SCREAMING_AFTER_FIRST_JUMP:
            OmegaMetroidScreamingAfterFirstJump();
            break;
        
        case OMEGA_METROID_POSE_FINISHED_SCREAMING_AFTER_FIRST_JUMP:
            OmegaMetroidFinishedScreamingAfterFirstJump();
            break;
       
        case OMEGA_METROID_POSE_WALKING_BEFORE_SA_X_INIT:
            OmegaMetroidWalkingBeforeSaXInit();

        case OMEGA_METROID_POSE_WALKING_BEFORE_SA_X:
            OmegaMetroidWalkingBeforeSaX();
            break;
        
        case OMEGA_METROID_POSE_SLOW_WALKING_INIT:
            OmegaMetroidSlowWalkingInit();

        case OMEGA_METROID_POSE_SLOW_WALKING:
            OmegaMetroidSlowWalking();
            break;
        
        case OMEGA_METROID_POSE_WALKING_INIT:
            OmegaMetroidWalkingInit();

        case OMEGA_METROID_POSE_WALKING:
            OmegaMetroidWalking();
            break;
        
        case OMEGA_METROID_POSE_IDLE_INIT:
            OmegaMetroidIdleInit();

        case OMEGA_METROID_POSE_IDLE:
            OmegaMetroidIdle();
            break;
        
        case OMEGA_METROID_POSE_WALKING_BACKWARD_INIT:
            OmegaMetroidWalkingBackwardInit();

        case OMEGA_METROID_POSE_WALKING_BACKWARD:
            OmegaMetroidWalkingBackward();
            break;
        
        case OMEGA_METROID_POSE_JUMP_WARNING_INIT:
            OmegaMetroidJumpWarningInit();

        case OMEGA_METROID_POSE_JUMP_WARNING:
            OmegaMetroidJumpWarning();
            break;
        
        case OMEGA_METROID_POSE_JUMPING:
            OmegaMetroidJumping();
            break;
        
        case OMEGA_METROID_POSE_FALLING:
            OmegaMetroidFalling();
            break;
        
        case OMEGA_METROID_POSE_LANDING_INIT:
            OmegaMetroidLandingInit();

        case OMEGA_METROID_POSE_LANDING:
            OmegaMetroidLanding();
            break;
        
        case OMEGA_METROID_POSE_SWIPING_INIT:
            OmegaMetroidSwipingInit();

        case OMEGA_METROID_POSE_SWIPING:
            OmegaMetroidSwiping();
            break;
        
        case OMEGA_METROID_POSE_VERTICAL_JUMP_INIT:
            OmegaMetroidVerticalJumpInit();

        case OMEGA_METROID_POSE_VERTICAL_JUMP:
            OmegaMetroidVerticalJump();
            break;
        
        case OMEGA_METROID_POSE_WAITING_FOR_SA_X_INIT:
            OmegaMetroidWaitingForSaXInit();

        case OMEGA_METROID_POSE_WAITING_FOR_SA_X:
            OmegaMetroidWaitingForSaX();
            break;
        
        case OMEGA_METROID_POSE_WATCHING_SA_X:
            OmegaMetroidWatchingSaX();
            break;
        
        case OMEGA_METROID_POSE_DAMAGED_BY_SA_X:
            OmegaMetroidDamagedBySaX();
            break;
        
        case OMEGA_METROID_POSE_WALKING_BACKWARDS_FROM_SA_X:
            OmegaMetroidWalkingBackwardFromSaX();
            break;
        
        case OMEGA_METROID_POSE_DAMAGED_BY_SA_X_2:
            OmegaMetroidDamagedBySaX2();
            break;
        
        case OMEGA_METROID_POSE_WAITING_TO_SWIPE_SA_X:
            OmegaMetroidWaitingToSwipeSaX();
            break;
        
        case OMEGA_METROID_POSE_SWIPING_SA_X:
            OmegaMetroidSwipingSaX();
            break;
        
        case OMEGA_METROID_POSE_KILLED_SA_X:
            OmegaMetroidKilledSaX();
            break;
       
        case OMEGA_METROID_POSE_SCREAMING_AFTER_ICE_BEAM_OBTAINED:
            OmegaMetroidScreamingAfterIceBeamObtained();
            break;
        
        case OMEGA_METROID_POSE_DYING_INIT:
            OmegaMetroidDyingInit();
            break;
        
        case OMEGA_METROID_POSE_DYING_1:
            OmegaMetroidDying1();
            break;
        
        case OMEGA_METROID_POSE_DYING_2:
            OmegaMetroidDying2();
            break;
        
        case OMEGA_METROID_POSE_DYING_3:
            OmegaMetroidDying3();
            break;
    }

    SpriteUtilUpdateSubSpriteData1Animation();
    OmegaMetroidSyncSubSprites();
    OmegaMetroidUpdatePalette();
}

/**
 * @brief 5611c | 24 | Omega Metroid part AI
 *
 */
void OmegaMetroidPart(void)
{
    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
    {
        OmegaMetroidPartInit();
    }
    else
    {
        OmegaMetroidPartIdle();
        OmegaMetroidSyncSubSprites();
    }
}
