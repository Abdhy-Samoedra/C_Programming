#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//DOUBLE LINKED LIST

// tail dan head diuat menjadi variabel lokal untuk kasus apabila terdapat banyak structnya atau LL

struct Node
{
    char name[100];
    int age;
    struct Node *next, *prev;
};

struct Node *createNode(char name[], int age)
{
    struct Node *node = (struct Node *)malloc(sizeof(Node));
    strcpy(node->name, name);
    node->age = age;
    node->prev = node->next = 0;
    return node;
}

void pushHead(Node **head, Node **tail, Node *node)
{
    if (*head == 0)
    {
        *head = *tail = node;
    }
    else
    {
        (*head)->prev = node;
        node->next = *head;
        *head = node;
    }
}

void pushTail(Node **head, Node **tail, Node *node)
{
    if (*tail == 0)
    {
        *head = *tail = node;
    }
    else
    {
        (*tail)->next = node;
        node->prev = *tail;
        *tail = node;
    }
}

void pushMid(Node **head, Node **tail, Node *node)
{
    if (*head == 0 || strcmp(node->name, (*head)->name) < 0)
    {
        pushHead(head, tail, node);
    }
    else if (strcmp(node->name, (*tail)->name) > 0)
    {
        pushTail(head, tail, node);
    }
    else
    {
        struct Node *curr = *head;
        while (strcmp(node->name, curr->next->name) >= 0)
        {
            curr = curr->next;
        }
        node->next = curr->next;
        curr->next->prev = node;
        node->prev = curr;
        curr->next = node;
    }
}

void popHead(Node **head, Node **tail)
{
    if (head == 0)
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

void popTail(Node **head, Node **tail)
{
    if (*head == 0)
    {
        printf("ga ada data");
    }
    else if (*head == *tail)
    {
        free(*head);
        *head = *tail = NULL;
    }
    else
    {
        *tail = (*tail)->prev;
        free((*tail)->next);
        (*tail)->next = NULL;
    }
}

void popMid(Node **head, Node **tail, char *name)
{
    if (*head == 0)
    {
        printf("ga ada data");
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
        struct Node *curr = *head;
        while (curr->next != 0 && strcmp(curr->name, name) != 0)
        {
            curr = curr->next;
        }
        if (curr->next == 0 || strcmp(curr->name, name) != 0)
        {
            printf("%s data tidak ketemu\n", name);
        }

        curr->next->prev = curr->prev;
        curr->prev->next = curr->next;
        free(curr);
        curr = 0;
    }
}

void popAll(Node **head, Node **tail)
{
    while (*head != 0)
    {
        popHead(head, tail);
    }
    printf("berhasil terhapus semua\n");
}

void display(Node *head)
{
    struct Node *curr = head;
    while (curr)
    {
        printf("%s - %d\n", curr->name, curr->age);
        curr = curr->next;
    }
}

int main()
{
    struct Node *tail = 0, *head = 0; // kali ini mencoba untuk dibuat di lokal

    pushMid(&head, &tail, createNode("erik", 30));
    pushMid(&head, &tail, createNode("abdul", 22));
    pushMid(&head, &tail, createNode("zefa", 19));
    pushMid(&head, &tail, createNode("budi", 22));
    pushMid(&head, &tail, createNode("xavier", 22));
    pushMid(&head, &tail, createNode("sapi", 25));
    // display(head);
    // printf("\n");
    // popMid(&head, &tail,"zefa");
    // display(head);
    // printf("\n");
    // popAll(&head, &tail);
    // display(head);
    // printf("\n");
    popHead(&head, &tail);
    // display(head);
    // printf("\n");
    popMid(&head, &tail,"xavier");
    display(head);

    // pushHead(&head, &tail, createNode("samoedra",33));
    // display(head);
    // printf("\n");

    // pushTail(&head, &tail, createNode("samu",33));
    // pushTail(&head, &tail, createNode("lundi",33));
    // display(head);
    // printf("\n");

    // pushMid(&head, &tail, createNode("jordy",33));
    // display(head);
    // printf("\n");

    // PUSHMID TIDAK BISA DICAMPUR DENGAN PUSH TAIL DAN PUSH HEAD, JIKA DICAMPUR TIDAK AKAN URUT
    // JIKA MAU URUT PAKAI PUSHMID SEMUA

    //    popHead(&head, &tail);
    // popMid(&head, &tail, "abdul");
    // popTail(&head, &tail);
    // popAll(&head, &tail);
    // display(head);

    // popMid(&head,&tail,"aji");
    // popAll(&head, &tail);
    // display(head);
    // printf("\n");
    // popMid(&head,&tail,"aji");
    // popTail(&head, &tail);
    // display(head);
    // printf("\n");
    // popHead(&head, &tail);
    // display(head);
    // printf("\n");
    // popAll(&head, &tail);
    // display(head);
    // printf("\n");
    // popHead(&head, &tail);
    // display(head);

}
