#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,j,qs,t,count,size,a,p[10],cap,rate,delay,flag=1,t1,t2;
    printf("enter the queue size:");
    scanf("%d",&size);
    count=size;
    printf("enter leaky bucket capacity:");
    scanf("%d",&cap);
    qs=cap;
    printf("enter the size of the packets in the queue:");
    for(i=0;i<size;i++)
    {
        scanf("%d",&a);
        if(a>cap)
        {
            i--;
            printf("packets cannot be entered");
        }
        else
            p[i]=a;
    }
    printf("enter the output rate:");
    scanf("%d",&rate);
    delay=cap/rate;
    printf("delay=%d\n",delay);
    while(flag)
    {
        qs=cap;
        while(qs>=p[0]&&count>0)
        {
            printf("\npacket of size %d is put into the bucket\n",p[0]);
            qs=qs-p[0];
            printf("\navailable space %d\n",qs);
            count--;
            for(i=0;i<count;i++)
                p[i]=p[i+1];
        }
        t=delay;
        long int t1=(long)time(NULL);
        long int t2=(long)time(NULL);
        while((t2-t1)<delay)
        {
            t2=(long)time(NULL);
            if((delay-t)==(t2-t1))
            {
                printf("\ntransmitting packets in the leaky bucket:%d seconds\n",t);
                t--;
            }
        }
        if (count>0)
        {
            printf("\npackets in the queue:\n");
            for(i=0;i<count;i++)
                printf("%d\t",p[i]);
        }
        else{
            printf("All the packets are transmitted\n");
        }
        
        if(count==0)
            flag=0;
    }
}

