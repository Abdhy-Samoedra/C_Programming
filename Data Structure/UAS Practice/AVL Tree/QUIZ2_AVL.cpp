#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int id = 1;
int titleCek = 0;
int cekRoot = 0;

struct Book
{
    char title[100];
    char author[100];
    int year;
    int rating;
    int id;
    int height;

    Book *left, *right;
};

Book *createBook(const char title[], const char author[], int year, int rating)
{
    Book *newBook = (Book *)malloc(sizeof(Book));
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->year = year;
    newBook->rating = rating;
    newBook->id = id;
    newBook->height = 1;
    newBook->left = newBook->right = 0;
    id++;
    return newBook;
}

void cekTitle(Book *curr, const char title[])
{
    if (curr == 0)
    {
        return;
    }
    cekTitle(curr->left, title);
    if (strcmp(curr->title, title) == 0)
    {
        titleCek = 1;
    }
    cekTitle(curr->right, title);
}

int getMax(int a, int b)
{
    return (a >= b) ? a : b;
}

int calculateHeight(Book *node)
{
    return (node == 0) ? 0 : 1 + getMax(calculateHeight(node->left), calculateHeight(node->right));
}

int getBalance(Book *node)
{
    return (node == 0) ? 0 : calculateHeight(node->left) - calculateHeight(node->right);
}

Book *leftRotate(Book *node)
{
    Book *newParent = node->right;
    node->right = newParent->left;
    newParent->left = node;

    node->height = calculateHeight(node);
    newParent->height = calculateHeight(newParent);
    return newParent;
}

Book *rightRotate(Book *node)
{
    Book *newParent = node->left;
    node->left = newParent->right;
    newParent->right = node;

    node->height = calculateHeight(node);
    newParent->height = calculateHeight(newParent);

    return newParent;
}
Book *insertBook(Book *curr, Book *newBook)
{
    if (curr == 0)
    {
        return newBook;
    }
    else if (newBook->id < curr->id)
    {
        curr->left = insertBook(curr->left, newBook);
    }
    else if (newBook->id > curr->id)
    {
        curr->right = insertBook(curr->right, newBook);
    }

    curr->height = calculateHeight(curr);

    int balanceFactor = getBalance(curr);
    if (balanceFactor > 1)
    {
        if (newBook->id > curr->id)
        {
            curr->left = leftRotate(curr->left);
        }
        return rightRotate(curr);
    }
    else if (balanceFactor < -1)
    {
        if (newBook->id < curr->id)
        {
            curr->right = rightRotate(curr->right);
        }
        return leftRotate(curr);
    }
    return curr;
}

Book *deleteBook(Book *curr, int id)
{
    if (curr == 0)
    {
        printf("data not found\n");
        return curr;
    }
    else if (id < curr->id)
    {
        curr->left = deleteBook(curr->left, id);
    }
    else if (id > curr->id)
    {
        curr->right = deleteBook(curr->right, id);
    }
    else
    {
        if (curr->right == 0 && curr->left == 0)
        {
            free(curr);
            curr = 0;
        }
        else if (curr->right == 0)
        {
            Book *temp = curr;
            curr = curr->left;
            free(temp);
            temp = 0;
        }
        else if (curr->left == 0)
        {
            Book *temp = curr;
            curr = curr->right;
            free(temp);
            temp = 0;
        }
        else
        {
            Book *temp = curr->left;
            while (temp->right != 0)
            {
                temp = temp->right;
            }
            strcpy(curr->title, temp->title);
            strcpy(curr->author, temp->author);
            curr->year = temp->year;
            curr->rating = temp->rating;
            curr->id = temp->id;
            curr->left = deleteBook(curr->left, temp->id);
        }
    }

    int balanceFactor = getBalance(curr);
    if (balanceFactor > 1)
    {
        if (id > curr->id)
        {
            curr->left = leftRotate(curr->left);
        }
        return rightRotate(curr);
    }
    else if (balanceFactor < -1)
    {
        if (id < curr->id)
        {
            curr->right = rightRotate(curr->right);
        }
        return leftRotate(curr);
    }

    return curr;
}

