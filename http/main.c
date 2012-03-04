#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/uio.h>
#include <sys/param.h>
#include <unistd.h>

#define PORT 80
#define BUF_LEN 1024

int httpconnect_open(const char *host_name)
{
	struct hostent *hostent;
	struct sockaddr_in server;
	int fd;

	if((hostent = gethostbyname(host_name)) == NULL){
		fprintf(stderr, "Cannot resolve %s.\n", host_name);
		return 0;
	}

	bzero(&server, sizeof(server));
	server.sin_family = AF_INET;
	bcopy(hostent->h_addr, &server.sin_addr, hostent->h_length);
	server.sin_port = htons(PORT);

	if((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		fprintf(stderr, "Cannot make socket.\n");
		return 0;
	}

	if(connect(fd, (struct sockaddr *)&server, sizeof(server)) == -1){
		fprintf(stderr, "Cannot Connect!.\n");
		return 0;
	}

	return fd;
}

void httpconnect_close(int socket)
{
	close(socket);
}


int main(int argc, char *argv[])
{
	int socket;
	char buf[BUF_LEN];

	if(argc != 2){
		printf("Usage: sock searver_name");
		return 0;
	}

	socket = httpconnect_open(argv[1]);
	if(socket <= 0) return 0;

	snprintf(buf, sizeof(buf) - 1,"GET / HTTP/1.0\r\nHOST: %s\r\n\r\n", argv[1]);
	write(socket, buf, 1024);
	while(read(socket, buf, BUF_LEN) > 0){
		printf("%s", buf);
	}

	httpconnect_close(socket);
	return 0;
}
