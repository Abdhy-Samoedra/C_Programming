#include <stdio.h>
#include <stdlib.h>

//Single Linked List

// head akan selalu terdapat pada data yang terakhir kita insert

struct node
{
    int val;
    struct node *next;
} *head = NULL;

struct node *newNode(int val)
{
    // mallocnya harus dicasting dulu
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    temp->val = val;
    temp->next = NULL;

    return temp;
}

void insertNode(int val)
{
    struct node *temp = newNode(val);
    // seiap kali insert harus melakukan validasi. apakah kita memasukkan data yang pertama atau data yang kedua lebih
    // insert data pertama
    if (head == NULL)
    {
        head = temp;
    }
    // insert data kedua atau lebih
    else
    {
        temp->next = head;
        head = temp;
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

    // jika yang mau didelet ada di head
    if (head->val == val)
    {
        head = curr->next;
        free(curr);
    }

    // jika yang mau dihapus ada di node kedua atau lebih
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
            free(del);
        }
    }
}



int main()
{
    insertNode(15);
    insertNode(20);
    insertNode(25);
    insertNode(5);

    deleteNode(5);
    deleteNode(15);
    deleteNode(35);

    dsiplayAll();
}