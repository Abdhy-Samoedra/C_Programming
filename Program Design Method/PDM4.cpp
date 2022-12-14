#include <stdio.h>


int calculate(int a,int b,int c,int d,int e,int f)
{
    int sum = a+b+c+d+e+f;
    printf(" test Biaya bulanan adalah : %d\n",sum);
    printf("Biaya tahunan adalah : %d\n",sum*12);
}


int main()
{
    int loan,insurance,gas,oil,tires,maintenance;

    printf("loan costs: ");
    scanf("%d",&loan);

    printf("insurance costs: ");
    scanf("%d",&insurance);
    
    printf("gas costs: ");
    scanf("%d",&gas);
    
    printf("oil costs: ");
    scanf("%d",&oil);

    printf("tires costs: ");
    scanf("%d",&tires);

    printf("maintenance costs: ");
    scanf("%d",&maintenance);

    calculate(loan,insurance,gas,oil,tires,maintenance);




    return 0;
}