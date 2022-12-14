#include <stdio.h>
#include <string.h>
int main()
{
	char kata[100];
	scanf("%s", kata);
	strlwr(kata);
	printf("%s", kata);
}
