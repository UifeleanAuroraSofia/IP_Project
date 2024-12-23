#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include "client.h"
#define SA struct sockaddr 
#define PORT 22228

int main(void) {

	struct sockaddr_storage their_addr;
	struct sockaddr_in server_addr;
	int sockfd, new_socket, result, trimitere, comanda;
	char buffer[500];
	socklen_t addr_size;
        char *msg = "Comanda neimplementata";

    	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    	if (sockfd == -1) { 
       		printf("socket creation failed...\n"); 
       	 	exit(0); 
    	} 
    	else
        	printf("Socket successfully created..\n"); 
    	bzero(&server_addr, sizeof(server_addr));
	
    	server_addr.sin_family = AF_INET; 
    	server_addr.sin_addr.s_addr = htonl(INADDR_ANY); 
    	server_addr.sin_port = htons(PORT);

        if ((bind(sockfd, (SA*)&server_addr, sizeof(server_addr))) != 0) {
       		 printf("socket bind failed...\n");
       		 exit(0);
   	 }
  	else
       		 printf("Socket successfully binded..\n");
	
    	if ((listen(sockfd, 5)) != 0) { 
       		 printf("Listen failed...\n"); 
       		 exit(0); 
   	} 
   	 else
       		 printf("Server listening..\n");  
      do {
		 addr_size = sizeof their_addr;
                 new_socket = accept(sockfd, (struct sockaddr *)&their_addr, &addr_size);

	 	 if (new_socket == -1) {
			perror("accept()");
	         }
		printf("\nConexiune reusita");
		
		do {
                        result = recv(new_socket, buffer, 500, 0);
			buffer[3] = '\0';
			if (strcmp("08#", buffer) == 0) {
				ClientMessage(new_socket);
			}
			else if (strcmp("08#", buffer) != 0) {
				 trimitere = send(new_socket, msg, strlen(msg), 0);
	               		 if (trimitere == -1){
		       			 perror("send()");
					 exit(0);
				 }
			}
			else if (result == 0) {
				printf("\nConexiune inchisa");
			}
			else {
				printf("\nConexiune esuata");
			}

	   	}while(result > 0);
	
	}while(new_socket != -1);
      close(new_socket);
      close(sockfd);
	
}
