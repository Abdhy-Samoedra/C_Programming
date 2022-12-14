#include <stdio.h>

// ---------------Fungsi rekursif pada C
// Rekursif adalah fungsi yang memanggil dirinya sendiri di dalam tubuhnya,
// kan kita biasanya memanggil fungsi di main.

int sum (int num)
{
    if (num != 0)
    {
        return num + sum(num-1);   // disini tertulis sum, menandakan memanggil dirinya sendiri dengan parameter berbeda
    }else
    {
        return num;
    }
    
    
}

int main()
{
    int number, result;

    printf("Masukkan sebuah bilangan bulat = ");
    scanf("%d", &number);

    result = sum(number);

    printf("sum = %d", result);
}