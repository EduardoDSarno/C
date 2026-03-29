#include "header.h"
#include <stdlib.h>

void send_sync_packet(struct tcphdr *header, unsigned int src_port,
                                             unsigned int *dest_port,
                                             const uint32_t *destination_ipv4,
                                             const uint32_t *source_ipv4,
                                             const uint8_t  *message){


    int sockfd = socket(PF_INET, SOCK_RAW, IPPROTO_TCP);

    struct sockaddr_in dest =  addr_init(dest_port, destination_ipv4);
    socklen_t dest_len = sizeof(dest);
    header->th_flags = TH_SYN;
    header->th_dport = htons(*dest_port);
    header->th_sport = htons(src_port);
    header->th_off   = sizeof(struct tcphdr) / 4; // 32 bit word (uni
    
    // getting formmated data on buffer
    size_t size = 0;
    uint16_t * buffer = format_check_sum(header, message, 0, *source_ipv4,*destination_ipv4, &size);

    // check summing
    uint16_t checksum = check_sum(buffer, &size);

    header->th_sum = checksum;
    size_t bytes_send = sendto(sockfd,header, sizeof(struct tcphdr), 0, (struct sockaddr *)&dest, dest_len);

    if (bytes_send == -1) {
    perror("sendto failed");
    }
    printf("%lu", bytes_send);

    free(buffer);
}
