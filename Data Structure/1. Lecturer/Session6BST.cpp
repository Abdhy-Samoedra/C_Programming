#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data
{
    int val;

    struct data *left;
    struct data *right;
} *root = 0;

struct data *createData(int val)
{
    struct data *temp = (struct data *)malloc(sizeof(struct data));
    temp->val = val;
    temp->left = temp->right = 0;
    return temp;
}

void insert(struct data *curr, int newVal)
{
    if (root == 0)
    {
        root = createData(newVal);
    }
    else
    {
        if (newVal < curr->val && curr->left == 0)
        {
            curr->left = createData(newVal);
        }
        else if (newVal > curr->val && curr->right == 0)
        {
            curr->right = createData(newVal);
        }
        else if (newVal < curr->val)
        {
            insert(curr->left, newVal);
        }
        else if (newVal > curr->val)
        {
            insert(curr->right, newVal);
        }
    }
}

void displayInfix(struct data *curr)
{
    if (curr != 0)
    {
        displayInfix(curr->left);
        printf("%d ", curr->val);
        displayInfix(curr->right);
    }
}

void find(struct data *curr, int val)
{
    if (curr == 0)
    {
        printf("%d is NOT found in BST\n", val);
        return;
    }
    if (curr->val == val)
    {
        printf("%d is found in BST\n", val);
        return;
    }
    // if val is smaller than current node's val
    // search recursively to left
    if (val < curr->val)
    {
        find(curr->left, val);
    }
    // if val is bigger than current node's val
    // search recursively to right
    else if (val > curr->val)
    {
        find(curr->right, val);
    }
}


struct data *delRecursive(struct data *parentNodeToDel, struct data *nodeToDel)
{
    // if noteToDel is LEAF
    if (nodeToDel->left == 0 && nodeToDel->right == 0)
    {
        // if there is only 1 node in BST
        if (root == nodeToDel)
        {
            root = 0;
        }
        if (nodeToDel->val < parentNodeToDel->val)
        {
            parentNodeToDel->left = 0;
        }
        else
        {
            parentNodeToDel->right = 0;
        }
        free(nodeToDel);
        return 0;
    }
    // if curr has ONLY LEFT child
    else if (nodeToDel->left != 0 && nodeToDel->right == 0)
    {
        struct data *temp = nodeToDel->left;
        if (nodeToDel->val < parentNodeToDel->val)
        {
            parentNodeToDel->left = temp;
        }
        else
        {
            parentNodeToDel->right = temp;
        }
        return temp;
    }
    // if curr has ONLY RIGHT child
    else if (nodeToDel->left == 0 && nodeToDel->right != 0)
    {
        struct data *temp = nodeToDel->right;
        if (nodeToDel->val < parentNodeToDel->val)
        {
            parentNodeToDel->left = temp;
        }
        else
        {
            parentNodeToDel->right = temp;
        }
        return temp;
    }
    // if curr has TWO children
    else
    {
        // find succesor (rightmost child of left subtree)
        struct data *t = nodeToDel->left;
        struct data *tp = nodeToDel;
        while (t->right)
        {
            tp = t;
            t = t->right;
        }
        // copy value from t (successor) to node to be deleted
        nodeToDel->val = t->val;
        // delete successor node
        // t = delRecursive(tp, t);
        // tp->right = t;

        if (tp->left == t)
        {
            tp->left = t->left;
        }
        else
        {
            tp->right = t->left;
        }

        return nodeToDel;
    }
}

struct data *parent = 0;
void del(struct data *curr, int delVal)
{
    // if we found 0 sport / delVal is notin BST
    if (curr == 0)
    {
        printf("%d is not available in BST\n", delVal);
        return;
    }

    // if we found delVal in BST
    if (curr->val == delVal)
    {
        // do deletion
        curr = delRecursive(parent, curr);
        return;
    }

    // if delVal is smaller than curr->val, recursive to left
    if (delVal < curr->val)
    {
        parent = curr;
        del(curr->left, delVal);
    }

    // if delVal is bigger than curr->val, recursice to right
    else if (delVal > curr->val)
    {
        parent = curr;
        del(curr->right, delVal);
    }
}

int main()
{
    insert(root, 10);
    insert(root, 20);
    insert(root, 9);
    insert(root, 11);
    insert(root, 1);
    insert(root, 12);
    insert(root, 25);
    insert(root, 30);
    insert(root, 35);
    insert(root, 40);

    del(root, 10);
    del(root, 20);
    del(root, 9);
    del(root, 11);
    del(root, 1);
    del(root, 12);
    del(root, 25);

    displayInfix(root);
    // printf("\n");
    // del(root, 20);
    // displayInfix(root);
    // printf("\n");
    // del(root, 10);
    // displayInfix(root);
    // printf("\n");
    // del(root, 40);
    // displayInfix(root);
    // printf("\n");
    // del(root, 111);
    // displayInfix(root);
    // printf("\n");
    // find(root, 5);
    // del(root, 1112);
    // find(root, 9);
    return 0;
}