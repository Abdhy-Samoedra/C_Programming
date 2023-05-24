#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cekTitle = 0;

struct Game
{
    char title[100];
    char genre[100];
    int stock;
    int height;
    Game *left, *right;
} *root = 0;

Game *createGame(const char title[], const char genre[], int stock)
{
    Game *newGame = (Game *)malloc(sizeof(Game));
    strcpy(newGame->title, title);
    strcpy(newGame->genre, genre);
    newGame->stock = stock;
    newGame->height = 1;
    newGame->left = newGame->right = 0;
    return newGame;
}

int getMax(int a, int b)
{
    return (a >= b) ? a : b;
}
int calculateHeight(Game *node)
{
    return (node == 0) ? 0 : 1 + getMax(calculateHeight(node->left), calculateHeight(node->right));
}

int getBalance(Game *node)
{
    return (node == 0) ? 0 : calculateHeight(node->left) - calculateHeight(node->right);
}
Game *leftRotate(Game *node)
{
    Game *newParent = node->right;
    node->right = newParent->left;
    newParent->left = node;

    node->height = calculateHeight(node);
    newParent->height = calculateHeight(newParent);
    return newParent;
}
Game *rightRotate(Game *node)
{
    Game *newParent = node->left;
    node->left = newParent->right;
    newParent->right = node;

    node->height = calculateHeight(node);
    newParent->height = calculateHeight(newParent);
    return newParent;
}
Game *insertGame(Game *curr, Game *newGame)
{
    if (curr == 0)
    {
        return newGame;
    }
    else if (strcmp(newGame->title, curr->title) < 0)
    {
        curr->left = insertGame(curr->left, newGame);
    }
    else if (strcmp(newGame->title, curr->title) > 0)
    {
        curr->right = insertGame(curr->right, newGame);
    }

    curr->height = calculateHeight(curr);

    int balanceFactor = getBalance(curr);
    if (balanceFactor > 1)
    {
        if (strcmp(newGame->title, curr->title) > 0)
        {
            curr->left = leftRotate(curr->left);
        }
        return rightRotate(curr);
    }
    if (balanceFactor < 1)
    {
        if (strcmp(newGame->title, curr->title) < 0)
        {
            curr->right = rightRotate(curr->right);
        }
        return leftRotate(curr);
    }
    return curr;
}

void viewAll(Game *curr)
{
    if (curr == 0)
    {
        return;
    }
    viewAll(curr->left);
    printf("| %-30s | %-15s | %-10d |\n", curr->title, curr->genre, curr->stock);
    printf("===============================================\n");
    viewAll(curr->right);
}

Game *checkingTitle(Game *curr, const char title[])
{
    if (curr == 0)
    {
        return 0;
    }
    else if (strcmp(title, curr->title) < 0)
    {
        return checkingTitle(curr->left, title);
    }
    else if (strcmp(title, curr->title) > 0)
    {
        return checkingTitle(curr->right, title);
    }
    else
    {
        cekTitle = 1;
        return curr;
    }
}

void insertNewGame()
{
    char title[100];
    char genre[100];
    int stock;
    do
    {
        cekTitle = 0;
        printf("Input game title[5-25][unique]: ");
        scanf("%[^\n]", title);
        getchar();
        checkingTitle(root, title);
    } while (strlen(title) < 5 || strlen(title) > 25 || cekTitle == 1);
    cekTitle = 0;
    do
    {
        printf("Input game type[Action][RPG][Adventure][Card Game]: ");
        scanf("%[^\n]", genre);
        getchar();
    } while (strcmp(genre, "Action") != 0 && strcmp(genre, "RPG") != 0 && strcmp(genre, "Adventure") != 0 && strcmp(genre, "Card Game") != 0);
    do
    {
        printf("Input game stock: ");
        scanf("%d", &stock);
        getchar();
    } while (stock < 1);
    root = insertGame(root, createGame(title, genre, stock));
}


