#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>

#define MY_PORT		8989

int main()
{
	struct sockaddr_in address;
	int sock = 0;
	struct sockaddr_in serv_addr;
	char str[256];	

	// Creating socket file descriptor
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("\n Socket creation error \n");
		return -1;
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(MY_PORT);	  // Host to Network Short (16-bit)
	serv_addr.sin_addr.s_addr = INADDR_ANY;  

	if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
		printf("\nAddress not supported \n");
		return -1;
	}

	if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
		printf("\nConnection Failed \n");
		return -1;
	}

	while(1){
		printf("\nInput the string: ");
		fgets(str, sizeof(str), stdin);

		send(sock, str, sizeof(str), 0);
	}
	
	return 0;
}