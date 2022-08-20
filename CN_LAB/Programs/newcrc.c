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

    // Append 0 at the end
    strcpy(temp, code);
    for (i = 0; i < genlen-1; i++)
    {
        temp[codelen + i] = '0';
    }

    
    // XOR operation
    for (int j = 0; j < codelen; j++)
    {
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
    
    printf("%s",strcat(code,rem));

return 0;
}