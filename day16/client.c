#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main(void)
{
	int sock;
	if ((sock = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP)) < 0){	//Or IPPROTO_TCP replace 0
		perror("socket");
		exit(EXIT_FAILURE);
	}

	struct sockaddr_in servaddr;
	memset(&servaddr,0,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(5188);
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	//inet_aton("127.0.0.1",&servaddr.sin_addr);
	if (connect(sock,(struct sockaddr*)&servaddr,sizeof(servaddr)) < 0){
		perror("connect");
		exit(EXIT_FAILURE);
	}

	char sendbuf[1024] = {0};
	char recvbuf[1024] = {0};

	while(fgets(sendbuf,sizeof(sendbuf),stdin) != NULL){
		write(sock,sendbuf,sizeof(sendbuf));
		read(sock,recvbuf,sizeof(recvbuf));

		fputs(recvbuf,stdout);
	}

	close(sock);

	return 0;

}
