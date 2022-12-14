#include <stdio.h>

int jojonanci(int ke, int x, int y)
{
    if (ke == 0)
    {
        return x;
    }else if (ke == 1)
    {
        return y;
    }else
    {
        return (jojonanci((ke-1),x,y)) - (jojonanci((ke-2),x,y));
    }
    
    
    

}

int main()
{

//     int kasus,n,x,y;
//     int temp = 0;
//     scanf("%d", &kasus);
//     for (int i = 0; i < kasus; i++)
//     {
//         scanf("%d %d %d", &n, &x, &y);
//         for (int j = 0; j < n; j++)
//         {
//             temp = y - x;
//             x = y;
//             y = temp;
//         }
//         printf("Case #%d: %d\n", i + 1, x);
//     }

    int kasus,x,y,ke;
    scanf("%d",&kasus);
    for (int i = 0; i < kasus; i++)
    {
        scanf("%d %d %d",&ke,&x,&y);
        printf("Case #%d: %d\n",i+1,jojonanci(ke,x,y));
    }
    
}