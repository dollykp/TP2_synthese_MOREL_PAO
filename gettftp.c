#include "gettftp.h"

int main(int argc, char * argv[]){
	int address;
	(void) argc;
	struct addrinfo hints;
	struct addrinfo *res;
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_DGRAM;
	hints.ai_protocol = IPPROTO_UDP;
	address = getaddrinfo(argv[1], argv[2], &hints, &res);
	printf("vérification getaddrinfo : %d \n\r", address);
	for(struct addrinfo *array_i= res; array_i != NULL; array_i = array_i->ai_next){
		printf("ai_family : %d \n\r", array_i->ai_family);
		printf("ai_socktype : %d \n\r", array_i->ai_socktype);
		printf("ai_protocol : %d \n\r", array_i->ai_protocol);
	}
}
