#include "sprites_AI/sa_x_monster.h"
#include "data/sprites/sa_x_monster.h"

#include "globals.h"
#include "macros.h"
#include "sprite_util.h"

#include "data/sprite_data.h"
#include "data/frame_data_pointers.h"
#include "data/sprite_pointers.h"
#include "data/sprites/x_parasite.h"

#include "constants/audio.h"
#include "constants/particle.h"
#include "constants/projectile.h"

#include "structs/projectile.h"
#include "structs/samus.h"
#include "structs/sprite.h"

enum SaXMonsterPose {
    SA_X_MONSTER_POSE_TURNING_AROUND_INIT = 3,
    SA_X_MONSTER_POSE_TURNING_AROUND = 4,
    SA_X_MONSTER_POSE_DROPPING_INIT = 0x15,
    SA_X_MONSTER_POSE_DROPPING = 0x16,
    SA_X_MONSTER_POSE_JUMP_WARNING_INIT = 0x17,
    SA_X_MONSTER_POSE_JUMP_WARNING = 0x18,
    SA_X_MONSTER_POSE_JUMPING = 0x1a,
    SA_X_MONSTER_POSE_FALLING_INIT = 0x1b,
    SA_X_MONSTER_POSE_FALLING = 0x1c,
    SA_X_MONSTER_POSE_LANDING_INIT = 0x1d,
    SA_X_MONSTER_POSE_LANDING = 0x1e,
    SA_X_MONSTER_POSE_SCREAMING_GROUNDED_INIT = 0x37,
    SA_X_MONSTER_POSE_SCREAMING_GROUNDED = 0x38,
    SA_X_MONSTER_POSE_SCREAMING_AIRBORNE_INIT = 0x39,
    SA_X_MONSTER_POSE_SCREAMING_AIRBORNE = 0x3a,
    SA_X_MONSTER_POSE_PANTING = 0x3c,
    SA_X_MONSTER_POSE_DYING = 0x3e,
    SA_X_MONSTER_POSE_TURNING_INTO_CORE_X = 0x40,
};

#define SA_X_MONSTER_CORE_X_TIMER workY
#define SA_X_MONSTER_LOAD_GFX_STAGE work1
#define SA_X_MONSTER_DYING_TIMER work1
#define SA_X_MONSTER_JUMP_SPEED_IDX work4


/**
 * @brief 507f4 | 68 | Syncs all the parts of the SA-X monster
 *
 */
void SaXMonsterSyncSubSprites(void)
{
    MultiSpriteDataInfo_T msdi;
    u16 oamIdx;

    msdi = gSubSpriteData1.pMultiOam[gSubSpriteData1.currentAnimationFrame].pData;
    oamIdx = msdi[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX];
    
    if (gCurrentSprite.pOam != sSaXMonsterFrameDataPointers[oamIdx])
    {
        gCurrentSprite.pOam = sSaXMonsterFrameDataPointers[oamIdx];
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }

    gCurrentSprite.yPosition = gSubSpriteData1.yPosition +
        msdi[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET];
    gCurrentSprite.xPosition = gSubSpriteData1.xPosition +
        msdi[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_X_OFFSET];
}

/**
 * @brief 5085c | dc | Handles wave beam colliding with the SA-X monster
 *
 */
void SaXMonsterProjectilesCollision(void)
{
    u16 spriteY;
    u16 spriteX;
    u16 spriteTop;
    u16 spriteBottom;
    u16 spriteLeft;
    u16 spriteRight;
    u16 projY;
    u16 projX;
    u8 i;

    if (gCurrentSprite.status & SPRITE_STATUS_IGNORE_PROJECTILES || gCurrentSprite.health == 0)
        return;

    spriteY = gCurrentSprite.yPosition;
    spriteX = gCurrentSprite.xPosition;
    spriteTop = spriteY + gCurrentSprite.hitboxTop;
    spriteBottom = spriteY + gCurrentSprite.hitboxBottom;
    spriteLeft = spriteX + gCurrentSprite.hitboxLeft;
    spriteRight = spriteX + gCurrentSprite.hitboxRight;

    for (i = 0; i < MAX_AMOUNT_OF_PROJECTILES; i++)
    {
        if ((gProjectileData[i].status & PROJ_STATUS_EXISTS) &&
            (gProjectileData[i].status & PROJ_STATUS_CAN_AFFECT_ENVIRONMENT) &&
            gProjectileData[i].type == PROJ_TYPE_WAVE_BEAM)
        {
            projY = gProjectileData[i].yPosition;
            projX = gProjectileData[i].xPosition;

            if (SpriteUtilCheckObjectsTouching(
                projY + gProjectileData[i].hitboxTop, projY + gProjectileData[i].hitboxBottom,
                projX + gProjectileData[i].hitboxLeft, projX + gProjectileData[i].hitboxRight,
                spriteTop, spriteBottom, spriteLeft, spriteRight))
            {
                ParticleSet(projY, projX, PE_INVINCIBLE_HIT);
                gProjectileData[i].status = 0;
            }
        }
    }
}

