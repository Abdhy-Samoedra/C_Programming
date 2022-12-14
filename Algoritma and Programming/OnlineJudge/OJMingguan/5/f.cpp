#include <stdio.h>


int main()
{
    int kasus, banyak;
    int butuh[100001];
    int punya[100001];

    scanf("%d",&kasus);
    
    for (int i = 0; i < kasus; i++)
    {
        scanf("%d",&banyak);
        for (int j = 0; j < banyak; j++)
        {
            scanf("%d",&butuh[j]);
        }
        for (int k = 0; k < banyak; k++)
        {
            scanf("%d",&punya[k]);
        }
        printf("Case #%d: ",i+1);
        for (int l = 0; l < banyak; l++)
        {
            printf("%d",butuh[l]-punya[l]);

            if (l<banyak-1)
            {
                printf(" ");
            }
            
        }
        printf("\n");
        
        
        
    }
    
}