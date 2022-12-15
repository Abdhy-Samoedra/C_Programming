#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *prev;
    struct node *next;
} *head = NULL, *tail = NULL;

struct node *newNode(int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->val = val;

    temp->next = temp->prev = NULL;
    return temp;
}

void insertTail(int val)
{
    struct node *temp = newNode(val);

    // jika data merupakan data pertama
    if (head == NULL)
    {
        head = tail = temp;
    }
    // jika data merupakan data kedua ata lebih
    else
    {
        tail->next = temp;
        temp->prev = tail;

        // menggeser
        tail = temp;
    }
}

void dsiplayAll()
{
    // membuat pointer untuk menunjuk data pertama
    struct node *curr = head;

    while (curr != NULL)
    {
        printf("%d\n", curr->val);

        // menggeser currentnya agar tidak berhenti di head
        curr = curr->next;
    }
}

void deleteNode(int val)
{
    struct node *curr = head;

    // jika menghapus satu satunya node yang ada dalam linked list
    if (head->val == val && head == tail)
    {
        free(head);
        head = tail = NULL;
    }
    // jika memhghapus head node
    else if (head->val == val)
    {
        head = head->next;
        free(head->prev);
        head->prev = NULL;
    }
    // jika menghapus tail node
    else if (tail->val == val)
    {
        tail = tail->prev;
        free(tail->next);
        tail->next = NULL;
    }
    // jika menghaus node yang bukan head atau tail
    else
    {
        while (curr->next != NULL && curr->next->val != val)
        {
            curr = curr->next;
        }

        if (curr->next != NULL)
        {
            struct node *del = curr->next;
            curr->next = del->next;
            del->next->prev = curr;
            free(del);
        }
    }
}
int main()
{
    insertTail(40);
    insertTail(50);
    insertTail(60);
    insertTail(70);

    deleteNode(40);
    // deleteNode(70);
    // deleteNode(60);
    deleteNode(5);

    dsiplayAll();
}