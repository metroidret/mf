#include "particle.h"

#include "gba.h"
#include "globals.h"
#include "macros.h"

#include "data/particle_data.h"
#include "data/projectile_data.h"

#include "constants/audio.h"
#include "constants/particle.h"
#include "constants/projectile.h"
#include "constants/samus.h"

#include "structs/escape.h"
#include "structs/particle.h"
#include "structs/projectile.h"
#include "structs/samus.h"

static Func_T sProcessParticleFunctionPointers[PE_END] = {
    [PE_NONE] = ParticleNone,
    [PE_BOMB] = ParticleBomb,
    [PE_FLARE_HIT] = ParticleFlareHit,
    [PE_NORMAL_BEAM_HIT] = ParticleNormalBeamHit,
    [PE_CHARGE_BEAM_HIT] = ParticleChargeBeamHit,
    [PE_WIDE_BEAM_HIT] = ParticleWideBeamHit,
    [PE_PLASMA_BEAM_HIT] = ParticlePlasmaBeamHit,
    [PE_INVINCIBLE_HIT] = ParticleInvincibleHit,
    [PE_MISSILE_EXPLOSION] = ParticleNormalMissileExplosion,
    [PE_SUPER_MISSILE_EXPLOSION] = ParticleSuperMissileExplosion,
    [PE_ICE_MISSILE_EXPLOSION] = ParticleIceMissileExplosion,
    [PE_DIFFUSION_MISSILE_EXPLOSION] = ParticleDiffusionMissileExplosion,
    [PE_CHARGED_DIFFUSION_MISSILE_EXPLOSION] = ParticleChargedDiffusionMissileExplosion,
    [PE_0xD] = ParticleSuperMissileExplosionNoScreenShake,
    [PE_ICE_BEAM_TRAIL] = ParticleIceBeamTrail,
    [PE_CHARGED_NORMAL_BEAM_TRAIL] = ParticleChargedNormalBeamTrail,
    [PE_CHARGED_CHARGE_BEAM_TRAIL] = ParticleChargedChargeBeamTrail,
    [PE_CHARGED_WIDE_BEAM_TRAIL] = ParticleChargedWideBeamTrail,
    [PE_CHARGED_PLASMA_BEAM_TRAIL] = ParticleChargedPlasmaBeamTrail,
    [PE_CHARGED_WAVE_BEAM_TRAIL] = ParticleChargedWaveBeamTrail,
    [PE_CHARGED_ICE_BEAM_TRAIL] = ParticleChargedIceBeamTrail,
    [PE_MISSILE_TRAIL] = ParticleNormalMissileTrail,
    [PE_SUPER_MISSILE_TRAIL] = ParticleSuperMissileTrail,
    [PE_ICE_MISSILE_TRAIL] = ParticleIceMissileTrail,
    [PE_DIFFUSION_MISSILE_TRAIL] = ParticleDiffusionMissileTrail,
    [PE_CHARGED_DIFFUSION_MISSILE_TRAIL] = ParticleChargedDiffusionMissileTrail,
    [PE_ABSORB_HEALTH_X] = ParticleAbsorbHealthX,
    [PE_ABSORB_MISSILE_X] = ParticleAbsorbMissileX,
    [PE_ABSORB_RED_X] = ParticleAbsorbRedX,
    [PE_ABSORB_CORE_X] = ParticleAbsorbCoreX,
    [PE_ABSORB_ICE_X_PRE_VARIA] = ParticleAbsorbIceXPreVaria,
    [PE_ICE_X_TRAIL] = ParticleIceXTrail,
    [PE_DIFFUSION_FLAKE_TRAIL] = ParticleDiffusionFlakeTrail,
    [PE_0x21] = ParticleExplosion1,
    [PE_0x22] = ParticleExplosion2,
    [PE_0x23] = ParticleExplosion3,
    [PE_0x24] = ParticleExplosion4,
    [PE_0x25] = ParticleExplosion5,
    [PE_0x26] = ParticleExplosion6,
    [PE_HEAVY_DUST_1] = ParticleHeavyDust1,
    [PE_HEAVY_DUST_2] = ParticleHeavyDust2,
    [PE_DUST_1] = ParticleDust1,
    [PE_DUST_2] = ParticleDust2,
    [PE_FIRE_BEAM] = ParticleFireBeam,
    [PE_ABSORBING_SUIT] = ParticleAbsorbingSuit,
    [PE_EXPLOSION_SMOKE] = ParticleExplosionSmoke,
    [PE_TAIL_EXPLOSION_SMOKE] = ParticleTailExplosionSmoke,
    [PE_0x2F] = ParticleExplosion7,
    [PE_0x30] = ParticleExplosion8,
    [PE_SMOKE] = ParticleSmoke,
    [PE_0x32] = ParticleExplosion9,
    [PE_0x33] = ParticleTailSmoke1,
    [PE_TAIL_EXPLOSION] = ParticleTailExplosion,
    [PE_0x35] = ParticleTailSmoke2,
    [PE_ENTER_OR_EXIT_WATER] = ParticleEnterOrExitWater,
    [PE_ENTER_OR_EXIT_WATER_BIG] = ParticleEnterOrExitWaterBig,
    [PE_SPRITE_ENTER_OR_EXIT_WATER] = ParticleSpriteEnterOrExitWater,
    [PE_0x39] = unk_73e90,
    [PE_0x3A] = ParticleExplosion10,
    [PE_OUTWARD_ICE_EXPLOSION] = ParticleOutwardIceExplosion,
    [PE_OUTWARD_SMOKE] = ParticleOutwardSmoke,
    [PE_SCREW_ATTACK_KILLED] = ParticleScrewAttackKilled,
    [PE_SPEEDBOOSTER_KILLED] = ParticleSpeedboosterKilled,
    [PE_SHINESPARK_KILLED] = ParticleShinesparkKilled,
    [PE_PSEUDO_SCREW_KILLED] = ParticlePseudoScrewKilled,
    [PE_GETTING_SUIT_BEAMS] = ParticleGettingSuitBeams,
    [PE_GETTING_SUIT] = ParticleGettingSuit,
    [PE_CHARGING_BEAM] = ParticleChargingBeam,
    [PE_CHARGING_BEAM_SPARKS] = ParticleChargingBeamSparks,
    [PE_CHARGING_MISSILE] = ParticleChargingMissile,
    [PE_ESCAPE] = ParticleEscape,
};

