#include "hblk_crypto.h"

/**
*ec_verify-verifies a signature
*Return:0/1
*@key:ec struct
*@msg:message
*@msglen:message length
*@sig:signature
*/
int ec_verify(EC_KEY const *key, uint8_t const *msg, size_t msglen,
					sig_t const *sig)
{
	if (!key || !msg || !sig)
		return (0);
	if (ECDSA_verify(0, msg, (int)msglen,
					  sig->sig, sig->len, (EC_KEY *)key) < 1)
		return (0);
	return (1);
}
