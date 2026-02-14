#include "sha256.h"
//#include <cstring>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

unsigned char encode_message(unsigned char message[]);

// will append the size of the message into the binary messgae
void get_binary_from_int(unsigned int num, uint8_t out_bits[]);

// Generic helper: write `width` bits (MSB->LSB) into out_bits[0..width-1].
void value_to_bits(uint64_t value, uint8_t out_bits[], unsigned width);

// Convenience wrapper for a single byte.
void byte_to_bits(uint8_t value, uint8_t out_bits[CHAR_BYTE_SIZE]);

// helper to print the bits for debugging
void print_bits(const uint8_t block[], size_t block_size);

int main(){
    unsigned char message[] = "HellomynameisEduardo";
    encode_message(message);
    return 0;
}

unsigned char encode_message(unsigned char message[]){
    
    uint8_t block[SIZE_BLOCK_BITS] = {0};
    size_t j = 0;

    // step 1: Encode
    // the loop will go through every char inside the message
    for (size_t character_index = 0; message[character_index] != '\0'; character_index++)
    {
        byte_to_bits(message[character_index], &block[j]);
        j += CHAR_BYTE_SIZE; // move 8 positions so we don't overlap
    }
    //step 2:
    block[j] = LAST_BIT_TO_APPEND; // appending 1 right after message bits

    // Debug: print only what we've filled so far (message bits + the '1' bit).
    print_bits(block, j + 1);

    return 0;
}


void get_binary_from_int(unsigned int num, uint8_t out_bits[])
{
    value_to_bits((uint64_t)num, out_bits, sizeof(num) * 8);
}








// helper function to 
void value_to_bits(uint64_t value, uint8_t out_bits[], unsigned width)
{
    // Writes exactly `width` bits, MSB first.
    for (unsigned k = 0; k < width; k++) {
        unsigned shift = (width - 1U) - k;
        out_bits[k] = (uint8_t)((value >> shift) & 1U);
    }
}

void byte_to_bits(uint8_t value, uint8_t out_bits[CHAR_BYTE_SIZE])
{
    value_to_bits((uint64_t)value, out_bits, CHAR_BYTE_SIZE);
}



// Will print the messgae in bits 
// for debugging
void print_bits(const uint8_t block[], size_t block_size)
{
    for (size_t i = 0; i < block_size; i++) {
        putchar((int)('0' + block[i]));
    }
    puts("");
}