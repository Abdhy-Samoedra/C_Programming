#include <stdio.h>

int main()
{
    // operator + - * / % 


    // PERRCABANGAN IF ELSE

    // puts("Masukkan 2 angka!");
    // int a;
    // int b;
    // scanf("%d %d", &a, &b);
    // int hasil = a%b;
    // if (hasil != 0)
    // {
    //     /* code */
    //     printf("hasil adalah %d",hasil);
    // }else
    // {
    //     printf("hasil kurang dari  0");
    // }
    
    // puts("Masukkan angka yang akan dicek!");
    // int cek;
    // scanf("%d",&cek);
    // int hasilCek = cek%2;
    // if (hasilCek == 0)
    // {
    //     /* code */
    //     puts("ini adalah bilangan genap");
    // }else
    // {
    //     /* code */
    //     puts("ini adalah bilangan ganjil");
    // }
    
    

    // PERCABANGAN SWITCH CASE

    int angka;
    scanf("%d", angka);
    switch (angka%2)
    {
        case 0:
            puts("ini bilangan genap");
    
            break;
        case 1:
            puts("ini bilangan ganjil");
    
            break;
        
        default:
            break;
    }


}