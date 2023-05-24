#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data
{
    char name[20];
    char NIM[10];
    double GPA;
    struct data *next;
} *head = 0, *tail = 0;

void push(char name[20], char NIM[10], double GPA)
{
    // tentuin prioritas dullu mau berdasarkan apa
    // misal berdasarkan GPA descending

    struct data *temp = (struct data *)malloc(sizeof(struct data));
    strcpy(temp->name, name);
    strcpy(temp->NIM, NIM);
    temp->GPA = GPA;
    temp->next = 0;

    // cek apakah data kosong
    if (head == 0)
    {
        head = tail = temp;
    }
    // memiliki prioritas lebih tinggi dari pada head
    else if (GPA > head->GPA)
    {
        // insert head
        temp->next = head;
        head = temp;
    }
    // jika memiliki prioritas lebih kecil/sama dengan tail
    else if (GPA <= tail->GPA)
    {
        tail->next = temp;
        tail = temp;
    }
    // jika memiliki prioritas di tengah tengah
    else
    {
        struct data *curr = head;
        while (curr->next->GPA >= GPA)
        {
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next = temp;
    }
}
void display()
{
    struct data *curr = head;
    while (curr != 0)
    {
        printf("%s %s %.2lf\n", curr->name, curr->NIM, curr->GPA);
        curr = curr->next;
    }
}

void popHead()
{
    if (head == 0)
    {
        printf("ga ada data nih");
    }

    struct data *del = head;
    head = head->next;
    free(del);
}

int main()
{
    push("Budi", "2602189846", 3.5); // 3
    push("Dani", "2602189867", 3.1); // 5
    push("Juki", "2602189837", 3.4); // 4
    push("Andi", "2602189809", 4.0); // 1
    push("Romi", "2602189870", 2.9); // 6
    push("Tono", "2602189839", 3.9); // 2

    display();
    printf("\n");
    printf("\n");

    popHead();
    popHead();
    display();

    return 0;
}