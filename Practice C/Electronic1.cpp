#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int main()
{
	int input;
	int index;
	int update;
	int sell;
	char yatidak [100] ;
	
	char itemId[100];
	char itemName[100];
	double itemPrice;
	
	char insertId[100][100];
	char insertName[100][100];
	double insertPrice[100];
	do
	{
		puts("Electronics!");
		puts("==============");
		puts("1. Insert Electronics Stock");
		puts("2. Update Electronics");
		puts("3. Sell Electronics");
		puts("4. Exit");
		printf(">> ");
		scanf("%d",&input);	getchar();
		
		if(input == 1)
		{
			do
			{
				printf("Input item Id [must be numeric with exactly 3 digit] : ");
				scanf("%s",itemId); getchar();

			} while(!isdigit(itemId[0]) || !isdigit(itemId[1]) || !isdigit(itemId[2]) || strlen(itemId) > 3);
			
			do
			{
				printf("Input item Name [5-25 character] : ");
				scanf("%[^\n]",itemName); getchar();
			} while(strlen(itemName) < 6 || strlen(itemName) > 24);
			
			do
			{
				printf("Input item Price [not more than 5m] : ");
				scanf("%lf",&itemPrice); getchar();
			} while(itemPrice > 5000000);
			
			strcpy(insertId[index], itemId);
			strcpy(insertName[index],itemName);
			insertPrice[index] = itemPrice;
			index++;
			
			puts("Item successfully inserted!");
			puts("Press enter to continue "); getchar();
		}
		
		if(input == 2)
		{
			
			if(index != 0)
			{	
			printf("=====================================================================\n");
			printf("| No. | Id      | Name                       | Price                |\n");
			printf("=====================================================================\n");
			for(int j = 0; j < index; j++)
				{
					printf("| %d  | ETC%s   | %-25s  | Rp. %-15.2lf  |\n",j+1,insertId[j],insertName[j],insertPrice[j]);
				}
			printf("=====================================================================\n");
				
			do
			{
			printf("Which item you want to update? [0 to exit] [1...%d] : ",index);
			scanf("%d",&update);getchar();
			} while(update > index || update < 1);
					
			do
			{
				printf("Input item Id [must be numeric with exactly 3 digit] : ");
				scanf("%s",itemId); getchar();
	
			} while(!isdigit(itemId[0]) || !isdigit(itemId[1]) || !isdigit(itemId[2]) || strlen(itemId) > 3);
				
			do
			{
				printf("Input item Name [5-25 character] : ");
				scanf("%[^\n]",itemName); getchar();
			} while(strlen(itemName) < 6 || strlen(itemName) > 24);
				
			do
			{
				printf("Input item Price [not more than 5m] : ");
				scanf("%lf",&itemPrice); getchar();
			} while(itemPrice > 5000000);
				
			strcpy(insertId[update-1], itemId);
			strcpy(insertName[update-1],itemName);
			insertPrice[update-1] = itemPrice;
					
					
			puts("Item successfully updated");
			puts("Press enter to continue "); getchar();
					
		}else
		{
			puts("There is no item yet...");
			puts("Press enter to continue "); getchar();
		}	
			
		}
		
		if(input == 3)
		{
		
			if(index != 0)
			{	
				printf("=====================================================================\n");
				printf("| No. | Id      | Name                       | Price                |\n");
				printf("=====================================================================\n");
				for(int j = 0; j < index; j++)
				{
					printf("| %d  | ETC%s   | %-25s  | Rp. %-15.2lf  |\n",j+1,insertId[j],insertName[j],insertPrice[j]);
				}
			printf("=====================================================================\n");
				
			do
			{
			printf("Which item you want to sell? [0 to exit] [1...%d] : ",index);
			scanf("%d",&sell);getchar();
			} while(sell > index || sell < 1);
			
			if(sell != 0)
			{
				int yes,no;
				srand(time(0));
				if(rand()%11 < 3)
				{
					puts("###########################");
					puts("Cutomer get discount 25%");
					puts("###########################");
					printf("\n");
					printf("ETC%s Item Detail\n",insertId[sell-1]);
					printf("============================================\n");
					printf("item name : %s\n",insertName[sell-1]);
					printf("item price : %.2lf\n",insertPrice[sell-1]-(insertPrice[sell-1] * 0.25));
					
					do
					{
						printf("are you sure you want to sell this? [yes/no]: ");
					scanf("%s",yatidak);getchar();
					yes = strcmp(yatidak,"yes");
					no = strcmp(yatidak,"no");
					}while(strcmp(yatidak,"yes") && strcmp(yatidak,"no"));
					
					if (yes == 0)
					{
						for(int k =sell; k< index; k++)
						{
							strcpy(insertId[k],insertId[k+1]);
							strcpy(insertName[k],insertName[k+1]);
							insertPrice[k] = insertPrice[k+1];
						}
						index --;
						puts("item succesfully to sel...");
			puts("Press enter to continue "); getchar();
						
					}if (no == 0)
					{
						puts("cancel selling...");
			puts("Press enter to continue "); getchar();
					}
					
				}else
				{
					
					printf("============================================\n");
					printf("ETC%s Item Detail\n",insertId[sell-1]);
					printf("item name : %s\n",insertName[sell-1]);
					printf("item price : %.2lf\n",insertPrice[sell-1]);
					do
					{
						printf("are you sure you want to sell this? [yes/no]: ");
					scanf("%s",yatidak);getchar();
					yes = strcmp(yatidak,"yes");
					no = strcmp(yatidak,"no");
					}while(strcmp(yatidak,"yes") && strcmp(yatidak,"no"));
					
					if (yes == 0)
					{
						for(int k =sell; k< index; k++)
						{
							strcpy(insertId[k],insertId[k+1]);
							strcpy(insertName[k],insertName[k+1]);
							insertPrice[k] = insertPrice[k+1];
						}
						index --;
						puts("item succesfully to sel...");
			puts("Press enter to continue "); getchar();
						
					}if (no == 0)
					{
						puts("cancel selling...");
			puts("Press enter to continue "); getchar();
					}
				}
			}
			
			
				
			}else
			{
				puts("There is no item yet...");
				puts("Press enter to continue "); getchar();
			}
			
		
	}

}while(input!=4);
}









