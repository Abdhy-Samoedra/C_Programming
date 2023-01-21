#include <stdio.h>
#include <stdlib.h>

// SINGEL LINKED LIST

// define data / node

struct Food
{
    int price;
    struct Food *next; // menyimpan alamat dari data selanjutnya
} *head = NULL, *tail = NULL;

struct Food *createFood(int price) // functiin untuk membuat data
{
    // pesan dulu memeori sebesar Food* dengan malloc
    // aga bisa digunakan harus di typecast dulu void* jadi Food*
    struct Food *food = (struct Food *)malloc(sizeof(Food *));
    // assign value
    food->price = price;
    food->next = NULL;

    return food;
};

void pushHead(int price)
{
    struct Food *newFood = createFood(price);

    if (!head)
    {
        head = tail = newFood; // data baru langsung jadi head dan tail
    }
    else
    {
        newFood->next = head; // data baru nunjuk ke head
        head = newFood;       // data bru jadi head
    }
}

void pushTail(int price)
{
    struct Food *newFood = createFood(price);

    if (!head)
    {
        head = tail = newFood;
    }
    else
    {
        tail->next = newFood;
        tail = newFood;
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
        struct Food *newFood = createFood(price);
        struct Food *curr = head;
        while (curr->next != 0 && curr->next->price < price)
        {
            curr = curr->next;
        }
        newFood->next = curr->next;
        curr->next = newFood;
    }
}

void printFoods()
{
    // temporal data untuk jalan dari data paling depan sampai akhir
    struct Food *curr = head;

    while (curr != NULL)
    {
        // print data nya
        printf("%d", curr->price);
        // jelan ke data sebeklumnya
        curr = curr->next;
    }
    return;
}

void popHead()
{
    if (!head)
    {
        return;
    }
    else if (head == tail)
    {
        free(head);
        head = tail = NULL;
    }
    else
    {
        struct Food *temp = head->next; // calon head barunya (data di sebelah head)
        free(head);                     // deallocate memori address dari head yang lama
        head = temp;                    // head barunya adalah head->nect (temp)
    }
}

void popTail()
{
    if (!head)
    {
        return;
    }
    else if (head == tail)
    {
        free(head);
        head = tail = NULL;
    }
    else
    {
        struct Food *curr = head;
        // jalan sampai data sebelum tail
        while (curr->next != tail)
        {
            curr = curr->next;
        }

        free(tail);        // deallocate address tail
        curr->next = NULL; // curr nunjuk NULL (karena udah ga nunjuk tail, udah ga ada tail)
        tail = curr;       // curr jadi tail yang baru
    }
}

void popMid(int price)
{
    if (!head)
    {
        return;
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
        struct Food *curr = head;
        // selama data yang mau dicari belum ketemu

        while (curr->next != NULL && curr->next->price != price)
        {
            curr = curr->next;
        }
        if (curr->next == NULL || curr->next->price != price)
        {
            printf("\nData to be deleted is not found!\n");
        }
        else
        {
            struct Food *temp = curr->next->next;
            free(curr->next);
            curr->next = temp;
        }
    }
}

int main()
{
    // pushHead(30000);
    // pushHead(28000);
    // pushHead(17000);
    pushMid(25000);
    pushMid(10000);
    printFoods();

    // popMid(28000);
    // printf("\n");
    // printFoods();

    // popMid(16000);
    // printf("\n");
    // printFoods();
}