#include "../socket/socket.h"
#include <stddef.h>

// will have constant since it is learning project
// I beleive in reality it would be dinamically allocated based on the type of node
#define MAX_CLIENTS 100

typedef struct TCPServer
{
    Socket server;
    Socket *clients; // multiple clients 
    size_t clients_count;
    size_t max_clients;

} TCPServer;

