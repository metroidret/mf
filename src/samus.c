#include "samus.h"
#include "clipdata.h"
#include "gba.h"
#include "globals.h"
#include "macros.h"
#include "oam.h"

#include "data/particle_data.h"
#include "data/samus_data.h"
#include "data/samus/arm_cannon_data.h"
#include "data/samus/arm_cannon_graphics.h"
#include "data/samus/arm_cannon_graphics_pointers.h"
#include "data/samus/samus_animation_pointers.h"
#include "data/samus/samus_graphics.h"
#include "data/samus/samus_palette_data.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/projectile.h"
#include "constants/samus.h"

#include "structs/samus.h"
#include "structs/sa_x.h"
#include "structs/screen_shake.h"

void SamusApplyScrewSpeedboosterDamageToEnvironment(u16, u16, u16);

/**
 * @brief 4D60 | 68 | Copies Samus data to the Samus data copy and resets Samus data
 * 
 */
void SamusCopyData(void)
{
    // Backup the Samus data of the previous frame before changing to the new state
    gSamusDataCopy = gSamusData;

    // Apply turning
    if (gSamusData.turning)
    {
        gSamusData.direction ^= KEY_LEFT | KEY_RIGHT;
        gSamusData.turning = FALSE;
    }

    // Reset most fields
    gSamusData.forcedMovement = 0;
    gSamusData.walljumpTimer = 0;
    gSamusData.speedboostingCounter = 0;
    gSamusData.armCannonDirection = ACD_NONE;
    gSamusData.armRunningFlag = FALSE;
    gSamusData.counter = 0;
    gSamusData.lastWallTouchedMidAir = KEY_NONE;
    gSamusData.xVelocity = 0;
    gSamusData.yVelocity = 0;

    gSamusData.animationDurationCounter = 0;
    gSamusData.currentAnimationFrame = 0;

    gSamusAnimationInfo.loadingSave = FALSE;
    gSamusAnimationInfo.paletteAnimationCounter = 0;
    gSamusAnimationInfo.currentPaletteRow = 0;
    gSamusAnimationInfo.spaceJumpSpinCounter = 0;
}

/**
 * @brief 4dc8 | 5c | Computes the effective X velocity according to slopes
 * 
 * @return s16 New velocity
 */
s16 SamusChangeVelocityOnSlope(void)
{
    s16 xVelocity;

    xVelocity = gSamusData.xVelocity;

    if (gSamusData.direction & gSamusData.slopeType)
    {
        // On a slope, dampen the velocity
        if (gSamusData.slopeType & SLOPE_STEEP)
            xVelocity = FRACT_MUL(xVelocity, 3, 5); // * .6f;
        else
            xVelocity = FRACT_MUL(xVelocity, 4, 5); // * .8f;
    }
    else
    {
        // Clamp ground walking velocity
        CLAMP(xVelocity, -SUB_PIXEL_TO_VELOCITY(QUARTER_BLOCK_SIZE + PIXEL_SIZE), SUB_PIXEL_TO_VELOCITY(QUARTER_BLOCK_SIZE + PIXEL_SIZE));
    }

    return xVelocity;
}

/**
 * @brief 4e24 | 44 | Copies the provided palette to Samus's palette or the SA-X's palette
 * 
 * @param src Source palette pointer
 * @param offset Destination offset
 * @param length Numbers of colors to copy
 * @param isSaX Whether to update the SA-X or Samus's palette
 */
void SamusSetPalette(const u16* src, s32 offset, s32 length, boolu32 isSaX)
{
    s32 i;
    const u16* pPalette;

    pPalette = src;

    for (i = offset; i < offset + length; i++)
    {
        if (!isSaX)
            gSamusPalette[i] = *pPalette++;
        else
            gSaXPalette[i] = *pPalette++;
    }
}

/**
 * @brief 4e68 | 184 | Updates the physics of Samus
 * 
 */
void SamusUpdatePhysics(void)
{
    u8 newPose;
    u32 slowed;
    s32 currentHazard;

    // Reset and check for underwater/slowed status
    gSamusUnderwaterFlag = FALSE;
    gSamusUseYVelocityForX = FALSE;

    slowed = FALSE;
    currentHazard = LOW_BYTE(ClipdataCheckCurrentAffectingAtPosition(gSamusData.yPosition, gSamusData.xPosition));

    switch (currentHazard)
    {
        case HAZARD_WATER:
            gSamusUnderwaterFlag++;
    
        case HAZARD_LAVA:
        case HAZARD_ACID:
            if (!(gEquipment.suitMiscStatus & (SMF_GRAVITY_SUIT | SMF_SA_X_SUIT)))
                slowed++;
            break;

        default:
            // TODO: Define for 0x80 slowed (nightmare related)
            if (gSamusPhysics.slowed & 0x80)
                slowed++;
    }

    // Update physics values
    if (slowed)
    {
        if (gSamusPhysics.slowed != 0x80)
            gSamusPhysics.slowed = TRUE;
            
        gSamusPhysics.yAcceleration = SAMUS_Y_ACCELERATION * 2.f / 3;
        gSamusPhysics.yVelocityCap = SAMUS_Y_VELOCITY_CAP * 0.375f;
        gSamusPhysics.midAirXAcceleration = SAMUS_MID_AIR_X_ACCELERATION / 2;
        gSamusPhysics.midAirXVelocityCap = SAMUS_MID_AIR_X_VELOCITY_CAP / 2;
        gSamusPhysics.midAirMorphedXVelocityCap = SAMUS_MID_AIR_MORPHED_X_VELOCITY_CAP / 2;
        gSamusPhysics.xAcceleration = SAMUS_X_ACCELERATION / 2;
        gSamusPhysics.xVelocityCap = SAMUS_X_VELOCITY_CAP / 2;

        gSamusData.speedboostingCounter = 0;
    }
    else
    {
        gSamusPhysics.slowed = FALSE;

        gSamusPhysics.yAcceleration = SAMUS_Y_ACCELERATION;
        gSamusPhysics.yVelocityCap = SAMUS_Y_VELOCITY_CAP;
        gSamusPhysics.midAirXAcceleration = SAMUS_MID_AIR_X_ACCELERATION;
        gSamusPhysics.midAirMorphedXVelocityCap = SAMUS_MID_AIR_MORPHED_X_VELOCITY_CAP;
        gSamusPhysics.xAcceleration = SAMUS_X_ACCELERATION;

        if (gSamusData.speedboostingCounter != 0)
        {
            gSamusPhysics.midAirXVelocityCap = SAMUS_MID_AIR_X_VELOCITY_CAP * 10.f / 3;
            gSamusPhysics.xVelocityCap = SAMUS_X_VELOCITY_CAP * 5.f / 3;
        }
        else
        {
            gSamusPhysics.midAirXVelocityCap = SAMUS_MID_AIR_X_VELOCITY_CAP;
            gSamusPhysics.xVelocityCap = SAMUS_X_VELOCITY_CAP;
        }
    }

    // Update SA-X suit status (why it this here?)
    if (gEquipment.beamStatus & BF_ICE_BEAM)
        gEquipment.suitMiscStatus |= SMF_SA_X_SUIT;
    else
        gEquipment.suitMiscStatus &= ~SMF_SA_X_SUIT;

    // if (gSubGameMode1 != SUB_GAME_MODE_NONE && gSubGameMode1 != SUB_GAME_MODE_DOOR_TRANSITION)
    if (gSubGameMode1 > SUB_GAME_MODE_DOOR_TRANSITION)
        APPLY_DELTA_TIME_INC(gSamusData.animationDurationCounter);

    gPreviousSamusField0 = gSamusData.unk_0;
    gPreviousXPosition = gSamusData.xPosition;
    gPreviousYPosition = gSamusData.yPosition;

    newPose = SAMUS_UPDATE();
    if (newPose != SPOSE_NONE)
        SAMUS_SET_POSE(newPose);

    SAMUS_UPDATE_DRAW_DISTAND_AND_STANDING_STATUS();
    SAMUS_UPDATE_VELOCITY_POSITION();
}

/**
 * @brief 4fec | b8 | Updates the collision data of Samus
 * 
 */
void SamusUpdateCollisionData(void)
{
    gSamusCollisionData.horizontalMovingDirection = KEY_NONE;
    gSamusCollisionData.verticalMovingDirection = KEY_NONE;
    gSamusCollisionData.touchingSideBlock = FALSE;
    gSamusCollisionData.touchingTopBlock = FALSE;
    gSamusCollisionData.unk_E = FALSE;

    gUnk_3004d8c = 0;

    if (gSamusData.xPosition > gPreviousXPosition)
    {
        gSamusCollisionData.horizontalMovingDirection = KEY_RIGHT;
        gSamusCollisionData.unk_4 = 1;
        gSamusCollisionData.unk_5 = 0;
        gSamusCollisionData.unk_6 = -ONE_SUB_PIXEL;
    }
    else if (gSamusData.xPosition < gPreviousXPosition)
    {
        gSamusCollisionData.horizontalMovingDirection = KEY_LEFT;
        gSamusCollisionData.unk_4 = 0;
        gSamusCollisionData.unk_5 = 1;
        gSamusCollisionData.unk_6 = BLOCK_SIZE;
    }
    else if (gSamusData.direction & KEY_RIGHT)
    {
        gSamusCollisionData.unk_4 = 1;
        gSamusCollisionData.unk_5 = 0;
        gSamusCollisionData.unk_6 = -ONE_SUB_PIXEL;
    }
    else
    {
        gSamusCollisionData.unk_4 = 0;
        gSamusCollisionData.unk_5 = 1;
        gSamusCollisionData.unk_6 = BLOCK_SIZE;
    }

    if (gSamusData.yPosition > gPreviousYPosition)
        gSamusCollisionData.verticalMovingDirection = KEY_DOWN;
    else if (gSamusData.yPosition < gPreviousYPosition)
        gSamusCollisionData.verticalMovingDirection = KEY_UP;

    SAMUS_CHECK_COLLISION();
    SAMUS_UPDATE_DRAW_DISTAND_AND_STANDING_STATUS();
}

/**
 * @brief 50a4 | 44 | Calls the update graphics functions
 * 
 */
void SamusCallUpdateGraphics(void)
{
    u8 direction;

    SamusUpdateEnvironmentEffect();

    if (gSamusData.direction & KEY_RIGHT)
        direction = FALSE;
    else
        direction = TRUE;

    SAMUS_UPDATE_GRAPHICS(direction);

    if (gSamusData.standingStatus == STANDING_MID_AIR)
        gSamusData.slopeType = SLOPE_NONE;
}

/**
 * @brief 50e8 | 20 | Calls the check play low health sound function
 * 
 */
void SamusCallCheckPlayLowHealthSound(void)
{
    SAMUS_PLAY_LOW_HEALTH_SOUND();
}

/**
 * @brief 5108 | 30 | Calls the update arm cannon offset function
 * 
 */
void SamusCheckUpdateArmCannonOffset(void)
{
    u8 direction;

    if (gSamusData.direction & KEY_RIGHT)
        direction = FALSE;
    else
        direction = TRUE;

    SAMUS_UPDATE_ARM_CANNON_OFFSET(direction);
}

/**
 * @brief 5138 | 7c | Makes Samus bounce on a bomb
 * 
 * @param direction Bounce direction
 */
void SamusBombBounce(u8 direction)
{
    s32 canBounce;

    if (gSamusPhysics.slowed)
        return;

    canBounce = FALSE;

    // Check has a direction
    if (MOD_AND(direction, FORCED_MOVEMENT_BOMB_JUMP_ABOVE) >= FORCED_MOVEMENT_BOMB_JUMP_RIGHT)
    {
        // Check pose
        switch (gSamusData.pose)
        {
            case SPOSE_MORPHING:
            case SPOSE_MORPH_BALL:
            case SPOSE_ROLLING:
            case SPOSE_GRABBED_BY_ZAZABI:
                canBounce++;
                break;

            case SPOSE_MORPH_BALL_MID_AIR:
                // Check when falling
                if (gSamusData.yVelocity <= 0 && !(direction & FORCED_MOVEMENT_BOMB_JUMP_ABOVE))
                    canBounce++;
                break;
        }
    }

    if (canBounce)
    {
        // Make bounce
        gSamusData.forcedMovement = direction & ~FORCED_MOVEMENT_BOMB_JUMP_ABOVE;
        SAMUS_SET_POSE(SPOSE_MID_AIR_REQUEST);
    }
}

/**
 * @brief 51b4 | 420 | Checks if an environment effect for Samus can/should spawn and spawns it
 * 
 * @param offset Offset in the effects
 * @param request Effect type requested
 */
void SamusCheckSetNewEnvironmentEffect(u32 offset, u32 request)
{
    u32 currentEffect;
    u32 previousEffect;
    u32 xPosition;

    switch (request)
    {
        case ENV_REQUEST_GROUND_EFFECT:
            if (gSamusData.direction & KEY_RIGHT)
                xPosition = gSamusData.xPosition + PIXEL_SIZE;
            else
                xPosition = gSamusData.xPosition - PIXEL_SIZE;

            currentEffect = ClipdataGetGroundEffect(gSamusData.yPosition + ONE_SUB_PIXEL, xPosition);

            if (currentEffect == GROUND_EFFECT_WET_GROUND)
            {
                gSamusEnvironmentalEffects[offset].effect = ENV_EFFECT_WALKING_ON_WET_GROUND;
                gSamusEnvironmentalEffects[offset].unk_6++;

                if (offset == 0)
                    SoundPlay(SOUND_66);
                else
                    SoundPlay(SOUND_67);
            }
            else if (currentEffect == GROUND_EFFECT_DUSTY_GROUND)
            {
                gSamusEnvironmentalEffects[offset].effect = ENV_EFFECT_WALKING_ON_DUSTY_GROUND;
                gSamusEnvironmentalEffects[offset].unk_6++;

                if (offset == 0)
                    SoundPlay(SOUND_68);
                else
                    SoundPlay(SOUND_69);
            }
            else if (currentEffect == GROUND_EFFECT_VERY_DUSTY_GROUND)
            {
                gSamusEnvironmentalEffects[offset].effect = ENV_EFFECT_WALKING_ON_VERY_DUSTY_GROUND;
                gSamusEnvironmentalEffects[offset].unk_6++;

                if (offset == 0)
                    SoundPlay(SOUND_68);
                else
                    SoundPlay(SOUND_69);
            }

            if (gSamusEnvironmentalEffects[offset].unk_6 == 0)
                return;

            gSamusEnvironmentalEffects[offset].xPosition = xPosition;
            gSamusEnvironmentalEffects[offset].yPosition = gSamusData.yPosition;
            break;

        case ENV_REQUEST_SKIDDING_EFFECT:
            currentEffect = ClipdataGetGroundEffect(gSamusData.yPosition + ONE_SUB_PIXEL, gSamusData.xPosition);

            if (currentEffect == GROUND_EFFECT_WET_GROUND)
            {
                gSamusEnvironmentalEffects[offset].effect = ENV_EFFECT_SKIDDING_ON_WET_GROUND;
                gSamusEnvironmentalEffects[offset].unk_6++;
            }
            else if (currentEffect == GROUND_EFFECT_DUSTY_GROUND || currentEffect == GROUND_EFFECT_VERY_DUSTY_GROUND)
            {
                gSamusEnvironmentalEffects[offset].effect = ENV_EFFECT_SKIDDING_ON_DUSTY_GROUND;
                gSamusEnvironmentalEffects[offset].unk_6++;
            }

            if (gSamusEnvironmentalEffects[offset].unk_6 == 0)
                return;

            gSamusEnvironmentalEffects[offset].xPosition = gSamusData.xPosition;
            gSamusEnvironmentalEffects[offset].yPosition = gSamusData.yPosition;
            break;

        case ENV_REQUEST_LANDING_EFFECT:
            currentEffect = ClipdataGetGroundEffect(gSamusData.yPosition + ONE_SUB_PIXEL, gSamusData.xPosition);

            if (currentEffect == GROUND_EFFECT_WET_GROUND)
            {
                gSamusEnvironmentalEffects[offset].effect = ENV_EFFECT_LANDING_ON_WET_GROUND;
                gSamusEnvironmentalEffects[offset].unk_6++;
                SoundPlay(SOUND_78);
            }
            else if (currentEffect == GROUND_EFFECT_BUBBLY_GROUND)
            {
                gSamusEnvironmentalEffects[offset].effect = ENV_EFFECT_LANDING_ON_BUBBLY_GROUND;
                gSamusEnvironmentalEffects[offset].unk_6++;

                if (gSamusPhysics.slowed == TRUE)
                    SoundPlay(SOUND_7B);
            }
            else if (currentEffect == GROUND_EFFECT_DUSTY_GROUND)
            {
                gSamusEnvironmentalEffects[offset].effect = ENV_EFFECT_LANDING_ON_DUSTY_GROUND;
                gSamusEnvironmentalEffects[offset].unk_6++;
                SoundPlay(SOUND_79);
            }
            else if (currentEffect == GROUND_EFFECT_VERY_DUSTY_GROUND)
            {
                gSamusEnvironmentalEffects[offset].effect = ENV_EFFECT_LANDING_ON_VERY_DUSTY_GROUND;
                gSamusEnvironmentalEffects[offset].unk_6++;
                SoundPlay(SOUND_7A);
            }
            else if (gSamusPhysics.slowed == TRUE)
            {
                SoundPlay(SOUND_97);
            }
            else if (gSamusDataCopy.lastWallTouchedMidAir != 0)
            {
                SoundPlay(SOUND_75);
            }
            else
            {
                SoundPlay(SOUND_74);
            }

            if (gSamusEnvironmentalEffects[offset].unk_6 == 0)
                return;

            gSamusEnvironmentalEffects[offset].xPosition = gSamusData.xPosition;
            gSamusEnvironmentalEffects[offset].yPosition = gSamusData.yPosition;
            break;

        case ENV_REQUEST_JUMPING_IN_OR_OUT_OF_WATER:
            currentEffect = ClipdataCheckCurrentAffectingAtPosition(gSamusData.yPosition, gSamusData.xPosition);
            currentEffect = LOW_BYTE(currentEffect);
            previousEffect = ClipdataCheckCurrentAffectingAtPosition(gPreviousYPosition, gSamusData.xPosition);
            previousEffect = LOW_BYTE(previousEffect);

            if (gSamusData.yPosition < gPreviousYPosition)
            {
                if (currentEffect != HAZARD_WATER && previousEffect == HAZARD_WATER)
                {
                    gSamusEnvironmentalEffects[offset].effect = ENV_EFFECT_JUMPING_IN_OR_OUT_OF_WATER;
                    gSamusEnvironmentalEffects[offset].unk_6++;
                }
            }
            else
            {
                if (currentEffect == HAZARD_WATER && previousEffect != HAZARD_WATER)
                {
                    gSamusEnvironmentalEffects[offset].effect = ENV_EFFECT_JUMPING_IN_OR_OUT_OF_WATER;
                    gSamusEnvironmentalEffects[offset].unk_6++;
                }
            }

            if (gSamusEnvironmentalEffects[offset].unk_6 == 0)
                return;

            gSamusEnvironmentalEffects[offset].xPosition = gSamusData.xPosition;

            // Get Y position
            if (gEffectYPosition != 0)
            {
                // Snap to effect position
                gSamusEnvironmentalEffects[offset].yPosition = gEffectYPosition;
            }
            else
            {
                // Use block position
                if (gSamusData.yPosition < gPreviousYPosition)
                    gSamusEnvironmentalEffects[offset].yPosition = gPreviousYPosition & BLOCK_POSITION_FLAG;
                else
                    gSamusEnvironmentalEffects[offset].yPosition = gSamusData.yPosition & BLOCK_POSITION_FLAG;
            }
            break;

        case ENV_REQUEST_WALKING_IN_OR_OUT_OF_WATER:
            currentEffect = ClipdataCheckCurrentAffectingAtPosition(gSamusData.yPosition, gSamusData.xPosition);
            currentEffect = LOW_BYTE(currentEffect);
            previousEffect = ClipdataCheckCurrentAffectingAtPosition(gPreviousYPosition, gSamusData.xPosition);
            previousEffect = LOW_BYTE(previousEffect);

            if (gSamusData.yPosition < gPreviousYPosition)
            {
                if (currentEffect != HAZARD_WATER && previousEffect == HAZARD_WATER)
                {
                    gSamusEnvironmentalEffects[offset].effect = ENV_EFFECT_WALKING_IN_OR_OUT_OF_WATER;
                    gSamusEnvironmentalEffects[offset].unk_6++;
                }
            }
            else
            {
                if (currentEffect == HAZARD_WATER && previousEffect != HAZARD_WATER)
                {
                    gSamusEnvironmentalEffects[offset].effect = ENV_EFFECT_WALKING_IN_OR_OUT_OF_WATER;
                    gSamusEnvironmentalEffects[offset].unk_6++;
                }
            }

            if (gSamusEnvironmentalEffects[offset].unk_6 == 0)
                return;

            gSamusEnvironmentalEffects[offset].xPosition = gSamusData.xPosition;

            // Get Y position
            if (gEffectYPosition != 0)
            {
                // Snap to effect position
                gSamusEnvironmentalEffects[offset].yPosition = gEffectYPosition;
            }
            else
            {
                // Use block position
                if (gSamusData.yPosition < gPreviousYPosition)
                    gSamusEnvironmentalEffects[offset].yPosition = gPreviousYPosition & BLOCK_POSITION_FLAG;
                else
                    gSamusEnvironmentalEffects[offset].yPosition = gSamusData.yPosition & BLOCK_POSITION_FLAG;
            }
            break;

        case ENV_REQUEST_BREATHING_BUBBLES:
            // Breathing bubbles can only be active if Samus is grounded, or hanging on a vertical ladder
            if (gSamusData.standingStatus != STANDING_MID_AIR || gSamusData.pose == SPOSE_HANGING_FROM_VERTICAL_LADDER)
            {
                gSamusEnvironmentalEffects[offset].effect = ENV_EFFECT_BREATHING_BUBBLES;
                gSamusEnvironmentalEffects[offset].unk_6++;
                gSamusEnvironmentalEffects[0].timer1 = 0;

                // Position the bubbles a bit above Samus
                gSamusEnvironmentalEffects[offset].yPosition = gSamusData.yPosition + gSamusData.drawDistanceTop + QUARTER_BLOCK_SIZE;

                // Position the bubbles in front of Samus
                if (gSamusData.direction & KEY_RIGHT)
                    gSamusEnvironmentalEffects[offset].xPosition = gSamusData.xPosition + (QUARTER_BLOCK_SIZE - PIXEL_SIZE);
                else
                    gSamusEnvironmentalEffects[offset].xPosition = gSamusData.xPosition - (QUARTER_BLOCK_SIZE - PIXEL_SIZE);

                SoundPlay(SOUND_93);
            }
            break;
    }

    if (gSamusEnvironmentalEffects[offset].unk_6 != 0)
        gSamusEnvironmentalEffects[offset].currentAnimationFrame = 0;
}

/**
 * @brief 55d4 | 4a0 | Updates both Samus environmental effects
 * 
 */
void SamusUpdateEnvironmentEffect(void)
{
    u32 affecting;
    u32 affectingAbove;
    u8 i;
    const struct FrameData* pOam;
    u8 effect;
    
    gSamusEnvironmentalEffects[0].unk_6 = 0;
    gSamusEnvironmentalEffects[1].unk_6 = 0;

    switch (gSamusData.pose)
    {
        case SPOSE_MID_AIR:
        case SPOSE_TURNING_AROUND_MID_AIR:
        case SPOSE_STARTING_SPIN_JUMP:
        case SPOSE_SPINNING:
        case SPOSE_MORPH_BALL_MID_AIR:
        case SPOSE_GETTING_HURT:
        case SPOSE_GETTING_HURT_IN_MORPH_BALL:
        case SPOSE_GETTING_KNOCKED_BACK:
        case SPOSE_GETTING_KNOCKED_BACK_IN_MORPH_BALL:
        case SPOSE_WALL_JUMPING:
        case SPOSE_PULLING_UP_FROM_HANGING:
        case SPOSE_SPACE_JUMPING:
        case SPOSE_SCREW_ATTACKING:
        case SPOSE_FROZEN_AND_FALLING:
        case SPOSE_FROZEN_IN_MORPH_BALL_AND_FALLING:
        case SPOSE_DELAY_BEFORE_SHINESPARKING:
        case SPOSE_SHINESPARKING:
            if (gSamusData.yPosition < gPreviousYPosition)
                SamusCheckSetNewEnvironmentEffect(0, 3);
            else
                SamusCheckSetNewEnvironmentEffect(1, 3);
            break;

        case SPOSE_RUNNING:
        case SPOSE_ROLLING:
        case SPOSE_HANGING_FROM_VERTICAL_LADDER:
            if (gSamusData.yPosition < gPreviousYPosition)
                SamusCheckSetNewEnvironmentEffect(0, 4);
            else
                SamusCheckSetNewEnvironmentEffect(1, 4);
            break;
    }

    affecting = LOW_BYTE(ClipdataCheckCurrentAffectingAtPosition(gSamusData.yPosition - BLOCK_SIZE * 2, gSamusData.xPosition));

    if (affecting == HAZARD_WATER)
    {
        if (gSamusEnvironmentalEffects[0].timer1 <= 0xDB)
            gSamusEnvironmentalEffects[0].timer1++;
        else if (gSamusEnvironmentalEffects[0].effect == 0x0)
            SamusCheckSetNewEnvironmentEffect(0, 5);
        else if (gSamusEnvironmentalEffects[1].effect == 0x0)
            SamusCheckSetNewEnvironmentEffect(1, 5);
    }

    if (gSamusData.pose == SPOSE_DYING)
    {
        gSamusEnvironmentalEffects[0].effect = 0x0;
        gSamusEnvironmentalEffects[1].effect = 0x0;
    }
    else if (gSamusEnvironmentalEffects[1].effect == 0)
    {
        affecting = LOW_BYTE(ClipdataCheckCurrentAffectingAtPosition(gSamusData.yPosition, gSamusData.xPosition));
        affectingAbove = LOW_BYTE(ClipdataCheckCurrentAffectingAtPosition(gSamusData.yPosition + gSamusData.drawDistanceTop - EIGHTH_BLOCK_SIZE, gSamusData.xPosition));

        if (affecting == HAZARD_LAVA && affectingAbove != HAZARD_LAVA)
        {
            if (!(gEquipment.suitMiscStatus & (SMF_GRAVITY_SUIT | SMF_SA_X_SUIT)))
            {
                gSamusEnvironmentalEffects[1].effect = 0x7;
                gSamusEnvironmentalEffects[1].currentAnimationFrame = 0;

                SoundPlay(SOUND_8C);
            }
        }
        else if (affecting == HAZARD_ACID && affectingAbove != HAZARD_ACID)
        {
            gSamusEnvironmentalEffects[1].effect = 0x7;
            gSamusEnvironmentalEffects[1].currentAnimationFrame = 0;

            SoundPlay(SOUND_8C);
        }

        if (gEffectYPosition != 0)
            gSamusEnvironmentalEffects[1].yPosition = gEffectYPosition;
    }

    for (i = 0; i < ARRAY_SIZE(gSamusEnvironmentalEffects); i++)
    {
        effect = gSamusEnvironmentalEffects[i].effect;
        if (effect != 0x0)
            gSamusEnvironmentalEffects[i].animationDurationCounter++;

        switch (effect)
        {
            case 0x1:
            case 0x3:
                if (gSamusEnvironmentalEffects[i].animationDurationCounter >= sSamusEnvironmentalEffectOam_3ecba4[gSamusEnvironmentalEffects[i].currentAnimationFrame].timer)
                {
                    gSamusEnvironmentalEffects[i].animationDurationCounter = 0;
                    gSamusEnvironmentalEffects[i].currentAnimationFrame++;

                    if (sSamusEnvironmentalEffectOam_3ecba4[gSamusEnvironmentalEffects[i].currentAnimationFrame].timer == 0)
                    {
                        gSamusEnvironmentalEffects[i].effect = 0x0;
                        gSamusEnvironmentalEffects[i].currentAnimationFrame = 0;
                    }
                }
                break;

            case 0x4:
                if (gSamusEnvironmentalEffects[i].animationDurationCounter >= sSamusEnvironmentalEffectOam_3ecd34[gSamusEnvironmentalEffects[i].currentAnimationFrame].timer)
                {
                    gSamusEnvironmentalEffects[i].animationDurationCounter = 0;
                    gSamusEnvironmentalEffects[i].currentAnimationFrame++;

                    if (sSamusEnvironmentalEffectOam_3ecd34[gSamusEnvironmentalEffects[i].currentAnimationFrame].timer == 0)
                    {
                        gSamusEnvironmentalEffects[i].effect = 0x0;
                        gSamusEnvironmentalEffects[i].currentAnimationFrame = 0;
                    }
                }
                break;

            case 0x5:
                if (gSamusEnvironmentalEffects[i].animationDurationCounter >= sSamusEnvironmentalEffectOam_3ecd94[gSamusEnvironmentalEffects[i].currentAnimationFrame].timer)
                {
                    gSamusEnvironmentalEffects[i].animationDurationCounter = 0;
                    gSamusEnvironmentalEffects[i].currentAnimationFrame++;

                    if (gSamusEnvironmentalEffects[i].currentAnimationFrame == 1)
                    {
                        SoundPlay(SOUND_76);
                    }
                    else if (sSamusEnvironmentalEffectOam_3ecd94[gSamusEnvironmentalEffects[i].currentAnimationFrame].timer == 0)
                    {
                        gSamusEnvironmentalEffects[i].effect = 0x0;
                        gSamusEnvironmentalEffects[i].currentAnimationFrame = 0;
                    }
                }
                break;

            case 0x6:
                if (gSamusEnvironmentalEffects[i].animationDurationCounter >= sSamusEnvironmentalEffectOam_3eceb4[gSamusEnvironmentalEffects[i].currentAnimationFrame].timer)
                {
                    gSamusEnvironmentalEffects[i].animationDurationCounter = 0;
                    gSamusEnvironmentalEffects[i].currentAnimationFrame++;

                    if (gSamusEnvironmentalEffects[i].currentAnimationFrame == 1)
                    {
                        SoundPlay(SOUND_77);
                    }
                    else if (sSamusEnvironmentalEffectOam_3eceb4[gSamusEnvironmentalEffects[i].currentAnimationFrame].timer == 0)
                    {
                        gSamusEnvironmentalEffects[i].effect = 0x0;
                        gSamusEnvironmentalEffects[i].currentAnimationFrame = 0;
                    }
                }
                break;

            case 0x7:
                gSamusEnvironmentalEffects[i].xPosition = gSamusData.xPosition;
                
                if (gSamusEnvironmentalEffects[i].animationDurationCounter >= sSamusEnvironmentalEffectOam_3ecc74[gSamusEnvironmentalEffects[i].currentAnimationFrame].timer)
                {
                    gSamusEnvironmentalEffects[i].animationDurationCounter = 0;
                    gSamusEnvironmentalEffects[i].currentAnimationFrame++;

                    if (sSamusEnvironmentalEffectOam_3ecc74[gSamusEnvironmentalEffects[i].currentAnimationFrame].timer == 0)
                    {
                        gSamusEnvironmentalEffects[i].effect = 0x0;
                        gSamusEnvironmentalEffects[i].currentAnimationFrame = 0;
                    }
                }
                break;

            case 0x8:
            case 0xA:
                if (gSamusEnvironmentalEffects[i].animationDurationCounter >= sSamusEnvironmentalEffectOam_3ecbd4[gSamusEnvironmentalEffects[i].currentAnimationFrame].timer)
                {
                    gSamusEnvironmentalEffects[i].animationDurationCounter = 0;
                    gSamusEnvironmentalEffects[i].currentAnimationFrame++;

                    if (sSamusEnvironmentalEffectOam_3ecbd4[gSamusEnvironmentalEffects[i].currentAnimationFrame].timer == 0)
                    {
                        gSamusEnvironmentalEffects[i].effect = 0x0;
                        gSamusEnvironmentalEffects[i].currentAnimationFrame = 0;
                    }
                }
                break;

            case 0x9:
                if (gSamusEnvironmentalEffects[i].animationDurationCounter >= sSamusEnvironmentalEffectOam_3eccec[gSamusEnvironmentalEffects[i].currentAnimationFrame].timer)
                {
                    gSamusEnvironmentalEffects[i].animationDurationCounter = 0;
                    gSamusEnvironmentalEffects[i].currentAnimationFrame++;

                    if (sSamusEnvironmentalEffectOam_3eccec[gSamusEnvironmentalEffects[i].currentAnimationFrame].timer == 0)
                    {
                        gSamusEnvironmentalEffects[i].effect = 0x0;
                        gSamusEnvironmentalEffects[i].currentAnimationFrame = 0;
                    }
                }
                break;

            case 0xB:
                if (gSamusEnvironmentalEffects[i].animationDurationCounter >= sSamusEnvironmentalEffectOam_3ecd5c[gSamusEnvironmentalEffects[i].currentAnimationFrame].timer)
                {
                    gSamusEnvironmentalEffects[i].animationDurationCounter = 0;
                    gSamusEnvironmentalEffects[i].currentAnimationFrame++;

                    if (sSamusEnvironmentalEffectOam_3ecd5c[gSamusEnvironmentalEffects[i].currentAnimationFrame].timer == 0)
                    {
                        gSamusEnvironmentalEffects[i].effect = 0x0;
                        gSamusEnvironmentalEffects[i].currentAnimationFrame = 0;
                    }
                }
                break;

            case 0xC:
                if (gSamusEnvironmentalEffects[i].animationDurationCounter >= sSamusEnvironmentalEffectOam_3ecbd4[gSamusEnvironmentalEffects[i].currentAnimationFrame].timer)
                {
                    gSamusEnvironmentalEffects[i].animationDurationCounter = 0;
                    gSamusEnvironmentalEffects[i].currentAnimationFrame++;

                    if (i == 0 && gSamusEnvironmentalEffects[i].currentAnimationFrame == 3)
                    {
                        SamusCheckSetNewEnvironmentEffect(1, 1);
                    }
                    else if (sSamusEnvironmentalEffectOam_3ecbd4[gSamusEnvironmentalEffects[i].currentAnimationFrame].timer == 0)
                    {
                        gSamusEnvironmentalEffects[i].effect = 0x0;
                        gSamusEnvironmentalEffects[i].currentAnimationFrame = 0;
                    }
                }
                break;

            case 0xD:
                if (gSamusEnvironmentalEffects[i].animationDurationCounter >= sSamusEnvironmentalEffectOam_3ecc34[gSamusEnvironmentalEffects[i].currentAnimationFrame].timer)
                {
                    gSamusEnvironmentalEffects[i].animationDurationCounter = 0;
                    gSamusEnvironmentalEffects[i].currentAnimationFrame++;

                    if (i == 0 && gSamusEnvironmentalEffects[i].currentAnimationFrame == 3)
                    {
                        SamusCheckSetNewEnvironmentEffect(1, 1);
                    }
                    else if (sSamusEnvironmentalEffectOam_3ecc34[gSamusEnvironmentalEffects[i].currentAnimationFrame].timer == 0)
                    {
                        gSamusEnvironmentalEffects[i].effect = 0x0;
                        gSamusEnvironmentalEffects[i].currentAnimationFrame = 0;
                    }
                }
                break;

            case 0xE:
                if (gSamusEnvironmentalEffects[i].animationDurationCounter >= sSamusEnvironmentalEffectOam_3ecddc[gSamusEnvironmentalEffects[i].currentAnimationFrame].timer)
                {
                    gSamusEnvironmentalEffects[i].animationDurationCounter = 0;
                    gSamusEnvironmentalEffects[i].currentAnimationFrame++;

                    if (sSamusEnvironmentalEffectOam_3ecddc[gSamusEnvironmentalEffects[i].currentAnimationFrame].timer == 0)
                    {
                        gSamusEnvironmentalEffects[i].effect = 0x0;
                        gSamusEnvironmentalEffects[i].currentAnimationFrame = 0;
                    }
                }
        }
        
        pOam = sEnvEffectOamPointers[effect - 1];
        pOam += gSamusEnvironmentalEffects[i].currentAnimationFrame;
        gSamusEnvironmentalEffects[i].pOamFrame = pOam->pFrame;
    }
}

