#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>

#define PORT 80

int ClientMessage(int serverSocket, int clientSocket) {

	struct addrinfo hints, *servinfo;
	// struct sockaddr_in6 server_addr;
	struct sockaddr_in server_addr; 
	int status, sockfd, ret;
        // char *msg = "GET / HTTP/1.0\r\n\r\n";
	char *msg = "GET / HTTP/1.0\r\n\r\n";
	int trimitere, result;
	char buffer[500];
	char *site = "httpforever.com";
	memset(&hints, 0, sizeof hints);
	// hints.ai_family = AF_INET6;
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	status = getaddrinfo(site, "80", &hints, &servinfo);

	if (status != 0) {
   	 fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
   	 exit(1);
	}

	sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
	if (sockfd == -1) {
       	 printf("socket creation failed...\n");
       	 exit(0);
   	 }
   	 else
       	 printf("Socket successfully created..\n");
   	 bzero(&hints, sizeof(hints));

	 //server_addr.sin6_family = AF_INET6;
	 //inet_pton(AF_INET6, "2001:470:0:503::2", &server_addr.sin6_addr);
	 //server_addr.sin6_port = htons(PORT);

	// ret = connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
	ret = connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen);
	 if (ret == -1) {
		perror("connect()");
		exit(0);
		return EXIT_FAILURE;
	}
	else
	 printf("Connection created successfully");

	// etapa 2
	trimitere = send(sockfd, msg, strlen(msg), 0);
	if (trimitere == -1){
		perror("send()");
		exit(0);
	}
	else {
		printf("\nNumarul de octeti trimisi: %d ",trimitere);
	}
	
	do {
		result = recv(sockfd, buffer, 500, 0);
		if (result > 0) {
			printf("\nNumarul de octeti primiti: %d", result);
			printf("%.*s\n", result,  buffer);
		}
		else if (result == 0) {
			printf("\nConexiune inchisa");
		}
		else {
			printf("\nConexiune esuata");
		}
	}while(result > 0);
	close(sockfd);
        return result;
}
