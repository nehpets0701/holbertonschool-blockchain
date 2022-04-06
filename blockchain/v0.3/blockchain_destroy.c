#include "blockchain.h"

/**
* blockchain_destroy-deletes the chain
* @blockchain: victim
*/
void blockchain_destroy(blockchain_t *blockchain)
{
	if (!blockchain)
		return;
	llist_destroy(blockchain->chain, 1, (node_dtor_t)block_destroy);
	llist_destroy(blockchain->chain, 1, NULL);
	free(blockchain);
}
