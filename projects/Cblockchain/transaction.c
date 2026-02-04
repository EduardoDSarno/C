#ifndef transaction_h
#define transaction_h

struct Transaction{
    int *sender_address;
    int *receiver_address;
    char signature;
    long timestamp;
    float amount;
};

#endif