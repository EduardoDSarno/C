// gcc TCPheader.c -o TCPheader && sudo ./TCPheader


#include "header.h"

void send_sync_packet(struct tcphdr *header, unsigned int src_port,
                                             unsigned int dest_port){


    int sockfd = socket(PF_INET, SOCK_RAW, IPPROTO_TCP);

    struct sockaddr_in dest;
    dest.sin_family = AF_INET;     // Set the address family to IPv4
    dest.sin_port = dest_port; // right endien
    dest.sin_addr.s_addr = inet_addr("127.0.0.1");
    socklen_t dest_len = sizeof(dest);
    header->th_flags = TH_SYN;

   size_t bytes_send = sendto(sockfd,header, sizeof(struct tcphdr), 0, (struct sockaddr *)&dest, dest_len);

   if (bytes_send == -1) {
    perror("sendto failed");
}

   printf("%lu", bytes_send);

}

int main(void){

    unsigned int src_port = 12345;
    unsigned int dest_port = 80;


    struct tcphdr *header = malloc(sizeof(struct tcphdr));
    header->th_dport = htons(dest_port);
    header->th_sport = htons(src_port);
    header->th_off   = sizeof(struct tcphdr) / 4; // 32 bit word (unix def )

    send_sync_packet(header, src_port, dest_port);

    free(header);

}