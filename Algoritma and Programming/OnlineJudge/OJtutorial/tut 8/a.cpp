#include <stdio.h>

int main()
{
    int size;
    scanf("%d", &size);

    int angka[5001];

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &angka[i]);

        int query;
        scanf("%d", &query);
        long long int elemen;
        for (int j = 0; j < query; j++)
        {
            scanf("%lld", &elemen);
        }
    }
}