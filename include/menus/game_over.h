#ifndef GAME_OVER_H
#define GAME_OVER_H

#include "types.h"

MAKE_ENUM(u8, GameOverStage) {
	GAME_OVER_STAGE_WAIT_FOR_SELECTION,
	GAME_OVER_STAGE_DELAY_AFTER_SELECTION
};

MAKE_ENUM(u8, GameOverOption) {
	GAME_OVER_OPTION_NONE,
	GAME_OVER_OPTION_RETURN_TO_GAME,
	GAME_OVER_OPTION_GO_TO_TILE
};

MAKE_ENUM(u8, GameOverOamType) {
	GAME_OVER_OAM_TYPE_NONE,
	GAME_OVER_OAM_TYPE_CURSOR,
	GAME_OVER_OAM_TYPE_UNUSED
};

u32 GameOverHandler(void);
void GameOverInit(void);
boolu32 GameOverAfterOptionDelay(void);
u8 GameOverSetupOam(GameOverOamType type, s16 xPosition, s16 yPosition);
void GameOverProcessCursor(struct GameOverOam* pOam);
void unk_9e2cc(struct GameOverOam* pOam);
void GameOverResetOam(u8 slot);
void GameOverProcessOam(void);
void GameOverDrawAllOam(void);
void GameOverDrawOam(struct GameOverOam* pOam);
void GameOverGetPositionOfOamByType(GameOverOamType type, s16* pXPosition, s16* pYPosition);
void GameOverVBlank(void);
void GameOverInitVBlank(void);

#endif /* GAME_OVER_H */
