#include <stdio.h>

int main()
{
    int teman,hari,mulai,selesai,jumlah;

    scanf("%d",&hari);
    int view[hari]; //batasan hari


    for (int i = 0; i < hari; i++)
    {
        scanf("%d ",&view[i]); //jumlah view per hari
    }

    scanf("%d",&teman); //jumlah teman

    for (int j = 1; j <= teman; j++)
    {
        jumlah = 0; //menampung jumlah
        scanf("%d %d",&mulai,&selesai); // hari mulai dan selesai

            for (int k = mulai-1; k <= selesai-1; k++)
            {
                jumlah += view[k]; //menghitung jumlah
            }
            
        printf("Case #%d: %d\n",j,jumlah);
        

    }


    
}