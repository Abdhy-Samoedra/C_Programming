#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct data
{
    char name[20];
    int age;

    struct data *next;
} *head = 0, *tail = 0;

void push(char name[], int age)
{
    struct data *temp = (struct data *)malloc(sizeof(struct data));
    // memasukkan age
    temp->age = age;
    temp->next = 0;
    // memasukkan name
    strcpy(temp->name, name);

    if (tail == 0) // bisa pake tail atau head
    {
        head = tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

void display()
{
    struct data *curr = head; // tanda pointer ditaruh di data* / *curr sama
    while (curr != 0)
    {
        printf("%s %d\n", curr->name, curr->age);
        curr = curr->next;
    }
}

void popHead()
{
    if(head == 0)
    {
        printf("ga ada data");
    }else
    {
        struct data *del = head;
        head = head->next;
        free(del);
    }
    
}

int main()
{
    push("sssss", 7);
    push("dnjknk", 988);
    push("kjhkdjldj", 33);
    display();
    popHead();
    popHead();
    popHead();
    popHead();
    popHead();
    printf("\n");
    display();
    return 0;
}