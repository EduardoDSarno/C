
#ifndef block_h
#define block_h
#include "transaction.h"
#include "SHA_256/sha256.h"
#include <stdlib.h>
#include <string.h>

#define SHA_OUTPUT_BYTES 32

typedef struct {
    int index;
    size_t timestamp;
    unsigned char *data;
    uint8_t previous_hash[SHA_OUTPUT_BYTES];
    int nounce;
    const Transaction *transactions;
    size_t transactions_count;
}Block;

Block init(int index,
           size_t timestamp,
           unsigned char *data,
           const uint8_t previous_hash[SHA_OUTPUT_BYTES],
           int nounce,
           const Transaction *transactions,
           size_t transactions_count);




#endif