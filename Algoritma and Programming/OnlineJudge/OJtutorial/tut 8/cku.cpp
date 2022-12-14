#include <stdio.h>

void quickSort(int arr[], int left, int right)
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
int lower(int arr[], int N, int X)
{
    int mid;
    int low = 0;
    int high = N;
    while (low < high)
    {
        mid = low + (high - low) / 2;

        if (X <= arr[mid])
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    if (low < N && arr[low] < X)
    {
        low++;
    }

    return low;
}

int main()
{
    int jumlah, panggil, dipanggil;
    scanf("%d", &jumlah);

    int tinggi[100050];
    for (int i = 0; i < jumlah; i++)
    {
        scanf("%d", &tinggi[i]);
    }
    quickSort(tinggi, 0, jumlah - 1);
    scanf("%d", &panggil);
    for (int i = 0; i < panggil; i++)
    {
        scanf("%d", &dipanggil);
        if (dipanggil < tinggi[0] || dipanggil > tinggi[jumlah - 1])
        {
            printf("-1\n");
            continue;
        }
        int found = lower(tinggi, jumlah - 1, dipanggil);
        if (found == -1)
            printf("-1\n");
        else
        {
            if (tinggi[found] != dipanggil)
                printf("-1\n");
            else
                printf("%d\n", found + 1);
        }
    }
}