#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

const int SIZE = 1007;
int countBook = 0;
struct Book
{
	char bookTitle[100];
	char bookAuthor[100];
	char ISBN[100];
	char bookId[100];
	int bookPage;
	struct Book *next,*prev;
};
struct Table
{
	struct Book *head,*tail;
} *table[SIZE];

void initializeTable()
{
	for(int i = 0;i<SIZE;i++)
	{
		table[i] = (struct Table*)malloc(sizeof(struct Table));
		table[i]->head = table[i]->tail = 0;
	}
}
struct Book *createBook(char bookId[],char bookTitle[],char bookAuthor[],char ISBN[],int bookPage)
{
	struct Book *temp = (struct Book*)malloc(sizeof(struct Book));
	strcpy(temp->bookTitle,bookTitle);
	strcpy(temp->bookAuthor,bookAuthor);
	strcpy(temp->bookId,bookId);
	strcpy(temp->ISBN,ISBN);
	temp->bookPage = bookPage;
	temp->next = temp->prev = 0;
	return temp;
}

int hash(char bookId[])
{
	int sum =0;
	for(int i = 0; i<strlen(bookId);i++)
	{
		sum += bookId[i];
	}
	return sum % SIZE;
}
void push(int key, struct Book *newBook)
{
	if(table[key]->head == 0)
	{
		table[key]->head = table[key]->tail = newBook;
	}else
	{
		newBook->prev = table[key]->tail;
		table[key]->tail->next = newBook;
		table[key]->tail = newBook;	
	}
}
void insertBook(char bookId[],char bookTitle[],char bookAuthor[],char ISBN[],int bookPage)
{
	int key = hash(bookId);
	struct Book *newBook = createBook(bookId,bookTitle,bookAuthor,ISBN,bookPage);
	push(key,newBook);
}

void view()
{
	if(countBook ==0)
	{
		printf("buku belum ada\n");
	}else
	{
			printf("=================================================\n");
			printf("|book id   | book title   | book author | ISBN    |  page number    |\n");
		for (int i =0;i<SIZE;i++)
		{
			struct Book *curr = table[i]->head;
		
			while(curr != 0)
			{
				printf("|%-10s |%-10s |%-10s |%-10s |%-2d |\n",curr->bookId,curr->bookTitle,curr->bookAuthor,curr->ISBN,curr->bookPage);
				curr = curr->next;
			}
		}
	}

}

int cekTitle(char title[])
{
	for (int i=0;i<SIZE;i++)
	{
		struct Book *curr = table[i]->head;
		while(curr!=0 && strcmpi(title,curr->bookTitle)!=0)
		{
			curr = curr->next;
		}
		if(curr != 0)
		{
			return 1;
		}
	}
	return -1;
}
int cekiddel(char idtodel[])
{
	for (int i=0;i<SIZE;i++)
	{
		struct Book *curr = table[i]->head;
		while(curr!=0 && strcmpi(idtodel,curr->bookId)!=0)
		{
			curr = curr->next;
		}
		if(curr != 0)
		{
			return 1;
		}
	}
	printf("id tidak ada\n");
	return -1;
}

int cekAuthor(char author[])
{
	char mr[] = "Mr. ";
	char mrs[] = "Mrs. ";
	int cek = 0;
	for(int i = 0;i<4;i++)
	{
		if(author[i] != mr[i])
		{
			cek = 1;
			break;
		}
	}
	if(cek == 1)
	{
		for(int i=0;i<5;i++)
		{
			if(author[i]!=mrs[i])
			{
				return -1;
			}
		}
	}
	return 1;
	
}
int cekIsbn(char ISBN[])
{
	for(int i=0;i<strlen(ISBN);i++)
	{
		if(isdigit(ISBN[i]) == 0)
		{
			return -1;
		}
	}
	return 1;
}

void popHead(int key)
{
	if(table[key]->head == 0)
	{
		printf("data gada\n");
		return;
	}else if(table[key]->head == table[key]->tail)
	{
		free(table[key]->head);
		table[key]->head=table[key]->tail=0;
	}else
	{
		struct Book *curr = table[key]->head->next;
		curr->prev = 0;
		free(table[key]->head);
		table[key]->head = curr;
	}
}
void popTail(int key)
{
	if(table[key]->tail == 0)
	{
		printf("data gada\n");
		return;
	}else if(table[key]->head == table[key]->tail)
	{
		free(table[key]->head);
		table[key]->head=table[key]->tail=0;
	}else
	{
		struct Book *curr = table[key]->tail->prev;
		curr->next = 0;
		free(table[key]->tail);
		table[key]->tail = curr;
	}
}
void popMid(int key, char idbook[])
{
	struct Book *curr = table[key]->head;
	while(curr!=0 && strcmpi(idbook,curr->bookId)!=0)
	{
		curr = curr->next;
	}
	if(curr == 0)
	{
		printf("data tidak ada\n");
		return;
	}
	curr->next->prev = curr->prev;
	curr->prev->next = curr->next;
	free(curr);
	curr=0;
	return;
}
void deleteBook(char idbook[])
{
	int key = hash(idbook);
	if(table[key]->head == 0)
	{
		printf("tidak ada data\n");
		return;
	}else if(strcmpi(idbook,table[key]->head->bookId) == 0)
	{
		popHead(key);
	}else if(strcmpi(idbook,table[key]->tail->bookId) == 0)
	{
		popTail(key);
	}else
	{
		popMid(key,idbook);
	}
}
int main()
{
	initializeTable();
	int input;
	char bookId[100];
	char title[100];
	char author[100];
	char ISBN[100];
	int page;
	int cekauthor;
	int cektitle;
	int cekiSBN;
	int idCount = 1;
	char idtodel[100];
	int cekdel;
	do{
		printf("Bluejak Library\n");
		printf("===============\n");
		printf("1. view book\n");
		printf("2. insert book\n");
		printf("3. remove book\n");
		printf("4. exit\n");
		printf(">> ");
		scanf("%d",&input);getchar();
		switch(input)
		{
			case 1:
				view();
				break;
			case 2:
				do
				{
					printf("Input book title[5-50][unique]: ");
					scanf("%[^\n]",title);getchar();
					cektitle = cekTitle(title);
				}while(strlen(title)<5 || strlen(title)> 50 || cektitle > 0);
				do
				{
					printf("input author name : ");
					scanf("%[^\n]",author);getchar();
					cekauthor = cekAuthor(author);
					printf("%d",cekiSBN);
				}while(strlen(author) < 3 || strlen(author) >25 || cekauthor < 0);
				do
				{
					printf("input  ISBN : ");
					scanf("%[^\n]",ISBN);getchar();
					cekiSBN = cekIsbn(ISBN);
					printf("%d",cekiSBN);
				}while(strlen(ISBN)<10 || strlen(ISBN)>13 || cekiSBN < 0);
				do
				{
					printf("input page number : ");
					scanf("%d",&page);getchar();
				}while(page<16);
				sprintf(bookId,"B%05d-%s-%c-%c",idCount,ISBN,toupper(author[0]),toupper(title[0]));
				insertBook(bookId,title,author,ISBN,page);
				countBook++;
				idCount++;
				break;
			case 3:
				view();
				do
				{
					printf("input id to delete : ");
					scanf("%s",idtodel);
					cekdel = cekiddel(idtodel);
					printf("%d",cekdel);
				}while(cekdel<0);
				deleteBook(idtodel);
				
				
				break;
			default:
				printf("pilih antara 1-4\n");
				break;
		}
	}while(input != 4);
	
}
