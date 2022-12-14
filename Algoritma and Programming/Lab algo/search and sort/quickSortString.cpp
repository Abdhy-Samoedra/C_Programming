#include <stdio.h>
#include <string.h>

int partition(char lagu[100][100], int low, int high)
{
    char pivot[100];
    strcpy(pivot, lagu[high]);
    int i = low - 1;
    int j = low;

    while (j < high)
    {
        if (strcmpi(lagu[j], pivot) <= 0)
        {
            i++;
            char temp[100];
            strcpy(temp, lagu[j]);
            strcpy(lagu[j], lagu[i]);
            strcpy(lagu[i], temp);
        }
        j++;
    }
    strcpy(lagu[high], lagu[i + 1]);
    strcpy(lagu[i + 1], pivot);
    return (i + 1);
}

void quickSortLagu(char lagu[100][100], int low, int high)
{
    if (low < high)
    {
        int pos = partition(lagu, low, high);
        quickSortLagu(lagu, low, pos - 1);
        quickSortLagu(lagu, pos + 1, high);
    }
}

int main()
{
    int jumlah;
    scanf("%d", &jumlah);
    getchar();

    char lagu[100][100];

    for (int i = 0; i < jumlah; i++)
    {
        scanf("%[^\n]", lagu[i]);
        getchar();
    }

    quickSortLagu(lagu, 0, jumlah - 1);

    for (int i = 0; i < jumlah; i++)
    {
        printf("%s\n",lagu[i]);
    }
    
}