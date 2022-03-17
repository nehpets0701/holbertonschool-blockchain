#include "blockchain.h"

/**
* block_mine-mine block
* @block:block to mine
*/
void block_mine(block_t *block)
{
	block->info.nonce = 0;
	while (hash_matches_difficulty(block->hash, block->info.difficulty) == 0)
	{
		if (!block_hash(block, block->hash))
			return;
		++block->info.nonce;
	}
}
