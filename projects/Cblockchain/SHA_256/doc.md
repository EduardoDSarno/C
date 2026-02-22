The currently implementation of the SHA 256 is divided into 3 steps

1- padding/processing the message 
2- Message Schedule
3- Compression Function (64 rounds)

## 1
- On steps one we used the methodology outlines in the simulation demonstraded in the link https://sha256algorithm.com/

The enconding message process envolves at it first step transforming the message mostly often given in text to binary 
each can be found in our encode function inside sh256.c file in the encode_message function first loop.
After enconding this message you append 1 (line 69). Then you have to get the lenght of the message and trasnform that
to binary, put inside a 64 bit block of 'bits' and append in the end of the Block. Finally you have to add in between the message from step 1 and step 3, 0's.

The code for now is really self explanatory is not that hard to understand we used calloc to alloc memory and initialize the message dynamicallu based on the size of it so we can make the correct quantity of blocks nescessary to perform the hashing
than we used a couple of helper funcitons to transform text and int into binary and append them to the block using loops.

We used another very broken down and self explanatory help functions to do the math to find the numbers of 0's needed for the block, I added some print statements as well for debug and visualization. Also I updated the header to have my prototypes so, everything is more organized and labled.

## 2
- On step 2 we take the padded message (the blocks array) and we break it into 512-bit blocks (chunks).
This is done in the message_schedule function inside sh256.c. Basically we loop from 0..num_blocks-1 and for each block we create a local array of words:

- W[0..63] (64 words) each word is 32 bits (uint32_t).

The first part is filling W[0..15]. Because each 512-bit block = 16 chunks * 32 bits.
So we take 32 bits at a time from the block and convert it to uint32 using bits_to_u32_be(). This helper is big-endian bit order meaning first bit is the MSB. This is inside expand_message_schedule first loop.

After that we expand W[16..63] with the math formula from the standard:
W[t] = sigma1(W[t-2]) + W[t-7] + sigma0(W[t-15]) + W[t-16]
We created sigma0 and sigma1 helpers and we also created constants on the header for the offsets to avoid magic numbers. At the end of expand_message_schedule we always have 64 numbers for this block.

## 3
- On step 3 we do the compression function (64 rounds). The way this works is:
we have the initial SHA state constants H0..H7 (8 words) and they are defined in the header (SHA256_H_INIT).
Inside message_schedule we copy that initial constants to out_H so it becomes our "hash so far" across blocks.

For each block after we get the words W from step 2 we call compress_message_schedule(out_H, words).
This compression uses a temp array v[8] to copy the state, so we dont break the state while we are doing the rounds.
Then we loop t = 0..63 (64 rounds). Each round uses:
- W[t] (the schedule word)
- SHA256_K[t] (the round constant table, also defined in the header)
- BIG_SIGMA0 / BIG_SIGMA1 and also Ch and Maj helpers
and we calculate T1 and T2 and shift the v array each round.

After the 64 rounds we add v back into out_H (out_H[i] += v[i]) so now the state is updated for the next block.
When all blocks are finished, out_H is the final digest result but still in 8 words format.

## Final output (hex string)
To print the final SHA like normal tools we convert H[0..7] into a 64 hex char string.
This is done by sha256_hex() which takes the 8 words and prints 8 hex chars per word (%08x) and concatenates into 64 chars + null terminator.
We also created constants in the header for the sizes (SHA_OUT_HEX_RESULT_LENGTH etc) so no magic numbers.
