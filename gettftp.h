#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <sys/socket.h>
#include <netdb.h>

#define TFTP_PORT "1069"
#define TFTP_OPCODE_RRQ 1
#define TFTP_OPCODE_DATA 3
#define TFTP_OPCODE_ACK 4
