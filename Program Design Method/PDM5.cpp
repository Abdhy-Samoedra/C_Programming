#include <stdio.h>

float validasiLemak(float &a)
{
    while (a<0)
    {
        printf("tidak boleh negatif\n");
        scanf("%f",&a);
    }
    
}
float validasiKalori(float &b)
{
    while (b<0)
    {
        printf("tidak boleh negatif\n");
        scanf("%f",&b);
    }
    
}
int main()
{
    float lemak,kalori,hitung=0;
    scanf("%f",&lemak);
    validasiLemak(lemak);
    scanf("%f",&kalori);
    validasiKalori(kalori);
    hitung = (lemak*9)/kalori;
    printf("%.2f\n",hitung);
    if (hitung<0.3)
    {
        printf("food is now low fat");
    }else
    {
        printf("food is not low fat");
    }
    

}