static u8 sBlob_79bddc_79c27c[] = INCBIN_U8("data/Blob_79bddc_79c27c.bin");

/**
 * @brief Checks if the current particle is on screen
 *
 */
void ParticleCheckOnScreen(void)
{
    u16 bgY;
    u16 bgX;

    u16 bgBaseY;
    u16 bgBaseX;

    u16 bgRightBoundry;
    u16 bgTopBoundry;
    u16 bgLeftBoundry;
    u16 bgBottomBoundry;

    u16 particleY;
    u16 particleX;

    if (gCurrentParticle.status & PARTICLE_STATUS_ABSOLUTE_POSITION)
    {
        gCurrentParticle.status |= PARTICLE_STATUS_ONSCREEN;
        return;
    }

    bgY = gBg1YPosition;
    bgX = gBg1XPosition;

    bgBaseY = bgY + BLOCK_TO_SUB_PIXEL(8);
    particleY = gCurrentParticle.yPosition + BLOCK_TO_SUB_PIXEL(8);
    bgBottomBoundry = bgBaseY - BLOCK_TO_SUB_PIXEL(2);
    bgTopBoundry = bgBaseY + BLOCK_TO_SUB_PIXEL(12);

    bgBaseX = bgX + BLOCK_TO_SUB_PIXEL(8);
    particleX = gCurrentParticle.xPosition + BLOCK_TO_SUB_PIXEL(8);
    bgLeftBoundry = bgBaseX - BLOCK_TO_SUB_PIXEL(2);
    bgRightBoundry = bgBaseX + BLOCK_TO_SUB_PIXEL(17);

    if (bgLeftBoundry < particleX && particleX < bgRightBoundry && bgBottomBoundry < particleY &&
        particleY < bgTopBoundry)
    {
        gCurrentParticle.status |= PARTICLE_STATUS_ONSCREEN;
    }
    else
    {
        if (gCurrentParticle.status & PARTICLE_STATUS_LIVE_OFF_SCREEN)
            gCurrentParticle.status &= ~PARTICLE_STATUS_ONSCREEN;
        else
            gCurrentParticle.status = 0;
    }
}

/**
 * @brief Draws a particle effect
 *
 * @param particleSlot Particle slot (unused)
 */
void ParticleDraw(s32 particleSlot)
{
    s32 prevSlot;
    s32 partCount;
    const u16* src;
    u16* dst;
    u16 yPosition;
    u16 xPosition;
    u16 bgPriority;
    u16 part;
    s32 i;

    prevSlot = gNextOamSlot;
    src = gCurrentParticleEffectOamFramePointer;

    partCount = *src++;

    if (partCount + prevSlot < OAM_BUFFER_DATA_SIZE)
    {
        dst = (u16*)(gOamData + prevSlot);

        if (gCurrentParticle.status & PARTICLE_STATUS_ABSOLUTE_POSITION)
        {
            yPosition = gCurrentParticle.yPosition;
            xPosition = gCurrentParticle.xPosition;
        }
        else
        {
            yPosition = SUB_PIXEL_TO_PIXEL(gCurrentParticle.yPosition) - SUB_PIXEL_TO_PIXEL(gBg1YPosition);
            xPosition = SUB_PIXEL_TO_PIXEL(gCurrentParticle.xPosition) - SUB_PIXEL_TO_PIXEL(gBg1XPosition);
        }

        if (gCurrentParticle.status & PARTICLE_STATUS_LOW_BG_PRIORITY)
        {
            if (gSamusOnTopOfBackgrounds)
                bgPriority = 1;
            else
                bgPriority = 2;
        }
        else
        {
            bgPriority = 0;
        }

        for (i = 0; i < partCount; i++)
        {
            part = *src++;
            *dst++ = part;
            gOamData[prevSlot + i].split.y = part + yPosition;

            part = *src++;
            *dst++ = part;
            gOamData[prevSlot + i].split.x = MOD_AND(part + xPosition, 512); // Needed to produce matching ASM

            *dst++ = *src++;
            gOamData[prevSlot + i].split.priority = bgPriority;

            dst++;
        }

        gNextOamSlot = partCount + prevSlot;
    }
}

/**
 * @brief Processes all the particle effects (calls handler and calls the draw function)
 *
 */
