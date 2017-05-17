#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>
#include <sysexits.h>
#include <stdlib.h>

#define BUF_SIZE 2048
#define MAX_CONN 4
#define PORT 8888

int main(int argc, char *argv[])
{
    int socket_desc, client_sock, c, read_size;
    struct sockaddr_in server , client;
    char client_message[BUF_SIZE];

    // Create socket descriptor
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1) {
        perror("Couldn't create socket");
        exit(EX_OSERR);;
    }
    puts("Socket created");

    // Prepare the sockaddr_sin structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind
    if(bind(socket_desc, (struct sockaddr *)&server , sizeof(server)) != 0) {
        perror("Bind failed");
        exit(EX_OSERR);;
    }
    puts("Bind done");

    /* 
     * listen() marks the socket as a passive socket, that is, 
     * as a socket that will be used to accept incoming connection
     */
    if (listen(socket_desc, MAX_CONN) != 0) {
        perror("Listen failed");
        exit(EX_OSERR);;
	}

    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);

    //accept connection from an incoming client
    client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
    if (client_sock < 0) {
        perror("accept failed");
        exit(EX_OSERR);;
    }
    puts("Connection accepted");

    //Receive a message from client
    while( (read_size = recv(client_sock , client_message , 2000 , 0)) > 0 ) {
        //Send the message back to client
        write(client_sock , client_message , strlen(client_message));
    }

    if(read_size == 0) {
        puts("Client disconnected");
        fflush(stdout);
    }
    else if(read_size == -1) {
        perror("recv failed");
    }

    return 0;
}
