#include <stdio.h>
#include <string.h>

int main ()
{
    int panjang1,panjang2,panjang3;
    char kata1[101],kata2[101],kata3[101];

    scanf("%d",&panjang1);getchar();
    for (int i = 0; i < panjang1; i++)
    {
        scanf("%c",&kata1[i]);
    }
    scanf("%d",&panjang2);getchar();
    for (int j = 0; j < panjang2; j++)
    {
        scanf("%c",&kata2[j]);
    }
    scanf("%d",&panjang3);getchar();
    for (int k = 0; k < panjang3; k++)
    {
        scanf("%c",&kata3[k]);
    }
    printf("%c%c\n",kata1[panjang1-1],kata1[0]);
    printf("%c%c\n",kata2[panjang2-1],kata2[0]);
    printf("%c%c\n",kata3[panjang3-1],kata3[0]);
    
    
}