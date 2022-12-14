#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data
{
	char Name[255];
	char Type[255];
	int Price;
	int Stock;
}electronic[255];

int electronicCount = 0;
double capacity = 150;
int capacityCount = 0;

int partition(data electronic[], int low, int high)
{
	data pivot = electronic[high];
	int i = low - 1;
	int j = low;
	
	while(j < high)
	{
		if(strcmpi(electronic[j].Name,pivot.Name) < 0)
		{
			i++;
			data temp;
			temp = electronic[j];
			electronic[j] = electronic[i];
			electronic[i] = temp;
		}
		j++;
	}
	electronic[high] = electronic[i+1];
	electronic[i+1] = pivot;
	return(i+1);
}

void quickSort(data electronic[], int low, int high)
{
	if(low < high)
	{
		int pos = partition(electronic, low, high);
		quickSort(electronic,low,pos-1);
		quickSort(electronic,pos+1,high);
	}
}

void importData()
{
	FILE* data;
	data = fopen("electronic.txt","r");
	
	char electroName[255];
	char electroType[255];
	int electroPrice;
	int electroStock;
	
	while(!feof(data))
	{
		fscanf(data,"%[^#]#%[^#]#%d#%d\n",electroName,electroType,&electroPrice,&electroStock);
		
		if(strcmp(electroType,"Small") == 0)
		{
			capacityCount += electroStock * 1;
		}else if(strcmp(electroType,"Medium") == 0)
		{
			capacityCount += electroStock * 2;
		}else if(strcmp(electroType,"Big") == 0)
		{
			capacityCount += electroStock * 4;
		}
		
		strcpy(electronic[electronicCount].Name,electroName);
		strcpy(electronic[electronicCount].Type,electroType);
		electronic[electronicCount].Price = electroPrice;
		electronic[electronicCount].Stock = electroStock;
				
		electronicCount++;
	}
	quickSort(electronic,0,electronicCount-1);
}

void viewAll()
{
	double hasil=0;
	for(int i=0;i<electronicCount;i++)
	{
		if(strcmp(electronic[i].Type,"Small") == 0)
		{
			hasil += electronic[i].Stock*1;
		}else if(strcmp(electronic[i].Type,"Medium") == 0)
		{
			hasil += electronic[i].Stock*2;
		}else if(strcmp(electronic[i].Type,"Big") == 0)
		{
			hasil += electronic[i].Stock*4;
		}
	}
	double percentage = hasil/capacity*100;
	printf("==============================================================\n");
	printf("| Name                  | Type     | Price           | Stock |\n");
	printf("==============================================================\n");
	for(int i = 0; i < electronicCount; i++)
		{
			printf("| %-20s  | %-6s   | Rp. %-10d  | %-4d  |\n",electronic[i].Name,electronic[i].Type,electronic[i].Price,electronic[i].Stock);
		}
	printf("==============================================================\n");
	printf("| Used Capacity Percentage                           | %.1lf%% |\n",percentage);
	printf("==============================================================\n");
}

int searchName(data electronic[], int left, int right, char electroName[])
{	
	
	while(left <= right)
	{
		int mid = (left+right) / 2;
		if(strcmp(electronic[mid].Name,electroName) == 0)
		{
			return mid;
			break;
		}else if(strcmp(electroName,electronic[mid].Name) < 0)
		{
			right = mid - 1;
		}else
		{
			left = mid + 1;
		}
	}
	return -1;
	
}

