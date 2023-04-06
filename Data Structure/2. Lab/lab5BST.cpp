#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Data
{
    int val;
    struct Data *left, *right;
} *root = 0;

Data *createData(int val)
{
    struct Data *data = (struct Data *)malloc(sizeof(struct Data));
    data->val = val;
    data->left = data->right = 0;
    return data;
}

Data *insertData(Data *curr, Data *data)
{
    if (curr == 0)
    {
        return data;
    }
    else if (data->val < curr->val)
    {
        curr->left = insertData(curr->left, data);
    }
    else if (data->val > curr->val)
    {
        curr->right = insertData(curr->right, data);
    }
    return curr;
}

Data *deleteData(Data *curr, int val)
{
    if (curr == 0)
    {
        return curr;
    }
    else if (val < curr->val)
    {
        curr->left = deleteData(curr->left, val);
    }
    else if (val > curr->val)
    {
        curr->right = deleteData(curr->right, val);
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
            Data *temp = curr;
            curr = curr->right;
            free(temp);
            temp = NULL;
        }
        else if (curr->right == 0)
        {
            Data *temp = curr;
            curr = curr->left;
            free(temp);
            temp = 0;
        }
        else
        {
            Data *temp = curr->right;
            while (temp->left != 0)
            {
                temp = temp->left;
            }
            curr->val = temp->val;
            curr->right = deleteData(curr->right, temp->val);
        }
    }
    return curr;
}

Data *searchData(Data *curr, int val)
{
    if (curr == 0)
    {
        return curr;
    }
    else if (val == curr->val)
    {
        return curr;
    }
    else if (val < curr->val)
    {
        return searchData(curr->left, val);
    }
    else
    {
        return searchData(curr->right, val);
    }
}

Data *deleteAll(Data *curr)
{
    while (curr != 0)
    {
        curr = deleteData(curr, curr->val);
    }
    printf("delete all success\n");
    return curr;
}

void displayInfix(Data *curr)
{
    if (curr != 0)
    {
        displayInfix(curr->left);
        printf("%d ", curr->val);
        displayInfix(curr->right);
    }
}

void displayPostfix(Data *curr)
{
    if (curr != 0)
    {
        displayPostfix(curr->left);
        displayPostfix(curr->right);
        printf("%d ", curr->val);
    }
}
void displayPrefix(Data *curr)
{
    if (curr != 0)
    {
        printf("%d ", curr->val);
        displayPrefix(curr->left);
        displayPrefix(curr->right);
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

    printf("infix : ");
    displayInfix(root);
    printf("\n");
    printf("prefix : ");
    displayPrefix(root);
    printf("\n");
    printf("postfix : ");
    displayPostfix(root);
    printf("\n");

    // root = deleteData(root, (20));
    // root = deleteData(root, (10));
    // root = deleteData(root, (5));
    // root = deleteData(root, (15));
    // root = deleteData(root, (14));
    // root = deleteData(root, (16));
    // root = deleteData(root, (30));
    // root = deleteData(root, (40));

    root = deleteAll(root);

    printf("infix : ");
    displayInfix(root);
    printf("\n");
    printf("prefix : ");
    displayPrefix(root);
    printf("\n");
    printf("postfix : ");
    displayPostfix(root);
}