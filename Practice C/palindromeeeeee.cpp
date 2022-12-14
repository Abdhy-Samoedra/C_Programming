#include <stdio.h>
#include <string.h>

int main()
{
	char kata1[100];

	int count = 0;

	scanf("%s", kata1);
	strlwr(kata1);

	for (int i = 0; i < strlen(kata1) / 2; i++)
	{

		if (kata1[i] == kata1[strlen(kata1) - i - 1])
		{
			count++;
		}
	}
	if (count == strlen(kata1) / 2)
	{
		printf("palindrome");
	}
	else
	{
		printf("not palindrome");
	}
}
