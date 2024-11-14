#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>

#define PORT 80

int main(void) {

	struct addrinfo hints, *servinfo;
	struct sockaddr_in6 server_addr;
	int status, sockfd, ret;
	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_INET6;
	hints.ai_socktype = SOCK_STREAM;
	status = getaddrinfo("he.net", "80", &hints, &servinfo);

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

}
