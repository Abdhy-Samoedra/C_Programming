#include <stdio.h>

void fibostring(char satu, char dua, int ke)
{
    if (ke == 0)
    {
       printf("%c",satu);
       return;
    }else if (ke == 1)
    {
        printf("%c",dua);
        return;
    }else
    {
        fibostring(satu, dua, ke-1);
        fibostring(satu, dua, ke-2);

    }
    
    
}

int main()
{
    int kasus;
    int ke;
    char satu;
    char dua;
    scanf("%d", &kasus);
    for (int i = 0; i < kasus; i++)
    {
        scanf("%d %c %c", &ke, &satu, &dua);
        printf("Case #%d: ", i + 1);
        fibostring(satu, dua, ke);
        printf("\n");
    }
}

/*int main()
{
    int kasus;
    int index = 0;
    char kata[20][20000];
    scanf("%d",&kasus);
    for (int i = 0; i < kasus; i++)
    {
        scanf("%d %c %c",&index,&kata[0],kata[1]);
        for (int j = 2; j <= index; j++)
        {
            sprintf(kata[j],"%s%s",kata[j-1],kata[j-2]);
        }

        printf("Case #%d: %s\n",i+1,kata[index]);

    }

}*/
