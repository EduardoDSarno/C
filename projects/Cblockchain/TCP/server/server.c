#include "server.h"
#include "../../utils/utils.h"
#include <stdio.h>
#include <stdlib.h>



TCPServer *server_init(const uint16_t port,const uint32_t ipv4)
{
    TCPServer *server = safe_malloc(sizeof(TCPServer));
    

    Socket *server_socket;

    server_socket = socket_init(port, ipv4);

    if(is_null(server_socket, "Error Creating server Sockert")){
        goto cleanup;
    }

    server->server = *server_socket;
    server->clients = NULL;
    server->clients_count = 0;
    server->max_clients = MAX_CLIENTS;


    // free(server_socket)
    cleanup:
        safe_free(server_socket, sizeof(Socket)); 
        return NULL;
}