/**
 * @brief 50938 | 40 | Checks if the SA-X monster should scream
 *
 * @param airborne True if the SA-X monster is mid-air, false when grounded
 * @return s32 bool, whether the SA-X should scream
 */
bools32 SaXMonsterCheckScream(boolu8 airborne)
{
    if ((gCurrentSprite.invincibilityStunFlashTimer & 0x7F) == 8)
    {
        if (airborne)
            SaXMonsterScreamingAirborneInit();
        else
            SaXMonsterScreamingGroundedInit();
        
        SoundPlayNotAlreadyPlaying(SOUND_1E1);
        return TRUE;
    }

    return FALSE;
}

/**
 * @brief 50978 | d0 | Moves the SA-X monster horizontally
 *
 * @param checkSamusPosition Whether the SA-X monster should only move if facing Samus
 */
void SaXMonsterXMovement(boolu8 checkSamusPosition)
{
    u16 distance;

    distance = BLOCK_TO_SUB_PIXEL(.1875f);
    
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if ((!checkSamusPosition || gSubSpriteData1.yPosition >= gSamusData.yPosition || gSubSpriteData1.xPosition <= gSamusData.xPosition) &&
            ((SpriteUtilCheckCollisionAtPosition(gSubSpriteData1.yPosition - BLOCK_TO_SUB_PIXEL(.5f),
                gSubSpriteData1.xPosition + BLOCK_TO_SUB_PIXEL(2.1875f)), gPreviousCollisionCheck == 0) ||
             (SpriteUtilCheckCollisionAtPosition(gSubSpriteData1.yPosition - BLOCK_TO_SUB_PIXEL(4.5f),
                gSubSpriteData1.xPosition + BLOCK_TO_SUB_PIXEL(2.1875f)), gPreviousCollisionCheck == 0)))
        {
            gSubSpriteData1.xPosition += distance;
        }
    }
    else
    {
        if ((!checkSamusPosition || gSubSpriteData1.yPosition >= gSamusData.yPosition || gSubSpriteData1.xPosition >= gSamusData.xPosition) &&
            ((SpriteUtilCheckCollisionAtPosition(gSubSpriteData1.yPosition - BLOCK_TO_SUB_PIXEL(.5f),
                gSubSpriteData1.xPosition - BLOCK_TO_SUB_PIXEL(2.1875f)), gPreviousCollisionCheck == 0) ||
             (SpriteUtilCheckCollisionAtPosition(gSubSpriteData1.yPosition - BLOCK_TO_SUB_PIXEL(4.5f),
                gSubSpriteData1.xPosition - BLOCK_TO_SUB_PIXEL(2.1875f)), gPreviousCollisionCheck == 0)))
        {
            gSubSpriteData1.xPosition -= distance;
        }
    }
}

/**
 * @brief 50a48 | 30 | Sets the horizontal hitboxes for the SA-X monster
 *
 */
void SaXMonsterSetSideHitboxes(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(1);
        gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(2);
    }
    else
    {
        gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(2);
        gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(1);
    }
}

/**
 * @brief 50a78 | 94 | Moves the SA-X monster vertically when falling
 *
 */
