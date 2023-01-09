#include <stdio.h>
#include <stdlib.h>

// define data / node

struct Food
{
    int price;
    struct Food *next; // menyimpan alamat dari data selanjutnya
} *head = NULL, *tail = NULL;

struct Food *createFood(int price)
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

void pushTail()
{

}

void pushMid()
{
}

void printFoods()
{
    // temporal data untuk jalan dari data paling depan sampai akhir
    struct Food *curr = head;

    while (curr != NULL)
    {
        // print data nya
        printf("%d",curr->price);
        // jelan ke data sebeklumnya
        curr = curr->next;
    }
    
}

int main()
{
    pushHead(300000);
    printf("%d\n", head->price);
    // struct Food *food = createFood(30000);
    // printf("%d\n", food->price);
}