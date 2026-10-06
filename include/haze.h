#ifndef HAZE_H
#define HAZE_H

#include "types.h"

void HazeSetBackgroundEffect(void);
u8 HazeGetAtmosphericStabilizerValue(void);
void HazeTransferAndDeactivate(void);
void unk_6ee8c(void);
void HazeSetupCode(u8 hazeValue);
void HazeResetLoops(void);
void HazeCalculateGradient(void);
bools32 HazeProcess(void);
void Haze_Bg3(void);
void Haze_Bg3StrongWeak(void);
void Haze_Bg3NoneWeak(void);
void Haze_Bg3Bg2StrongWeakMedium(void);
void Haze_Bg0(void);
void Haze_Bg3Bg2Bg1(void);
bools32 Haze_PowerBombExpanding(void);
bools32 Haze_PowerBombRetracting(void);
void unk_6fca8(void);
void Haze_Bg3Y(void);
void unk_6fdd0(void);

#endif /* HAZE_H */
