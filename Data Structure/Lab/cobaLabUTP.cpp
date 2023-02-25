#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int SIZE = 26;
struct Data
{
    char name[100];
    int age;
    struct Data *next, *prev;
};
struct Table
{
    struct Data *head, *tail;
} *table[SIZE];

void initializeTable()
{
    for (int i = 0; i < SIZE; i++)
    {
        table[i] = (struct Table *)malloc(sizeof(struct Table));
        table[i]->head = table[i]->tail = 0;
    }
}

struct Data *createData(char name[], int age)
{
    struct Data *temp = (struct Data *)malloc(sizeof(struct Data));
    strcpy(temp->name, name);
    temp->age = age;
    temp->prev = temp->next = 0;
    return temp;
}

int hash(const char *name)
{
    char firstChar = name[0];
    if (firstChar >= 'A' && firstChar <= 'Z')
    {
        return (firstChar - 'A') % SIZE;
    }
    else if (firstChar >= 'a' && firstChar <= 'z')
    {
        return (firstChar - 'a') % SIZE;
    }
    return firstChar % SIZE;
}

void pushHead(int key, struct Data *newData)
{
    if (table[key]->head == 0)
    {
        table[key]->head = table[key]->tail = newData;
    }
    else
    {
        newData->next = table[key]->head;
        table[key]->head->prev = newData;
        table[key]->head = newData;
    }
    return;
}

void pushTail(int key, struct Data *newData)
{
    if (table[key]->tail == 0)
    {
        table[key]->head = table[key]->tail = newData;
    }
    else
    {
        newData->prev = table[key]->tail;
        table[key]->tail->next = newData;
        table[key]->tail = newData;
    }
    return;
}

void pushMid(int key, struct Data *newData)
{
    struct Data *curr = table[key]->head;
    while (curr != 0 && strcmpi(newData->name,curr->next->name) >= 0)
    {
        curr = curr->next;
    }
    newData->next = curr->next;
    curr->next->prev = newData;
    newData->prev = curr;
    curr->next = newData;
    
}

void insertData(char name[], int age)
{
    int key = hash(name);
    struct Data *newData = createData(name, age);
    if (table[key]->head == 0 || strcmpi(newData->name, table[key]->head->name) < 0)
    {
        pushHead(key, newData);
    }
    else if (table[key]->tail == 0 || strcmpi(newData->name, table[key]->tail->name) > 0)
    {
        pushTail(key, newData);
    }
    else
    {
        pushMid(key, newData);
    }
}

int main()
{
}