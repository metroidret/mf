#include "gba.h"
#include "audio_wrappers.h"

#include "data/audio.h"

#include "structs/audio.h"

/**
 * @brief 30b8 | 5c | DMA 2 interrupt callback
 * 
 */
void Dma2IntrCode(void)
{
    gMusicInfo.unk_10++;
    if (gMusicInfo.unk_10 == gMusicInfo.unk_E)
    {
        // Flush DMA 1 and 2
        WRITE_32(REG_DMA1_CNT, C_32_2_16(DMA_DEST_FIXED | DMA_32BIT | DMA_ENABLE, sizeof(u32)));
        WRITE_32(REG_DMA2_CNT, C_32_2_16(DMA_DEST_FIXED | DMA_32BIT | DMA_ENABLE, sizeof(u32)));
        WRITE_16(REG_DMA1_CNT + 2, DMA_SRC_FIXED | DMA_32BIT);
        WRITE_16(REG_DMA2_CNT + 2, DMA_SRC_FIXED | DMA_32BIT);

        WRITE_16(REG_DMA1_CNT + 2, DMA_REPEAT | DMA_32BIT | DMA_START_VBLANK | DMA_START_HBLANK | DMA_ENABLE);
        WRITE_16(REG_DMA2_CNT + 2, DMA_REPEAT | DMA_32BIT | DMA_START_VBLANK | DMA_START_HBLANK | DMA_INTR_ENABLE | DMA_ENABLE);

        gMusicInfo.unk_10 = 0;
    }
}

/**
 * @brief 3114 | 7c | Restarts the sound registers
 * 
 */
void RestartSound(void)
{
    if (gMusicInfo.occupied)
        return;

    gMusicInfo.occupied = TRUE;

    WRITE_16(REG_SOUND1CNT_X, SOUNDCNT_RESTART_SOUND);

    WRITE_8(REG_SOUND2CNT_L + 1, HIGH_BYTE(SOUNDCNT_ENVELOPE_INCREASE));
    WRITE_16(REG_SOUND2CNT_H, SOUNDCNT_RESTART_SOUND);

    WRITE_8(REG_SOUND3CNT_L, 0); // Turn off channel 3

    WRITE_8(REG_SOUND4CNT_L + 1, HIGH_BYTE(SOUNDCNT_ENVELOPE_INCREASE));
    WRITE_16(REG_SOUND4CNT_H, SOUNDCNT_RESTART_SOUND);

    // Flush DMA 1 and 2
    WRITE_32(REG_DMA1_CNT, C_32_2_16(DMA_DEST_FIXED | DMA_32BIT | DMA_ENABLE, sizeof(u32)));
    WRITE_32(REG_DMA2_CNT, C_32_2_16(DMA_DEST_FIXED | DMA_32BIT | DMA_ENABLE, sizeof(u32)));
    WRITE_16(REG_DMA1_CNT + 2, DMA_SRC_FIXED | DMA_32BIT);
    WRITE_16(REG_DMA2_CNT + 2, DMA_SRC_FIXED | DMA_32BIT);

    CPU_FILL_32(0, gMusicInfo.soundRawData, sizeof(gMusicInfo.soundRawData));
    WRITE_8(REG_SOUNDCNT_X, 0); // Disable and reset sound (PSG and FIFO) registers

    gMusicInfo.occupied = FALSE;
}

/**
 * @brief 3190 | 1a8 | To document
 * 
 * @param isInterrupting Is interrupting
 */
