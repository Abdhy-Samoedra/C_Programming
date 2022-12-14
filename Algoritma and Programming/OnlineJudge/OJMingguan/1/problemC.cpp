#include <stdio.h>

int main()
{
    char kata1 [21];
    char kata2 [21];
    char kata3 [21];

    scanf("%[a-z] %[a-z] %[a-z]",kata1,kata2,kata3); //[a-z]=tidak bisa jika angka
    printf("%s %s %s\n",kata3,kata2,kata1);
    
    return 0;
}