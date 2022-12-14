#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char kalimat[10001];
    scanf("%[^\n]s", kalimat);

    for (int i = 0; i < strlen(kalimat); i++)
    {
        kalimat[i] = toupper(kalimat[i]);
        if (kalimat[i] == 'I')
        {
            kalimat[i] = '1';
        }
        if (kalimat[i] == 'R')
        {
            kalimat[i] = '2';
        }
        if (kalimat[i] == 'E')
        {
            kalimat[i] = '3';
        }
        if (kalimat[i] == 'A')
        {
            kalimat[i] = '4';
        }
        if (kalimat[i] == 'S')
        {
            kalimat[i] = '5';
        }
        if (kalimat[i] == 'G')
        {
            kalimat[i] = '6';
        }
        if (kalimat[i] == 'T')
        {
            kalimat[i] = '7';
        }
        if (kalimat[i] == 'B')
        {
            kalimat[i] = '8';
        }
        if (kalimat[i] == 'P')
        {
            kalimat[i] = '9';
        }
        if (kalimat[i] == 'O')
        {
            kalimat[i] = '0';
        }
        
    }
    printf("%s\n", kalimat);
}