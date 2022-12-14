#include <stdio.h>
#include <string.h>

int main()
{
    int kasus,temp;
    char kata [1001];
    scanf("%d",&kasus);
    for (int i = 0; i < kasus; i++)
    {
        scanf("%s",kata);
        for (int j = 0; j <strlen(kata)/2; j++)
        {
            temp = kata[j];
            kata[j]=kata[strlen(kata)-j-1];
            kata[strlen(kata)-j-1] = temp;
        }
        printf("Case #%d : %s\n",i+1,kata);
        
    }
    
}