#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <stdint.h>
#include <stdlib.h>

#define SIGNATURE_LENGTH_BYTES 64
#define ADDRESS_LENGTH_BYTES 32

// Serialized sizes (for wire/disk format)
#define TX_TIMESTAMP_BYTES 8   // uint64_t
#define TX_AMOUNT_BYTES 8     // uint64_t
#define TRANSACTION_SERIALIZED_SIZE \
    (ADDRESS_LENGTH_BYTES * 2 + SIGNATURE_LENGTH_BYTES + TX_TIMESTAMP_BYTES + TX_AMOUNT_BYTES)

// Minimal transaction model (learning version)
typedef struct Transaction {
    char sender_address[ADDRESS_LENGTH_BYTES];
    char receiver_address[ADDRESS_LENGTH_BYTES];
    char signature[SIGNATURE_LENGTH_BYTES];
    uint64_t timestamp;
    uint64_t amount;
} Transaction;

#endif

