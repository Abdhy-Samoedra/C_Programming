#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//      CHAINING

const int maxArrSize = 20;

struct data
{
    char heroName[20];
    char heroType[20];

    int level;
    struct data *next;
};

// membuat hash tablenya
struct data *dataArr[maxArrSize];

// membut hash function, contoh inin menggunakan functiion DIVISION
int hashFunct(char heroName[]) // parameter nya gunakan variabel paling unique (disini name karena hero dota name gaada yang sama)
{
    // disini first dan last terserah kita, bisa juga menggunakan semua hruf dalam katanya apabila terjadi kesamaan antara huruf awal dan akhir antara kata satu dengn kata lainnnya
    char first = heroName[0];
    char last = heroName[strlen(heroName) - 1];

    int res = (first + last) % maxArrSize;
    return res;
}

void insert(char heroName[], char heroType[], int level)
{
    struct data *temp = (struct data *)malloc(sizeof(struct data));
    strcpy(temp->heroName, heroName);
    strcpy(temp->heroType, heroType);
    temp->level = level;
    temp->next = 0;

    // get hash value/key/index from hash function
    int index = hashFunct(heroName);
    printf("%d\n", index);

    // insert to hash table, aply chaining if needed atau terjadi collusion (dobel)

    // if current index in hash table is empty
    if (dataArr[index] == 0)
    {
        dataArr[index] = temp;
    }
    // if current index in hash table is not empty
    else
    {
        // jika ternyata ada datanya, kita melakukan chaining
        struct data *curr = dataArr[index];
        while (curr->next != 0)
        {
            curr = curr->next;
        }
        curr->next = temp;
    }
}

void display()
{
    for (int i = 0; i < maxArrSize; i++)
    {

        if (dataArr[i] != 0) // if curr index is not empty, karena di chaining bisa empty indexnya
        {
            struct data *curr = dataArr[i];
            while (curr != 0)
            {
                printf("%s -> ", curr->heroName);
                curr = curr->next;
            }
            printf("\n");
        }
    }
}

int main()
{
    insert("axe", "str", 1);
    insert("invoker", "int", 1);
    insert("sven", "str", 1);
    insert("axe", "str", 1);
    insert("sven", "str", 1);
    insert("juggernaut", "agi", 1);
    insert("sniper", "agi", 1);
    insert("andre", "mage", 1);
    insert("junt", "agi", 1);
    insert("magnus","int",1);
    insert("lion","int",1); //lion masuk ke axe dan andre karena hasil modulus dari penjumlahan last dam first indenya adalah sama

    display();
    return 0;
}