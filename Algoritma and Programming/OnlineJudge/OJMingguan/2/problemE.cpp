#include <stdio.h>

int main()
{

    int peserta,jumlah,a,rata,nilai1,nilai2,nilai3;

    scanf("%d",&peserta);

    scanf("%d %d %d",&nilai1,&nilai2,&nilai3);
    jumlah = nilai1+nilai2+nilai3;

    for (int i = 0; i < peserta; i++)
    {
        scanf("%d", &a);
        jumlah += a;
    }
    rata = jumlah/(peserta+3);

    if (nilai1 >= rata)
    {
        printf("Jojo lolos\n");
    }else 
    {
        printf("Jojo tidak lolos\n");
    }

    if (nilai2 >= rata)
    {
        printf("Lili lolos\n");
    }else 
    {
        printf("Lili tidak lolos\n");
    }
    
    if (nilai3 >= rata)
    {
        printf("Bibi lolos\n");
    }else 
    {
        printf("Bibi tidak lolos\n");
    }
    
    return 0;
    


  
  


    

}