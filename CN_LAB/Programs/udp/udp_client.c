#include <stdio.h>
#include <stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>

#define PORT_ID 8000

void clearBuf(char* b){
    for (int i = 0; i < 300; i++)
        b[i] = '\0';
}

int main(){
    char buf[30000];
    int fd1,n;
    struct sockaddr_in s;
    int s_length = sizeof(s);
    system("clear");
    printf("Enter the filename to be sent to the server \n");
    scanf("%s",buf);

    s.sin_family = AF_INET;
    s.sin_port = htons(PORT_ID);
    s.sin_addr.s_addr = inet_addr("127.0.0.1");


    fd1 = socket(AF_INET, SOCK_DGRAM, 0);

    if((connect(fd1,(struct sockaddr *)&s, sizeof(struct sockaddr)))==-1)
        printf("Error in socket connecting!!!!\n");

    sendto(fd1, buf, strlen(buf),0,(struct sockaddr *)&s,sizeof(s));
    clearBuf(buf);
    printf("**** contents of the requested file is ****\n");

    while(recvfrom(fd1,buf,sizeof(buf),0,(struct sockaddr *)&s,&s_length)){
        puts(buf);
        clearBuf(buf);
    }

    printf("\n");
    close(fd1);
    printf("Client terminated....\n");
    return 0;
}