void SaXMonsterFallingMovement(void)
{
    u8 index;
    s16 distance;
    u32 blockTop;

    index = gCurrentSprite.SA_X_MONSTER_JUMP_SPEED_IDX;
    distance = sSaXMonsterFallingYSpeeds[index];
    if (distance == SHORT_MAX)
    {
        distance = sSaXMonsterFallingYSpeeds[index - 1];
        gSubSpriteData1.yPosition += distance;
    }
    else
    {
        index++;
        gCurrentSprite.SA_X_MONSTER_JUMP_SPEED_IDX = index;
        gSubSpriteData1.yPosition += distance;
    }

    if (gSubSpriteData1.yPosition > BLOCK_TO_SUB_PIXEL(28 + 31/32.f))
    {
        blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gSubSpriteData1.yPosition, gSubSpriteData1.xPosition);
        if (gPreviousVerticalCollisionCheck & 0xF)
        {
            gSubSpriteData1.yPosition = blockTop;
            gCurrentSprite.pose = SA_X_MONSTER_POSE_LANDING_INIT;
            ScreenShakeStartVertical(CONVERT_SECONDS(2/3.f), 0x80 | 1);
        }
    }
}

/**
 * @brief 50b0c | b4 | Handles the SA-X monster spawning from X
 *
 */
void SaXMonsterSpawningFromX(void)
{
    u8 row;

    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    if (gCurrentSprite.SA_X_MONSTER_LOAD_GFX_STAGE == 0)
    {
        if (gCurrentSprite.scaling < Q_8_8(1))
        {
            gCurrentSprite.scaling++;
        }
        else
        {
            gCurrentSprite.status &= ~SPRITE_STATUS_ROTATION_SCALING_WHOLE;
            gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.pose = SPRITE_POSE_IDLE_INIT;
        }
    }
    else
    {
        gCurrentSprite.SA_X_MONSTER_LOAD_GFX_STAGE--;
        if (gCurrentSprite.SA_X_MONSTER_LOAD_GFX_STAGE <= 3)
        {
            row = gCurrentSprite.SA_X_MONSTER_LOAD_GFX_STAGE;
            DMA3_COPY_16(GET_SPRITE_GRAPHICS(PSPRITE_SA_X_MONSTER) + row * 512,
                VRAM_BASE + 0x14000 + row * 512, 256);
        }
        else if (gCurrentSprite.SA_X_MONSTER_LOAD_GFX_STAGE == 4)
        {
            DMA3_COPY_16(GET_SPRITE_PALETTE(PSPRITE_SA_X_MONSTER), PALRAM_OBJ + 0x100, 16);
        }
    }
}

/**
 * @brief 50bc0 | 1d0 | Initializes the SA-X monster
 *
 */
void SaXMonsterInit(void)
{
    struct MultiSpriteData* pMSD;
    
    gCurrentSprite.pose = SPRITE_POSE_SPAWNING_FROM_X;
    gCurrentSprite.SA_X_MONSTER_LOAD_GFX_STAGE = 5;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.status |=  SPRITE_STATUS_ROTATION_SCALING_WHOLE;
    
    gCurrentSprite.scaling = Q_8_8(21/32.f);
    gCurrentSprite.rotation = 0;

    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(4.25f);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(0);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(4.f);

    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(4.5f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0);

    gCurrentSprite.drawOrder = 4;
    gCurrentSprite.bgPriority = gIoRegisters.bg1Cnt & 3;
    gCurrentSprite.roomSlot = SA_X_MONSTER_PART_HEAD;
    gCurrentSprite.frozenPaletteRowOffset = 0;
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);

    gSubSpriteData1.yPosition = gCurrentSprite.yPosition;
    gSubSpriteData1.xPosition = gCurrentSprite.xPosition;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gSubSpriteData1.pMultiOam = sSaXMonsterMultiOam_Still_Right;
    else
        gSubSpriteData1.pMultiOam = sSaXMonsterMultiOam_Still_Left;

    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;

    SaXMonsterSetSideHitboxes();

    SpriteSpawnSecondary(SSPRITE_SA_X_MONSTER_PART, SA_X_MONSTER_PART_CHEEK_SPIKE, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_SA_X_MONSTER_PART, SA_X_MONSTER_PART_SHOULDER_MOUTH, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_SA_X_MONSTER_PART, SA_X_MONSTER_PART_FRONT_ARM, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_SA_X_MONSTER_PART, SA_X_MONSTER_PART_TONGUE, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_SA_X_MONSTER_PART, SA_X_MONSTER_PART_BACK_LEG, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_SA_X_MONSTER_PART, SA_X_MONSTER_PART_JAW, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_SA_X_MONSTER_PART, SA_X_MONSTER_PART_FRONT_LEG, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_SA_X_MONSTER_PART, SA_X_MONSTER_PART_BACK_TENTACLES, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_SA_X_MONSTER_PART, SA_X_MONSTER_PART_LOWER_BACK_TENTACLE, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_SA_X_MONSTER_PART, SA_X_MONSTER_PART_BACK_ARM, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);

    SoundPlay_3b1c(SOUND_9F);
}

