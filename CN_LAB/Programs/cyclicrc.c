#include<stdio.h>
#include<stdlib.h>
int main()
{
	int c[50],b[50];
	int i,j,m,n=3,e,pos,fail=1;
	printf("Enter no of bits for messages:\n");
	scanf("%d",&m);
	printf("Enter the message to be transmitted:\n");
	for(i=0;i<m;i++)
	{
		scanf("%d",&b[i] );
 		c[i]= b[i];
	}
	for(i=m;i<m+n-1;i++) // append n-1 zeros at the end of message
		c[i]=b[i]=0;

	if(m<n)
	{
		printf("Error!!!Enter bits again");
		exit(0);
	}
	
	printf ("Message to be sent is:\n");
	for (i=0; i<m+n-1; i++)
 		printf ("%d", c[i]);

	printf ("\nIntroduce error?? yes or no[1 or 0]:\n");
	scanf ("%d", &e);
	if (e==1)
	{
 		printf("Enter the position to be changed:");
 		scanf("%d",&pos);
		if( pos>m)
			printf ("\nInvalid position!!");
		else
			if(c[pos-1]==0)
			{
				c[pos-1]=1;
				fail=0;
			}
 else
			{
				c[pos-1]=0;
				fail=0;
			}
				
	}
	printf ("message received at receiver site:\n");
	for (i=0; i<m+n-1; i++)
		printf ("%d", c[i]);

	if (fail)
		printf ("\n successful transfer of message\n");
	else{
	printf ("Error in the message");
}
return 0;
}