#include <stdio.h>

int main()
{
    int kasus, jumlah, max1, max2, sum,angka[100001];

    scanf("%d", &kasus);

    for (int i = 0; i < kasus; i++)
    {
        max1 = -1000000;
        max2 = -1000000;
        sum = 0;
        scanf("%d", &jumlah);

        for (int j = 0; j < jumlah; j++)
        {
            scanf("%d", &angka[j]);
        }

        for (int k = 0; k < jumlah; k++)
        {
            
            if (max1 < angka[k])
            {
                max2 = max1;
                max1 = angka[k];
            
            } 
            else if (max2 < angka[k])
            {
                max2=angka[k];
            }
    
        }
        sum = max1 + max2;
        printf("Case #%d: %d\n", i+1, sum);

    
        
    }
}