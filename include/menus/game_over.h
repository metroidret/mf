#ifndef GAME_OVER_H
#define GAME_OVER_H

#include "types.h"

boolu32 GameOverHandler(void);
void GameOverInit(void);
boolu32 GameOverAfterOptionDelay(void);
u8 GameOverSetupOam(u8 type, s16 xPosition, s16 yPosition);
void GameOverProcessCursor(struct GameOverOam* pOam);
void unk_9e2cc(struct GameOverOam* pOam);
void GameOverResetOam(u8 slot);
void GameOverProcessOam(void);
void GameOverDrawAllOam(void);
void GameOverDrawOam(struct GameOverOam* pOam);
void GameOverGetPositionOfOamByType(u8 type, s16* pXPosition, s16* pYPosition);
void GameOverVblank(void);
void unk_9e58c(void);

#endif /* GAME_OVER_H */
