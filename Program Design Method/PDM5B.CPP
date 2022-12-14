#include <stdio.h>

float validasi(float &a,float &b)
{
    while (a < 0  || b < 0 )
    {
        printf("tidak boleh negatif\n");
        scanf("%f %f", &a, &b);
    }
}
// float validasiKalori(float b)
// {
//     while (b < 0)
//     {
//         printf("tidak boleh negatif\n");
//         scanf("%f", &b);
//     }
// }
int main()
{
    float lemak, kalori, hitung = 0;
    scanf("%f %f", &lemak, &kalori);
    validasi(lemak,kalori);
    // scanf("%f", &kalori);
    // validasiKalori(kalori);
    hitung = (lemak * 9) / kalori;
    printf("%.2f\n", hitung);
    if (hitung < 0.3)
    {
        printf("food is now low fat");
    }
    else
    {
        printf("food is not low fat");
    }
}
