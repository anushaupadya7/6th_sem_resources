#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#define PORT_ID 8000
int main()
{

    char buf[30000];
    int fd1,n;
    struct sockaddr_in s;
    system("clear");
    printf("Enter the filename to be sent to the server\n");
    scanf("%s",buf);

    s.sin_family=AF_INET;
    s.sin_port=htons(PORT_ID);
    s.sin_addr.s_addr=inet_addr("127.0.0.1");

    fd1=socket(AF_INET,SOCK_STREAM,0);

    if((connect(fd1,(struct socketaddr *)&s,sizeof(struct sockaddr)))==-1)
         printf("Error in socket binding\n");

    send(fd1,buf,strlen(buf),0);

    printf("****Contents of the requested file is **** \n");
    while((n=recv(fd1,buf,sizeof(buf),0))>0)
    {
        buf[n]='\0';
        printf("%s",buf);
    }
    printf("\n");
    close(fd1);
    return 0;

}


