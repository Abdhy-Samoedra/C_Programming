#include <stdio.h>
#include <string.h>

int main()
{
    FILE *ice;
    ice = fopen("testdata.in", "r");
    int kasus;
    int jumlah;
    int area = 0;
    int perim1 = 0;
    int es[1000];
    int diff = 0;
    int temp = 0;

    fscanf(ice, "%d", &kasus);

    for (int i = 0; i < kasus; i++)
    {
        fscanf(ice, "%d", &jumlah);

        for (int j = 0; j < jumlah; j++)
        {
            fscanf(ice, "%d", &es[j]);
        }
        for (int j = 0; j < jumlah; j++)
        {
            area += es[j] * 4;
        }

        perim1 = es[0] * 2 + es[jumlah - 1] * 2;
        temp = 4 * jumlah;
        perim1 = perim1 + temp;

        for (int j = 0; j < jumlah-1; j++)
        {
            if (es[j] >= es[j + 1])
            {
                diff = es[j] - es[j + 1];
                perim1 = perim1 + 2 * diff;
            }
            else if (es[j] < es[j+1])
            {
                diff = es[j + 1] - es[j];
                perim1 = perim1 + 2 * diff;
            }
        }

        printf("Case #%d: %d %d\n", i + 1, perim1, area);
        area = 0;
        perim1 = 0;
        diff = 0;
        temp = 0;
        
    }
}