void insertData()
{
	
	char electroName[255];
	char electroType[255];
	int electroPrice;
	int electroStock;
	int cek = 0;
	int cek2;
	int capacityCOuntCek = capacityCount;
	
	printf("Current capacity = %d\n",capacityCount);
	printf("Limit capacity = %.0lf\n",capacity);
	printf("\n");
	
	do
	{
		printf("Input Item Name [5-25 Characters | unique]: ");
		scanf("%[^\n]",electroName);
		getchar();
		cek = searchName(electronic,0,electronicCount-1,electroName);
	}while(strlen(electroName) < 5 || strlen(electroName) > 25 || cek != -1);

	do
	{
		cek2 = 1;
		printf("Input Item type [Small | Medium | Big]: ");
		scanf("%[^\n]",electroType);
		getchar();
		if(strcmp(electroType,"Small")==0)
		{
			capacityCOuntCek =capacityCOuntCek+ 1;
			if(capacityCOuntCek > capacity)
			{
				cek2 = 0;	
			}
			capacityCOuntCek =capacityCOuntCek- 1;
			
		}else if(strcmp(electroType,"Medium")==0)
		{
			capacityCOuntCek =capacityCOuntCek+ 2;
			if(capacityCOuntCek > capacity)
			{
				cek2 = 0;	
			}
			capacityCOuntCek =capacityCOuntCek- 2;
			
		}else if(strcmp(electroType,"Big")==0)
		{
			capacityCOuntCek =capacityCOuntCek+ 4;
			if(capacityCOuntCek > capacity)
			{
				cek2 = 0;	
			}
			capacityCOuntCek =capacityCOuntCek- 4;
			
		}
		
	}while((strcmp(electroType,"Small") != 0 && strcmp(electroType,"Medium") != 0 && strcmp(electroType,"Big") != 0 ) || cek2 == 0);	
	
	int cek3;
	do
	{
		cek3 = 1;
		if(strcmp(electroType,"Small")==0)
		{
			printf("Input Item price [max 200.000]: ");
			scanf("%d",&electroPrice);
			if(electroPrice>200000)
			{
				cek3=0;
			}
		}else if(strcmp(electroType,"Medium")==0)
		{
			printf("Input Item price [max 1.500.000]: ");
			scanf("%d",&electroPrice);
			if(electroPrice>1500000)
			{
				cek3=0;
			}
		}else if(strcmp(electroType,"Big")==0)
		{
			printf("Input Item price [max 10.000.000]: ");
			scanf("%d",&electroPrice);
			if(electroPrice>10000000)
			{
				cek3=0;
			}
		}
		
	}while(cek3==0);
	
	do
	{
		printf("Input item stock [more than 0]: ");
		scanf("%d",&electroStock);
		
		
		if(strcmp(electroType,"Small")==0)
		{
			capacityCount += electroStock*1;
		}else if(strcmp(electroType,"Medium")==0)
		{
			capacityCount += electroStock*2;
		}else if(strcmp(electroType,"Big")==0)
		{
			capacityCount += electroStock*4;
		}
		
		 
	}while(electroStock==0 || capacityCount > capacity);
	
	strcpy(electronic[electronicCount].Name,electroName);
	strcpy(electronic[electronicCount].Type,electroType);
	electronic[electronicCount].Price = electroPrice;
	electronic[electronicCount].Stock = electroStock;
	electronicCount++;
	quickSort(electronic,0,electronicCount-1);
}

void insertExistData()
{
	printf("==============================================================\n");
	printf("| Name                  | Type     | Price           | Stock |\n");
	printf("==============================================================\n");
	for(int i = 0; i < electronicCount; i++)
		{
			printf("| %-20s  | %-6s   | Rp. %-10d  | %-4d  |\n",electronic[i].Name,electronic[i].Type,electronic[i].Price,electronic[i].Stock);
		}
	printf("==============================================================\n");
	
	printf("Current capacity = %d\n",capacityCount);
	printf("Limit capacity = %.0lf\n",capacity);
	printf("\n");
	
	char electroName[255];
	int electroStock;
	int index;
	
	do
	{
		printf("Input electronic name want to add stock[input back to back]: " );
		scanf("%[^\n]",electroName);
		getchar();
		if(strcmp(electroName,"back")==0)
		{
			index = 1;
		}else
		{
			index = searchName(electronic,0,electronicCount-1,electroName);
		}
		
//		printf("%d",index);
	}while(index == -1);
	
	if(strcmp(electroName,"back")!=0)
	{
		do
		{
			char size[255];
			strcpy(size,electronic[index].Type);
			printf("Input how many stock you want to add: ");
			scanf("%d",&electroStock);
			if(strcmp(size,"Small")==0)
			{
				capacityCount += electroStock*1;
			}else if(strcmp(size,"Medium")==0)
			{
				capacityCount += electroStock*2;
			}else if(strcmp(size,"Big")==0)
			{
				capacityCount += electroStock*4;
			}
		
		}while(electronicCount > capacity);
		printf("Succesfully add\n");
		printf("Press enter to continue....");
		getchar();getchar();
		system("cls");
	}else if(strcmp(electroName,"back")!=0)
	{
		
	}
	
	electronic[index].Stock += electroStock;
	
}

