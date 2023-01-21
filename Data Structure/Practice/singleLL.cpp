#include <stdio.h>
#include <stdlib.h>

struct data
{
    int price;
    struct data *next;
} *head = 0, *tail = 0;

// create data
struct data *createData(int price)
{
    struct data *Data = (struct data *)malloc(sizeof(data *));
    Data->price = price;
    Data->next = 0;

    return Data;
}   

void pushHead(int price)
{
    struct data *newHead = createData(price);
    if (head == 0)
    {
        head = tail = newHead;
    }
    else
    {
        newHead->next = head; // ini karena single linked list push head menganut prinsip stacked, first in langsung diatas
        head = newHead;
    }
}

void pushTail(int price)
{
    struct data *newTail = createData(price);

    if (tail == 0)
    {
        tail = head = newTail;
    }
    else
    {
        tail->next = newTail;
        tail = newTail;
    }
}

void pushMid(int price)
{
    if (head == 0 || price < head->price)
    {
        pushHead(price);
    }
    else if (price >= tail->price)
    {
        pushTail(price);
    }
    else
    {
        struct data *newMid = createData(price);
        struct data *curr = head;
        while (curr->next != 0 && curr->next->price < price)
        {
            curr = curr->next;
        }
        newMid->next = curr->next;
        curr->next = newMid;
    }
}

void displayAll()
{
    struct data *curr = head;

    while (curr != 0)
    {
        printf("%d ", curr->price);
        curr = curr->next;
        printf("\n");
    }
    
}

void popHead()
{
    if (head == 0)
    {
        printf("ga ada data");
    }
    else if (head == tail)
    {
        free(head);
        head = tail = 0;
    }
    else
    {
        struct data *temp = head->next;
        free(head);
        head = temp;
    }
}

void popTail()
{
    if (tail == 0)
    {
        printf("ga ada data");
    }
    else if (head == tail)
    {
        free(head);
        head = tail = 0;
    }
    else
    {
        struct data *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        free(tail);
        temp->next = 0;
        tail = temp;
    }
}

void popMid(int price)
{
    if (head == 0)
    {
        printf("ga ada data");
    }
    else if (price == head->price)
    {
        popHead();
    }
    else if (price == tail->price)
    {
        popTail();
    }
    else
    {
        struct data *curr = head;

        while (curr->next != 0 && curr->next->price != price)
        {
            curr = curr->next;
        }

        if (curr->next == 0 || curr->next->price != price)
        {
            printf("data tidak ketemu\n");
        }
        else
        {
            struct data *temp = curr->next->next;
            free(curr->next);
            curr->next = temp;
        }
    }
}

int main()
{
    // NOTE PUSH TAIL PUSH HEAD TIDAK BISA DICAMPUR DENGAN PUSHMID/PUSHVALUE
    pushTail(4);
    pushHead(77);
    // pushTail(5);
    pushTail(9);
    // pushTail(2);
    pushHead(7);
    
    // pushMid(6);
    // pushMid(8);

    popMid(4);
    popHead();
    popTail();
    // popMid(11);
    // popHead();
    
    popMid(77);
    popMid(11);
    displayAll();
}