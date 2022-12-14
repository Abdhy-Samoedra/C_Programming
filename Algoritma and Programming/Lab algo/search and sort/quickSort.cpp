#include <stdio.h>

int partition(int arr[], int low, int high)
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

void quickSort(int arr[], int low, int high)
{

    if (low < high)
    {

        int pos = partition(arr, low, high);
        quickSort(arr, low, pos - 1);
        quickSort(arr, pos+1, high);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{

    int numbers[] = {1, 9, 7, 5, 5, 4, 2, 3, 6, 6, 8};
    int arraySize = 11;

    printArray(numbers, arraySize);
    quickSort(numbers, 0, arraySize - 1);
    printArray(numbers, arraySize);

    return 0;
}