void ParticleUpdate(void)
{
    s32 i;
    u8 status;

    if (gSubGameMode1 == SUB_GAME_MODE_PLAYING)
    {
        for (i = 0; i < MAX_AMOUNT_OF_PARTICLES; i++)
        {
            if ((gParticleEffects[i].status & (PARTICLE_STATUS_EXISTS | PARTICLE_STATUS_HIGH_OAM_PRIORITY)) ==
                (PARTICLE_STATUS_EXISTS | PARTICLE_STATUS_HIGH_OAM_PRIORITY))
            {
                // Copy to current particle
                gCurrentParticle = gParticleEffects[i];

                // Call function for this effect
                sProcessParticleFunctionPointers[gCurrentParticle.effect]();

                if (gCurrentParticle.status & PARTICLE_STATUS_EXISTS)
                {
                    ParticleCheckOnScreen();
                    status = (gCurrentParticle.status & (PARTICLE_STATUS_ONSCREEN | PARTICLE_STATUS_NOT_DRAWN));
                    if (status == PARTICLE_STATUS_ONSCREEN)
                        ParticleDraw(i);
                }

                // Copy back to particle data
                gParticleEffects[i] = gCurrentParticle;
            }
        }

        for (i = 0; i < MAX_AMOUNT_OF_PARTICLES; i++)
        {
            if ((gParticleEffects[i].status & (PARTICLE_STATUS_EXISTS | PARTICLE_STATUS_HIGH_OAM_PRIORITY)) ==
                PARTICLE_STATUS_EXISTS)
            {
                // Copy to current particle
                gCurrentParticle = gParticleEffects[i];

                // Call function for this effect
                sProcessParticleFunctionPointers[gCurrentParticle.effect]();

                if (gCurrentParticle.status & PARTICLE_STATUS_EXISTS)
                {
                    ParticleCheckOnScreen();
                    status = (gCurrentParticle.status & (PARTICLE_STATUS_ONSCREEN | PARTICLE_STATUS_NOT_DRAWN));
                    if (status == PARTICLE_STATUS_ONSCREEN)
                        ParticleDraw(i);
                }

                // Copy back to particle data
                gParticleEffects[i] = gCurrentParticle;
            }
        }

        EscapeUpdate();
    }
}

/**
 * @brief Sets a new particle effect with the given parameters
 *
 */
void ParticleSet(u16 yPosition, u16 xPosition, u8 effect)
{
    s32 i;
    u8 low;
    u8 counter;
    u8 currCounter;
    u8 count;

    // Try to find an empty slot
    counter = FALSE;
    for (i = 0; i < MAX_AMOUNT_OF_PARTICLES; i++)
    {
        if (!gParticleEffects[i].status)
        {
            counter = TRUE;
            break;
        }
    }

    if (!counter)
    {
        // Couldn't find an empty slot, try to find a particle with the highest frame counter
        low = UCHAR_MAX;
        for (i = 0; i < MAX_AMOUNT_OF_PARTICLES; i++)
        {
            if (gParticleEffects[i].effect < PE_CHARGING_BEAM)
            {
                // Get counter
                currCounter = gParticleEffects[i].frameCounter;
            }
            else
            {
                // Includes PE_CHARGING_BEAM, PE_CHARGING_BEAM_SPARKS and PE_ESCAPE,
                // these can never be replaced
                currCounter = 0;
            }

            if (counter < currCounter)
            {
                // Found new highest, update counter
                counter = currCounter;
                // Store particle index
                low = i;
            }
        }

        if (low != UCHAR_MAX)
        {
            // Found a particle, get the index
            i = low;
        }
        else
        {
            // Couldn't find a particle, abort
            return;
        }
    }

    // Initialize
    gParticleEffects[i].status = PARTICLE_STATUS_EXISTS;

    gParticleEffects[i].yPosition = yPosition;
    gParticleEffects[i].xPosition = xPosition;

    gParticleEffects[i].currentAnimationFrame = 0;
    gParticleEffects[i].animationDurationCounter = 0;

    gParticleEffects[i].effect = effect;
    gParticleEffects[i].stage = 0;
    gParticleEffects[i].frameCounter = 0;
}

/**
 * @brief Updates the animation of a particle effect
 *
 * @param pOam OAM pointer of the particle
 */
void ParticleUpdateAnimation(const struct FrameData* pOam)
{
    gCurrentParticle.animationDurationCounter++;

    if (pOam[gCurrentParticle.currentAnimationFrame].timer <= gCurrentParticle.animationDurationCounter)
    {
        gCurrentParticle.animationDurationCounter = 0;
        gCurrentParticle.currentAnimationFrame++;

        if (pOam[gCurrentParticle.currentAnimationFrame].timer == 0)
            gCurrentParticle.currentAnimationFrame = 0;
    }

    // Update OAM pointer
    gCurrentParticleEffectOamFramePointer = pOam[gCurrentParticle.currentAnimationFrame].pFrame;
}

void ParticleNone(void)
{
    if (gCurrentParticle.stage == 0)
    {
        ParticleUpdateAnimation(sBombOam_Slow);
        gCurrentParticle.stage = 80;
        gCurrentParticle.status |= (PARTICLE_STATUS_LIVE_OFF_SCREEN | PARTICLE_STATUS_HIGH_OAM_PRIORITY);
    }
    else
    {
        gCurrentParticle.stage--;
        if (gCurrentParticle.stage > 30)
        {
            ParticleUpdateAnimation(sBombOam_Slow);
            return;
        }
        else if (gCurrentParticle.stage == 30)
        {
            gCurrentParticle.currentAnimationFrame = 0;
            gCurrentParticle.animationDurationCounter = 0;
        }

        ParticleUpdateAnimation(sBombOam_Fast);

        if (gCurrentParticle.stage == 0)
            gCurrentParticle.status = 0;
    }
}

