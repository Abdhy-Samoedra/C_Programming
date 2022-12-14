#include <stdio.h>
#include <string.h>

struct siswa
{
    char teman[101];
    char pohon[101];
};

int main()
{
    FILE *tree;
    tree = fopen("testdata.in", "r");

    struct siswa infoSiswa[101];

    int jumlah;
    char teman2[101][101];

    fscanf(tree, "%d", &jumlah);
    fgetc(tree);

    int count = 0;

    for (int i = 0; i < jumlah; i++)
    {
        fscanf(tree, "%[^#]#%[^\n]\n", infoSiswa[i].teman, infoSiswa[i].pohon);
    }

    int kasus;
    fscanf(tree, "%d", &kasus);
    fgetc(tree);

    for (int i = 0; i < kasus; i++)
    {
        fscanf(tree, "%s\n", teman2[i]);
        for (int j = 0; j < jumlah; j++)
        {
            if (strcmp(teman2[i], infoSiswa[j].teman) == 0)
            {
                printf("Case #%d: %s\n", i + 1, infoSiswa[j].pohon);
                count = 1;
                break;
            }
        }
        if (count == 0)
        {
            printf("Case #%d: N/A\n", i + 1);
        }

        count = 0;
    }
}