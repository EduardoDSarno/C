// gcc main.c -o main && sudo ./main

#include "client/header.h"
#include "shared/helpers.h"
#include <stdlib.h>
#include <string.h>

int main(void){

    unsigned int src_port = 12345;
    unsigned int dest_port = 80;
    uint32_t destination_ipv4 = inet_addr("127.0.0.1");
    uint32_t source_ipv4 = inet_addr("127.0.0.1");
    uint8_t *message = NULL;


    struct tcphdr *header = malloc(sizeof(struct tcphdr));
    

    send_sync_packet(header, src_port, &dest_port, &destination_ipv4,&source_ipv4, message);

    free(header);

}