void ParticleBomb(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_Bomb);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
    {
        gCurrentParticle.stage++;
        gCurrentParticle.status |= PARTICLE_STATUS_HIGH_OAM_PRIORITY;
        SoundPlay(SOUND_BOMB_EXPLODE);
    }
}

void ParticleFlareHit(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_FlareHit);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
    {
        gCurrentParticle.stage++;
        SoundPlay(SOUND_FLARE_FIRE);
    }
}

void ParticleNormalBeamHit(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_NormalBeamHit);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
    {
        gCurrentParticle.stage++;
        SoundPlay(SOUND_NORMAL_BEAM_HIT);
    }
}

void ParticleChargeBeamHit(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_ChargeBeamHit);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
    {
        gCurrentParticle.stage++;
        SoundPlay(SOUND_CHARGE_BEAM_HIT);
    }
}

void ParticleWideBeamHit(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_WideBeamHit);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
    {
        gCurrentParticle.stage++;
        SoundPlay(SOUND_WIDE_BEAM_HIT);
    }
}

void ParticlePlasmaBeamHit(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_PlasmaBeamHit);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
    {
        gCurrentParticle.stage++;
        SoundPlay(SOUND_PLASMA_BEAM_HIT);
    }
}

void ParticleInvincibleHit(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_InvincibleHit);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
    {
        gCurrentParticle.stage++;
        SoundPlayNotAlreadyPlaying(SOUND_INVINCIBLE_HIT);
    }
}

void ParticleNormalMissileExplosion(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_NormalMissileExplosion);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
    {
        gCurrentParticle.stage++;
        SoundStop(SOUND_NORMAL_MISSILE_THRUST);
        SoundPlay(SOUND_NORMAL_MISSILE_EXPLODE);
    }
}

void ParticleSuperMissileExplosion(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_SuperMissileExplosion);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
    {
        gCurrentParticle.stage++;
        SoundStop(SOUND_SUPER_MISSILE_THRUST);
        SoundPlay(SOUND_SUPER_MISSILE_EXPLODE);
        ScreenShakeStartHorizontal(10, 0x81);
        ScreenShakeStartVertical(10, 0x81);
    }
}

void ParticleIceMissileExplosion(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_IceMissileExplosion);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
    {
        gCurrentParticle.stage++;
        SoundStop(SOUND_ICE_MISSILE_THRUST);
        SoundPlay(SOUND_ICE_MISSILE_EXPLODE);
        ScreenShakeStartHorizontal(20, 0x81);
        ScreenShakeStartVertical(20, 0x81);
    }
}

void ParticleDiffusionMissileExplosion(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_DiffusionMissileExplosion);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
    {
        gCurrentParticle.stage++;
        SoundStop(SOUND_DIFFUSION_MISSILE_THRUST);
        SoundPlay(SOUND_DIFFUSION_MISSILE_EXPLODE);
        ScreenShakeStartHorizontal(30, 0x81);
        ScreenShakeStartVertical(30, 0x81);
    }
}

void ParticleChargedDiffusionMissileExplosion(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_ChargedDiffusionMissileExplosion);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
    {
        gCurrentParticle.stage++;
        SoundStop(SOUND_CHARGED_DIFFUSION_MISSILE_THRUST);
        SoundPlay_3b1c(SOUND_CHARGED_DIFFUSION_MISSILE_EXPLODE);
        ScreenShakeStartHorizontal(40, 0x81);
        ScreenShakeStartVertical(40, 0x81);
    }
}

void ParticleSuperMissileExplosionNoScreenShake(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_SuperMissileExplosion);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
        gCurrentParticle.stage++;
}

void ParticleIceBeamTrail(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_IceBeamTrail);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
        gCurrentParticle.stage++;
}

void ParticleChargedNormalBeamTrail(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_ChargedNormalBeamTrail);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
        gCurrentParticle.stage++;
}

void ParticleChargedChargeBeamTrail(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_ChargedChargeBeamTrail);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
        gCurrentParticle.stage++;
}

void ParticleChargedWideBeamTrail(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_ChargedWideBeamTrail);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
        gCurrentParticle.stage++;
}

void ParticleChargedPlasmaBeamTrail(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_ChargedPlasmaBeamTrail);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
        gCurrentParticle.stage++;
}

void ParticleChargedWaveBeamTrail(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_ChargedWaveBeamTrail);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
        gCurrentParticle.stage++;
}

void ParticleChargedIceBeamTrail(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_ChargedIceBeamTrail);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
        gCurrentParticle.stage++;
}

void ParticleNormalMissileTrail(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_NormalMissileTrail);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
    {
        gCurrentParticle.stage++;
        gCurrentParticle.status |= PARTICLE_STATUS_LOW_BG_PRIORITY;
    }
}

void ParticleSuperMissileTrail(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_SuperMissileTrail);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
    {
        gCurrentParticle.stage++;
        gCurrentParticle.status |= PARTICLE_STATUS_LOW_BG_PRIORITY;
    }
}

void ParticleIceMissileTrail(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_IceMissileTrail);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
    {
        gCurrentParticle.stage++;
        gCurrentParticle.status |= PARTICLE_STATUS_LOW_BG_PRIORITY;
    }
}

void ParticleDiffusionMissileTrail(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_DiffusionMissileTrail);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
    {
        gCurrentParticle.stage++;
        gCurrentParticle.status |= PARTICLE_STATUS_LOW_BG_PRIORITY;
    }
}

