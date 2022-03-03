#include "hblk_crypto.h"

/**
*ec_save-saves key pair to a file
*Return: 0/1
*@key:key pait
*@folder:where to put it
*/
int ec_save(EC_KEY *key, char const *folder)
{
	char file[512] = {0};
	FILE *fp;
	struct stat st = {0};

	if (!key || !folder)
		return (0);
	if (stat(folder, &st) == -1)
	{
		if (mkdir(folder, 0700) == -1)
			return (0);
	}
	sprintf(file, "%s/%s", folder, PRI_FILENAME);
	fp = fopen(file, "w");
	if (!fp)
		return (0);
	if (!PEM_write_ECPrivateKey(fp, key, NULL, NULL, 0, NULL, NULL))
		return (0);
	fclose(fp);
	sprintf(file, "%s/%s", folder, PUB_FILENAME);
	fp = fopen(file, "w");
	if (!fp)
		return (0);
	if (!PEM_write_EC_PUBKEY(fp, key))
		return (0);
	fclose(fp);
	return (1);
}
