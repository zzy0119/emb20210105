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
	struct sockaddr_in laddr;

	sd = socket(AF_INET, SOCK_STREAM, 0);
	if (sd == -1) {
		perror("socket()");
		exit(1);
	}

	laddr.sin_family = AF_INET;
	inet_aton(SERVERIP, &laddr.sin_addr);
	laddr.sin_port = htons(SERVERPORT);
	bind(sd, (struct sockaddr *)&laddr, sizeof(laddr));
	// if error

	listen(sd, 20);
	// if error

	while (1) {
		newsd = accept(sd, NULL, NULL);
		if (newsd == -1) {
			perror("accept()");
			close(sd);
			exit(1);
		}
		write(newsd, "hello", 5);
		close(newsd);
	}

	close(sd);

	exit(0);
}

