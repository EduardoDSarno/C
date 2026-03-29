#include "server.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


void send_ack_packet(struct sockaddr_in source, struct sockaddr_in destination,
                     struct tcphdr *client_header, struct tcphdr *server_header)
{

    uint32_t ack_num = ntohl(client_header->th_seq) + 1;

    uint32_t seq_number = htonl(rand());
    server_header->th_seq = seq_number;

    /*For the flags heere since each flag is in one opsiton (0-7) as bits in the byte
      when we or them is the same as adding them toghter to the flag from SYN because SYN-ACK*/
    send_packet(source, destination, server_header, (TH_SYN | TH_ACK), ack_num);
}

/* Wrapper will return the header stuct */
struct tcphdr * listen_syn_package(){
    return listen_packet(TH_SYN);
}

/* This case we will just be printing connected, in reality we would start exahcnge data
   I might implement this later*/
void listen_ack_package(){
    listen_packet(TH_ACK);
    printf("CONNECTED");
}
