#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Data
{
    char name[200];
    struct Data *left, *right;
} *root;

struct Data *createData(char name[])
{
    struct Data *temp = (struct Data *)malloc(sizeof(struct Data));
    strcpy(temp->name, name);
    temp->left = temp->right = 0;
    return temp;
}

struct Data *insertData(struct Data *curr, struct Data *newData)
{
    if (curr == 0)
    {
        return newData;
    }
    else if (strcmpi(newData->name, curr->name) < 0)
    {
        curr->left = insertData(curr->left, newData);
    }
    else if (strcmpi(newData->name, curr->name) > 0)
    {
        curr->right = insertData(curr->right, newData);
    }
    return curr;
}

struct Data *deleteData(struct Data *curr, char nameDel[])
{
    if (curr == 0)
    {
        return curr;
    }
    else if (strcmpi(nameDel, curr->name) < 0)
    {
        curr->left = deleteData(curr->left, nameDel);
    }
    else if (strcmpi(nameDel, curr->name) > 0)
    {
        curr->right = deleteData(curr->right, nameDel);
    }
    else
    {
        if (curr->left == 0 && curr->right == 0)
        {
            free(curr);
            curr == 0;
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
            // predecessor
            struct Data *temp = curr->left;
            while (temp->right != 0)
            {
                temp = temp->right;
            }

            strcpy(curr->name, temp->name);
            curr->left = deleteData(curr->left, temp->name);
        }
    }
    return curr;
}
void viewInfix(struct Data *curr)
{
    if (curr != 0)
    {
        viewInfix(curr->left);
        printf("%s ", curr->name);
        viewInfix(curr->right);
    }
}

int main()
{
    root = insertData(root, createData("samoedra"));
    root = insertData(root, createData("rudi"));
    root = insertData(root, createData("agil"));
    root = insertData(root, createData("mika"));
    root = insertData(root, createData("angga"));
    viewInfix(root);
    printf("\n");
    root = deleteData(root, "Agil");
    root = deleteData(root, "mika");
    viewInfix(root);
}