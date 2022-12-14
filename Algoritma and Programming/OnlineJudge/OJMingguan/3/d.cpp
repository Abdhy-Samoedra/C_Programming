#include <stdio.h>

int main()
{
    int kasus, jumlah, sum2;
    long long int angka[2000],sum;

    scanf("%d", &kasus);
    for (int i = 0; i < kasus; i++)
    {
        sum = 0;
        sum2 = 0;
        scanf("%d", &jumlah);

        for (int k = 0; k < jumlah; k++)
        {
            scanf("%lld", &angka[k]);
            sum += angka[k];
        }
        for (int j = 0; j < jumlah; j++)
        {
            if (angka[j] > sum)
            {
                sum2++;
            }
        }

        printf("Case #%d: %lld\n", i + 1, sum);
        printf("%d\n", sum2);
    }
}