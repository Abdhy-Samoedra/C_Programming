#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Data
{
    char name[20];
    struct Data *next, *prev;
};

struct Data *createNewData(char name[])
{
    struct Data *newData = (struct Data *)malloc(sizeof(struct Data));
    strcpy(newData->name, name);
    newData->next = newData->prev = 0;

    return newData;
}

void pushHead(Data **head, Data **tail, Data *newData)
{
    if (*head == 0)
    {
        *head = *tail = newData;
    }
    else
    {
        (*head)->prev = newData;
        newData->next = *head;
        *head = newData;
    }
}

void pushTail(Data **head, Data **tail, Data *newData)
{
    if (*tail == 0)
    {
        *head = *tail = newData;
    }
    else
    {
        (*tail)->next = newData;
        newData->prev = *tail;
        *tail = newData;
    }
}

void pushValue(Data **head, Data **tail, Data *newData)
{
    if (*head == 0 || strcmp(newData->name, (*head)->name) < 0)
    {
        pushHead(head, tail, newData);
    }
    else if (*tail == 0 || strcmp(newData->name, (*tail)->name) >= 0)
    {
        pushTail(head, tail, newData);
    }
    else
    {
        struct Data *curr = *head;
        while (curr->next != 0 && strcmp(newData->name, curr->next->name) >= 0)
        {
            curr = curr->next;
        }
        newData->next = curr->next;
        curr->next->prev = newData;
        newData->prev = curr;
        curr->next = newData;
    }
}

void popHead(Data **head, Data **tail)
{
    if (*head == 0)
    {
        printf("ga ada data");
    }
    else if (*head == *tail)
    {
        free(*head);
        *head = *tail = 0;
    }
    else
    {
        *head = (*head)->next;
        free((*head)->prev);
        (*head)->prev = 0;
    }
}

void popTail(Data **head, Data **tail)
{
    if (*tail == 0)
    {
        printf("ga ada data");
    }
    else if (*head == *tail)
    {
        free(*head);
        *head = *tail = 0;
    }
    else
    {
        *tail = (*tail)->prev;
        free((*tail)->next);
        (*tail)->next = 0;
    }
}

void popValue(Data **head, Data **tail, char name[])
{
    if (*head == 0)
    {
        printf("tidak ada data");
    }
    else if (strcmp(name, (*head)->name) == 0)
    {
        popHead(head, tail);
    }
    else if (strcmp(name, (*tail)->name) == 0)
    {
        popTail(head, tail);
    }
    else
    {
        struct Data *curr = *head;
        while (curr->next != 0 && strcmp(name, curr->name) != 0)
        {
            curr = curr->next;
        }
        if (curr->next == 0 || strcmp(name, curr->name) != 0)
        {
            printf("data tidak ketemu");
        }
        curr->next->prev = curr->prev;
        curr->prev->next = curr->next;
        free(curr);
        curr = 0;
    }
}

void popAll(Data **head, Data **tail)
{
    while (*head != 0)
    {
        popHead(head, tail);
    }
    printf("berhasil terhaspu semua\n");
}

void display(Data *head)
{
    struct Data *curr = head;
    while (curr != 0)
    {
        printf("%s\n", curr->name);
        curr = curr->next;
    }
}

int main()
{
    struct Data *head = 0, *tail = 0;

    // pushHead(&head, &tail, createNewData("agus"));
    // pushHead(&head, &tail, createNewData("budi"));
    // pushTail(&head, &tail, createNewData("agung"));
    // pushTail(&head, &tail, createNewData("samu"));

    pushValue(&head, &tail, createNewData("agus"));
    pushValue(&head, &tail, createNewData("budi"));
    pushValue(&head, &tail, createNewData("agung"));
    pushValue(&head, &tail, createNewData("samu"));
    pushValue(&head, &tail, createNewData("rusi"));
    pushValue(&head, &tail, createNewData("sandrra"));
    display(head);
    printf("\n");

    // popHead(&head, &tail);
    // display(head);
    // printf("\n");

    // popTail(&head, &tail);
    // display(head);
    // printf("\n");

    popAll(&head, &tail);

    popValue(&head, &tail, "sandrra");
    display(head);
    printf("\n");
}