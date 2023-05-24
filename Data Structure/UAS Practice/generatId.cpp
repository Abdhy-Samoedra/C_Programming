#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
    // Take any two strings
    char s1[] = "GeeksforGeeks";
    char s2[] = "eeks";
    char *p;

    // Find first occurrence of s2 in s1
    p = strstr(s1, s2);

    // Prints the result
    if (p == NULL)
    {
        printf("String not found\n");
    }
    else
        printf("String found\n");

    return 0;

    // char email[100];
    // char *cek;
    // scanf("%[^\n]",email);
    // cek = strrchr(email,'@');
    // printf("%s",cek);
    // if (strcmp(cek,"@gmail.com") == 0)
    // {
    //     printf("benar");
    // }else
    // {
    //     printf("salah");
    // }
    // double number1 = 4;
    // double number2 = 2;
    // printf("%lf ",pow(number1,number2));
    // printf("%lf ",sqrt(number1));
    // printf("%lf ",sin(number1));
    // printf("%lf ",cos(number1));
    // printf("%lf ",tan(number1));
    // YYXXX
    // Y huruf, X angka
    // srand(time(NULL));
    // int a = (rand() % (90 - 65 + 1)) + 65; // karena ascii huruf 65-90
    // int b = (rand() % (90 - 65 + 1)) + 65;
    // int c = (rand() % (999 - 100 + 1)) + 100;
    // char id[100] = {};
    // sprintf(id,"%c%c%d",a,b,c);
    // printf("%s",id);
}