#include "block.h"
#include <stddef.h>


// function to initilize block, it will return block
// instaed of void
Block init(
    uint32_t index,
    uint64_t timestamp,
    const uint8_t previous_hash[SHA256_DIGEST_BYTES],
    uint32_t nounce,
    const Transaction *transactions,
    size_t transactions_count)
{
    Block block;
    block.index = index;
    block.timestamp = timestamp;

    // copies bytes into the array, no need to assign it
    memcpy(block.previous_hash, previous_hash, SHA256_DIGEST_BYTES);

    block.nounce = nounce;
    block.transactions = transactions;
    block.transactions_count = transactions_count;

    return block;
}

// int sha256_hash_digest(const uint8_t *message, size_t message_len_bytes, uint8_t out_digest[SHA256_DIGEST_BYTES])

char hash(Block block)
{
    (void)block;
    //const uint8_t message[] = ;
    //char hex[SHA_OUT_HEX_RESULT_LENGTH];

   // size_t *message_len_bytes = malloc(sizeof(message) * 8);
   // sha256_hash_hex((const uint8_t *)data_ptr, data_len, hex);
    return 0;
}
