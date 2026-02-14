#define SHA256_ES


// in C we use ~ for complement A' 
// ^ for XOR
#define XOR(a,b)     a^b
#define AND(a,b)    (a & b)
#define OR(a,b)     (a | b)
#define CHAR_BYTE_SIZE 8
#define INT_BYTE_SIZE 8
#define CHAR_BYTE_LENGHT 7 // starting from 0
#define SIZE_BLOCK_BYTE 64

#define SIZE_BLOCK_BITS SIZE_BLOCK_BYTE*CHAR_BYTE_SIZE 
#define MESSAGE_LENGTH_SIZE_BLOCK
#define LAST_BIT_TO_APPEND 1

