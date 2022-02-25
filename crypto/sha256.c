#include "hblk_crypto.h"

/**
*sha256-hashes a string
*Return:hash of a string, stored in digest
*@s:input
*@len:length of s
*@digest:storage location
*/
uint8_t *sha256(int8_t const *s, size_t len,
					uint8_t digest[SHA256_DIGEST_LENGTH])
{
	if (!digest || !s)
		return (NULL);
	return (SHA256((void *)s, len, digest));
}
