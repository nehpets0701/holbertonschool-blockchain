#include "hblk_crypto.h"

/**
*ec_to_pub-gets public key from EC_KEY
*Return:pub, containing the public key
*@key:EC_KEY
*@pub:buffer
*/
uint8_t *ec_to_pub(EC_KEY const *key, uint8_t pub[EC_PUB_LEN])
{
	const EC_POINT *pubKey;
	const EC_GROUP *group;

	if (!key || !pub)
		return (NULL);
	pubKey = EC_KEY_get0_public_key(key);
	if (!pubKey)
		return (NULL);
	group = EC_KEY_get0_group(key);
	if (!group)
		return (NULL);
	if (!EC_POINT_point2oct(group, pubKey,
							POINT_CONVERSION_UNCOMPRESSED, pub, EC_PUB_LEN, NULL))
		return (NULL);
	return (pub);
}
