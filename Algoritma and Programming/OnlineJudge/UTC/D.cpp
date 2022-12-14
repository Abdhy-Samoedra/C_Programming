#include <stdio.h>

int main()
{
    int kasus;
    int panjang;
    int angka[100];
    int counter =0;

    scanf("%d",&kasus);

    for (int i = 0; i < kasus; i++)
    {
        scanf("%d",&panjang);
        for (int j = 0; j < panjang; j++)
        {
            scanf("%d",&angka[j]);
        }

        for (int k = 0; k < panjang;)
        {
            if (angka[k] == angka[k+1])
            {
                counter++;
                k+=2;
            } else
            {
                k+=1;
            }
            
        }
        printf("Case #%d: %d\n",i+1,counter);
        counter =0;
        
    }
    
}