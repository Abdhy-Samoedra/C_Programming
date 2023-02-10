#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node *left, *right;
} *root = 0;

Node *createNode(int val)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->val = val;
    temp->left = temp->right = 0;
    return temp;
}

Node *insertNode(Node *curr, Node *node)
{
    if (curr == 0)
    {
        return node;
    }
    else if (node->val < curr->val)
    {
        curr->left = insertNode(curr->left, node);
    }
    else if (node->val > curr->val)
    {
        curr->right = insertNode(curr->right, node);
    }
    return curr;
}

Node *deleteData(Node *curr, int val)
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
            struct Node *temp = curr;
            curr = curr->right;
            free(temp);
            temp = 0;
        }
        else if (curr->right == 0)
        {
            struct Node *temp = curr;
            curr = curr->left;
            free(temp);
            temp = 0;
        }
        else
        {
            struct Node *temp = curr->left;
            while (temp->right != 0)
            {
                temp = temp->right;
            }
            curr->val = temp->val;
            curr->right = deleteData(curr->right, val);
        }
    }
}

void displayInfix(Node *curr)
{
    if (curr != 0)
    {
        displayInfix(curr->left);
        printf("%d ", curr->val);
        displayInfix(curr->right);
    }
}

int main()
{
    root = insertNode(root, createNode(20));
    root = insertNode(root, createNode(10));
    root = insertNode(root, createNode(5));
    root = insertNode(root, createNode(15));
    root = insertNode(root, createNode(14));
    root = insertNode(root, createNode(16));
    root = insertNode(root, createNode(30));
    root = insertNode(root, createNode(40));
    displayInfix(root);
    // root = deleteData(root, 20);
}