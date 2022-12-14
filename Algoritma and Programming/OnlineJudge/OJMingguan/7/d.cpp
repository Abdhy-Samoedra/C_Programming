#include <stdio.h>
#include <string.h>

int main()
{
    FILE *badPrank;
    badPrank = fopen("testdata.in", "r");
    int kasus;
    int shifting;
    char kata[1001];

    fscanf(badPrank, "%d", &kasus);

    for (int i = 0; i < kasus; i++)
    {
        fscanf(badPrank, "%d\n", &shifting);
        fscanf(badPrank, "%[^\n]\n", kata);
        for (int j = 0; j < strlen(kata); j++)
        {
            if (kata[j] == '0')
            {
                kata[j] = 'O';
            }
            else if (kata[j] == '1')
            {
                kata[j] = 'I';
            }
            else if (kata[j] == '3')
            {
                kata[j] = 'E';
            }
            else if (kata[j] == '4')
            {
                kata[j] = 'A';
            }
            else if (kata[j] == '5')
            {
                kata[j] = 'S';
            }
            else if (kata[j] == '6')
            {
                kata[j] = 'G';
            }
            else if (kata[j] == '7')
            {
                kata[j] = 'T';
            }
            else if (kata[j] == '8')
            {
                kata[j] = 'B';
            }
        }
        for (int j = 0; j < strlen(kata); j++)
        {
            if (kata[j] != 32)
            {
                kata[j] = kata[j] - shifting;

                if (kata[j] < 65)
                {
                    kata[j] = kata[j] + 26;
                }
            }
        }

        printf("Case #%d: %s\n", i + 1, kata);
    }
    fclose(badPrank);
}