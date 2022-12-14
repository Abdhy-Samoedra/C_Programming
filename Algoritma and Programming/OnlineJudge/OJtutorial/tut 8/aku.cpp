#include <stdlib.h>
#include <stdio.h>

int main()
{
    int jumlah;
    scanf("%d", &jumlah);

    long long angka;
    int querry;
    long long prefiks[5050] = {};
    long long arr[5050];

    long long x;

    prefiks[0] = 0;

    for (int j = 1; j <= jumlah; j++)
    {
        scanf("%lld", &x);
        prefiks[j] = x + prefiks[j - 1];
    }

    scanf("%d", &querry);

    for (int i = 0; i < querry; i++)
    {

        scanf("%lld", &angka);
        int maxx = -1;

        for (int j = 0; j < jumlah; j++)
        {
            for (int k = jumlah; k >= j + 1; k--)

            {

                if (prefiks[k] - prefiks[j] <= angka)
                {
                    if (k - j > maxx)
                    {

                        maxx = k - j;
                        break;
                    }
                    if (k - j < maxx)
                        break;
                }
            }
        }
        printf("Case #%d: %d\n", i + 1, maxx);
    }
}
