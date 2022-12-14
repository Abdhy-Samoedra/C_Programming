#include <stdio.h>

/*
t       -> 1 - 10
n       -> 1 - 240
bunga   -> 1 - 10
saldo   -> 1 - 2 * 10^9
*/
int main()
{
    int t, n;
    double bunga;
    long long saldo;
    scanf("%d", &t);
    for (int tc = 0; tc < t; tc++)
    {
        scanf("%lld %lf %d", &saldo, &bunga, &n);
        printf("Case #%d:\n", tc + 1);
        for (int i = 0; i < n; i++)
        {
            saldo *= ((bunga / 100 / 12) * 0.8 + 1);
            printf("%d %lld\n", i + 1, saldo);
        }
    }
    return 0;
}