/**
 * @brief 5a74 | 6c | Aims the arm cannon when Samus is standing
 * 
 */
void SamusAimCannonStanding(void)
{
    if (gButtonInput & gButtonAssignments.diagonalAim)
    {
        if (gButtonInput & KEY_DOWN)
        {
            // Aim diagonally down
            gSamusData.armCannonDirection = ACD_DIAGONAL_DOWN;
            gSamusData.diagonalAim = DIAG_AIM_DOWN;
        }
        else if (gSamusData.diagonalAim == DIAG_AIM_NONE || gButtonInput & KEY_UP)
        {
            // Aim diagonally up
            gSamusData.armCannonDirection = ACD_DIAGONAL_UP;
            gSamusData.diagonalAim = DIAG_AIM_UP;
        }

        return;
    }

    gSamusData.diagonalAim = DIAG_AIM_NONE;

    if (gButtonInput & KEY_UP)
    {
        // Aim up
        gSamusData.armCannonDirection = ACD_UP;
    }
    else
    {
        // Aim forward
        gSamusData.armCannonDirection = ACD_FORWARD;
    }
}

/**
 * @brief 5ae0 | b4 | Aims the arm cannon when Samus is mid-air
 * 
 */
void SamusAimCannonMidAir(void)
{
    if (gButtonInput & gButtonAssignments.diagonalAim)
    {
        if (gButtonInput & KEY_DOWN)
        {
            // Aim diagonally down
            gSamusData.armCannonDirection = ACD_DIAGONAL_DOWN;
            gSamusData.diagonalAim = DIAG_AIM_DOWN;
        }
        else if (gSamusData.diagonalAim == DIAG_AIM_NONE || gButtonInput & KEY_UP)
        {
            // Aim diagonally up
            gSamusData.armCannonDirection = ACD_DIAGONAL_UP;
            gSamusData.diagonalAim = DIAG_AIM_UP;
        }

        return;
    }

    if (gButtonInput & KEY_UP)
    {
        if (gButtonInput & gSamusData.direction)
        {
            // Aim diagonally up
            gSamusData.armCannonDirection = ACD_DIAGONAL_UP;
        }
        else
        {
            // Aim up
            gSamusData.armCannonDirection = ACD_UP;
        }

        gSamusData.diagonalAim = DIAG_AIM_NONE;
        return;
    }

    if (gButtonInput & KEY_DOWN)
    {
        if (gButtonInput & gSamusData.direction)
        {
            // Aim diagonally down
            gSamusData.armCannonDirection = ACD_DIAGONAL_DOWN;
        }
        else
        {
            // Aim down
            gSamusData.armCannonDirection = ACD_DOWN;
        }

        gSamusData.diagonalAim = DIAG_AIM_NONE;
        return;
    }

    if (gSamusData.diagonalAim != DIAG_AIM_NONE || gSamusData.direction & gButtonInput)
    {
        // Aim forward
        gSamusData.armCannonDirection = ACD_FORWARD;
    }

    gSamusData.diagonalAim = DIAG_AIM_NONE;
}

/**
 * @brief 5b94 | 94 | Aims the arm cannon when Samus is running
 * 
 */
void SamusAimCannonRunning(void)
{
    if (gButtonInput & gButtonAssignments.diagonalAim)
    {
        if (gButtonInput & KEY_DOWN)
        {
            // Aim diagonally down
            gSamusData.armCannonDirection = ACD_DIAGONAL_DOWN;
            gSamusData.diagonalAim = DIAG_AIM_DOWN;
        }
        else if (gSamusData.diagonalAim == DIAG_AIM_NONE || gButtonInput & KEY_UP)
        {
            // Aim diagonally up
            gSamusData.armCannonDirection = ACD_DIAGONAL_UP;
            gSamusData.diagonalAim = DIAG_AIM_UP;
        }

        gSamusData.armRunningFlag = FALSE;
        return;
    }

    gSamusData.diagonalAim = DIAG_AIM_NONE;

    if (gButtonInput & KEY_UP)
    {
        // Aim diagonally up
        gSamusData.armCannonDirection = ACD_DIAGONAL_UP;
        gSamusData.armRunningFlag = FALSE;
        return;
    }

    if (gButtonInput & KEY_DOWN)
    {
        // Aim diagonally up
        gSamusData.armCannonDirection = ACD_DIAGONAL_DOWN;
        gSamusData.armRunningFlag = FALSE;
        return;
    }

    if (!gSamusData.armRunningFlag)
        gSamusData.armCannonDirection = ACD_FORWARD;
}

/**
 * @brief 5c28 | 5c | Aims the arm cannon when Samus is hanging on an horizontal ladder
 * 
 */
void SamusAimCannonHorizontalLadder(void)
{
    if (gButtonInput & gButtonAssignments.diagonalAim)
    {
        // Can only aim diagonally down
        gSamusData.armCannonDirection = ACD_DIAGONAL_DOWN;
        gSamusData.diagonalAim = DIAG_AIM_DOWN;
        return;
    }

    if (gButtonInput & KEY_DOWN)
    {
        // Holding down
        if (gSamusData.direction & gButtonInput)
        {
            // Holding down and the facing direction, so diagonally down
            gSamusData.armCannonDirection = ACD_DIAGONAL_DOWN;
        }
        else
        {
            // Holding only down
            gSamusData.armCannonDirection = ACD_DOWN;
        }
    }
    else
    {
        // Aim forward by default
        gSamusData.armCannonDirection = ACD_FORWARD;
    }

    gSamusData.diagonalAim = DIAG_AIM_NONE;
}

/**
 * @brief 5c84 | c0 | Checks if Samus is firing
 * 
 * @return u8 bool, firing
 */
u8 SamusCheckShooting(void)
{
    u8 fired;

    fired = FALSE;

    if (gSamusData.newProjectile == NEW_PROJ_NONE && gSamusData.cooldownTimer == 0)
    {
        if (gChangedInput & KEY_B)
        {
            if (!(gSamusData.weaponHighlighted & WH_MISSILES))
            {
                gSamusData.newProjectile = NEW_PROJ_BEAM;

                // Start charge counter as if we charged for a single frame
                gSamusData.chargeBeamCounter = DELTA_TIME;
            }
            else
            {
                gSamusData.newProjectile = NEW_PROJ_MISSILE;
            }

            fired++;
        }
    }

    if (!fired)
    {
        if (!(gSamusData.weaponHighlighted & WH_MISSILES))
        {
            if (gButtonInput & KEY_B)
            {
                if (gEquipment.beamStatus & BF_CHARGE_BEAM)
                {
                    if (gSamusData.chargeBeamCounter < CHARGE_BEAM_MAX_THRESHOLD)
                        APPLY_DELTA_TIME_INC(gSamusData.chargeBeamCounter);
                    else
                        gSamusData.chargeBeamCounter = CHARGE_BEAM_THRESHOLD;
                }
                else
                {
                    gSamusData.chargeBeamCounter = 0;
                }
            }
            else
            {
                if (gSamusData.chargeBeamCounter >= CHARGE_BEAM_THRESHOLD)
                {
                    gSamusData.newProjectile = NEW_PROJ_CHARGED_BEAM;
                    fired = TRUE;
                }
                else if (gSamusData.chargeBeamCounter > (u32)(CHARGE_BEAM_THRESHOLD * .4f))
                {
                    gSamusData.newProjectile = NEW_PROJ_BEAM;
                    fired = TRUE;
                }
    
                gSamusData.chargeBeamCounter = 0;
            }
        }
        else
        {
            gSamusData.chargeBeamCounter = 0;
        }
    }

    if (fired)
    {
        // Fired something, so set arm cannon to forward if it was hanging
        if (gSamusData.armCannonDirection == ACD_NONE)
        {
            gSamusData.armCannonDirection = ACD_FORWARD;
            gSamusData.armRunningFlag = FALSE;
        }
    }

    return fired;
}

/**
 * @brief 5d44 | 1a8 | Checks if Samus should have a new projectile
 * 
 */
void SamusCheckNewProjectile(void)
{
    gSamusData.shooting = FALSE;

    switch (gSamusData.pose)
    {
        case SPOSE_STANDING:
        case SPOSE_TURNING_AROUND:
        case SPOSE_SHOOTING:
        case SPOSE_RUNNING:
        case SPOSE_MID_AIR:
        case SPOSE_TURNING_AROUND_MID_AIR:
        case SPOSE_LANDING:
        case SPOSE_CROUCHING:
        case SPOSE_TURNING_AROUND_AND_CROUCHING:
        case SPOSE_SHOOTING_AND_CROUCHING:
        case SPOSE_STARTING_SPIN_JUMP:
        case SPOSE_SPINNING:
        case SPOSE_WALL_JUMPING:
        case SPOSE_SPACE_JUMPING:
        case SPOSE_SCREW_ATTACKING:
        case SPOSE_HANGING_FROM_VERTICAL_LADDER:
        case SPOSE_HOLDING_ARM_OUT_ON_VERTICAL_LADDER:
        case SPOSE_SHOOTING_ON_VERTICAL_LADDER:
        case SPOSE_HANGING_ON_HORIZONTAL_LADDER:
        case SPOSE_MOVING_ON_HORIZONTAL_LADDER:
        case SPOSE_TURNING_AROUND_ON_HORIZONTAL_LADDER:
        case SPOSE_DELAY_AFTER_SHOOTING_ON_HORIZONTAL_LADDER:
        case SPOSE_SHOOTING_ON_HORIZONTAL_LADDER:
            gSamusData.shooting = SamusCheckShooting();
            break;

        case SPOSE_MORPHING:
        case SPOSE_GETTING_HURT:
        case SPOSE_GETTING_KNOCKED_BACK:
        case SPOSE_STARTING_WALL_JUMP:
        case SPOSE_HANGING_ON_LEDGE:
        case SPOSE_PULLING_UP_FROM_HANGING:
        case SPOSE_PULLING_FORWARD_FROM_HANGING:
        case SPOSE_LOWERING_DOWN_TO_START_HANGING:
        case SPOSE_SKIDDING:
        case SPOSE_STARTING_TO_HOLD_ARM_OUT_ON_VERTICAL_LADDER:
        case SPOSE_STARTING_TO_PUT_ARM_AWAY_ON_VERTICAL_LADDER:
            if (gButtonInput & KEY_B)
            {
                if (gEquipment.beamStatus & BF_CHARGE_BEAM)
                {
                    if (gSamusData.chargeBeamCounter < CHARGE_BEAM_MAX_THRESHOLD)
                    {
                        gSamusData.chargeBeamCounter++;
                        break;
                    }
                    else
                    {
                        gSamusData.chargeBeamCounter = CHARGE_BEAM_THRESHOLD;
                        break;
                    }
                }
            }
            else
            {
                if (gSamusData.chargeBeamCounter >= CHARGE_BEAM_THRESHOLD)
                    gSamusData.newProjectile = NEW_PROJ_CHARGED_BEAM;
            }

            gSamusData.chargeBeamCounter = 0;
            break;

        case SPOSE_MORPH_BALL:
        case SPOSE_ROLLING:
        case SPOSE_MORPH_BALL_MID_AIR:
        case SPOSE_GRABBED_BY_ZAZABI:
            if (gChangedInput & KEY_B)
            {
                if (gSamusData.cooldownTimer == 0 && gEquipment.weaponsStatus & MBF_BOMBS)
                {
                    if (gSamusData.weaponHighlighted & WH_POWER_BOMB)
                        gSamusData.newProjectile = NEW_PROJ_POWER_BOMB;
                    else
                        gSamusData.newProjectile = NEW_PROJ_BOMB;
                }
            }

        default:
            gSamusData.chargeBeamCounter = 0;
    }
}

/**
 * @brief 5eec | 74 | Checks if Samus is standing on a pass through clipdata
 * 
 * @return u32 bool, standing on pass through clipdata
 */
u32 SamusCheckStandingOnDropThroughClipdata(void)
{
    u8 check;
    u32 blockRight;
    u32 blockLeft;

    check = FALSE;

    if (gSamusData.standingStatus != STANDING_ENEMY)
    {
        blockRight = ClipdataProcessForSamus(gSamusData.yPosition + ONE_SUB_PIXEL, gSamusData.xPosition + (HALF_BLOCK_SIZE - PIXEL_SIZE / 2));
        blockLeft = ClipdataProcessForSamus(gSamusData.yPosition + ONE_SUB_PIXEL, gSamusData.xPosition - (HALF_BLOCK_SIZE - PIXEL_SIZE / 2));

        if (LOW_BYTE(blockRight) == CLIPDATA_TYPE_PASS_THROUGH_BOTTOM)
        {
            if (!(blockLeft & CLIPDATA_TYPE_SOLID_FLAG))
                check = TRUE;
        }
        else if (!(blockRight & CLIPDATA_TYPE_SOLID_FLAG))
        {
            if (LOW_BYTE(blockLeft) == CLIPDATA_TYPE_PASS_THROUGH_BOTTOM)
                check = TRUE;
        }
    }

    return check;
}

/**
 * @brief 5f60 | 4c | Checks if Samus should jump or drop through
 * 
 * @return u32 bool, performed action
 */
u32 SamusSetForcedMovementForJumpingOrDropping(void)
{
    if (gChangedInput & KEY_A)
    {
        if (gButtonInput & KEY_DOWN && SamusCheckStandingOnDropThroughClipdata())
        {
            gSamusData.forcedMovement = FORCED_MOVEMENT_MID_AIR_DROP;
            return TRUE;
        }
    
        gSamusData.forcedMovement = FORCED_MOVEMENT_MID_AIR_JUMP;
        return TRUE;
    }

    return FALSE;
}

/**
 * @brief 5fac | 1c4 | Updates the weapon highlight and diffusion missile charge
 * 
 */
void SamusUpdateHighlightedWeaponsAndCharge(void)
{
    u8 weaponHighlight;

    weaponHighlight = WH_NONE;

    switch (gSamusData.pose)
    {
        case SPOSE_MORPH_BALL:
        case SPOSE_ROLLING:
        case SPOSE_MORPH_BALL_MID_AIR:
        case SPOSE_GETTING_HURT_IN_MORPH_BALL:
        case SPOSE_FROZEN_IN_MORPH_BALL:
        case SPOSE_FROZEN_IN_MORPH_BALL_AND_FALLING:
        case SPOSE_GRABBED_BY_ZAZABI:
            // In a morph ball pose, check to select power bombs
            if (gButtonInput & gButtonAssignments.armMissiles && gEquipment.weaponsStatus & MBF_POWER_BOMBS && gEquipment.currentPowerBombs != 0)
                weaponHighlight = WH_POWER_BOMB;
            break;

        case SPOSE_USING_ELEVATOR:
        case SPOSE_ON_SAVE_PAD:
        case SPOSE_ON_RECHARGE_OR_SECURITY_PAD:
        case SPOSE_TURNING_AROUND_TO_RECHARGE_OR_UNLOCK_DOORS:
        case SPOSE_DELAY_BEFORE_SHINESPARKING:
        case SPOSE_SHINESPARKING:
        case SPOSE_DELAY_AFTER_SHINESPARKING:
        case SPOSE_FROZEN:
        case SPOSE_FROZEN_AND_FALLING:
        case SPOSE_UNLOCKING_SECURITY:
        case SPOSE_SAVING:
        case SPOSE_ON_NAVIGATION_PAD:
        case SPOSE_DOWNLOADING_ABILITY:
        case SPOSE_BEING_RECHARGED:
        case SPOSE_FACING_FOREGROUND:
        case SPOSE_FACING_BACKGROUND:
        case SPOSE_UNLOCKING_HABITATIONS_DECK:
        case SPOSE_LOADING_SAVE:
        case SPOSE_DYING:
        case SPOSE_GRABBED_BY_YAKUZA:
            // In a "non moving" pose, reset the diffusion missile charge counter
            gSamusEnvironmentalEffects[1].externalTimer = 0;
            break;

        default:
            // In any other state, check to select missiles
            if (gButtonInput & gButtonAssignments.armMissiles && gEquipment.weaponsStatus & MBF_MISSILES && gEquipment.currentMissiles != 0)
            {
                weaponHighlight = WH_MISSILES;

                // Fire charged beam if ready when selecting missiles
                if (gSamusData.chargeBeamCounter >= CHARGE_BEAM_THRESHOLD)
                    gSamusData.newProjectile = NEW_PROJ_CHARGED_BEAM;
            }
    }

    if (weaponHighlight == WH_MISSILES && gEquipment.weaponsStatus & MBF_DIFFUSION_MISSILES)
    {
        // Update diffusion missiles charge counter
        if ((s8)gSamusEnvironmentalEffects[1].externalTimer >= 0)
            APPLY_DELTA_TIME_INC(gSamusEnvironmentalEffects[1].externalTimer);
    }
    else
    {
        gSamusEnvironmentalEffects[1].externalTimer = 0;
    }

    if (gSamusData.weaponHighlighted < weaponHighlight)
        SoundPlay(SOUND_91);

    gSamusData.weaponHighlighted = weaponHighlight;

    if (weaponHighlight != WH_NONE || gSamusData.newProjectile != NEW_PROJ_NONE)
    {
        gSamusData.chargeBeamCounter = 0;
        gSamusData.armRunningFlag = FALSE;
    }
}

/**
 * @brief 6170 | d0 | Sets the spinning pose for Samus
 * 
 */
void SamusSetSpinningPose(void)
{
    switch (gSamusData.pose)
    {
        case SPOSE_SPINNING:
        case SPOSE_WALL_JUMPING:
            if (gSamusPhysics.slowed)
            {
                // No change needed if slowed
                break;
            }

            if (gEquipment.suitMiscStatus & SMF_SCREW_ATTACK)
            {
                // Set screw attacking
                gSamusData.pose = SPOSE_SCREW_ATTACKING;
                break;
            }

            if (gEquipment.suitMiscStatus & SMF_SPACE_JUMP)
            {
                // Set space jumping
                gSamusData.pose = SPOSE_SPACE_JUMPING;
                break;
            }
            break;

        case SPOSE_SPACE_JUMPING:
            if (gEquipment.suitMiscStatus & SMF_SCREW_ATTACK)
            {
                // Screw attacking takes priority
                gSamusData.pose = SPOSE_SCREW_ATTACKING;
                break;
            }

            if (!(gEquipment.suitMiscStatus & SMF_SPACE_JUMP) || gSamusPhysics.slowed)
            {
                // Set spinning if doesn't have space jump or is slowed
                gSamusData.pose = SPOSE_SPINNING;
                gSamusData.currentAnimationFrame = 0;
            }
            break;

        case SPOSE_SCREW_ATTACKING:
            if (gSamusPhysics.slowed)
            {
                // Set spinning if slowed
                gSamusData.pose = SPOSE_SPINNING;
                gSamusData.currentAnimationFrame = 0;
                break;
            }

            if (gEquipment.suitMiscStatus & SMF_SCREW_ATTACK)
                break;

            // Screw attack was disabled, set new spinning pose
            if (gEquipment.suitMiscStatus & SMF_SPACE_JUMP)
                gSamusData.pose = SPOSE_SPACE_JUMPING;
            else
                gSamusData.pose = SPOSE_SPINNING;

            gSamusData.currentAnimationFrame = 0;
            break;
    }
}

/**
 * @brief 6240 | 50 | Applies an X acceleration to Samus
 * 
 * @param acceleration Acceleration
 * @param maxVelocity Max velocity
 */
void SamusApplyXAcceleration(s16 acceleration, s16 maxVelocity)
{
    if (gSamusData.direction & KEY_RIGHT)
    {
        gSamusData.xVelocity += acceleration;

        if (gSamusData.xVelocity > maxVelocity)
            gSamusData.xVelocity = maxVelocity;
    }
    else
    {
        gSamusData.xVelocity -= acceleration;

        if (gSamusData.xVelocity < -maxVelocity)
            gSamusData.xVelocity = -maxVelocity;
    }
}

/**
 * @brief 6290 | 168 | Handles Samus taking hazard/environmental damage
 * 
 * @return u32 bool, requesting hurt pose
 */
u32 SamusHazardDamage(void)
{
    u32 inEffect;
    u32 knockback;
    u32 damage;
    u32 hazard;

    if (gSamusData.pose == SPOSE_DYING)
        return FALSE;

    // Global hazard timer, used to determine when Samus gets hurt
    APPLY_DELTA_TIME_INC(gSamusEnvironmentalEffects[1].timer1);

    inEffect = FALSE;
    knockback = FALSE;
    damage = FALSE;

    // Get hazard
    hazard = LOW_BYTE(ClipdataCheckCurrentAffectingAtPosition(gSamusData.yPosition, gSamusData.xPosition));

    // Check for suit status, then for each hazard that can hurt Samus
    if (gEquipment.suitMiscStatus & (SMF_GRAVITY_SUIT | SMF_SA_X_SUIT))
    {
        if (hazard == HAZARD_ACID)
        {
            inEffect = TRUE;
            if (gSamusEnvironmentalEffects[1].timer1 > CONVERT_SECONDS(.05f))
                damage = TRUE;
        }
    }
    else if (gEquipment.suitMiscStatus & SMF_VARIA_SUIT)
    {
        if (hazard == HAZARD_ACID)
        {
            inEffect = TRUE;
            if (gSamusEnvironmentalEffects[1].timer1 > CONVERT_SECONDS(1.f / 60))
                damage = TRUE;
        }
        else if (hazard == HAZARD_LAVA)
        {
            inEffect = TRUE;
            if (gSamusEnvironmentalEffects[1].timer1 > CONVERT_SECONDS(1.f / 15))
                damage = TRUE;
        }
    }
    else
    {
        if (hazard == HAZARD_ACID)
        {
            inEffect = TRUE;
            // No need to check for the timer, take damage every frame
            damage = TRUE;
        }
        else if (hazard == HAZARD_COLD_KNOCKBACK)
        {
            inEffect = TRUE;
            if (gSamusEnvironmentalEffects[1].timer1 > CONVERT_SECONDS(.05f))
            {
                damage = TRUE;
                SoundPlay(SOUND_8F);
            }

            // Knockback timer
            if (APPLY_DELTA_TIME_INC_POST(gSamusEnvironmentalEffects[0].timer2) > CONVERT_SECONDS(1.45f))
            {
                gSamusEnvironmentalEffects[0].timer2 = 0;
                knockback = TRUE;
            }
        }
        else if (hazard == HAZARD_LAVA)
        {
            inEffect = TRUE;
            if (gSamusEnvironmentalEffects[1].timer1 > CONVERT_SECONDS(1.f / 30))
                damage = TRUE;
        }
        else if (hazard == HAZARD_HEAT || hazard == HAZARD_COLD)
        {
            inEffect = TRUE;
            if (gSamusEnvironmentalEffects[1].timer1 > CONVERT_SECONDS(.15f))
            {
                damage = TRUE;
                SoundPlay(SOUND_8F);
            }
        }
    }

    if (!inEffect)
    {
        // Not in any effect, clear all the timers
        gSamusEnvironmentalEffects[0].timer2 = 0;
        gSamusEnvironmentalEffects[1].timer1 = 0;
        gSamusEnvironmentalEffects[1].timer2 = 0;
    }
    else
    {
        // Check for hazard hurting sound
        switch (APPLY_DELTA_TIME_INC_POST(gSamusEnvironmentalEffects[1].timer2))
        {
            case DELTA_TIME:
            case CONVERT_SECONDS(.4f + 1.f / 30):
                // Only apply to liquid hazard
                if (hazard == HAZARD_LAVA || hazard == HAZARD_ACID)
                    SoundPlay(SOUND_8B);
                break;

            case CONVERT_SECONDS(.8f + 1.f / 30):
                unk_3b78(SOUND_SAMUS_HURT);
                gSamusEnvironmentalEffects[1].timer2 = 0;
        }

        if (damage)
        {
            // Reset hurting timer
            gSamusEnvironmentalEffects[1].timer1 = 0;
            gEquipment.currentEnergy--;
        }
    }

    // If dead or requires knockback, signal a hurt pose request
    if (gEquipment.currentEnergy == 0 || knockback)
        return TRUE;

    return FALSE;
}

/**
 * @brief 63f8 | 194 | Updates Samus
 * 
 * @return u32 New pose
 */
u32 SamusUpdate(void)
{
    u8 pose;
    u16 velocity;

    if (SamusHazardDamage())
        return SPOSE_HURT_REQUEST;

    // Update timers
    if (gSamusData.cooldownTimer != 0)
        APPLY_DELTA_TIME_DEC(gSamusData.cooldownTimer);

    if (gSamusData.unk_B != 0)
        APPLY_DELTA_TIME_DEC(gSamusData.unk_B);

    if (gSamusAnimationInfo.shinesparkTimer != 0)
    {
        if (gSamusAnimationInfo.shinesparkTimer % CONVERT_SECONDS(.25f + 1.f / 60) == CONVERT_SECONDS(1.f / 15))
            SoundPlay(SOUND_98);

        APPLY_DELTA_TIME_DEC(gSamusAnimationInfo.shinesparkTimer);
    }

    if (gUnk_300144f != 0)
    {
        APPLY_DELTA_TIME_DEC(gUnk_300144f);
        if (MOD_AND(gUnk_300144f, CONVERT_SECONDS(.25f + 1.f / 60)) == 0)
            gUnk_300144f = 0;
    }

    if (gPoseLock != 0)
    {
        // Pose locked, reset missile/beam charge counters
        gSamusEnvironmentalEffects[1].externalTimer = 0;
        gSamusData.chargeBeamCounter = 0;
    }

    SamusUpdateHighlightedWeaponsAndCharge();
    SamusSetSpinningPose();

    pose = SPOSE_NONE;

    if (gPoseLock == 0)
    {
        SamusCheckNewProjectile();
        pose = sSamusPoseFunctionsPointers[gSamusData.pose]();
    }
    else if (gPoseLock & 0x80)
    {
        if (gSamusData.pose == SPOSE_HIT_BY_OMEGA_METROID)
        {
            pose = sSamusPoseFunctionsPointers[gSamusData.pose]();
        }
        else
        {
            if (!(gEquipment.suitMiscStatus & SMF_SA_X_SUIT) && gSamusData.xVelocity == 0)
                gSamusData.xVelocity = -SUB_PIXEL_TO_VELOCITY(EIGHTH_BLOCK_SIZE + PIXEL_SIZE + ONE_SUB_PIXEL / 2.f);
        }
    }

    if (gSamusData.pose == SPOSE_SHINESPARKING)
    {
        gSamusData.speedboostingCounter = DELTA_TIME;
    }
    else
    {
        velocity = gSamusData.xVelocity + SAMUS_X_SPEEDBOOST_VELOCITY_CAP - 1;
        if (velocity >= SUB_PIXEL_TO_VELOCITY(HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE) - 1)
        {
            if (APPLY_DELTA_TIME_INC_POST(gSamusData.speedboostingCounter) >= CONVERT_SECONDS(1.f))
            {
                gSamusData.speedboostingCounter = CONVERT_SECONDS(.7f + 1.f / 30);
                SoundPlay(SOUND_6B);
            }
        }
        else
        {
            if (gSamusData.speedboostingCounter != 0)
                SoundStop(0x6A);

            gSamusData.speedboostingCounter = 0;
        }
    }

    // Some form of velocity cancel?
    if (gUnk_300144f & 0x80)
    {
        if (gSamusData.xVelocity < 0)
            gSamusData.xVelocity = 0;
    }
    else if (gUnk_300144f != 0)
    {
        if (gSamusData.xVelocity > 0)
            gSamusData.xVelocity = 0;
    }

    if (pose == SPOSE_NONE)
        pose = sSamusPoseGfxFunctionsPointers[gSamusData.pose]();

    return pose;
}

/**
 * @brief 658c | 4 | Samus inactivity handler
 * 
 * @return u8 New pose
 */
u8 SamusInactivity(void)
{
    return SPOSE_NONE;
}

/**
 * @brief 6590 | 160 | Samus standing handler
 * 
 * @return u8 New pose
 */
u8 SamusStanding(void)
{
    s32 clipdata;
    u8 diagAim;
    u8 acd;
    u16 offset;

    // Check to start a shinespark
    if (gChangedInput & KEY_A && gSamusAnimationInfo.shinesparkTimer != 0)
    {
        offset = sSamusCollisionOffsets[SCT_MID_AIR][SAMUS_HITBOX_TOP] - HALF_BLOCK_SIZE;
        if (SamusCheckCollisionAbove(SCT_STANDING, offset, TRUE) == SCD_NONE)
        {
            gSamusData.yPosition -= HALF_BLOCK_SIZE;
            return SPOSE_DELAY_BEFORE_SHINESPARKING;
        }
    }

    if (SamusSetForcedMovementForJumpingOrDropping())
        return SPOSE_MID_AIR_REQUEST;

    if (gButtonInput & gSamusData.direction)
        return SPOSE_RUNNING;

    if (gButtonInput & OPPOSITE_DIRECTION(gSamusData.direction))
    {
        // Shooting takes precedence over turning around, meaning that doing both at the same time will eat away the turn around for a single frame
        if (gSamusData.shooting)
            return SPOSE_SHOOTING;

        return SPOSE_TURNING_AROUND;
    }

    if (gChangedInput & KEY_DOWN)
    {
        // Check for down elevator
        clipdata = ClipdataCheckCurrentAffectingAtPosition(gSamusData.yPosition + PIXEL_SIZE, gSamusData.xPosition);
        if (HIGH_SHORT(clipdata) == CLIPDATA_MOVEMENT_ELEVATOR_DOWN)
        {
            gSamusData.xPosition = (gSamusData.xPosition & BLOCK_POSITION_FLAG) + HALF_BLOCK_SIZE;
            gSamusData.elevatorOrClimbingDirection = KEY_DOWN;
            return SPOSE_USING_ELEVATOR;
        }

        // Check for crouch
        if (gSamusData.diagonalAim == DIAG_AIM_NONE || gSamusData.armCannonDirection == ACD_DIAGONAL_DOWN)
        {
            if (gSamusPhysics.slowed == TRUE)
                SoundPlay(SOUND_95);
            else
                SoundPlay(SOUND_81);
    
            if (gSamusData.shooting)
                return SPOSE_SHOOTING_AND_CROUCHING;

            return SPOSE_CROUCHING;
        }
    }
    else if (gChangedInput & KEY_UP)
    {
        // Check for up elevator
        clipdata = ClipdataCheckCurrentAffectingAtPosition(gSamusData.yPosition + PIXEL_SIZE, gSamusData.xPosition);
        if (HIGH_SHORT(clipdata) == CLIPDATA_MOVEMENT_ELEVATOR_UP)
        {
            gSamusData.xPosition = (gSamusData.xPosition & BLOCK_POSITION_FLAG) + HALF_BLOCK_SIZE;
            gSamusData.elevatorOrClimbingDirection = KEY_UP;
            return SPOSE_USING_ELEVATOR;
        }
    }

    acd = gSamusData.armCannonDirection;
    diagAim = gSamusData.diagonalAim;

    SamusAimCannonStanding();

    // Prevents Samus from aiming up as long as the counter isn't 0, used to prevent instantly aiming up when going from crouching to standing
    if (gSamusData.counter != 0)
    {
        APPLY_DELTA_TIME_DEC(gSamusData.counter);
        if (gSamusData.armCannonDirection == ACD_UP)
        {
            gSamusData.armCannonDirection = acd;
            gSamusData.diagonalAim = diagAim;
        }
    }

    if (gSamusData.shooting && gSamusData.pose != SPOSE_SHOOTING)
        return SPOSE_SHOOTING;

    return SPOSE_NONE;
}

/**
 * @brief 66f0 | 44 | Samus standing graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusStandingGfx(void)
{
    if (gSamusData.animationDurationCounter >= sSamusAnim_Standing_Forward_Right[gSamusData.currentAnimationFrame].timer)
    {
        gSamusData.animationDurationCounter = 0;
        gSamusData.currentAnimationFrame++;
        if (sSamusAnim_Standing_Forward_Right[gSamusData.currentAnimationFrame].timer == 0)
            gSamusData.currentAnimationFrame = 0;
    }

    return SPOSE_NONE;
}

/**
 * @brief 6734 | bc | Samus turning around handler
 * 
 * @return u8 New pose
 */
u8 SamusTurningAround(void)
{
    u16 offset;

    // Check to start a shinespark
    if (gChangedInput & KEY_A && gSamusAnimationInfo.shinesparkTimer != 0)
    {
        offset = sSamusCollisionOffsets[SCT_MID_AIR][SAMUS_HITBOX_TOP] - HALF_BLOCK_SIZE;
        if (SamusCheckCollisionAbove(SCT_STANDING, offset, TRUE) == SCD_NONE)
        {
            gSamusData.yPosition -= HALF_BLOCK_SIZE;
            return SPOSE_DELAY_BEFORE_SHINESPARKING;
        }
    }

    // Check for crouch
    if (gChangedInput & KEY_DOWN && (gSamusData.diagonalAim == DIAG_AIM_NONE || gSamusData.armCannonDirection == ACD_DIAGONAL_DOWN))
    {
        // Don't return the value to smootly transition between the 2 turning around animations
        // otherwise the crouching turning animation would start from the beginning 
        gSamusData.pose = SPOSE_TURNING_AROUND_AND_CROUCHING;

        if (gSamusPhysics.slowed == TRUE)
            SoundPlay(SOUND_95);
        else
            SoundPlay(SOUND_81);
    }
    
    if (SamusSetForcedMovementForJumpingOrDropping())
        return SPOSE_MID_AIR_REQUEST;

    if (gSamusData.shooting)
    {
        if (gSamusData.pose == SPOSE_TURNING_AROUND_AND_CROUCHING)
            return SPOSE_SHOOTING_AND_CROUCHING;
        
        return SPOSE_SHOOTING;
    }

    return SPOSE_NONE;
}

/**
 * @brief 67f0 | 48 | Samus turning around graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusTurningAroundGfx(void)
{
    if (gSamusData.animationDurationCounter >= sSamusAnim_Turning_Forward_Right[gSamusData.currentAnimationFrame].timer)
    {
        gSamusData.animationDurationCounter = 0;
        gSamusData.currentAnimationFrame++;
        if (sSamusAnim_Turning_Forward_Right[gSamusData.currentAnimationFrame].timer == 0)
            return SPOSE_STANDING;
    }

    return SPOSE_NONE;
}

/**
 * @brief 6838 | 48 | Samus shooting graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusShootingGfx(void)
{
    if (gSamusData.animationDurationCounter >= sSamusAnim_Shooting_Forward_Right[gSamusData.currentAnimationFrame].timer)
    {
        gSamusData.animationDurationCounter = 0;
        gSamusData.currentAnimationFrame++;
        if (sSamusAnim_Shooting_Forward_Right[gSamusData.currentAnimationFrame].timer == 0)
            return SPOSE_STANDING;
    }

    return SPOSE_NONE;
}

/**
 * @brief 6880 | 108 | Samus running handler
 * 
 * @return u8 New pose
 */
