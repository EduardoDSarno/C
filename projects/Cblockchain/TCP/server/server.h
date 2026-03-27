#ifndef SERVER_H
#define SERVER_H

#include "../socket/socket.h"
#include <stddef.h>
#include "../../utils/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>

// will have constant since it is learning project
// I beleive in reality it would be dinamically allocated based on the type of node
#define MAX_CLIENTS 100

typedef enum {
    SERVER_UNBOUND,
    SERVER_BOUND,
    SERVER_LISTENING,
    SERVER_ON

} ServerState;

typedef struct TCPServer
{
    Socket server;
    Socket *clients; // multiple clients 
    size_t clients_count;
    size_t max_clients;
    ServerState state;

} TCPServer;

TCPServer *server_init(const uint16_t port,const uint32_t ipv4);
int server_connect(TCPServer * const server);
int server_listen(TCPServer * const server, const int backlog);
int server_bind(TCPServer * const server);

#endif
