#include <stdio.h>
#include <string.h>

int main()
{
    int kasus;
    char kata[1001];
    scanf("%d", &kasus);
    for (int i = 0; i < kasus; i++)
    {
        scanf("%s",kata);
        printf("Case %d: ", i+1);
        for (int i = 0; kata[i] != '\0'; i++)
        {

            printf("%d", kata[i]);
            if (i<strlen(kata)-1)
            {
                printf("-");
            }
            
        }
        printf("\n");
    }
}