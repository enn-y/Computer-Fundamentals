//////////////////////////  Server.c ////////////////
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>

#define MY_PORT		8989
#define MAXBUF		256

int main(int argc , char *argv[]){

    int sockfd , clientfd;
    struct sockaddr_in self;
	char buffer[MAXBUF];

	/*---create streaming socket---*/
    if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 )
	{
		perror("socket failed.");
		return -1;
	}
        printf("Socket created.\n");

	/*---initialize address/port structure---*/
	/* bzero(&self, sizeof(self));*/
	self.sin_family = AF_INET;
	self.sin_port = htons(MY_PORT);	  // Host to Network Short (16-bit)
	self.sin_addr.s_addr = INADDR_ANY;  

	/*---assign a port number to the socket---*/
    if ( bind(sockfd, (struct sockaddr*)&self, sizeof(self)) != 0 )
	{
		perror("bind failed.");
		return -1;
	}
        puts("Bind done");

	/*---make it a "listening socket"---*/
	if( listen(sockfd, 20) != 0 )
    {
		perror("accept");
		return -1;
	}

	puts("Waiting for incoming connections...");
	
	/*---accept a connection (creating a data pipe)---*/

	/*---forever... ---*/
	while (1)
    {
		struct sockaddr_in client_addr;
		int addrlen=sizeof(client_addr);	

		clientfd = accept(sockfd, (struct sockaddr*)&self, (socklen_t*)&addrlen);

		read(clientfd, buffer, sizeof(buffer));

		int i, j, k, tempvar, count;
		
		while(buffer[i] != '\0'){
			i++;
		}

		printf("\nString sent by client: %s\n", buffer);

        for (j=0;j<=sizeof(buffer);j++){  
            if (buffer[j] >= 65 && buffer[j] <= 90)  
            buffer[j] = buffer[j] + 32; 
        }

        for (k = 0; k < i/2; k++){  
			tempvar = buffer[k];  
			buffer[k] = buffer[i - k - 1];  
			buffer[i - k - 1] = tempvar;  
    	}  

		printf("\nString in reverse and lowercase: %s\n", buffer);

		send(clientfd, buffer, recv(clientfd, buffer, MAXBUF, 0), 0);

		/*---close connection---*/
		close(clientfd);
	}

	/*---clean up (should never get here!)---*/
	close(sockfd);
	return 0;
}