void unk_3190(u8 isInterrupting)
{
    vu8 j;
    vu8 track;
    vu8 tmp;
    vu8 currChannel;
    vu8 startTrack;
    volatile struct TrackData* pTrack;
    volatile struct TrackVariables* pVariables;
    volatile struct SoundChannel* pChannel;
    volatile struct SoundChannel* pChannelNext;

    currChannel = 0;
    if (!isInterrupting)
        startTrack = 0;
    else
        startTrack = 2;

    for (track = startTrack; track <= (u16)gNumMusicPlayers; track++)
    {
        if ((0x4D >> track) & 1)
        {
            if (track == 0)
            {
                if (gMusicInfo.unk_20 == 0)
                    pTrack = sMusicTrackDataRom[1].pTrack;
                else
                    pTrack = sMusicTrackDataRom[0].pTrack;
            }
            else
            {
                pTrack = sMusicTrackDataRom[track].pTrack;
            }
            
            if (pTrack->occupied)
                continue;

            pTrack->occupied = TRUE;

            if (!(pTrack->unk_1E & 1) && (pTrack->flags & 2) &&
               (track != 0 || (pTrack->unk_1E & 2)))
            {
                pTrack->unk_1E = 1;

                for (j = 0, pVariables = pTrack->pVariables; j < pTrack->amountOfTracks; j++, pVariables++)
                {
                    if (pVariables->channel & 0xC0)
                        continue;
                    
                    if (pVariables->pSoundPsg != NULL)
                    {
                        tmp = (pVariables->channel & 7) - 1;
                        ClearRegistersForPsg(pVariables->pSoundPsg, tmp);
                    }

                    if (pVariables->pChannel == NULL)
                        continue;
                    
                    for (pChannel = pVariables->pChannel; pChannel != NULL; pChannel = pChannelNext)
                    {
                        gSoundChannelBackup[currChannel].pChannel = (struct SoundChannel*)pChannel;
                        gSoundChannelBackup[currChannel].channel = *pChannel;
                        currChannel++;

                        pChannel->unk_0 = 0;
                        pChannel->pVariables = NULL;
                        pChannelNext = pChannel->pChannel2;
                        pChannel->pChannel2 = NULL;
                        pChannel->pChannel1 = NULL;
                    }
                }
            }

            pTrack->occupied = FALSE;
        }
    }
}

/**
 * @brief 3338 | 15c | To document
 * 
 * @param arg0
 */
void unk_3338(u8 arg0)
{
    vu8 j;
    vu8 track;
    vu8 tmp; // Unused
    vu8 currChannel;
    vu8 startTrack;
    volatile struct TrackData* pTrack;
    volatile struct TrackVariables* pVariables;
    volatile struct SoundChannel* pChannel;

    currChannel = 0;
    if (!arg0)
        startTrack = 0;
    else
        startTrack = 2;

    for (track = startTrack; track <= (u16)gNumMusicPlayers; track++)
    {
        if ((0x4D >> track) & 1)
        {
            if (track == 0)
            {
                if (gMusicInfo.unk_20 == 0)
                    pTrack = sMusicTrackDataRom[1].pTrack;
                else
                    pTrack = sMusicTrackDataRom[0].pTrack;
            }
            else
            {
                pTrack = sMusicTrackDataRom[track].pTrack;
            }
            
            if (pTrack->occupied)
                continue;

            pTrack->occupied = TRUE;

            if (pTrack->unk_1E & 1)
            {
                pTrack->unk_1E &= ~1;
                pTrack->unk_1E |= 2;

                for (j = 0, pVariables = pTrack->pVariables; j < pTrack->amountOfTracks; j++, pVariables++)
                {
                    if (pVariables->channel & 0xC0)
                        continue;

                    if (pVariables->pChannel == NULL)
                        continue;
                        
                    for (pChannel = pVariables->pChannel; pChannel != NULL; pChannel = pChannel->pChannel2)
                    {
                        unk_1e14(pChannel);
                        *pChannel = gSoundChannelBackup[currChannel].channel;
                        currChannel++;
                    }
                }
            }

            pTrack->occupied = FALSE;
        }
    }
}

/**
 * @brief 3494 | 4 | To document
 * 
 */
void unk_3494(void)
{
    // Empty
}

/**
 * @brief 3498 | 5c | Checks if a new music track should play after a transition,
 * and fades the current music if so
 * 
 * @param musicTrack New music track to set
 */
