#ifndef BLOCK_H
#define BLOCK_H

#include "types.h"

#include "constants/block.h"
#include "structs/block.h"

bools32 BlockCheckClipdataAction(struct ClipdataBlockData* pClipBlock);
bools32 BlockDestroyNonReformBlock(struct ClipdataBlockData* pClipBlock);
void BlockDestroyBombChainBlock(struct ClipdataBlockData* pClipBlock);
void BlockDestroySingleBreakableBlock(struct ClipdataBlockData* pClipBlock);
void BlockDestroySquareBlock(struct ClipdataBlockData* pClipBlock);
bools32 BlockStoreSingleNeverReformBlock(u16 xPosition, u16 yPosition);
void BlockRemoveNeverReformBlocks(void);
bools32 BlockStoreBrokenNonReformBlock(u16 xPosition, u16 yPosition, BlockType type);
bools32 BlockCheckRevealOrDestroyNonBombBlock(struct ClipdataBlockData* pClipBlock);
bools32 BlockApplyClipdataAction(u16 yPosition, u16 xPosition, u16 trueClip);
bools32 BlockUpdateMakeSolidBlock(boolu8 makeSolid, u16 xPosition, u16 yPosition);
bools32 BlockApplySpeedBoosterScrewAttackDamage(u16 xPosition, u16 yPosition, u16 action);
void BlockUpdateBrokenBlocks(void);
void BlockUpdateNonReformBlocksAnimation(void);
void BlockRedrawBrokenBlocks(void);
void BlockUpdateBrokenBlockAnimation(struct BrokenBlock* pBlock, u8 index);
bools32 BlockStoreBrokenReformBlock(BlockType type, u16 xPosition, u16 yPosition, boolu8 advanceStage);
bools32 BlockStoreRevealedBlock(BlockType type, u16 xPosition, u16 yPosition);
bools32 BlockCheckSamusInReformingBlock(u16 yPosition, u16 xPosition);
bools32 BlockStartBombChain(BombChainType type, u16 xPosition, u16 yPosition);
void BlockUpdateBombChains(void);
void BlockCheckStartNewSubBombChain(SubBombChainRequest type, u8 xPosition, u8 yPosition);

#endif /* BLOCK_H */