u8 SamusRunning(void)
{
    s16 velocityCap;
    u16 velocity;

    // Check jumping
    if (gChangedInput & KEY_A)
    {
        if (gSamusPhysics.slowed && gSamusData.slopeType & gSamusData.direction)
            gSamusData.yPosition -= PIXEL_SIZE / 2;

        gSamusData.forcedMovement = FORCED_MOVEMENT_MID_AIR_JUMP;
        return SPOSE_MID_AIR_REQUEST;
    }

    velocityCap = gSamusPhysics.xVelocityCap;

    if (gEquipment.suitMiscStatus & SMF_SPEED_BOOSTER && !gSamusPhysics.slowed)
    {
        if (gSamusData.counter >= 140)
            velocityCap = SAMUS_X_SPEEDBOOST_VELOCITY_CAP;
        else if (gSamusData.counter >= 120)
            velocityCap = 0x8C;

        velocity = gSamusData.xVelocity + 0x3F;

        if (velocity > 0x7E)
        {
            if (gSamusData.counter < CONVERT_SECONDS(2.f) + TWO_THIRD_SECOND &&
                APPLY_DELTA_TIME_INC_POST(gSamusData.counter) == CONVERT_SECONDS(2.4f))
            {
                SoundPlay(SOUND_6A);
            }
        }
        else
        {
            gSamusData.counter = 0;
        }
    }
    else
    {
        gSamusData.counter = 0;
    }

    // Check still running
    if (gButtonInput & gSamusData.direction)
    {
        // Apply acceleration
        SamusApplyXAcceleration(gSamusPhysics.xAcceleration, velocityCap);

        // Aim cannon
        SamusAimCannonRunning();

        return SPOSE_NONE;
    }

    // Not holding the running direction anymore

    // Check was speedboosting to start skidding
    if (gSamusData.speedboostingCounter != 0)
        return SPOSE_SKIDDING;

    // Check shooting
    if (gSamusData.shooting)
        return SPOSE_SHOOTING;

    // Check standing or turning around
    if (!(gButtonInput & OPPOSITE_DIRECTION(gSamusData.direction)))
        return SPOSE_STANDING;

    return SPOSE_TURNING_AROUND;
}

/**
 * @brief 6988 | c8 | Samus running graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusRunningGfx(void)
{
    u8 timer;

    timer = sSamusAnim_Running_None_Right[gSamusData.currentAnimationFrame].timer;

    if (gSamusData.speedboostingCounter != 0)
        timer--;

    if (gSamusPhysics.slowed)
        timer *= 2;

    if (gSamusData.animationDurationCounter < timer)
        return SPOSE_NONE;

    gSamusData.animationDurationCounter = 0;
    gSamusData.currentAnimationFrame++;

    if (sSamusAnim_Running_None_Right[gSamusData.currentAnimationFrame].timer == 0)
    {
        gSamusData.currentAnimationFrame = 0;
        return SPOSE_NONE;
    }

    switch (gSamusData.currentAnimationFrame)
    {
        case 1:
            if (gSamusPhysics.slowed == TRUE)
                SoundPlay(SOUND_95);
            else
                SoundPlay(SOUND_64);
            break;

        case 6:
            if (gSamusPhysics.slowed == TRUE)
                SoundPlay(SOUND_95);
            else
                SoundPlay(SOUND_65);
            break;

        case 4:
        case 9:
            if (gSamusEnvironmentalEffects[0].effect == ENV_EFFECT_NONE)
                SamusCheckSetNewEnvironmentEffect(0, ENV_REQUEST_GROUND_EFFECT);
            else if (gSamusEnvironmentalEffects[1].effect == ENV_EFFECT_NONE)
                SamusCheckSetNewEnvironmentEffect(1, ENV_REQUEST_GROUND_EFFECT);
            break;
    }

    return SPOSE_NONE;
}

/**
 * @brief 6a50 | 124 | Samus mid-air handler
 * 
 * @return u8 New pose
 */
u8 SamusMidAir(void)
{
    u32 turning;
    s16 acceleration;

    if (gChangedInput & KEY_DOWN && gSamusData.armCannonDirection == ACD_DOWN && gEquipment.suitMiscStatus & SMF_MORPH_BALL)
    {
        SoundPlay(SOUND_7F);
        return SPOSE_MORPH_BALL_MID_AIR;
    }

    if (gChangedInput & KEY_A)
    {
        if (gSamusAnimationInfo.shinesparkTimer != 0)
            return SPOSE_DELAY_BEFORE_SHINESPARKING;

        if (!(gButtonInput & (KEY_UP | KEY_DOWN)))
        {
            gSamusData.pose = SPOSE_SPINNING;
            gSamusData.currentAnimationFrame = 0;
            gSamusData.animationDurationCounter = 0;
            return SPOSE_NONE;
        }
    }

    turning = FALSE;
    acceleration = gSamusPhysics.midAirXAcceleration;

    if (gButtonInput & gSamusData.direction)
    {
        SamusApplyXAcceleration(acceleration, gSamusPhysics.midAirXVelocityCap);
    }
    else
    {
        if (gButtonInput & OPPOSITE_DIRECTION(gSamusData.direction))
        {
            turning = TRUE;
        }
        else
        {
            // Apply decceleration
            if (gSamusData.xVelocity > 0)
            {
                gSamusData.xVelocity -= acceleration;
                if (gSamusData.xVelocity < 0)
                    gSamusData.xVelocity = 0;
            }
            else if (gSamusData.xVelocity < 0)
            {
                gSamusData.xVelocity += acceleration;
                if (gSamusData.xVelocity > 0)
                    gSamusData.xVelocity = 0;
            }
        }
    }

    SamusAimCannonMidAir();

    // Check turning
    if (turning)
        return SPOSE_TURNING_AROUND_MID_AIR;

    // Check terminate Y velocity if not pressing A and going up
    if (!(gButtonInput & KEY_A) && gSamusData.yVelocity > 0)
        gSamusData.yVelocity = 0;

    return SPOSE_NONE;
}

/**
 * @brief 6b74 | 70 | Samus mid-air graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusMidAirGfx(void)
{
    if (gSamusData.yVelocity >= 0)
    {
        if (gSamusData.currentAnimationFrame == 2)
            gSamusData.animationDurationCounter = 0;
    }
    else
    {
        if (gSamusData.currentAnimationFrame < 2)
            gSamusData.currentAnimationFrame = 2;
    }

    if (gSamusData.animationDurationCounter >= sSamusAnim_MidAir_None_Right[gSamusData.currentAnimationFrame].timer)
    {
        gSamusData.animationDurationCounter = 0;
        gSamusData.currentAnimationFrame++;
        if (sSamusAnim_MidAir_None_Right[gSamusData.currentAnimationFrame].timer == 0)
            gSamusData.currentAnimationFrame--;
    }

    return SPOSE_NONE;
}

/**
 * @brief 6be4 | 90 | Samus turning around mid-air handler
 * 
 * @return u8 New pose
 */
u8 SamusTurningAroundMidAir(void)
{
    if (gChangedInput & KEY_A)
    {
        if (gSamusAnimationInfo.shinesparkTimer != 0)
            return SPOSE_DELAY_BEFORE_SHINESPARKING;

        if (!(gButtonInput & (KEY_UP | KEY_DOWN)))
        {
            gSamusData.pose = SPOSE_SPINNING;
            gSamusData.direction ^= (KEY_RIGHT | KEY_LEFT);

            gSamusData.currentAnimationFrame = 0;
            gSamusData.animationDurationCounter = 0;

            gSamusData.turning = FALSE;
            return SPOSE_NONE;
        }
    }

    if (gSamusData.shooting)
    {
        gSamusData.forcedMovement = FORCED_MOVEMENT_MID_AIR_CARRY;
        return SPOSE_MID_AIR_REQUEST;
    }

    if (!(gButtonInput & KEY_A) && gSamusData.yVelocity > 0)
        gSamusData.yVelocity = 0;

    return SPOSE_NONE;
}

/**
 * @brief 6c74 | 50 | Samus turning around mid-air graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusTurningAroundMidAirGfx(void)
{
    if (gSamusData.animationDurationCounter >= sSamusAnim_TurningMidAir_Forward_Right[gSamusData.currentAnimationFrame].timer)
    {
        gSamusData.animationDurationCounter = 0;
        gSamusData.currentAnimationFrame++;
        if (sSamusAnim_TurningMidAir_Forward_Right[gSamusData.currentAnimationFrame].timer == 0)
        {
            gSamusData.forcedMovement = FORCED_MOVEMENT_MID_AIR_CARRY;
            return SPOSE_MID_AIR_REQUEST;
        }
    }

    return SPOSE_NONE;
}

/**
 * @brief 6cc4 | 68 | Samus landing graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusLandingGfx(void)
{
    if (gSamusData.animationDurationCounter >= sSamusAnim_Landing_None_Right[gSamusData.currentAnimationFrame].timer)
    {
        gSamusData.animationDurationCounter = 0;
        gSamusData.currentAnimationFrame++;
        if (sSamusAnim_Landing_None_Right[gSamusData.currentAnimationFrame].timer == 0)
        {
            if (gPoseLock != 0)
            {
                gPoseLock++;
                gPreventMovementTimer = CONVERT_SECONDS(8.5f + 1.f / 30);
                return SPOSE_FACING_FOREGROUND;
            }

            return SPOSE_STANDING;
        }
    }

    return SPOSE_NONE;
}

/**
 * @brief 6d2c | 240 | Samus crouching handler
 * 
 * @return u8 New pose
 */
u8 SamusCrouching(void)
{
    u16 offset;
    u16 offset2;
    u16 xPosition;
    u8 var_0;
    u32 collisionFlags;

    // Check to start a shinespark
    if (gChangedInput & KEY_A && gSamusAnimationInfo.shinesparkTimer != 0)
    {
        offset = sSamusCollisionOffsets[SCT_MID_AIR][SAMUS_HITBOX_TOP] - HALF_BLOCK_SIZE;
        if (SamusCheckCollisionAbove(SCT_STANDING, offset, TRUE) == SCD_NONE)
        {
            gSamusData.yPosition -= HALF_BLOCK_SIZE;
            return SPOSE_DELAY_BEFORE_SHINESPARKING;
        }
    }

    var_0 = 0;
    offset2 = sSamusCollisionOffsets[SCT_STANDING][SAMUS_HITBOX_TOP];
    collisionFlags = SamusCheckCollisionAbove(0, offset2, TRUE);

    if (collisionFlags == SCD_NONE)
    {
        var_0 = 0x4;
    }
    else if (collisionFlags == SCD_TOP_LEFT_MOST)
    {
        xPosition = gSamusData.xPosition + sSamusCollisionOffsets[SCT_STANDING][SAMUS_HITBOX_LEFT];
        var_0 = 0x1;
    }
    else if (collisionFlags == SCD_TOP_RIGHT_MOST)
    {
        xPosition = gSamusData.xPosition + sSamusCollisionOffsets[SCT_STANDING][SAMUS_HITBOX_RIGHT];
        var_0 = 0x2;
    }

    if (SamusSetForcedMovementForJumpingOrDropping())
    {
        if (var_0 != 0)
        {
            if (var_0 & 1)
                gSamusData.xPosition = (xPosition & BLOCK_POSITION_FLAG) - sSamusCollisionOffsets[SCT_STANDING][SAMUS_HITBOX_LEFT] + BLOCK_SIZE;
            else if (var_0 & 2)
                gSamusData.xPosition = (xPosition & BLOCK_POSITION_FLAG) - sSamusCollisionOffsets[SCT_STANDING][SAMUS_HITBOX_RIGHT] - ONE_SUB_PIXEL;

            return SPOSE_MID_AIR_REQUEST;
        }
    }
    else
    {
        if (var_0 != 0)
        {
            if (gChangedInput & KEY_UP && (gSamusData.diagonalAim == DIAG_AIM_NONE || gSamusData.armCannonDirection == DIAG_AIM_DOWN))
            {
                if (var_0 & 1)
                    gSamusData.xPosition = (xPosition & BLOCK_POSITION_FLAG) - sSamusCollisionOffsets[SCT_STANDING][SAMUS_HITBOX_LEFT] + BLOCK_SIZE;
                else if (var_0 & 2)
                    gSamusData.xPosition = (xPosition & BLOCK_POSITION_FLAG) - sSamusCollisionOffsets[SCT_STANDING][SAMUS_HITBOX_RIGHT] - ONE_SUB_PIXEL;

                gSamusData.counter = CONVERT_SECONDS(.1f);
                return SPOSE_STANDING;
            }
        }
    }

    if (gChangedInput & KEY_DOWN && gEquipment.suitMiscStatus & SMF_MORPH_BALL && (gSamusData.diagonalAim == DIAG_AIM_NONE || gSamusData.armCannonDirection == ACD_DIAGONAL_DOWN))
    {
        SoundPlay(SOUND_7F);
        return SPOSE_MORPHING;
    }

    SamusAimCannonStanding();

    if (gSamusData.armCannonDirection == ACD_UP)
        gSamusData.armCannonDirection = ACD_FORWARD;

    if (gSamusData.shooting && gSamusData.pose != SPOSE_SHOOTING_AND_CROUCHING)
        return SPOSE_SHOOTING_AND_CROUCHING;

    if (gButtonInput & OPPOSITE_DIRECTION(gSamusData.direction))
        return SPOSE_TURNING_AROUND_AND_CROUCHING;

    if (gButtonInput & gSamusData.direction)
    {
        if (var_0 != 0)
        {
            if (APPLY_DELTA_TIME_INC_POST(gSamusData.lastWallTouchedMidAir) >= CONVERT_SECONDS(.1f))
            {
                if (var_0 & 1)
                    gSamusData.xPosition = (xPosition & BLOCK_POSITION_FLAG) - sSamusCollisionOffsets[SCT_STANDING][SAMUS_HITBOX_LEFT] + BLOCK_SIZE;
                else if (var_0 & 2)
                    gSamusData.xPosition = (xPosition & BLOCK_POSITION_FLAG) - sSamusCollisionOffsets[SCT_STANDING][SAMUS_HITBOX_RIGHT] - ONE_SUB_PIXEL;

                return SPOSE_STANDING;
            }
        }
    }
    else
    {
        gSamusData.lastWallTouchedMidAir = 0;
    }

    return SPOSE_NONE;
}

/**
 * @brief 6f6c | 170 | Samus turning around and crouching handler
 * 
 * @return u8 New pose
 */
u8 SamusTurningAroundAndCrouching(void)
{
    u16 offset;
    u16 offset2;
    u16 xPosition;
    u32 var_0;
    u32 collisionFlags;

    // Check to start a shinespark
    if (gChangedInput & KEY_A && gSamusAnimationInfo.shinesparkTimer != 0)
    {
        offset = sSamusCollisionOffsets[SCT_MID_AIR][SAMUS_HITBOX_TOP] - HALF_BLOCK_SIZE;
        if (SamusCheckCollisionAbove(SCT_STANDING, offset, TRUE) == SCD_NONE)
        {
            gSamusData.yPosition -= HALF_BLOCK_SIZE;
            return SPOSE_DELAY_BEFORE_SHINESPARKING;
        }
    }

    var_0 = 0;
    offset2 = sSamusCollisionOffsets[SCT_STANDING][SAMUS_HITBOX_TOP];
    collisionFlags = SamusCheckCollisionAbove(0, offset2, TRUE);

    if (collisionFlags == SCD_NONE)
    {
        var_0 = 0x4;
    }
    else if (collisionFlags == SCD_TOP_LEFT_MOST)
    {
        xPosition = gSamusData.xPosition + sSamusCollisionOffsets[SCT_STANDING][SAMUS_HITBOX_LEFT];
        var_0 = 0x1;
    }
    else if (collisionFlags == SCD_TOP_RIGHT_MOST)
    {
        xPosition = gSamusData.xPosition + sSamusCollisionOffsets[SCT_STANDING][SAMUS_HITBOX_RIGHT];
        var_0 = 0x2;
    }

    if (var_0 != 0)
    {
        if (gChangedInput & KEY_UP && (gSamusData.diagonalAim == DIAG_AIM_NONE || gSamusData.armCannonDirection == DIAG_AIM_DOWN))
        {
            if (var_0 & 1)
                gSamusData.xPosition = (xPosition & BLOCK_POSITION_FLAG) - sSamusCollisionOffsets[SCT_STANDING][SAMUS_HITBOX_LEFT] + BLOCK_SIZE;
            else if (var_0 & 2)
                gSamusData.xPosition = (xPosition & BLOCK_POSITION_FLAG) - sSamusCollisionOffsets[SCT_STANDING][SAMUS_HITBOX_RIGHT] - ONE_SUB_PIXEL;

            // Don't return the value to smootly transition between the 2 turning around animations
            // otherwise the turning animation would start from the beginning 
            gSamusData.pose = SPOSE_TURNING_AROUND;
        }
    }

    if (SamusSetForcedMovementForJumpingOrDropping())
    {
        if (var_0 != 0)
        {
            if (var_0 & 1)
                gSamusData.xPosition = (xPosition & BLOCK_POSITION_FLAG) - sSamusCollisionOffsets[SCT_STANDING][SAMUS_HITBOX_LEFT] + BLOCK_SIZE;
            else if (var_0 & 2)
                gSamusData.xPosition = (xPosition & BLOCK_POSITION_FLAG) - sSamusCollisionOffsets[SCT_STANDING][SAMUS_HITBOX_RIGHT] - ONE_SUB_PIXEL;

            return SPOSE_MID_AIR_REQUEST;
        }
    }

    if (gSamusData.shooting)
    {
        if (gSamusData.pose == SPOSE_TURNING_AROUND)
            return SPOSE_SHOOTING;

        return SPOSE_SHOOTING_AND_CROUCHING;
    }

    return SPOSE_NONE;
}

/**
 * @brief 70dc | 48 | Samus turning around and crouching graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusTurningAroundAndCrouchingGfx(void)
{
    if (gSamusData.animationDurationCounter >= sSamusAnim_TurningAndCrouching_Forward_Right[gSamusData.currentAnimationFrame].timer)
    {
        gSamusData.animationDurationCounter = 0;
        gSamusData.currentAnimationFrame++;
        if (sSamusAnim_TurningAndCrouching_Forward_Right[gSamusData.currentAnimationFrame].timer == 0)
            return SPOSE_CROUCHING;
    }

    return SPOSE_NONE;
}

/**
 * @brief 7124 | 48 | Samus shooting and crouching graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusShootingAndCrouchingGfx(void)
{
    if (gSamusData.animationDurationCounter >= sSamusAnim_ShootingAndCrouching_Forward_Right[gSamusData.currentAnimationFrame].timer)
    {
        gSamusData.animationDurationCounter = 0;
        gSamusData.currentAnimationFrame++;
        if (sSamusAnim_ShootingAndCrouching_Forward_Right[gSamusData.currentAnimationFrame].timer == 0)
            return SPOSE_CROUCHING;
    }

    return SPOSE_NONE;
}

/**
 * @brief 716c | 4c | Samus starting spin jump graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusStartingSpinJumpGfx(void)
{
    if (gSamusData.animationDurationCounter >= sSamusAnim_StartingSpinJump_Right[gSamusData.currentAnimationFrame].timer)
    {
        gSamusData.animationDurationCounter = 0;
        gSamusData.currentAnimationFrame++;
        if (sSamusAnim_StartingSpinJump_Right[gSamusData.currentAnimationFrame].timer == 0)
        {
            gSamusData.pose = SPOSE_SPINNING;
            gSamusData.currentAnimationFrame = 0;
        }
    }

    return SPOSE_NONE;
}

/**
 * @brief 71b8 | 1c0 | Samus spinning handler
 * 
 * @return u8 New pose
 */
