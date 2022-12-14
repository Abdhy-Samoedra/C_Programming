#include <stdio.h>

int main()
{
    int kasus;
    scanf("%d", &kasus);
    int size;
    for (int i = 0; i < kasus; i++)
    {
        
        scanf("%d", &size);
        int matrix[1001][1001   ] = {};
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                scanf("%d", &matrix[j][k]);
            }
        }
        printf("Case #%d: ", i + 1);
        int result = 0;
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                result += matrix[k][j];
            }
            printf("%d", result);
            if (j < size-1)
            {
                printf(" ");
            }
            result = 0;
        }
        
        printf("\n");
    }
}