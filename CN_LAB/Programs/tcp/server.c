#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#define PORT_ID 8000


int main()
{
    char buf[300];
    int fd1,fd2,size,n;
    struct sockaddr_in s;
    system("clear");
    printf("Server is getting ready\n");

    s.sin_family=AF_INET;
    s.sin_port=htons(PORT_ID);
    s.sin_addr.s_addr=inet_addr("127.0.0.1");

    fd1=socket(AF_INET,SOCK_STREAM,0);

    if((bind(fd1,(struct sockaddr *)&s,sizeof(struct sockaddr)))==-1)
        printf("Error in socket binding\n");
    if((listen(fd1,5))==-1)
    printf("Error in listening\n");
    printf("Waiting for client request\n");
    size=sizeof(struct sockaddr);

    fd2=accept(fd1,(struct sockaddr *)&s,&size);
    size=recv(fd2,buf,sizeof(buf),0);
    buf[size]='\0';
    printf("Filename received is %s\n",buf);
    if((fd1=open(buf,O_RDONLY))!=-1)
    {
        while((n=read(fd1,buf,sizeof(buf)))>0)
            send(fd2,buf,n,0);

    }
    else
        send(fd2,"File not found",20,0);

        close(fd1);
        close(fd2);
        printf("Server terminated");
        return 0;


}


