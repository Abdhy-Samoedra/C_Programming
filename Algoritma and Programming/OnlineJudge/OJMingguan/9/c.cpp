#include <stdio.h>
int binarySearch(long long int batas, int size, long long int total[])
{
    int low = 0;
    int high = size - 1;
    int mid;

    while (low < high)
    {
        mid = (low + high) / 2;
        if (batas <= total[mid])
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    if (total[low] == batas)
    {
        return low;
    }
    else
    {
        return low - 1;
    }
}

int main()
{
    int size;

    scanf("%d", &size);
    long long int angka[100001];
    long long int temp = 0;
    long long int total[100000] = {};
    for (int i = 0; i < size; i++)
    {
        scanf("%lld", &angka[i]);
        temp += angka[i];
        total[i] = temp;
    }

    long long int kasus;
    scanf("%lld", &kasus);
    long long int batas;
    for (int i = 0; i < kasus; i++)
    {
        scanf("%lld", &batas);
        int result = binarySearch(batas, size, total);
        if (total[0] > batas)
        {
            result = -2;
        }
        else if (total[size - 1] < batas)
        {
            result = size - 1;
        }
        printf("Case #%d: %d\n", i + 1, result + 1);
    }
}