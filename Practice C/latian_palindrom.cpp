#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	int kasus;
	
	char kata[100];
	scanf("%d",&kasus);
	for(int i = 0;i<kasus;i++)
	{
		int count =0;
		scanf("%s",kata);
		
		for(int j =0; j<strlen(kata)/2;j++)
		{
			if(kata[j] == kata[strlen(kata) -j -1])
			{
				count++;
			}
		}
		
		if(count == strlen(kata)/2)
		{
			printf("its palindrome\n");
		}else
		{
			printf("its not palindrome\n");
		}
		
	}
}
