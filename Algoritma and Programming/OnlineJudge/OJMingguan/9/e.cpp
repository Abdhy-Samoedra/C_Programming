#include <stdio.h>

int main()
{
    int cases;
    scanf("%d", &cases);

    int size;
    long long int batas;

    for (int i = 0; i < cases; i++)
    {
        scanf("%d %lld", &size, &batas);
        long long int number[size];
        for (int j = 0; j < size; j++)
        {
            scanf("%lld", &number[j]);
        }

        long long int max = 0;
        for (int j = 0; j < size; j++)
        {
            long long int count = 0;
            long long int result = 0;
            for (int k = j; k < size; k++)
            {
                if (result + number[k] <= batas)
                {
                    result += number[k];
                    count++;
                    if (count > max)
                    {
                        max = count;
                    }
                }
                else
                {
                    break;
                }
            }

            count = 0;
            result = 0;
        }
        if (max == 0)
        {
            printf("Case #%d: -1\n", i + 1);
        }
        else
        {
            printf("Case #%d: %lld\n", i + 1, max);
        }

        max = 0;
    }
}