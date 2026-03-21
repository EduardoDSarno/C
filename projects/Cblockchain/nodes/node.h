#include <stdint.h>
#include "../SHA_256/sha256.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include </opt/homebrew/include/secp256k1.h>



#define SIZE_PUB_KEY_BYTES 33
#define SIZE_PRIV_KEY_BYTES 32

uint8_t* generate_pub_key_helper(const uint8_t *priv_key, FILE *file);