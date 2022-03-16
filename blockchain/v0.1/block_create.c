#include "blockchain.h"

/**
*block_create-creates a block
*Return: new block
*@prev:previous block
*@data:block data
*@data_len:length of data
*/
block_t *block_create(block_t const *prev, int8_t const *data,
					  uint32_t data_len)
{
	block_t *block;
	uint32_t maxLen = data_len > BLOCKCHAIN_DATA_MAX ?
		   BLOCKCHAIN_DATA_MAX : data_len;

	if (!prev || !data)
		return (NULL);
	block = calloc(1, sizeof(*block));
	if (!block)
		return (NULL);

	memcpy(block->data.buffer, data, maxLen);
	block->data.len = maxLen;

	memcpy(block->info.prev_hash, prev->hash, SHA256_DIGEST_LENGTH);
	block->info.index = prev->info.index + 1;
	block->info.timestamp = (uint64_t)time(NULL);
	return (block);
}
