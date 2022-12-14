#include <stdio.h>
#include <string.h>

int main()
{
    int kasus;
    int jam;
    int menit;
    char waktu[100];

    scanf("%d", &kasus);
    for (int i = 0; i < kasus; i++)
    {
        scanf("%d:%d %s", &jam, &menit, waktu);
        printf("Case #%d: ", i + 1);
        if (strcmp(waktu, "am") == 0)
        {
            if (jam == 12)
            {
                jam = 0;
                printf("%.02d:%.02d\n", jam, menit);
            }
            else if (jam != 12)
            {
                printf("%.02d:%.02d\n", jam, menit);
            }
        }
        else if (strcmp(waktu, "pm") == 0)
        {
            if (jam == 12)
            {
                printf("%.02d:%.02d\n", jam, menit);
            }
            else if (jam != 12)
            {
                printf("%.02d:%.02d\n", jam+12, menit);
            }
        }
    }
}