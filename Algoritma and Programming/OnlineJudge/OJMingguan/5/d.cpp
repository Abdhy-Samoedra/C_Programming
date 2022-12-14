#include <stdio.h>

int main()
{
    int tim;
    int count = 0;
    int baju;
    int arr[1000];

    scanf("%d", &tim);
    for (int i = 0; i < tim * tim; i++)
    {
        scanf("%d", &baju);
        arr[baju]++;
    }
    for (int j = 1; j <= tim; j++)
    {
        if (arr[j] < tim)
        {
            count++;
        }
    }
    printf("%d\n", count);
}