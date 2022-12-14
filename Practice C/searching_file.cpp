#include <stdio.h>
#include <string.h>

void linearSearch()
{
    // sediakan arraya yang akan digunakan untuk mencari angka
    int arr[] = {10, 20, 30, 40, 40, 50};

    int length = sizeof(arr) / sizeof(arr[0]);

    // angka yang akan dicari
    int find = 12;

    int counter = 0;

    for (int i = 0; i < length; i++)
    {
        if (find == arr[i])
        {
            printf("%d ketemu nih di index %d\n", arr[i], i);
            counter++;
            break;
        }
    }
    if (counter == 0)
    {
        printf("tidak ada nih anying\n");
    }
}

void binarySearch()
{
    // binary search dimulai dari tengah
    int arr[] = {10, 20, 30, 40, 50};
    int length = sizeof(arr) / sizeof(arr[0]);

    int find = 40;
    int leftIdx = 0;
    int rightIdx = length - 1;

    while (leftIdx <= rightIdx)
    {
        int midIdx = (leftIdx + rightIdx) / 2;
        // cek datanya sama atau tidak
        if (arr[midIdx] == find)
        {
            printf("ketemu nih %d di index %d\n", find, midIdx);
            break;
        }
        else if (arr[midIdx] < find)
        {
            leftIdx = midIdx + 1;
        }
        else if (arr[midIdx] > find)
        {
            rightIdx = midIdx - 1;
        }
    }
}
void interpolationSearch()
{
    // binary search dimulai dari tengah
    int arr[] = {10, 20, 30, 40, 50};
    int length = sizeof(arr) / sizeof(arr[0]);

    int find = 40;
    int leftIdx = 0;
    int rightIdx = length - 1;

    while (leftIdx <= rightIdx)
    {
        int midIdx = leftIdx + ((rightIdx - leftIdx) * (find - arr[leftIdx]) / (arr[rightIdx] - arr[leftIdx]));
        // cek datanya sama atau tidak
        if (arr[midIdx] == find)
        {
            printf("ketemu nih %d di index %d\n", find, midIdx);
            break;
        }
        else if (arr[midIdx] < find)
        {
            leftIdx = midIdx + 1;
        }
        else if (arr[midIdx] > find)
        {
            rightIdx = midIdx - 1;
        }
    }
}

typedef struct Product
{
    char name[255];
    int price;
}prd;

int main()
{
    linearSearch();
    binarySearch();
    interpolationSearch();

    FILE *baca;

    baca = fopen64("products.txt", "r");

    prd product[10];
    int lastIndex = 0;

    while (!feof(baca))
    {
        fscanf(baca, "%[^#]#%d\n", product[lastIndex].name, &product[lastIndex].price);  
        printf("%s %d", product[lastIndex].name, product[lastIndex].price);
        lastIndex++;
    }

    fclose(baca);

    baca = fopen("products.txt","w");

    // menambahkan data di product
    strcpy(product[lastIndex].name,"sepatu");
    product[lastIndex].price = 5000;
    lastIndex++;

    // masukin data kedalam file
    for (int i = 0; i < lastIndex; i++)
    {
        fprintf(baca,"%s#%d\n",product[i].name,product[i].price);
    }
    

    return 0;
}