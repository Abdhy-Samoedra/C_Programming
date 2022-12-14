#include <stdio.h>
#include <string.h>

int main()
{
    int kasus,length,temp;
    char kata[1001];

    scanf("%d", &kasus);
    for (int i = 0; i < kasus; i++)
    {
        scanf("%s",kata);
        printf("Case %d: ",i+1);
        for (int j = 0; j <strlen(kata)/2; j++)
        {
            temp = kata[j];
            kata[j]=kata[strlen(kata)-j-1];
            kata[strlen(kata)-j-1] = temp;
        }
        for (int k = 0; kata[k] != '\0'; k++)
        {
            printf("%d", kata[k]%2);
        }
        printf("\n");
        
  
    }

}