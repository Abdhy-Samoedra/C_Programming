#include <stdio.h>
#include <string.h>

struct biodata
{
    char nama[255];
    char alamat[100];
} info[255];

int partition(biodata info[], int low, int high)
{
    biodata pivot = info[high];
    int i = low - 1;
    int j = low;

    while (j < high)
    {
        if (strcmpi(info[j].nama, pivot.nama) <= 0)
        {
            i++;
            biodata temp;
            temp = info[j];
            info[j] = info[i];
            info[i] = temp;
        }
        j++;
    }
    info[high] = info[i + 1];
    info[i + 1] = pivot;

    return (i + 1);
}

void quickSort(biodata info[], int low, int high)
{
    if (low < high)
    {
        int pos = partition(info, low, high);
        quickSort(info, low, pos - 1);
        quickSort(info, pos + 1, high);
    }
}

void binarySearch(biodata info[], int left, int right, char cari[])
{
    int count = 0;
    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (strcmpi(info[mid].nama, cari) == 0)
        {
            printf("%d\n",mid);
            
            printf("%s\n", info[mid].nama);
            printf("%s", info[mid].alamat);
            count++;
            break;
        }
        else if (strcmpi(cari, info[mid].nama) < 0)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    if (count == 0)
    {
        printf("tidak ada datanya");
    }
}

int main()
{
    int size;

    scanf("%d", &size);
    getchar();

    // biodata info[255];

    for (int i = 0; i < size; i++)
    {
        scanf("%[^\n]", info[i].nama);
        getchar();
        scanf("%[^\n]", info[i].alamat);
        getchar();
    }

    quickSort(info, 0, size - 1);

    for (int i = 0; i < size; i++)
    {
        printf("%s\n", info[i].nama);
        printf("%s\n", info[i].alamat);
    }

    char cari[255];
    scanf("%[^\n]", cari);
    getchar();

    binarySearch(info, 0, size - 1, cari);
}