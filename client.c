#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>

#define PORT 80

void ClientMessage(int clientSocket) {

	struct addrinfo hints, *servinfo;
	struct sockaddr_in6 server_addr;
	int status, siteSocket, ret;
	char *msg = "GET / HTTP/1.0\r\n\r\n";
	int trimitere, result;
	char buffer[500];
	char *site = "www.ietf.org";
	FILE *fisier;
	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_INET6;
	hints.ai_socktype = SOCK_STREAM;
	status = getaddrinfo(site, "80", &hints, &servinfo);

	if (status != 0) {
   	 fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
   	 exit(1);
	}

	siteSocket = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
	if (siteSocket == -1) {
       	 printf("socket creation failed...\n");
       	 exit(0);
   	 }
   	 else
       	 printf("Socket successfully created..\n");
   	 bzero(&hints, sizeof(hints));

	 server_addr.sin6_family = AF_INET6;
	 inet_pton(AF_INET6, "::1", &server_addr.sin6_addr);
	 server_addr.sin6_port = htons(PORT);

	 ret = connect(siteSocket, (struct sockaddr*)&server_addr, sizeof(server_addr));
	 if (ret == -1) {
		perror("connect()");
		exit(0);
		return EXIT_FAILURE;
	}
	else
	 printf("Connection created successfully");

	trimitere = send(siteSocket, msg, strlen(msg), 0);
	if (trimitere == -1){
		perror("send()");
		exit(0);
	}
	
	fisier =  fopen("fisier.html", "w");
        if (fisier == NULL) {
       		 perror("Error opening file");
       		 close(siteSocket);
       		 return EXIT_FAILURE;
   	} else {
		fclose(fopen("fisier.html", "w"));
	}

	do {
		result = recv(siteSocket, buffer, 500, 0);
		if (result > 0) {
			fwrite(buffer, 1, result, fisier);
			send(clientSocket, buffer, result, 0);
		}
		else if (result == 0) {
			printf("\nConexiune inchisa cu site-ul");
		}
		else {
			printf("\nConexiune esuata");
		}
	}while(result > 0);
	close(siteSocket);
	fclose(fisier);
}
