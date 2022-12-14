#include <stdio.h>
#include <string.h>

char angka[10000000] = {};

int main()
{
    int hasil = 0;
    int convert;
    int kasus;
    scanf("%d",&kasus);
    for (int i = 0; i < kasus; i++)
    {
        scanf("%s",angka);getchar();
        for (int j = strlen(angka)-1; j >= 0; j--)
        {
            convert = angka[j] - 48;
            if (j%2 == 0)
            {
                hasil += convert;
            }else
            {
                hasil -= convert;
            }
        }

        if (hasil % 11 == 0)
        {
            printf("Case #%d: Yeah\n",i+1);
            hasil = 0;
        }else
        {
            printf("Case #%d: Nah\n",i+1);
            hasil = 0;
        }
        
        
    }
    
}