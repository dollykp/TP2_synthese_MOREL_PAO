#include "gettftp.h"

int main(int argc, char * argv[]){
	int address;
	int len=0;
	int sent;
	int received;
	struct sockaddr_storage server_addr;
	socklen_t server_len = sizeof(server_addr);
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
	if(sock<0){
		printf("error while sending");
		return -1;
	}
	
	size_t rrq_len=2+strlen(argv[3]) +1 + strlen("octet")+1;
	char *rrq=malloc(rrq_len);
	
	*((uint16_t *) rrq) = htons(1); // OPCODE RRQ = 1 
	len += 2;
	strcpy(rrq + len, argv[3]);
	len += strlen(argv[3]) + 1;
	strcpy(rrq + len, "octet");
	len += strlen("octet") + 1;
	sent = sendto(sock, rrq, len, 0, res->ai_addr, res->ai_addrlen);
	
	received = recvfrom(sock, rrq, rrq_len, 0, (struct sockaddr *) &server_addr, &server_len);
	close(sock);
	//uint16_t opcode = ntohs(*((uint16_t *) rrq));
	uint16_t block_num = ntohs(*((uint16_t *) (rrq + 2)));
	
	// Construction of ACK packet
        char ack_packet[4];
        *((uint16_t *) ack_packet) = htons(TFTP_OPCODE_ACK);  // OPCODE ACK = 4
        *((uint16_t *) (ack_packet + 2)) = htons(block_num);
        sent = sendto(sock, ack_packet, sizeof(ack_packet), 0, (struct sockaddr *) &server_addr, server_len);
	printf("sent : %d \n\r",sent);
	printf("received : %d \n\r",received);
}
