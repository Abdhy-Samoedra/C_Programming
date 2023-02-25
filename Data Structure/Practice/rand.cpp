#include <stdio.h>
#include <stdlib.h>

struct Data
{
    int value;
    struct Data *left, *right;
} *root = 0;

struct Data *createData(int value)
{
    struct Data *temp = (struct Data *)malloc(sizeof(struct Data));
    temp->value = value;
    temp->left = temp->right = 0;
    return temp;
}

struct Data *insertData(struct Data *curr, struct Data *newValue)
{
    if (curr == 0)
    {
        return newValue;
    }
    else if (newValue->value < curr->value)
    {
        curr->left = insertData(curr->left, newValue);
    }
    else if (newValue->value > curr->value)
    {
        curr->right = insertData(curr->right, newValue);
    }
    return curr;
}

void viewInfix(struct Data *curr)
{

    if (curr != 0)
    {
        viewInfix(curr->left);
        printf("%d ", curr->value);
        viewInfix(curr->right);
    }
}

struct Data *deleteData(struct Data *curr, int value)
{
    if (curr == 0)
    {
        printf("tidak ada \n");
        return 0;
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
        if (curr->left == 0 && curr->right == 0)
        {
            free(curr);
            curr = 0;
        }
        else if (curr->left == 0)
        {
            struct Data *temp = curr;
            curr = curr->right;
            free(temp);
            temp = 0;
        }
        else if (curr->right == 0)
        {
            struct Data *temp = curr;
            curr = curr->left;
            free(temp);
            temp = 0;
        }
        else
        {
            struct Data *temp = curr->left;
            while (temp->right != 0)
            {
                temp = temp->right;
            }
            curr->value = temp->value;
            curr->left = deleteData(curr->left, temp->value);
        }
    }
    return curr;
}

int main()
{
    root = insertData(root, createData(12));
    root = insertData(root, createData(29));
    root = insertData(root, createData(66));
    root = insertData(root, createData(30));
    root = insertData(root, createData(21));
    root = insertData(root, createData(30));
    root = insertData(root, createData(9));
    root = insertData(root, createData(33));
    viewInfix(root);

    root = deleteData("")
}