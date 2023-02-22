//////////////////////////  Server.c ////////////////
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define MY_PORT		8989
#define MAXBUF		256

int compare(char* buffer1, char* buffer2);

int main(int argc , char *argv[]){

    int sockfd , clientfd;
    struct sockaddr_in self;
	char sentstring;
	char buffer[MAXBUF];

	/*---create buffereaming socket---*/
    if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 )
	{
		perror("socket failed.");
		return -1;
	}
        printf("Socket created.\n");

	/*---initialize address/port bufferucture---*/
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

	struct sockaddr_in client_addr;
	int addrlen=sizeof(client_addr);	
	time_t t = time(NULL);
    struct tm *lt = localtime(&t);

	clientfd = accept(sockfd, (struct sockaddr*)&self, (socklen_t*)&addrlen);

	read(clientfd, buffer, sizeof(buffer));

	printf("IP Adress: %s\n", inet_ntoa(client_addr.sin_addr));
	printf("Port Number: %d\n", htons(client_addr.sin_port));

	/*---forever... ---*/
	while(1)
    {
		printf("\nString sent by client: %s\n", buffer);

		if(compare(buffer, "exit server") == 0){
			printf("\nExited Server.");
			return -1;
		}
		else if(compare(buffer, "DATE") == 0){
			strftime(buffer, MAXBUF, "%a %b %d %X %Y %Z", lt);
			printf("\nDate: %s", buffer);
		}
		else if(compare(buffer, buffer) == 0){
			int i=0, j, k, temp, count;
		
			while(buffer[i] != '\0'){
				i++;
			}

			i--;

			printf("\nLength of String: %d", i);

			for(j=0;j<=sizeof(buffer);j++){  
				if (buffer[j] >= 65 && buffer[j] <= 90){ 
					buffer[j] = buffer[j] + 32; 
				}
			}

			for (k = 0; k < i/2; k++){  
				temp = buffer[k];  
				buffer[k] = buffer[i - k - 1];  
				buffer[i - k - 1] = temp;  
			}  

			printf("\nString in reverse and lowercase: %s\n", buffer);
		}

		send(clientfd, buffer, recv(clientfd, buffer, MAXBUF, 0), 0);
	}

	/*---close connection---*/
	close(clientfd);

	/*---clean up (should never get here!)---*/
	close(sockfd);
	return 0;
}

int compare(char* buffer1,char* buffer2){  
    int indication=0, i=0;

    while(buffer1[i] != '\0' && buffer2[i] != '\0'){  
       	if(buffer1[i] != buffer2[i]){  
        	indication = 1;  
        	break;  
       	}  
    	i++;  
    }  

    if(indication == 0){
		return 0;  
	}
    else{
		return 1;  
	}
}  