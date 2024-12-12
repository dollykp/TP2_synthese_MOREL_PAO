#include "main.h"
	(void) argc;
	printf("Name resolution for %s \n", argv[1]);
	struct addrinfo hints;
	struct addrinfo *res;
	memset(&hints, 0, sizeof(hints));	
	getaddrinfo(argv[1], NULL, &hints, &res);
}
