#include <stdio.h>
#include <string.h>

long long int MAXX = __LONG_LONG_MAX__;

void print(int pos, int k, int arr[], long long mid, int fin)
{
    long long count = 0;
    int cek = -1;
    for (int i = pos; i >= 0; i--)
    {
        if (count + arr[i] > mid || i == k - 2)
        {
            print(i, k - 1, arr, mid, fin);
            cek = i;
            break;
        }
        count += arr[i];
    }

    if (cek >= 0)
    {
        printf("; ");
    }
    for (int i = cek + 1; i <= pos; i++)
    {
        if (i == fin - 1)
            printf("%d", arr[i]);
        else
            printf("%d ", arr[i]);
    }
}

int check(int arr[], int gap, long long mid, int n)
{
    int temp = n, i = 0, cek = 1;
    long long sum = 0;
    while (i < n)
    {
        if (arr[i] > mid)
            return 0;
        if (sum + arr[i] > mid)
        {
            cek++;
            sum = 0;
        }
        if (sum <= mid)
        {
            sum += arr[i];
            i++;
        }
    }

    if (cek <= gap)
        return 1;
    return 0;
}

long long binarySearch(int arr[], int gap, int n)
{
    long long low = 1, high = MAXX, ans = MAXX, mid;
    while (low < high)
    {
        mid = low + (high - low) / 2;
        int flag = check(arr, gap, mid, n);
        if (flag)
        {
            ans = (ans < mid) ? ans : mid;
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int cases;
    scanf("%d", &cases);

    while (cases--)
    {
        int city, staff;
        scanf("%d %d", &city, &staff);
        int arr[city + 1];
        for (int i = 0; i < city; i++)
            scanf("%d", &arr[i]);
        long long limit = binarySearch(arr, staff, city);
        print(city - 1, staff, arr, limit, city);
        puts("");
    }
    return 0;
}