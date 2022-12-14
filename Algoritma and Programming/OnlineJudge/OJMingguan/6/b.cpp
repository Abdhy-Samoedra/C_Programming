#include <stdio.h>

int main()
{
    int kasus;
    char nama[101];
    int nim;
    int umur;
    int pos;
    char tanggal[101];
    char tempat[101];
    char sma[101];
    int saudara;
    int tinggi;
    int rekening;
    scanf("%d", &kasus);

    for (int i = 0; i < kasus; i++)
    {
        scanf("%s", nama);
        scanf("%d", &nim);
        scanf("%d", &umur);
        scanf("%d", &pos);
        scanf("%s", tempat);
        getchar();
        scanf("%s", tanggal);
        getchar();
        scanf("%[^\n]", sma);
        getchar();
        scanf("%d", &saudara);
        scanf("%d", &tinggi);
        scanf("%d", &rekening);

        printf("Mahasiswa ke-%d:\n", i + 1);
        printf("Nama: %s\n", nama);
        printf("NIM: %d\n", nim);
        printf("Umur: %d\n", umur);
        printf("Kode Pos: %d\n", pos);
        printf("Tempat Lahir: %s\n", tempat);
        printf("Tanggal Lahir: %s\n", tanggal);
        printf("Almamater SMA: %s\n", sma);
        printf("Jumlah Saudara Kandung: %d\n", saudara);
        printf("Tinggi Badan: %d\n", tinggi);
        printf("NOMOR REKENING: %d\n", rekening);
    }
}