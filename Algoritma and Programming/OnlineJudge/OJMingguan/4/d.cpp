#include <stdio.h>
#include <ctype.h>

int main()
{
    int panjang, soal,soal2;
    char arr[202];

    scanf("%d %d", &panjang, &soal);
    
    scanf("%s", arr);

    for (int j = 0; j < soal; j++)
        {
            scanf("%d",&soal2);
            if (isupper(arr[soal2]))
            {
                arr[soal2]=tolower(arr[soal2]);
            }
            else 
            {
                arr[soal2]=toupper(arr[soal2]);
            }
            
        }
    printf("%s\n",arr);
    
}