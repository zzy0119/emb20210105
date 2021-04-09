#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netinet/ip.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "proto.h"

int main(void)
{
	int sd, newsd;
	struct sockaddr_in raddr;
	char buf[MAXMSG] = {};

	sd = socket(AF_INET, SOCK_STREAM, 0);
	if (sd == -1) {
		perror("socket()");
		exit(1);
	}

	// bind()

	raddr.sin_family = AF_INET;
	inet_aton(SERVERIP, &raddr.sin_addr);
	raddr.sin_port = htons(SERVERPORT);

	connect(sd, (struct sockaddr *)&raddr, sizeof(raddr));

	read(sd, buf, MAXMSG);
	puts(buf);

	close(sd);

	exit(0);
}

