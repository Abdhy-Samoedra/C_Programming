#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int check = 1;

struct Salon
{
	char name[100];
	int price;
	char category[100];
	char avail[100];
	int height;
	Salon *left , *right;
}*root = NULL;

Salon *createSalon(const char name[], int price,const char category[] ,const char avail[])
{
	Salon *newSalon = (Salon*)malloc(sizeof(Salon));
	strcpy(newSalon->name,name);
	newSalon->price = price;
	strcpy(newSalon->category,category);
	strcpy(newSalon->avail,avail);
	newSalon->height = 1;
	newSalon->left = newSalon->right = NULL;
	return newSalon;
}

int getMax(int a, int b)
{
	return (a >= b) ? a : b;
}
int calculateHeight(Salon *node)
{
	return (node == 0) ? 0 : 1 + getMax(calculateHeight(node->left),calculateHeight(node->right));
}
int getBalance(Salon *node)
{
	return (node == 0) ? 0 : calculateHeight(node->left) - calculateHeight(node->right);
}

Salon *leftRotate(Salon *node)
{
	Salon *newParent = node->right;
	node->right = newParent->left;
	newParent->left = node;
	
	node->height = calculateHeight(node);
	newParent->height = calculateHeight(newParent);
	
	return newParent;
}
Salon *rightRotate(Salon *node)
{
	Salon *newParent = node->left;
	node->left = newParent->right;
	newParent->right = node;
	
	node->height = calculateHeight(node);
	newParent->height = calculateHeight(newParent);
	
	return newParent;
}

Salon *insertSalon(Salon *curr, Salon *newSalon)
{
	if(curr == 0)
	{
		return newSalon;
	}else if(strcmp(newSalon->name,curr->name) < 0)
	{
		curr->left = insertSalon(curr->left, newSalon);
	}else if(strcmp(newSalon->name,curr->name) > 0)
	{
		curr->right = insertSalon(curr->right, newSalon);
	}
	newSalon->height = calculateHeight(curr);
	
	int balanceFactor = getBalance(curr);
	
	if(balanceFactor > 1)
	{
		if(strcmp(newSalon->name,curr->name) > 0)
		{
			curr->left = leftRotate(curr->left);
		}
		return rightRotate(curr);
	}else if(balanceFactor < -1)
	{
		if(strcmp(newSalon->name,curr->name) < 0)
		{
			curr->right = rightRotate(curr->right);
		}
		return leftRotate(curr);
	}
	return curr;
}
int validateName(const char name[])
{
	if(strlen(name) > 5 && strlen(name) < 20)
	{
		if(name[0] == 'S' && name[1] == 'a' && name[2] == 'l' && name[3] == 'l' && name[4] == 'y')
		{
			if(isspace(name[5]) != 0 && isalpha(name[6]) > 0)
			{
				return 1;
			}
		}
	}
	return 0;
}
void insert()
{
	char name[100];
	int price;
	char category[100];
	char avail[100];
	printf("Insert New Treatment\n");
	do
	{	
		printf("Input new treatment name : ");
		scanf("%[^\n]", name);getchar();
	}while(validateName(name) == 0);
	do
	{
		printf("Input treatment price [50000-1000000]: ");
		scanf("%d", &price);getchar();
	}while(price < 50000 || price > 1000000);
	do
	{
		printf("Input treatment category [Hair Care | Nail Care | Body Care]: ");
		scanf("%[^\n]", category);getchar();
	}while(strcmp(category,"Hair Care") != 0 && strcmp(category,"Nail Care") != 0 && strcmp(category,"Body Care") != 0);
	
	do
	{
		printf("Input treatment avaibility [Available | Unavailable]: ");
		scanf("%[^\n]", avail);getchar();
	}while(strcmp(avail,"Available") != 0 && strcmp(avail,"Unavailable") !=0);
	
	root = insertSalon(root,createSalon(name,price,category,avail));
	printf("New treatment succes to input\n");
	printf("Press enter to continue.....");getchar();
}

void viewPreorder(Salon *curr)
{
	if(curr == 0)
	{
		return;
	}
	printf("|%s  |  %s  |  %d  |  %s  |\n",curr->name,curr->category,curr->price,curr->avail);
	viewPreorder(curr->left);
	viewPreorder(curr->right);
}
void viewInorder(Salon *curr)
{
	if(curr == 0)
	{
		return;
	}
	viewInorder(curr->left);
	printf("|%s  |  %s  |  %d  |  %s  |\n",curr->name,curr->category,curr->price,curr->avail);
	viewInorder(curr->right);
}
void viewPostorder(Salon *curr)
{
	if(curr == 0)
	{
		return;
	}
	viewPostorder(curr->left);
	viewPostorder(curr->right);
	printf("|%s  |  %s  |  %d  |  %s  |\n",curr->name,curr->category,curr->price,curr->avail);
}

