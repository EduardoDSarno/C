// gcc TCPheader.c -o TCPheader && sudo ./TCPheader


#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include "pseIPHeader.c"


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

/* this function will get the  Pseudo IP heade, TCP header and TCP body add to a buffer and return
    a pointer to this buffer with the formmated data to perfrom checksum*/
uint16_t* format_check_sum(struct tcphdr *header, uint8_t * message_buffer,  size_t buffer_size,
                                                                     uint32_t ipv4_scr,
                                                                     uint32_t ipv4_dest,
                                                                     size_t *out_size_buffer)
{
     size_t size = sizeof(struct tcphdr) +  buffer_size + sizeof(PseudoIpHeader);

    // this should hold the whole lenght of the sum for the calculation.
    uint16_t *temp_buffer = malloc(size + 1); // + 1 for possible allocation of padding
    if (temp_buffer == NULL) {
        fprintf(stderr, "Error allocating memory");
        return NULL;
    }

    // cast temp buffer because with uint16 it will advance 2 bytes foward in the function insated of 1
    memcpy((uint8_t *)temp_buffer, header, sizeof(struct tcphdr));
    memcpy((uint8_t *)temp_buffer + sizeof(struct tcphdr), message_buffer, buffer_size);

    uint16_t segment  = sizeof(struct tcphdr) + buffer_size;
    PseudoIpHeader *pseud_ip_header = psdIpHeader_intit(ipv4_scr, ipv4_dest, IPPROTO_TCP, segment);

    memcpy((uint8_t *)temp_buffer + sizeof(struct tcphdr) +  buffer_size, pseud_ip_header, sizeof(PseudoIpHeader));

   

    if (size % 2 == 1) {
        memset((uint8_t *)temp_buffer + size, 0, 1);
        size+=1;
    }

    free(pseud_ip_header);

    out_size_buffer = &size;
    return temp_buffer;
}

uint16_t check_sum(uint16_t * buffer, size_t * size){


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