Book *findBook(Book *curr, int id)
{
    if (curr == 0)
    {
        printf("not found");
        return 0;
    }
    else if (id < curr->id)
    {
        curr->left = findBook(curr->left, id);
    }
    else if (id > curr->id)
    {
        curr->right = findBook(curr->right, id);
    }
    else
    {
        printf("ID : %d\n", curr->id);
        printf("Title : %s\n", curr->title);
        printf("Author : %s\n", curr->author);
        printf("Year : %d\n", curr->year);
        printf("Rating : %d\n\n", curr->rating);
        // return curr;
    }
}
void showAll(Book *curr)
{
    if (curr == 0)
    {
        return;
    }
    showAll(curr->left);
    printf("ID : %d\n", curr->id);
    printf("Title : %s\n", curr->title);
    printf("Author : %s\n", curr->author);
    printf("Year : %d\n", curr->year);
    printf("Rating : %d\n\n", curr->rating);
    showAll(curr->right);
}

void cekUnderTitle(Book *curr, const char title[])
{
    if (curr == 0)
    {
        return;
    }
    cekUnderTitle(curr->left, title);
    if (strcmp(curr->title, title) == 0)
    {
        printf("left\n");
        showAll(curr->left);
        printf("right\n");
        showAll(curr->right);
    }
    cekUnderTitle(curr->right, title);
}
void rootCek(Book *curr)
{
    if (curr == 0)
    {
        return;
    }
    rootCek(curr->left);
    cekRoot++;
    rootCek(curr->right);
}

int main()
{
    Book *root = NULL;
    root = insertBook(root, createBook("More Than Balloons", "Gregor", 1997, 4));
    root = insertBook(root, createBook("Dump Truck", "Heimdall", 2000, 3));
    root = insertBook(root, createBook("Hello World", "Travy", 1999, 4));
    root = insertBook(root, createBook("Secret Tetris", "Tetron", 2010, 5));
    root = insertBook(root, createBook("Florian", "Homer", 1997, 2));
    root = insertBook(root, createBook("Sea Gardener", "Garen", 2005, 4));
    root = insertBook(root, createBook("Wild Dog", "Hisna", 2006, 4));
    root = insertBook(root, createBook("Trump Game", "Fiona", 2009, 2));
    root = insertBook(root, createBook("Class Act", "Navi", 2002, 1));
    // root = insertBook(root, createBook("Silly Bear", "Garen", 2020, 5));

    int menu;
    char command[100];
    int insert;

    char title[100];
    char author[100];
    int year;
    int rating;

    int find;
    int del;
    char underTitle[100];

    scanf("%d", &menu);
    getchar();
    for (int i = 0; i < menu; i++)
    {
        scanf("%s", command);
        getchar();
        if (strcmp(command, "INSERT") == 0)
        {
            scanf("%d", &insert);
            getchar();
            for (int j = 0; j < insert; j++)
            {
                scanf("%[^#]#%[^#]#%d#%d", title, author, &year, &rating);
                getchar();
                cekTitle(root, title);
                if (titleCek == 1)
                {
                    printf("title already exist\n");
                    scanf("%[^#]#%[^#]#%d#%d", title, author, &year, &rating);
                    getchar();
                }
                root = insertBook(root, createBook(title, author, year, rating));
            }
        }
        else if (strcmp(command, "FIND") == 0)
        {
            scanf("%d", &find);
            getchar();
            findBook(root, find);
        }
        else if (strcmp(command, "DELETE") == 0)
        {
            scanf("%d", &del);
            getchar();
            root = deleteBook(root, del);
        }
        else if (strcmp(command, "SHOWALL") == 0)
        {
            showAll(root);
        }
        else if (strcmp(command, "CHECKLEFTROOT") == 0)
        {
            rootCek(root->left);
            printf("%d", cekRoot);
            cekRoot = 0;
        }
        else if (strcmp(command, "CHECKRIGHTROOT") == 0)
        {
            rootCek(root->right);
            printf("%d", cekRoot);
            cekRoot = 0;
        }
        else if (strcmp(command, "TITLEUNDER") == 0)
        {
            scanf("%[^\n]", underTitle);
            getchar();
            cekUnderTitle(root,underTitle);
        }
    }
}
