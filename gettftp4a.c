#include "gettftp.h"

int main(int argc, char * argv[]){
	int address;
	int len=0;
	int sent;
	int received;
	char buffer[516];
	socklen_t server_len = sizeof(argv[1]);
	(void) argc;
	struct addrinfo hints;
	struct addrinfo *res;
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_DGRAM;
	hints.ai_protocol = IPPROTO_UDP;
	address = getaddrinfo(argv[1], argv[2], &hints, &res);
	printf("verification of getaddrinfo : %d \n\r", address);
	for(struct addrinfo *array_i= res; array_i != NULL; array_i = array_i->ai_next){
		printf("ai_family : %d \n\r", array_i->ai_family);
		printf("ai_socktype : %d \n\r", array_i->ai_socktype);
		printf("ai_protocol : %d \n\r", array_i->ai_protocol);
	}
	
	int sock;
	sock=socket(res->ai_family,res->ai_socktype,0);
	sent = sendto(sock, buffer, len, 0, res->ai_addr, res->ai_addrlen);
	if(sock<0){
		printf("error while sending");
		return -1;
	}
	close(sock);
	
	*((uint16_t *) buffer) = htons(1); // OPCODE RRQ = 1 
	len += 2;
	strcpy(buffer + len, argv[3]);
	len += strlen(argv[3]) + 1;
	received = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr *) &argv[1], &server_len);
	//uint16_t opcode = ntohs(*((uint16_t *) buffer));
	uint16_t block_num = ntohs(*((uint16_t *) (buffer + 2)));
	
	// Construction of ACK packet
        char ack_packet[4];
        *((uint16_t *) ack_packet) = htons(TFTP_OPCODE_ACK);  // OPCODE ACK = 4
        *((uint16_t *) (ack_packet + 2)) = htons(block_num);
	printf("sent : %d \n\r",sent);
	printf("received : %d \n\r",received);
}
