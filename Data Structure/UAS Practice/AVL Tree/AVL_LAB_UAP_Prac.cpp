#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int findID = 0;
struct Property
{
    char id[100];
    char type[100];
    int N;
    int length;
    int price;
    int height;
    Property *left, *right;
};

Property *createProp(const char id[], const char type[], int N, int length, int price)
{
    Property *newProp = (Property *)malloc(sizeof(Property));
    strcpy(newProp->id, id);
    strcpy(newProp->type, type);
    newProp->N = N;
    newProp->length = length;
    newProp->price = price;
    newProp->height = 1;
    newProp->left = newProp->right = 0;
    return newProp;
}

int getMax(int a, int b)
{
    return (a >= b) ? a : b;
}
int calculateHeight(Property *node)
{
    return (node == 0) ? 0 : 1 + getMax(calculateHeight(node->left), calculateHeight(node->right));
}

int getBalance(Property *node)
{
    return (node == 0) ? 0 : calculateHeight(node->left) - calculateHeight(node->right);
}

Property *leftRotate(Property *node)
{
    Property *newParent = node->right;
    node->right = newParent->left;
    newParent->left = node;

    node->height = calculateHeight(node);
    newParent->height = calculateHeight(newParent);

    return newParent;
}
Property *rightRoate(Property *node)
{
    Property *newParent = node->left;
    node->left = newParent->right;
    newParent->right = node;

    node->height = calculateHeight(node);
    newParent->height = calculateHeight(newParent);

    return newParent;
}

Property *insertProp(Property *curr, Property *newProp)
{
    if (curr == 0)
    {
        return newProp;
    }
    else if (strcmp(newProp->id, curr->id) < 0)
    {
        curr->left = insertProp(curr->left, newProp);
    }
    else if (strcmp(newProp->id, curr->id) > 0)
    {
        curr->right = insertProp(curr->right, newProp);
    }

    curr->height = calculateHeight(curr);

    int balanceFactor = getBalance(curr);
    if (balanceFactor > 1)
    {
        if (strcmp(newProp->id, curr->id) > 0)
        {
            curr->left = leftRotate(curr->left);
        }
        return rightRoate(curr);
    }
    else if (balanceFactor < -1)
    {
        if (strcmp(newProp->id, curr->id) < 0)
        {
            curr->right = rightRoate(curr->right);
        }
        return leftRotate(curr);
    }

    return curr;
}
Property *deleteProp(Property *curr, const char id[])
{
    if (curr == 0)
    {
        return 0;
    }
    else if (strcmp(id, curr->id) < 0)
    {
        curr->left = deleteProp(curr->left, id);
    }
    else if (strcmp(id, curr->id) > 0)
    {
        curr->right = deleteProp(curr->right, id);
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
            Property *temp = curr;
            curr = curr->right;
            free(temp);
            temp = 0;
        }
        else if (curr->right == 0)
        {
            Property *temp = curr;
            curr = curr->left;
            free(temp);
            temp = 0;
        }
        else
        {
            Property *temp = curr->left;
            while (temp->right != 0)
            {
                temp = temp->right;
            }
            strcpy(curr->id, temp->id);
            strcpy(curr->type, temp->type);
            curr->N = temp->N;
            curr->price = temp->price;
            curr->length = temp->length;
            curr->left = deleteProp(curr->left, temp->id);
        }

        int balanceFactor = getBalance(curr);
        if (balanceFactor > 1)
        {
            if (strcmp(id, curr->id) > 0)
            {
                curr->left = leftRotate(curr->left);
            }
            return rightRoate(curr);
        }
        else if (balanceFactor < -1)
        {
            if (strcmp(id, curr->id) < 0)
            {
                curr->right = rightRoate(curr->right);
            }
            return leftRotate(curr);
        }
    }
    return curr;
}
void inOrder(Property *curr)
{
    if (curr == 0)
    {
        return;
    }
    inOrder(curr->left);
    printf("| %-2s    | %d     | %d    | %-2s      | %d      |\n", curr->id, curr->N, curr->length, curr->type, curr->price);
    inOrder(curr->right);
}
void preOrder(Property *curr)
{
    if (curr == 0)
    {
        return;
    }
    printf("| %-2s    | %d     | %d    | %-2s      | %d      |\n", curr->id, curr->N, curr->length, curr->type, curr->price);
    preOrder(curr->left);
    preOrder(curr->right);
}
double calculateArea(int N, int length)
{
    double area;
    if (N == 4)
    {
        area = (double)length * (double)length;
    }
    else
    {
        area = ((double)N * (double)length * (double)length) / (4 * tan(3.14 / (double)N));
    }
    return area;
}
 
