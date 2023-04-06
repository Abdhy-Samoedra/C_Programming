#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int SIZE = 26;

struct Node
{
    char name[20];
    int age;
} *table[SIZE];

Node *createNewNode(char *name, int age)
{
    Node *node = (struct Node *)malloc(sizeof(struct Node));
    strcpy(node->name, name);
    node->age = age;

    return node;
}

int hash(char *name)
{
    char c = name[0];
    if (c >= 'A' && c <= 'Z')
    {
        return c - 'A';
    }
    else if (c >= 'a' && c <= 'Z')
    {
        return c - 'a';
    }
    else
    {
        return c % SIZE;
    }
}

void insertNode(char *name, int age)
{
    int key = hash(name);

    if (table[key] == 0)
    {
        table[key] = createNewNode(name, age);
        return;
    }

    int curr = key + 1;

    while (key != curr && table[curr])
    {
        curr = (curr + 1) % SIZE;
    }

    if (curr == key)
    {
        printf("table full\n");
        return;
    }

    table[curr] = createNewNode(name, age);
}

void deleteNode(char *name)
{
    int key = hash(name);

    if (table[key] && strcmp(table[key]->name, name) == 0)
    {
        free(table[key]);
        table[key] = 0;
        return;
    }

    int curr = key + 1;

    while (key != curr && (table[curr] == 0 || strcmp(table[curr]->name, name) != 0))
    {
        curr = (curr + 1) % SIZE;
    }

    if (key == curr) // not found
    {
        printf("%s not found\n", name);
        return;
    }

    free(table[curr]);
    table[curr] = 0;
}

void view()
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d.", i + 1);
        Node *curr = table[i];
        if (curr != 0)
        {
            printf("%s - %d\n", curr->name, curr->age);
        }
        else
        {
            printf("-\n");
        }
    }
}

int main()
{
    insertNode("budi", 20);
    insertNode("clara", 20);
    insertNode("abel", 20);
    insertNode("abdul", 20);
    insertNode("jull", 20);
    insertNode("jason", 20);

    view();
    printf("\n");
    deleteNode("clara");
    deleteNode("abdul");
    deleteNode("budi");
    deleteNode("abel");
    deleteNode("budiman");
    deleteNode("samu");
    deleteNode("jull");
    // for (int i = 0; i < 30; i++)
    // {
    //     char name[20];
    //     sprintf(name, "budi %d", i);
    //     insertNode(name, 20);
    // }

    view();
    return 0;
}
