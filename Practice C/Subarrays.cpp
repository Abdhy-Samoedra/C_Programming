#include <stdio.h>

void subArrays(int *array, int start, int end, int size)
{
    if (end == size)
        return;
    else if (start > end)
        subArrays(array, 0, end + 1, size);
    else
    {
        for (int i = start; i <= end; i++)
            printf("%d%s", array[i], i == end ? "\n" : " ");
        subArrays(array, start + 1, end, size);
    }
    return;
}
int main()
{
    int input, i;
    scanf("%d", &input);
    getchar();
    int values[input];
    for (i = 0; i < input; i++)
        scanf("%d", &values[i]);
    subArrays(values, 0, 0, input);
    return 0;
}
