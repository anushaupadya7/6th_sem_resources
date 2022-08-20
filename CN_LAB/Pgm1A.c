 /* 1.a. Design and Implement C program in which sender module should count the number of bytes in the frame and receiver module should display each frame received */ 

#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 

char res[100]; 

void sender() 
{ 
	int n,i,len; 
	char frame[100],l[100]; 
	printf("Enter the number of frames\n"); 
	scanf("%d",&n); 
	for(i=0;i<n;i++) 
	{ 
		printf("Enter the frame %d\n",i+1); 
		scanf("%s",&frame); 
		len=strlen(frame); 
		printf("Number of bytes in the frame %d = %d\n",i+1,len); 
		sprintf(l,"%d",len); 
		strcat(l,frame); 
		strcat(res,l); 
	} 
	
} 
	
void reciever() 
{ 
	int len,i,j; 
	printf("Received frame \n"); 
	for(i=0;i<strlen(res);i++) 
	{ 
		len=res[i]-'0'; 
		for(j=i+1;j<=(i+len);j++) 
			printf("%c",res[j]); i=i+len; 
		printf("\n"); 
	} 
} 

void main() 
{ 
	sender(); 
	reciever(); 
	return 0;
}
