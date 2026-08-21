#ifndef AUDIO_WRAPPERS_H
#define AUDIO_WRAPPERS_H

#include "constants/audio.h"

#include "structs/audio.h"

extern void CallSoundCodeA(void);
extern void CallSoundCodeB(void);
extern void CallSoundCodeC(void);

void InitializeAudio(void);
void DoSoundAction(u32 action);
void SetupSoundTransfer(void);
void SoundPlay(u16 sound);
void SoundStop(u16 sound);
void StopAllMusicAndSounds(void);
void unk_27a8(void);
void FadeAllSounds(u16 timer);
void SoundPlayNotAlreadyPlaying(u16 sound);
void unk_2894(u16 sound);
void unk_28fc(u16 sound);
void unk_2938(struct TrackData* pTrack);
void unk_2974(void);
void ApplyMusicSoundFading(struct TrackData* pTrack, u16 timer);
void ApplyRawMusicSoundFading(struct TrackData* pTrack, u16 timer);
void unk_2a40(struct TrackData* pTrack);
void PlayFadingSound(u16 sound, u16 timer);
void InitFadingMusic(struct TrackData* pTrack, const u8* pHeader, u16 timer);
void unk_2b6c(struct TrackData* pTrack, u16 timer);
void unk_2ba4(struct TrackData* pTrack);
void unk_2c38(u16 musicTrack1, u16 musicTrack2, u16 timer);
void unk_2d60(struct TrackData* pTrack, u16 param_2);
void unk_2d90(struct TrackData* pTrack, u16 variablesMask, u16 param_3);
void unk_2dec(struct TrackData* pTrack, u16 variablesMask, u16 param_3);
void unk_2e48(struct TrackData* pTrack, u16 variablesMask, u8 param_3);
void unk_2e94(struct TrackData* pTrack, u16 variablesMask, u8 param_3);
void unk_2ed8(struct TrackData* pTrack, u16 variablesMask, u8 param_3);

#endif /* AUDIO_WRAPPERS_H */
