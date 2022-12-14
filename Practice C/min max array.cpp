#include <stdio.h>

int largest(int x[])
{
    int max = x[0];

    for (int i = 0; i < 10; i++)
    {
        if (max < x[i])
        {
            max = x[i];
        }
    }

    return max;
}

int smallest(int y[])
{
    int min = y[0];

    for (int i = 0; i < 10; i++)
    {
        if (y[i] < min)
        {
            min = y[i];
        }
    }

    return min;
}

void print_array(int z[])
{
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", z[i]);
    }
}

int main()
{
    int a[10];

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Max: %d\n", largest(a));
    printf("Min: %d\n", smallest(a));

    print_array(a);

    return 0;
}
