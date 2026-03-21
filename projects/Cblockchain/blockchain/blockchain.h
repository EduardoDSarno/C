#include <stdio.h>
#include <stdlib.h>
#include "../block/block.h"
#include "../SHA_256/sha256.h"
#include <time.h>
#include <stdint.h>
#include <string.h>
#include "../hash/hash.h"

typedef struct BlockChain{

    
    Block * genesis_block;
    Block * last_block;
    Block **blocks; // array of blocks
    size_t block_count;
    

    // pointer to an array of SHA256_DIGEST_BYTES bytes
    uint8_t (* hash_array) [SHA256_DIGEST_BYTES]; 

} BlockChain;

BlockChain *init();
int inser_block(Block * new_block, BlockChain* blockchain);
Block* get_block(size_t index, const BlockChain *blockchain );