double calculatePrice(char type[], double area)
{
    double price;
    if (strcmp(type, "rural") == 0)
    {
        price = area * 2000;
    }
    else if (strcmp(type, "metro") == 0)
    {
        price = area * 5500;
    }
    else if (strcmp(type, "capital") == 0)
    {
        price = area * 10000;
    }
    return price;
}

Property *findProp(Property *curr, const char id[])
{
    if (curr == 0)
    {
        return 0;
    }
    else if (strcmp(id, curr->id) < 0)
    {
        curr->left = findProp(curr->left, id);
    }
    else if (strcmp(id, curr->id) > 0)
    {
        curr->right = findProp(curr->right, id);
    }
    else
    {
        findID = 1;
    }
}

int main()
{
    int input;
    char type[100];
    int N, length;
    char id[100];
    int idCount = 1;
    int price;
    double area;
    int printed = 0;
    char view[100];
    char del[100];
    Property *root = NULL;

    do
    {
        system("cls");
        printf("Flex Property\n");
        printf("\n");
        if (root != 0)
        {
            printf("======================================================\n");
            printf("| ID    | N     | Length    | Type      | Price      |\n");
            printf("======================================================\n");
        }
        else
        {
            printf("No property\n");
        }
        if (printed == 1)
        {
            preOrder(root);
        }
        else if (printed == 0)
        {
            inOrder(root);
        }

        printf("\n");

        printf("1. Insert Property\n");
        printf("2. Change View\n");
        printf("3. Delete Property\n");
        printf("4. Exit\n");
        printf(">> ");
        scanf("%d", &input);
        getchar();
        switch (input) 
        {
        case 1:
            system("cls");

            sprintf(id, "TX%03d", idCount);
            do
            {
                printf("Input property location type [capital | metro | rural]: ");
                scanf("%s", type);
                getchar();
            } while (strcmp(type, "rural") != 0 && strcmp(type, "capital") != 0 && strcmp(type, "metro") != 0);
            do
            {
                printf("Input number of sides [4 - 10]: ");
                scanf("%d", &N);
                getchar();
            } while (N < 4 || N > 10);
            do
            {
                printf("Input side's length [1 - 1000]: ");
                scanf("%d", &length);
                getchar();
            } while (length < 1 || length > 1000);
            area = calculateArea(N, length);
            price = (int)calculatePrice(type, area);
            root = insertProp(root, createProp(id, type, N, length, price));
            idCount++;
            printf("Succesfully insert\n");
            printf("press enter to continue...");
            getchar();
            break;
        case 2:
            do
            {
                printf("select view option [pre | in] (Case Sensitive):");
                scanf("%s", view);
                getchar();
            } while (strcmp(view, "pre") != 0 && strcmp(view, "in") != 0);
            if (strcmp(view, "pre") == 0)
            {
                printed = 1;
            }
            else
            {
                printed = 0;
            }

            break;
        case 3:
            if (root == 0)
            {
                printf("No property\n");
                printf("Press Enter to continue");
                getchar();
            }
            else
            {
                do
                {
                    printf("Input property id (Case Sensitive):");
                    scanf("%s", del);
                    getchar();
                    root = findProp(root, del);
                    printf("%d\n",findID);
                } while (findID == 0);
                findID = 0;
                root = deleteProp(root, del);
                printf("Property deleted\n");
                printf("Press Enter to contiinue");
                getchar();
            }

            break;
        }
    } while (input != 4);
}