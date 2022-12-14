#include <stdio.h>

void binarySearch(long long int* tB,int jumlah,long long int dipanggil)
{
    // binary search dimulai dari tengah
    // int arr[] = {10, 20, 30, 40, 50};
    // int length = sizeof(arr) / sizeof(arr[0]);

    int find = dipanggil;
    int leftIdx = 0;
    int rightIdx = jumlah - 1;

    while (leftIdx <= rightIdx)
    {
        int midIdx = (leftIdx + rightIdx) / 2;
        // cek datanya sama atau tidak
        if (tB[midIdx] == find)
        {
            printf("ketemu nih %d di index %d\n", find, midIdx);
            break;
        }
        else if (tB[midIdx] < find)
        {
            leftIdx = midIdx + 1;
        }
        else if (tB[midIdx] > find)
        {
            rightIdx = midIdx - 1;
        }
    }
}

int partition(long long int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    int j = low;

    while (j < high)
    {
        if (pivot >= arr[j])
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

        long long int pos = partition(arr, low, high);
        quickSort(arr, low, pos - 1);
        quickSort(arr, pos, high);
    }
}

int main()
{
    int jumlah;
    scanf("%d", &jumlah);
    long long int tB[1000];
    for (int i = 0; i < jumlah; i++)
    {
        scanf("%lld", &tB[i]);
    }

    quickSort(tB, 0, jumlah - 1);

    int panggil;
    scanf("%d", &panggil);
    long long int dipanggil[1000];
    for (int i = 0; i < panggil; i++)
    {
        scanf("%lld", &dipanggil);
        binarySearch(tB,jumlah,dipanggil);
    }


}
