#include <stdio.h>
#include <stdlib.h>

// curr/current selalu dari head

struct node
{
    int val;

    struct node *next;
} *head = NULL, *tail = NULL;

struct node *newNode(int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->val = val;
    temp->next = NULL;

    return temp;
}

void insertTail(int val)
{
    struct node *temp = newNode(val);

    // jika merupakan data pertama
    if (tail == NULL)
    {
        head = tail = temp;
    }
    // jika data merupakan data kedua atau selebihnya
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

void displayAll()
{
    struct node *curr = head;
    while (curr != NULL)
    {
        printf("%d ", curr->val);
        curr = curr->next;
    }
}

void insertMiddleAscending(int val)
{
    struct node *curr = head;
    struct node *temp = newNode(val);

    while (curr->next->val < val)
    {
        curr = curr->next;
    }
    temp->next = curr->next;
    curr->next = temp;
}

void insertMiddleDescending(int val)
{
    struct node *curr = head;
    struct node *temp = newNode(val);

    while (curr->next->val > val)
    {
        curr = curr->next;
    }
    temp->next = curr->next;
    curr->next = temp;
}

void insertHead(int val)
{
    struct node *temp = newNode(val);

    // jika merupakan data pertama
    if (tail == NULL)
    {
        head = tail = temp;
    }
    // jika data merupakan data kedua atau selebihnya
    else
    {
        temp->next = head;
        head = temp;
    }
}

void insertDataAscending(int val)
{
    // jika data dalam LL kosong
    if (head == NULL)
    {
        // bisa pilih salah satu karena jika kosong head dan tail sama
        insertHead(val);
        // insertTail(val);
    }
    // jika value baru lebih kecil daripada head value
    else if (val < head->val)
    {
        insertHead(val);
    }
    // jika value baru lebih besar daripada tail value
    else if (val > tail->val)
    {
        insertTail(val);
    }
    // jika valur baru berada pada tengah tengah head dan tail
    else
    {
        insertMiddleAscending(val);
    }
}

int main()
{
    // insertTail(20);
    // insertTail(30);
    // insertTail(40);
    // insertTail(50);

    // insertMiddleAscending(26);
    // insertMiddleAscending(34);

    // insertMiddleDescending(25);
    // insertMiddleDescending(35);
    // insertMiddleDescending(21);

    insertDataAscending(40);
    insertDataAscending(10);
    insertDataAscending(29);
    insertDataAscending(50);
    insertDataAscending(1);
    insertDataAscending(24);

    displayAll();
}
