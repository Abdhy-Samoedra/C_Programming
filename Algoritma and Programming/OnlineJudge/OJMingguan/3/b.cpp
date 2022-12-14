#include <stdio.h>

int main()
{
    int jumlah;
    int index[1000];
    int input[1000];

    scanf("%d", &jumlah);

    for (int i = 0; i < jumlah; i++)
    {
        scanf("%d", &index[i]);
    }

    for (int j = 0; j < jumlah; j++)
    {
        scanf("%d", &input[index[j]]);
    }

    

    for (int k = 0; k < jumlah; k++)
    {
        printf("%d", input[k]);

        if (k < jumlah - 1)

            printf(" ");
    }
    printf("\n");
}
