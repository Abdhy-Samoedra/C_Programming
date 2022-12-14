#include <stdio.h>

int main()
{
    long long int size, max;
    long long int count = 0;
    

    scanf("%lld", &size);
    long long int arr[size];

    for (int i = 0; i < size; i++)
    {
        scanf("%lld", &arr[i]);
        count = count + arr[i];
    }
    for (int j = 0; j < size; j++)
    {
        if (arr[j] % 2 != 0)
        {
            max = arr[j];
        }
    }
    for (int k = 0; k < size; k++)
    {
        if (arr[k] % 2 != 0)
        {
            if (arr[k] < max)
            {
                max = arr[k];
            }
        }
    }


    if (count % 2 == 0)
    {
        printf("%lld\n", count);
    }else
    {
        printf("%lld\n", count - max);
    }
    
    
}