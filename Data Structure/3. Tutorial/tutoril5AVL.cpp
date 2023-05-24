#include <stdio.h>
#include <stdlib.h>

struct Data
{
    int value;
    int height;
    struct Data *left, *right;
} *root;

Data *createData(int value)
{
    struct Data *temp = (struct Data *)malloc(sizeof(struct Data));
    temp->value = value;
    temp->height = 1;
    temp->left = temp->right = 0;
    return temp;
}

int max(int a, int b)
{
    return a > b ? a : b;
}
int getHeight(struct Data *curr)
{
    if (curr == 0)
    {
        return 0;
    }
    return curr->height;
}
int getBalFac(struct Data *curr)
{
    if (curr == 0)
    {
        return 0;
    }
    return getHeight(curr->left)-getHeight(curr->right);
    
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
void displayPrefix(Data *curr)
{
    if (curr != 0)
    {
        printf("%d ", curr->value);
        displayPrefix(curr->left);
        displayPrefix(curr->right);
    }
}

int main()
{
}