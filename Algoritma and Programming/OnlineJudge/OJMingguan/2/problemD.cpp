#include <stdio.h>

int main()
{
    int panjang;
    scanf("%d",&panjang);
    for (int i = 0; i < panjang; i++)
    {
        for (int j = 0; j < panjang; j++)
        {
            printf("*");
        }
        
        printf("\n");
    }
    

    return 0;
}