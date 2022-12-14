#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int kasus;
    char kata[1001];

    scanf("%d", &kasus);

    for (int i = 0; i < kasus; i++)
    {
        scanf("%s", kata);
        printf("Case #%d: ",i+1);
        for (int j = strlen(kata)-1; j >= 0; j--)
        {
            if (isupper(kata[j]))
            {
                kata[j] = tolower(kata[j]);
            }
            else
            {
                kata[j] = toupper(kata[j]);
            }
            printf("%c", kata[j]);
        }
        printf("\n");
        
    }
}

