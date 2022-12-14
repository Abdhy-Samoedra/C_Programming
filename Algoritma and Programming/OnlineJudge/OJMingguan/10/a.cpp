#include <stdio.h>
#include <math.h>

int main()
{
    int size;
    scanf("%d", &size);

    int batas = pow(2, size) - 1;
    int r = 0;
    while (batas > 0)
    {
        for (int j = 0; j < batas; j++)
        {
            for (int k = 0; k < pow(2, r) - 1; k++)
            {
                printf(" ");
            }
            printf("*");
        }
        r++;
        batas = batas / 2;
        printf("\n");
    }
}