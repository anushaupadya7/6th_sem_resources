#include<stdio.h> 
#include<stdlib.h>
#include<math.h> 

void receiver(int *frame, int l2) 
{ 
    int i, j=0,counter=0,  l3; 
    int msg[100]; 
    l3=l2-8;  
    for(i=8;i<l3;i++) 
     {
           if(frame[i]==0)
        { 
            if(counter==5) 
            { 
                counter=0; 
            } 
            else 
            { 
                msg[j]=frame[i]; 
                j++;
                counter=0; 
                
            } 
        } 
        else 
        { 
            msg[j]=frame[i]; 
            j++;
            counter++; 
        } 

    } 
    printf("Received message is: \n"); 
    for(i=0;i<j;i++) 
        printf("%d",msg[i]); 
    printf("\n"); 
} 

void sender() 
{ 
    int data[100], frame[100], framelen=0, n, i, j=8; 
    int count, zeroadded=0, zero; 
    printf("Enter the number of bits\n"); 
    scanf("%d",&n); 
    printf("Enter data for bits\n"); 
    for(i=0;i<n;i++) 
        scanf("%d",&data[i]); 
    frame[0]=0; 
    frame[1]=1; 
    frame[2]=1; 
    frame[3]=1; 
    frame[4]=1; 
    frame[5]=1; 
    frame[6]=1; 
    frame[7]=0; 
    for(i=0;i<n;i++) 
    { 
        if(data[i]==0) 
        { 
            frame[j]=data[i]; 
            j++; 
            count=0; 
            zero=1; 
        } 
        else 
        { 
            if((count==5)&&(zero==1)) 
            { 
                frame[j]=0; 
                j++; 
                zeroadded++; 
                frame[j]=data[i]; 
                j++; 
                count=0; 
            }
            else 
            { 
                frame[j]=data[i];
                 j++; 
                count++; 
            } 
        } 
    } 
    frame[j++]=0; 
    frame[j++]=1; 
    frame[j++]=1; 
    frame[j++]=1; 
    frame[j++]=1; 
    frame[j++]=1; 
    frame[j++]=1; 
    frame[j++]=0; 
    framelen=n+16+zeroadded; 
    printf("length of frame sent %d \n",framelen); 
    printf("Frame sent: "); 
    for(i=0;i<framelen;i++) 
        printf("%d",frame[i]); 
    printf("\n"); 
    receiver(frame,framelen); 
} 

void main() 
{ 
    sender(); 
}