/**
 * @brief 50d90 | 18 | Initializes the SA-X monster to drop
 *
 */
void SaXMonsterDroppingInit(void)
{
    gCurrentSprite.pose = SA_X_MONSTER_POSE_DROPPING;
    gCurrentSprite.SA_X_MONSTER_JUMP_SPEED_IDX = 0;
}

/**
 * @brief 50da8 | 28 | Handles the SA-X monster dropping
 *
 */
void SaXMonsterDropping(void)
{
    SaXMonsterFallingMovement();

    if (gCurrentSprite.pose == SA_X_MONSTER_POSE_LANDING_INIT)
        SaXMonsterCheckScream(FALSE);
    else
        SaXMonsterCheckScream(TRUE);
}

/**
 * @brief 50dd0 | 4c | Initializes the SA-X monster to be idle
 *
 */
void SaXMonsterIdleInit(void)
{

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gSubSpriteData1.pMultiOam = sSaXMonsterMultiOam_Idle_Right;
    else
        gSubSpriteData1.pMultiOam = sSaXMonsterMultiOam_Idle_Left;
    
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = SPRITE_POSE_IDLE;
    gCurrentSprite.frozenPaletteRowOffset = 0;
}

/**
 * @brief 50e1c | 60 | Handles the SA-X monster being idle
 *
 */
void SaXMonsterIdle(void)
{
    bools32 turn;

    turn = FALSE;

    if (SpriteUtilHasSubSprite1AnimationNearlyEnded())
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            if (gCurrentSprite.xPosition > gSamusData.xPosition)
                turn = TRUE;
        }
        else
        {
            if (gCurrentSprite.xPosition < gSamusData.xPosition)
                turn = TRUE;
        }
        
        if (turn)
            gCurrentSprite.pose = SA_X_MONSTER_POSE_TURNING_AROUND_INIT;
        else
            gCurrentSprite.pose = SA_X_MONSTER_POSE_JUMP_WARNING_INIT;

    }

    SaXMonsterCheckScream(FALSE);
}

/**
 * @brief 50e7c | 4c | Initializes the SA-X monster to do a jump warning
 *
 */
void SaXMonsterJumpWarningInit(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gSubSpriteData1.pMultiOam = sSaXMonsterMultiOam_JumpWarning_Right;
    else
        gSubSpriteData1.pMultiOam = sSaXMonsterMultiOam_JumpWarning_Left;

    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = SA_X_MONSTER_POSE_JUMP_WARNING;
    gCurrentSprite.frozenPaletteRowOffset = 0;
}

/**
 * @brief 50ec8 | 64 | Handles the SA-X monster doing a jump warning
 *
 */
void SaXMonsterJumpWarning(void)
{
    if (SpriteUtilHasSubSprite1AnimationEnded())
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            gSubSpriteData1.pMultiOam = sSaXMonsterMultiOam_Jumping_Right;
        else
            gSubSpriteData1.pMultiOam = sSaXMonsterMultiOam_Jumping_Left;
        
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;
        gCurrentSprite.SA_X_MONSTER_JUMP_SPEED_IDX = 0;
        gCurrentSprite.pose = SA_X_MONSTER_POSE_JUMPING;

        SoundPlay(SOUND_A0);
    }

    SaXMonsterCheckScream(FALSE);
}

/**
 * @brief 50f2c | 58 | Handles the SA-X monster jumping
 *
 */
