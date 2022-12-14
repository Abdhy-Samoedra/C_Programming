#include <stdio.h>

int main()
{
    int kasus,banyak,bibi,lili;
    scanf("%d",&kasus);
    int data[100001];

    for (int i = 0; i < kasus; i++)
    {
        scanf("%d",&banyak);
        for (int j = 1; j <= banyak; j++)
        {
            scanf("%d",&data[j]);
        }
        scanf("%d %d",&bibi,&lili);

        printf("Case #%d : ",i+1);

        if (data[bibi] > data[lili])
        {
            printf("Bibi\n");
        }else if (data[bibi] < data[lili])
        {
            printf("Lili\n");
        }else{
            printf("Draw\n");
        }
        
        
        
    }
    
}