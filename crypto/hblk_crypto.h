#ifndef HBLK_CRYPTO_H
#define HBLK_CRYPTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>
#include <openssl/sha.h>
#include <openssl/evp.h>
#include <openssl/ec.h>
#include <openssl/pem.h>
#include <openssl/bio.h>
#include <sys/types.h>
#include <sys/stat.h>

uint8_t *sha256(int8_t const *s, size_t len,
					uint8_t digest[SHA256_DIGEST_LENGTH]);

#endif
