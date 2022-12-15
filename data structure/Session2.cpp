#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
} *head = NULL;

void insertNode(int val)
{
    // mallocnya harus dicasting dulu
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    temp->val = val;
    temp->next = NULL;

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

int main()
{
    insertNode(12);
    insertNode(2);
    insertNode(5);
    insertNode(1);
}