u8 SamusSpinning(void)
{
    s16 acceleration;
    s16 xOffset;
    u32 blockLow;
    u32 blockHigh;

    if (gSamusData.shooting)
    {
        gSamusData.forcedMovement = FORCED_MOVEMENT_MID_AIR_FALL;
        return SPOSE_MID_AIR_REQUEST;
    }

    if (!(gButtonInput & (KEY_RIGHT | KEY_LEFT)) && gButtonInput & (KEY_UP | KEY_DOWN))
    {
        gSamusData.forcedMovement = FORCED_MOVEMENT_MID_AIR_FALL;
        return SPOSE_MID_AIR_REQUEST;
    }

    SamusAimCannonMidAir();

    acceleration = gSamusPhysics.midAirXAcceleration;

    if (gEquipment.suitMiscStatus & SMF_SPACE_JUMP && !gSamusPhysics.slowed)
    {
        if (gChangedInput & KEY_A && gSamusData.yVelocity <= -SUB_PIXEL_TO_VELOCITY(EIGHTH_BLOCK_SIZE + ONE_SUB_PIXEL + ONE_SUB_PIXEL * .75f))
        {
            if (gEquipment.suitMiscStatus & SMF_HIGH_JUMP)
            {
                gSamusData.yVelocity = SAMUS_HIGH_JUMP_VELOCITY;
                return SPOSE_NONE;
            }
            else
            {
                gSamusData.yVelocity = SAMUS_LOW_JUMP_VELOCITY;
                return SPOSE_NONE;
            }
        }
    }
    else if (gSamusData.walljumpTimer != 0)
    {
        APPLY_DELTA_TIME_DEC(gSamusData.walljumpTimer);
        if (gSamusData.direction & gSamusData.lastWallTouchedMidAir)
        {
            if (gChangedInput & KEY_A)
            {
                // Get check offset
                if (gSamusData.lastWallTouchedMidAir & KEY_RIGHT)
                    xOffset = -(HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
                else
                    xOffset = (HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);

                blockLow = ClipdataProcessForSamus(gSamusData.yPosition, gSamusData.xPosition + xOffset) & CLIPDATA_TYPE_SOLID_FLAG;
                // Check has block
                if (blockLow)
                {
                    gSamusData.direction = gSamusData.lastWallTouchedMidAir;
                    return SPOSE_STARTING_WALL_JUMP;
                }
            }

            acceleration = 1;
        }
    }

    if (gButtonInput & OPPOSITE_DIRECTION(gSamusData.direction))
    {
        gSamusData.direction = OPPOSITE_DIRECTION(gSamusData.direction);

        // Cancel all X velocity, allows to directly turn around and not have to cancel the momentum manually
        gSamusData.xVelocity = 0;

        if (gSamusData.direction & gSamusData.lastWallTouchedMidAir)
        {
            if (gSamusData.lastWallTouchedMidAir & KEY_RIGHT)
                xOffset = -HALF_BLOCK_SIZE;
            else
                xOffset = HALF_BLOCK_SIZE;

            blockLow = ClipdataProcessForSamus(gSamusData.yPosition, gSamusData.xPosition + xOffset) & CLIPDATA_TYPE_SOLID_FLAG;
            blockHigh = ClipdataProcessForSamus(gSamusData.yPosition - BLOCK_SIZE, gSamusData.xPosition + xOffset) & CLIPDATA_TYPE_SOLID_FLAG;

            if (blockLow || blockHigh)
                gSamusData.walljumpTimer = CONVERT_SECONDS(1.f / 6);
        }
    }
    else
    {
        SamusApplyXAcceleration(acceleration, gSamusPhysics.midAirXVelocityCap);
    }

    if (!(gButtonInput & KEY_A) && gSamusData.yVelocity > 0)
        gSamusData.yVelocity = 0;

    return SPOSE_NONE;
}

/**
 * @brief 7378 | 84 | Samus spinning graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusSpinningGfx(void)
{
    u8 timer;

    timer = sSamusAnim_Spinning_Right[gSamusData.currentAnimationFrame].timer;

    if (gSamusPhysics.slowed)
        timer *= 2;

    if (gSamusData.animationDurationCounter >= timer)
    {
        gSamusData.animationDurationCounter = 0;
        gSamusData.currentAnimationFrame++;
        if (sSamusAnim_Spinning_Right[gSamusData.currentAnimationFrame].timer == 0)
            gSamusData.currentAnimationFrame = 0;
    }

    if (gSamusData.currentAnimationFrame == 0 && gSamusData.animationDurationCounter == 1)
    {
        if (gSamusPhysics.slowed == TRUE)
            SoundPlay(SOUND_94);
        else
            SoundPlay(SOUND_6E);
    }

    return SPOSE_NONE;
}

/**
 * @brief 73fc | 24 | Samus morphing handler
 * 
 * @return u8 New pose
 */
u8 SamusMorphing(void)
{
    if (gChangedInput & KEY_UP)
        gSamusData.pose = SPOSE_UNMORPHING;

    return SPOSE_NONE;
}

/**
 * @brief 7420 | 48 | Samus morphing graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusMorphingGfx(void)
{
    if (gSamusData.animationDurationCounter >= sSamusAnim_Morphing_Right[gSamusData.currentAnimationFrame].timer)
    {
        gSamusData.animationDurationCounter = 0;
        gSamusData.currentAnimationFrame++;
        if (sSamusAnim_Morphing_Right[gSamusData.currentAnimationFrame].timer == 0)
            return SPOSE_MORPH_BALL;
    }

    return SPOSE_NONE;
}

/**
 * @brief 7468 | f0 | Samus morph ball handler
 * 
 * @return u8 New pose
 */
u8 SamusMorphBall(void)
{
    u32 collision;
    u16 xPosition;
    u16 hitbox;

    // Check for morphball bounce
    if (gSamusData.forcedMovement > FORCED_MOVEMENT_MORPH_BALL_BOUNCE_BEFORE_JUMP + DELTA_TIME)
    {
        gSamusData.forcedMovement = FORCED_MOVEMENT_MID_AIR_JUMP;
        return SPOSE_MID_AIR_REQUEST;
    }

    if (gSamusData.forcedMovement >= FORCED_MOVEMENT_MORPH_BALL_BOUNCE_BEFORE_JUMP)
    {
        APPLY_DELTA_TIME_INC(gSamusData.forcedMovement);
        return SPOSE_NONE;
    }

    if (SamusSetForcedMovementForJumpingOrDropping())
    {
        if (gSamusData.forcedMovement != FORCED_MOVEMENT_MID_AIR_JUMP)
            return SPOSE_MID_AIR_REQUEST;

        if (gEquipment.suitMiscStatus & SMF_HIGH_JUMP)
            return SPOSE_MID_AIR_REQUEST;

        gSamusData.forcedMovement = 0;
    }

    // Check start rolling
    if (gButtonInput & (KEY_RIGHT | KEY_LEFT))
    {
        gSamusData.direction = gButtonInput & (KEY_RIGHT | KEY_LEFT);
        return SPOSE_ROLLING;
    }

    // Check unmorphing
    if (gChangedInput & KEY_UP)
    {
        hitbox = sSamusCollisionOffsets[SCT_STANDING][SAMUS_HITBOX_TOP];
        collision = SamusCheckCollisionAbove(SCT_STANDING, hitbox, TRUE);

        // Check for smooth unmorph if only slightly in a block

        // First clamp the position under to the block by adding the hitbox
        // Then remove the hitbox to have the position where Samus would be against the wall
        // Then if the block was on the left, add a single block to the position to put Samus in the correct block
        // Or if the block was on the right, remove one sub pixel
        if (collision == SCD_TOP_LEFT_MOST)
        {
            xPosition = gSamusData.xPosition;
            xPosition += sSamusCollisionOffsets[SCT_STANDING][SAMUS_HITBOX_LEFT];

            gSamusData.xPosition = (xPosition & BLOCK_POSITION_FLAG) - sSamusCollisionOffsets[SCT_STANDING][SAMUS_HITBOX_LEFT] + BLOCK_SIZE;

            collision = SCD_NONE;
        }
        else if (collision == SCD_TOP_RIGHT_MOST)
        {
            xPosition = gSamusData.xPosition;
            xPosition += sSamusCollisionOffsets[SCT_STANDING][SAMUS_HITBOX_RIGHT];

            gSamusData.xPosition = (xPosition & BLOCK_POSITION_FLAG) - sSamusCollisionOffsets[SCT_STANDING][SAMUS_HITBOX_RIGHT] - ONE_SUB_PIXEL;

            collision = SCD_NONE;
        }

        if (collision == SCD_NONE)
        {
            // Unmorph
            if (gSamusPhysics.slowed == TRUE)
                SoundPlay(SOUND_95);
            else
                SoundPlay(SOUND_80);

            return SPOSE_UNMORPHING;
        }
    }

    return SPOSE_NONE;
}

/**
 * @brief 7558 | 44 | Samus morph ball graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusMorphBallGfx(void)
{
    if (gSamusData.animationDurationCounter >= sSamusAnim_MorphBall_Right[gSamusData.currentAnimationFrame].timer)
    {
        gSamusData.animationDurationCounter = 0;
        gSamusData.currentAnimationFrame++;
        if (sSamusAnim_MorphBall_Right[gSamusData.currentAnimationFrame].timer == 0)
            gSamusData.currentAnimationFrame = 0;
    }

    return SPOSE_NONE;
}

/**
 * @brief 759c | bc | Samus rolling handler
 * 
 * @return u8 New pose
 */
u8 SamusRolling(void)
{
    u16 hitbox;

    if (gChangedInput & KEY_A && gEquipment.suitMiscStatus & SMF_HIGH_JUMP)
    {
        gSamusData.forcedMovement = FORCED_MOVEMENT_MID_AIR_JUMP;
        return SPOSE_MID_AIR_REQUEST;
    }

    hitbox = sSamusCollisionOffsets[SCT_STANDING][SAMUS_HITBOX_TOP];
    if (SamusCheckCollisionAbove(SCT_STANDING, hitbox, TRUE) == SCD_NONE && gChangedInput & KEY_UP)
    {
        if (gSamusPhysics.slowed == TRUE)
            SoundPlay(SOUND_95);
        else
            SoundPlay(SOUND_80);

        return SPOSE_UNMORPHING;
    }

    if (gButtonInput & gSamusData.direction)
    {
        SamusApplyXAcceleration(gSamusPhysics.xAcceleration, gSamusPhysics.xVelocityCap);
        return SPOSE_NONE;
    }

    if (gButtonInput & OPPOSITE_DIRECTION(gSamusData.direction))
        gSamusData.turning = TRUE;

    return SPOSE_MORPH_BALL;
}

/**
 * @brief 7658 | 38 | Samus unmorphing handler
 * 
 * @return u8 New pose
 */
u8 SamusUnmorphing(void)
{
    if (gChangedInput & KEY_A)
    {
        gSamusData.forcedMovement = FORCED_MOVEMENT_MID_AIR_JUMP;
        return SPOSE_MID_AIR_REQUEST;
    }

    if (gChangedInput & KEY_DOWN)
        gSamusData.pose = SPOSE_MORPHING;

    return SPOSE_NONE;
}

/**
 * @brief 7690 | 48 | Samus unmorphing graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusUnmorphingGfx(void)
{
    if (gSamusData.animationDurationCounter >= sSamusAnim_Unmorphing_Right[gSamusData.currentAnimationFrame].timer)
    {
        gSamusData.animationDurationCounter = 0;
        gSamusData.currentAnimationFrame++;
        if (sSamusAnim_Unmorphing_Right[gSamusData.currentAnimationFrame].timer == 0)
            return SPOSE_CROUCHING;
    }

    return SPOSE_NONE;
}

/**
 * @brief 76d8 | d0 | Samus morph ball mid-air handler
 * 
 * @return u8 New pose
 */
u8 SamusMorphBallMidAir(void)
{
    u16 hitbox;

    if (gChangedInput & KEY_UP)
    {
        hitbox = sSamusCollisionOffsets[SCT_MID_AIR][SAMUS_HITBOX_TOP];
        if (SamusCheckCollisionAbove(SCT_STANDING, hitbox, TRUE) == SCD_NONE)
        {
            if (gSamusPhysics.slowed == TRUE)
                SoundPlay(SOUND_95);
            else
                SoundPlay(SOUND_80);
    
            return SPOSE_MID_AIR;
        }
    }

    if (gSamusData.forcedMovement == 0)
    {
        // Check terminate Y velocity if not holding A and going up
        if (!(gButtonInput & KEY_A) && gSamusData.yVelocity > 0)
            gSamusData.yVelocity = 0;
    }
    else
    {
        // Morph ball bounce after landing
        if (gSamusData.yVelocity < SUB_PIXEL_TO_VELOCITY(ONE_SUB_PIXEL) - 1)
            gSamusData.forcedMovement = 0;
    }

    if (gSamusData.yVelocity >= 0 && gSamusData.xVelocity != 0)
    {
        // Move horizontally
        SamusApplyXAcceleration(gSamusPhysics.midAirXAcceleration, gSamusPhysics.midAirMorphedXVelocityCap);
    }
    else if (gButtonInput & gSamusData.direction)
    {
        // Move horizontally
        SamusApplyXAcceleration(gSamusPhysics.midAirXAcceleration, gSamusPhysics.midAirMorphedXVelocityCap);
    }
    else
    {
        // Check turning
        if (gButtonInput & OPPOSITE_DIRECTION(gSamusData.direction))
            gSamusData.direction ^= KEY_RIGHT | KEY_LEFT;

        // Terminate velocity if not holding forward
        gSamusData.xVelocity = 0;
    }

    return SPOSE_NONE;
}

/**
 * @brief 77a8 | 4c | Samus getting hurt graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusGettingHurtGfx(void)
{
    u32 collision;
    u16 hitbox;

    if (gSamusData.counter > CONVERT_SECONDS(.2f))
    {
        hitbox = sSamusCollisionOffsets[SCT_MID_AIR][SAMUS_HITBOX_TOP];
        collision = SamusCheckCollisionAbove(SCT_STANDING, hitbox, TRUE);

        if (gSamusData.yVelocity < -SUB_PIXEL_TO_VELOCITY(ONE_SUB_PIXEL) && collision == SCD_NONE)
        {
            if (gSamusData.pose == SPOSE_GETTING_HURT)
                return SPOSE_MID_AIR;

            return SPOSE_MORPH_BALL_MID_AIR;
        }
    }
    else
    {
        APPLY_DELTA_TIME_INC(gSamusData.counter);
    }

    return SPOSE_NONE;
}

/**
 * @brief 77f4 | 4c | Samus getting knocked back graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusGettingKnockedBackGfx(void)
{
    u32 collision;
    u16 hitbox;

    if (gSamusData.counter > CONVERT_SECONDS(.2f))
    {
        hitbox = sSamusCollisionOffsets[SCT_MID_AIR][SAMUS_HITBOX_TOP];
        collision = SamusCheckCollisionAbove(SCT_STANDING, hitbox, TRUE);

        if (gSamusData.yVelocity < -SUB_PIXEL_TO_VELOCITY(ONE_SUB_PIXEL * 2.5f) && collision == SCD_NONE)
        {
            if (gSamusData.pose == SPOSE_GETTING_KNOCKED_BACK)
                return SPOSE_MID_AIR;

            return SPOSE_MORPH_BALL_MID_AIR;
        }
    }
    else
    {
        APPLY_DELTA_TIME_INC(gSamusData.counter);
    }

    return SPOSE_NONE;
}

/**
 * @brief 7840 | 48 | Samus starting wall jump graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusStartingWallJumpGfx(void)
{
    if (gSamusData.animationDurationCounter >= sSamusAnim_StartingWallJump_Right[gSamusData.currentAnimationFrame].timer)
    {
        gSamusData.animationDurationCounter = 0;
        gSamusData.currentAnimationFrame++;
        if (sSamusAnim_StartingWallJump_Right[gSamusData.currentAnimationFrame].timer == 0)
            return SPOSE_MID_AIR_REQUEST;
    }

    return SPOSE_NONE;
}

/**
 * @brief 7888 | ec | Samus wall jumping handler
 * 
 * @return u8 New pose
 */
u8 SamusWallJumping(void)
{
    if (gSamusData.direction & KEY_RIGHT)
    {
        if (gSamusData.xVelocity < gSamusPhysics.midAirXVelocityCap)
            SamusApplyXAcceleration(gSamusPhysics.midAirXAcceleration, gSamusPhysics.midAirXVelocityCap);
    }
    else
    {
        if (gSamusData.xVelocity > -gSamusPhysics.midAirXVelocityCap)
            SamusApplyXAcceleration(gSamusPhysics.midAirXAcceleration, gSamusPhysics.midAirXVelocityCap);
    }

    if (gSamusData.shooting)
    {
        // Cancel if shooting
        gSamusData.forcedMovement = FORCED_MOVEMENT_MID_AIR_FALL;
        return SPOSE_MID_AIR_REQUEST;
    }

    // Check for spin break
    if (gSamusData.yVelocity <= 0 && !(gButtonInput & (KEY_RIGHT | KEY_LEFT)) && gButtonInput & (KEY_UP | KEY_DOWN))
    {
        gSamusData.forcedMovement = FORCED_MOVEMENT_MID_AIR_FALL;
        return SPOSE_MID_AIR_REQUEST;
    }

    // Aim cannon
    SamusAimCannonMidAir();

    // Cancel wall jump if slowed
    if (gSamusPhysics.slowed)
        gSamusData.pose = SPOSE_SPINNING;

    if (!(gButtonInput & KEY_A))
    {
        // Stop upwards Y velocity if released A
        if (gSamusData.yVelocity > 0)
            gSamusData.yVelocity = 0;

        // Set spinning
        gSamusData.pose = SPOSE_SPINNING;
    }
    else
    {
        if (gSamusData.yVelocity <= 0 && gButtonInput & OPPOSITE_DIRECTION(gSamusData.direction))
        {
            // Set spinning
            gSamusData.pose = SPOSE_SPINNING;
        }
    }

    return SPOSE_NONE;
}

/**
 * @brief 7974 | b8 | Samus using elevator handler
 * 
 * @return u8 New pose
 */
u8 SamusUsingElevator(void)
{
    u8 stop;
    u32 currentBlock;
    u32 previousBlock;
    s16 newPosition;

    if (gSamusData.elevatorOrClimbingDirection & KEY_UP && gSamusData.yVelocity > 0)
    {
        currentBlock = HIGH_SHORT(ClipdataCheckCurrentAffectingAtPosition(gSamusData.yPosition, gSamusData.xPosition));
        previousBlock = HIGH_SHORT(ClipdataCheckCurrentAffectingAtPosition(gSamusData.yPosition - (EIGHTH_BLOCK_SIZE + PIXEL_SIZE - PIXEL_SIZE / 2), gSamusData.xPosition));

        // Check hitting an elevator down block
        if (currentBlock == CLIPDATA_MOVEMENT_ELEVATOR_DOWN && previousBlock != CLIPDATA_MOVEMENT_ELEVATOR_DOWN)
        {
            // Snap to block
            newPosition = (gSamusData.yPosition & BLOCK_POSITION_FLAG) - ONE_SUB_PIXEL;
            gSamusData.yPosition = newPosition;
            gSamusData.currentAnimationFrame = 4;
            gSamusData.animationDurationCounter = 0;
            gSamusData.yVelocity = 0;
            SoundStop(0xFC);
        }
    }
    else if (gSamusData.elevatorOrClimbingDirection & KEY_DOWN && gSamusData.yVelocity < 0)
    {
        currentBlock = HIGH_SHORT(ClipdataCheckCurrentAffectingAtPosition(gSamusData.yPosition + EIGHTH_BLOCK_SIZE, gSamusData.xPosition));
        // Check hitting an elevator up block
        if (currentBlock == CLIPDATA_MOVEMENT_ELEVATOR_UP)
        {
            // Snap to block
            newPosition = gSamusData.yPosition | SUB_PIXEL_POSITION_FLAG;
            gSamusData.yPosition = newPosition;
            gSamusData.currentAnimationFrame = 4;
            gSamusData.animationDurationCounter = 0;
            gSamusData.yVelocity = 0;
            SoundStop(0xFC);
        }
    }

    return SPOSE_NONE;
}

/**
 * @brief 7a2c | 8c | Samus using elevator graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusUsingElevatorGfx(void)
{
    APPLY_DELTA_TIME_INC(gSamusAnimationInfo.paletteAnimationCounter);

    if (gSamusAnimationInfo.paletteAnimationCounter >= sArmCannonOam_UsingElevator[gSamusAnimationInfo.currentPaletteRow].timer)
    {
        gSamusAnimationInfo.paletteAnimationCounter = 0;
        gSamusAnimationInfo.currentPaletteRow++;

        if (sArmCannonOam_UsingElevator[gSamusAnimationInfo.currentPaletteRow].timer == 0)
            gSamusAnimationInfo.currentPaletteRow = 0;
    }

    if (gSamusData.animationDurationCounter >= sSamusAnim_UsingElevator_Right[gSamusData.currentAnimationFrame].timer)
    {
        gSamusData.animationDurationCounter = 0;
        gSamusData.currentAnimationFrame++;

        if (gSamusData.currentAnimationFrame != 4)
        {
            if (sSamusAnim_UsingElevator_Right[gSamusData.currentAnimationFrame].timer == 0)
                return SPOSE_FACING_FOREGROUND;
        }
        else
        {
            gSamusData.currentAnimationFrame--;
        }
    }

    return SPOSE_NONE;
}

/**
 * @brief 7ab8 | 15c | Samus hanging on ledge handler
 * 
 * @return u8 New pose
 */
u8 SamusHangingOnLedge(void)
{
    u16 xPosition;
    u32 blockSideFar;
    u32 blockAbove;
    u32 blockSideNear;
    s32 movementBlock;

    if (gScreenShakeX.timer >= CONVERT_SECONDS(.5f))
        return SPOSE_MID_AIR_REQUEST;

    if (gSamusData.direction & KEY_RIGHT)
        xPosition = gSamusData.xPosition + SAMUS_LEDGE_GRAB_X_RANGE;
    else
        xPosition = gSamusData.xPosition - SAMUS_LEDGE_GRAB_X_RANGE;

    blockSideFar = ClipdataProcessForSamus(gSamusData.yPosition - (BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE), xPosition) & CLIPDATA_TYPE_SOLID_FLAG;
    blockAbove = ClipdataProcessForSamus(gSamusData.yPosition - (BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE), gSamusData.xPosition) & CLIPDATA_TYPE_SOLID_FLAG;
    blockSideNear = ClipdataProcessForSamus(gSamusData.yPosition - (BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE), xPosition) & CLIPDATA_TYPE_SOLID_FLAG;

    if (gChangedInput & KEY_UP)
    {
        if (!blockAbove && !blockSideNear)
        {
            if (!(gEquipment.suitMiscStatus & SMF_MORPH_BALL) && blockSideFar)
                return SPOSE_LOWERING_DOWN_TO_START_HANGING;

            return SPOSE_PULLING_UP_FROM_HANGING;
        }

        return SPOSE_MID_AIR_REQUEST;
    }

    if (gChangedInput & KEY_A)
    {
        if (gButtonInput & KEY_DOWN)
            return SPOSE_MID_AIR_REQUEST;

        if (gButtonInput & OPPOSITE_DIRECTION(gSamusData.direction))
        {
            gSamusData.direction = OPPOSITE_DIRECTION(gSamusData.direction);
            return SPOSE_STARTING_WALL_JUMP;
        }

        if (gButtonInput & gSamusData.direction)
        {
            if (blockAbove)
                return SPOSE_MID_AIR_REQUEST;

            if (blockSideNear)
                return SPOSE_MID_AIR_REQUEST;

            if (gEquipment.suitMiscStatus & SMF_MORPH_BALL)
                return SPOSE_PULLING_UP_FROM_HANGING;

            if (!blockSideFar)
                return SPOSE_PULLING_UP_FROM_HANGING;
        }

        gSamusData.forcedMovement = FORCED_MOVEMENT_MID_AIR_CARRY;
        gSamusData.yVelocity = SUB_PIXEL_TO_VELOCITY(QUARTER_BLOCK_SIZE);
        return SPOSE_MID_AIR_REQUEST;
    }

    if (gChangedInput & KEY_DOWN)
        return SPOSE_MID_AIR_REQUEST;

    movementBlock = ClipdataCheckCurrentAffectingAtPosition(gSamusData.yPosition - (BLOCK_SIZE * 2 - PIXEL_SIZE), xPosition);

    if (HIGH_SHORT(movementBlock) == CLIPDATA_MOVEMENT_WALL_LADDER)
        return SPOSE_HANGING_FROM_VERTICAL_LADDER;

    return SPOSE_NONE;
}

/**
 * @brief 7c14 | 54 | Samus hanging on ledge graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusHangingOnLedgeGfx(void)
{
    u8 timer;

    timer = sSamusAnim_HangingOnLedge_Default_Right[gSamusData.currentAnimationFrame].timer;

    if (gSamusPhysics.slowed)
        timer *= 2;

    if (gSamusData.animationDurationCounter >= timer)
    {
        gSamusData.animationDurationCounter = 0;
        gSamusData.currentAnimationFrame++;
        if (sSamusAnim_HangingOnLedge_Default_Right[gSamusData.currentAnimationFrame].timer == 0)
            gSamusData.currentAnimationFrame = 3;
    }

    return SPOSE_NONE;
}

/**
 * @brief 7c68 | 10 | Samus pulling up from hanging handler
 * 
 * @return u8 New pose
 */
u8 SamusPullingUpFromHanging(void)
{
    gSamusData.yPosition -= (QUARTER_BLOCK_SIZE - PIXEL_SIZE);

    return SPOSE_NONE;
}

/**
 * @brief 7c78 | 90 | Samus pulling up from hanging graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusPullingUpFromHangingGfx(void)
{
    s16 xOffset;

    if (gSamusData.animationDurationCounter >= sSamusAnim_PullingUpFromHanging_Right[gSamusData.currentAnimationFrame].timer)
    {
        gSamusData.animationDurationCounter = 0;
        gSamusData.currentAnimationFrame++;
        if (sSamusAnim_PullingUpFromHanging_Right[gSamusData.currentAnimationFrame].timer == 0)
        {
            if (gSamusData.direction & KEY_RIGHT)
            {
                gSamusData.xPosition += EIGHTH_BLOCK_SIZE;
                xOffset = SAMUS_LEDGE_GRAB_X_RANGE;
            }
            else
            {
                gSamusData.xPosition -= EIGHTH_BLOCK_SIZE;
                xOffset = -SAMUS_LEDGE_GRAB_X_RANGE;
            }

            if (ClipdataProcessForSamus(gSamusData.yPosition - BLOCK_SIZE * 2, gSamusData.xPosition + xOffset) & CLIPDATA_TYPE_SOLID_FLAG)
                return SPOSE_PULLING_INTO_MORPH_FROM_HANGING;

            return SPOSE_PULLING_FORWARD_FROM_HANGING;
        }
    }

    return SPOSE_NONE;
}

/**
 * @brief 7d08 | 30 | Samus pulling forward from hanging handler
 * 
 * @return u8 New pose
 */
u8 SamusPullingForwardFromHanging(void)
{
    u16 speed;

    if (gSamusData.slopeType != SLOPE_NONE)
        speed = PIXEL_SIZE / 2;
    else
        speed = PIXEL_SIZE;

    if (gSamusData.direction & KEY_RIGHT)
        gSamusData.xPosition += speed;
    else
        gSamusData.xPosition -= speed;

    return SPOSE_NONE;
}

/**
 * @brief 7d38 | 5c | Samus pulling forward from hanging graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusPullingForwardFromHangingGfx(void)
{
    if (gSamusData.animationDurationCounter >= sSamusAnim_PullingForwardFromHanging_Right[gSamusData.currentAnimationFrame].timer)
    {
        if (gSamusData.currentAnimationFrame == 0)
            gSamusData.yPosition = (gSamusData.yPosition & BLOCK_POSITION_FLAG) - ONE_SUB_PIXEL;

        gSamusData.animationDurationCounter = 0;
        gSamusData.currentAnimationFrame++;

        if (sSamusAnim_PullingForwardFromHanging_Right[gSamusData.currentAnimationFrame].timer == 0)
            return SPOSE_STANDING;
    }

    return SPOSE_NONE;
}

/**
 * @brief 7d94 | 24 | Samus pulling into morph from hanging handler
 * 
 * @return u8 New pose
 */
u8 SamusPullingIntoMorphFromHanging(void)
{
    if (gSamusData.direction & KEY_RIGHT)
        gSamusData.xPosition += EIGHTH_BLOCK_SIZE;
    else
        gSamusData.xPosition -= EIGHTH_BLOCK_SIZE;

    return SPOSE_NONE;
}

/**
 * @brief 7db8 | 44 | Samus pulling into morph from hanging graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusPullingIntoMorphFromHangingGfx(void)
{
    if (gSamusData.animationDurationCounter >= sSamusAnim_PullingIntoMorphFromHanging_Right[gSamusData.currentAnimationFrame].timer)
    {
        gSamusData.yPosition = (gSamusData.yPosition & BLOCK_POSITION_FLAG) - ONE_SUB_PIXEL;
        SoundPlay(SOUND_7F);
        return SPOSE_MORPH_BALL;
    }

    return SPOSE_NONE;
}

/**
 * @brief 7dfc | 30 | Samus lowering down to start hanging handler
 * 
 * @return u8 New pose
 */
u8 SamusLoweringDownToStartHanging_Unused(void)
{
    gDisableScrolling = TRUE;

    if (gSamusData.currentAnimationFrame == 0)
        gSamusData.yPosition -= (QUARTER_BLOCK_SIZE - PIXEL_SIZE);
    else
        gSamusData.yPosition += (QUARTER_BLOCK_SIZE - PIXEL_SIZE);

    return SPOSE_NONE;
}

/**
 * @brief 7e2c | 48 | Samus lowering down to start hanging graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusLoweringDownToStartHanging_UnusedGfx(void)
{
    if (gSamusData.animationDurationCounter >= sSamusAnim_LoweringDownToStartHanging_Right[gSamusData.currentAnimationFrame].timer)
    {
        gSamusData.animationDurationCounter = 0;
        gSamusData.currentAnimationFrame++;
        if (sSamusAnim_LoweringDownToStartHanging_Right[gSamusData.currentAnimationFrame].timer == 0)
            return SPOSE_HANGING_ON_LEDGE;
    }

    return SPOSE_NONE;
}

/**
 * @brief 7e74 | a4 | Samus space jumping graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusSpaceJumpingGfx(void)
{
    u8 timer;

    timer = sSamusAnim_SpaceJumping_Right[gSamusData.currentAnimationFrame].timer;

    if (gSamusPhysics.slowed)
        timer *= 2;

    if (gSamusData.currentAnimationFrame == 0 && gSamusData.animationDurationCounter == 1)
    {
        if (MOD_AND(gSamusAnimationInfo.spaceJumpSpinCounter, 2) == 0)
        {
            if (gSamusPhysics.slowed == TRUE)
                SoundPlay(SOUND_94);
            else
                SoundPlay(SOUND_6F);
        }

        gSamusAnimationInfo.spaceJumpSpinCounter++;
    }

    if (gSamusData.animationDurationCounter >= timer)
    {
        gSamusData.animationDurationCounter = 0;
        gSamusData.currentAnimationFrame++;

        if (sSamusAnim_SpaceJumping_Right[gSamusData.currentAnimationFrame].timer == 0)
            gSamusData.currentAnimationFrame = 0;
    }

    return SPOSE_NONE;
}

/**
 * @brief 7f18 | b4 | Samus screw attacking jumping graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusScrewAttackingGfx(void)
{
    u8 timer;

    timer = sSamusAnim_ScrewAttacking_Right[gSamusData.currentAnimationFrame].timer;

    if (gSamusPhysics.slowed)
        timer *= 2;

    if (gSamusData.currentAnimationFrame == 0 && gSamusData.animationDurationCounter == 1)
        SoundPlay(SOUND_70);

    if (gSamusData.animationDurationCounter >= timer)
    {
        gSamusData.animationDurationCounter = 0;
        gSamusData.currentAnimationFrame++;

        if (sSamusAnim_ScrewAttacking_Right[gSamusData.currentAnimationFrame].timer == 0)
            gSamusData.currentAnimationFrame = 0;
    }

    APPLY_DELTA_TIME_INC(gSamusAnimationInfo.paletteAnimationCounter);

    timer = sArmCannonOam_ScrewAttacking_Right[gSamusAnimationInfo.currentPaletteRow].timer;

    if (gSamusPhysics.slowed)
        timer *= 2;

    if (gSamusAnimationInfo.paletteAnimationCounter >= timer)
    {
        gSamusAnimationInfo.paletteAnimationCounter = 0;
        gSamusAnimationInfo.currentPaletteRow++;

        if (sArmCannonOam_ScrewAttacking_Right[gSamusAnimationInfo.currentPaletteRow].timer == 0)
            gSamusAnimationInfo.currentPaletteRow = 0;
    }

    return SPOSE_NONE;
}

/**
 * @brief 7fcc | 80 | Samus skidding handler
 * 
 * @return u8 New pose
 */
u8 SamusSkidding(void)
{
    // Check jump
    if (gChangedInput & KEY_A)
    {
        gSamusData.forcedMovement = FORCED_MOVEMENT_MID_AIR_JUMP;
        return SPOSE_MID_AIR_REQUEST;
    }

    // Check run
    if (gButtonInput & gSamusData.direction)
        return SPOSE_RUNNING;

    if ((gButtonInput & KEY_ALL_DIRECTIONS) == KEY_DOWN)
    {
        // Holding down, store speedbooster
        gSamusAnimationInfo.shinesparkTimer = 60 * 3;
        return SPOSE_CROUCHING;
    }

    // Slowly reduce velocity towards 0, set standing if reached 0
    if (gSamusData.direction & KEY_RIGHT)
    {
        gSamusData.xVelocity -= SKIDDING_VELOCITY_LOSS;

        if (gSamusData.xVelocity <= 0)
            return SPOSE_STANDING;
    }
    else
    {
        gSamusData.xVelocity += SKIDDING_VELOCITY_LOSS;

        if (gSamusData.xVelocity >= 0)
            return SPOSE_STANDING;
    }

    return SPOSE_NONE;
}

/**
 * @brief 804c | 48 | Samus on save pad graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusOnSavePadGfx(void)
{
    if (gSamusData.animationDurationCounter >= sSamusAnim_OnSavePad_Right[gSamusData.currentAnimationFrame].timer)
    {
        gSamusData.animationDurationCounter = 0;
        gSamusData.currentAnimationFrame++;

        if (sSamusAnim_OnSavePad_Right[gSamusData.currentAnimationFrame].timer == 0)
            gSamusData.currentAnimationFrame = 1;
    }

    return SPOSE_NONE;
}

/**
 * @brief 8094 | 48 | Samus turning around to recharge or unlock security graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusTurningAroundToRechargeOrUnlockSecurityGfx(void)
{
    if (gSamusData.animationDurationCounter >= sSamusAnim_Turning_Forward_Right[gSamusData.currentAnimationFrame].timer)
    {
        gSamusData.animationDurationCounter = 0;
        gSamusData.currentAnimationFrame++;

        if (sSamusAnim_Turning_Forward_Right[gSamusData.currentAnimationFrame].timer == 0)
            return SPOSE_ON_RECHARGE_OR_SECURITY_PAD;
    }

    return SPOSE_NONE;
}

/**
 * @brief 80dc | 6c | Samus delay before shinesparking graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusDelayBeforeShinesparkingGfx(void)
{
    gSamusAnimationInfo.shinesparkTimer = 2;

    if (gSamusData.animationDurationCounter >= sSamusAnim_DelayBeforeShinesparking_Right[gSamusData.currentAnimationFrame].timer)
    {
        gSamusData.animationDurationCounter = 0;
        gSamusData.currentAnimationFrame++;

        if (sSamusAnim_DelayBeforeShinesparking_Right[gSamusData.currentAnimationFrame].timer == 0)
        {
            if (gButtonInput & OPPOSITE_DIRECTION(gSamusData.direction))
                gSamusData.turning = TRUE;

            return SPOSE_SHINESPARKING;
        }
    }

    return SPOSE_NONE;
}

/**
 * @brief 8148 | 50 | Samus shinesparking handler
 * 
 * @return u8 New pose
 */
u8 SamusShinesparking(void)
{
    if (gSamusData.forcedMovement == FORCED_MOVEMENT_UPWARDS_SHINESPARK)
    {
        // Check still moving upwards
        if (gSamusData.yVelocity == 0)
        {
            ScreenShakeStartVertical(30, 1);
            return SPOSE_DELAY_AFTER_SHINESPARKING;
        }
    }
    else if (gSamusData.forcedMovement == FORCED_MOVEMENT_SIDEWARDS_SHINESPARK)
    {
        // Check still moving sideways
        if (gSamusData.xVelocity == 0)
        {
            ScreenShakeStartHorizontal(30, 1);
            return SPOSE_DELAY_AFTER_SHINESPARKING;
        }
    }
    else
    {
        // Check still moving diagonally
        if (gSamusData.xVelocity == 0 || gSamusData.yVelocity == 0)
        {
            ScreenShakeStartHorizontal(30, 1);
            return SPOSE_DELAY_AFTER_SHINESPARKING;
        }
    }

    return SPOSE_NONE;
}

/**
 * @brief 8198 | 48 | Samus shinesparking graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusShinesparkingGfx(void)
{
    if (gSamusData.animationDurationCounter >= sSamusAnim_Shinesparking_Upwards_Right[gSamusData.currentAnimationFrame].timer)
    {
        gSamusData.animationDurationCounter = 0;
        gSamusData.currentAnimationFrame++;

        if (sSamusAnim_Shinesparking_Upwards_Right[gSamusData.currentAnimationFrame].timer == 0)
            gSamusData.currentAnimationFrame--;
    }

    return SPOSE_NONE;
}

/**
 * @brief 81e0 | 48 | Samus delay after shinesparking graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusDelayAfterShinesparkingGfx(void)
{
    if (gSamusData.animationDurationCounter >= sSamusAnim_DelayAfterShinesparking_Upwards_Right[gSamusData.currentAnimationFrame].timer)
    {
        gSamusData.animationDurationCounter = 0;
        gSamusData.currentAnimationFrame++;

        if (sSamusAnim_DelayAfterShinesparking_Upwards_Right[gSamusData.currentAnimationFrame].timer == 0)
            return SPOSE_MID_AIR_REQUEST;
    }

    return SPOSE_NONE;
}

/**
 * @brief 8228 | 1d8 | Samus hanging on vertical ladder handler
 * 
 * @return u8 New pose
 */
u8 SamusHangingOnVerticalLadder(void)
{
    s16 xOffset;
    s32 movementBlock;

    if (gSamusData.counter < ONE_THIRD_SECOND)
        APPLY_DELTA_TIME_INC(gSamusData.counter);

    if (gChangedInput & KEY_A && gSamusData.counter >= ONE_THIRD_SECOND)
    {
        if (gButtonInput & OPPOSITE_DIRECTION(gSamusData.direction))
        {
            gSamusData.direction = OPPOSITE_DIRECTION(gSamusData.direction);
            return SPOSE_STARTING_WALL_JUMP;
        }

        if (!(gButtonInput & gSamusData.direction))
            return SPOSE_MID_AIR_REQUEST;
    }

    if (gChangedInput & OPPOSITE_DIRECTION(gSamusData.direction) || gButtonInput & gButtonAssignments.diagonalAim)
    {
        gSamusData.direction = OPPOSITE_DIRECTION(gSamusData.direction);
        return SPOSE_STARTING_TO_HOLD_ARM_OUT_ON_VERTICAL_LADDER;
    }

    if (gSamusData.shooting)
    {
        gSamusData.direction = OPPOSITE_DIRECTION(gSamusData.direction);
        if (gButtonInput & KEY_DOWN)
            gSamusData.armCannonDirection = ACD_DOWN;
        else
            gSamusData.armCannonDirection = ACD_UP;

        return SPOSE_SHOOTING_ON_VERTICAL_LADDER;
    }

    gSamusData.yVelocity = 0;

    if (gSamusData.direction & KEY_RIGHT)
        xOffset = HALF_BLOCK_SIZE;
    else
        xOffset = -HALF_BLOCK_SIZE;

    movementBlock = HIGH_SHORT(ClipdataCheckCurrentAffectingAtPosition(gSamusData.yPosition - (BLOCK_SIZE * 2 - PIXEL_SIZE + ONE_SUB_PIXEL),
        gSamusData.xPosition + xOffset));

    if (gButtonInput & KEY_UP)
    {
        if (movementBlock == CLIPDATA_MOVEMENT_WALL_LADDER)
        {
            if (gSamusData.currentAnimationFrame == 0)
            {
                gSamusData.currentAnimationFrame++;
                gSamusData.animationDurationCounter = 0;

                if (gSamusPhysics.slowed == TRUE)
                    SoundPlay(SOUND_95);
                else
                    SoundPlay(SOUND_86);
            }

            gSamusData.elevatorOrClimbingDirection = KEY_UP;
            gSamusData.yVelocity = SUB_PIXEL_TO_VELOCITY(ONE_SUB_PIXEL / 2.f);
        }
        else if (movementBlock != CLIPDATA_MOVEMENT_PREVENTS_CLIMBING_INTO_FROM_LADDER)
        {
            if (!(gEquipment.suitMiscStatus & SMF_MORPH_BALL) &&
                ClipdataProcessForSamus(gSamusData.yPosition - (BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE),
                gSamusData.xPosition + xOffset) & CLIPDATA_TYPE_SOLID_FLAG)
            {
                return SPOSE_LOWERING_DOWN_TO_START_HANGING;
            }

            return SPOSE_PULLING_UP_FROM_HANGING;
        }
    }
    else if (gButtonInput & KEY_DOWN)
    {
        if (gSamusData.currentAnimationFrame == 0)
        {
            gSamusData.currentAnimationFrame = 6;
            gSamusData.animationDurationCounter = 0;

            if (gSamusPhysics.slowed == TRUE)
                SoundPlay(SOUND_95);
            else
                SoundPlay(SOUND_86);
        }

        gSamusData.elevatorOrClimbingDirection = KEY_DOWN;
        gSamusData.yVelocity = -SUB_PIXEL_TO_VELOCITY(ONE_SUB_PIXEL / 2.f);
    }

    if (gSamusPhysics.slowed)
        gSamusData.yVelocity = DIV_SHIFT(gSamusData.yVelocity, 2);

    return SPOSE_NONE;
}

/**
 * @brief 8400 | 78 | Samus hanging on vertical ladder graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusHangingOnVerticalLadderGfx(void)
{
    u8 timer;

    if (gSamusData.currentAnimationFrame != 0)
    {
        timer = sSamusAnim_HangingOnVerticalLadder_Right[gSamusData.currentAnimationFrame].timer;

        if (gSamusPhysics.slowed)
            timer *= 2;

        if (gSamusData.animationDurationCounter >= timer)
        {
            gSamusData.animationDurationCounter = 0;

            if (gSamusData.elevatorOrClimbingDirection & KEY_UP)
            {
                gSamusData.currentAnimationFrame++;
        
                if (sSamusAnim_HangingOnVerticalLadder_Right[gSamusData.currentAnimationFrame].timer == 0)
                    gSamusData.currentAnimationFrame = 0;
            }
            else
            {
                gSamusData.currentAnimationFrame--;
            }
        }
    }

    if (gSamusData.currentAnimationFrame == 0)
        gSamusData.yVelocity = 0;

    return SPOSE_NONE;
}

/**
 * @brief 8478 | 38 | Samus starting to hold arm out on vertical ladder handler
 * 
 * @return u8 New pose
 */
u8 SamusStartingToHoldArmOutOnVerticalLadder(void)
{
    if (gChangedInput & KEY_A)
    {
        if (gButtonInput & gSamusData.direction)
        {
            // Jumping off of ladder
            return SPOSE_STARTING_WALL_JUMP;
        }

        // Set dropping ladder
        return SPOSE_MID_AIR_REQUEST;
    }

    return SPOSE_NONE;
}

/**
 * @brief 84b0 | 54 | Samus starting to hold arm out on vertical ladder graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusStartingToHoldArmOutOnVerticalLadderGfx(void)
{
    u8 timer;

    timer = sSamusAnim_StartingToHoldArmOutOnVerticalLadder_Right[gSamusData.currentAnimationFrame].timer;

    if (gSamusPhysics.slowed)
        timer *= 2;

    if (gSamusData.animationDurationCounter >= timer)
    {
        gSamusData.animationDurationCounter = 0;
        gSamusData.currentAnimationFrame++;

        if (sSamusAnim_StartingToHoldArmOutOnVerticalLadder_Right[gSamusData.currentAnimationFrame].timer == 0)
            return SPOSE_HOLDING_ARM_OUT_ON_VERTICAL_LADDER;
    }

    return SPOSE_NONE;
}

/**
 * @brief 8504 | 88 | Samus holding arm out on vertical ladder handler
 * 
 * @return u8 New pose
 */
u8 SamusHoldingArmOutOnVerticalLadder(void)
{
    // Aim cannon
    SamusAimCannonMidAir();

    // Check shooting
    if (gSamusData.shooting)
        return SPOSE_SHOOTING_ON_VERTICAL_LADDER;

    // Check release
    if (gChangedInput & KEY_A)
    {
        if (gButtonInput & gSamusData.direction)
        {
            // Jumping off of ladder
            return SPOSE_STARTING_WALL_JUMP;
        }

        // Set dropping ladder
        return SPOSE_MID_AIR_REQUEST;
    }

    if (!(gButtonInput & gButtonAssignments.diagonalAim))
    {
        // Check holding opposite direction
        if (OPPOSITE_DIRECTION(gSamusData.direction) & gButtonInput)
            return SPOSE_STARTING_TO_PUT_ARM_AWAY_ON_VERTICAL_LADDER;

        // Check start to move down/up
        if (gButtonInput & (KEY_UP | KEY_DOWN))
        {
            if (gSamusData.counter++ > 9)
                return SPOSE_STARTING_TO_PUT_ARM_AWAY_ON_VERTICAL_LADDER;
        }
    }

    return SPOSE_NONE;
}

/**
 * @brief 858c | 54 | Samus shooting on vertical ladder graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusShootingOnVerticalLadderGfx(void)
{
    u8 timer;

    timer = sSamusAnim_ShootingOnVerticalLadder_Forward_Right[gSamusData.currentAnimationFrame].timer;

    if (gSamusPhysics.slowed)
        timer *= 2;

    if (gSamusData.animationDurationCounter >= timer)
    {
        gSamusData.animationDurationCounter = 0;
        gSamusData.currentAnimationFrame++;

        if (sSamusAnim_ShootingOnVerticalLadder_Forward_Right[gSamusData.currentAnimationFrame].timer == 0)
            return SPOSE_HOLDING_ARM_OUT_ON_VERTICAL_LADDER;
    }

    return SPOSE_NONE;
}

/**
 * @brief 85e0 | 38 | Samus starting to put arm away on vertical ladder handler
 * 
 * @return u8 New pose
 */
u8 SamusStartingToPutArmAwayOnVerticalLadder(void)
{
    if (gChangedInput & KEY_A)
    {
        if (gButtonInput & gSamusData.direction)
        {
            // Jumping off of ladder
            return SPOSE_STARTING_WALL_JUMP;
        }

        // Set dropping ladder
        return SPOSE_MID_AIR_REQUEST;
    }

    return SPOSE_NONE;
}

/**
 * @brief 8618 | 64 | Samus starting to put arm away on vertical ladder graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusStartingToPutArmAwayOnVerticalLadderGfx(void)
{
    u8 timer;

    timer = sSamusAnim_StartingToPutArmAwayOnVerticalLadder_Right[gSamusData.currentAnimationFrame].timer;

    if (gSamusPhysics.slowed)
        timer *= 2;

    if (gSamusData.animationDurationCounter >= timer)
    {
        gSamusData.animationDurationCounter = 0;
        gSamusData.currentAnimationFrame++;

        if (sSamusAnim_StartingToPutArmAwayOnVerticalLadder_Right[gSamusData.currentAnimationFrame].timer == 0)
        {
            gSamusData.direction = OPPOSITE_DIRECTION(gSamusData.direction);
            return SPOSE_HANGING_FROM_VERTICAL_LADDER;
        }
    }

    return SPOSE_NONE;
}

/**
 * @brief 867c | 9c | Samus hanging on horizontal ladder handler
 * 
 * @return u8 New pose
 */
u8 SamusHangingOnHorizontalLadder(void)
{
    s32 xOffset;
    s32 affecting;

    if (gChangedInput & KEY_A)
    {
        // Drop down from ladder
        return SPOSE_MID_AIR_REQUEST;
    }

    SamusAimCannonHorizontalLadder();

    if (gSamusData.shooting)
        return SPOSE_SHOOTING_ON_HORIZONTAL_LADDER;

    if (gSamusData.diagonalAim != DIAG_AIM_NONE || gSamusData.armCannonDirection == ACD_DOWN)
        return SPOSE_DELAY_AFTER_SHOOTING_ON_HORIZONTAL_LADDER;

    if (gButtonInput & gSamusData.direction)
    {
        gSamusData.armCannonDirection = ACD_FORWARD;

        if (gSamusData.direction & KEY_RIGHT)
            xOffset = ONE_SUB_PIXEL;
        else
            xOffset = -ONE_SUB_PIXEL;

        // Check for an horizontal ladder right in front of Samus
        affecting = HIGH_SHORT(ClipdataCheckCurrentAffectingAtPosition(gSamusData.yPosition - (BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE), gSamusData.xPosition + xOffset));
        if (affecting == CLIPDATA_MOVEMENT_CEILING_LADDER)
            return SPOSE_MOVING_ON_HORIZONTAL_LADDER;
    }
    else if (gButtonInput & OPPOSITE_DIRECTION(gSamusData.direction))
    {
        return SPOSE_TURNING_AROUND_ON_HORIZONTAL_LADDER;
    }

    return SPOSE_NONE;
}

/**
 * @brief 8718 | 9c | Samus moving on horizontal ladder handler
 * 
 * @return u8 New pose
 */
u8 SamusMovingOnHorizontalLadder(void)
{
    s16 velocity;

    // Check release
    if (gChangedInput & KEY_A)
        return SPOSE_MID_AIR_REQUEST;

    // Check turning
    if (gButtonInput & OPPOSITE_DIRECTION(gSamusData.direction))
        return SPOSE_TURNING_AROUND_ON_HORIZONTAL_LADDER;

    if (gSamusData.shooting)
    {
        // Aim cannon only if shooting
        SamusAimCannonHorizontalLadder();
        return SPOSE_SHOOTING_ON_HORIZONTAL_LADDER;
    }

    // Compute velocity
    velocity = SUB_PIXEL_TO_VELOCITY(0);
    if (gButtonInput & gSamusData.direction)
    {
        if (gSamusData.direction & KEY_RIGHT)
            velocity = HORIZONTAL_LADDER_X_VELOCITY;
        else if (gSamusData.direction & KEY_LEFT)
            velocity = -HORIZONTAL_LADDER_X_VELOCITY;
    }
    else
    {
        gSamusData.animationDurationCounter *= 2;
    }

    // Half velocity if slowed
    if (gSamusPhysics.slowed)
        velocity = DIV_SHIFT(velocity, 2);

    gSamusData.xVelocity = velocity;

    return SPOSE_NONE;
}

/**
 * @brief 87b4 | 7c | Samus moving on horizontal ladder graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusMovingOnHorizontalLadderGfx(void)
{
    u8 timer;

    timer = sSamusAnim_MovingOnHorizontalLadder_Right[gSamusData.currentAnimationFrame].timer;

    if (gSamusPhysics.slowed)
        timer *= 2;

    if (gSamusData.animationDurationCounter >= timer)
    {
        gSamusData.animationDurationCounter = 0;
        gSamusData.currentAnimationFrame++;

        if (sSamusAnim_MovingOnHorizontalLadder_Right[gSamusData.currentAnimationFrame].timer == 0)
            return SPOSE_HANGING_ON_HORIZONTAL_LADDER;

        if (gSamusData.currentAnimationFrame == 1)
        {
            if (gSamusPhysics.slowed)
                SoundPlay(SOUND_95);
            else
                SoundPlay(SOUND_87);
        }
        else if (gSamusData.currentAnimationFrame == 6)
        {
            if (gSamusPhysics.slowed == TRUE)
                SoundPlay(SOUND_95);
            else
                SoundPlay(SOUND_87);
        }
    }

    return SPOSE_NONE;
}

/**
 * @brief 8830 | 34 | Samus turning around on horizontal ladder handler
 * 
 * @return u8 New pose
 */
u8 SamusTurningAroundOnHorizontalLadder(void)
{
    if (gSamusData.shooting)
    {
        // Aim cannon only if shooting
        SamusAimCannonHorizontalLadder();
        return SPOSE_SHOOTING_ON_HORIZONTAL_LADDER;
    }

    // Check release
    if (gChangedInput & KEY_A)
        return SPOSE_MID_AIR_REQUEST;

    return SPOSE_NONE;
}

/**
 * @brief 8864 | 70 | Samus turning around on horizontal ladder graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusTurningAroundOnHorizontalLadderGfx(void)
{
    u8 timer;

    timer = sSamusAnim_TurningOnHorizontalLadder_Right[gSamusData.currentAnimationFrame].timer;

    if (gSamusPhysics.slowed)
        timer *= 2;

    if (gSamusData.animationDurationCounter >= timer)
    {
        gSamusData.animationDurationCounter = 0;
        gSamusData.currentAnimationFrame++;

        if (sSamusAnim_TurningOnHorizontalLadder_Right[gSamusData.currentAnimationFrame].timer == 0)
        {
            if (gButtonInput & gButtonAssignments.diagonalAim)
                return SPOSE_DELAY_AFTER_SHOOTING_ON_HORIZONTAL_LADDER;

            return SPOSE_HANGING_ON_HORIZONTAL_LADDER;
        }
    }

    return SPOSE_NONE;
}

/**
 * @brief 88d4 | 78 | Samus delay after shooting on horizontal ladder handler
 * 
 * @return u8 New pose
 */
u8 SamusDelayAfterShootingOnHorizontalLadder(void)
{
    // Aim cannon
    SamusAimCannonHorizontalLadder();

    // Check shooting
    if (gSamusData.shooting)
        return SPOSE_SHOOTING_ON_HORIZONTAL_LADDER;

    // Check release
    if (gChangedInput & KEY_A)
        return SPOSE_MID_AIR_REQUEST;

    // Check turning
    if (gButtonInput & OPPOSITE_DIRECTION(gSamusData.direction))
        return SPOSE_TURNING_AROUND_ON_HORIZONTAL_LADDER;

    // Check go back to idle
    if (!(gButtonInput & gButtonAssignments.diagonalAim) && gButtonInput & (KEY_RIGHT | KEY_LEFT))
    {
        if (APPLY_DELTA_TIME_INC_POST(gSamusData.counter) > CONVERT_SECONDS(.15f))
            return SPOSE_HANGING_ON_HORIZONTAL_LADDER;
    }

    return SPOSE_NONE;
}

/**
 * @brief 894c | 54 | Samus delay after shooting on horizontal ladder graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusShootingOnHorizontalLadderGfx(void)
{
    u8 timer;

    timer = sSamusAnim_ShootingOnHorizontalLadder_Default_Right[gSamusData.currentAnimationFrame].timer;

    if (gSamusPhysics.slowed)
        timer *= 2;

    if (gSamusData.animationDurationCounter >= timer)
    {
        gSamusData.animationDurationCounter = 0;
        gSamusData.currentAnimationFrame++;

        if (sSamusAnim_ShootingOnHorizontalLadder_Default_Right[gSamusData.currentAnimationFrame].timer == 0)
            return SPOSE_DELAY_AFTER_SHOOTING_ON_HORIZONTAL_LADDER;
    }

    return SPOSE_NONE;
}

/**
 * @brief 89a0 | 20 | Samus frozen graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusFrozenGfx(void)
{
    if (gSamusData.counter >= SAMUS_FROZEN_DURATION)
    {
        // Unfreeze
        return SPOSE_STANDING;
    }

    APPLY_DELTA_TIME_INC(gSamusData.counter);
    return SPOSE_NONE;
}

/**
 * @brief 89c0 | 20 | Samus frozen in morph ball graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusFrozenInMorphBallGfx(void)
{
    if (gSamusData.counter >= SAMUS_FROZEN_DURATION)
    {
        // Unfreeze
        return SPOSE_MORPH_BALL;
    }

    APPLY_DELTA_TIME_INC(gSamusData.counter);
    return SPOSE_NONE;
}

/**
 * @brief 89e0 | 80 | Samus unlocking security graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusUnlockingSecurityGfx(void)
{
    if (gSamusData.animationDurationCounter >= sSamusAnim_UnlockingSecurity_Right[gSamusData.currentAnimationFrame].timer)
    {
        gSamusData.animationDurationCounter = 0;
        gSamusData.currentAnimationFrame++;

        if (sSamusAnim_UnlockingSecurity_Right[gSamusData.currentAnimationFrame].timer == 0)
            gSamusData.currentAnimationFrame = 0;
    }

    APPLY_DELTA_TIME_INC(gSamusAnimationInfo.paletteAnimationCounter);
    if (gSamusAnimationInfo.paletteAnimationCounter >= sArmCannonOam_UnlockingSecurity_Right[gSamusAnimationInfo.currentPaletteRow].timer)
    {
        gSamusAnimationInfo.paletteAnimationCounter = 0;
        gSamusAnimationInfo.currentPaletteRow++;

        if (sArmCannonOam_UnlockingSecurity_Right[gSamusAnimationInfo.currentPaletteRow].timer == 0)
            gSamusAnimationInfo.currentPaletteRow = 0;
    }

    return SPOSE_NONE;
}

/**
 * @brief 8a60 | 48 | Samus saving graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusSavingGfx(void)
{
    if (gSamusData.animationDurationCounter >= sSamusAnim_Saving[gSamusData.currentAnimationFrame].timer)
    {
        gSamusData.animationDurationCounter = 0;
        gSamusData.currentAnimationFrame++;

        if (sSamusAnim_Saving[gSamusData.currentAnimationFrame].timer == 0)
            return SPOSE_FACING_FOREGROUND;
    }

    return SPOSE_NONE;
}

/**
 * @brief 8aa8 | 48 | Samus on navigation pad graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusOnNavigationPadGfx(void)
{
    if (gSamusData.animationDurationCounter >= sSamusAnim_OnNavigationPad_Right[gSamusData.currentAnimationFrame].timer)
    {
        gSamusData.animationDurationCounter = 0;
        gSamusData.currentAnimationFrame++;

        if (sSamusAnim_OnNavigationPad_Right[gSamusData.currentAnimationFrame].timer == 0)
            return SPOSE_FACING_BACKGROUND;
    }

    return SPOSE_NONE;
}

/**
 * @brief 8af0 | 44 | Samus downloading ability graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusDownloadingAbilityGfx(void)
{
    if (gSamusData.animationDurationCounter >= sSamusAnim_DownloadingAbility_Right[gSamusData.currentAnimationFrame].timer)
    {
        gSamusData.animationDurationCounter = 0;
        gSamusData.currentAnimationFrame++;

        if (sSamusAnim_DownloadingAbility_Right[gSamusData.currentAnimationFrame].timer == 0)
            gSamusData.currentAnimationFrame = 0;
    }

    return SPOSE_NONE;
}

/**
 * @brief 8b34 | 44 | Samus being recharged graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusBeingRechargedGfx(void)
{
    if (gSamusData.animationDurationCounter >= sSamusAnim_BeingRecharged_Right[gSamusData.currentAnimationFrame].timer)
    {
        gSamusData.animationDurationCounter = 0;
        gSamusData.currentAnimationFrame++;

        if (sSamusAnim_BeingRecharged_Right[gSamusData.currentAnimationFrame].timer == 0)
            gSamusData.currentAnimationFrame = 0;
    }

    return SPOSE_NONE;
}

/**
 * @brief 8b78 | 50 | Samus facing foreground handler
 * 
 * @return u8 New pose
 */
u8 SamusFacingForeground(void)
{
    // Last wall touched mid-air is used as a timer to temporarily prevent turning around
    if (gSamusData.lastWallTouchedMidAir != 0)
    {
        // Lock animation on first frame
        gSamusData.currentAnimationFrame = 0;
        gSamusData.animationDurationCounter = 0;

        // Decrement timer
        APPLY_DELTA_TIME_DEC(gSamusData.lastWallTouchedMidAir);
    }
    else
    {
        if (gSamusData.currentAnimationFrame < 3 && gButtonInput & (KEY_RIGHT | KEY_LEFT))
        {
            // Set direction
            gSamusData.direction = gButtonInput & (KEY_RIGHT | KEY_LEFT);

            // Set end of facing foreground animation
            gSamusData.currentAnimationFrame = 3;
            gSamusData.animationDurationCounter = 0;
        }
    }

    return SPOSE_NONE;
}

/**
 * @brief 8bc8 | 54 | Samus facing foreground graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusFacingForegroundGfx(void)
{
    if (gSamusData.animationDurationCounter >= sSamusAnim_FacingForeground_Right[gSamusData.currentAnimationFrame].timer)
    {
        gSamusData.animationDurationCounter = 0;
        gSamusData.currentAnimationFrame++;

        if (gSamusData.currentAnimationFrame == FRAME_DATA_FRAME_COUNT(sSamusAnim_FacingForeground_Right) - 1)
            gSamusData.currentAnimationFrame = 0;
        else if (sSamusAnim_FacingForeground_Right[gSamusData.currentAnimationFrame].timer == 0)
            return SPOSE_STANDING;
    }

    return SPOSE_NONE;
}

/**
 * @brief 8c1c | 5c | Samus unlocking habitations deck graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusUnlockingHabitationsDeckGfx(void)
{
    if (gSamusData.animationDurationCounter >= sSamusAnim_UnlockingHabitationsDeck[gSamusData.currentAnimationFrame].timer)
    {
        gSamusData.animationDurationCounter = 0;
        gSamusData.currentAnimationFrame++;

        if (gSamusData.currentAnimationFrame != 2)
        {
            if (sSamusAnim_UnlockingHabitationsDeck[gSamusData.currentAnimationFrame].timer == 0)
            {
                gSamusData.direction = KEY_RIGHT;
                return SPOSE_STANDING;
            }
        }
        else
        {
            gSamusData.currentAnimationFrame--;
        }
    }

    return SPOSE_NONE;
}

/**
 * @brief 8c78 | 18 | Samus loading save handler
 * 
 * @return u8 New pose
 */
u8 SamusLoadingSave(void)
{
    if (!gSamusAnimationInfo.loadingSave)
        gSamusAnimationInfo.loadingSave++;

    return SPOSE_NONE;
}

/**
 * @brief 8c90 | b0 | Samus loading save graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusLoadingSaveGfx(void)
{
    if (gSamusData.animationDurationCounter >= sSamusAnim_LoadingSave[gSamusData.currentAnimationFrame].timer)
    {
        gSamusData.animationDurationCounter = 0;
        gSamusData.currentAnimationFrame++;

        if (sSamusAnim_LoadingSave[gSamusData.currentAnimationFrame].timer == 0)
            return SPOSE_FACING_FOREGROUND;
    }

    if (gSamusAnimationInfo.loadingSave == TRUE)
    {
        APPLY_DELTA_TIME_INC(gSamusAnimationInfo.paletteAnimationCounter);

        if (gSamusAnimationInfo.paletteAnimationCounter >= sArmCannonOam_LoadingSave[gSamusAnimationInfo.currentPaletteRow].timer)
        {
            gSamusAnimationInfo.paletteAnimationCounter = 0;
            gSamusAnimationInfo.currentPaletteRow++;

            if (gSamusAnimationInfo.currentPaletteRow == FRAME_DATA_FRAME_COUNT(sArmCannonOam_LoadingSave) / 2)
            {
                if (gSamusData.currentAnimationFrame < 20)
                    gSamusAnimationInfo.currentPaletteRow = 16;
            }
            else if (sArmCannonOam_LoadingSave[gSamusAnimationInfo.currentPaletteRow].timer == 0)
            {
                gSamusAnimationInfo.loadingSave++;
                gSamusAnimationInfo.currentPaletteRow = 0;
            }
        }
    }

    return SPOSE_NONE;
}

/**
 * @brief 8d40 | ac | Samus dying handler
 * 
 * @return u8 New pose
 */
u8 SamusDying(void)
{
    u32 targetX;
    u32 targetY;

    if (gSamusData.lastWallTouchedMidAir == 0)
    {
        gSamusData.lastWallTouchedMidAir++;
        StopAllMusicAndSounds();
    }
    else if (gSamusData.lastWallTouchedMidAir == 1)
    {
        gSamusData.lastWallTouchedMidAir++;
        SoundPlay(SOUND_8E);
    }

    gSamusData.invincibilityTimer = CONVERT_SECONDS(1.f + 1.f / 15);

    if (gSamusAnimationInfo.loadingSave)
        return SPOSE_NONE;

    targetX = gBg1XPosition + PIXEL_TO_SUB_PIXEL(SCREEN_X_MIDDLE);
    targetY = gBg1YPosition + PIXEL_TO_SUB_PIXEL(SCREEN_Y_MIDDLE) + BLOCK_SIZE + QUARTER_BLOCK_SIZE;

    if (gSamusData.xVelocity > 0)
    {
        if (gSamusData.xPosition >= targetX)
            gSamusData.xVelocity = 0;
    }
    else if (gSamusData.xVelocity < 0)
    {
        if (gSamusData.xPosition <= targetX)
            gSamusData.xVelocity = 0;
    }

    if (gSamusData.yVelocity > 0)
    {
        if (gSamusData.yPosition >= targetY)
            gSamusData.yVelocity = 0;
    }
    else if (gSamusData.yVelocity < 0)
    {
        if (gSamusData.yPosition <= targetY)
            gSamusData.yVelocity = 0;
    }

    gSamusData.yPosition += gSamusData.yVelocity;

    return SPOSE_NONE;
}

/**
 * @brief 8dec | c4 | Samus dying graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusDyingGfx(void)
{
    if (gSamusAnimationInfo.loadingSave > 1)
    {
        APPLY_DELTA_TIME_INC(gSamusAnimationInfo.paletteAnimationCounter);
        if (gSamusAnimationInfo.paletteAnimationCounter >= sArmCannonOam_Dying_Right[gSamusAnimationInfo.currentPaletteRow].timer)
        {
            gSamusAnimationInfo.paletteAnimationCounter = 0;
            gSamusAnimationInfo.currentPaletteRow++;
    
            if (sArmCannonOam_Dying_Right[gSamusAnimationInfo.currentPaletteRow].timer == 0)
                gSamusAnimationInfo.currentPaletteRow--;
        }
    }

    if (gSamusData.animationDurationCounter >= sSamusAnim_Dying_Right[gSamusData.currentAnimationFrame].timer)
    {
        gSamusData.animationDurationCounter = 0;
        gSamusData.currentAnimationFrame++;

        if (gSamusData.currentAnimationFrame == 3)
        {
            if (gSamusData.counter < CONVERT_SECONDS(.5f))
            {
                gSamusData.currentAnimationFrame = 0;
                APPLY_DELTA_TIME_INC(gSamusData.counter);
            }
            else
            {
                gSamusAnimationInfo.loadingSave = 1;
                gMonochromeFading = 0x2;
            }
        }
        else if (gSamusData.currentAnimationFrame == 4)
        {
            gSamusData.counter = 0;
            gSamusAnimationInfo.loadingSave = 2;
        }
        else if (sSamusAnim_Dying_Right[gSamusData.currentAnimationFrame].timer == 0)
        {
            gSamusData.currentAnimationFrame--;
        }
    }

    return SPOSE_NONE;
}

/**
 * @brief 8eb0 | 68 | Samus hit by Omega Metroid handler
 * 
 * @return u8 New pose
 */
u8 SamusHitByOmegaMetroid(void)
{
    if (gEquipment.suitMiscStatus & SMF_SA_X_SUIT || gEquipment.currentEnergy >= 99)
    {
        // Second counter, doesn't decrement
        gSamusData.lastWallTouchedMidAir += gSamusData.counter;

        // Increment second counter
        if (APPLY_DELTA_TIME_INC_POST(gSamusData.lastWallTouchedMidAir) >= CONVERT_SECONDS(3.f))
        {
            // Release Samus
            gPoseLock = FALSE;
            return SPOSE_STANDING;
        }

        // Check wiggling
        if (gChangedInput & KEY_UP)
        {
            gSamusData.counter += CONVERT_SECONDS(1.f / 6);
        }
        else
        {
            // Not doing anything, decrement counter
            if (gSamusData.counter != 0)
                APPLY_DELTA_TIME_DEC(gSamusData.counter);
        }
    }

    return SPOSE_NONE;
}

/**
 * @brief 8f18 | 44 | Samus hit by Omega Metroid graphics handler
 * 
 * @return u8 New pose
 */
u8 SamusHitByOmegaMetroidGfx(void)
{
    if (gSamusData.animationDurationCounter >= sSamusAnim_HitByOmegaMetroid_Default_Right[gSamusData.currentAnimationFrame].timer)
    {
        gSamusData.animationDurationCounter = 0;
        gSamusData.currentAnimationFrame++;

        if (sSamusAnim_HitByOmegaMetroid_Default_Right[gSamusData.currentAnimationFrame].timer == 0)
            gSamusData.currentAnimationFrame = 0;
    }

    return SPOSE_NONE;
}

/**
 * @brief 8f5c | 44 | Samus grabbed by Yakuza handler
 * 
 * @return u8 New pose
 */
u8 SamusGrabbedByYakuza(void)
{
    if (gSamusData.counter > CONVERT_SECONDS(2.f + 2.f / 15))
    {
        // Release Samus
        gSamusData.invincibilityTimer = TWO_THIRD_SECOND + CONVERT_SECONDS(2.f / 15);
        return SPOSE_MID_AIR;
    }

    // Check wiggling
    if (gChangedInput & (KEY_RIGHT | KEY_LEFT))
    {
        // Increment counter
        gSamusData.counter += CONVERT_SECONDS(1.f / 6 + 1.f / 60);

        // Set direction
        gSamusData.direction = gChangedInput & (KEY_RIGHT | KEY_LEFT);
    }
    else
    {
        // Not doing anything, decrement counter
        if (gSamusData.counter != 0)
            APPLY_DELTA_TIME_DEC(gSamusData.counter);
    }

    return SPOSE_NONE;
}

/**
 * @brief 8fa0 | e0 | Sets the current Samus pose
 * 
 * @param pose Pose
 */
void SamusSetPose(u8 pose)
{
    // Check cancel turn around
    if (pose == SPOSE_KNOCKBACK_REQUEST || pose == SPOSE_HURT_REQUEST)
        gSamusData.turning = FALSE;

    // Copy current Samus data
    SamusCopyData();

    // Check stop speedbooster/shinespark sounds
    switch (gSamusDataCopy.pose)
    {
        case SPOSE_RUNNING:
            if (gSamusDataCopy.speedboostingCounter == 0 && gSamusDataCopy.counter > 80)
                SoundStop(0x6A);
            break;

        case SPOSE_DELAY_BEFORE_SHINESPARKING:
            if (pose != SPOSE_SHINESPARKING)
                SoundStop(0x99);
            break;

        case SPOSE_SHINESPARKING:
            SoundStop(0x99);
            break;

        case SPOSE_LOWERING_DOWN_TO_START_HANGING:
            gDisableScrolling = FALSE;
            break;
    }

    // Apply new pose, either a sub frame pose (request) or any other pose
    switch (pose)
    {
        case SPOSE_MID_AIR_REQUEST:
            SamusSetMidAirPose();
            break;

        case SPOSE_LANDING_REQUEST:
            SamusSetLandingPose();
            break;

        case SPOSE_FROZEN_REQUEST:
            SamusSetFrozenPose();
            break;

        case SPOSE_HURT_REQUEST:
            SamusSetHurtPose();
            break;

        case SPOSE_KNOCKBACK_REQUEST:
            SamusSetKnockbackPose();
            break;

        case SPOSE_F8:
            unk_99a0();
            break;

        case SPOSE_F7:
            unk_99d8();
            break;

        case SPOSE_FC:
        default:
            // Set pose and check carry
            gSamusData.pose = pose;
            SamusCheckCarryFromCopy();
    }
}

/**
 * @brief 9080 | 3a0 | Sets a mid-air pose for Samus based on the previous pose
 * 
 */
void SamusSetMidAirPose(void)
{
    gSamusData.xVelocity = gSamusDataCopy.xVelocity;
    gSamusData.speedboostingCounter = gSamusDataCopy.speedboostingCounter;
    
    if (gSamusDataCopy.armCannonDirection == ACD_NONE)
        gSamusData.armCannonDirection = ACD_FORWARD;
    else
        gSamusData.armCannonDirection = gSamusDataCopy.armCannonDirection;

    switch (gSamusDataCopy.pose)
    {
        case SPOSE_RUNNING:
            if (gSamusDataCopy.forcedMovement == FORCED_MOVEMENT_MID_AIR_JUMP)
            {
                gSamusData.pose = SPOSE_STARTING_SPIN_JUMP;

                if (gEquipment.suitMiscStatus & SMF_HIGH_JUMP)
                    gSamusData.yVelocity = SAMUS_HIGH_JUMP_VELOCITY;
                else
                    gSamusData.yVelocity = SAMUS_LOW_JUMP_VELOCITY;

                if (gSamusData.speedboostingCounter != 0 && gSamusDataCopy.slopeType & gSamusDataCopy.direction && gSamusDataCopy.slopeType & SLOPE_STEEP)
                {
                    gSamusData.yPosition -= QUARTER_BLOCK_SIZE;
                    gSamusUseYVelocityForX++;
                }
            }
            else
            {
                gSamusData.pose = SPOSE_MID_AIR;
            }
            break;

        case SPOSE_STARTING_SPIN_JUMP:
        case SPOSE_SPINNING:
        case SPOSE_WALL_JUMPING:
        case SPOSE_SPACE_JUMPING:
        case SPOSE_SCREW_ATTACKING:
            gSamusData.pose = SPOSE_MID_AIR;
            gSamusData.xVelocity = 0;
            gSamusData.yPosition += QUARTER_BLOCK_SIZE + PIXEL_SIZE;
            break;

        case SPOSE_MORPH_BALL_MID_AIR:
            // Check perform bomb jump
            if (gSamusDataCopy.forcedMovement == FORCED_MOVEMENT_BOMB_JUMP_RIGHT)
            {
                // Set direction and velocity
                gSamusData.direction = KEY_RIGHT;

                gSamusData.xVelocity = SAMUS_BOMB_BOUNCE_X_VELOCITY;
                gSamusData.yVelocity = SAMUS_BOMB_BOUNCE_Y_VELOCITY;
            }
            else if (gSamusDataCopy.forcedMovement == FORCED_MOVEMENT_BOMB_JUMP_UP)
            {
                // Set velocity
                gSamusData.xVelocity = 0;
                gSamusData.yVelocity = SAMUS_BOMB_BOUNCE_Y_VELOCITY;
            }
            else if (gSamusDataCopy.forcedMovement == FORCED_MOVEMENT_BOMB_JUMP_LEFT)
            {
                // Set direction and velocity
                gSamusData.direction = KEY_LEFT;

                gSamusData.xVelocity = -SAMUS_BOMB_BOUNCE_X_VELOCITY;
                gSamusData.yVelocity = SAMUS_BOMB_BOUNCE_Y_VELOCITY;
            }
            break;

        case SPOSE_MORPHING:
        case SPOSE_MORPH_BALL:
        case SPOSE_ROLLING:
        case SPOSE_GRABBED_BY_ZAZABI:
            gSamusData.pose = SPOSE_MORPH_BALL_MID_AIR;

            // Check perform bomb jump
            if (gSamusDataCopy.forcedMovement == FORCED_MOVEMENT_BOMB_JUMP_RIGHT)
            {
                // Set direction and velocity
                gSamusData.direction = KEY_RIGHT;

                gSamusData.xVelocity = SAMUS_BOMB_BOUNCE_X_VELOCITY;
                gSamusData.yVelocity = SAMUS_BOMB_BOUNCE_Y_VELOCITY * 2;

                gSamusData.forcedMovement = FORCED_MOVEMENT_MID_AIR_JUMP;
            }
            else if (gSamusDataCopy.forcedMovement == FORCED_MOVEMENT_BOMB_JUMP_UP)
            {
                // Set velocity
                gSamusData.xVelocity = 0;
                gSamusData.yVelocity = SAMUS_BOMB_BOUNCE_Y_VELOCITY * 2;

                gSamusData.forcedMovement = FORCED_MOVEMENT_MID_AIR_JUMP;
            }
            else if (gSamusDataCopy.forcedMovement == FORCED_MOVEMENT_BOMB_JUMP_LEFT)
            {
                // Set direction and velocity
                gSamusData.direction = KEY_LEFT;

                gSamusData.xVelocity = -SAMUS_BOMB_BOUNCE_X_VELOCITY;
                gSamusData.yVelocity = SAMUS_BOMB_BOUNCE_Y_VELOCITY * 2;

                gSamusData.forcedMovement = FORCED_MOVEMENT_MID_AIR_JUMP;
            }
            else
            {
                gSamusData.xVelocity = DIV_SHIFT(gSamusData.xVelocity, 2);

                if (gSamusDataCopy.forcedMovement == FORCED_MOVEMENT_MID_AIR_JUMP)
                {
                    gSamusData.yVelocity = SAMUS_LOW_JUMP_VELOCITY;
                }
                else if (gSamusDataCopy.forcedMovement == FORCED_MOVEMENT_MID_AIR_DROP)
                {
                    gPreviousYPosition += ONE_SUB_PIXEL;
                    gSamusData.yPosition += ONE_SUB_PIXEL;
                    gSamusData.yVelocity = -SUB_PIXEL_TO_VELOCITY(ONE_SUB_PIXEL / 2.f);
                }
            }
            break;

        case SPOSE_STARTING_WALL_JUMP:
            gSamusData.pose = SPOSE_WALL_JUMPING;

            if (!gSamusPhysics.slowed || gSamusDataCopy.forcedMovement == 0x0)
                gSamusData.yVelocity = SAMUS_LOW_JUMP_VELOCITY;
            else
                gSamusData.yVelocity = 0x30;

            if (gSamusData.direction & KEY_RIGHT)
            {
                gSamusData.xVelocity = SAMUS_WALL_JUMP_X_VELOCITY;
                gSamusData.xPosition += VELOCITY_TO_SUB_PIXEL(SAMUS_WALL_JUMP_X_VELOCITY);
            }
            else
            {
                gSamusData.xVelocity = -SAMUS_WALL_JUMP_X_VELOCITY;
                gSamusData.xPosition -= VELOCITY_TO_SUB_PIXEL(SAMUS_WALL_JUMP_X_VELOCITY);
            }

            if (gSamusPhysics.slowed == TRUE)
                SoundPlay(SOUND_96);
            else
                SoundPlay(SOUND_7E);
            break;

        case SPOSE_FROZEN:
            gSamusData.pose = SPOSE_FROZEN_AND_FALLING;
            gSamusData.counter = gSamusDataCopy.counter;
            break;

        case SPOSE_FROZEN_IN_MORPH_BALL:
            gSamusData.pose = SPOSE_FROZEN_IN_MORPH_BALL_AND_FALLING;
            gSamusData.counter = gSamusDataCopy.counter;
            break;

        default:
            gSamusData.pose = SPOSE_MID_AIR;

            if (gSamusDataCopy.forcedMovement == FORCED_MOVEMENT_MID_AIR_JUMP)
            {
                if (gButtonInput & (KEY_RIGHT | KEY_LEFT))
                    gSamusData.pose = SPOSE_STARTING_SPIN_JUMP;
                else
                    gSamusData.pose = SPOSE_MID_AIR;

                if (gEquipment.suitMiscStatus & SMF_HIGH_JUMP)
                    gSamusData.yVelocity = SAMUS_HIGH_JUMP_VELOCITY;
                else
                    gSamusData.yVelocity = SAMUS_LOW_JUMP_VELOCITY;
            }
            else if (gSamusDataCopy.forcedMovement == FORCED_MOVEMENT_MID_AIR_CARRY)
            {
                gSamusData.yVelocity = gSamusDataCopy.yVelocity;
            }
            else if (gSamusDataCopy.forcedMovement == FORCED_MOVEMENT_MID_AIR_DROP)
            {
                gPreviousYPosition += ONE_SUB_PIXEL;
                gSamusData.yPosition += ONE_SUB_PIXEL;
                gSamusData.yVelocity = -SUB_PIXEL_TO_VELOCITY(ONE_SUB_PIXEL / 2.f);
            }
    }

    if (gSamusData.pose == SPOSE_MID_AIR)
    {
        if (gSamusData.yVelocity == SAMUS_LOW_JUMP_VELOCITY)
        {
            if (gSamusPhysics.slowed != TRUE)
                SoundPlay(SOUND_71);
            else
                SoundPlay(SOUND_96);
        }
        else if (gSamusData.yVelocity == SAMUS_HIGH_JUMP_VELOCITY)
        {
            if (gSamusPhysics.slowed != TRUE)
                SoundPlay(SOUND_72);
            else
                SoundPlay(SOUND_96);
        }
    }
    else if (gSamusData.pose == SPOSE_MORPH_BALL_MID_AIR)
    {
        if (gSamusDataCopy.forcedMovement == FORCED_MOVEMENT_MID_AIR_JUMP)
        {
            if (gSamusPhysics.slowed == TRUE)
                SoundPlay(SOUND_96);
            else
                SoundPlay(SOUND_73);
        }
    }
}

/**
 * @brief 9420 | 2f4 | Sets a landing pose for Samus based on the previous pose
 * 
 */
void SamusSetLandingPose(void)
{
    u32 collision;
    
    gSamusDataCopy.lastWallTouchedMidAir = 0;

    if (gPoseLock & 0x80)
    {
        gSamusData.pose = SPOSE_HIT_BY_OMEGA_METROID;
        gSamusData.armCannonDirection = ACD_FORWARD;
        gSamusData.diagonalAim = DIAG_AIM_NONE;
        return;
    }

    switch (gSamusDataCopy.pose)
    {
        case SPOSE_MID_AIR:
            collision = SamusCheckCollisionAbove(SCT_STANDING, sSamusCollisionOffsets[SCT_STANDING][SAMUS_HITBOX_TOP], TRUE);
            if (collision != SCD_NONE)
            {
                // Blocks above, set crouched
                gSamusData.pose = SPOSE_CROUCHING;
                break;
            }

            if (gSamusDataCopy.xVelocity == 0)
            {
                // No X movement, normal landing
                gSamusData.pose = SPOSE_LANDING;
                break;
            }
            
            if (gSamusDataCopy.speedboostingCounter != 0)
            {
                // Landing from a fall with speedbooster activated
                gSamusData.pose = SPOSE_RUNNING;

                // Intended to keep speedbooster, however it's immediatly cancelled because of the velocity being too small
                gSamusData.speedboostingCounter = DELTA_TIME;
                break;
            }

            gSamusData.pose = SPOSE_STANDING;
            break;

        case SPOSE_SHINESPARKING:
            if (gButtonInput & gSamusData.direction)
            {
                if (gSamusData.direction & KEY_RIGHT)
                    gSamusData.xVelocity = SAMUS_X_SPEEDBOOST_VELOCITY_CAP;
                else
                    gSamusData.xVelocity = -SAMUS_X_SPEEDBOOST_VELOCITY_CAP;

                gSamusData.pose = SPOSE_RUNNING;
                gSamusData.speedboostingCounter = TRUE;
                gSamusData.counter = CONVERT_SECONDS(2.f) + TWO_THIRD_SECOND;
            }
            else
            {
                ScreenShakeStartHorizontal(CONVERT_SECONDS(.5f), 1);
                gSamusData.pose = SPOSE_DELAY_AFTER_SHINESPARKING;
                // Keep direction
                gSamusData.forcedMovement = gSamusDataCopy.forcedMovement;
                SoundPlay(SOUND_9A);
            }
            break;

        case SPOSE_MORPH_BALL_MID_AIR:
            gSamusDataCopy.lastWallTouchedMidAir++;
            if (gButtonInput & KEY_A && gEquipment.suitMiscStatus & SMF_HIGH_JUMP)
            {
                // Set bounce from maintained A
                gSamusData.forcedMovement = FORCED_MOVEMENT_MORPH_BALL_BOUNCE_BEFORE_JUMP;
            }
            else if (gSamusDataCopy.yVelocity < -SUB_PIXEL_TO_VELOCITY(QUARTER_BLOCK_SIZE) && !gSamusPhysics.slowed &&
                ClipdataGetGroundEffect(gSamusData.yPosition + ONE_SUB_PIXEL, gSamusData.xPosition) != GROUND_EFFECT_VERY_DUSTY_GROUND)
            {
                // Morph ball bounce
                gSamusData.forcedMovement = FORCED_MOVEMENT_MORPH_BALL_BOUNCE_AFTER_FALL;
                gSamusData.yVelocity = SUB_PIXEL_TO_VELOCITY(PIXEL_SIZE + PIXEL_SIZE / 2 + ONE_SUB_PIXEL / 4.f);
                break;
            }

        case SPOSE_GETTING_HURT_IN_MORPH_BALL:
        case SPOSE_GETTING_KNOCKED_BACK_IN_MORPH_BALL:
            gSamusData.pose = SPOSE_MORPH_BALL;
            break;

        case SPOSE_FROZEN_AND_FALLING:
            gSamusData.pose = SPOSE_FROZEN;
            gSamusData.counter = gSamusDataCopy.counter;
            break;

        case SPOSE_FROZEN_IN_MORPH_BALL_AND_FALLING:
            gSamusData.pose = SPOSE_FROZEN_IN_MORPH_BALL;
            gSamusData.counter = gSamusDataCopy.counter;
            gSamusDataCopy.lastWallTouchedMidAir++;
            break;

        default:
            collision = SamusCheckCollisionAbove(SCT_STANDING, sSamusCollisionOffsets[SCT_STANDING][SAMUS_HITBOX_TOP], TRUE);
            if (collision != SCD_NONE)
            {
                // Blocks above, set crouched
                gSamusData.pose = SPOSE_CROUCHING;
                break;
            }

            if (gSamusDataCopy.xVelocity == 0)
            {
                // No X movement, normal landing
                gSamusData.pose = SPOSE_LANDING;
                break;
            }
            
            gSamusData.pose = SPOSE_STANDING;
    }

    gSamusData.armCannonDirection = gSamusDataCopy.armCannonDirection;

    switch (gSamusData.pose)
    {
        case SPOSE_RUNNING:
            if (gSamusDataCopy.armCannonDirection == ACD_UP)
                gSamusData.armCannonDirection = ACD_DIAGONAL_UP;

        case SPOSE_STANDING:
        case SPOSE_LANDING:
            if (gSamusDataCopy.armCannonDirection == ACD_DOWN)
                gSamusData.armCannonDirection = ACD_DIAGONAL_DOWN;
    }

    SamusCheckSetNewEnvironmentEffect(1, ENV_REQUEST_LANDING_EFFECT);
}

/**
 * @brief 9714 | 7c | Sets the frozen pose for Samus
 * 
 */
void SamusSetFrozenPose(void)
{
    switch (gSamusDataCopy.pose)
    {
        case SPOSE_MORPHING:
        case SPOSE_MORPH_BALL:
        case SPOSE_ROLLING:
        case SPOSE_MORPH_BALL_MID_AIR:
        case SPOSE_GETTING_HURT_IN_MORPH_BALL:
        case SPOSE_GETTING_KNOCKED_BACK_IN_MORPH_BALL:
        case SPOSE_PULLING_INTO_MORPH_FROM_HANGING:
            // Any morph ball pose
            gSamusData.pose = SPOSE_FROZEN_IN_MORPH_BALL;
            break;

        default:
            // Any other pose
            gSamusData.pose = SPOSE_FROZEN;
    }
}

/**
 * @brief 9790 | 150 | Sets a hurt pose for Samus based on the previous pose
 * 
 */
void SamusSetHurtPose(void)
{
    u32 collision;
    s16 xVelocity;
    s16 yVelocity;

    if (gEquipment.currentEnergy != 0)
    {
        collision = SCD_NONE;

        switch (gSamusDataCopy.pose)
        {
            case SPOSE_MORPHING:
            case SPOSE_MORPH_BALL:
            case SPOSE_ROLLING:
            case SPOSE_MORPH_BALL_MID_AIR:
            case SPOSE_GETTING_HURT_IN_MORPH_BALL:
            case SPOSE_GETTING_KNOCKED_BACK_IN_MORPH_BALL:
            case SPOSE_PULLING_INTO_MORPH_FROM_HANGING:
                gSamusData.pose = SPOSE_GETTING_HURT_IN_MORPH_BALL;
                break;

            default:
                collision = SamusCheckCollisionAbove(SCT_STANDING, sSamusCollisionOffsets[SCT_MID_AIR][SAMUS_HITBOX_TOP], TRUE);
                gSamusData.pose = SPOSE_GETTING_HURT;
        }

        if (collision == SCD_NONE)
        {
            gSamusData.yVelocity = HURT_Y_VELOCITY;

            if (gSamusDataCopy.standingStatus == STANDING_MID_AIR)
                gSamusData.yVelocity = HURT_Y_VELOCITY / 2;
        }

        gSamusData.armCannonDirection = gSamusDataCopy.armCannonDirection;

        if (gSamusDataCopy.direction & KEY_RIGHT)
            gSamusData.xVelocity = -HURT_X_VELOCITY;
        else
            gSamusData.xVelocity = HURT_X_VELOCITY;

        unk_3b78(SOUND_SAMUS_HURT);
    }
    else
    {
        // Disable scrolling and fade screen to black
        gDisableScrolling = TRUE;
        gMonochromeFading = 0x1;
        gPoseLock = 0;

        // Set velocity to go to the center of the screen
        gSamusData.pose = SPOSE_DYING;
        xVelocity = gBg1XPosition + PIXEL_TO_SUB_PIXEL(SCREEN_X_MIDDLE) - gSamusData.xPosition;
        xVelocity = DIV_SHIFT(xVelocity, 2);
        gSamusData.xVelocity = xVelocity;

        yVelocity = gBg1YPosition + PIXEL_TO_SUB_PIXEL(SCREEN_Y_MIDDLE) + BLOCK_SIZE + QUARTER_BLOCK_SIZE - gSamusData.yPosition;
        yVelocity = DIV_SHIFT(yVelocity, 16);
        gSamusData.yVelocity = yVelocity;

        gSubGameMode1 = SUB_GAME_MODE_DYING;
    }

    gSamusData.newProjectile = NEW_PROJ_NONE;
    gSamusData.invincibilityTimer = CONVERT_SECONDS(.8f);
    gSamusAnimationInfo.shinesparkTimer = 0;
}

/**
 * @brief 98e0 | c0 | Sets the knockback pose for Samus
 * 
 */
void SamusSetKnockbackPose(void)
{
    // Set correct pose
    switch (gSamusDataCopy.pose)
    {
        case SPOSE_MORPHING:
        case SPOSE_MORPH_BALL:
        case SPOSE_ROLLING:
        case SPOSE_MORPH_BALL_MID_AIR:
        case SPOSE_GETTING_HURT_IN_MORPH_BALL:
        case SPOSE_PULLING_INTO_MORPH_FROM_HANGING:
            // Any morph ball pose
            gSamusData.pose = SPOSE_GETTING_KNOCKED_BACK_IN_MORPH_BALL;
            break;

        case SPOSE_GETTING_KNOCKED_BACK_IN_MORPH_BALL:
            break;

        default:
            // Any other pose
            gSamusData.pose = SPOSE_GETTING_KNOCKED_BACK;
            gSamusData.currentAnimationFrame = 5;
    }

    // Set Y velocity
    gSamusData.yVelocity = KNOCKBACK_Y_VELOCITY;

    if (gSamusDataCopy.standingStatus == STANDING_MID_AIR)
    {
        // Half the velocity if the hit was taken mid-air
        gSamusData.yVelocity = KNOCKBACK_Y_VELOCITY / 2;
    }

    gSamusData.armCannonDirection = gSamusDataCopy.armCannonDirection;

    // Set X velocity
    if (gSamusDataCopy.direction & KEY_RIGHT)
        gSamusData.xVelocity = -KNOCKBACK_X_VELOCITY;
    else
        gSamusData.xVelocity = KNOCKBACK_X_VELOCITY;

    // Cancel any new projectile
    gSamusData.newProjectile = 0;
}

/**
 * @brief 99a0 | 28 | To document
 * 
 */
void unk_99a0(void)
{
    gSamusData.pose = SPOSE_MID_AIR;
    gSamusData.armCannonDirection = ACD_FORWARD;

    if (gSamusDataCopy.yVelocity < 0)
        gSamusData.yVelocity = gSamusDataCopy.yVelocity;

    gSamusData.currentAnimationFrame = 2;
    gPoseLock = 0x1;
}

/**
 * @brief 99d8 | 64 | To document
 * 
 */
void unk_99d8(void)
{
    if (gSamusData.standingStatus == STANDING_GROUND)
    {
        switch (gSamusDataCopy.pose)
        {
            case SPOSE_MORPHING:
            case SPOSE_MORPH_BALL:
            case SPOSE_ROLLING:
                gSamusData.pose = SPOSE_MORPH_BALL;
                break;

            default:
                gSamusData.pose = SPOSE_STANDING;
                gSamusData.armCannonDirection = ACD_FORWARD;
                gSamusData.diagonalAim = DIAG_AIM_NONE;
        }

        gPreventMovementTimer = CONVERT_SECONDS(9.f) + ONE_THIRD_SECOND;
    }
    else
    {
        gSamusData = gSamusDataCopy;
    }
}

/**
 * @brief 9a3c | 33c | Carries what should be carried from the Samus data copy, also handles shinespark direction selection
 * 
 */
void SamusCheckCarryFromCopy(void)
{
    switch (gSamusData.pose)
    {
        case SPOSE_STANDING:
            gSamusData.armCannonDirection = gSamusDataCopy.armCannonDirection;

            if ((gSamusData.chargeBeamCounter != 0 || gSamusData.newProjectile != NEW_PROJ_NONE) &&
                gSamusDataCopy.armCannonDirection == ACD_NONE)
            {
                gSamusData.armCannonDirection = ACD_FORWARD;
            }

            if (gSamusDataCopy.pose == SPOSE_CROUCHING || gSamusDataCopy.pose == SPOSE_SHOOTING_AND_CROUCHING)
                gSamusData.counter = gSamusDataCopy.counter;
            break;

        case SPOSE_RUNNING:
            gSamusData.armRunningFlag++;

            if (gSamusData.chargeBeamCounter != 0 || gSamusData.newProjectile != NEW_PROJ_NONE || gButtonInput & gButtonAssignments.diagonalAim)
            {
                gSamusData.armCannonDirection = gSamusDataCopy.armCannonDirection;

                if (gSamusData.armCannonDirection != ACD_FORWARD && gSamusData.armCannonDirection != ACD_DIAGONAL_UP && gSamusData.armCannonDirection != ACD_DIAGONAL_DOWN)
                    gSamusData.armCannonDirection = ACD_FORWARD;
            }
            break;

        case SPOSE_CROUCHING:
            gSamusData.armCannonDirection = gSamusDataCopy.armCannonDirection;
            gSamusData.currentAnimationFrame = 1;

            if (gSamusDataCopy.armCannonDirection > ACD_DIAGONAL_DOWN)
                gSamusData.armCannonDirection = ACD_FORWARD;

            if ((gSamusData.chargeBeamCounter != 0 || gSamusData.newProjectile != NEW_PROJ_NONE) && gSamusData.armCannonDirection == ACD_NONE)
                gSamusData.armCannonDirection = ACD_FORWARD;
            break;

        case SPOSE_MORPH_BALL:
        case SPOSE_MORPH_BALL_MID_AIR:
        case SPOSE_PULLING_INTO_MORPH_FROM_HANGING:
            if (gSamusData.chargeBeamCounter >= CHARGE_BEAM_THRESHOLD)
                gSamusData.newProjectile = NEW_PROJ_CHARGED_BEAM;

            gSamusData.chargeBeamCounter = 0;
            gSamusData.diagonalAim = DIAG_AIM_NONE;
            break;

        case SPOSE_USING_ELEVATOR:
            gSamusData.chargeBeamCounter = 0;

            if (gSamusData.elevatorOrClimbingDirection & KEY_UP)
                gSamusData.yVelocity = PIXEL_SIZE;
            else
                gSamusData.yVelocity = -PIXEL_SIZE;

            SoundPlay(SOUND_FC);
            break;

        case SPOSE_STARTING_WALL_JUMP:
            gSamusData.armCannonDirection = gSamusDataCopy.armCannonDirection;

            if (gSamusDataCopy.pose == SPOSE_SPINNING || gSamusDataCopy.pose == SPOSE_WALL_JUMPING)
                gSamusData.forcedMovement++;
            break;

        case SPOSE_HANGING_ON_LEDGE:
            if ((gSamusData.yPosition & SUB_PIXEL_POSITION_FLAG) < SUB_PIXEL_POSITION_FLAG / 2)
                gSamusData.yPosition = (gSamusData.yPosition & BLOCK_POSITION_FLAG) + (EIGHTH_BLOCK_SIZE + PIXEL_SIZE - ONE_SUB_PIXEL);
            else
                gSamusData.yPosition = (gSamusData.yPosition & BLOCK_POSITION_FLAG) + BLOCK_SIZE + (EIGHTH_BLOCK_SIZE + PIXEL_SIZE - ONE_SUB_PIXEL);
            break;

        case SPOSE_SKIDDING:
            gSamusData.xVelocity = gSamusDataCopy.xVelocity;
            SamusCheckSetNewEnvironmentEffect(0, ENV_REQUEST_SKIDDING_EFFECT);
            SoundPlay(SOUND_6C);
            break;

        case SPOSE_DELAY_BEFORE_SHINESPARKING:
            SoundPlay(SOUND_99);
            break;

        case SPOSE_SHINESPARKING:
            if (gButtonInput & gButtonAssignments.diagonalAim)
            {
                gSamusData.forcedMovement = FORCED_MOVEMENT_DIAGONAL_SHINESPARK;

                if (gSamusData.direction & KEY_RIGHT)
                    gSamusData.xVelocity = SAMUS_DIAGONAL_SHINESPARK_X_VELOCITY;
                else
                    gSamusData.xVelocity = -SAMUS_DIAGONAL_SHINESPARK_X_VELOCITY;

                gSamusData.yVelocity = SAMUS_DIAGONAL_SHINESPARK_Y_VELOCITY;
                
                gSamusData.speedboostingCounter++;
            }
            else if (gButtonInput & gSamusData.direction)
            {
                if (gButtonInput & KEY_UP)
                {
                    gSamusData.forcedMovement = FORCED_MOVEMENT_DIAGONAL_SHINESPARK;

                    if (gSamusData.direction & KEY_RIGHT)
                        gSamusData.xVelocity = SAMUS_DIAGONAL_SHINESPARK_X_VELOCITY;
                    else
                        gSamusData.xVelocity = -SAMUS_DIAGONAL_SHINESPARK_X_VELOCITY;
    
                    gSamusData.yVelocity = SAMUS_DIAGONAL_SHINESPARK_Y_VELOCITY;

                    gSamusData.speedboostingCounter++;
                }
                else
                {
                    gSamusData.forcedMovement += FORCED_MOVEMENT_SIDEWARDS_SHINESPARK;

                    if (gSamusData.direction & KEY_RIGHT)
                        gSamusData.xVelocity = SAMUS_SIDEWARD_SHINESPARK_X_VELOCITY;
                    else
                        gSamusData.xVelocity = -SAMUS_SIDEWARD_SHINESPARK_X_VELOCITY;

                    gSamusData.speedboostingCounter++;
                }
            }
            else
            {
                gSamusData.yVelocity = SAMUS_SIDEWARD_SHINESPARK_X_VELOCITY;
            }

            gSamusAnimationInfo.shinesparkTimer = 0;
            break;

        case SPOSE_DELAY_AFTER_SHINESPARKING:
            gSamusData.forcedMovement = gSamusDataCopy.forcedMovement;
            SoundPlay(SOUND_9A);
            break;

        case SPOSE_PULLING_UP_FROM_HANGING:
        case SPOSE_LOWERING_DOWN_TO_START_HANGING:
            if (gSamusPhysics.slowed == TRUE)
                SoundPlay(SOUND_96);
            else
                SoundPlay(SOUND_85);

        case SPOSE_ON_SAVE_PAD:
        case SPOSE_ON_RECHARGE_OR_SECURITY_PAD:
        case SPOSE_HANGING_FROM_VERTICAL_LADDER:
        case SPOSE_HANGING_ON_HORIZONTAL_LADDER:
        case SPOSE_UNLOCKING_SECURITY:
            gSamusData.armCannonDirection = ACD_FORWARD;
            gSamusData.diagonalAim = DIAG_AIM_NONE;
            break;
        
        case SPOSE_TURNING_AROUND_MID_AIR:
            gSamusData.yVelocity = gSamusDataCopy.yVelocity;

        case SPOSE_TURNING_AROUND:
        case SPOSE_TURNING_AROUND_AND_CROUCHING:
        case SPOSE_TURNING_AROUND_TO_RECHARGE_OR_UNLOCK_DOORS:
        case SPOSE_TURNING_AROUND_ON_HORIZONTAL_LADDER:
            gSamusData.turning = TRUE;

        default:
            gSamusData.armCannonDirection = gSamusDataCopy.armCannonDirection;

            if (gSamusData.chargeBeamCounter != 0 || gSamusData.newProjectile != NEW_PROJ_NONE)
            {
                if (gSamusData.armCannonDirection == ACD_NONE)
                    gSamusData.armCannonDirection = ACD_FORWARD;
            }
    }
}

/**
 * @brief 9d78 | 1e8 | Updates Samus's velocity and position
 * 
 */
void SamusUpdateVelocityPosition(void)
{
    s16 velocity;

    gSamusCollisionData.collisionType = sSamusCollisionData[gSamusData.pose][1];
    gSamusCollisionData.unk_A = sSamusCollisionData[gSamusData.pose][2];
    gSamusCollisionData.unk_B = sSamusCollisionData[gSamusData.pose][3];

    velocity = 0;

    switch (gSamusData.pose)
    {
        case SPOSE_MID_AIR:
        case SPOSE_TURNING_AROUND_MID_AIR:
        case SPOSE_STARTING_SPIN_JUMP:
        case SPOSE_SPINNING:
        case SPOSE_MORPH_BALL_MID_AIR:
        case SPOSE_GETTING_HURT:
        case SPOSE_GETTING_HURT_IN_MORPH_BALL:
        case SPOSE_GETTING_KNOCKED_BACK:
        case SPOSE_GETTING_KNOCKED_BACK_IN_MORPH_BALL:
        case SPOSE_WALL_JUMPING:
        case SPOSE_SPACE_JUMPING:
        case SPOSE_SCREW_ATTACKING:
        case SPOSE_FROZEN_AND_FALLING:
        case SPOSE_FROZEN_IN_MORPH_BALL_AND_FALLING:
            // Check is within the bounds
            if (gSamusData.yVelocity > gSamusPhysics.yVelocityCap)
                velocity = VELOCITY_TO_SUB_PIXEL(gSamusPhysics.yVelocityCap);
            else if (gSamusData.yVelocity < -gSamusPhysics.yVelocityCap)
                velocity = VELOCITY_TO_SUB_PIXEL(-gSamusPhysics.yVelocityCap);
            else
                velocity = VELOCITY_TO_SUB_PIXEL(gSamusData.yVelocity);

            // Apply acceleration
            if (gSamusData.yVelocity > -SAMUS_TERMINAL_VELOCITY)
                gSamusData.yVelocity -= gSamusPhysics.yAcceleration;

            gSamusData.yPosition -= velocity;
            break;

        case SPOSE_SHINESPARKING:
            if (!(gSamusData.forcedMovement & FORCED_MOVEMENT_SIDEWARDS_SHINESPARK))
            {
                velocity = VELOCITY_TO_SUB_PIXEL(gSamusData.yVelocity);
                gSamusData.yPosition -= velocity;
            }
            break;

        case SPOSE_USING_ELEVATOR:
        case SPOSE_HANGING_FROM_VERTICAL_LADDER:
            // Don't perform convertion
            velocity = gSamusData.yVelocity;
            gSamusData.yPosition -= velocity;
            break;
    }

    if (gSamusData.standingStatus == STANDING_GROUND)
    {
        // Get ground velocity
        velocity = VELOCITY_TO_SUB_PIXEL(SamusChangeVelocityOnSlope());

        if (gSamusData.pose == SPOSE_RUNNING)
        {
            // Security measure, cancel all velocity if it's going in the opposite direction
            if (gSamusData.direction & KEY_RIGHT)
            {
                if (velocity < 0)
                    velocity = 0;
            }
            else
            {
                if (velocity != 0 && velocity > 0)
                    velocity = 0;
            }
        }
    }
    else if (!gSamusUseYVelocityForX)
    {
        velocity = VELOCITY_TO_SUB_PIXEL(gSamusData.xVelocity);
    }

    gSamusData.xPosition += velocity;
}

/**
 * @brief 9f60 | f4 | Checks for screw attack and speed booster damage to the environment
 * 
 */
void SamusCheckScrewSpeedboosterAffectingEnvironment(void)
{
    u16 action;
    u32 collisionType;
    u16 xLeft;
    u16 xRight;
    u16 yTop;
    u16 yBottom;

    action = SDA_NONE;

    if (gSamusData.pose == SPOSE_SCREW_ATTACKING)
        action = SDA_SCREW_ATTACK;

    if (gSamusData.speedboostingCounter != 0)
        action += SDA_SPEED_BOOSTER;

    if (action == SDA_NONE)
        return;

    collisionType = gSamusCollisionData.collisionType;
    xLeft = gSamusData.xPosition + sSamusCollisionOffsets[collisionType][SAMUS_HITBOX_LEFT];
    xRight = gSamusData.xPosition + sSamusCollisionOffsets[collisionType][SAMUS_HITBOX_RIGHT];
    yTop = gSamusData.yPosition + sSamusCollisionOffsets[collisionType][SAMUS_HITBOX_TOP];
    yBottom = gSamusData.yPosition;

    // Destroy the top left and right blocks
    SamusApplyScrewSpeedboosterDamageToEnvironment(xLeft, yTop, action);
    SamusApplyScrewSpeedboosterDamageToEnvironment(xRight, yTop, action);

    if (gSamusCollisionData.horizontalMovingDirection & KEY_RIGHT)
    {
        // Destroy bottom right block
        SamusApplyScrewSpeedboosterDamageToEnvironment(xRight, yTop + BLOCK_SIZE, action);
        // Destroy below bottom right block
        SamusApplyScrewSpeedboosterDamageToEnvironment(xRight, yBottom, action);
    }
    else
    {
        // Destroy bottom left block
        SamusApplyScrewSpeedboosterDamageToEnvironment(xLeft, yTop + BLOCK_SIZE, action);
        // Destroy below bottom left block
        SamusApplyScrewSpeedboosterDamageToEnvironment(xLeft, yBottom, action);
    }

    if (gSamusCollisionData.standingStatus == STANDING_GROUND)
    {
        yBottom += ONE_SUB_PIXEL;
        action = SDA_SPEED_BOOSTER_ON_GROUND;
    }

    SamusApplyScrewSpeedboosterDamageToEnvironment(xLeft, yBottom, action);
    SamusApplyScrewSpeedboosterDamageToEnvironment(xRight, yBottom, action);
}

/**
 * @brief a054 | 48c | Main function that handles Samus collision detection
 * 
 */
void SamusCheckCollisions(void)
{
    u16 nextX;
    u16 nextY;
    u16 unk_0;
    u32 slopeType;
    u8 newPose;
    s16 xOffset;
    u32 blockAbove;
    u32 blockSideNear;
    u32 blockSideFar;
    s32 clipdata;

    gSamusCollisionData.standingStatus = sSamusCollisionData[gSamusData.pose][4];

    if (gSamusCollisionData.standingStatus == STANDING_NOT_IN_CONTROL)
    {
        if (gSamusData.pose != SPOSE_PULLING_FORWARD_FROM_HANGING)
            return;

        slopeType = SamusCheckCollisionAtPosition(gSamusData.xPosition, gSamusData.yPosition, &nextX, &nextY, &unk_0);

        if (slopeType != SLOPE_NONE)
        {
            gSamusData.slopeType = slopeType;
            gSamusData.yPosition = nextY;
        }

        return;
    }

    SamusCheckScrewSpeedboosterAffectingEnvironment();

    newPose = SPOSE_NONE;

    if (gSamusCollisionData.verticalMovingDirection & KEY_UP)
    {
        newPose = SamusCheckJumpingCollision();
    }
    else if (gSamusCollisionData.verticalMovingDirection & KEY_DOWN)
    {
        newPose = SamusCheckLandingCollision();
    }
    else if (gSamusCollisionData.horizontalMovingDirection != KEY_NONE)
    {
        if (gSamusCollisionData.standingStatus == STANDING_MID_AIR)
        {
            newPose = SamusCheckLandingCollision();
        }
        else
        {
            newPose = SamusCheckWalkingSidesCollision();
            if (newPose == SPOSE_NONE)
                newPose = unk_b3c8();
        }
    }
    else if (gSamusCollisionData.standingStatus == STANDING_GROUND)
    {
        newPose = SamusCheckStandingOnGroundCollision();
    }

    if (newPose == SPOSE_NONE)
    {
        if (gButtonInput & gSamusData.direction && gSamusData.yVelocity <= 0)
        {
            if (gSamusData.direction & KEY_RIGHT)
                xOffset = (SAMUS_LEDGE_GRAB_X_RANGE - ONE_SUB_PIXEL);
            else
                xOffset = -(SAMUS_LEDGE_GRAB_X_RANGE - ONE_SUB_PIXEL);

            blockAbove = ClipdataProcessForSamus(gSamusData.yPosition + HALF_BLOCK_SIZE, gSamusData.xPosition);

            if (blockAbove == CLIPDATA_TYPE_AIR)
            {
                blockAbove = ClipdataProcessForSamus(gSamusData.yPosition - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE), gSamusData.xPosition) & CLIPDATA_TYPE_SOLID_FLAG;
                blockSideNear = ClipdataProcessForSamus(gSamusData.yPosition - (BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE), gSamusData.xPosition + xOffset) & CLIPDATA_TYPE_SOLID_FLAG;
                blockSideFar = ClipdataProcessForSamus(gSamusData.yPosition - (BLOCK_SIZE * 2), gSamusData.xPosition + xOffset) & CLIPDATA_TYPE_SOLID_FLAG;

                switch (gSamusData.pose)
                {
                    case SPOSE_MID_AIR:
                    case SPOSE_STARTING_SPIN_JUMP:
                    case SPOSE_SPINNING:
                    case SPOSE_STARTING_WALL_JUMP:
                    case SPOSE_WALL_JUMPING:
                    case SPOSE_SPACE_JUMPING:
                    case SPOSE_SCREW_ATTACKING:
                        if (!blockAbove && blockSideNear && !blockSideFar)
                        {
                            newPose = SPOSE_HANGING_ON_LEDGE;

                            if (gSamusPhysics.slowed == TRUE)
                                SoundPlay(SOUND_97);
                            else
                                SoundPlay(SOUND_82);
                        }

                        if (newPose == SPOSE_NONE)
                        {
                            clipdata = HIGH_SHORT(ClipdataCheckCurrentAffectingAtPosition(gSamusData.yPosition - (BLOCK_SIZE * 2 - PIXEL_SIZE), gSamusData.xPosition + xOffset));
                            if (clipdata == CLIPDATA_MOVEMENT_WALL_LADDER)
                            {
                                newPose = SPOSE_HANGING_FROM_VERTICAL_LADDER;

                                if (gSamusPhysics.slowed == TRUE)
                                    SoundPlay(SOUND_97);
                                else
                                    SoundPlay(SOUND_83);
                            }
                        }
                }
            }
        }

        if (newPose == SPOSE_NONE)
        {
            switch (gSamusData.pose)
            {
                case SPOSE_MID_AIR:
                case SPOSE_STARTING_SPIN_JUMP:
                case SPOSE_SPINNING:
                case SPOSE_STARTING_WALL_JUMP:
                case SPOSE_WALL_JUMPING:
                case SPOSE_SPACE_JUMPING:
                case SPOSE_SCREW_ATTACKING:
                    if (!(gButtonInput & KEY_UP))
                        break;

                    if (gSamusData.yVelocity > 0)
                        break;

                    clipdata = HIGH_SHORT(ClipdataCheckCurrentAffectingAtPosition(gSamusData.yPosition - BLOCK_SIZE * 2, gSamusData.xPosition));
                    if (clipdata == CLIPDATA_MOVEMENT_CEILING_LADDER)
                    {
                        gSamusData.yPosition = (gSamusData.yPosition & BLOCK_POSITION_FLAG) + BLOCK_SIZE + EIGHTH_BLOCK_SIZE;
                        newPose = SPOSE_HANGING_ON_HORIZONTAL_LADDER;

                        if (gSamusPhysics.slowed == TRUE)
                            SoundPlay(SOUND_97);
                        else
                            SoundPlay(SOUND_84);
                    }
            }
        }
    }

    if (gSamusData.pose == SPOSE_HANGING_FROM_VERTICAL_LADDER)
    {
        if (gSamusData.direction & KEY_RIGHT)
            xOffset = HALF_BLOCK_SIZE;
        else
            xOffset = -HALF_BLOCK_SIZE;

        clipdata = HIGH_SHORT(ClipdataCheckCurrentAffectingAtPosition(gSamusData.yPosition - (BLOCK_SIZE * 2 - PIXEL_SIZE), gSamusData.xPosition + xOffset));

        if (gSamusCollisionData.verticalMovingDirection & KEY_UP)
        {
            if (clipdata != CLIPDATA_MOVEMENT_WALL_LADDER)
            {
                nextY = gSamusData.yPosition + sSamusCollisionOffsets[gSamusCollisionData.collisionType][SAMUS_HITBOX_TOP];
                gSamusData.yPosition = (nextY & BLOCK_POSITION_FLAG) - sSamusCollisionOffsets[gSamusCollisionData.collisionType][SAMUS_HITBOX_TOP] + BLOCK_SIZE;
            }
        }
        else if (gSamusCollisionData.verticalMovingDirection & KEY_DOWN)
        {
            gSamusData.xPosition = gPreviousXPosition;

            if (clipdata != CLIPDATA_MOVEMENT_WALL_LADDER)
            {
                newPose = SPOSE_MID_AIR_REQUEST;
                gSamusData.yPosition = gPreviousYPosition + ONE_SUB_PIXEL;
            }
        }
    }

    if (gSamusData.pose == SPOSE_MOVING_ON_HORIZONTAL_LADDER)
    {
        clipdata = HIGH_SHORT(ClipdataCheckCurrentAffectingAtPosition(gSamusData.yPosition - (BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE), gSamusData.xPosition));
        if (clipdata != CLIPDATA_MOVEMENT_CEILING_LADDER)
        {
            if (gSamusData.direction & KEY_RIGHT)
                xOffset = -ONE_SUB_PIXEL;
            else
                xOffset = BLOCK_SIZE;

            gSamusData.xPosition = (gSamusData.xPosition & BLOCK_POSITION_FLAG) + xOffset;
        }
    }

    if (gSamusCollisionData.touchingSideBlock)
    {
        switch (gSamusData.pose)
        {
            case SPOSE_SPINNING:
            case SPOSE_WALL_JUMPING:
            case SPOSE_SCREW_ATTACKING:
                gSamusData.walljumpTimer = CONVERT_SECONDS(.1f);
                gSamusData.lastWallTouchedMidAir = OPPOSITE_DIRECTION(gSamusData.direction);
        }
    }

    if (gSamusCollisionData.standingStatus != STANDING_INVALID)
    {
        if (newPose != SPOSE_NONE)
            SamusSetPose(newPose);

        if (newPose == SPOSE_MID_AIR_REQUEST)
            gSamusData.yPosition += ONE_SUB_PIXEL;
    }
}

