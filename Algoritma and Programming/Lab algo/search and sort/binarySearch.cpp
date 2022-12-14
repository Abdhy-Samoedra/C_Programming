#include <stdio.h>

void binarySearch()
{
    // binary search dimulai dari tengah
    int arr[] = {11, 12, 30, 40, 50};
    int length = sizeof(arr) / sizeof(arr[0]);

    int find = 40;
    int leftIdx = 0;
    int rightIdx = length - 1;
    int counter = 1;

    while (leftIdx <= rightIdx)
    {
        int midIdx = (rightIdx + leftIdx) / 2;
        // cek datanya sama atau tidak
        if (arr[midIdx] == find)
        {
            printf("ketemu nih %d di index %d\n", find, midIdx);
            counter = 0;
            break;
        }
        else if (arr[midIdx] < find)
        {
            leftIdx = midIdx + 1;
        }
        else if (arr[midIdx] > find) 
        {
            rightIdx = midIdx - 1;
        }
    }
    if (counter == 1)
    {
        printf("tidak ada nih anying\n");
    }
}

int main()
{
    binarySearch();
    return 0;
}