void CheckSetNewMusicTrack(u16 musicTrack)
{
    struct TrackData* pTrack;
    
    if (gMusicInfo.priority != 0)
        return;

    if (musicTrack == MUSIC_C)
        return;
    
    if (gMusicInfo.occupied)
        return;

    gMusicInfo.occupied = TRUE;

    pTrack = sMusicTrackDataRom[0].pTrack;

    // Probably used as an indicator during development when no music track was set
    if (musicTrack == MUSIC_NONE)
        musicTrack = SOUND_CHARACTER_APPEARING_FEDERATION;

    if (sSoundDataEntries[musicTrack].pHeader != pTrack->pHeader)
    {
        ApplyMusicSoundFading(pTrack, 30);
        gMusicInfo.musicTrackOnTransition = musicTrack;
    }
    
    gMusicInfo.occupied = FALSE;
}

/**
 * @brief 34f4 | 44 | Checks if a new music track was set to play after a transition
 * 
 */
void CheckPlayNewMusicTrack(void)
{
    if (gMusicInfo.priority == 0 && gMusicInfo.musicTrackOnTransition != MUSIC_NONE)
    {
        InitTrack(sMusicTrackDataRom[0].pTrack, sSoundDataEntries[gMusicInfo.musicTrackOnTransition].pHeader);

        gMusicInfo.unk_20 = 0;
        gMusicInfo.musicTrack = gMusicInfo.musicTrackOnTransition;
        gMusicInfo.musicTrackOnTransition = MUSIC_NONE;
    }
}

/**
 * @brief 3538 | 18c | Plays a music track with a priority
 * 
 * @param musicTrack Music track to play
 * @param priority Priority of the music
 */
void PlayMusic(u16 musicTrack, u8 priority)
{
    // TODO: Remove goto statements

    const u8 *pHeader;
    u32 flag1;
    struct TrackData *pTrack0;
    struct TrackData *pTrack1;

    if (gMusicInfo.occupied != 0)
        return;

    gMusicInfo.occupied = TRUE;
    gMusicInfo.priority = priority;
    pHeader = sSoundDataEntries[musicTrack].pHeader;
    
    if (priority != 0)
    {
        if (gMusicInfo.unk_20 == 0)
        {
            if (musicTrack == gMusicInfo.musicTrack && (sMusicTrackDataRom[0].pTrack->flags & 2))
                goto exit;

            if (sMusicTrackDataRom[1].pTrack->unk_1E & 2)
                flag1 = FALSE;
            else
                flag1 = TRUE;
        }
        else
        {
            if (musicTrack == gMusicInfo.unk_1E && (sMusicTrackDataRom[1].pTrack->flags & 2))
                goto exit;

            if (sMusicTrackDataRom[0].pTrack->unk_1E & 2)
                flag1 = TRUE;
            else
                flag1 = FALSE;
        }

        if (!flag1)
        {
            pTrack1 = sMusicTrackDataRom[0].pTrack;
            pTrack0 = sMusicTrackDataRom[1].pTrack;

            if ((pTrack1->flags & 0x1A) != 2 || pHeader != pTrack1->pHeader)
            {
                gMusicInfo.unk_20 = 0;
                gMusicInfo.musicTrack = musicTrack;
                
                if (pTrack0->flags > 1 && !(pTrack0->unk_1E & 2))
                    StopMusicOrSound(pTrack0);
                
                goto block_32;
            }
        }
        else
        {
            pTrack1 = sMusicTrackDataRom[1].pTrack;
            pTrack0 = sMusicTrackDataRom[0].pTrack;
            
            if ((pTrack1->flags & 0x1A) != 2 || pHeader != pTrack1->pHeader)
            {
                gMusicInfo.unk_20 = 1;
                gMusicInfo.unk_1E = musicTrack;

                if (pTrack0->flags > 1 && !(pTrack0->unk_1E & 2))
                    StopMusicOrSound(pTrack0);
                
                goto block_32;
            }
        }
    }
    else
    {
        if (musicTrack == gMusicInfo.musicTrack)
        {
            if (sMusicTrackDataRom[0].pTrack->unk_1E & 2)
                StopMusicOrSound(sMusicTrackDataRom[0].pTrack);
            else if (sMusicTrackDataRom[0].pTrack->flags & 2)
                goto exit;
        }

        pTrack1 = sMusicTrackDataRom[0].pTrack;
        pTrack0 = sMusicTrackDataRom[1].pTrack;

        if ((pTrack1->flags & 0x1A) != 2 || pHeader != pTrack1->pHeader)
        {
            if (pTrack0->flags > 1 && !(pTrack0->unk_1E & 2))
                StopMusicOrSound(pTrack0);
            
            pHeader = sSoundDataEntries[musicTrack].pHeader;
            gMusicInfo.unk_20 = 0;
            gMusicInfo.musicTrack = musicTrack;
block_32:
            gMusicInfo.occupied = FALSE;
            InitTrack(pTrack1, pHeader);
        }
    }

exit:
    gMusicInfo.occupied = FALSE;
}

