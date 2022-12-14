#include <stdio.h>
long long tinggi[5000];
void quickSort(long long arr[], int left, int right)
{
    int i = left, j = right;
    long long tmp;
    long long pivot = arr[(left + right) / 2];

    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };

    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}
int main()
{
    int kasus;
    scanf("%d", &kasus);

    int jumlah;
    for (int i = 0; i < kasus; i++)
    {
        scanf("%d", &jumlah);
        for (int j = 0; j < jumlah; j++)
        {
            scanf("%lld", &tinggi[j]);
        }

        quickSort(tinggi, 0, jumlah - 1);
        long long maxx = 0;
        for (int j = 1; j < jumlah / 2; j++)
        {
            if (j == 1)
            {
                maxx = tinggi[j] - tinggi[j - 1];
            }
            else
            {
                if (tinggi[j] - tinggi[j - 1] > maxx)
                    maxx = tinggi[j] - tinggi[j - 1];
            }
        }
        for (int j = jumlah / 2 + 1; j < jumlah; j++)
        {
            if (tinggi[j] - tinggi[j - 1] > maxx)
                maxx = tinggi[j] - tinggi[j - 1];
        }

        printf("Case #%d: %lld\n", i + 1, maxx);
    }
}