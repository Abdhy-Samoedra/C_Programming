#include <stdio.h>

int AtoB(int awal, int akhir)
{
    if (awal == akhir)
    {
        return awal;
    }
    else if (awal != akhir)
    {
        if (awal == 1)
        {
            return awal;
        }
        else if (awal % 2 == 0)
        {
            awal = awal / 2;
            return AtoB(awal, akhir);
        }
        else if (awal % 2 == 1)
        {
            awal = awal * 3 + 1;
            return AtoB(awal, akhir);
        }
    }
}

int main()
{

    int kasus;
    int awal, akhir;
    int hasil;

    scanf("%d", &kasus);
    for (int i = 0; i < kasus; i++)
    {
        scanf("%d %d", &awal, &akhir);
        hasil = AtoB(awal, akhir);

        if (hasil == akhir)
        {
            printf("Case #%d: YES\n", i + 1);
            hasil = 0;
        }
        else
        {
            printf("Case #%d: NO\n", i + 1);
            hasil = 0;
        }
    }

    // int kasus;
    // int awal, akhir;

    // scanf("%d", &kasus);

    // for (int i = 0; i < kasus; i++)
    // {
    //     scanf("%d %d", &awal, &akhir);

    //     while (awal != 1 && akhir != awal)
    //     {
    //         if (awal % 2 == 0)
    //         {
    //             awal = awal / 2;
    //         }
    //         else if (awal % 2 == 1)
    //         {
    //             awal = awal * 3 + 1;
    //         }
    //     }
    //     if (akhir == awal)
    //     {
    //         printf("Case #%d: YES\n", i + 1);
    //     }
    //     else
    //     {
    //         printf("Case #%d: NO\n", i + 1);
    //     }
    // }
}