#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	int kasus;
	char kata[100];
	
	scanf("%d",&kasus);
	for(int i =0;i<kasus;i++)
	{
		scanf("%s",kata);
		for(int j =strlen(kata)-1 ;j>=0 ;j--)
		{
			if(isupper(kata[j]) == 1)
			{
				kata[j] = tolower(kata[j]);
			}else
			{
				kata[j] = toupper(kata[j]);
			}
			
			printf("%c",kata[j]);
		}
		printf("\n");
	}
	
}
