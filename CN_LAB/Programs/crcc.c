#include<stdio.h>
#include<stdlib.h>

void main(){
    int msg1[50], msg2[50], code[5]={1,0,0,0,1};
    int i, j, k, p, n=5, m, err=0, e,fail=1;

    printf("Enter the no. of bits of msg : ");
    scanf("%d",&m);

    if(m<n){
        printf("ERROR!! Size of the msg is less than the code\n");
        return;
    }

    printf("Enter the msg : ");
    for(i=0;i<m;i++){
        scanf("%d",&msg1[i]);
        msg2[i]=msg1[i];
    }

    for(i=m;i<m+n-1;i++)
        msg2[i]=0;

    p=0;
    for(k=0;k<m;k++){
        if(msg2[p]==1){
            for(i=p, j=0;i<p+n;i++,j++)
                msg2[i] ^= code[j];
        }else{
            for(i=p;i<p+n;i++)
                msg2[i] ^=0;
        }
        p++;
    }

    for(i=m;i<m+n-1;i++)
        msg1[i]=msg2[i];

    printf("Transmitted msg is : ");
    for(i=0;i<m+n-1;i++)
        printf("%d",msg1[i]);
    printf("\n");

    printf("Do you want to Insert Error YES(1), NO(0) : ");
    scanf("%d",&err);

    if(err){
        printf("Enter the position to be changed : ");
        scanf("%d",&e);

        if(e>m+n-1){
            printf("Invalid Position!!");
        }else{
            msg1[e-1] = !(msg1[e-1]);
            fail=0;
        }
    }

    printf("Received Msg is : ");
    for(i=0;i<m+n-1;i++)
        printf("%d",msg1[i]);
    printf("\n");

     if (fail)
        printf ("\n successful transfer of message\n");
    else{
    printf ("\nError in the message");}
}
