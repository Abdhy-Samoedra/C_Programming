#include <stdio.h>

int binarySearch(int size1, int angka1[], int angka2)
{
    // binary search dimulai dari tengah
    // int angka1[] = {10, 20, 30, 40, 50};
    int length = size1;
    int result = -2;
    int find = angka2;
    int leftIdx = 0;
    int rightIdx = length - 1;
    int counter = 1;

    while (leftIdx <= rightIdx)
    {    
        int midIdx = (leftIdx + rightIdx) / 2;

        if (angka1[midIdx] < find)
        {
            leftIdx = midIdx + 1;
        }
        else
        {
            if (angka1[midIdx] == find)
            {
                result =  midIdx;
            }

            rightIdx = midIdx - 1;
        }
    }
    return result;
}

int main()
{
    int size1;
    int size2;    

    scanf("%d %d", &size1, &size2);

    int angka1[size1];
    int angka2[size2];
    for (int i = 0; i < size1; i++)
    {
        scanf("%d", &angka1[i]);
    }
    for (int i = 0; i < size2; i++)
    {
        scanf("%d", &angka2[i]);
    }
    for (int i = 0; i < size2; i++)
    {
        int hasil = binarySearch(size1, angka1, angka2[i]);
        printf("%d\n", hasil+1);
    }
}