/**
 * @brief a4e0 | 190 | To document
 * 
 * @param xPosition X position
 * @param yPosition Y position
 * @param pNextX Pointer to next X position
 * @param pNextY Pointer to next Y position
 * @param param_4 To document
 * @return u32 Collision result
 */
u32 SamusCheckCollisionAtPosition(u16 xPosition, u16 yPosition, u16* pNextX, u16* pNextY, u16* param_4)
{
    // TODO: param_4 should be set to the same enum
    
    u32 clipType;
    u16 yPos;
    u16 xPos;
    u32 result;

    clipType = ClipdataProcessForSamus(yPosition, xPosition);

    if (clipType & CLIPDATA_TYPE_SOLID_FLAG)
        *param_4 = CLIPDATA_TYPE_SOLID;
    else
        *param_4 = CLIPDATA_TYPE_AIR;

    switch (LOW_BYTE(clipType))
    {
        case CLIPDATA_TYPE_RIGHT_STEEP_FLOOR_SLOPE:
            yPos = (yPosition & BLOCK_POSITION_FLAG) + SUB_PIXEL_POSITION_FLAG - (xPosition & SUB_PIXEL_POSITION_FLAG);
            xPos = (xPosition & BLOCK_POSITION_FLAG) + SUB_PIXEL_POSITION_FLAG - (yPosition & SUB_PIXEL_POSITION_FLAG);
            result = SLOPE_STEEP | KEY_RIGHT;
            break;

        case CLIPDATA_TYPE_RIGHT_LOWER_SLIGHT_FLOOR_SLOPE:
            yPos = (yPosition & BLOCK_POSITION_FLAG) + SUB_PIXEL_POSITION_FLAG - ((xPosition & SUB_PIXEL_POSITION_FLAG) / 2);
            xPos = (xPosition & BLOCK_POSITION_FLAG) + (SUB_PIXEL_POSITION_FLAG * 2) - ((yPosition & SUB_PIXEL_POSITION_FLAG) * 2);
            result = SLOPE_SLIGHT | KEY_RIGHT;
            break;

        case CLIPDATA_TYPE_RIGHT_UPPER_SLIGHT_FLOOR_SLOPE:
            yPos = (yPosition & BLOCK_POSITION_FLAG) + (SUB_PIXEL_POSITION_FLAG / 2) - ((xPosition & SUB_PIXEL_POSITION_FLAG) / 2);
            xPos = (xPosition & BLOCK_POSITION_FLAG) + (SUB_PIXEL_POSITION_FLAG - 1) - ((yPosition & SUB_PIXEL_POSITION_FLAG) * 2);
            result = SLOPE_SLIGHT | KEY_RIGHT;
            break;

        case CLIPDATA_TYPE_LEFT_STEEP_FLOOR_SLOPE:
            yPos = (yPosition & BLOCK_POSITION_FLAG) | (xPosition & SUB_PIXEL_POSITION_FLAG);
            xPos = (xPosition & BLOCK_POSITION_FLAG) | (yPosition & SUB_PIXEL_POSITION_FLAG);
            result = SLOPE_STEEP | KEY_LEFT;
            break;

        case CLIPDATA_TYPE_LEFT_LOWER_SLIGHT_FLOOR_SLOPE:
            yPos = (yPosition & BLOCK_POSITION_FLAG) | (((xPosition & SUB_PIXEL_POSITION_FLAG) / 2) + (SUB_PIXEL_POSITION_FLAG / 2));
            xPos = (xPosition & BLOCK_POSITION_FLAG) + (((yPosition & SUB_PIXEL_POSITION_FLAG) * 2) + (BLOCK_POSITION_FLAG + 1));
            result = SLOPE_SLIGHT | KEY_LEFT;
            break;

        case CLIPDATA_TYPE_LEFT_UPPER_SLIGHT_FLOOR_SLOPE:
            yPos = (yPosition & BLOCK_POSITION_FLAG) | ((xPosition & SUB_PIXEL_POSITION_FLAG) / 2);
            xPos = (xPosition & BLOCK_POSITION_FLAG) + ((yPosition & SUB_PIXEL_POSITION_FLAG) * 2);
            result = SLOPE_SLIGHT | KEY_LEFT;
            break;

        case CLIPDATA_TYPE_PASS_THROUGH_BOTTOM:
            *param_4 = COLLISION_PASS_THROUGH_BOTTOM;

        default:
            yPos = (yPosition & BLOCK_POSITION_FLAG);
            xPos = (xPosition & BLOCK_POSITION_FLAG);
            result = SLOPE_NONE;
            break;
    }

    *pNextY = yPos;
    *pNextX = xPos;
    return result;
}