Game *deleteGame(Game *curr, const char title[])
{
    if (curr == 0)
    {
        return 0;
    }
    else if (strcmp(title, curr->title) < 0)
    {
        curr->left = deleteGame(curr->left, title);
    }
    else if (strcmp(title, curr->title) > 0)
    {
        curr->right = deleteGame(curr->right, title);
    }
    else
    {
        if (curr->left == 0 && curr->right == 0)
        {
            free(curr);
            curr = 0;
        }
        else if (curr->left == 0)
        {
            Game *temp = curr;
            curr = curr->right;
            free(temp);
            temp = 0;
        }
        else if (curr->right == 0)
        {
            Game *temp = curr;
            curr = curr->left;
            free(temp);
            temp = 0;
        }
        else
        {
            Game *temp = curr->left;
            while (temp->right != 0)
            {
                temp = temp->right;
            }
            strcpy(curr->title, temp->title);
            strcpy(curr->genre, temp->genre);
            curr->stock = temp->stock;
            curr->left = deleteGame(curr->left, temp->title);
        }

        int balanceFactor = getBalance(curr);
        if (balanceFactor > 1)
        {
            if (strcmp(title, curr->title) > 0)
            {
                curr->left = leftRotate(curr->left);
            }
            return rightRotate(curr);
        }
        else if (balanceFactor < -1)
        {
            if (strcmp(title, curr->title) < 0)
            {
                curr->right = rightRotate(curr->right);
            }
            return leftRotate(curr);
        }
    }
    return curr;
}

void deleteData()
{
    char title[100];
    char type[100];
    int update;
    int remove;
    Game *currRoot = NULL;
    printf("Input game title: ");
    scanf("%[^\n]", title);
    getchar();
    currRoot = checkingTitle(root, title);
    printf(currRoot->title);
    if (cekTitle != 1)
    {
        printf("Data not found!\n");
        printf("Press enter to continue...");
        getchar();
        cekTitle = 0;
    }
    else
    {
        cekTitle = 0;
        do
        {
            printf("Input update type[add][remove][case insensitive]: ");
            scanf("%[^\n]", type);
            getchar();
        } while (strcmpi(type, "add") != 0 && strcmpi(type, "remove") != 0);
        if (strcmpi(type, "add") == 0)
        {
            do
            {
                printf("Input stock to add: ");
                scanf("%d", &update);
                getchar();
            } while (update < 1);
            currRoot->stock += update;
        }
        else if (strcmpi(type, "remove") == 0)
        {
            do
            {
                printf("Input stock to remove[1-%d]: ", currRoot->stock);
                scanf("%d", &update);
                getchar();
            } while (update > currRoot->stock);
            currRoot->stock -= update;
            if (currRoot->stock == 0)
            {
                printf("%s is removed from the warehouse!\n", title);
                root = deleteGame(root, title);
            }
            printf("press enter to continue");
            getchar();
        }
    }
    currRoot = NULL;
}
 
int main()
{

    int input;

    do
    {
        system("cls");
        printf("Bluejack GShop\n");
        printf("==============\n");
        printf("1. Insert Game\n");
        printf("2. View Game\n");
        printf("3. Update Stock\n");
        printf("4. Exit\n");
        printf(">> ");
        scanf("%d", &input);
        getchar();
        switch (input)
        {
        case 1:
            system("cls");
            insertNewGame();
            printf("Succes input, press Enter...");
            getchar();
            break;
        case 2:
            system("cls");
            if (root == 0)
            {
                printf("Warehouse is empty!\n");
                printf("Press enter to continue...");
                getchar();
            }
            else
            {
                printf("=================================================================\n");
                printf("| Title                          | Genre          | Stock       |\n");
                printf("=================================================================\n");
                viewAll(root);
                printf("Press enter to back....");
                getchar();
            }
            break;
        case 3:
            deleteData();
            break;
        }
    } while (input != 4);
}
