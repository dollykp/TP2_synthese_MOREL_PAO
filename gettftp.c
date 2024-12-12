#include "main.h"

	int address;
	(void) argc; /*putting a void cast because the makefile doesn't allow unused variable*/
	struct addrinfo hints;
	struct addrinfo *res;
	hints.ai_socktype = SOCK_DGRAM; /*An UDP server listens to a local port, and waits for a datagram.*/
	hints.ai_family = AF_INET; /*IPv4*/
	hints.ai_protocol = IPPROTO_UDP; /*UDP protocol*/
	memset(&hints, 0, sizeof(hints));	
	address = getaddrinfo(argv[1], argv[2], &hints, &res);
	printf("The address is : %s \n", argv[1]);
	printf("The port number is : %s \n", argv[2]);
	printf("The file is : %s \n", argv[3]);
	printf("The address is : %d \n", address);
}