/**
 * @brief a670 | 148 | To document
 * 
 * @param collisionType Collision type
 * @param pNextX Result X position
 * @param hitbox Y hitbox
 * @return u32 Collision flags
 */
u32 unk_a670(u8 collisionType, u16* pNextX, s16 hitbox)
{
    u32 result;
    u16 xPosition;
    u16 yPosition;
    s32 clipdata;

    result = SCD_NONE;
    xPosition = gSamusData.xPosition + sSamusCollisionOffsets[collisionType][gSamusCollisionData.unk_4];
    yPosition = gSamusData.yPosition + sSamusCollisionOffsets[collisionType][SAMUS_HITBOX_TOP];

    clipdata = ClipdataProcessForSamus(yPosition, xPosition);

    if (clipdata & CLIPDATA_TYPE_SOLID_FLAG)
    {
        switch (LOW_BYTE(clipdata))
        {
            case CLIPDATA_TYPE_LEFT_STEEP_FLOOR_SLOPE:
            case CLIPDATA_TYPE_RIGHT_STEEP_FLOOR_SLOPE:
            case CLIPDATA_TYPE_LEFT_UPPER_SLIGHT_FLOOR_SLOPE:
            case CLIPDATA_TYPE_LEFT_LOWER_SLIGHT_FLOOR_SLOPE:
            case CLIPDATA_TYPE_RIGHT_LOWER_SLIGHT_FLOOR_SLOPE:
            case CLIPDATA_TYPE_RIGHT_UPPER_SLIGHT_FLOOR_SLOPE:
                break;

            default:
                result += SCD_TOP_LEFT_MOST;
        }
    }

    if (hitbox > sSamusCollisionOffsets[collisionType][SAMUS_HITBOX_TOP] + BLOCK_SIZE)
    {
        yPosition += BLOCK_SIZE;
        clipdata = ClipdataProcessForSamus(yPosition, xPosition);
    
        if (clipdata & CLIPDATA_TYPE_SOLID_FLAG)
        {
            switch (LOW_BYTE(clipdata))
            {
                case CLIPDATA_TYPE_LEFT_STEEP_FLOOR_SLOPE:
                case CLIPDATA_TYPE_RIGHT_STEEP_FLOOR_SLOPE:
                case CLIPDATA_TYPE_LEFT_UPPER_SLIGHT_FLOOR_SLOPE:
                case CLIPDATA_TYPE_LEFT_LOWER_SLIGHT_FLOOR_SLOPE:
                case CLIPDATA_TYPE_RIGHT_LOWER_SLIGHT_FLOOR_SLOPE:
                case CLIPDATA_TYPE_RIGHT_UPPER_SLIGHT_FLOOR_SLOPE:
                    break;

                default:
                    result += SCD_TOP_LEFT_MIDDLE;
            }
        }
    }

    if (hitbox > sSamusCollisionOffsets[collisionType][SAMUS_HITBOX_TOP])
    {
        yPosition = gSamusData.yPosition + hitbox;
        clipdata = ClipdataProcessForSamus(yPosition, xPosition);
    
        if (clipdata & CLIPDATA_TYPE_SOLID_FLAG)
        {
            switch (LOW_BYTE(clipdata))
            {
                case CLIPDATA_TYPE_LEFT_STEEP_FLOOR_SLOPE:
                case CLIPDATA_TYPE_RIGHT_STEEP_FLOOR_SLOPE:
                case CLIPDATA_TYPE_LEFT_UPPER_SLIGHT_FLOOR_SLOPE:
                case CLIPDATA_TYPE_LEFT_LOWER_SLIGHT_FLOOR_SLOPE:
                case CLIPDATA_TYPE_RIGHT_LOWER_SLIGHT_FLOOR_SLOPE:
                case CLIPDATA_TYPE_RIGHT_UPPER_SLIGHT_FLOOR_SLOPE:
                    break;

                default:
                    result += SCD_TOP_RIGHT_MIDDLE;
            }
        }
    }

    if (result != SCD_NONE)
    {
        *pNextX = (xPosition & BLOCK_POSITION_FLAG) -
            sSamusCollisionOffsets[collisionType][gSamusCollisionData.unk_4] + gSamusCollisionData.unk_6;
    }

    return result;
}

