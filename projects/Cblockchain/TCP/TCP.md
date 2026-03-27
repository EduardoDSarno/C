So on this file I will take notes of how I implement TCP 
and how I understand from the ground up

TCP is created to solve 3 major problems that can happen when communicating 
between computers happen (data trasnfer)

1- They solve a problem of lost packets
2- Corrupted packets
3- Out of order packets

TCP uses sockets that are described as a endpoint of a connection
This connection is going to be made by a client and server

- Server
The server will need to have it's socket saying I am on, a bind to the client
knows where to go it will have a listen to be able to listen to things in a specific way
 and a accept that will be for acceptign this communication

 -Client
 The client will have it's socket (the endpoint) it will have a connect, so it can connect
 the bind is automatically decided by the OS since the relationship from client to server is normally one-to-many the server does not need to know before where the client is located, just
after the conneciton attempt


Start:
socket/socket.c
socket/socket.h

This 2 files will have the responsability of Creating and initliazing a Socket, that will receive
a port and IPV4 and will generate a socket using the defaoult C fn socket. That generates a file descriptor for it, Which for now with my basic understading is a contract that happens betwee nthe program and the kernel  since the program itself does not have access to the functionalities nescessaries to make a socket


server/server.c
server/server.h

These fils are repon