#include "stdio.h"

void merge(int arr[], int left, int midindex, int right)
{
    int i, j, mergeindex;
    int leftindex = midindex - left + 1;
    int rightindex = right - midindex;

    int Leftmerge[leftindex], RightMerge[rightindex];

    for (i = 0; i < leftindex; i++)
        Leftmerge[i] = arr[left + i];
    for (j = 0; j < rightindex; j++)
        RightMerge[j] = arr[midindex + 1 + j];

    i = 0;
    j = 0;
    mergeindex = left;
    while (i < leftindex && j < rightindex)
    {
        if (Leftmerge[i] <= RightMerge[j])
        {
            arr[mergeindex] = Leftmerge[i];
            i++;
        }

        else
        {
            arr[mergeindex] = RightMerge[j];
            j++;
        }
        mergeindex++;
    }

    while (i < leftindex)
    {
        arr[mergeindex] = Leftmerge[i];
        i++;
        mergeindex++;
    }

    while (j < rightindex)
    {
        arr[mergeindex] = RightMerge[j];
        j++;
        mergeindex++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {

        int midindex = left + (right - left) / 2;

        mergeSort(arr, left, midindex);
        mergeSort(arr, midindex + 1, right);

        merge(arr, left, midindex, right);
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
    int arr[] = {1, 9, 7, 5, 4, 2, 3, 6, 8, 0};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, arr_size);
    mergeSort(arr, 0, arr_size - 1);
    printArray(arr, arr_size);
    return 0;
}