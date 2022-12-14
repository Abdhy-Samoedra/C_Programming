#include <stdio.h>

int main()
{
    int kasus, size;
    long long int arr[100][100],count;

    scanf("%d", &kasus);
    for (int i = 0; i < kasus; i++)
    {
        scanf("%d", &size);
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                scanf("%lld", &arr[j][k]);
            }
        }
        printf("Case #%d: ",i+1);
        for (int l = 0; l < size; l++)
        {
            count=0;
            for (int m = 0; m < size; m++)
            {
                count = count + arr[m][l];
            }
            printf("%lld",count);
            if (l<size-1)
            {
                printf(" ");
            }
            
            
        }
        printf("\n");
        
    }
}