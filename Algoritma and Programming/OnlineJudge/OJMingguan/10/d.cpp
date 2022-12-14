#include <stdio.h>
#include <string.h>

int partition(char nama[101][101], int low, int high)
{
    char pivot[101];
    strcpy(pivot,nama[high]);
    int i = low - 1;
    int j = low;

    while (j < high)
    {
        if (strcmp(nama[j], pivot) <= 0)
        {
            i++;
            char temp[101];
            strcpy(temp, nama[j]);
            strcpy(nama[j], nama[i]);
            strcpy(nama[i], temp);
        }
        j++;
    }
    strcpy(nama[high], nama[i + 1]);
    strcpy(nama[i + 1], pivot);
    return (i + 1);
}

void quickSort(char nama[101][101], int low, int high)
{
    if (low < high)
    {
        int pos = partition(nama, low, high);
        quickSort(nama, low, pos - 1);
        quickSort(nama, pos, high);
    }
}
int main()
{
    int cases;
    scanf("%d", &cases);

    int size;
    int find;
    for (int i = 0; i < cases; i++)
    {
        scanf("%d %d", &size, &find);
        char nama[101][101];
        for (int j = 0; j < size; j++)
        {
            scanf("%s", nama[j]);
        }
        quickSort(nama, 0, size - 1);
        printf("Case #%d: %s\n",i+1,nama[find-1]);

    }
}