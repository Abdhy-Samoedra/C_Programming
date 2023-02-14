#include <stdio.h>
#include <stdlib.h>

struct Data
{
    int value;
    struct Data *left, *right;
} *root;

Data *createData(int value)
{
    struct Data *newData = (struct Data *)malloc(sizeof(struct Data));
    newData->value = value;
    newData->left = newData->right = 0;
    return newData;
}

Data *insertData(Data *curr, Data *data)
{
    if (curr == 0)
    {
        return data;
    }
    else if (data->value < curr->value)
    {
        curr->left = insertData(curr->left, data);
    }
    else if (data->value > curr->value)
    {
        curr->right = insertData(curr->right, data);
    }

    return curr;
}

Data *deleteData(Data *curr, int value)
{
    if (curr == 0)
    {
        return curr;
    }
    else if (value < curr->value)
    {
        curr->left = deleteData(curr->left, value);
    }
    else if (value > curr->value)
    {
        curr->right = deleteData(curr->right, value);
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
            Data *temp = curr;
            curr = curr->left;
            free(temp);
            temp = 0;
        }
        else if (curr->left == 0)
        {
            Data *temp = curr;
            curr = curr->right;
            free(temp);
            temp = 0;
        }
        else
        {
            // most left right child
            Data *temp = curr->right;
            while (temp->left != 0)
            {
                temp = temp->left;
            }
            curr->value = temp->value;
            curr->right = deleteData(curr->right, temp->value);
        }
    }
    return curr;
}

Data *searchData(Data *curr, int value)
{
    if (curr == 0)
    {
        return curr;
    }else if (value == curr->value)
    {
        return curr;
    }else if (value < curr->value)
    {
        searchData(curr->left,value);
    }else
    {
        searchData(curr->right,value);
    }
    
    
    
    
}

Data* deleteAll(Data *curr)
{
    while (curr != 0)
    {
        curr = deleteData(curr,curr->value);
    }
    printf("delete all success\n");
    return curr;
    
}

void displayInfix(Data *curr)
{
    if (curr != 0)
    {
        displayInfix(curr->left);
        printf("%d ", curr->value);
        displayInfix(curr->right);
    }
}

void displayPrefix(Data *curr)
{
    if (curr != 0)
    {
        printf("%d ", curr->value);
        displayPrefix(curr->left);
        displayPrefix(curr->right);
    }
}

void displayPostfix(Data *curr)
{
    if (curr != 0)
    {
        displayPostfix(curr->left);
        displayPostfix(curr->right);
        printf("%d ", curr->value);
    }
}

int main()
{
    root = insertData(root, createData(20));
    root = insertData(root, createData(10));
    root = insertData(root, createData(5));
    root = insertData(root, createData(15));
    root = insertData(root, createData(14));
    root = insertData(root, createData(16));
    root = insertData(root, createData(30));
    root = insertData(root, createData(40));

    printf("Infix : ");
    displayInfix(root);
    printf("\n");

    printf("postfix : ");
    displayPostfix(root);
    printf("\n");

    printf("prefix : ");
    displayPrefix(root);
    printf("\n");

    // root = deleteAll(root);
    root = deleteData(root, 14);
    root = deleteData(root, 20);
    root = deleteData(root, 16);

    printf("Infix : ");
    displayInfix(root);
    printf("\n");

    printf("postfix : ");
    displayPostfix(root);
    printf("\n");

    printf("prefix : ");
    displayPrefix(root);
    printf("\n");

    root = insertData(root, createData(33));
    root = insertData(root, createData(12));
    root = insertData(root, createData(3));

    printf("Infix : ");
    displayInfix(root);
    printf("\n");

    printf("postfix : ");
    displayPostfix(root);
    printf("\n");

    printf("prefix : ");
    displayPrefix(root);
    printf("\n");
}