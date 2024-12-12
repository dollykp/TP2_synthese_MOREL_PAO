#include "main.h"

	(void) argc;
	struct addrinfo hints;
	struct addrinfo *res;
	memset(&hints, 0, sizeof(hints));
	hints	
	getaddrinfo(argv[1], NULL, &hints, &res);
}
