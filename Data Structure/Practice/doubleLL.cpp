#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Data
{
    char name[20];
    int age;
    struct Data *next, *prev;
};

struct Data *createData(char name[], int age)
{
    struct Data *newData = (struct Data *)malloc(sizeof(struct Data));
    strcpy(newData->name, name);
    newData->age = age;
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
    if (*head == 0 || strcmp(newData->name, (*head)->name) < 0) // jika urutan abjad lebih dari head, maka push head
    {
        pushHead(head, tail, newData);
    }
    else if (strcmp(newData->name, (*tail)->name) >= 0) // jika urutan abjad lebih dari tail, maka pushtail
    {
        pushTail(head, tail, newData);
    }
    else
    {
        struct Data *curr = *head;
        while (strcmp(newData->name, curr->next->name) >= 0)
        {
            curr = curr->next; // ini looping untuk mengetahui posisi dari data yang akan dimasukkan, looping ini menghasilkan data yang urutannya berada sebelum data yang akan dimasukkan
        }
        newData->next = curr->next; // mindahin data setelah current, menjadi data setelah data baru
        curr->next->prev = newData;  // menunjuk posisi data setalah current pada saat posisi awal, lalu ditunjuk prev sebagai lokasi/alamatnya saja lalu prev di isi data baru
        newData->prev = curr; // prev dari data baru menjadi current
        curr->next = newData; // next dari current jadi data baru
    }
}

void popHead(Data **head, Data **tail)
{
    if (*head == 0)
    {
        printf("tidak ada data");
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
        printf("tidak ada data");
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
    else if (strcmp(name, (*head)->name) == 0) // jika ternyata valuenya di head, maka pophead
    {
        popHead(head, tail);
    }
    else if (strcmp(name, (*tail)->name) == 0) // jika ternyata valuenya di tail maka, pop tail
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
            printf("%s data tidak ketemu", name);
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
        popHead(head,tail);
    }
    printf("berhasil terhapus semua\n");
    
}

void display(Data *head)
{
    struct Data *curr = head;
    while (curr != 0)
    {
        printf("%-10s | %d\n", curr->name, curr->age);
        curr = curr->next;
    }
}

int main()
{
    struct Data *tail = 0, *head = 0;

    // NOTE PUSHHEAD DAN PUSHHEAD TIDAK BISA DICAMPUR DENGAN PUSHVALUE

    // pushHead(&head, &tail, createData("samudra", 99));
    // pushHead(&head, &tail, createData("joel", 44));
    // pushTail(&head, &tail, createData("jordy", 90));
    // pushTail(&head, &tail, createData("alex", 34));

    pushValue(&head, &tail, createData("jordy", 90));
    pushValue(&head, &tail, createData("alex", 34));
    pushValue(&head, &tail, createData("samuel", 90));
    pushValue(&head, &tail, createData("andro", 34));

    // display(head);
    // printf("\n");

    // popHead(&head, &tail);
    // printf("\n");
    // display(head);

    // popTail(&head, &tail);
    // printf("\n");
    // display(head);
    popAll(&head,&tail);
    popValue(&head, &tail,"ssss");
    
}