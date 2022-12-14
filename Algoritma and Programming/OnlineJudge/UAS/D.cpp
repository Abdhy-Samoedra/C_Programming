#include <stdio.h>

long long length;
int target;
long long array[100000];
long long count = 0;
long long last;

void mergeSort(long long array[], long long low, long long high)
{

    int i;
    int j;
    int k;

    if (low < high)
    {
        long long mid = low + (high - low) / 2;
        mergeSort(array, low, mid);
        mergeSort(array, mid + 1, high);
        long long left = mid - low + 1;
        long long right = high - mid;
        long long leftArray[left];
        long long rightArray[right];
        for (i = 0; i < left; i++)
        {
            leftArray[i] = array[low + i];
        }
        for (j = 0; j < right; j++)
        {
            rightArray[j] = array[mid + 1 + j];
        }

        i = 0, j = 0, k = low;

        while (i < left && j < right)
        {
            if (leftArray[i] <= rightArray[j])
            {
                array[k] = leftArray[i];
                i++;
            }
            else
            {
                array[k] = rightArray[j];
                j++;
            }
            k++;
        }

        while (i < left)
        {
            array[k] = leftArray[i];
            i++;
            k++;
        }

        while (j < right)
        {
            array[k] = rightArray[j];
            j++;
            k++;
        }
    }
}

long long binarySearch(long long array[], long long size, long long start, long long target, long long pivot)
{
    long long left = start, right = size - 1;
    while (left <= right)
    {
        long long mid = (right + left) / 2;
        long long temp = target - pivot;
        if (temp <= 0)
        {
            return 0;
        }
        if (array[mid] == temp && array[mid] > pivot)
        {
            return 1;
        }
        if (array[mid] > temp)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return 0;
}

int main()
{

    int cases;
    FILE *data;
    data = fopen("testdata2.txt", "r");
    while (!feof(data))
    {
        fscanf(data, "%d", &cases);
        for (int i = 0; i < cases; i++)
        {
            fscanf(data, "%lld %d", &length, &target);
            for (int j = 0; j < length; j++)
            {
                fscanf(data, "%lld", &array[j]);
            }
            mergeSort(array, 0, length - 1);
            for (int j = 0; j < length; j++)
            {
                if (array[j] == last)
                    continue;
                if (target - array[j] <= 0)
                    break;
                count = count + binarySearch(array, length, j, target, array[j]);
                last = array[j];
            }
            printf("Case#%d:%lld\n", i + 1, count);
            count = 0;
        }
    }
}