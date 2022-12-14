#include <stdio.h>
#include <string.h>

int main() 
{
    int kasus;
    int arr[1001];
    char kata[1001];

    scanf("%d",&kasus);

    for (int i = 0; i < kasus; i++)
    {
        scanf("%s",kata);
        for (int j = 0; j < strlen(kata); j++)
        {
            if (kata[j] == 'A' || kata[j] == 'B' || kata[j] == 'C' || kata[j] == 'D')
            {
                arr[j] = kata[j] - 'A';
                kata[j] = 'A';
            }
            if (kata[j] == 'E' || kata[j] == 'F' || kata[j] == 'G' || kata[j] == 'H')
            {
                arr[j] = kata[j] - 'E';
                kata[j] = 'E';
            }
            if (kata[j] == 'I' || kata[j] == 'J' || kata[j] == 'K' || kata[j] == 'L' || kata[j] == 'M' || kata[j] == 'N')
            {
                arr[j] = kata[j] - 'I';
                kata[j] = 'I';
            }
            if (kata[j] == 'O' || kata[j] == 'P' || kata[j] == 'Q' || kata[j] == 'R' || kata[j] == 'S' || kata[j] == 'T' )
            {
                arr[j] = kata[j] - 'O';
                kata[j] = 'O';
            }
            if (kata[j] == 'U' || kata[j] == 'V' || kata[j] == 'W' || kata[j] == 'X' || kata[j] == 'Y' || kata[j] == 'Z' )
            {
                arr[j] = kata[j] - 'U';
                kata[j] = 'U';
            }
            
        }
        printf("Case #%d:\n",i+1);
        printf("%s\n",kata);
        for (int k = 0; k < strlen(kata); k++)
        {
            printf("%d",arr[k]);
        }
        printf("\n");
        
        
    }
    
}