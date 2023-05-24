#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Food
{
    char name[100];
    int price;
    int height;
    Food *left, *right;
};

Food *createFood(const char name[], int price)
{
    struct Food *newFood = (struct Food *)malloc(sizeof(struct Food));
    strcpy(newFood->name, name);
    newFood->price = price;
    newFood->height = 1;
    newFood->left = newFood->right = 0;
    return newFood;
}

int getMax(int a, int b)
{
    return (a >= b) ? a : b;
}

int calculateHeight(Food *node)
{
    return (node == 0) ? 0 : 1 + getMax(calculateHeight(node->left), calculateHeight(node->right));
}

int getBalance(Food *node)
{
    return (node == 0) ? 0 : calculateHeight(node->left) - calculateHeight(node->right);
}

Food *rightRotate(Food *node)
{
    Food *newParent = node->left;
    node->left = newParent->right;
    newParent->right = node;

    node->height = calculateHeight(node);
    newParent->height = calculateHeight(newParent);

    return newParent;
}

Food *leftRotate(Food *node)
{
    Food *newParent = node->right;
    node->right = newParent->left;
    newParent->left = node;

    node->height = calculateHeight(node);
    newParent->height = calculateHeight(newParent);

    return newParent;
}

Food *insertFood(Food *curr, const char name[], int price)
{
    if (curr == 0)
    {
        return createFood(name, price);
    }
    else if (price < curr->price)
    {
        curr->left = insertFood(curr->left, name, price);
    }
    else if (price > curr->price)
    {
        curr->right = insertFood(curr->right, name, price);
    }

    curr->height = calculateHeight(curr);

    int balanceFactor = getBalance(curr);
    if (balanceFactor > 1)
    {
        if (price > curr->price)
        {
            curr->left = leftRotate(curr->left);
        }
        return rightRotate(curr);
    }
    else if (balanceFactor < -1)
    {
        if (price < curr->price)
        {
            curr->right = rightRotate(curr->right);
        }
        return leftRotate(curr);
    }
    return curr;
}

Food *deleteFood(Food *curr, int price)
{
    if (curr == 0)
    {
        return curr;
    }
    else if (price < curr->price)
    {
        curr->left = deleteFood(curr->left, price);
    }
    else if (price > curr->price)
    {
        curr->right = deleteFood(curr->right, price);
    }
    else
    {
        if (curr->right == 0 && curr->left == 0)
        {
            free(curr);
            curr = 0;
        }
        else if (curr->left == 0)
        {
            Food *temp = curr;
            curr = curr->right;
            free(temp);
            temp = 0;
        }
        else if (curr->right == 0)
        {
            Food *temp = curr;
            curr = curr->left;
            free(temp);
            temp = 0;
        }
        else
        {
            //most right left child , anak kiri paling kanan
            Food *temp = curr->left;
            while (temp->right != 0)
            {
                temp = temp->right;
            }
            strcpy(curr->name, temp->name);
            curr->price = temp->price;
            curr->left = deleteFood(curr->left, temp->price);
        }
    }

    int balanceFactor = getBalance(curr);
    if (balanceFactor > 1)
    {
        if (price > curr->price)
        {
            curr->left = leftRotate(curr->left);
        }
        return rightRotate(curr);
    }
    else if (balanceFactor < -1)
    {
        if (price < curr->price)
        {
            curr->right = rightRotate(curr->right);
        }
        return leftRotate(curr);
    }
    return curr;
}

Food *updateFood(Food *curr, const char name[], int price)
{
    if (curr == 0)
    {
        printf("data not found\n");
        return curr;
    }
    else if (price < curr->price)
    {
        curr->left = updateFood(curr->left, name, price);
    }
    else if (price > curr->price)
    {
        curr->right = updateFood(curr->right, name, price);
    }
    else
    {
        strcpy(curr->name, name);
        printf("upaated\n");
    }
    return curr;
}

void printInOrder(Food *curr)
{
    if (curr == 0)
    {
        return;
    }
    printInOrder(curr->left);
    printf("%s - %d - (%d)\n", curr->name, curr->price,curr->height);
    printInOrder(curr->right);
}

int main()
{
    // Food *root = insertFood(NULL, "Sate Padang", 53000);
    // root = insertFood(root, "Sate Kambing", 84000);
    // root = insertFood(root, "Sate Ayam", 32000);
    // root = insertFood(root, "Sate Kelinci", 92000);
    // root = insertFood(root, "Sate Taichan", 100000);

    // root = deleteFood(root, 24000);
    // root = deleteFood(root, 22000);

    // tampilin data
    // printInOrder(root);

    // root = updateFood(root, "Sate Taichan Pedas", 24000);
    // printf("\nAfter Update\n");
    // printInOrder(root);

    
    
    
    // printf("\n");
    // root = updateFood(root, "Sate Taichan Pedas Banget", 40000);
    // printInOrder(root);

    return 0;
}