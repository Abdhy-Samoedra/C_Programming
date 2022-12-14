#include <stdio.h>

int main ()
{
    int pinjaman;
    int hitung = 0;
    scanf("%d",&pinjaman);
    while (pinjaman<=0 || pinjaman>100000)
    {
        printf("tidak boleh lebih dari 100000\n");
        scanf("%d",&pinjaman);
    }

    if (pinjaman < 25000)
    {
        hitung = 23;
    }else if (pinjaman < 50000)
    {
        hitung = 1250 ;
    }else if (pinjaman <= 100000)
    {
        hitung = 5000;
    }
    printf("%d",hitung);
    
    
}