#include <stdio.h>
#include <string.h>

int main()
{
    int kasus;
    char kata[501];

    scanf("%d", &kasus);

    for (int i = 0; i < kasus; i++)
    {
        int count = 0;
        scanf("%s", kata);
        printf("Case #%d: ", i + 1);
        for (int j = 0; j < strlen(kata) / 2; j++)
        {
            if (kata[j] == kata[strlen(kata) - j - 1])
            {
                count++;
            }
        }
        if (count == strlen(kata) / 2)
        {
            printf("Yay, it's a palindrome\n");
        }
        else
        {
            printf("Nah, it's not a palindrome\n");
        }
    }
}
