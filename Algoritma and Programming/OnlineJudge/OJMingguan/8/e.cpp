#include <stdio.h>

int count = 0;
int pacmon(char game[200][200], int j, int k)
{
    if (game[j][k] == '#' || (game[j][k] != '*' && game[j][k] != '.' && game[j][k] != 'P'))
    {
        return 0;
    }
    if (game[j][k] == '*')
    {
        count++;
    }
    game[j][k] = '#';
    return pacmon(game, j - 1, k) + pacmon(game, j + 1, k) + pacmon(game, j, k - 1) + pacmon(game, j, k + 1);
}

int main()
{

    int kasus;
    scanf("%d", &kasus);
    int baris, kolom;
    for (int i = 0; i < kasus; i++)
    {
        char game[200][200] = {0};
        scanf("%d %d", &baris, &kolom);
        getchar();
        for (int j = 0; j < baris; j++)
        {
            for (int k = 0; k < kolom; k++)
            {
                scanf("%c", &game[j][k]);
            }
            getchar();
        }

        for (int j = 0; j < baris; j++)
        {
            for (int k = 0; k < kolom; k++)
            {
                if (game[j][k] == 'P')
                {
                    pacmon(game, j, k);
                }
            }
        }
        printf("Case #%d: %d\n", i + 1, count);
        count = 0;
    }
}