/**
 * @brief 36c4 | 2c | To document
 * 
 */
void unk_36c4(void)
{
    struct TrackData* pTrack;

    if (gMusicInfo.unk_20 == 0)
        pTrack = sMusicTrackDataRom[0].pTrack;
    else
        pTrack = sMusicTrackDataRom[1].pTrack;

    StopMusicOrSound(pTrack);
}

/**
 * @brief 36f0 | 3c | Fades music using the provided timer
 * 
 * @param timer Fade timer
 */
void FadeMusic(u16 timer)
{
    struct TrackData* pTrack;
    
    if (gMusicInfo.unk_20 == 0)
        pTrack = sMusicTrackDataRom[0].pTrack;
    else
        pTrack = sMusicTrackDataRom[1].pTrack;
    
    if (timer != 0)
        ApplyMusicSoundFading(pTrack, timer);
    else
        StopMusicOrSound();
}

/**
 * @brief 372c | 4c | To document
 * 
 */
void unk_372c(u16 timer, u16 track, u8 priority)
{
    struct TrackData *pTrack;
    
    if (timer == 0)
    {
        PlayMusic(track, priority);
    }
    else
    {
        if (gMusicInfo.unk_20 == 0)
            pTrack = sMusicTrackDataRom[0].pTrack;
        else
            pTrack = sMusicTrackDataRom[1].pTrack;
        
        pTrack->musicTrack = track;
        pTrack->priority = priority;
        ApplyMusicSoundFading(pTrack, timer);
    }
}

/**
 * @brief 3778 | 130 | To document
 * 
 * @param arg0
 * @param arg1
 * @param arg2
 */
void unk_3778(u16 arg0, u16 arg1, u8 arg2)
{
    const u8 *pHeader;
    u32 flag1;
    u32 flag2;
    u32 flag3;
    struct TrackData *pTrack0;
    struct TrackData *pTrack1;
    s32 tmp = 0;

    if (gMusicInfo.occupied)
        return;
    
    gMusicInfo.occupied = TRUE;
    gMusicInfo.priority = arg2;
    pHeader = sSoundDataEntries[arg0].pHeader;
    
    if (arg2 != 0)
    {
        if (gMusicInfo.unk_20 == 0)
        {
            if (arg0 != gMusicInfo.musicTrack || !(sMusicTrackDataRom[0].pTrack->flags & 2))
            {
                if (sMusicTrackDataRom[1].pTrack->unk_1E & 2)
                    flag1 = FALSE;
                else
                    flag1 = TRUE;

                flag2 = FALSE;
            }
            else
            {
                flag2 = TRUE;
            }
        }
        else if (arg0 != gMusicInfo.unk_1E || !(sMusicTrackDataRom[1].pTrack->flags & 2))
        {
            if (sMusicTrackDataRom[0].pTrack->unk_1E & 2)
                flag1 = TRUE;
            else
                flag1 = FALSE;

            flag2 = FALSE;
        }
        else
        {
            flag2 = TRUE;
        }
    }
    else if (arg0 != gMusicInfo.musicTrack || !(sMusicTrackDataRom[0].pTrack->flags & 2))
    {
        flag1 = FALSE;
        flag2 = FALSE;
    }
    else
    {
        flag2 = TRUE;
    }

    if (!flag2)
    {
        if (flag1 == 0)
        {
            pTrack1 = sMusicTrackDataRom[0].pTrack;
            pTrack0 = sMusicTrackDataRom[1].pTrack;
            
            if ((pTrack1->flags & 0x1A) != 2 || pHeader != pTrack1->pHeader)
            {
                gMusicInfo.unk_20 = tmp;
                gMusicInfo.musicTrack = arg0;
                flag3 = TRUE;
            }
            else
            {
                flag3 = FALSE;
            }
        }
        else
        {
            pTrack1 = sMusicTrackDataRom[1].pTrack;
            pTrack0 = sMusicTrackDataRom[0].pTrack;
            
            if ((pTrack1->flags & 0x1A) != 2 || pHeader != pTrack1->pHeader)
            {
                gMusicInfo.unk_20 = 1;
                gMusicInfo.unk_1E = arg0;
                flag3 = TRUE;
            }
            else
            {
                flag3 = FALSE;
            }
        }

        if (flag3)
        {
            if (pTrack0->flags > 1 && !(pTrack0->unk_1E & 2))
                StopMusicOrSound(pTrack0);
            
            gMusicInfo.occupied = FALSE;
            InitFadingMusic(pTrack1, pHeader, arg1);
        }
    }

    gMusicInfo.occupied = FALSE;
}

