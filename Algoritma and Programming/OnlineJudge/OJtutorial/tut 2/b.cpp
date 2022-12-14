#include <stdio.h>

int main()
{

    int kasus,jumlah;
    long long int nilai,hitung=0;
    scanf("%d",&kasus);
    for (int i = 0; i < kasus; i++)
    {
        scanf("%d",&jumlah);
        for (int k = 0; k < jumlah; k++)
        {
            scanf("%lld",&nilai);

            hitung+=nilai;
        }
        printf("Case #%d: %lld\n",i+1,hitung);
        hitung=0;


        
    }
    




    
    return 0;
}