/**
 * @brief a7b8 | 144 | Checks for collision in the 4 blocks above Samus
 * 
 * @param collisionType Collision type
 * @param hitbox Y hitbox
 * @param param_3 To document
 * @return u32 Collision flags
 */
u32 SamusCheckCollisionAbove(u8 collisionType, u16 yHitbox, u8 param_3)
{
    u32 previous;
    u32 result;
    u16 yPosition;
    u16 xPosition;

    previous = SCD_NONE;
    if (!param_3)
    {
        yPosition = gPreviousYPosition + yHitbox;

        xPosition = gSamusData.xPosition + sSamusCollisionOffsetsAbove[collisionType][0];
        if (ClipdataProcessForSamus(yPosition, xPosition) & CLIPDATA_TYPE_SOLID_FLAG)
            previous += SCD_TOP_LEFT_MOST;

        xPosition = gSamusData.xPosition + sSamusCollisionOffsetsAbove[collisionType][3];
        if (ClipdataProcessForSamus(yPosition, xPosition) & CLIPDATA_TYPE_SOLID_FLAG)
            previous += SCD_TOP_RIGHT_MOST;
    }

    result = SCD_NONE;
    yPosition = gSamusData.yPosition + yHitbox;

    if (!(previous & SCD_TOP_LEFT_MOST))
    {
        xPosition = gSamusData.xPosition + sSamusCollisionOffsetsAbove[collisionType][0];
        if (ClipdataProcessForSamus(yPosition, xPosition) & CLIPDATA_TYPE_SOLID_FLAG)
            result += SCD_TOP_LEFT_MOST;
    }

    xPosition = gSamusData.xPosition + sSamusCollisionOffsetsAbove[collisionType][1];
    if (ClipdataProcessForSamus(yPosition, xPosition) & CLIPDATA_TYPE_SOLID_FLAG)
        result += SCD_TOP_LEFT_MIDDLE;

    xPosition = gSamusData.xPosition + sSamusCollisionOffsetsAbove[collisionType][2];
    if (ClipdataProcessForSamus(yPosition, xPosition) & CLIPDATA_TYPE_SOLID_FLAG)
        result += SCD_TOP_RIGHT_MIDDLE;

    if (!(previous & SCD_TOP_RIGHT_MOST))
    {
        xPosition = gSamusData.xPosition + sSamusCollisionOffsetsAbove[collisionType][3];
        if (ClipdataProcessForSamus(yPosition, xPosition) & CLIPDATA_TYPE_SOLID_FLAG)
            result += SCD_TOP_RIGHT_MOST;
    }

    return result;
}

/**
 * @brief a8fc | 100 | To document
 * 
 * @param collisionType Collision type
 * @param yPosition Y position
 * @param param_3 To document
 * @return u32 Collision flags
 */
u32 unk_a8fc(u8 collisionType, u16 yPosition, u16* param_3)
{
    u32 result;
    u16 flags;
    u32 clipdata;
    u16 xPosition;

    result = SCD_NONE;
    flags = SCD_NONE;

    xPosition = gSamusData.xPosition + sSamusCollisionOffsets[collisionType][SAMUS_HITBOX_LEFT];
    clipdata = ClipdataProcessForSamus(yPosition, xPosition);
    if (clipdata & CLIPDATA_TYPE_SOLID_FLAG)
    {
        result += SCD_TOP_LEFT_MOST;
    }
    else if (LOW_BYTE(clipdata) == CLIPDATA_TYPE_PASS_THROUGH_BOTTOM)
    {
        result += SCD_TOP_LEFT_MOST;
        flags += SCD_TOP_LEFT_MOST;
    }

    xPosition = gSamusData.xPosition + sSamusCollisionOffsets[collisionType][SAMUS_HITBOX_RIGHT];
    clipdata = ClipdataProcessForSamus(yPosition, xPosition);
    if (clipdata & CLIPDATA_TYPE_SOLID_FLAG)
    {
        result += SCD_TOP_LEFT_MIDDLE;
    }
    else if (LOW_BYTE(clipdata) == CLIPDATA_TYPE_PASS_THROUGH_BOTTOM)
    {
        result += SCD_TOP_LEFT_MIDDLE;
        flags += SCD_TOP_LEFT_MIDDLE;
    }

    if (sSamusCollisionOffsets[collisionType][SAMUS_HITBOX_RIGHT] > HALF_BLOCK_SIZE - ONE_SUB_PIXEL)
    {
        xPosition = gSamusData.xPosition;
        clipdata = ClipdataProcessForSamus(yPosition, xPosition);
        if (clipdata & CLIPDATA_TYPE_SOLID_FLAG)
        {
            result += SCD_TOP_RIGHT_MIDDLE;
        }
        else if (LOW_BYTE(clipdata) == CLIPDATA_TYPE_PASS_THROUGH_BOTTOM)
        {
            result += SCD_TOP_RIGHT_MIDDLE;
            flags += SCD_TOP_RIGHT_MIDDLE;
        }
    }

    *param_3 = flags;
    return result;
}

/**
 * @brief a9fc | 3d0 | Checks for collisions on the side when walking
 * 
 * @return u8 New pose
 */
u8 SamusCheckWalkingSidesCollision(void)
{
    u16 nextX;
    u16 nextY;
    u8 collisionType_;
    u8 collisionType;
    u16 var_0;
    u32 unk_4;
    u32 unk_5;
    u32 result;
    u16 yPosition;
    u16 xPosition;
    u16 hdMoving;
    s16 hitbox;

    hdMoving = gSamusCollisionData.horizontalMovingDirection;
    collisionType = gSamusCollisionData.collisionType;
    collisionType_ = collisionType;
    unk_4 = gSamusCollisionData.unk_4;
    unk_5 = gSamusCollisionData.unk_5;

    if (gSamusData.slopeType == SLOPE_NONE)
    {
        if (gSamusData.standingStatus == STANDING_ENEMY)
        {
            hitbox = 0;
            result = unk_a670(collisionType, &nextX, hitbox);
        }
        else
        {
            hitbox = -(BLOCK_SIZE - PIXEL_SIZE / 2);
            result = unk_a670(collisionType, &nextX, hitbox);
        }

        if (result != SCD_NONE)
        {
            gSamusData.xPosition = nextX;
            gSamusData.xVelocity = 0;
            gSamusCollisionData.touchingSideBlock++;
        }
        else
        {
            collisionType_ = gSamusCollisionData.unk_B;
        }

        xPosition = gSamusData.xPosition + sSamusCollisionOffsets[collisionType][unk_4];
        yPosition = gSamusData.yPosition;
        result = SamusCheckCollisionAtPosition(xPosition, yPosition, &nextX, &nextY, &var_0);

        if (result != SLOPE_NONE && var_0 != 0)
        {
            gSamusData.slopeType = result;
            gSamusData.yPosition = nextY;
            gSamusData.standingStatus = STANDING_GROUND;
            return SPOSE_NONE;
        }

        xPosition = gSamusData.xPosition + sSamusCollisionOffsets[collisionType_][unk_4];
        yPosition += ONE_SUB_PIXEL;
        result = SamusCheckCollisionAtPosition(xPosition, yPosition, &nextX, &nextY, &var_0);

        if (var_0 == 0)
        {
            xPosition = gSamusData.xPosition + sSamusCollisionOffsets[collisionType][unk_5];
            result = SamusCheckCollisionAtPosition(xPosition, yPosition, &nextX, &nextY, &var_0);

            if (result != SLOPE_NONE)
            {
                gSamusData.slopeType = result;
                gSamusData.yPosition = nextY;
                gSamusData.standingStatus = STANDING_GROUND;
                return SPOSE_NONE;
            }

            xPosition = gSamusData.xPosition + sSamusCollisionOffsets[collisionType_][unk_5];
            SamusCheckCollisionAtPosition(xPosition, yPosition, &nextX, &nextY, &var_0);

            if (var_0 == 0)
            {
                if (gSamusData.standingStatus == STANDING_ENEMY)
                    return SPOSE_NONE;

                SamusCheckCollisionAtPosition(gSamusData.xPosition, yPosition, &nextX, &nextY, &var_0);

                if (var_0 == 0)
                    return SPOSE_MID_AIR_REQUEST;
            }
        }
        else
        {
            if (var_0 & 0x10)
            {
                if (gSamusData.standingStatus == STANDING_ENEMY)
                    return SPOSE_NONE;

                SamusCheckCollisionAtPosition(xPosition, gSamusData.yPosition - ONE_SUB_PIXEL, &nextX, &nextY, &var_0);

                if (var_0 & 0x10)
                {
                    xPosition = gSamusData.xPosition + sSamusCollisionOffsets[collisionType_][unk_5];
                    SamusCheckCollisionAtPosition(xPosition, gSamusData.yPosition - ONE_SUB_PIXEL, &nextX, &nextY, &var_0);

                    if (var_0 == 0 || var_0 & 0x10)
                        return SPOSE_MID_AIR_REQUEST;
                }
            }
        }

        gSamusData.standingStatus = STANDING_GROUND;
        return SPOSE_NONE;
    }

    if (gSamusData.slopeType & hdMoving)
    {
        result = unk_a670(collisionType, &nextX, -(BLOCK_SIZE - PIXEL_SIZE / 2));

        if (result != SCD_NONE)
        {
            gSamusData.xPosition = nextX;
            gSamusData.xVelocity = 0;
            gSamusCollisionData.touchingSideBlock++;
        }

        xPosition = gSamusData.xPosition + sSamusCollisionOffsets[collisionType][unk_4];
        yPosition = gSamusData.yPosition;
        result = SamusCheckCollisionAtPosition(xPosition, yPosition, &nextX, &nextY, &var_0);
        gSamusData.slopeType = result;

        if (result == SLOPE_NONE)
        {
            if (var_0 == 0)
                return SPOSE_NONE;

            yPosition -= BLOCK_SIZE;
            result = SamusCheckCollisionAtPosition(xPosition, yPosition, &nextX, &nextY, &var_0);
            gSamusData.slopeType = result;

            if (result != SLOPE_NONE)
            {
                gSamusData.yPosition = nextY;
                return SPOSE_NONE;
            }

            gSamusData.yPosition = nextY + BLOCK_SIZE - ONE_SUB_PIXEL;
            return SPOSE_NONE;
        }

        gSamusData.yPosition = nextY;
        return SPOSE_NONE;
    }

    if (gSamusData.standingStatus == STANDING_ENEMY)
    {
        gSamusData.slopeType = SLOPE_NONE;
        return SPOSE_NONE;
    }

    xPosition = gSamusData.xPosition + sSamusCollisionOffsets[collisionType][unk_5];
    yPosition = gSamusData.yPosition;
    result = SamusCheckCollisionAtPosition(xPosition, yPosition, &nextX, &nextY, &var_0);

    if (result != SLOPE_NONE)
    {
        gSamusData.yPosition = nextY;
        return SPOSE_NONE;
    }

    if (var_0 != 0)
        return SPOSE_NONE;

    yPosition += BLOCK_SIZE;
    result = SamusCheckCollisionAtPosition(xPosition, yPosition, &nextX, &nextY, &var_0);
    gSamusData.slopeType = result;

    if (result != SLOPE_NONE)
    {
        gSamusData.yPosition = nextY;
        return SPOSE_NONE;
    }
    
    if (var_0 != 0)
    {
        if (gSamusData.direction & KEY_RIGHT)
            gSamusData.xPosition = nextX - sSamusCollisionOffsets[collisionType][SAMUS_HITBOX_LEFT];
        else
            gSamusData.xPosition = nextX - sSamusCollisionOffsets[collisionType][SAMUS_HITBOX_RIGHT] + BLOCK_SIZE - ONE_SUB_PIXEL;

        gSamusData.yPosition = nextY - ONE_SUB_PIXEL;
    }

    return SPOSE_NONE;
}

/**
 * @brief adcc | 1dc | Checks for collisions when standing
 * 
 * @return u8 New pose
 */
u8 SamusCheckStandingOnGroundCollision(void)
{
    u8 collisionType;
    u8 unk_A;
    u32 result;
    u16 xPosition;
    u16 yPosition;
    u16 nextX;
    u16 nextY;
    u16 var_0;
    u16 oldY;

    collisionType = gSamusCollisionData.collisionType;
    unk_A = gSamusCollisionData.unk_A;

    result = SamusCheckCollisionAbove(unk_A, sSamusCollisionOffsets[collisionType][SAMUS_HITBOX_TOP], TRUE);

    if (result == SCD_TOP_LEFT_MOST || result == (SCD_TOP_LEFT_MOST | SCD_TOP_LEFT_MIDDLE))
    {
        xPosition = gSamusData.xPosition + sSamusCollisionOffsetsAbove[unk_A][0];
        gSamusData.xPosition = (xPosition & BLOCK_POSITION_FLAG) - sSamusCollisionOffsetsAbove[unk_A][0] + BLOCK_SIZE;
    }
    else if (result == SCD_TOP_RIGHT_MOST || result == (SCD_TOP_RIGHT_MOST | SCD_TOP_RIGHT_MIDDLE))
    {
        xPosition = gSamusData.xPosition + sSamusCollisionOffsetsAbove[unk_A][3];
        gSamusData.xPosition = (xPosition & BLOCK_POSITION_FLAG) - sSamusCollisionOffsetsAbove[unk_A][3] - ONE_SUB_PIXEL;
    }

    xPosition = gSamusData.xPosition + sSamusCollisionOffsets[collisionType][SAMUS_HITBOX_LEFT];
    yPosition = gSamusData.yPosition + ONE_SUB_PIXEL;

    result = SamusCheckCollisionAtPosition(xPosition, yPosition, &nextX, &nextY, &var_0);

    if (var_0 != 0)
    {
        if (result != SLOPE_NONE)
        {
            gSamusData.slopeType = result;
            gSamusData.yPosition = nextY;
        }
        else if (var_0 != 0x10)
        {
            oldY = nextY;
            result = SamusCheckCollisionAtPosition(xPosition + ONE_SUB_PIXEL, yPosition + ONE_SUB_PIXEL, &nextX, &nextY, &var_0);
            gSamusData.slopeType = result;

            if (result != SLOPE_NONE)
                gSamusData.yPosition = oldY;
            else
                gSamusData.yPosition = oldY - ONE_SUB_PIXEL;
        }

        return SPOSE_NONE;
    }

    xPosition = gSamusData.xPosition + sSamusCollisionOffsets[collisionType][SAMUS_HITBOX_RIGHT];
    result = SamusCheckCollisionAtPosition(xPosition, yPosition, &nextX, &nextY, &var_0);

    if (var_0 != 0)
    {
        if (result != SLOPE_NONE)
        {
            gSamusData.slopeType = result;
            gSamusData.yPosition = nextY;
        }
        else if (var_0 != 0x10)
        {
            oldY = nextY;
            result = SamusCheckCollisionAtPosition(xPosition - ONE_SUB_PIXEL, yPosition + ONE_SUB_PIXEL, &nextX, &nextY, &var_0);
            gSamusData.slopeType = result;

            if (result != SLOPE_NONE)
                gSamusData.yPosition = oldY;
            else
                gSamusData.yPosition = oldY - ONE_SUB_PIXEL;
        }

        return SPOSE_NONE;
    }

    if (sSamusCollisionOffsets[collisionType][SAMUS_HITBOX_RIGHT] >= HALF_BLOCK_SIZE)
    {
        xPosition = gSamusData.xPosition;
        result = SamusCheckCollisionAtPosition(xPosition, yPosition, &nextX, &nextY, &var_0);

        if (var_0 != 0)
        {
            gSamusData.slopeType = result;
            if (var_0 != 0x10)
                gSamusData.yPosition = nextY - ONE_SUB_PIXEL;

            return SPOSE_NONE;
        }
    }

    if (gSamusData.standingStatus != STANDING_ENEMY)
        return SPOSE_MID_AIR_REQUEST;

    return SPOSE_NONE;
}

/**
 * @brief afa8 | 27c | Checks for bottom collision when mid-air
 * 
 * @return u8 New pose
 */
u8 SamusCheckLandingCollision(void)
{
    s16 unk_6;
    u8 collisionType;
    u8 unk_5;
    u8 unk_4;
    u32 result;
    u16 xPosition;
    u16 yPosition;
    u16 nextX;
    u16 nextY;
    u16 var_0;

    collisionType = gSamusCollisionData.collisionType;
    unk_4 = gSamusCollisionData.unk_4;
    unk_5 = gSamusCollisionData.unk_5;
    unk_6 = gSamusCollisionData.unk_6;

    if (gSamusCollisionData.horizontalMovingDirection != 0)
    {
        result = unk_a670(collisionType, &nextX, -(QUARTER_BLOCK_SIZE + PIXEL_SIZE + PIXEL_SIZE / 2));

        if (result != SCD_NONE)
        {
            gSamusData.xPosition = nextX;
            gSamusData.xVelocity = 0;
            gSamusCollisionData.touchingSideBlock = result;
        }
    }

    if (gSamusData.standingStatus == STANDING_ENEMY)
        return SPOSE_NONE;

    xPosition = gSamusData.xPosition + sSamusCollisionOffsets[collisionType][unk_4];
    yPosition = gSamusData.yPosition;

    result = SamusCheckCollisionAtPosition(xPosition, yPosition, &nextX, &nextY, &var_0);

    if (var_0 != 0)
    {
        if (result != SLOPE_NONE)
        {
            gSamusData.slopeType = result;
            gSamusData.yPosition = nextY;

            xPosition = gSamusData.xPosition + sSamusCollisionOffsets[collisionType][unk_5];
            yPosition = gSamusData.yPosition;

            result = SamusCheckCollisionAtPosition(xPosition, yPosition, &nextX, &nextY, &var_0);

            if (var_0 != 0 && result == SLOPE_NONE)
            {
                gSamusData.slopeType = result;
                gSamusData.yPosition = nextY - ONE_SUB_PIXEL;
            }

            return SPOSE_LANDING_REQUEST;
        }

        if (gPreviousYPosition < nextY)
        {
            yPosition = gPreviousYPosition;
            result = SamusCheckCollisionAtPosition(xPosition, yPosition, &nextX, &nextY, &var_0);
            gSamusData.slopeType = result;

            if (result != SLOPE_NONE)
                gSamusData.yPosition = nextY;
            else
                gSamusData.yPosition = nextY + BLOCK_SIZE - ONE_SUB_PIXEL;

            return SPOSE_LANDING_REQUEST;
        }
        
        if (var_0 != 0x10)
        {
            gSamusData.xPosition = unk_6 + (nextX - sSamusCollisionOffsets[collisionType][unk_4]);

            xPosition = gSamusData.xPosition;
            result = SamusCheckCollisionAtPosition(xPosition, yPosition, &nextX, &nextY, &var_0);
            gSamusData.slopeType = result;

            if (result != SLOPE_NONE)
            {
                gSamusData.yPosition = nextY;
                return SPOSE_LANDING_REQUEST;
            }

            if (var_0 != 0)
            {
                gSamusData.yPosition = nextY - ONE_SUB_PIXEL;
                return SPOSE_LANDING_REQUEST;
            }

            gSamusData.xVelocity = 0;
            return SPOSE_NONE;
        }
    }

    xPosition = gSamusData.xPosition + sSamusCollisionOffsets[collisionType][unk_5];
    yPosition = gSamusData.yPosition;
    result = SamusCheckCollisionAtPosition(xPosition, yPosition, &nextX, &nextY, &var_0);

    if (var_0 != 0)
    {
        if (result != SLOPE_NONE)
        {
            gSamusData.slopeType = result;
            gSamusData.yPosition = nextY;
            return SPOSE_LANDING_REQUEST;
        }

        if (gPreviousYPosition < nextY)
        {
            yPosition = gPreviousYPosition;
            result = SamusCheckCollisionAtPosition(xPosition, yPosition, &nextX, &nextY, &var_0);
            gSamusData.slopeType = result;

            if (result != SLOPE_NONE)
                gSamusData.yPosition = nextY;
            else
                gSamusData.yPosition = nextY + BLOCK_SIZE - ONE_SUB_PIXEL;

            return SPOSE_LANDING_REQUEST;
        }
    }
    else
    {
        if (sSamusCollisionOffsets[collisionType][SAMUS_HITBOX_RIGHT] >= HALF_BLOCK_SIZE)
        {
            xPosition = gSamusData.xPosition;
            result = SamusCheckCollisionAtPosition(xPosition, yPosition, &nextX, &nextY, &var_0);

            if (var_0 != 0 && gPreviousYPosition < nextY)
            {
                gSamusData.slopeType = result;
                gSamusData.yPosition = nextY - ONE_SUB_PIXEL;
                return SPOSE_LANDING_REQUEST;
            }
        }
    }

    return SPOSE_NONE;
}

/**
 * @brief b224 | 1a4 | Checks for top collision when mid-air
 * 
 * @return u8 New pose
 */
u8 SamusCheckJumpingCollision(void)
{
    u8 collisionType;
    u8 unk_5;
    u8 unk_4;
    u8 unk_A;
    u32 result;
    u16 xPosition;
    u16 yPosition;
    u16 nextX;
    u16 nextY;
    u16 var_0;
    u16 otherX;

    collisionType = gSamusCollisionData.collisionType;
    unk_A = gSamusCollisionData.unk_A;
    unk_4 = gSamusCollisionData.unk_4;

    if (gUnk_3004d8c == 0)
    {
        result = SamusCheckCollisionAbove(unk_A, sSamusCollisionOffsets[collisionType][SAMUS_HITBOX_TOP], FALSE);

        if (result != SCD_NONE)
        {
            if (result == SCD_TOP_LEFT_MOST)
            {
                xPosition = gSamusData.xPosition + sSamusCollisionOffsets[collisionType][SAMUS_HITBOX_LEFT];
                gSamusData.xPosition = (xPosition & BLOCK_POSITION_FLAG) - sSamusCollisionOffsets[collisionType][SAMUS_HITBOX_LEFT] + BLOCK_SIZE;
            }
            else if (result == SCD_TOP_RIGHT_MOST)
            {
                xPosition = gSamusData.xPosition + sSamusCollisionOffsets[collisionType][SAMUS_HITBOX_RIGHT];
                gSamusData.xPosition = (xPosition & BLOCK_POSITION_FLAG) - sSamusCollisionOffsets[collisionType][SAMUS_HITBOX_RIGHT] - ONE_SUB_PIXEL;
            }
            else if (result & (SCD_TOP_LEFT_MIDDLE | SCD_TOP_RIGHT_MIDDLE))
            {
                yPosition = gSamusData.yPosition + sSamusCollisionOffsets[collisionType][SAMUS_HITBOX_TOP];
                gSamusData.yPosition = (yPosition & BLOCK_POSITION_FLAG) - sSamusCollisionOffsets[collisionType][SAMUS_HITBOX_TOP] + BLOCK_SIZE;

                gSamusCollisionData.touchingTopBlock++;
            }
        }
    }

    if (gSamusCollisionData.horizontalMovingDirection != 0)
    {
        xPosition = gSamusData.xPosition + sSamusCollisionOffsets[collisionType][unk_4];
        yPosition = gSamusData.yPosition;
        result = SamusCheckCollisionAtPosition(xPosition, yPosition, &nextX, &nextY, &var_0);

        if (var_0 != 0)
        {
            if (result != SLOPE_NONE)
            {
                gSamusData.slopeType = result;
                gSamusData.yPosition = nextY;
                return SPOSE_LANDING_REQUEST;
            }

            otherX = (nextX - sSamusCollisionOffsets[collisionType][unk_4]) + gSamusCollisionData.unk_6;
            xPosition = gSamusData.xPosition;
            result = SamusCheckCollisionAtPosition(xPosition, yPosition, &nextX, &nextY, &var_0);
            if (result != SLOPE_NONE)
            {
                gSamusData.slopeType = result;
                gSamusData.xPosition = otherX;
                gSamusData.yPosition = nextY;
                return SPOSE_LANDING_REQUEST;
            }
        }

        result = unk_a670(collisionType, &nextX, 0);
        if (result != SCD_NONE)
        {
            gSamusData.xPosition = nextX;
            gSamusData.xVelocity = 0;
            gSamusCollisionData.touchingSideBlock++;
        }
    }

    if (gSamusCollisionData.touchingTopBlock)
        gSamusData.yVelocity = 0;

    return SPOSE_NONE;
}

/**
 * @brief b3c8 | b0 | To document
 * 
 * @return u8 New pose
 */
u8 unk_b3c8(void)
{
    u32 result;
    u16 xPosition;
    u16 previousX;
    u16 yPosition;
    u16 nextX;
    u16 nextY;
    u16 var_0;

    if ((gSamusData.xPosition & BLOCK_POSITION_FLAG) != (gPreviousXPosition & BLOCK_POSITION_FLAG))
        return SPOSE_NONE;

    if (gSamusData.slopeType != SLOPE_NONE)
        return SPOSE_NONE;

    if (gSamusData.standingStatus != STANDING_GROUND)
        return SPOSE_NONE;

    xPosition = gSamusData.xPosition;
    previousX = gSamusData.yPosition + ONE_SUB_PIXEL;

    result = SamusCheckCollisionAtPosition(xPosition, previousX, &nextX, &nextY, &var_0);

    if (result == SLOPE_NONE && var_0 == 0)
    {
        xPosition = gSamusData.xPosition & SUB_PIXEL_POSITION_FLAG;
        previousX = gPreviousXPosition & SUB_PIXEL_POSITION_FLAG;
        if (gSamusCollisionData.horizontalMovingDirection & KEY_RIGHT)
        {
            if (xPosition >= SUB_PIXEL_POSITION_FLAG / 2 - ONE_SUB_PIXEL && previousX < SUB_PIXEL_POSITION_FLAG / 2)
            {
                gSamusData.xPosition = (gSamusData.xPosition & BLOCK_POSITION_FLAG) + SUB_PIXEL_POSITION_FLAG / 2 - ONE_SUB_PIXEL;
                return SPOSE_MID_AIR_REQUEST;
            }
        }
        else if (gSamusCollisionData.horizontalMovingDirection & KEY_LEFT)
        {
            if (xPosition <= SUB_PIXEL_POSITION_FLAG / 2 + ONE_SUB_PIXEL * 2 && previousX > SUB_PIXEL_POSITION_FLAG / 2 + ONE_SUB_PIXEL)
            {
                gSamusData.xPosition = (gSamusData.xPosition & BLOCK_POSITION_FLAG) + HALF_BLOCK_SIZE + ONE_SUB_PIXEL;
                return SPOSE_MID_AIR_REQUEST;
            }
        }
    }

    return SPOSE_NONE;
}

/**
 * @brief b478 | cbc | Updates Samus's graphics, including graphics/OAM pointers, graphics/palette lengths, and palette data
 * 
 * @param direction Direction (0 = right, 1 = left)
 */
