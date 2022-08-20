#include<stdio.h>
#include<stdlib.h>

int main()
{
    int c[50],b[50],a[17]={1, 0, 0};
    int i,j,m,n=3,q,r,x,y,z,e,pos,fail=1;

    printf ("Enter no of bits for messages:\n");
    scanf ("%d",&m);
    
    printf ("Enter the message to be transmitted:\n");
    for (i=0; i<m; i++)
    {
        scanf("%d", &b[i] );
        c[i]=b[i];
    }

    for (i=m; i<m+n-1; i++) // append n-1 zeros at the end of message
        b[i] = 0;

    if ( m<n )
    {
        printf ("error!!! enter bits again");
        exit (0);
    }

    else
    {
        y=0;
        for (i=0;i<m;i++)
        {
            if (b[y]==1)
            for (x=y,j=0; x<y+n; x++, j++)
            b[x] = b[x] ^ a[j];
            else
            for (x=y; x<y+n; x++)
            b[x] = b[x] ^ 0;
            y++;
        }
    }

    for (i=m; i<m+n-1; i++)
        c[i] = b[i];

    printf ("message to be sent is:\n");
    for (i=0; i<m+n-1; i++)
        printf ("%d", c[i]);

    printf ("\n Introduce error?? yes or no[1 or 0]:\n");
    scanf ("%d", &e);
    
    if (e==1)
    {
        printf("enter the position to be changed:");
        scanf("%d",&pos);

        if( pos>m)
        printf ("\ninvalid position!!");
        else
        if( c[pos-1]==0)
            c[pos-1]=1;
        else
            c[pos-1]=0;
    }

    printf ("message received at receiver site:\n");

    for (i=0; i<m+n-1; i++)
        printf ("%d", c[i]);
        z = 0;
        for (i=0; i<m; i++)
        {
            if (c[z]==a[0])
            {
            for (x=z,j=0; x<z+n; x++, j++)
                 c[x] = c[x] ^ a[j];
            }
            else
            {
                 for (x=z; x<z+n; x++)
                 c[x] = c[x] ^ 0;
            }
            z++;
        }

        for (i=0; i<m+n-1; i++)
        {
            if (c[i]==1)
            {
                printf ("\n error in the message!!!\n");
                fail = 0;
                break;
            }
        }
        if (fail)
            printf ("\n successful transfer of message\n");
        return 0;
    }
