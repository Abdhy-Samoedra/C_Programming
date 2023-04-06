#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 100 // 99 data, karena idx 0 ga dipake

// heap: binary tree, partially ordered
// maxheap: parentnya lebih besar daripada childnya
// minheap: parentnya lebih kecil daripada childnya

// define struct
struct Food
{
    char name[100];
    int price;
} foods[MAXSIZE];

int lastIndex = 1; // kalau punya data baru masuk ke index last

void swap(Food *a, Food *b)
{
    Food temp = *a;
    *a = *b;
    *b = temp;
    return;
}

// curr = node yang sekarang lagi dicek
void heapify(int curr, int size)
{
    // cari index anak kiri dan kanan
    int left = 2 * curr;
    int right = left + 1;

    int largest = curr;
    // apakah ada anak kiri dan anak kiri lebih besar?
    if (left < size && foods[left].price > foods[largest].price)
    {
        largest = left;
    }
    // apakah ada anak kanan dan anak kanan lebih besar?
    if (right < size && foods[right].price > foods[right].price)
    {
        largest = right;
    }

    // kalau largest bukan di curr
    if (largest != curr)
    {
        // swap
        swap(&foods[largest], &foods[curr]);
        // heapify recursive ke bawah
        heapify(largest, size);
    }
}

void buildHeap()
{
    // untuk loooping semua data yang punya child/bukan leaf
    for (int i = lastIndex / 2; i >= 1; i--)
    {
        // heapify = proses memindahkan node heap ke posisi yang tepat(paling besar di paling atas)
        heapify(i, lastIndex);
    }
    return;
}

void insertFood(char name[], int price)
{
    strcpy(foods[lastIndex].name, name);
    foods[lastIndex].price = price;
    lastIndex++;

    // cek apakah sudah sesuai
    buildHeap();
}
int searchFood(int price)
{
    // linear search
    for (int i = 0; i < lastIndex; i++)
    {
        // kalau ketemu
        if (foods[i].price == price)
        {
            return i;
        }
    }
    return -1;
}
void deleteFood(int price)
{
    int idx = searchFood(price);
    if (idx == -1)
    {
        return;
    }

    // swap dengan data terakhir
    swap(&foods[idx], &foods[lastIndex-1]);
    lastIndex--;

    // cek lagi
    buildHeap();
    return;
    
}

void heapsort(){
    // pastiin dulu tree sudah berberntuk heap
    buildHeap();
    for (int i = lastIndex-1; i > 1; i--)
    {
        swap(&foods[1],&foods[i]);
        heapify(1 , i);
    }

    return;
    
}

void viewFood()
{
    for (int i = 1; i < lastIndex; i++)
    {
        printf("%s %d\n", foods[i].name, foods[i].price);
    }
}
int main()
{
    insertFood("ayam", 30000);
    insertFood("ayam", 28000);
    insertFood("ayam", 37000);
    insertFood("ayam", 42000);
    insertFood("ayam", 76000);
    viewFood();
    printf("\n");
    heapsort();
    // insertFood("ayam", 36000);
    viewFood();
}
