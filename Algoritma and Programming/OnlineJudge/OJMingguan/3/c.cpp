#include <stdio.h>

int main()
{
    int jumlah;
    int barang[100000];
    int jumlah2;
    int update;
    int awal, akhir;

    scanf("%d", &jumlah);

    for (int i = 0; i < jumlah; i++)
    {
        scanf("%d", &barang[i]);
    }

    scanf("%d", &jumlah2);

    for (int j = 0; j < jumlah2; j++)
    {
        scanf("%d %d", &awal, &akhir);
        barang[awal - 1] = akhir;
        printf("Case #%d: ", j + 1);
        for (int k = 0; k < jumlah; k++)
        {
            printf("%d", barang[k]);
            if (k < jumlah - 1)

            printf(" ");
            
        }
        printf("\n");
    }
}