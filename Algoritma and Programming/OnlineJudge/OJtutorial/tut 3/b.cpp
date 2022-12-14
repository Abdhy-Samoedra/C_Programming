#include <stdio.h>

int main()
{
    int kasus,tes,count=0;
    long long int nilai[10000], minim[10000];

    scanf("%d",&kasus);

    for (int i = 0; i < kasus; i++)
    {
        count=0;

        scanf("%d",&tes);
        for (int j = 0; j < tes; j++)
        {
            scanf("%lld",&nilai[j]);
        }
        for (int k = 0; k < tes; k++)
        {
            scanf("%lld",&minim[k]);
        }
        for (int l = 0; l < tes; l++)
        {
            if (nilai[l] < minim[l])
            {
                count++;
            }
            
        }
        printf("Case #%d: %d\n",i+1,count);
        
        
        
        
    }
    
}