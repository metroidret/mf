#ifndef TEXT_H
#define TEXT_H

#include "types.h"

u8 GetCharacterWidth(u16 idx);

void DrawLocationTextCharacters(u8 param_1, u16** ppText);

void DrawLocationText(u8 locationText, u8 gfxSlot);
void TextDrawMessageBanner(u8 messageId, u8 gfxSlot, u8 stage);
void TextDisplayMessage(u8 gfxSlot, u8 stage);
void TextClearGraphics(u8 action);

#endif /* TEXT_H */
