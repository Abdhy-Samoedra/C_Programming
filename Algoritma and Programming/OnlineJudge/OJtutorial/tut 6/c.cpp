#include <stdio.h>

int main()
{
    int kasus;
    int count = 0;
    int max = 0;
    int jumlah;
    int nilai[1000];
    scanf("%d",&kasus);

    for (int i = 0; i < kasus; i++)
    {
        scanf("%d",&jumlah);
        for (int j = 0; j < jumlah; j++)
        {
            scanf("%d",&nilai[j]);
            if (nilai[j]>=max)
            {
                max = nilai[j];
            }
        }
        for (int j = 0; j < jumlah; j++)
        {
            if (nilai[j] == max)
            {
                count++;
            }
            
        }
        printf("Case #%d: %d\n",i+1,count);
        count = 0;
        max = 0;    
        
    }
    
}