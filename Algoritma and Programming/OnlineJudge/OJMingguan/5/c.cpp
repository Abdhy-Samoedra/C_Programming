#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char kalimat[10001];
    scanf("%[^\n]s", kalimat);

    for (int i = 0; i < strlen(kalimat); i++)
    {
        kalimat[i] = tolower(kalimat[i]);
        if (kalimat[i] == '1')
        {
            kalimat[i] = 'i';
        }
        if (kalimat[i] == '2')
        {
            kalimat[i] = 'r';
        }
        if (kalimat[i] == '3')
        {
            kalimat[i] = 'e';
        }
        if (kalimat[i] == '4')
        {
            kalimat[i] = 'a';
        }
        if (kalimat[i] == '5')
        {
            kalimat[i] = 's';
        }
        if (kalimat[i] == '6')
        {
            kalimat[i] = 'g';
        }
        if (kalimat[i] == '7')
        {
            kalimat[i] = 't';
        }
        if (kalimat[i] == '8')
        {
            kalimat[i] = 'b';
        }
        if (kalimat[i] == '9')
        {
            kalimat[i] = 'p';
        }
        if (kalimat[i] == '0')
        {
            kalimat[i] = 'o';
        }
        
    }
    printf("%s\n", kalimat);
}