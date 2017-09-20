#include <arpa/inet.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sysexits.h>
#include <unistd.h>
 
#define PORT 8888
#define BUF_SIZE 2048
 
 
int main(int argc , char *argv[])
{
    int sock;
    struct sockaddr_in server;
    char message[BUF_SIZE], server_reply[BUF_SIZE];
     
    // create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1) {
		perror("Error");
        exit(EX_OSERR);
    }
    puts("Socket created");
    
    // 127.0.0.1 -> https://en.wikipedia.org/wiki/Localhost
    server.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
 
    // connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0) {
        perror("Error");
        exit(EX_OSERR);
    }
     
    puts("Connected\n");
     
    // keep communicating with server
    while(true) {
        // reset buffers
        memset(message, '\0', sizeof(message));
        memset(server_reply, '\0', sizeof(server_reply));
        
        int i;
        for(i=0; i<BUF_SIZE; i++) {
        server_reply[i] = '\0';
        message[i] = '\0';
        }
        
        printf("Enter message: ");
        fgets(message, sizeof(message), stdin);
         
        if( send(sock, message, strlen(message), 0) == -1) {
            perror("Error");
			exit(EX_OSERR);
        }
         
        // receive a reply from the server
        if( recv(sock, server_reply, BUF_SIZE, 0) == -1) {
			perror("Error");
        	exit(EX_OSERR);
        }
        puts("Server reply:");
        printf("%s", server_reply);
    }
    close(sock);
    return 0;
}
