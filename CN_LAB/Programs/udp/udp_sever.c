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
    char buf[300];
    int fd1,n,size;
    FILE *fp;
    struct sockaddr_in s1, s2;
    int s_length = sizeof(s2);
    system("clear");
    printf("Server is getting ready.... \n");

    s1.sin_family = AF_INET;
    s1.sin_port = htons(PORT_ID);
    s1.sin_addr.s_addr = inet_addr("127.0.0.1");


    fd1 = socket(AF_INET, SOCK_DGRAM, 0);

    if((bind(fd1,(struct sockaddr *)&s1, sizeof(struct sockaddr)))==-1)
        printf("Error in socket binding!!!!\n");

    printf("Waiting for client request....\n");

    size = recvfrom(fd1,buf,sizeof(buf), 0,(struct sockaddr *)&s2, &s_length);
    buf[size] = '\0';

    fp = fopen(buf, "r");
    printf("File Name recieved is : %s\n",buf);

    if (fp == NULL){
        sendto(fd1,"File not found .... ", 20, 0,(struct sockaddr *)&s2, s_length);
    }
    else{
        printf("\nFile Successfully opened!\n");
        clearBuf(buf);
        while(fscanf(fp, "%s", buf)!=EOF){  
            sendto(fd1,buf,sizeof(buf),0,(struct sockaddr *)&s2, s_length);
            clearBuf(buf);
        }
        sendto(fd1,NULL,0,0,(struct sockaddr *)&s2, s_length);
        fclose(fp);
    }
 
    close(fd1);
    printf("Server terminated....\n");
    return 0;
}