void ParticleChargedDiffusionMissileTrail(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_ChargedDiffusionMissileTrail);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
    {
        gCurrentParticle.stage++;
        gCurrentParticle.status |= PARTICLE_STATUS_LOW_BG_PRIORITY;
    }
}

void ParticleAbsorbHealthX(void)
{
    gCurrentParticle.frameCounter++;
    gCurrentParticle.yPosition = gSamusData.yPosition + gSamusData.drawDistanceTop / 2;
    gCurrentParticle.xPosition = gSamusData.xPosition;

    switch (gCurrentParticle.stage)
    {
        case 0:
            gCurrentParticle.stage = 1;
            ParticleUpdateAnimation(sParticleOam_AbsorbHealthXAbsorbing);
            break;

        case 1:
            if (gCurrentParticle.frameCounter > 27)
            {
                gCurrentParticle.stage = 2;
                gCurrentParticle.currentAnimationFrame = 0;
                gCurrentParticle.animationDurationCounter = 0;
                ParticleUpdateAnimation(sParticleOam_AbsorbHealthXEnding);
            }
            else
            {
                ParticleUpdateAnimation(sParticleOam_AbsorbHealthXAbsorbing);
            }
            break;

        case 2:
            ParticleUpdateAnimation(sParticleOam_AbsorbHealthXEnding);
            if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
                gCurrentParticle.status = 0;
            break;

        default:
            gCurrentParticle.status = 0;
            break;
    }
}

void ParticleAbsorbMissileX(void)
{
    gCurrentParticle.frameCounter++;
    gCurrentParticle.yPosition = gSamusData.yPosition + gSamusData.drawDistanceTop / 2;
    gCurrentParticle.xPosition = gSamusData.xPosition;

    switch (gCurrentParticle.stage)
    {
        case 0:
            gCurrentParticle.stage = 1;
            ParticleUpdateAnimation(sParticleOam_AbsorbMissileXAbsorbing);
            break;

        case 1:
            if (gCurrentParticle.frameCounter > 27)
            {
                gCurrentParticle.stage = 2;
                gCurrentParticle.currentAnimationFrame = 0;
                gCurrentParticle.animationDurationCounter = 0;
                ParticleUpdateAnimation(sParticleOam_AbsorbMissileXEnding);
            }
            else
            {
                ParticleUpdateAnimation(sParticleOam_AbsorbMissileXAbsorbing);
            }
            break;

        case 2:
            ParticleUpdateAnimation(sParticleOam_AbsorbMissileXEnding);
            if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
                gCurrentParticle.status = 0;
            break;

        default:
            gCurrentParticle.status = 0;
    }
}

void ParticleAbsorbRedX(void)
{
    gCurrentParticle.frameCounter++;
    gCurrentParticle.yPosition = gSamusData.yPosition + gSamusData.drawDistanceTop / 2;
    gCurrentParticle.xPosition = gSamusData.xPosition;

    switch (gCurrentParticle.stage)
    {
        case 0:
            gCurrentParticle.stage = 1;
            ParticleUpdateAnimation(sParticleOam_AbsorbRedXAbsorbing);
            break;

        case 1:
            if (gCurrentParticle.frameCounter > 27)
            {
                gCurrentParticle.stage = 2;
                gCurrentParticle.currentAnimationFrame = 0;
                gCurrentParticle.animationDurationCounter = 0;
                ParticleUpdateAnimation(sParticleOam_AbsorbRedXEnding);
            }
            else
            {
                ParticleUpdateAnimation(sParticleOam_AbsorbRedXAbsorbing);
            }
            break;

        case 2:
            ParticleUpdateAnimation(sParticleOam_AbsorbRedXEnding);
            if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
                gCurrentParticle.status = 0;
            break;

        default:
            gCurrentParticle.status = 0;
            break;
    }
}

void ParticleAbsorbCoreX(void)
{
    gCurrentParticle.frameCounter++;
    gCurrentParticle.yPosition = gSamusData.yPosition + gSamusData.drawDistanceTop / 2;
    gCurrentParticle.xPosition = gSamusData.xPosition;

    switch (gCurrentParticle.stage)
    {
        case 0:
            gCurrentParticle.stage = 1;
            ParticleUpdateAnimation(sParticleOam_AbsorbCoreXAbsorbing);
            break;

        case 1:
            if (gCurrentParticle.frameCounter > 27)
            {
                gCurrentParticle.stage = 2;
                gCurrentParticle.currentAnimationFrame = 0;
                gCurrentParticle.animationDurationCounter = 0;
                ParticleUpdateAnimation(sParticleOam_AbsorbCoreXEnding);
            }
            else
            {
                ParticleUpdateAnimation(sParticleOam_AbsorbCoreXAbsorbing);
            }
            break;

        case 2:
            ParticleUpdateAnimation(sParticleOam_AbsorbCoreXEnding);
            if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
                gCurrentParticle.status = 0;
            break;

        default:
            gCurrentParticle.status = 0;
            break;
    }
}

void ParticleAbsorbIceXPreVaria(void)
{
    gCurrentParticle.frameCounter++;
    gCurrentParticle.yPosition = gSamusData.yPosition + gSamusData.drawDistanceTop / 2;
    gCurrentParticle.xPosition = gSamusData.xPosition;
    ParticleUpdateAnimation(sParticleOam_AbsorbIceXPreVaria);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
        gCurrentParticle.stage++;
}

void ParticleIceXTrail(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_IceXTrail);
    gCurrentParticle.status ^= PARTICLE_STATUS_LOW_BG_PRIORITY;

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
        gCurrentParticle.stage++;
}

