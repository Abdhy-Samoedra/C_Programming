#include <stdio.h>
#include <string.h>

int main()
{
    FILE *alfabet;
    alfabet = fopen("testdata.in", "r");
    int kasus;

    fscanf(alfabet, "%d\n", &kasus);

    for (int i = 0; i < kasus; i++)
    {
        int jumlah = 0;
        int hitungAwal[100] = {};
        int hitung[200] = {};
        char awal;
        char akhir;
        int proses;
        char kataX[101] = {};
        fscanf(alfabet, "%s\n", kataX);
        fscanf(alfabet, "%d\n", &proses);
        for (int j = 0; j < proses; j++)
        {
            fscanf(alfabet, "%c %c\n", &awal, &akhir);

            if (hitungAwal[awal] != 1)
            {
                for (int k = 0; k < strlen(kataX); k++)
                {
                    if (kataX[k] == awal)
                    {
                        kataX[k] = akhir;
                    }
                }
                hitungAwal[awal]++;
            }
        }
        for (int j = 0; j < strlen(kataX); j++)
        {
            hitung[kataX[j]]++;
        }

        for (int k = 0; k < 200; k++)
        {
            if (hitung[k] != 0)
            {
                printf("%c %d\n", k, hitung[k]);
            }
        }
    }
}