void SaXMonsterJumping(void)
{
    u8 index;
    s16 distance;

    index = gCurrentSprite.SA_X_MONSTER_JUMP_SPEED_IDX;
    distance = sSaXMonsterJumpingYSpeeds[index];
    if (distance == SHORT_MAX)
    {
        gCurrentSprite.pose = SA_X_MONSTER_POSE_FALLING_INIT;
    }
    else
    {
        gCurrentSprite.SA_X_MONSTER_JUMP_SPEED_IDX++;
        gSubSpriteData1.yPosition += distance;
        SaXMonsterXMovement(FALSE);
    }

    SaXMonsterCheckScream(TRUE);
}

/**
 * @brief 50f84 | 18 | Initializes the SA-X monster to fall
 *
 */
void SaXMonsterFallingInit(void)
{
    gCurrentSprite.pose = SA_X_MONSTER_POSE_FALLING;
    gCurrentSprite.SA_X_MONSTER_JUMP_SPEED_IDX = 0;
}

/**
 * @brief 50f9c | 30 | Handles the SA-X monster falling
 *
 */
void SaXMonsterFalling(void)
{
    SaXMonsterXMovement(TRUE);
    SaXMonsterFallingMovement();
    
    if (gCurrentSprite.pose == SA_X_MONSTER_POSE_LANDING_INIT)
        SaXMonsterCheckScream(FALSE);
    else
        SaXMonsterCheckScream(TRUE);
}

/**
 * @brief 50fcc | 54 | Initializes the SA-X monster to land
 *
 */
void SaXMonsterLandingInit(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gSubSpriteData1.pMultiOam = sSaXMonsterMultiOam_Landing_Right;
    else
        gSubSpriteData1.pMultiOam = sSaXMonsterMultiOam_Landing_Left;

    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = SA_X_MONSTER_POSE_LANDING;
    gCurrentSprite.frozenPaletteRowOffset = 0;
    
    SoundPlay_3b1c(SOUND_A1);
}

/**
 * @brief 51020 | 60 | Handles the SA-X monster landing
 *
 */
void SaXMonsterLanding(void)
{
    bools32 turn;

    turn = FALSE;

    if (SpriteUtilHasSubSprite1AnimationNearlyEnded())
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            if (gCurrentSprite.xPosition > gSamusData.xPosition)
                turn = TRUE;
        }
        else
        {
            if (gCurrentSprite.xPosition < gSamusData.xPosition)
                turn = TRUE;
        }

        if (turn)
            gCurrentSprite.pose = SA_X_MONSTER_POSE_TURNING_AROUND_INIT;
        else
            gCurrentSprite.pose = SA_X_MONSTER_POSE_JUMP_WARNING_INIT;
    }

    SaXMonsterCheckScream(FALSE);
}

/**
 * @brief 51080 | 4c | Initializes the SA-X monster to turn around
 *
 */
void SaXMonsterTurningAroundInit(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gSubSpriteData1.pMultiOam = sSaXMonsterMultiOam_TurningAround_Right;
    else
        gSubSpriteData1.pMultiOam = sSaXMonsterMultiOam_TurningAround_Left;

    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = SA_X_MONSTER_POSE_TURNING_AROUND;
    gCurrentSprite.frozenPaletteRowOffset = 0;

    // BUG: SaXMonsterCheckScream isn't called, which means the SA-X's health isn't checked.
    // Killing the SA-X on this frame causes a softlock
#ifdef BUGFIX
    SaXMonsterCheckScream(FALSE);
#endif // BUGFIX
}

/**
 * @brief 510cc | 3c | Handles the SA-X monster turning around
 *
 */
void SaXMonsterTurningAround(void)
{
    if (gCurrentSprite.currentAnimationFrame == 2 && gCurrentSprite.animationDurationCounter == 1)
    {
        gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
        SaXMonsterSetSideHitboxes();
    }

    if (SpriteUtilHasCurrentAnimationEnded())
        SaXMonsterJumpWarningInit();

    SaXMonsterCheckScream(FALSE);
}

/**
 * @brief 51108 | 54 | Initializes the SA-X monster to scream while airborne
 *
 */
