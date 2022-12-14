#include <stdio.h>
int hasil=0;

int fibonacci(int fib)
{
    hasil++;
    int angka = 0;
    if (fib == 0)
    {
        angka = 0;
    }
    
    else if (fib == 1)
    {
       angka = 1;
    }else 
    {
        
        angka = fibonacci(fib-1) + fibonacci(fib-2);
        
    }
    return angka;
    
}

int main()
{
    int kasus;
    int fib;
    scanf("%d", &kasus);
    for (int i = 0; i < kasus; i++)
    {
        scanf("%d", &fib);
        fibonacci(fib);
        printf("Case #%d: %d\n",i+1,hasil);
        hasil = 0;
    }
}