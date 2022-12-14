#include <stdio.h>
#include <string.h>

int main()
{
	int kasus;
	char kata[100];
	scanf("%d",&kasus);
	for(int i = 0; i < kasus; i++)
	{
		scanf("%s",kata);
		for(int j= strlen(kata)-1; j>=0;j--)
		{
			printf("%c",kata[j]);
		}
	}
}
