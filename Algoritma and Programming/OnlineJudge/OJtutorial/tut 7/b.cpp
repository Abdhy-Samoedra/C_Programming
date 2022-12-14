#include <stdio.h>

int hitung(int angka[], int hari)
{
    if (hari <= 0)
    {
        return 0;
    }

    return (hitung(angka, hari - 1) + angka[hari - 1]);
}

int main()
{
    int kasus;
    int hari;
    int angka[100001];
             
    scanf("%d", &kasus);
    for (int i = 0; i < kasus; i++)
    {
        scanf("%d", &hari);
        for (int j = 0; j < hari; j++)
        {
            scanf("%d", &angka[j]);
        }
        printf("Case #%d: %d\n", i + 1, hitung(angka, hari));
    }
}