void printMenu()
{
	char type[100];
	do
	{
		printf("input view order [pre | in | post]: ");
		scanf("%s",type);getchar();
	}while(strcmp(type,"pre") != 0 && strcmp(type,"in") != 0 && strcmp(type,"post") != 0);
	if(strcmp(type,"pre") == 0)
	{
		viewPreorder(root);
	}else if(strcmp(type,"in") == 0)
	{
		viewInorder(root);
	}else if(strcmp(type,"post") == 0)
	{
		viewPostorder(root);
	}
	printf("\n");
	printf("press enter to continue...");getchar();
}
Salon *deleteSalon(Salon *curr, const char name[])
{
	if(curr == 0)
	{
		printf("Data not found\n");
		printf("Press enter to continue...");getchar();
		check = 0;
		return 0;
	}else if(strcmp(name,curr->name) < 0)
	{
		curr->left = deleteSalon(curr->left, name);
	}else if(strcmp(name,curr->name) > 0)
	{
		curr->right = deleteSalon(curr->right, name);
	}else
	{
		if(curr->right == 0 && curr->left ==0)
		{
			free(curr);
			curr = 0;
		}else if(curr->right == 0)
		{
			Salon *temp = curr;
			curr = curr->left;
			free(temp);
			temp = 0;
		}else if(curr->left == 0)
		{
			Salon *temp = curr;
			curr = curr->right;
			free(temp);
			temp = 0;
		}else
		{
			Salon *temp = curr->left;
			while(temp->right != 0)
			{
				temp = temp->right;
			}
			strcpy(curr->name,temp->name);
			curr->price = temp->price;
			strcpy(curr->category,temp->category);
			strcpy(curr->avail,temp->avail);
			curr->left = deleteSalon(curr->left,temp->name);
		}
	}
	
	int balanceFactor = getBalance(curr);
	
	if(balanceFactor > 1)
	{
		if(strcmp(name,curr->name) > 0)
		{
			curr->left = leftRotate(curr->left);
		}
		return rightRotate(curr);
	}else if(balanceFactor < -1)
	{
		if(strcmp(name,curr->name) < 0)
		{
			curr->right = rightRotate(curr->right);
		}
		return leftRotate(curr);
	}
	return curr;
}
void deleteMenu()
{
	char nameToDel[100];
	printf("Delete Treatment\n");
	viewInorder(root);
	printf("\n");
	printf("Input treatment to delete: ");
	scanf("%[^\n]",nameToDel);getchar();
	root = deleteSalon(root, nameToDel);
	if(check != 0)
	{
		printf("Data succes to delete \n");
		printf("Press enter to continue...");getchar();
	}
	check = 1;
}
int main()
{
	root = insertSalon(root,createSalon("Sally d",60000,"Nail care","Available"));
	root = insertSalon(root,createSalon("Sally x",60000,"Nail care","Available"));
	root = insertSalon(root,createSalon("Sally t",60000,"Nail care","Available"));
	root = insertSalon(root,createSalon("Sally a",60000,"Nail care","Available"));
	root = insertSalon(root,createSalon("Sally i",60000,"Nail care","Available"));
	int input;
	
	do
	{
		system("cls");
		printf("============\n");
		printf("SALLY SALLON\n");
		printf("============\n");
		printf("Menu:\n");
		printf("1. View Available Treatment\n");
		printf("2. Insert New Treatment\n");
		printf("3. Delete Treatment\n");
		printf("4. Exit\n");
		printf("[1-4]\n");
		printf(">> ");
		scanf("%d", &input);getchar();
		
		switch(input)
		{
			case 1:
				system("cls");
				if(root == 0)
				{
					printf("No data\n");
					printf("Press to enter...");getchar();
				}else
				{
					printMenu();
				}
				break;
			case 2:
				system("cls");
				insert();
				break;
			case 3:
				system("cls");
				if(root == 0)
				{
					printf("No data\n");
					printf("Press to enter...");getchar();
				}else
				{
					deleteMenu();
				}
				break;
		}
	}while(input != 4);
}
