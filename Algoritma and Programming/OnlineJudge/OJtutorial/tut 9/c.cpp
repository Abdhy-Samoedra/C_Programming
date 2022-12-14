#include <stdio.h>

int main()
{
    FILE *data;
    data = fopen("testdata.in", "r");
    int size;
    fscanf(data, "%d\n", &size);

    char kata[1000];
    int page = 1;
    int count = 0;
    int count2 = 1;

    while (fscanf(data, "%s", kata) == 1)
    {
        if (kata[0] == '#')
        {
            if (count < size)
            {
                count2 = 0;
                printf("page %d: %d word(s)\n", page, count);
            }
            count = 0;
            page++;
        }
        else
        {
            count++;
        }
    }

    if (count2 == 1)
    {
        printf("The essay is correct\n");
    }

    fclose(data);
    return 0;
}