/**
 * @brief 38a8 | 124 | To document
 * 
 */
void unk_38a8(u16 track, u8 arg1)
{
    const u8 *pHeader;
    struct TrackData *pTrack0;
    struct TrackData *pTrack1;
    u32 flag1;
    u32 flag2;

    if (gMusicInfo.occupied)
        return;
    
    gMusicInfo.occupied = TRUE;
    pHeader = sSoundDataEntries[track].pHeader;

    if (arg1 == 0)
    {
        unk_3190(1);
        unk_27a8();
    }

    if (arg1 == 2)
    {
        if (gMusicInfo.unk_20 == 0)
        {
            pTrack1 = sMusicTrackDataRom[0].pTrack;
            pTrack0 = pTrack1;
            gMusicInfo.unk_20 = 0;
            gMusicInfo.musicTrack = track;
        }
        else
        {
            pTrack1 = sMusicTrackDataRom[1].pTrack;
            pTrack0 = pTrack1;
            gMusicInfo.unk_20 = 1;
            gMusicInfo.unk_1E = track;
        }

        flag2 = FALSE;
        flag1 = TRUE;
    }
    else if (gMusicInfo.unk_20 == 0)
    {
        pTrack1 = sMusicTrackDataRom[1].pTrack;
        pTrack0 = sMusicTrackDataRom[0].pTrack;

        if ((pTrack1->flags & 0x1A) != 2 || pHeader != pTrack1->pHeader)
        {
            gMusicInfo.unk_20 = 1;
            if (arg1 != 0)
                gMusicInfo.unk_1E = track;

            flag2 = TRUE;
            flag1 = TRUE;
        }
        else
        {
            flag1 = FALSE;
        }
    }
    else
    {
        pTrack1 = sMusicTrackDataRom[0].pTrack;
        pTrack0 = sMusicTrackDataRom[1].pTrack;

        if ((pTrack1->flags & 0x1A) != 2 || pHeader != pTrack1->pHeader)
        {
            gMusicInfo.unk_20 = 0;
            if (arg1 != 0)
                gMusicInfo.musicTrack = track;
            
            flag2 = TRUE;
            flag1 = TRUE;
        }
        else
        {
            flag1 = FALSE;
        }
    }

    if (flag1)
    {
        if (flag2)
            pTrack1->queueFlags |= 0x80;
        
        if (arg1 != 0 && pTrack0->flags > 1)
            StopMusicOrSound(pTrack0);

        gMusicInfo.occupied = FALSE;
        InitTrack(pTrack1, pHeader);
    }

    gMusicInfo.occupied = FALSE;
}

/**
 * @brief 39cc | bc | To document
 * 
 */
