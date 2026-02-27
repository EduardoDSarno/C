#include "transaction.h"

struct Transaction{
    char sender_address[ADDRESS_LENGTH_BYTES];
    char receiver_address[ADDRESS_LENGTH_BYTES];
    char signature[SIGNATURE_LENGTH_BYTES];
    uint64_t timestamp;
    uint64_t amount;
};
