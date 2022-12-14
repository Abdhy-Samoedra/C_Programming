#include <stdio.h>

int biner(long long int angka)
{
    if (angka > 1)
    {
        biner(angka / 2);
    }
    printf("%lld", angka % 2);
}

int main()
{
    int kasus;
    scanf("%d", &kasus);
    for (int i = 0; i < kasus; i++)
    {
        long long int angka;
        scanf("%lld", &angka);
        printf("Case #%d: ", i + 1);
        biner(angka);
        printf("\n");
    }
}