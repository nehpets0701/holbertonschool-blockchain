#include "blockchain.h"

/**
*hash_matches_difficulty-checks if hash matches difficulty
*Return:0/1
*@hash:hash
*@difficulty:difficulty
*/
int hash_matches_difficulty(uint8_t const hash[SHA256_DIGEST_LENGTH],
					uint32_t difficulty)
{
	uint32_t i, mod;

	mod = difficulty & 7;
	difficulty -= mod;
	difficulty /= 8;
	for (i = 0; i < difficulty; ++i)
	{
		if (hash[i] != 0)
			return (0);
	}
	if (hash[difficulty] >> (8 - mod))
		return (0);
	return (1);
}
