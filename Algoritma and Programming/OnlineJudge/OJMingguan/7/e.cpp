#include <stdio.h>

void rekursif(int arr[], int limit, int index, int sum)
{
    if (index == limit)
    {
        printf("%d\n", sum);
        return;
    }
    else if (2 * index == limit)
    {
        printf("%d\n", sum + arr[2 * index]);
        return;
    }
    else if (2 * index > limit)
    {
        printf("%d\n", sum);
        return;
    }
    rekursif(arr, limit, 2 * index, sum + arr[2 * index]);
    
    rekursif(arr, limit, (2 * index) + 1, sum + arr[(2 * index) + 1]);
}

int main()
{
    int kasus;
    int jumlah;
    scanf("%d", &kasus);
    for (int i = 1; i <= kasus; i++)
    {
        scanf("%d", &jumlah);
        int angka[jumlah + 1];
        for (int j = 1; j <= jumlah; j++)
        {
            scanf("%d", &angka[j]);
        }
        printf("Case #%d:\n", i);
        rekursif(angka, jumlah, 1, angka[1]);
    }
}