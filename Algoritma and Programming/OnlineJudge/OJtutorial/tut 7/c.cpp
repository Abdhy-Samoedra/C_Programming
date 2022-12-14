#include <stdio.h>
int main()
{
    int kasus;
    scanf("%d", &kasus);
    int counter = 0;
    long long int nomor;
    long long int puas[kasus];
    for (int i = 0; i < kasus; i++)
    {
        int cek = 1;
        scanf("%lld", &nomor);
        for (int j = 0; j < counter; j++)
        {
            if (nomor == puas[j])
            {
                cek = 0;
            }
        }
        if (cek == 1)
        {
            puas[counter] = nomor;
            counter++;
        }
    }
    printf("%d\n", counter);
}