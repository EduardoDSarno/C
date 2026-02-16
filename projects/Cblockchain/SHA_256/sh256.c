#include "sha256.h"
//#include <cstring>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>


int main(){

    // step 1
    unsigned char message[] = "HellomynameisEduardo";
    size_t message_len_bytes = strlen((const char *)message);

    // get initial values with helpers
    size_t n_bits = message_size_bits(message_len_bytes);
    size_t k = find_number_of_zeros_needed(n_bits);
    size_t total_bits = padded_message_size_bits(n_bits, k);
    size_t num_blocks = block_count_from_total_bits(total_bits);

    // initialize to zero
    uint8_t *blocks = calloc(total_bits, sizeof(uint8_t));
    if (blocks == NULL) {
        fprintf(stderr, "Failed to allocate %zu bits buffer\n", total_bits);
        return 1;
    }

    printf("message bits: %zu\n", n_bits);
    printf("k (zero bits): %zu\n", k);
    printf("total bits: %zu\n", total_bits);
    printf("num blocks: %zu\n", num_blocks);

    if (encode_message(message, message_len_bytes, blocks, total_bits) != 0) {
        free(blocks);
        return 1;
    }

    print_bits(blocks, total_bits);
    free(blocks);
    return 0;
}

// stopped here
// void expand_message_schedule(const uint8_t block_bits[SIZE_BLOCK_BITS], 
//                                    uint32_t W[NUMBER_OF_WORDS_ARRAY])
// {
//     int chunck = 1;
//     for(int i = 0; i <= SIZE_BLOCK_BITS; i += chunck*NUMBER_OF_WORDS_ARRAY)
// }

// this will make sure we break down the number of blocks we have and
// loops through each one of them inside the blocks array
void message_schedule(const uint8_t *blocks, size_t num_blocks)
{
    
    for (size_t block_index = 0; block_index < num_blocks; block_index++) 
    {
        size_t block_start = block_index * SIZE_BLOCK_BITS;
        const uint8_t *individual_block = blocks + block_start;
        uint32_t words[NUMBER_OF_WORDS_ARRAY]; // NUMBER_OF_BIT_PER_WORD_ARRAY array words
    
        // Now block_ptr[0..511] is exactly this one block
        expand_message_schedule(individual_block, words);
    }
}



/* This function is a the one responsible for performing the padding of */
int encode_message(const unsigned char message[], size_t message_len_bytes, uint8_t block_bits[], size_t total_bits){
    size_t j = 0;
    size_t message_bits = message_size_bits(message_len_bytes);
    size_t minimum_needed = message_bits + LAST_BIT_TO_APPEND + SIZE_MESSAGE_LENGHT_BLOCK_BIT;

    if (total_bits < minimum_needed) {
        fprintf(stderr, "total_bits (%zu) is too small, need at least %zu\n", total_bits, minimum_needed);
        return 1;
    }

    // step 1: Encode
    // the loop will go through every char inside the message
    for (size_t character_index = 0; character_index < message_len_bytes; character_index++)
    {
        if (j + CHAR_BYTE_SIZE_BITS > total_bits) {
            fprintf(stderr, "Bit buffer overflow while encoding message\n");
            return 1;
        }
        byte_to_bits(message[character_index], &block_bits[j]);
        j += CHAR_BYTE_SIZE_BITS; // move 8 positions so we don't overlap
    }
    //step 2:
    block_bits[j] = LAST_BIT_TO_APPEND; // appending 1 right after message bits

    // step 3 append the original message length at the end of the padded bitstream.
    append_size(block_bits, total_bits, message_bits);

    return 0;
}

void append_size(uint8_t block[], size_t block_size, uint64_t message_size){

    uint8_t message_size_value_bits[SIZE_MESSAGE_LENGHT_BLOCK_BIT];

    // make value_bits be our SIZE_LENGHT_BLOCK_BIT bit block of the decimal number
    value_to_bits( message_size,
                message_size_value_bits,
                   SIZE_MESSAGE_LENGHT_BLOCK_BIT);

    // apend value_bitsin the end of block[]
    size_t start_position = block_size - SIZE_MESSAGE_LENGHT_BLOCK_BIT;

    for(size_t i = 0; i < SIZE_MESSAGE_LENGHT_BLOCK_BIT; i++){
        block[start_position + i]= message_size_value_bits[i];
    }

}


void get_binary_from_int(unsigned int num, uint8_t out_bits[])
{
    value_to_bits((uint64_t)num, out_bits, sizeof(num) * INT_BYTE_SIZE_BITS);
}



// helper function to get decimal to bits
void value_to_bits(uint64_t value, uint8_t out_bits[], unsigned width)
{
    // Writes exactly `width` bits, MSB first.
    for (unsigned k = 0; k < width; k++) {
        unsigned shift = (width - 1U) - k;
        out_bits[k] = (uint8_t)((value >> shift) & 1U);
    }
}

void byte_to_bits(uint8_t value, uint8_t out_bits[CHAR_BYTE_SIZE_BITS])
{
    value_to_bits((uint64_t)value, out_bits, CHAR_BYTE_SIZE_BITS);
}

size_t message_size_bits(size_t message_len_bytes)
{
    return message_len_bytes * CHAR_BYTE_SIZE_BITS;
}

size_t find_number_of_zeros_needed(size_t message_bits)
{
    // k such that (message_bits + 1 + k) % 512 == 448
    size_t k = (SIZE_OF_BLOCK_BITS_WITHOUT_MESSAGE_LENGTH - ((message_bits + LAST_BIT_TO_APPEND) % SIZE_BLOCK_BITS) + SIZE_BLOCK_BITS) % SIZE_BLOCK_BITS;
    return k;
}

size_t padded_message_size_bits(size_t message_bits, size_t zero_bits)
{
    return message_bits + LAST_BIT_TO_APPEND + zero_bits + SIZE_MESSAGE_LENGHT_BLOCK_BIT;
}

size_t block_count_from_total_bits(size_t total_bits)
{
    return total_bits / SIZE_BLOCK_BITS;
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