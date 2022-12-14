#include <stdio.h>

int main()
{
    int kasus;    // deklarasi untuk variabel jumlah kasus
    scanf("%d",&kasus); //input jumlah kasus

    int sisi[kasus]; //deklarasi variabel sisi segitiga agar batasannya adalah kasus

    for (int i = 0; i < kasus; i++) 
    {
        scanf("%d",&sisi[i]);   // masukkan sisi tiap kasus, dengan kasus disimpan dalam array
    }

    for (int j = 0; j < kasus; j++)
    {
        printf("Case #%d:\n",j+1); //print case#0+1 karena dimulai j= 0
        int space = sisi[j];  // deklarasi variabel spasi dengan ukuran tidak lebih dari sisi[]

        for (int k = 1; k <= sisi[j]; k++) 
        {
            for (int l = 1; l <= sisi[j]; l++)
            {
                if (l<space)
                {
                    printf(" ");
                }else if ((k+l)%2 == 0)
                {
                    printf("*");
                }else
                {
                    printf("#");
                }
                
            }
            space--;
            printf("\n");
        }
            
    }

    return 0;
    
}