void ParticleDiffusionFlakeTrail(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_DiffusionFlakeTrail);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
        gCurrentParticle.stage++;
}

void ParticleFireBeam(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_FireBeam);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
    {
        gCurrentParticle.stage++;
        gCurrentParticle.status |= PARTICLE_STATUS_LOW_BG_PRIORITY;
    }
}

void ParticleExplosion1(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_Explosion1);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
        gCurrentParticle.stage++;
}

void ParticleExplosion2(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_Explosion2);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
        gCurrentParticle.stage++;
}

void ParticleExplosion3(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_Explosion3);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
        gCurrentParticle.stage++;
}

void ParticleExplosion4(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_Explosion4);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
        gCurrentParticle.stage++;
}

void ParticleExplosion5(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_Explosion5);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
        gCurrentParticle.stage++;
}

void ParticleExplosion6(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_Explosion6);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
    {
        gCurrentParticle.stage++;
        gCurrentParticle.status |= PARTICLE_STATUS_HIGH_OAM_PRIORITY;
    }
}

void ParticleHeavyDust1(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_HeavyDust);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
        gCurrentParticle.stage++;
}

void ParticleHeavyDust2(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_HeavyDust);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
    {
        gCurrentParticle.stage++;
        gCurrentParticle.status |= PARTICLE_STATUS_LOW_BG_PRIORITY;
    }
}

void ParticleEnterOrExitWater(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_EnterOrExitWater);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
    {
        gCurrentParticle.stage++;
        gCurrentParticle.status |= PARTICLE_STATUS_LOW_BG_PRIORITY;
    }
}

void ParticleEnterOrExitWaterBig(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_EnterOrExitWaterBig);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
    {
        gCurrentParticle.stage++;
        gCurrentParticle.status |= PARTICLE_STATUS_LOW_BG_PRIORITY;
    }
}

void ParticleSpriteEnterOrExitWater(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_SpriteEnterOrExitWater);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
    {
        gCurrentParticle.stage++;
        gCurrentParticle.status |= PARTICLE_STATUS_LOW_BG_PRIORITY;
    }
}

void unk_73e90(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sWaterDropOam_Splashing);
    gCurrentParticle.yPosition = gEffectYPosition;

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
        gCurrentParticle.stage++;
}

void ParticleExplosionSmoke(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_ExplosionSmoke);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
        gCurrentParticle.stage++;
}

void ParticleTailExplosionSmoke(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_TailExplosionSmoke);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
        gCurrentParticle.stage++;
}

void ParticleExplosion7(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_Explosion7);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
        gCurrentParticle.stage++;
}

void ParticleExplosion10(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_Explosion10);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
        gCurrentParticle.stage++;
}

void ParticleExplosion8(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_Explosion8);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
        gCurrentParticle.stage++;
}

void ParticleSmoke(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_Smoke);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
        gCurrentParticle.stage++;
}

void ParticleExplosion9(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_Explosion9);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
        gCurrentParticle.stage++;
}

void ParticleTailSmoke1(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_TailSmoke1);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
        gCurrentParticle.stage++;
}

void ParticleTailExplosion(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_TailExplosion);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
        gCurrentParticle.stage++;
}

void ParticleTailSmoke2(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_TailSmoke2);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
        gCurrentParticle.stage++;
}

void ParticleOutwardIceExplosion(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_OutwardIceExplosion);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
        gCurrentParticle.stage++;
}

void ParticleOutwardSmoke(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_OutwardSmoke);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
        gCurrentParticle.stage++;
}

void ParticleScrewAttackKilled(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_ScrewAttackKilled);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
    {
        gCurrentParticle.stage++;
        SoundPlay(SOUND_SHINESPARK_SCREW_ATTACK_KILLED);
    }
}

void ParticleSpeedboosterKilled(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_SpeedboosterKilled);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
    {
        gCurrentParticle.stage++;
        SoundPlay(SOUND_SPEEDBOOSTER_KILLED);
    }
}

void ParticleShinesparkKilled(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_ShinesparkKilled);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
    {
        gCurrentParticle.stage++;
        SoundPlay(SOUND_SHINESPARK_SCREW_ATTACK_KILLED);
    }
}

void ParticlePseudoScrewKilled(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_PseudoScrewKilled);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
    {
        gCurrentParticle.stage++;
        SoundPlay(SOUND_PSEUDO_SCREW_KILLED);
    }
}

void ParticlePlayBeamChargingSound(void)
{
    u8 beams;

    beams = gEquipment.beamStatus;

    if (beams & BF_ICE_BEAM)
        SoundPlay(SOUND_ICE_BEAM_CHARGING);
    else if (beams & BF_WAVE_BEAM)
        SoundPlay(SOUND_WAVE_BEAM_CHARGING);
    else if (beams & BF_PLASMA_BEAM)
        SoundPlay(SOUND_PLASMA_BEAM_CHARGING);
    else if (beams & BF_WIDE_BEAM)
        SoundPlay(SOUND_WIDE_BEAM_CHARGING);
    else
        SoundPlay(SOUND_CHARGE_BEAM_CHARGING);
}

void ParticleStopBeamChargingSound(void)
{
    u8 beams;

    beams = gEquipment.beamStatus;

    if (beams & BF_ICE_BEAM)
        SoundStop(SOUND_ICE_BEAM_CHARGING);
    else if (beams & BF_WAVE_BEAM)
        SoundStop(SOUND_WAVE_BEAM_CHARGING);
    else if (beams & BF_PLASMA_BEAM)
        SoundStop(SOUND_PLASMA_BEAM_CHARGING);
    else if (beams & BF_WIDE_BEAM)
        SoundStop(SOUND_WIDE_BEAM_CHARGING);
    else
        SoundStop(SOUND_CHARGE_BEAM_CHARGING);
}

