#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Food
{
    int id;
    char name[20];
    int price;
    int height;
    Food *left, *right;
};

int max(int a, int b)
{
    return (a > b) ? a : b;
}
int getHeight(struct Food *curr)
{
    if (curr == 0)
    {
        return 0;
    }
    return curr->height;
}
int calculateHeight(struct Food *curr)
{
    return max(getHeight(curr->left), getHeight(curr->right)) + 1;
}
int getBalanceFactor(struct Food *curr)
{
    if (curr == 0)
    {
        return 0;
    }
    return getHeight(curr->left) - getHeight(curr->right);
}
struct Food *rightRotate(struct Food *curr)
{
    struct Food *cL = curr->left;
    struct Food *cR = curr->right;

    cL->right = curr;
    curr->left = cR;

    curr->height = calculateHeight(curr);
    cL->height = calculateHeight(cL);

    return cL;
}
struct Food *leftRotate(struct Food *curr)
{
    Food *cR = curr->right;
    Food *cL = curr->left;

    cR->left = curr;
    curr->right = cR;

    curr->height = calculateHeight(curr);
    cR->height = calculateHeight(cR);

    return cR;
}

struct Food *createFood(int id, char name[], int price)
{
    struct Food *newFood = (struct Food *)malloc(sizeof(struct Food));
    newFood->id = id;
    strcpy(newFood->name, name);
    newFood->price = price;
    newFood->height = 1;
    newFood->left = newFood->right = 0;
    return newFood;
}

struct Food *insertFood(struct Food *curr, struct Food *food)
{
    if (curr == 0)
    {
        return food;
    }
    else if (food->id < curr->id)
    {
        curr->left = insertFood(curr->left, food);
    }
    else if (food->id > curr->id)
    {
        curr->right = insertFood(curr->right, food);
    }
    return curr;
}

struct Food *deleteFood(struct Food *curr, int id)
{
    if (curr == 0)
    {
        return curr;
    }
    else if (id < curr->id)
    {
        curr->left = deleteFood(curr->left, id);
    }
    else if (id > curr->id)
    {
        curr->right = deleteFood(curr->right, id);
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
            Food *temp = curr;
            temp = curr->left;
            free(temp);
            temp = 0;
        }
        else if (curr->left == 0)
        {
            Food *temp = curr;
            temp = curr->right;
            free(temp);
            temp = 0;
        }
        else
        {
            Food *temp = curr->left;
            while (temp->right != 0)
            {
                temp = temp->right;
            }
            curr->id = temp->id;
            strcpy(curr->name, temp->name);
            curr->price = temp->price;
            curr->left = deleteFood(curr->left, temp->id);
        }
    }
    return curr;
}

void displayInorder(struct Food *curr)
{
    if (curr == 0)
    {
        return;
    }
    displayInorder(curr->left);
    printf("%-3d %-50s %-6d (%d)\n", curr->id, curr->name, curr->price, curr->height);
    displayInorder(curr->right);
}

int main()
{
    Food *root = NULL;

    root = insertFood(root, createFood(10, "Bakso", 20000));
    root = insertFood(root, createFood(5, "Mie Ayam", 15000));
    root = insertFood(root, createFood(3, "Salad", 10000));
    root = insertFood(root, createFood(20, "Kari", 15000));
    root = insertFood(root, createFood(30, "Nasi Uduk", 25000));
    displayInorder(root);
}
