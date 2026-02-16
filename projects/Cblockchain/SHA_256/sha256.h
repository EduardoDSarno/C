#ifndef SHA256_H
#define SHA256_H

#include <stddef.h>
#include <stdint.h>

// In C we use ~ for complement A', ^ for XOR.
#define XOR(a,b)     a^b
#define AND(a,b)     (a & b)
#define OR(a,b)      (a | b)

#define CHAR_BYTE_SIZE_BITS 8
#define INT_BYTE_SIZE_BITS 8
#define CHAR_BYTE_LENGHT 7 // starting from 0

#define SIZE_BLOCK_BYTE 64
#define SIZE_MESSAGE_LENGHT_BLOCK_BIT 64
#define LAST_BIT_TO_APPEND 1

#define SIZE_BLOCK_BITS (SIZE_BLOCK_BYTE * CHAR_BYTE_SIZE_BITS)
#define SIZE_OF_BLOCK_BITS_WITHOUT_MESSAGE_LENGTH (SIZE_BLOCK_BITS - SIZE_MESSAGE_LENGHT_BLOCK_BIT)

// Words scheduler
#define NUMBER_OF_WORDS_ARRAY 64
#define NUMBER_OF_BIT_PER_WORD_ARRAY 32

void expand_message_schedule(const uint8_t block_bits[SIZE_BLOCK_BITS], uint32_t W[NUMBER_OF_WORDS_ARRAY]);
void message_schedule(const uint8_t *blocks, size_t num_blocks);

size_t message_size_bits(size_t message_len_bytes);
size_t find_number_of_zeros_needed(size_t message_bits);
size_t padded_message_size_bits(size_t message_bits, size_t zero_bits);
size_t block_count_from_total_bits(size_t total_bits);

int encode_message(const unsigned char message[], size_t message_len_bytes, uint8_t block_bits[], size_t total_bits);
void append_size(uint8_t block[], size_t block_size, uint64_t message_size);
void get_binary_from_int(unsigned int num, uint8_t out_bits[]);
void value_to_bits(uint64_t value, uint8_t out_bits[], unsigned width);
void byte_to_bits(uint8_t value, uint8_t out_bits[CHAR_BYTE_SIZE_BITS]);
void print_bits(const uint8_t block[], size_t block_size);

#endif // SHA256_H

