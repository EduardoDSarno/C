
#ifndef block_h
#define block_h
#include "transaction.c"

typedef struct {
    int index;
    long timestamp;
    char data;
    int *previous_block_hash;
    int nounce;
    struct Transaction transactions;
}Block;

Block init(int index, long timestamp,char data, int *previous_block_address,                
    int nounce, struct Transaction transactions);


#endif

// function to initilize block, it will return block
// instaed of void
Block init(int index,
    long timestamp,
    char data,
    int *previous_block_hash,
    int nounce,
    struct Transaction transactions)
{
Block block;
block.index = index;
block.timestamp = timestamp;
block.data = data;
block.previous_block_hash = previous_block_hash;
block.nounce = nounce;
block.transactions = transactions;


return block;
}

char hash(Block index, 
        Block data, 
        Block nounce, 
        Block preivous_block_hash)
{
    
}

