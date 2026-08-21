#ifndef MUSIC_WRAPPERS_H
#define MUSIC_WRAPPERS_H

#include "structs/audio.h"

void Dma2IntrCode(void);
void RestartSound(void);
void unk_3190(u8 isInterrupting);
void unk_3338(u8 arg0);
void unk_3494(void);
void CheckSetNewMusicTrack(u16 musicTrack);
void CheckPlayNewMusicTrack(void);
void PlayMusic(u16 musicTrack, u8 priority);
void unk_36c4(void);
void FadeMusic(u16 timer);
void unk_372c(u16 timer, u16 track, u8 priority);
void unk_3778(u16 arg0, u16 arg1, u8 arg2);
void unk_38a8(u16 track, u8 arg1);
void unk_39cc(void);
void FadeMusic_2(u16 timer);
void unk_3ac4(void);
void SoundPlay_3b1c(u16 sound);
void unk_3b78(u16 sound);
void unk_3bd4(u16 sound, u8 arg1);
void unk_3c14(u16 sound, u8 arg1);
void DecreaseMusicVolume(void);
void ResetMusicVolume(void);
void unk_3cd4(u16 sound);
void unk_3cfc(void);
void PlayCharacterAppearingSound(u8 unused, u8 speaker);

#endif /* MUSIC_WRAPPERS_H */
