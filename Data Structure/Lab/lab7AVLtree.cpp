#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// BERDASARKAN PRICE
struct Food
{
    char name[20];
    int price;
    struct Food *left, *right;
    int height;
};
Food *createFood(char name[], int price)
{
    Food *newFood = (struct Food *)malloc(sizeof(struct Food));
    strcpy(newFood->name, name);
    newFood->price = price;
    newFood->left = newFood->right = NULL;
    newFood->height = 1;
    return newFood;
}

int getMax(int a, int b)
{
    return (a >= b) ? a : b;
    // a lebih dari b gak ? kalo iya retura a , kalo gak return b
}
int calculateHeight(Food *node)
{
    return (node == 0) ? 0 : 1 + getMax(calculateHeight(node->left), calculateHeight(node->right));

    // PENJABARAN TERNARY NYA
    // if (node == 0)
    // {
    //     return 0;
    // }

    // // bandignin tinggi anak kiri dan kanan
    // int leftHeight = calculateHeight(node->left);
    // int rightHeight = calculateHeight(node->right);

    // //bandingin dan ambil yang paling gede
    // //lalu ditambah 1
    // return 1 + getMax(leftHeight,rightHeight);
}
int getBalance(Food *node)
{
    // balance kalau -1 / 0 / 1
    return (node == 0) ? 0 : (calculateHeight(node->left) - calculateHeight(node->right));
}
Food *rightRotate(Food *node)
{
    Food *newParent = node->left;
    node->left = newParent->right;
    newParent->right = node;

    // update height
    node->height = calculateHeight(node);
    newParent->height = calculateHeight(newParent);

    return newParent;
}
Food *leftRotate(Food *node)
{
    Food *newParent = node->right;
    node->right = newParent->left;
    newParent->left = node;

    // update height
    node->height = calculateHeight(node);
    newParent->height = calculateHeight(newParent);

    return newParent;
}
Food *insertFood(struct Food *root, char name[], int price)
{
    // kalau root belum ada data / root == null
    if (root == 0)
    {
        return createFood(name, price);
    }

    // kalau root ada dan data yang mau dimasukkin lebih kecil daripada root
    else if (price < root->price)
    {
        root->left = insertFood(root->left, name, price);
    }

    // kalau root ada dan data yang mau dimasukkin lebih besar daripada root
    else if (price > root->price)
    {
        root->right = insertFood(root->right, name, price);
    }

    // UPDATE height
    root->height = calculateHeight(root);

    // cek balance
    int balance = getBalance(root);

    // cek
    // berat kiri
    if (balance > 1)
    {
        // kalau price > root->price
        // left rotate dulu
        if (price > root->price)
        {
            root->left = leftRotate(root->left);
        }

        // right rotate
        return rightRotate(root);
    }
    // berat kanan
    else if (balance < -1)
    {
        // kalau price < root->price
        // left rotate dulu
        if (price < root->price)
        {
            root->left = rightRotate(root->left);
        }

        // right rotate
        return leftRotate(root);
    }

    return root;
}
Food *updateFood(Food *root , int price, char newName[])
{
    if (root == 0)
    {
        printf("Data not found\n");
        return root;
    }
    else if (price < root->price)
    {
        root->left = updateFood(root->left , price, newName);
    }
    else if (price > root->price)
    {
        root->right = updateFood(root->right , price, newName);
    }
    else
    {
        strcpy(root->name,newName);
        printf("succesfully update\n");
    }
    return root;
    
}
// display in order

void displayInOrder(Food *root)
{
    // jika ga ada data
    if (root == 0)
    {
        // printf("ga ada data\n");
        return;
    }
    displayInOrder(root->left);
    printf("%s %d | height : %d | balance : %d\n", root->name, root->price, root->height,getBalance(root));
}

int main()
{
    // declare root pertama kalinya
    Food *root = insertFood(NULL, "sate padang", 34000);
    root = insertFood(root , "Sate Kambing",30000);
	root = insertFood(root , "Sate Ayam",28000);
	root = insertFood(root , "Sate Kelinci",26000);
	root = insertFood(root , "Sate Taichan",24000);
	root = insertFood(root , "Sate Kuda",22000);
	
	displayInOrder(root);
	
	printf("\nAfter Update: \n");
	
	root = updateFood(root,24000,"Sate Taichan Pedas");
	displayInOrder(root);
	
	printf("\nAfter Update: \n");
	
	root = updateFood(root,20000,"Sate Abdhy");
	displayInOrder(root);
}