#include <stdio.h>
int partition(int year[], int low, int high)
{
    int pivot = year[high];
    int i = low - 1;
    int j = low;

    while (j < high)
    {
        if (year[j] >= pivot)
        {
            i++;
            int temp = year[j];
            year[j] = year[i];
            year[i] = temp;
        }
        j++;
    }
    year[high] = year[i + 1];
    year[i + 1] = pivot;
    return (i + 1);
}

void quickSort(int year[], int low, int high)
{
    if (low < high)
    {
        int pos = partition(year, low, high);
        quickSort(year, low, pos - 1);
        quickSort(year, pos, high);
    }
}

int main()
{
    int cases;
    scanf("%d", &cases);
    int number;
    for (int i = 0; i < cases; i++)
    {
        scanf("%d", &number);
        int year[1000] = {};
        for (int j = 0; j < number; j++)
        {
            scanf("%d", &year[j]);
        }
        quickSort(year, 0, number - 1);

        int min = year[0] - year[1];
        int hasil = 0;
        for (int j = 0; j < number-1; j++)
        {
            hasil = year[j] - year[j + 1];
            if (hasil < min)
            {
                min = hasil;
            }
        }
        printf("Case #%d: %d\n",i+1,min);
    }
}