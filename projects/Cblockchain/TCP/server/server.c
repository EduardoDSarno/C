#include "server.h"
#include <stdio.h>

/* This function will initiate a server
    it will return a pointer to the Server*/
TCPServer *server_init(const uint16_t port,const uint32_t ipv4)
{
    TCPServer *server = safe_malloc(sizeof(TCPServer));
    
    if(is_null(server, "Error allocating Server Memory")) goto cleanup;

    Socket *server_socket = NULL;

    server_socket = socket_init(port, ipv4);

    if(is_null(server_socket, "Error Creating server Sockert")){
        goto cleanup;
    }

    server->server = *server_socket;
    server->clients = NULL;
    server->clients_count = 0;
    server->max_clients = MAX_CLIENTS;
    server->state = SERVER_UNBOUND;


    safe_free(server_socket, sizeof(Socket));
    return server;
    cleanup:
        safe_free(server_socket, sizeof(Socket)); 
        safe_free(server, sizeof(TCPServer));
        return NULL;
}

/*This funciton will return sucess or failure for binding the server*/
int server_bind(TCPServer * const server){

    struct sockaddr_in my_address;

    my_address.sin_family        = AF_INET;
    my_address.sin_port          = htons(server->server.port); // swaps bites order is nescessary
    my_address.sin_addr.s_addr   = server->server.ipv4;
    
    const int result = bind(server->server.file_descriptor_index, 
                     (struct sockaddr *)& my_address,
                      sizeof(my_address));

    if (result < 0) {
        perror("bind");
        return result;
    }

    server->state = SERVER_BOUND;
    return result;
}

/*Ths listen funciton wrapped with check*/
int server_listen(TCPServer * const server, const int backlog){

    if(server->state != SERVER_BOUND) return -1;

    const int result = listen(server->server.file_descriptor_index, backlog);

    if (result < 0) {
        perror("listen");
        return result;
    }

    server->state = SERVER_LISTENING;
    return result;
}

/* This function is the one used for the Server to be set up*/
int server_connect(TCPServer * const server){

    server->state = SERVER_ON;

    int result = 0;
    /* This struct is being declared now because will be the space on which
        later on the client will ocupy*/
    struct sockaddr_in client_addr;
    socklen_t addr_len = sizeof(client_addr);

    // await for connection
    while (server->state == SERVER_ON) 
    {
        result = accept(server->server.file_descriptor_index, 
                        (struct sockaddr *)&client_addr,
                         &addr_len);

        if (result < 0) {
            perror("Connection Stoped");
            break;
        }

        Socket *new_socket = safe_malloc(sizeof(Socket));

        if(is_null(new_socket, "Error on Connection")) break;

        

        // reallocate server clients
        server->clients = safe_realloc(server->clients, 
                                sizeof(Socket) * (server->clients_count + 1),
                                           sizeof(Socket) * server->clients_count);

        if(is_null(server->clients, "Error on Connection - Realocation")) break;

        // create new socket with values the OS will generate
        new_socket->ipv4 = client_addr.sin_addr.s_addr;
        new_socket->port = client_addr.sin_port;
        new_socket->file_descriptor_index = result;

        server->clients[server->clients_count] = *new_socket; // store inside clients
        server->clients_count++; // increment

        safe_free(new_socket, sizeof(Socket));
            
    }

    
    server->state = SERVER_LISTENING;
    return result;
}

