#include <stdio.h>
struct data
{
    char code[10];
    char name[101];
    int credits;
};

int main()
{
    int jumlah;
    scanf("%d", &jumlah);
    getchar();

    struct data infodata[1001];

    for (int i = 0; i < jumlah; i++)
    {
        scanf("%s", infodata[i].code);
        getchar();
        scanf("%[^\n]", infodata[i].name);
        getchar();
        scanf("%d", &infodata[i].credits);
        getchar();
    }

    int kasus;
    scanf("%d", &kasus);getchar();
    int keluar;
    for (int i = 0; i < kasus; i++)
    {
        scanf("%d", &keluar);getchar();
        printf("Query #%d:\n", i + 1);
        printf("Code: %s\n", infodata[keluar - 1].code);
        printf("Name: %s\n", infodata[keluar - 1].name);
        printf("Credits: %d\n", infodata[keluar - 1].credits);
    }
}