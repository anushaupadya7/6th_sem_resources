#include <stdio.h>
#include <string.h>

int main() 
{
    char rem[50], code[100], gen[50], temp[100];
    int codelen, genlen, i,pos,e;

    printf("Enter the code :");
    scanf("%s", &code);

    printf("Enter the generator:");
    scanf("%s", &gen);

    codelen = strlen(code);
    genlen = strlen(gen);

    code[codelen] = '\0';
    rem[genlen] = '\0';
    // printf("codelen=%d\n",code[codelen]);
    // printf("genlen=%d\n",gen[codelen]);

    // Append 0 at the end
    strcpy(temp, code);
    for (i = 0; i < genlen-1; i++)
    {
        temp[codelen + i] = '0';
    }

    
    // XOR operation
    for (int j = 0; j < codelen; j++)
    {
        // When you perform XOR operation first position should be 1 itself as per algorithm
        if (temp[j] != '0')
        {
            for (int k = 0; k < genlen; k++)
            {
               rem[k] = temp[j+k] = (temp[j+k] == gen[k]) ? '0' : '1';
            }
        }
        // printf("%s\n",temp);
        // printf("%s\n",rem);
    }

    // Reduce remainder
    for (int i = 0; i < genlen; i++)
    {
        rem[i] = rem[i+1];
    }
    
    printf("Message recieved at reciever site: %s",strcat(code,rem));

    printf ("\n Introduce error?? yes or no[1 or 0]:\n");
    scanf ("%d", &e);
    
    if (e==1)
    {
        printf("enter the position to be changed:");
        scanf("%d",&pos);

        if( code[pos-1]==0)
            code[pos-1]=1;
        else
            code[pos-1]=0;
    }

    printf ("Message received at receiver site:\n");

    for (i=0; i<m+n-1; i++)
        printf ("%s", code);
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