#include <stdio.h>
int partition(long long int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    int j = low;

    while (j < high)
    {
        if (arr[j] <= pivot)
        {
            i++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
        j++;
    }
    arr[high] = arr[i + 1];
    arr[i + 1] = pivot;
    return (i + 1);
}
void quickSort(long long int arr[], int low, int high)
{
    if (low < high)
    {
        int pos = partition(arr, low, high);
        quickSort(arr, low, pos - 1);
        quickSort(arr, pos, high);
    }
}

int main()
{
    int cases;
    scanf("%d", &cases);

    int size = 25;
    long long int arr[100];
    for (int j = 0; j < cases; j++)
    {
        for (int i = 0; i < size; i++)
        {
            scanf("%lld", &arr[i]);
        }
        quickSort(arr, 0, size - 1);
        int hasil = 0;
        for (int i = 0; i < size; i++)
        {
            hasil += arr[i];
        }

        int a = arr[0] / 2;
        int b = arr[1] - a;
        int e = arr[size - 1] / 2;
        int d = arr[size - 2] -e;
        // int c = (hasil - (10 * a + 10 * b + 10 * d + 10 * e)) / 10;
        int c = arr[4] - a;
        printf("Case #%d: %d %d %d %d %d\n", j + 1, a, b, c, d, e);
        hasil = 0;
    }
}