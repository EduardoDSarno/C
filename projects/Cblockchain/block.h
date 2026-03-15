
#ifndef block_h
#define block_h
#include "transaction.h"
#include "SHA_256/sha256.h"
#include <stdlib.h>
#include <string.h>

#define SHA_OUTPUT_BYTES 32

typedef struct {
    uint32_t index;
    uint64_t timestamp;
    uint8_t previous_hash[SHA_OUTPUT_BYTES];
    uint32_t nounce;
    const Transaction *transactions;
    size_t transactions_count;
}Block;

Block init(uint32_t index,
           uint64_t timestamp,
           const uint8_t previous_hash[SHA_OUTPUT_BYTES],
           uint32_t nounce,
           const Transaction *transactions,
           size_t transactions_count);




#endif