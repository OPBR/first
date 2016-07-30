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
	int listenfd;
	if ((listenfd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP)) < 0){	//Or IPPROTO_TCP replace 0
		perror("socket");
		exit(EXIT_FAILURE);
	}

	struct sockaddr_in servaddr;
	memset(&servaddr,0,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(5188);
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	//servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	//inet_aton("127.0.0.1",&servaddr.sin_addr);
	

	if (bind(listenfd,(struct sockaddr*)&servaddr,sizeof(servaddr)) < 0){
		perror("bind");
		exit(EXIT_FAILURE);
	}

	if (listen(listenfd,SOMAXCONN) < 0){
		perror("listen");
		exit(EXIT_FAILURE);
	}

	struct sockaddr_in peeraddr;
	socklen_t peerlen = sizeof(peeraddr);
	int conn;

	if ((conn = accept(listenfd,(struct sockaddr*)&peeraddr,&peerlen)) < 0){
		perror("accept");
		exit(EXIT_FAILURE);
	}

	char recvbuf[1024];

	while(1){
		memset(recvbuf,0,sizeof(recvbuf));
		int ret = read(conn,recvbuf,sizeof(recvbuf));
		fputs(recvbuf,stdout);
		write(conn,recvbuf,ret);
	
	}

	return 0;


}
