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
