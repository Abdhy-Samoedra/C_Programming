#include <stdio.h>

int main()
{
    int kasus;
    scanf("%d",&kasus);

    int sisi[kasus];
    
    for (int i = 0; i < kasus; i++)
    {
        scanf("%d",&sisi[i]);
    }

    for (int j = 0; j < kasus; j++)
    {
        printf("Case #%d:\n",j+1);
        int spacing = sisi[j];
        
        for (int k = 1; k <= sisi[j]; k++)
        {
            for (int l = 1; l <= sisi[j]; l++)
            {
                if (l<spacing)
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
            spacing--;
            printf("\n");
            
        }
        
    }

    return 0;
    
    

    
}