void sell()
{
	printf("==============================================================\n");
	printf("| Name                  | Type     | Price           | Stock |\n");
	printf("==============================================================\n");
	for(int i = 0; i < electronicCount; i++)
		{
			printf("| %-20s  | %-6s   | Rp. %-10d  | %-4d  |\n",electronic[i].Name,electronic[i].Type,electronic[i].Price,electronic[i].Stock);
		}
	printf("==============================================================\n");	
	
	char electroName[255];
	int stockSell;
	int index;
	
	do
	{
		printf("Input electronic name want to sell[input back to back]: " );
		scanf("%[^\n]",electroName);
		getchar();
		if(strcmp(electroName,"back")==0)
		{
			index = 1;
		}else
		{
			index = searchName(electronic,0,electronicCount-1,electroName);
		}
		
	}while(index == -1);
	
	if(strcmp(electroName,"back")!=0)
	{
	do
	{
		printf("Input quantity want to sell[1-%d]: ",electronic[index].Stock );
		scanf("%d",&stockSell);
	}while(stockSell==0||stockSell>electronic[index].Stock);
	
	printf("\n");
	printf("\n");
	printf("Succesfully sold item!\n");
	printf("=======================\n");
	printf("Transaction Details\n");
	printf("=======================\n");
	printf("Electronic name: %s\n",electronic[index].Name);
	printf("Electronic type: %s\n",electronic[index].Type);
	printf("Quantity: %d\n",stockSell);
	printf("Total Price: %d\n",electronic[index].Price*stockSell);
	printf("Press enter to continue....");
	getchar();getchar();
	system("cls");
	
	if(stockSell==electronic[index].Stock)
	{
		for(int i=index;i<electronicCount;i++)
		{
			strcpy(electronic[i].Name,electronic[i+1].Name);
			strcpy(electronic[i].Type,electronic[i+1].Type);
			electronic[i].Price = electronic[i+1].Price;
			electronic[i].Stock = electronic[i+1].Stock;
		}
		electronicCount--;
	}else if(stockSell<electronic[index].Stock)
	{
		electronic[index].Stock -= stockSell;
	}
	}	
}

void save()
{
	FILE* data;
	data = fopen("electronic.txt","w");
	
	for(int i= 0; i<electronicCount; i++)
	{
		fprintf(data,"%s#%s#%d#%d\n",electronic[i].Name,electronic[i].Type,electronic[i].Price,electronic[i].Stock);
	}
	
	fclose(data);
}

int main()
{
	
	importData();
	
	int input;
	int option;
	
	do
	{
		puts("Electronics 2.0");
		puts("===============");
		puts("1. Insert Electronic Stock");
		puts("2. View Electronics List");
		puts("3. Sell Electronics");
		puts("4. Exit");
		printf(">> ");
		scanf("%d",&input);
		getchar();
		
		switch(input)
		{
			case 1:
				system("cls");
				do
				{
					puts("Select this two option");
					puts("1. Insert new item");
					puts("2. Add existing item stock");
					puts("0. Back");
					printf(">> ");
					scanf("%d",&option);
					getchar();
					
					switch(option)
					{
						case 1:
							system("cls");
							if(capacityCount >= capacity)
							{
								printf("There is no spaces left\n");
								printf("press enter to back.....");
								getchar();
								system("cls");
								break;
							}else
							{
								insertData();
								
							}
							break;
							
						case 2:
							system("cls");
							if(capacityCount >= capacity)
							{
								printf("There is no spaces left\n");
								printf("press enter to back.....");
								getchar();
								system("cls");
								break;
							}else
							{
								insertExistData();	
							}
//							system("cls");
							break;
					}
//					break;
					
				}while(option != 0);
				
				system("cls");
				
				break;
			case 2:
				system("cls");
				viewAll();
				break;
			case 3:
				system("cls");
				sell();
				
				break;
		}
		
	}while(input != 4);
	save();
	
}
