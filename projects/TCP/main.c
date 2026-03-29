// gcc main.c -o main && sudo ./main

#include "client/client.h"
#include "server/server.h"
#include "shared/helpers.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>

int main(void){

    srand(time(NULL)); // for rand sequence number
    unsigned int src_port = 12345;
    unsigned int dest_port = 80;
    uint32_t destination_ipv4 = inet_addr("127.0.0.1");
    uint32_t source_ipv4 = inet_addr("127.0.0.1");

    struct sockaddr_in source = addr_init(&src_port, &source_ipv4);
    struct sockaddr_in destination = addr_init(&dest_port, &destination_ipv4);

    // 1: send firsrt SYN
    struct tcphdr *client_header = malloc(sizeof(struct tcphdr));
    send_sync_packet(source, destination, client_header);

    // pt2 Server listens for SYN, then sends SYNCACK
    struct tcphdr *received_syn = listen_syn_package();  // mallocs inside
    struct tcphdr *server_header = malloc(sizeof(struct tcphdr));
    send_ack_packet(source, destination, received_syn, server_header);

    // pt3 Client listens for SYN-ACK, then send final ACK
    struct tcphdr *received_syn_ack = listen_packet(TH_SYN | TH_ACK);
    send_syn_ack_pack(source, destination, client_header, received_syn_ack);

    // pt4 Server listens for ACK and print if sucess
    listen_ack_package();


    free(client_header);
    free(received_syn);
    free(server_header);
    free(received_syn_ack);
 

}