void unk_39cc(void)
{
    struct TrackData *pTrack0;
    struct TrackData *pTrack1;
    u16 track;
    const u8* pHeader;

    if (gMusicInfo.occupied)
        return;

    gMusicInfo.occupied = TRUE;
    unk_3338(1);

    if (gMusicInfo.unk_20 == 0)
    {
        pTrack0 = sMusicTrackDataRom[1].pTrack;
        pTrack1 = sMusicTrackDataRom[0].pTrack;
        gMusicInfo.unk_20 = 1;
        track = gMusicInfo.unk_1E;
    }
    else
    {
        pTrack0 = sMusicTrackDataRom[0].pTrack;
        pTrack1 = sMusicTrackDataRom[1].pTrack;
        gMusicInfo.unk_20 = 0;
        track = gMusicInfo.musicTrack;
    }

    if (pTrack1->flags > 1)
        StopMusicOrSound(pTrack1);

    pHeader = sSoundDataEntries[track].pHeader;
    gMusicInfo.occupied = FALSE;
    InitTrack(pTrack0, pHeader);

    if (gMusicInfo.unk_2 != 0)
        SoundPlay(gMusicInfo.unk_2);

    if (gMusicInfo.volumeDownFlag & 0x80)
    {
        unk_2d90(sMusicTrackDataRom[0].pTrack, 0xFFFF, 0x48);
        unk_2d90(sMusicTrackDataRom[1].pTrack, 0xFFFF, 0x48);
        unk_2d90(sMusicTrackDataRom[7].pTrack, 0xFFFF, 0x48);
    }
    
    gMusicInfo.occupied = FALSE;
}

/**
 * @brief 3a88 | 3c | Identical to FadeMusic
 * 
 * @param timer Fade timer
 */
void FadeMusic_2(u16 timer)
{
    struct TrackData *pTrack;

    if (gMusicInfo.unk_20 == 0)
        pTrack = sMusicTrackDataRom[0].pTrack;
    else
        pTrack = sMusicTrackDataRom[1].pTrack;

    if (timer != 0)
        ApplyMusicSoundFading(pTrack, timer);
    else
        StopMusicOrSound();
}

/**
 * @brief 3ac4 | 58 | To document
 * 
 */
void unk_3ac4(void)
{
    struct TrackData *pTrack;
    u16 track;
    const u8* pHeader;

    if (gMusicInfo.occupied)
        return;

    gMusicInfo.occupied = TRUE;
    
    if (gMusicInfo.unk_20 == 0)
    {
        pTrack = sMusicTrackDataRom[0].pTrack;
        gMusicInfo.unk_20 = 0;
        track = gMusicInfo.musicTrack;
    }
    else
    {
        pTrack = sMusicTrackDataRom[1].pTrack;
        gMusicInfo.unk_20 = 1;
        track = gMusicInfo.unk_1E;
    }

    pHeader = sSoundDataEntries[track].pHeader;
    gMusicInfo.occupied = FALSE;
    InitTrack(pTrack, pHeader);

    gMusicInfo.occupied = FALSE;
}

/**
 * @brief 3b1c | 5c | To document
 * 
 * @param sound Sound ID
 */
void SoundPlay_3b1c(u16 sound)
{
    struct TrackData *pTrack;
    const u8* pHeader;
    
    if (gMusicInfo.occupied)
        return;

    gMusicInfo.occupied = TRUE;

    if (gMusicInfo.unk_20 == 0)
        pTrack = sMusicTrackDataRom[1].pTrack;
    else
        pTrack = sMusicTrackDataRom[0].pTrack;

    pHeader = sSoundDataEntries[sound].pHeader;
    gMusicInfo.occupied = FALSE;
    InitTrack(pTrack, pHeader);
    pTrack->unk_1E |= 2;
    
    gMusicInfo.occupied = FALSE;
}

/**
 * @brief 3b78 | 5c | To document
 * 
 * @param sound Sound ID
 */
