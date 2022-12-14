#include <stdio.h>
#include <string.h>

int main()
{
    char kata[1001] = {};
    int count = 0;
    int index[400] = {};
    char palindrome[1001][1001] = {};
    int index2 = 0;
    int hasil;
    int sama;
    char temp[1001] = {};

    scanf("%s", kata);

    for (int i = 0; i < strlen(kata); i++)
    {
        index[kata[i]] = 1;
    }


    for (int i = 0; i < 128; i++)
    {
        if (index[i] == 1)
        {
            count++;
        }
    }

    for (int i = 1; i < strlen(kata); i++)
    {
        for (int j = 0; j < strlen(kata) - i; j++)
        {
            hasil = 1;
            sama = 0;
            
            for (int k = j; k < j + i + 1; k++)
            {
                temp[k - j] = kata[k];
            }


            for (int l = 0; l < strlen(temp) / 2; l++)
            {
                if (temp[l] != temp[strlen(temp) - l - 1])
                {
                    hasil = 0;
                }
            }


            if (hasil)
            {
                for (int i = 0; i < index2; i++)
                {
                    if (strcmp(palindrome[i], temp) == 0)
                    {
                        sama = 1;
                        break;
                    }
                }
                if (!sama)
                {
                    strcpy(palindrome[index2], temp);
                    count++;
                }
                index2++;
                sama = 0;
            }

            
        }
    }

    printf("%d", count);
}