void SaXMonsterScreamingAirborneInit(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gSubSpriteData1.pMultiOam = sSaXMonsterMultiOam_ScreamingAirborne_Right;
    else
        gSubSpriteData1.pMultiOam = sSaXMonsterMultiOam_ScreamingAirborne_Left;

    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = SA_X_MONSTER_POSE_SCREAMING_AIRBORNE;
    gCurrentSprite.SA_X_MONSTER_JUMP_SPEED_IDX = 0;
    gCurrentSprite.frozenPaletteRowOffset = 1;
}

/**
 * @brief 5115c | 84 | Handles the SA-X monster screaming while airborne
 *
 */
void SaXMonsterScreamingAirborne(void)
{
    SaXMonsterXMovement(FALSE);
    SaXMonsterFallingMovement();

    if (gCurrentSprite.pose == SA_X_MONSTER_POSE_LANDING_INIT && gCurrentSprite.health == 0)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            gSubSpriteData1.pMultiOam = sSaXMonsterMultiOam_ScreamingGrounded_Right;
        else
            gSubSpriteData1.pMultiOam = sSaXMonsterMultiOam_ScreamingGrounded_Left;

        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;
        gCurrentSprite.pose = SA_X_MONSTER_POSE_PANTING;
        gCurrentSprite.samusCollision = SSC_NONE;
    }
    else if (gCurrentSprite.currentAnimationFrame == 0 && gCurrentSprite.animationDurationCounter == 2)
    {
        SoundPlay(SOUND_A6);
    }
}

/**
 * @brief 511e0 | 4c | Initializes the SA-X monster to scream while grounded
 *
 */
void SaXMonsterScreamingGroundedInit(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gSubSpriteData1.pMultiOam = sSaXMonsterMultiOam_ScreamingGrounded_Right;
    else
        gSubSpriteData1.pMultiOam = sSaXMonsterMultiOam_ScreamingGrounded_Left;
    
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = SA_X_MONSTER_POSE_SCREAMING_GROUNDED;
    gCurrentSprite.frozenPaletteRowOffset = 1;
}

/**
 * @brief 5122c | 84 | Handles the SA-X monster screaming while grounded
 *
 */
void SaXMonsterScreamingGrounded(void)
{
    bools32 turn;

    turn = FALSE;

    if (SpriteUtilHasCurrentAnimationEnded())
    {
        if (gCurrentSprite.health == 0)
        {
            gCurrentSprite.pose = SA_X_MONSTER_POSE_PANTING;
            gCurrentSprite.samusCollision = SSC_NONE;
            return;
        }
        
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            if (gCurrentSprite.xPosition > gSamusData.xPosition)
                turn = TRUE;
        }
        else
        {
            if (gCurrentSprite.xPosition < gSamusData.xPosition)
                turn = TRUE;
        }

        if (turn)
            SaXMonsterTurningAroundInit();
        else
            SaXMonsterJumpWarningInit();
    }
    else if (gCurrentSprite.currentAnimationFrame == 0 && gCurrentSprite.animationDurationCounter == 2)
    {
        SoundPlay(SOUND_A6);
    }
}

/**
 * @brief 512b0 | 9c | Handles the SA-X monster panting
 *
 */
void SaXMonsterPanting(void)
{
    u16 screenX;

    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    if (gCurrentSprite.currentAnimationFrame == 0 && gCurrentSprite.animationDurationCounter == 2)
        SoundPlay_3b1c(SOUND_A8);

    screenX = SUB_PIXEL_TO_PIXEL(gCurrentSprite.xPosition) - SUB_PIXEL_TO_PIXEL(gBg1XPosition);
    if (screenX >= 25 && screenX <= SCREEN_SIZE_X - 25 && SpriteUtilHasCurrentAnimationEnded())
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
             gSubSpriteData1.pMultiOam = sSaXMonsterMultiOam_Panting_Right;
        else
             gSubSpriteData1.pMultiOam = sSaXMonsterMultiOam_Panting_Left;

        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;
        gCurrentSprite.pose = SA_X_MONSTER_POSE_DYING;
        gCurrentSprite.SA_X_MONSTER_DYING_TIMER = 0xA0;

        SoundPlay_3b1c(SOUND_A7);
    }
}

