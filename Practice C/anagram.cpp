#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
	int kasus;
	char kata1[1000];
	char kata2[1000];
	int counter;
	
	int place1;
	int place2;
	
	
	
	scanf("%d",&kasus);
	for(int i = 0; i<kasus;i++)
	{
		int counter1[1000] = {};
    	int counter2[1000] = {};
    	
		scanf("%s",kata1);
		scanf("%s",kata2);
		strlwr(kata1);
		strlwr(kata2);
		if(strlen(kata1) != strlen(kata2))
		{
			printf("not anagram\n");
		}else if(strlen(kata1) == strlen(kata2))
		{
		
		for(int i = 0; i<strlen(kata1);i++)
		{
			place1 = kata1[i] - 97;
			place2 = kata2[i] - 97;
			counter1[place1]++;
			counter2[place2]++;
		}
		
		for(int j=0;j<26;j++)
		{
			if(counter1[j] != counter2[j])
			{
				counter++;
			}
		}
		
		if(counter == 0)
		{
			printf("anagram\n");
		}else
		{
			printf("not anagram\n");
		}

	}
	counter=0; 
	}
	
}
