#ifndef SCROLL_H
#define SCROLL_H

#include "types.h"
#include "structs/scroll.h"

void ScrollProcess(struct RawCoordsX* pCoords);
void ScrollScreen(u16 screenX, u16 screenY);
s32 ScrollProcessX(struct Scroll* pScroll, struct RawCoordsX* pCoords);
s32 ScrollProcessY(struct Scroll* pScroll, struct RawCoordsX* pCoords);
void ScrollLoad(void);
void ScrollUpdateCurrent(void);
void ScrollProcessGeneral(void);
void ScrollWithNoScrolls(struct RawCoordsX* coords);
void ScrollWithNoScrollsX(struct RawCoordsX* coords);
void ScrollFrontWideComputeBase(struct RawCoordsX* coords);
void ScrollFrontWideComputeTarget(struct RawCoordsX* coords);
void ScrollFrontWideApplyVelocity(void);
void ScrollUpdateEffectAndHazePosition(struct RawCoordsX* coords);
void ScrollAutoBg0(void);
u32 ScrollGetBg3Scroll(void);
void ScrollBg3(void);
void ScrollSetInitialBg3Position(void);
void ScrollAutoBg3(void);
void ScrollNoClipUnlockedCamera(struct RawCoordsX* pCoords);
void ScrollNightmareShadow(void);
void ScrollSr388Planet(void);

#endif /* SCROLL_H */
