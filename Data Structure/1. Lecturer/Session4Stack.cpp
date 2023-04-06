#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct data
{
    char name[20];
    int age;

    struct data *next;
} *head = 0; //  karena pada stack hanya memakai head

// stack adalah first in last out, maka dari itu hanya ada head saja

void push(char name[], int age)
{
    // create new node
    struct data *temp = (struct data *)malloc(sizeof(struct data));
    // mengisi node baru dengan data yang di butuhkan
    temp->age = age;
    temp->next = 0;

    strcpy(temp->name, name);
    // cek apakah stack/LL kosong apa tidak
    if (head == 0)
    {
        head = temp;
    }
    // jika ada isinya
    else
    {
        temp->next = head;
        head = temp;
    }
}

void display()
{
    struct data* curr = head;
    while (curr != 0)
    {
        printf("%s %d\n",curr->name,curr->age);
        curr = curr->next;
    }
    
}

void popHead()
{
    if (head == 0)
    {
        printf("ga ada data");
    }
    else
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
    printf("\n");
    display();
    return 0;
}