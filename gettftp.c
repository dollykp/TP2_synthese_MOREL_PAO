#include "gettftp.h"

int main(int argc, char * argv[]){
	int address;
	(void) argc;
	struct addrinfo hints;
	struct addrinfo *res;
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET; /*IPv4*/
	hints.ai_socktype = SOCK_DGRAM; /*An UDP server listens to a local port, and waits for a datagram.*/
	hints.ai_protocol = IPPROTO_UDP; /*UDP protocol*/
	address = getaddrinfo(argv[1], argv[2], &hints, &res); /*returns a linked list*/
							       /*returns 0 if it succeeds*/
	printf("vérification getaddrinfo : %d \n\r", address);
	for(struct addrinfo *array_i= res; array_i != NULL; array_i = array_i->ai_next){
		printf("ai_family : %d \n\r", array_i->ai_family);
		printf("ai_socktype : %d \n\r", array_i->ai_socktype);
		printf("ai_protocol : %d \n\r", array_i->ai_protocol);
	}
}
