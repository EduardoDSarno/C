#include "server.h"
#include <stdio.h>
#include <stdlib.h>



TCPServer *server_init(const uint16_t port,const uint32_t ipv4)
{
    TCPServer *server = malloc(sizeof(TCPServer));

    Socket *server_socket;

    server_socket = socket_init(port, ipv4);

    if (server_socket == NULL) {
        fprintf(stderr, "Error Creating server Sockert");
        goto cleanup;
    }


    // free(server_socket)
    cleanup:
        if (server_socket != NULL) free(server_socket); 
        return NULL;
}