void ParticlePlayBeamChargedSound(void)
{
    u8 beams;

    beams = gEquipment.beamStatus;

    if (beams & BF_ICE_BEAM)
        SoundPlay(SOUND_ICE_BEAM_CHARGED);
    else if (beams & BF_WAVE_BEAM)
        SoundPlay(SOUND_WAVE_BEAM_CHARGED);
    else if (beams & BF_PLASMA_BEAM)
        SoundPlay(SOUND_PLASMA_BEAM_CHARGED);
    else if (beams & BF_WIDE_BEAM)
        SoundPlay(SOUND_WIDE_BEAM_CHARGED);
    else
        SoundPlay(SOUND_CHARGE_BEAM_CHARGED);
}

void ParticleChargingBeam(void)
{
    gCurrentParticle.yPosition = gArmCannonY;
    gCurrentParticle.xPosition = gArmCannonX;

    if (gSamusData.chargeBeamCounter < CHARGE_BEAM_START_THRESHOLD)
    {
        gCurrentParticle.status = 0;
        if (gCurrentParticle.stage <= 1)
            ParticleStopBeamChargingSound();
        return;
    }

    switch (gSamusData.pose)
    {
        case SPOSE_SPINNING:
        case SPOSE_WALL_JUMPING:
        case SPOSE_SPACE_JUMPING:
        case SPOSE_SCREW_ATTACKING:
            gCurrentParticle.status |= PARTICLE_STATUS_NOT_DRAWN;
            break;

        default:
            gCurrentParticle.status &= ~PARTICLE_STATUS_NOT_DRAWN;
            break;
    }

    switch (gCurrentParticle.stage)
    {
        case 0:
            gCurrentParticle.status |= PARTICLE_STATUS_LIVE_OFF_SCREEN;
            gCurrentParticle.stage++;
            ParticleUpdateAnimation(sParticleOam_ChargingBeamBegin);
            ParticlePlayBeamChargingSound();
            break;

        case 1:
            if (gSamusData.chargeBeamCounter >= CHARGE_BEAM_THRESHOLD)
            {
                gCurrentParticle.stage++;
                gCurrentParticle.currentAnimationFrame = 0;
                gCurrentParticle.animationDurationCounter = 0;
                gCurrentParticle.frameCounter = 0;
                ParticleUpdateAnimation(sParticleOam_ChargingBeamCharged);
            }
            else
            {
                ParticleUpdateAnimation(sParticleOam_ChargingBeamBegin);
            }
            break;

        default:
            ParticleUpdateAnimation(sParticleOam_ChargingBeamCharged);
            if (MOD_AND(gCurrentParticle.frameCounter, 16) == 0)
                ParticlePlayBeamChargedSound();
            gCurrentParticle.frameCounter++;
            break;
    }
}

void ParticleChargingBeamSparks(void)
{
    gCurrentParticle.yPosition = gArmCannonY;
    gCurrentParticle.xPosition = gArmCannonX;

    if (gSamusData.chargeBeamCounter < CHARGE_BEAM_START_THRESHOLD)
    {
        gCurrentParticle.status = 0;
        return;
    }

    switch (gSamusData.pose)
    {
        case SPOSE_SPINNING:
        case SPOSE_WALL_JUMPING:
        case SPOSE_SPACE_JUMPING:
        case SPOSE_SCREW_ATTACKING:
            gCurrentParticle.status |= PARTICLE_STATUS_NOT_DRAWN;
            break;

        default:
            gCurrentParticle.status &= ~PARTICLE_STATUS_NOT_DRAWN;
            break;
    }

    switch (gCurrentParticle.stage)
    {
        case 0:
            gCurrentParticle.status |= PARTICLE_STATUS_LIVE_OFF_SCREEN | PARTICLE_STATUS_HIGH_OAM_PRIORITY;
            gCurrentParticle.stage++;
            ParticleUpdateAnimation(sParticleOam_ChargingBeamSparksBegin);
            break;

        case 1:
            if (gSamusData.chargeBeamCounter >= CHARGE_BEAM_THRESHOLD)
            {
                gCurrentParticle.stage++;
                gCurrentParticle.currentAnimationFrame = 0;
                gCurrentParticle.animationDurationCounter = 0;
                ParticleUpdateAnimation(sParticleOam_ChargingBeamSparksCharged);
            }
            else
            {
                ParticleUpdateAnimation(sParticleOam_ChargingBeamSparksBegin);
            }
            break;

        default:
            ParticleUpdateAnimation(sParticleOam_ChargingBeamSparksCharged);
            break;
    }
}

