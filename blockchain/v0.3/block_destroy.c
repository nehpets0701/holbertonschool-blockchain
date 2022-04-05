#include "blockchain.h"

/**
* block_destroy-destroys block
* @block:victim
*/
void block_destroy(block_t *block)
{
	free(block);
}
