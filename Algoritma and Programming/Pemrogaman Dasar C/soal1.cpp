#include <stdio.h>
#include <string.h>

int main()
{
    char input[100];
    scanf("%[^\n]" , input);

    printf("%s,", strrev (input));

    return 0 ;
}