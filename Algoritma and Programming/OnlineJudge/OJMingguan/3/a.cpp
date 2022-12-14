#include <stdio.h>

int main()
{
    int luas[101][101];
    int x, y, T, a, b, ganti;
    scanf("%d %d", &x, &y);

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            scanf("%d", &luas[i][j]);
        }
    }

    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        scanf("%d %d %d", &a, &b, &ganti);
        luas[a - 1][b - 1] = ganti;
    }

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("%d", luas[i][j]);
            

            if (j < y-1 )
            {
                printf(" ");
            }
            
        }printf("\n");
    }

    return 0;
}