#include <stdio.h>

int main()
{
    int hours,minute,second;
    printf("masukkan detik = ");
    scanf("%d",&second);


    printf("%d %d %d ",second/3600,(second%3600)/60,second%60);

}