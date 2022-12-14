#include <stdio.h>

int main()
{
    int kasus;
    scanf("%d",&kasus);
    int gojo,bipay;

    for (int i = 0; i < kasus; i++)
    {
        scanf("%d %d",&gojo,&bipay);

        if (gojo > bipay)
        {
            printf("Case #%d: Go-Jo\n",i+1);
        }else
        {
            printf("Case #%d: Bi-Pay\n",i+1);
        } 
    }


    return 0;
}