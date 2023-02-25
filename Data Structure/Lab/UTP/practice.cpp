#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int SIZE = 26;

struct Food
{
    char name[100];
    int price;
    struct Food *next, *prev;
};

struct Table
{
    struct Food *head, *tail;
} *table[SIZE];

void initializeTable()
{
    for (int i = 0; i < SIZE; i++)
    {
        table[i] = (struct Table *)malloc(sizeof(struct Table));
        table[i]->head = table[i]->tail = 0;
    }
}

struct Food *createFood(char name[], int price)
{
    struct Food *newFood = (struct Food *)malloc(sizeof(struct Food));
    strcpy(newFood->name, name);
    newFood->price = price;
    newFood->next = newFood->prev = 0;
    return newFood;
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

void pushHead(int key, struct Food *newFood)
{
    if (table[key]->head == 0)
    {
        table[key]->head = table[key]->tail = newFood;
    }
    else
    {
        newFood->next = table[key]->head;
        table[key]->head->prev = newFood;
        table[key]->head = newFood;
    }
}

void pushTail(int key, struct Food *newFood)
{
    if (table[key]->head == 0)
    {
        table[key]->head = table[key]->tail = newFood;
    }
    else
    {
        newFood->prev = table[key]->tail;
        table[key]->tail->next = newFood;
        table[key]->tail = newFood;
    }
}
void pushMid(int key, struct Food *newFood)
{
    struct Food *curr = table[key]->head;
    while (curr != 0 && strcmpi(newFood->name, curr->next->name) >= 0)
    {
        curr = curr->next;
    }
    newFood->next = curr->next;
    newFood->prev = curr;
    curr->next->prev = newFood;
    curr->next = newFood;
}

void insertFood(char name[], int price)
{
    int key = hash(name);
    struct Food *newFood = createFood(name, price);

    if (table[key]->head == 0 || strcmpi(name, table[key]->head->name) < 0)
    {
        pushHead(key, newFood);
    }
    else if (table[key]->tail == 0 || strcmp(name, table[key]->tail->name) >= 0)
    {
        pushTail(key, newFood);
    }
    else
    {
        pushMid(key, newFood);
    }
}

void view()
{
    for (int i = 0; i < SIZE; i++)
    {
        struct Food *curr = table[i]->head;
        while (curr != 0)
        {
            printf("%s %d\n", curr->name, curr->price);
            curr = curr->next;
        }
    }
}

int main()
{
    initializeTable();
    
    view();
    insertFood("A", 29000);
    insertFood("B", 29000);
    insertFood("C", 29000);
    insertFood("C", 30);
    insertFood("C", 9);
    insertFood("Sate Kambing", 29000);
    view();
}