void ParticleAbsorbingSuit(void)
{
    gCurrentParticle.frameCounter++;
    gCurrentParticle.yPosition = gArmCannonY;
    gCurrentParticle.xPosition = gArmCannonX;
    ParticleUpdateAnimation(sParticleOam_AbsorbingSuit);

    if (gSamusData.unk_B == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
        gCurrentParticle.stage++;
}

void ParticleChargingMissile(void)
{
    gCurrentParticle.yPosition = gArmCannonY;
    gCurrentParticle.xPosition = gArmCannonX;

    if (gSamusEnvironmentalEffects[1].externalTimer < CHARGE_BEAM_START_THRESHOLD)
    {
        gCurrentParticle.status = 0;
        if (gCurrentParticle.stage <= 1)
            SoundStop(SOUND_DIFFUSION_MISSILE_CHARGING);
        return;
    }

    switch (gSamusData.pose)
    {
        case SPOSE_SPINNING:
        case SPOSE_WALL_JUMPING:
        case SPOSE_SPACE_JUMPING:
        case SPOSE_SCREW_ATTACKING:
            gCurrentParticle.status |= PARTICLE_STATUS_NOT_DRAWN;
            break;

        default:
            gCurrentParticle.status &= ~PARTICLE_STATUS_NOT_DRAWN;
            break;
    }

    switch (gCurrentParticle.stage)
    {
        case 0:
            gCurrentParticle.status |= PARTICLE_STATUS_LIVE_OFF_SCREEN;
            gCurrentParticle.stage++;
            ParticleUpdateAnimation(sParticleOam_ChargingMissileBegin);
            SoundPlay(SOUND_DIFFUSION_MISSILE_CHARGING);
            break;

        case 1:
            if (gSamusEnvironmentalEffects[1].externalTimer >= CHARGE_MISSILE_THRESHOLD)
            {
                gCurrentParticle.stage++;
                gCurrentParticle.currentAnimationFrame = 0;
                gCurrentParticle.animationDurationCounter = 0;
                gCurrentParticle.frameCounter = 0;
                ParticleUpdateAnimation(sParticleOam_ChargingMissileCharged);
            }
            else
            {
                ParticleUpdateAnimation(sParticleOam_ChargingMissileBegin);
            }
            break;

        default:
            ParticleUpdateAnimation(sParticleOam_ChargingMissileCharged);
            if (MOD_AND(gCurrentParticle.frameCounter, 16) == 0)
                SoundPlay(SOUND_DIFFUSION_MISSILE_CHARGED);
            gCurrentParticle.frameCounter++;
            break;
    }
}

void ParticleDust1(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_Dust1);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
        gCurrentParticle.stage++;
}

void ParticleDust2(void)
{
    gCurrentParticle.frameCounter++;
    ParticleUpdateAnimation(sParticleOam_Dust2);

    if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
        gCurrentParticle.stage++;
}

void ParticleEscape(void)
{
    switch (gCurrentParticle.stage)
    {
        case 0:
            gCurrentParticle.stage = 1;
            gCurrentParticle.status |= (PARTICLE_STATUS_ABSOLUTE_POSITION | PARTICLE_STATUS_LIVE_OFF_SCREEN);
            EscapeSetDigits();
            gEscapeStatus = ESCAPE_STATUS_HAPPENNING;
            break;

        case 1:
            if (gEscapeStatus == ESCAPE_STATUS_FAILED)
            {
                gPreventMovementTimer = 1000;
                gCurrentParticle.stage = 3;
                gCurrentParticle.frameCounter = UCHAR_MAX;
                unk_6dee8();
            }
            else if (gEscapeStatus == ESCAPE_STATUS_HAPPENNING && EventCheckOn_EndEscape())
            {
                gCurrentParticle.stage = 2;
                gCurrentParticle.frameCounter = 32;
            }
            break;

        case 2:
            gCurrentParticle.yPosition -= BLOCK_TO_SUB_PIXEL(0.03125f);
            if (--gCurrentParticle.frameCounter == 0)
                gCurrentParticle.status = 0;
            break;
    }

    EscapeUpdateOam();
    gCurrentParticleEffectOamFramePointer = gEscapeDigitsOam;
}

void ParticleGettingSuit(void)
{
    gCurrentParticle.frameCounter++;
    gCurrentParticle.yPosition = gSamusData.yPosition + gSamusData.drawDistanceTop / 2 - BLOCK_TO_SUB_PIXEL(0.5f);
    gCurrentParticle.xPosition = gSamusData.xPosition;

    switch (gCurrentParticle.stage)
    {
        case 0:
            gCurrentParticle.stage = 1;
            ParticleUpdateAnimation(sParticleOam_GettingSuit);
            break;

        case 1:
            if (!gPoseLock)
            {
                gCurrentParticle.stage = 2;
                gCurrentParticle.currentAnimationFrame = 0;
                gCurrentParticle.animationDurationCounter = 0;
                ParticleUpdateAnimation(sParticleOam_AbsorbingSuit);
            }
            else
            {
                ParticleUpdateAnimation(sParticleOam_GettingSuit);
            }
            break;

        case 2:
            ParticleUpdateAnimation(sParticleOam_AbsorbingSuit);
            if (gCurrentParticle.currentAnimationFrame == 0 && gCurrentParticle.animationDurationCounter == 0)
                gCurrentParticle.status = 0;
            break;

        default:
            gCurrentParticle.status = 0;
            break;
    }
}

void ParticleGettingSuitBeams(void)
{
    gCurrentParticle.frameCounter++;
    gCurrentParticle.yPosition = gSamusData.yPosition + gSamusData.drawDistanceTop / 2 - BLOCK_TO_SUB_PIXEL(0.5f);
    gCurrentParticle.xPosition = gSamusData.xPosition;
    ParticleUpdateAnimation(sParticleOam_GettingSuitBeams);

    if (!gPoseLock)
        gCurrentParticle.status = 0;

    if (gCurrentParticle.stage == 0)
    {
        gCurrentParticle.stage++;
        gCurrentParticle.status |= PARTICLE_STATUS_HIGH_OAM_PRIORITY;
    }
}
