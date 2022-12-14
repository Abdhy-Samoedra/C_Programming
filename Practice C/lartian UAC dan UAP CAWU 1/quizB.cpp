#include <stdio.h>

struct data
{
	char id[21];
	char name[101];
	int age;
};


int main()
{
	int jumlah;
	scanf("%d",&jumlah);
	
	data song[100];
	
	for(int i = 0; i< jumlah; i++)
	{
		scanf("%s",song[i].id);getchar();
		scanf("%[^\n]",song[i].name);getchar();
		scanf("%d",&song[i].age);
	}
	
	int query;
	scanf("%d",&query);
	int hasil;
	for (int i =0;i<query;i++)
	{
		scanf("%d",&hasil);
		printf("Query #%d: \n",i+1);
		printf("ID: %s\n",song[hasil-1].id);
		printf("Name: %s\n",song[hasil-1].name);
		printf("Age: %d\n",song[hasil-1].age);
	}
	
}
