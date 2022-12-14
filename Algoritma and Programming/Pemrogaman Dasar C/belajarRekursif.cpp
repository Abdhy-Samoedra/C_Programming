#include <stdio.h>

int pangkatRekursif(int x, int y)
{
    if (y <= 1)
    {
        return x;
    }
    else
    {
        return x * pangkatRekursif(x, y - 1);
    }
}

int faktorial(int f)
{
    if (f <= 1)
    {
        printf("%d\n", f);
        return f;
    }
    else
    {
        printf("%d*", f);
        return f * faktorial(f - 1);
    }
}

int fibonacci(int fib)
{
    if (fib == 0 || fib == 1)
    {
        return fib;
    }else
    {
        return fibonacci(fib-1) + fibonacci(fib-2);
    }
    
    
}

int main()
{
    int x, y;
    printf("Angka : ");
    scanf("%d", &x);
    printf("Pangkat : ");
    scanf("%d", &y);
    printf("Hasil %d pangkat %d : %d\n", x, y, pangkatRekursif(x, y));

    int f;
    printf("Menghitung faktorial dari : ");
    scanf("%d", &f);
    printf("Hasil faktorial dari %d : %d\n", f, faktorial(f));

    int fib;
    printf("menghitung fibonacci ke : ");
    scanf("%d",&fib);
    printf("hasil fibonaci ke %d : %d",fib,fibonacci(fib));
}