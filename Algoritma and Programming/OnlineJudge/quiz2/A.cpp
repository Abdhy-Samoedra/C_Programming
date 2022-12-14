#include <stdio.h>

int arr[400020];
long long int arr2[400020];
long long int batas;
int size;

long long int find()
{
    long long int max = 0;
    long long int sum = 0;
    int i = size;
    int j = size;
    int k = 0;

    while (i >= 0)
    {
        if (sum == batas)
        {
            return sum;
        }
        else if (sum < batas)
        {
            i--;
            k++;
            sum += (arr[i] * k);
        }
        else
        {
            k--;
            sum -= (arr2[i] - arr2[j]);
            j--;
        }

        if (sum > max && sum <= batas)
        {
            max = sum;
        }
    }
    return max;
}

int main()
{

    scanf("%d", &size);

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    long long int sum = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        sum += arr[i];
        arr2[i] = sum;
    }

    scanf("%lld", &batas);

    long long int hasil = find();

    printf("%lld\n", hasil);

    return 0;
}