/**
 * @brief 5134c | 44 | Handles the SA-X monster dying
 *
 */
void SaXMonsterDying(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    gCurrentSprite.SA_X_MONSTER_DYING_TIMER--;
    if (gCurrentSprite.SA_X_MONSTER_DYING_TIMER == 0)
    {
        gCurrentSprite.pose = SA_X_MONSTER_POSE_TURNING_INTO_CORE_X;
        gCurrentSprite.status |= SPRITE_STATUS_MOSAIC | SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.SA_X_MONSTER_CORE_X_TIMER = CONVERT_SECONDS(11/15.f);
    }
}

/**
 * @brief 51390 | 94 | Handles the SA-X monster turning into a core-X
 *
 */
void SaXMonsterTurningIntoCoreX(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;
    gWrittenToMosaic_H = sXParasiteMosaicValues[gCurrentSprite.SA_X_MONSTER_CORE_X_TIMER];

    gCurrentSprite.SA_X_MONSTER_CORE_X_TIMER--;
    if (gCurrentSprite.SA_X_MONSTER_CORE_X_TIMER < CONVERT_SECONDS(1/3.f))
    {
        SpriteLoadGfx(PSPRITE_ICE_BEAM_CORE_X, 0, gCurrentSprite.SA_X_MONSTER_CORE_X_TIMER);

        if (gCurrentSprite.SA_X_MONSTER_CORE_X_TIMER == 0)
        {
            gCurrentSprite.pose = SPRITE_POSE_SPAWNING_FROM_X_INIT;
            gCurrentSprite.spriteId = PSPRITE_ICE_BEAM_CORE_X;
            gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;

            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(1.25f);
            else
                gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(1.25f);

            gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(1.25f);
        }
    }
    else if (gCurrentSprite.SA_X_MONSTER_CORE_X_TIMER == CONVERT_SECONDS(1/3.f))
    {
        SpriteLoadPal(PSPRITE_ICE_BEAM_CORE_X, 0, 5);
    }
}

/**
 * @brief 51424 | 94 | Initializes an SA-X monster part
 *
 */
void SaXMonsterPartInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(4.25f);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(0);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(4);

    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(.0625f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(.0625f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(.0625f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(.0625f);

    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.pose = SPRITE_POSE_IDLE;

    if (gCurrentSprite.roomSlot <= SA_X_MONSTER_PART_JAW)
        gCurrentSprite.drawOrder = 4;
    else
        gCurrentSprite.drawOrder = 5;

    gCurrentSprite.bgPriority = gIoRegisters.bg1Cnt & 3;

    if (gCurrentSprite.roomSlot == SA_X_MONSTER_PART_FRONT_ARM || gCurrentSprite.roomSlot == SA_X_MONSTER_PART_BACK_ARM)
    {
        gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(.5f);
        gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(3);
    }

    SaXMonsterSyncSubSprites();
}

/**
 * @brief 514b8 | f8 | Handles an SA-X monster part being idle
 *
 */
void SaXMonsterPartIdle(void)
{
    switch (gSpriteData[gCurrentSprite.primarySpriteRamSlot].pose)
    {
        case SA_X_MONSTER_POSE_SCREAMING_AIRBORNE:
        case SPRITE_POSE_SPAWNING_FROM_X:
        case SA_X_MONSTER_POSE_TURNING_AROUND:
        case SA_X_MONSTER_POSE_SCREAMING_GROUNDED:
            gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
            break;

        case SA_X_MONSTER_POSE_PANTING:
            gCurrentSprite.status = 0;
            break;

        default:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

            if (gCurrentSprite.roomSlot == SA_X_MONSTER_PART_TONGUE && gCurrentSprite.currentAnimationFrame == 0 &&
                gCurrentSprite.animationDurationCounter == 1)
            {
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    if (gCurrentSprite.pOam == sSaXMonsterPartOam_Tongue_Whipping_Right)
                        SoundPlay(SOUND_A2);
                    else if (gCurrentSprite.pOam == sSaXMonsterPartOam_Tongue_Swaying_Right)
                        SoundPlay(SOUND_A3);
                    else if (gCurrentSprite.pOam == sSaXMonsterPartOam_Tongue_Spinning_Right)
                        SoundPlay(SOUND_A4);
                    else if (gCurrentSprite.pOam == sSaXMonsterPartOam_Tongue_Curling_Right)
                        SoundPlay(SOUND_A5);
                }
                else
                {
                    if (gCurrentSprite.pOam == sSaXMonsterPartOam_Tongue_Whipping_Left)
                        SoundPlay(SOUND_A2);
                    else if (gCurrentSprite.pOam == sSaXMonsterPartOam_Tongue_Swaying_Left)
                        SoundPlay(SOUND_A3);
                    else if (gCurrentSprite.pOam == sSaXMonsterPartOam_Tongue_Spinning_Left)
                        SoundPlay(SOUND_A4);
                    else if (gCurrentSprite.pOam == sSaXMonsterPartOam_Tongue_Curling_Left)
                        SoundPlay(SOUND_A5);
                }
            }
            break;
    }
}

/**
 * @brief 515b0 | 214 | SA-X monster AI
 *
 */
void SaXMonster(void)
{
    SaXMonsterProjectilesCollision();

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            SaXMonsterInit();
            break;
        
        case SPRITE_POSE_SPAWNING_FROM_X:
            SaXMonsterSpawningFromX();
            break;
        
        case SA_X_MONSTER_POSE_DROPPING_INIT:
            SaXMonsterDroppingInit();
        
        case SA_X_MONSTER_POSE_DROPPING:
            SaXMonsterDropping();
            break;
        
        case SPRITE_POSE_IDLE_INIT:
            SaXMonsterIdleInit();
        
        case SPRITE_POSE_IDLE:
            SaXMonsterIdle();
            break;
        
        case SA_X_MONSTER_POSE_JUMP_WARNING_INIT:
            SaXMonsterJumpWarningInit();
        
        case SA_X_MONSTER_POSE_JUMP_WARNING:
            SaXMonsterJumpWarning();
            break;
        
        case SA_X_MONSTER_POSE_JUMPING:
            SaXMonsterJumping();
            break;
        
        case SA_X_MONSTER_POSE_FALLING_INIT:
            SaXMonsterFallingInit();
        
        case SA_X_MONSTER_POSE_FALLING:
            SaXMonsterFalling();
            break;
        
        case SA_X_MONSTER_POSE_LANDING_INIT:
            SaXMonsterLandingInit();
        
        case SA_X_MONSTER_POSE_LANDING:
            SaXMonsterLanding();
            break;
        
        case SA_X_MONSTER_POSE_TURNING_AROUND_INIT:
            SaXMonsterTurningAroundInit();
            break;
        
        case SA_X_MONSTER_POSE_TURNING_AROUND:
            SaXMonsterTurningAround();
            break;
        
        case SA_X_MONSTER_POSE_SCREAMING_GROUNDED_INIT:
            SaXMonsterScreamingGroundedInit();
            break;
        
        case SA_X_MONSTER_POSE_SCREAMING_GROUNDED:
            SaXMonsterScreamingGrounded();
            break;
        
        case SA_X_MONSTER_POSE_SCREAMING_AIRBORNE_INIT:
            SaXMonsterScreamingAirborneInit();
            break;
        
        case SA_X_MONSTER_POSE_SCREAMING_AIRBORNE:
            SaXMonsterScreamingAirborne();
            break;
        
        case SA_X_MONSTER_POSE_PANTING:
            SaXMonsterPanting();
            break;
        
        case SA_X_MONSTER_POSE_DYING:
            SaXMonsterDying();
            break;
        
        case SA_X_MONSTER_POSE_TURNING_INTO_CORE_X:
            SaXMonsterTurningIntoCoreX();
            break;
    }

    SpriteUtilUpdateSubSpriteData1Animation();
    SaXMonsterSyncSubSprites();
}

/**
 * @brief 517c4 | 24 | SA-X monster part AI
 *
 */
void SaXMonsterPart(void)
{
    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
    {
        SaXMonsterPartInit();
    }
    else
    {
        SaXMonsterPartIdle();
        SaXMonsterSyncSubSprites();
    }
}