void unk_3b78(u16 sound)
{
    struct TrackData *pTrack;
    const u8* pHeader;
    
    if (gMusicInfo.occupied)
        return;

    gMusicInfo.occupied = TRUE;

    if (gMusicInfo.unk_20 == 0)
        pTrack = sMusicTrackDataRom[1].pTrack;
    else
        pTrack = sMusicTrackDataRom[0].pTrack;

    if (pTrack->flags == 2)
        pTrack = sMusicTrackDataRom[5].pTrack;

    pHeader = sSoundDataEntries[sound].pHeader;
    gMusicInfo.occupied = FALSE;
    InitTrack(pTrack, pHeader);
    
    gMusicInfo.occupied = FALSE;
}

/**
 * @brief 3bd4 | 40 | To document
 * 
 * @param sound Sound ID
 * @param arg1
 */
void unk_3bd4(u16 sound, u8 arg1)
{
    if (sound < MUSIC_COUNT)
    {
        if (arg1 == 0)
            PlayMusic(sound, 1);
    }
    else
    {
        if (arg1 == 0)
        {
            if (sound >= SOUND_AA && sound <= SOUND_B3)
                SoundPlay_3b1c(sound);
            else
                SoundPlay(sound);
        }
    }
}

/**
 * @brief 3c14 | 20 | To document
 * 
 */
void unk_3c14(u16 sound, u8 arg1)
{
    if (sound < MUSIC_COUNT)
    {
        if (arg1 == 0)
            unk_36c4();
    }
    else
    {
        SoundStop(sound);
    }
}

/**
 * @brief 3c34 | 50 | Decreases music volume
 * 
 */
void DecreaseMusicVolume(void)
{
    unk_3190(0);
    
    gMusicInfo.volumeDownFlag |= 0x81;

    unk_2d90(sMusicTrackDataRom[0].pTrack, USHORT_MAX, (u16)gUnk_Audio0x50);
    unk_2d90(sMusicTrackDataRom[1].pTrack, USHORT_MAX, (u16)gUnk_Audio0x50);
    unk_2d90(sMusicTrackDataRom[7].pTrack, USHORT_MAX, (u16)gUnk_Audio0x50);
}

/**
 * @brief 3c84 | 50 | Resets music volume
 * 
 */
void ResetMusicVolume(void)
{
    unk_2d90(sMusicTrackDataRom[0].pTrack, USHORT_MAX, 0x100);
    unk_2d90(sMusicTrackDataRom[1].pTrack, USHORT_MAX, 0x100);
    unk_2d90(sMusicTrackDataRom[7].pTrack, USHORT_MAX, 0x100);

    gMusicInfo.volumeDownFlag = gMusicInfo.volumeDownFlag & 0x7F | 2;
    unk_3338(0);
}

/**
 * @brief 3cd4 | 28 | To document
 * 
 */
void unk_3cd4(u16 sound)
{
    if (gMusicInfo.occupied)
        return;
    
    gMusicInfo.occupied = TRUE;
    gMusicInfo.unk_2 = sound;
    SoundPlay(sound);

    gMusicInfo.occupied = FALSE;
}

/**
 * @brief 3cfc | 2c | To document
 * 
 */
void unk_3cfc(void)
{
    if (gMusicInfo.occupied)
        return;

    gMusicInfo.occupied = TRUE;
    gMusicInfo.unk_2 = 0;
    ApplyMusicSoundFading(sMusicTrackDataRom[7].pTrack, CONVERT_SECONDS(.5f));

    gMusicInfo.occupied = FALSE;
}

/**
 * @brief 3d28 | 40 | Plays the sound for a character appearing during a navigation
 * conversation depending on the speaker
 * 
 * @param unused Unused
 * @param speaker Speaker
 */
void PlayCharacterAppearingSound(u8 unused, u8 speaker)
{
    switch (speaker)
    {
        case 0x1:
            SoundPlayNotAlreadyPlaying(SOUND_CHARACTER_APPEARING_ADAM);
            break;

        case 0x21:
            SoundPlayNotAlreadyPlaying(SOUND_CHARACTER_APPEARING_SAMUS);
            break;

        case 0x41:
            SoundPlayNotAlreadyPlaying(SOUND_CHARACTER_APPEARING_FEDERATION);
            break;
    }
}
