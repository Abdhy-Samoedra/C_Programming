#include <stdio.h>

int main()
{
    char input[101];
    scanf("%[^\n]",input);
    printf("Happy Birthday to %s\n",input);

    return 0;
}