void SamusUpdateGraphics(u8 direction)
{
    s32 ppc;
    u8 pose;
    u8 acd;
    const struct SamusAnimData* pAnim;
    const struct ArmCannonAnimData* pArmCannonAnim;
    const u8* pGraphics;
    const struct FrameData* pFrameData;
    const u16* pOam;
    const u16* pPalette;
    s32 row;

    if (gSamusData.pose != SPOSE_GETTING_HURT && gSamusData.invincibilityTimer != 0)
        gSamusData.invincibilityTimer--;

    if (gSamusEnvironmentalEffects[0].externalTimer != 0)
        gSamusEnvironmentalEffects[0].externalTimer--;

    if (gSamusData.speedboostingCounter != 0)
    {
        gSamusEcho.active = TRUE;
        gSamusEcho.timer = 16;
    }
    else if (gSamusEcho.timer != 0)
    {
        gSamusEcho.timer--;
    }
    else
    {
        gSamusEcho.active = FALSE;
    }

    ppc = gPreviousPositionCounter & (ARRAY_SIZE(gPrevious64Positions[0]) - 1);
    gPrevious64Positions[0][ppc] = gPreviousXPosition;
    gPrevious64Positions[1][ppc] = gPreviousYPosition;
 
    if (gPreviousPositionCounter++ > 0x100)
        gPreviousPositionCounter -= 0x80;

    if (gPreviousPositionCounter >= ARRAY_SIZE(gPrevious64Positions[0]))
        *(u8 *)0x0300144E = TRUE;

    pose = gSamusData.pose;
    acd = gSamusData.armCannonDirection;

    switch (pose)
    {
        case SPOSE_STANDING:
            pAnim = sSamusAnimPointers_Standing[acd][direction];
            pArmCannonAnim = sArmCannonAnimPointers_Standing[acd][direction];
            break;
        
        case SPOSE_TURNING_AROUND:
            pAnim = sSamusAnimPointers_Turning[acd][direction];
            pArmCannonAnim = sArmCannonAnimPointers_Turning[acd][direction];
            break;
        
        case SPOSE_SHOOTING:
            pAnim = sSamusAnimPointers_Shooting[acd][direction];
            pArmCannonAnim = sArmCannonAnimPointers_Shooting[acd][direction];
            break;
        
        case SPOSE_RUNNING:
            pAnim = sSamusAnimPointers_Running[acd][direction];
            pArmCannonAnim = sArmCannonAnimPointers_Running[acd][direction];
            break;
        
        case SPOSE_MID_AIR:
            pAnim = sSamusAnimPointers_MidAir[acd][direction];
            pArmCannonAnim = sArmCannonAnimPointers_MidAir[acd][direction];
            break;
        
        case SPOSE_TURNING_AROUND_MID_AIR:
            pAnim = sSamusAnimPointers_TurningMidAir[acd][direction];
            pArmCannonAnim = sArmCannonAnimPointers_TurningMidAir[acd][direction];
            break;
        
        case SPOSE_LANDING:
            pAnim = sSamusAnimPointers_Landing[acd][direction];
            pArmCannonAnim = sArmCannonAnimPointers_Landing[acd][direction];
            break;
        
        case SPOSE_CROUCHING:
            pAnim = sSamusAnimPointers_ShootingAndCrouching[acd][direction];
            pArmCannonAnim = sArmCannonAnimPointers_ShootingAndCrouching[acd][direction];
            break;
        
        case SPOSE_TURNING_AROUND_AND_CROUCHING:
            pAnim = sSamusAnimPointers_TurningAndCrouching[acd][direction];
            pArmCannonAnim = sArmCannonAnimPointers_TurningAndCrouching[acd][direction];
            break;
        
        case SPOSE_SHOOTING_AND_CROUCHING:
            pAnim = sSamusAnimPointers_ShootingAndCrouching[acd][direction];
            pArmCannonAnim = sArmCannonAnimPointers_ShootingAndCrouching[acd][direction];
            break;
        
        case SPOSE_HANGING_ON_LEDGE:
            if (gButtonInput & (gSamusData.direction ^ (KEY_RIGHT | KEY_LEFT)))
                acd++;
            pAnim = sSamusAnimPointers_HangingOnLedge[acd][direction];
            pArmCannonAnim = sArmCannonAnimPointers_HangingOnLedge[acd][direction];
            break;
        
        case SPOSE_SKIDDING:
            if (gSamusData.weaponHighlighted == 1)
                acd++;
            pAnim = sSamusAnimPointers_Skidding[acd][direction];
            pArmCannonAnim = sArmCannonAnimPointers_Default[pose][direction];
            break;
        
        case SPOSE_SHINESPARKING:
            acd = gSamusData.forcedMovement;
            pAnim = sSamusAnimPointers_Shinesparking[acd][direction];
            pArmCannonAnim = sArmCannonAnimPointers_Shinesparking[acd][direction];
            break;
        
        case SPOSE_DELAY_AFTER_SHINESPARKING:
            acd = gSamusData.forcedMovement;
            pAnim = sSamusAnimPointers_DelayAfterShinesparking[acd][direction];
            pArmCannonAnim = sArmCannonAnimPointers_DelayAfterShinesparking[acd][direction];
            break;
        
        case SPOSE_HOLDING_ARM_OUT_ON_VERTICAL_LADDER:
            pAnim = sSamusAnimPointers_ArmOutOnVerticalLadder[acd][direction];
            pArmCannonAnim = sArmCannonAnimPointers_OnVerticalLadder[acd][direction];
            break;
        
        case SPOSE_SHOOTING_ON_VERTICAL_LADDER:
            pAnim = sSamusAnimPointers_ShootingOnVerticalLadder[acd][direction];
            pArmCannonAnim = sArmCannonAnimPointers_ShootingOnVerticalLadder[acd][direction];
            break;
        
        case SPOSE_DELAY_AFTER_SHOOTING_ON_HORIZONTAL_LADDER:
            pAnim = sSamusAnimPointers_AfterShootingOnHorizontalLadder[acd][direction];
            pArmCannonAnim = sArmCannonAnimPointers_AfterShootingOnHorizontalLadder[acd][direction];
            break;
        
        case SPOSE_SHOOTING_ON_HORIZONTAL_LADDER:
            pAnim = sSamusAnimPointers_ShootingOnHorizontalLadder[acd][direction];
            pArmCannonAnim = sArmCannonAnimPointers_ShootingOnHorizontalLadder[acd][direction];
            break;
        
        case SPOSE_HIT_BY_OMEGA_METROID:
            acd = gButtonInput & (KEY_RIGHT | KEY_LEFT | KEY_UP) ? 1 : 0;
            pAnim = sSamusAnimPointers_HitByOmegaMetroid[acd][direction];
            pArmCannonAnim = sArmCannonAnimPointers_Default[pose][direction];
            break;
        
        default:
            pAnim = sSamusAnimPointers_Default[pose][direction];
            pArmCannonAnim = sArmCannonAnimPointers_Default[pose][direction];
            break;
    }

    pAnim = &pAnim[gSamusData.currentAnimationFrame];
    gSamusGraphicsInfo.pSamusOamFrame = pAnim->pOam;
    
    pGraphics = pAnim->pTopGfx;
    gSamusGraphicsInfo.bodyTopHalfGfxLength = *pGraphics++ * SAMUS_GFX_PART_SIZE;
    gSamusGraphicsInfo.bodyBottomHalfGfxLength = *pGraphics++ * SAMUS_GFX_PART_SIZE;
    gSamusGraphicsInfo.pBodyTopHalfGfx = pGraphics;
    gSamusGraphicsInfo.pBodyBottomHalfGfx = &pGraphics[gSamusGraphicsInfo.bodyTopHalfGfxLength];

    pGraphics = pAnim->pBottomGfx;
    gSamusGraphicsInfo.legsTopHalfGfxLength = *pGraphics++ * SAMUS_GFX_PART_SIZE;
    gSamusGraphicsInfo.legsBottomHalfGfxLength = *pGraphics++ * SAMUS_GFX_PART_SIZE;
    gSamusGraphicsInfo.pLegsTopHalfGfx = pGraphics;
    gSamusGraphicsInfo.pLegsBottomHalfGfx = &pGraphics[gSamusGraphicsInfo.legsTopHalfGfxLength];
    
    gSamusGraphicsInfo.unk_26 = 0;
    gSamusGraphicsInfo.armCannonTopHalfGfxLength = 0;
    gSamusGraphicsInfo.armCannonBottomHalfGfxLength = 0;
    
    switch (pose)
    {
        case SPOSE_USING_ELEVATOR:
            pFrameData = &sArmCannonOam_UsingElevator[gSamusAnimationInfo.currentPaletteRow];
            gSamusGraphicsInfo.pArmCannonOamFrame = pFrameData->pFrame;
            gSamusGraphicsInfo.unk_26 = 0x2000;
            gSamusGraphicsInfo.pArmCannonTopHalfGfx = sArmCannonGfx_Elevator_Top;
            gSamusGraphicsInfo.pArmCannonBottomHalfGfx = sArmCannonGfx_Elevator_Bottom;
            gSamusGraphicsInfo.armCannonTopHalfGfxLength = 0xC0;
            gSamusGraphicsInfo.armCannonBottomHalfGfxLength = 0xC0;
            break;
        
        case SPOSE_SCREW_ATTACKING:
            pFrameData = &sArmCannonOamPointers_ScrewAttacking[direction][gSamusAnimationInfo.currentPaletteRow];
            gSamusGraphicsInfo.pArmCannonOamFrame = pFrameData->pFrame;
            gSamusGraphicsInfo.unk_26 = 0x1000;
            gSamusGraphicsInfo.pArmCannonTopHalfGfx = sArmCannonGfxPointers_ScrewAttacking_Top[gSamusAnimationInfo.currentPaletteRow];
            gSamusGraphicsInfo.pArmCannonBottomHalfGfx = sArmCannonGfxPointers_ScrewAttacking_Bottom[gSamusAnimationInfo.currentPaletteRow];
            gSamusGraphicsInfo.armCannonTopHalfGfxLength = 0x100;
            gSamusGraphicsInfo.armCannonBottomHalfGfxLength = 0x100;
            break;
        
        case SPOSE_UNLOCKING_SECURITY:
            pFrameData = &sArmCannonOamPointers_UnlockingSecurity[direction][gSamusAnimationInfo.currentPaletteRow];
            gSamusGraphicsInfo.pArmCannonOamFrame = pFrameData->pFrame;
            gSamusGraphicsInfo.unk_26 = 0x2000;
            gSamusGraphicsInfo.pArmCannonTopHalfGfx = sArmCannonGfx_UnlockingSecurity_Top;
            gSamusGraphicsInfo.pArmCannonBottomHalfGfx = sArmCannonGfx_UnlockingSecurity_Bottom;
            gSamusGraphicsInfo.armCannonTopHalfGfxLength = 0x200;
            gSamusGraphicsInfo.armCannonBottomHalfGfxLength = 0x200;
            break;
        
        case SPOSE_LOADING_SAVE:
            if (gSamusAnimationInfo.loadingSave == 1)
            {
                pFrameData = &sArmCannonOam_LoadingSave[gSamusAnimationInfo.currentPaletteRow];
                gSamusGraphicsInfo.pArmCannonOamFrame = pFrameData->pFrame;
                gSamusGraphicsInfo.unk_26 = 0x1000;
                gSamusGraphicsInfo.pArmCannonTopHalfGfx = sArmCannonGfxPointers_LoadingSave_Top[gSamusAnimationInfo.currentPaletteRow];
                gSamusGraphicsInfo.pArmCannonBottomHalfGfx = sArmCannonGfxPointers_LoadingSave_Bottom[gSamusAnimationInfo.currentPaletteRow];
                gSamusGraphicsInfo.armCannonTopHalfGfxLength = 0x180;
                gSamusGraphicsInfo.armCannonBottomHalfGfxLength = 0x100;
            }
            break;
        
        case SPOSE_DYING:
            if (gSamusAnimationInfo.loadingSave == 0)
            {
                DMA3_COPY_16(sArmCannonGfx_Dying_HairTop0, 0x06010900, 0x30);
                DMA3_COPY_16(sArmCannonGfx_Dying_HairTop1, 0x06010D00, 0x20);
            }
            else if (gSamusAnimationInfo.loadingSave == 2)
            {
                pFrameData = &sArmCannonOamPointers_Dying[direction][gSamusAnimationInfo.currentPaletteRow];
                gSamusGraphicsInfo.pArmCannonOamFrame = pFrameData->pFrame;
                gSamusGraphicsInfo.unk_26 = 0x2000;
                gSamusGraphicsInfo.pArmCannonTopHalfGfx = sArmCannonGfxPointers_Dying_Top[gSamusAnimationInfo.currentPaletteRow];
                gSamusGraphicsInfo.pArmCannonBottomHalfGfx = sArmCannonGfxPointers_Dying_Bottom[gSamusAnimationInfo.currentPaletteRow];
                gSamusGraphicsInfo.armCannonTopHalfGfxLength = 0x100;
                gSamusGraphicsInfo.armCannonBottomHalfGfxLength = 0x100;
            }
            else if (gSamusAnimationInfo.loadingSave == 3)
            {
                gSamusGraphicsInfo.unk_26 = 0x2000;
            }
            break;
        
        case SPOSE_HOLDING_ARM_OUT_ON_VERTICAL_LADDER:
        case SPOSE_SHOOTING_ON_VERTICAL_LADDER:
            pArmCannonAnim = &pArmCannonAnim[gSamusData.currentAnimationFrame];
            pOam = pArmCannonAnim->pOam;
            gSamusGraphicsInfo.pArmCannonOamFrame = pOam;
            gSamusGraphicsInfo.unk_26 = pOam[0];

            if (gSamusData.weaponHighlighted & 1)
            {
                if (gSamusData.direction & KEY_RIGHT)
                {
                    gSamusGraphicsInfo.pArmCannonTopHalfGfx = sArmCannonGfxPointers_Default_Armed_Right_Top[acd];
                    gSamusGraphicsInfo.pArmCannonBottomHalfGfx = sArmCannonGfxPointers_Default_Armed_Right_Bottom[acd];
                }
                else
                {
                    gSamusGraphicsInfo.pArmCannonTopHalfGfx = sArmCannonGfxPointers_Default_Armed_Left_Top[acd];
                    gSamusGraphicsInfo.pArmCannonBottomHalfGfx = sArmCannonGfxPointers_Default_Armed_Left_Bottom[acd];
                }
            }
            else if (gSamusData.direction & KEY_RIGHT)
            {
                gSamusGraphicsInfo.pArmCannonTopHalfGfx = sArmCannonGfxPointers_OnVerticalLadder_Right_Top[acd];
                gSamusGraphicsInfo.pArmCannonBottomHalfGfx = sArmCannonGfxPointers_OnVerticalLadder_Right_Bottom[acd];
            }
            else
            {
                gSamusGraphicsInfo.pArmCannonTopHalfGfx = sArmCannonGfxPointers_OnVerticalLadder_Left_Top[acd];
                gSamusGraphicsInfo.pArmCannonBottomHalfGfx = sArmCannonGfxPointers_OnVerticalLadder_Left_Bottom[acd];
            }

            gSamusGraphicsInfo.armCannonTopHalfGfxLength = 0xC0;
            gSamusGraphicsInfo.armCannonBottomHalfGfxLength = 0xC0;
            break;

        case SPOSE_HANGING_ON_HORIZONTAL_LADDER:
        case SPOSE_DELAY_AFTER_SHOOTING_ON_HORIZONTAL_LADDER:
        case SPOSE_SHOOTING_ON_HORIZONTAL_LADDER:
            pArmCannonAnim = &pArmCannonAnim[gSamusData.currentAnimationFrame];
            pOam = pArmCannonAnim->pOam;
            gSamusGraphicsInfo.pArmCannonOamFrame = pOam;
            gSamusGraphicsInfo.unk_26 = pOam[0];

            if (gSamusData.weaponHighlighted & 1)
            {
                if (gSamusData.direction & KEY_RIGHT)
                {
                    gSamusGraphicsInfo.pArmCannonTopHalfGfx = sArmCannonGfxPointers_Default_Armed_Right_Top[acd];
                    gSamusGraphicsInfo.pArmCannonBottomHalfGfx = sArmCannonGfxPointers_Default_Armed_Right_Bottom[acd];
                }
                else
                {
                    gSamusGraphicsInfo.pArmCannonTopHalfGfx = sArmCannonGfxPointers_Default_Armed_Left_Top[acd];
                    gSamusGraphicsInfo.pArmCannonBottomHalfGfx = sArmCannonGfxPointers_Default_Armed_Left_Bottom[acd];
                }
            }
            else if (gSamusData.direction & KEY_RIGHT)
            {
                gSamusGraphicsInfo.pArmCannonTopHalfGfx = sArmCannonGfxPointers_OnHorizontalLadder_Right_Top[acd];
                gSamusGraphicsInfo.pArmCannonBottomHalfGfx = sArmCannonGfxPointers_OnHorizontalLadder_Right_Bottom[acd];
            }
            else
            {
                gSamusGraphicsInfo.pArmCannonTopHalfGfx = sArmCannonGfxPointers_OnHorizontalLadder_Left_Top[acd];
                gSamusGraphicsInfo.pArmCannonBottomHalfGfx = sArmCannonGfxPointers_OnHorizontalLadder_Left_Bottom[acd];
            }

            gSamusGraphicsInfo.armCannonTopHalfGfxLength = 0xC0;
            gSamusGraphicsInfo.armCannonBottomHalfGfxLength = 0xC0;
            break;

        case SPOSE_GRABBED_BY_YAKUZA:
            acd = ACD_DOWN;
        default:
            pArmCannonAnim = &pArmCannonAnim[gSamusData.currentAnimationFrame];
            pOam = pArmCannonAnim->pOam;
            gSamusGraphicsInfo.pArmCannonOamFrame = pOam;
            gSamusGraphicsInfo.unk_26 = pOam[0];
            
            if (gSamusData.weaponHighlighted & 1)
            {
                if (gSamusData.direction & KEY_RIGHT)
                {
                    gSamusGraphicsInfo.pArmCannonTopHalfGfx = sArmCannonGfxPointers_Default_Armed_Right_Top[acd];
                    gSamusGraphicsInfo.pArmCannonBottomHalfGfx = sArmCannonGfxPointers_Default_Armed_Right_Bottom[acd];
                }
                else
                {
                    gSamusGraphicsInfo.pArmCannonTopHalfGfx = sArmCannonGfxPointers_Default_Armed_Left_Top[acd];
                    gSamusGraphicsInfo.pArmCannonBottomHalfGfx = sArmCannonGfxPointers_Default_Armed_Left_Bottom[acd];
                }
            }
            else if (gSamusData.direction & KEY_RIGHT)
            {
                gSamusGraphicsInfo.pArmCannonTopHalfGfx = sArmCannonGfxPointers_Default_Right_Top[acd];
                gSamusGraphicsInfo.pArmCannonBottomHalfGfx = sArmCannonGfxPointers_Default_Right_Bottom[acd];
            }
            else
            {
                gSamusGraphicsInfo.pArmCannonTopHalfGfx = sArmCannonGfxPointers_Default_Left_Top[acd];
                gSamusGraphicsInfo.pArmCannonBottomHalfGfx = sArmCannonGfxPointers_Default_Left_Bottom[acd];
            }

            gSamusGraphicsInfo.armCannonTopHalfGfxLength = 0xC0;
            gSamusGraphicsInfo.armCannonBottomHalfGfxLength = 0xC0;
            break;
    }

    // Update palette

    // Check if dying
    if (pose == SPOSE_DYING)
    {
        gSamusPaletteLength = 2 * PAL_ROW_SIZE;
        pPalette = sSamusPal_Dying_Row0;
        SET_SAMUS_PAL_ROW_0(pPalette);
        pPalette = sSamusPal_DyingFade_Row1;

        if (gSamusAnimationInfo.currentPaletteRow > 4)
        {
            if (gSamusData.counter < CONVERT_SECONDS(1 + (1.0f / 3)))
            {
                gSamusData.counter++;
            }
            else
            {
                gMainGameMode = 8;
                gSubGameMode1 = 0;
            }

            if (gSamusData.counter < CONVERT_SECONDS(1.0f))
                row = DIV_SHIFT(gSamusData.counter, 4);
            else
                row = 15;
            
            pPalette += (row * PAL_ROW);
        }
        
        SET_SAMUS_PAL_ROW_1(pPalette);
        return;
    }

    // Check if flashing from invincibility
    if (gSamusData.invincibilityTimer != 0 && (gFrameCounter8Bit & 3) <= 1)
    {
        gSamusPaletteLength = 2 * PAL_ROW_SIZE;
        pPalette = sSamusPal_Flashing_BothRows;
        SET_SAMUS_PAL_ROW_0(pPalette);
        SET_SAMUS_PAL_ROW_1(pPalette);
        return;
    }

    // Check if absorbing an X
    if (gSamusEnvironmentalEffects[0].externalTimer != 0)
    {
        gSamusPaletteLength = 2 * PAL_ROW_SIZE;
        row = DIV_SHIFT(48 - gSamusEnvironmentalEffects[0].externalTimer, 2);
        pPalette = sSamusPal_AbsorbX_BothRows + (row * PAL_ROW);
        SET_SAMUS_PAL_ROW_0(pPalette);
        SET_SAMUS_PAL_ROW_1(pPalette);
        return;
    }

    // TODO: What is this checking?
    if (gSamusEnvironmentalEffects[1].timer1 >= 1 && gSamusEnvironmentalEffects[1].timer1 <= 4)
    {
        gSamusPaletteLength = 2 * PAL_ROW_SIZE;
        pPalette = sSamusPal_Flashing_BothRows;
        SET_SAMUS_PAL_ROW_0(pPalette);
        SET_SAMUS_PAL_ROW_1(pPalette);
    }
    else
    {
        switch (pose)
        {
            case SPOSE_FROZEN:
            case SPOSE_FROZEN_AND_FALLING:
            case SPOSE_FROZEN_IN_MORPH_BALL:
            case SPOSE_FROZEN_IN_MORPH_BALL_AND_FALLING:
                gSamusPaletteLength = 2 * PAL_ROW_SIZE;
                pPalette = sSamusPal_Frozen_Row0;
                SET_SAMUS_PAL_ROWS_0_1(pPalette);
                break;
    
            case SPOSE_SCREW_ATTACKING:
                gSamusPaletteLength = 2 * PAL_ROW_SIZE;
                if (gSamusData.currentAnimationFrame <= 4)
                {
                    if (gEquipment.suitMiscStatus & SMF_SA_X_SUIT)
                        pPalette = sSamusPal_Default_Row0_SaX;
                    else if (gEquipment.suitMiscStatus & SMF_GRAVITY_SUIT)
                        pPalette = sSamusPal_Default_Row0_Gravity;
                    else if (gEquipment.suitMiscStatus & SMF_VARIA_SUIT)
#ifdef BUGFIX
                        pPalette = sSamusPal_Default_Row0_Varia;
#else // !BUFIX
                        pPalette = sSamusPal_Default_Row0_Fusion + PAL_ROW;
#endif // BUGFIX
                    else
                        pPalette = sSamusPal_Default_Row0_Fusion;
                }
                else if (gSamusData.currentAnimationFrame <= 7)
                {
                    pPalette = sSamusPal_ScrewAttacking_Row0;
                }
                else if (gSamusData.currentAnimationFrame <= 12)
                {
                    pPalette = sSamusPal_ScrewAttacking_Row0 + PAL_ROW;
                }
                else
                {
                    pPalette = sSamusPal_ScrewAttacking_Row0;
                }

                SET_SAMUS_PAL_ROW_0(pPalette);
                pPalette = sSamusPal_ScrewAttacking_Row1;
                SET_SAMUS_PAL_ROW_1(pPalette);
                break;
    
            case SPOSE_SAVING:
                gSamusPaletteLength = PAL_ROW_SIZE;
                row = (gSamusData.currentAnimationFrame / 2) & 3;
                if (gEquipment.suitMiscStatus & SMF_SA_X_SUIT)
                    pPalette = sSamusPal_SavingGame_Row0_SaX + row * PAL_ROW;
                else if (gEquipment.suitMiscStatus & SMF_GRAVITY_SUIT)
                    pPalette = sSamusPal_SavingGame_Row0_Gravity + row * PAL_ROW;
                else if (gEquipment.suitMiscStatus & SMF_VARIA_SUIT)
                    pPalette = sSamusPal_SavingGame_Row0_Varia + row * PAL_ROW;
                else
                    pPalette = sSamusPal_SavingGame_Row0_Fusion + row * PAL_ROW;
                
                SET_SAMUS_PAL_ROW_0(pPalette);
                break;
    
            case SPOSE_LOADING_SAVE:
                gSamusPaletteLength = 2 * PAL_ROW_SIZE;
                if (gEquipment.suitMiscStatus & SMF_SA_X_SUIT)
                    pPalette = sSamusPalPointers_LoadingSave_Row0_SaX[gSamusData.currentAnimationFrame];
                else if (gEquipment.suitMiscStatus & SMF_GRAVITY_SUIT)
                    pPalette = sSamusPalPointers_LoadingSave_Row0_Gravity[gSamusData.currentAnimationFrame];
                else if (gEquipment.suitMiscStatus & SMF_VARIA_SUIT)
                    pPalette = sSamusPalPointers_LoadingSave_Row0_Varia[gSamusData.currentAnimationFrame];
                else
                    pPalette = sSamusPalPointers_LoadingSave_Row0_Fusion[gSamusData.currentAnimationFrame];

                SET_SAMUS_PAL_ROW_0(pPalette);
                pPalette = sSamusPal_LoadingSave_Row0_Varia_20;
                SET_SAMUS_PAL_ROW_1(pPalette);
                break;

            default:
                gSamusPaletteLength = 2 * PAL_ROW_SIZE;

                if (gSamusData.speedboostingCounter != 0 || gSamusAnimationInfo.shinesparkTimer != 0)
                {
                    if (gFrameCounter8Bit & 8)
                        pPalette = sSamusPal_Speedboost0_BothRows;
                    else
                        pPalette = sSamusPal_Speedboost1_BothRows;

                    SET_SAMUS_PAL_ROW_0(pPalette);
                    SET_SAMUS_PAL_ROW_1(pPalette);
                    break;
                }

                if (gSamusData.chargeBeamCounter >= CHARGE_BEAM_THRESHOLD)
                {
                    if (gEquipment.suitMiscStatus & SMF_SA_X_SUIT)
                        row = 3 * 4;
                    else if (gEquipment.suitMiscStatus & SMF_GRAVITY_SUIT)
                        row = 2 * 4;
                    else if (gEquipment.suitMiscStatus & SMF_VARIA_SUIT)
                        row = 1 * 4;
                    else
                        row = 0 * 4;

                    row += DIV_SHIFT(gSamusData.chargeBeamCounter - CHARGE_BEAM_THRESHOLD, 4);

                    if (gEquipment.beamStatus & BF_ICE_BEAM)
                        pPalette = sSamusPal_ChargingIceBeam_BothRows + (row * PAL_ROW);
                    else if (gEquipment.beamStatus & BF_WAVE_BEAM)
                        pPalette = sSamusPal_ChargingWaveBeam_BothRows + (row * PAL_ROW);
                    else if (gEquipment.beamStatus & BF_PLASMA_BEAM)
                        pPalette = sSamusPal_ChargingPlasmaBeam_BothRows + (row * PAL_ROW);
                    else if (gEquipment.beamStatus & BF_WIDE_BEAM)
                        pPalette = sSamusPal_ChargingWideBeam_BothRows + (row * PAL_ROW);
                    else if (gEquipment.beamStatus & BF_CHARGE_BEAM)
                        pPalette = sSamusPal_ChargingChargeBeam_BothRows + (row * PAL_ROW);
                    else
                        pPalette = sSamusPal_ChargingNormalBeam_BothRows + (row * PAL_ROW);

                    SET_SAMUS_PAL_ROW_0(pPalette);
                    SET_SAMUS_PAL_ROW_1(pPalette);
                    break;
                }
                
                if (gEquipment.suitMiscStatus & SMF_SA_X_SUIT)
                    pPalette = sSamusPal_Default_Row0_SaX;
                else if (gEquipment.suitMiscStatus & SMF_GRAVITY_SUIT)
                    pPalette = sSamusPal_Default_Row0_Gravity;
                else if (gEquipment.suitMiscStatus & SMF_VARIA_SUIT)
#ifdef BUGFIX
                    pPalette = sSamusPal_Default_Row0_Varia;
#else // !BUGFIX
                    pPalette = sSamusPal_Default_Row0_Fusion + PAL_ROW;
#endif // BUGFIX
                else
                    pPalette = sSamusPal_Default_Row0_Fusion;

                SET_SAMUS_PAL_ROW_0(pPalette);
                if (pose != SPOSE_UNLOCKING_SECURITY)
                    pPalette = sSamusPal_Default_Row1;
                SET_SAMUS_PAL_ROW_1(pPalette);
                break;
        }
    }
}

/**
 * @brief c134 | 40 | Checks if the low health sound should play
 * 
 */
void SamusCheckPlayLowHealthSound(void)
{
    if (!gEquipment.lowHealth)
        return;

    // Don't play sound if dying
    if (gSamusData.pose == SPOSE_DYING)
        return;

    // Don't play sound if can't move
    if (gPreventMovementTimer != 0)
        return;

    // Play sound about every quarter of a second
    if (MOD_AND(gFrameCounter8Bit, CONVERT_SECONDS(.25f + 1.f / 60)) == 0)
        unk_3b78(SOUND_LOW_HEALTH);
}

/**
 * @brief c174 | 78 | Updates Samus's draw distance and standing status
 * 
 */
void SamusUpdateDrawDistanceAndStandingStatus(void)
{
    u8 offset;
    u8 standing;

    offset = sSamusCollisionData[gSamusData.pose][0];
    gSamusData.drawDistanceLeft = sSamusDrawDistanceOffsets[offset][0];
    gSamusData.drawDistanceTop = sSamusDrawDistanceOffsets[offset][1];
    gSamusData.drawDistanceRight = sSamusDrawDistanceOffsets[offset][2];
    gSamusData.drawDistanceBottom = sSamusDrawDistanceOffsets[offset][3];

    standing = sSamusCollisionData[gSamusData.pose][4];

    if (standing == STANDING_MID_AIR)
    {
        gSamusData.standingStatus = standing;
        gSamusData.slopeType = SLOPE_NONE;
    }
    else if (gSamusData.standingStatus == STANDING_ENEMY)
    {
        gSamusData.slopeType = SLOPE_NONE;
    }
    else
    {
        gSamusData.standingStatus = standing;
    }
}

/**
 * @brief c1ec | 264 | Updates the offset of Samus's arm cannon opening
 * 
 * @param direction Direction (0 = right, 1 = left)
 */
void SamusUpdateArmCannonOffset(u8 direction)
{
    u8 pose;
    s32 acd;
    const struct ArmCannonAnimData* pAnim;
    const s16* pOffset;
    s32 offset;

    pose = gSamusData.pose;
    acd = gSamusData.armCannonDirection;
    
    switch (pose)
    {
        case SPOSE_STANDING:
            pAnim = sArmCannonAnimPointers_Standing[acd][direction];
            break;

        case SPOSE_TURNING_AROUND:
            pAnim = sArmCannonAnimPointers_Turning[acd][direction];
            break;

        case SPOSE_SHOOTING:
            pAnim = sArmCannonAnimPointers_Shooting[acd][direction];
            break;
        
        case SPOSE_RUNNING:
            pAnim = sArmCannonAnimPointers_Running[acd][direction];
            break;
        
        case SPOSE_MID_AIR:
            pAnim = sArmCannonAnimPointers_MidAir[acd][direction];
            break;
        
        case SPOSE_TURNING_AROUND_MID_AIR:
            pAnim = sArmCannonAnimPointers_TurningMidAir[acd][direction];
            break;
        
        case SPOSE_LANDING:
            pAnim = sArmCannonAnimPointers_Landing[acd][direction];
            break;
        
        case SPOSE_CROUCHING:
            pAnim = sArmCannonAnimPointers_ShootingAndCrouching[acd][direction];
            break;
        
        case SPOSE_TURNING_AROUND_AND_CROUCHING:
            pAnim = sArmCannonAnimPointers_TurningAndCrouching[acd][direction];
            break;

        case SPOSE_SHOOTING_AND_CROUCHING:
            pAnim = sArmCannonAnimPointers_ShootingAndCrouching[acd][direction];
            break;

        case SPOSE_HANGING_ON_LEDGE:
            acd = gButtonInput & (gSamusData.direction ^ (KEY_RIGHT | KEY_LEFT)) ? 1 : 0;
            pAnim = sArmCannonAnimPointers_HangingOnLedge[acd][direction];
            break;

        case SPOSE_HOLDING_ARM_OUT_ON_VERTICAL_LADDER:
            pAnim = sArmCannonAnimPointers_OnVerticalLadder[acd][direction];
            break;

        case SPOSE_SHOOTING_ON_VERTICAL_LADDER:
            pAnim = sArmCannonAnimPointers_ShootingOnVerticalLadder[acd][direction];
            break;

        case SPOSE_DELAY_AFTER_SHOOTING_ON_HORIZONTAL_LADDER:
            pAnim = sArmCannonAnimPointers_AfterShootingOnHorizontalLadder[acd][direction];
            break;

        case SPOSE_SHOOTING_ON_HORIZONTAL_LADDER:
            pAnim = sArmCannonAnimPointers_ShootingOnHorizontalLadder[acd][direction];
            break;

        default:
            pAnim = sArmCannonAnimPointers_Default[pose][direction];
            break;
    }

    pAnim = &pAnim[gSamusData.currentAnimationFrame];
    pOffset = pAnim->pOffset;

    acd = pOffset[ACO_Y];
    if (acd & 0x80)
        gSamusGraphicsInfo.armCannonYOffset = acd - 0x80 * 2;
    else
        gSamusGraphicsInfo.armCannonYOffset = acd;
    gSamusGraphicsInfo.armCannonYOffset++;

    offset = pOffset[ACO_X];
    if (offset & 0x100)
        gSamusGraphicsInfo.armCannonXOffset = offset - 0x100 * 2;
    else
        gSamusGraphicsInfo.armCannonXOffset = offset;

    switch (gSamusData.pose)
    {
        case SPOSE_MORPHING:
        case SPOSE_MORPH_BALL:
        case SPOSE_ROLLING:
        case SPOSE_UNMORPHING:
            if (gSamusData.slopeType != 0)
                gSamusGraphicsInfo.armCannonYOffset += 2;
            break;

        default:
            if (gSamusData.slopeType & 0x10)
            {
                gSamusGraphicsInfo.armCannonXOffset += 2;
                gSamusGraphicsInfo.armCannonYOffset++;
            }
            else if (gSamusData.slopeType & 0x20)
            {
                gSamusGraphicsInfo.armCannonXOffset -= 2;
                gSamusGraphicsInfo.armCannonYOffset++;
            }
            break;
    }
}

/**
 * @brief c450 | 144 | Initializes data for various Samus related structs
 * 
 */
void SamusInit(void)
{
    s32 flag;
    
    if (gPauseScreenFlag == 0)
    {
        if (!gIsLoadingFile)
        {
            flag = gSamusEnvironmentalEffects[1].externalTimer > 15;
            gSamusEcho = *(struct SamusEcho *)sSamusGenericData_Empty;
            gSamusEnvironmentalEffects[0] = *(struct SamusEnvironmentalEffect *)sSamusGenericData_Empty;
            gSamusEnvironmentalEffects[1] = *(struct SamusEnvironmentalEffect *)sSamusGenericData_Empty;

            if (flag)
                gSamusEnvironmentalEffects[1].externalTimer = 0x80;

            // Charge beam fully if started charging before door transition
            if (gSamusData.chargeBeamCounter >= CHARGE_BEAM_START_THRESHOLD)
                gSamusData.chargeBeamCounter = CHARGE_BEAM_THRESHOLD;
        }

        gPreviousPositionCounter = 0;
        gUnk_300144e = 0;
        gSaXData = *(struct SaXData *)sSamusGenericData_Empty;
        gPoseLock = 0;
        gSamusPhysics = *(struct SamusPhysics *)sSamusGenericData_Empty;
    }

    if (gUnk_3000be3 || gIsLoadingFile)
        return;

    gEquipment = sEquipment_Empty;
    gSamusData = sSamusData_Empty;
    gSamusGraphicsInfo = *(struct SamusGraphicsInfo *)sSamusGenericData_Empty;
    gSamusAnimationInfo = *(struct SamusAnimationInfo *)sSamusGenericData_Empty;
    gSamusEnvironmentalEffects[0] = *(struct SamusEnvironmentalEffect *)sSamusGenericData_Empty;
    gSamusEnvironmentalEffects[1] = *(struct SamusEnvironmentalEffect *)sSamusGenericData_Empty;
    gSaXData = *(struct SaXData *)sSamusGenericData_Empty;
}

/**
 * @brief c594 | 44c | Updates the OAM data for Samus
 * 
 */
void SamusDraw(void)
{
    u8 priority;
    u8 oamSlot;
    u16* dst;
    u8 nextSlot;
    u8 currSlot;
    s16 i;
    const u16* src;
    s16 yPosition;
    s16 xPosition;
    u16 part;
    s16 ppc;
    u8 futureSlot;

    priority = 2;

    if (gSamusData.pose == SPOSE_DYING)
    {
        priority = 0;
        gNextOamSlot = 0;
    }
    else if (gSamusOnTopOfBackgrounds)
    {
        priority = 1;
    }

    if (gNextOamSlot > 106)
        gNextOamSlot = 106;

    dst = (u16*)gOamData;
    dst = (u16*)(gOamData + gNextOamSlot);
    nextSlot = gNextOamSlot;
    currSlot = gNextOamSlot;

    for (i = 0; i < ARRAY_SIZE(gSamusEnvironmentalEffects); i++)
    {
        if (gSamusEnvironmentalEffects[i].effect == ENV_EFFECT_NONE)
            continue;

        src = gSamusEnvironmentalEffects[i].pOamFrame;
        part = *src++;
        nextSlot += LOW_BYTE(part);

        xPosition = SUB_PIXEL_TO_PIXEL_(gSamusEnvironmentalEffects[i].xPosition) - SUB_PIXEL_TO_PIXEL_(gBg1XPosition);
        yPosition = SUB_PIXEL_TO_PIXEL_(gSamusEnvironmentalEffects[i].yPosition) - SUB_PIXEL_TO_PIXEL_(gBg1YPosition) + SUB_PIXEL_TO_PIXEL_(EIGHTH_BLOCK_SIZE);

        for (; currSlot < nextSlot; currSlot++)
        {
            part = *src++;
            *dst++ = part;

            gOamData[currSlot].split.y = part + yPosition;

            part = *src++;
            *dst++ = part;

            gOamData[currSlot].split.x = MOD_AND(part + xPosition, 512);

            *dst++ = *src++;

            gOamData[currSlot].split.priority = priority;
            
            dst++;
        }
    }

    xPosition = SUB_PIXEL_TO_PIXEL_(gSamusData.xPosition) - SUB_PIXEL_TO_PIXEL_(gBg1XPosition);
    yPosition = SUB_PIXEL_TO_PIXEL_(gSamusData.yPosition) - SUB_PIXEL_TO_PIXEL_(gBg1YPosition) + SUB_PIXEL_TO_PIXEL_(EIGHTH_BLOCK_SIZE);

    switch (gSamusData.pose)
    {
        case SPOSE_MORPHING:
        case SPOSE_MORPH_BALL:
        case SPOSE_ROLLING:
        case SPOSE_UNMORPHING:
            if (gSamusData.slopeType != SLOPE_NONE)
                do { yPosition += SUB_PIXEL_TO_PIXEL_(EIGHTH_BLOCK_SIZE); } while (0);
            break;

        default:
            if (gSamusData.slopeType & KEY_RIGHT)
                xPosition += SUB_PIXEL_TO_PIXEL_(EIGHTH_BLOCK_SIZE);
            else if (gSamusData.slopeType & KEY_LEFT)
                xPosition -= SUB_PIXEL_TO_PIXEL_(EIGHTH_BLOCK_SIZE);
            else
                break;

            yPosition += SUB_PIXEL_TO_PIXEL_(PIXEL_SIZE);
            break;
    }

    if (gSamusGraphicsInfo.unk_26 & 0x2000)
    {
        src = gSamusGraphicsInfo.pArmCannonOamFrame;
        part = *src++;
        nextSlot += LOW_BYTE(part);

        for (; currSlot < nextSlot; currSlot++)
        {
            part = *src++;
            *dst++ = part;

            gOamData[currSlot].split.y = part + yPosition;

            part = *src++;
            *dst++ = part;

            gOamData[currSlot].split.x = MOD_AND(part + xPosition, 512);

            *dst++ = *src++;

            gOamData[currSlot].split.priority = priority;
            
            dst++;
        }
    }

    src = gSamusGraphicsInfo.pSamusOamFrame;
    nextSlot += *src++;

    for (; currSlot < nextSlot; currSlot++)
    {
        part = *src++;
        *dst++ = part;

        gOamData[currSlot].split.y = part + yPosition;

        part = *src++;
        *dst++ = part;

        gOamData[currSlot].split.x = MOD_AND(part + xPosition, 512);

        *dst++ = *src++;

        gOamData[currSlot].split.priority = priority;
        
        dst++;
    }

    if (gSamusGraphicsInfo.unk_26 & 0x1000)
    {
        src = gSamusGraphicsInfo.pArmCannonOamFrame;
        part = *src++;
        nextSlot += LOW_BYTE(part);

        for (; currSlot < nextSlot; currSlot++)
        {
            part = *src++;
            *dst++ = part;

            gOamData[currSlot].split.y = part + yPosition;

            part = *src++;
            *dst++ = part;

            gOamData[currSlot].split.x = MOD_AND(part + xPosition, 512);

            *dst++ = *src++;

            gOamData[currSlot].split.priority = priority;
            
            dst++;
        }
    }

    if (gSamusEcho.active)
    {
        ppc = (s16)(gPreviousPositionCounter - gSamusEcho.position * 4 - 3);

        if (gUnk_300144e != 0 || ppc >= 0)
        {
            // Written this way to produce matching ASM
            gSamusGraphicsInfo.unk_26 = gSamusGraphicsInfo.unk_26;

            src = gSamusGraphicsInfo.pSamusOamFrame;
            nextSlot += *src++;

            ppc = MOD_AND(ppc, 64);
            xPosition = SUB_PIXEL_TO_PIXEL_(gPrevious64Positions[0][ppc]) - SUB_PIXEL_TO_PIXEL_(gBg1XPosition);
            yPosition = SUB_PIXEL_TO_PIXEL_(gPrevious64Positions[1][ppc]) - SUB_PIXEL_TO_PIXEL_(gBg1YPosition) + SUB_PIXEL_TO_PIXEL_(EIGHTH_BLOCK_SIZE);

            for (; currSlot < nextSlot; currSlot++)
            {
                part = *src++;
                *dst++ = part;
    
                gOamData[currSlot].split.y = part + yPosition;
    
                part = *src++;
                *dst++ = part;
    
                gOamData[currSlot].split.x = MOD_AND(part + xPosition, 512);
    
                *dst++ = *src++;
    
                gOamData[currSlot].split.priority = priority;
                
                dst++;
            }

            gSamusEcho.position = MOD_AND(gSamusEcho.position + 1, 4);
        }
    }

    gNextOamSlot = nextSlot;
}
