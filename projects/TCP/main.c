// gcc main.c -o main && sudo ./main

#include "client/client.h"
#include "server/server.h"
#include "shared/helpers.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>

int main(void){

    srand(time(NULL)); // for rand sequence number

    ConnectionData *conn = connection_init(12345, inet_addr("127.0.0.1"),
                                           80,    inet_addr("127.0.0.1"));

   

   
    free(conn->header);
    free(conn);
 

}