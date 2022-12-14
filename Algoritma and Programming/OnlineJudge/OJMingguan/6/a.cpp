#include <stdio.h>

void cetak1(char nama[100], double tinggi, int umur)
{
    printf("Name 1: %s\n",nama);
    printf("Height 1: %.2lf\n",tinggi);
    printf("Age 1: %d\n",umur);
}
void cetak2(char nama[100], double tinggi, int umur)
{
    printf("Name 2: %s\n",nama);
    printf("Height 2: %.2lf\n",tinggi);
    printf("Age 2: %d\n",umur);
}

void input(char nama[100], double tinggi, int umur)
{
    scanf("%s %lf %d",nama,&tinggi,&umur);
    cetak1(nama,tinggi,umur);
    scanf("%s %lf %d",nama,&tinggi,&umur);
    cetak2(nama,tinggi,umur);
}

int main()
{
    char nama[100];
    double tinggi;
    int umur;

    input(nama,tinggi,umur);
}