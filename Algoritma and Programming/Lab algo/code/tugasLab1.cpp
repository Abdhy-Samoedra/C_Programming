#include <stdio.h>

int main()
{

    printf("\n");
    printf("Simple Input/Output Program\n");
    printf("=============================\n");
    printf("Welcome to \"Algorithm and Programming\"");

    printf("\n");
    printf("\n");

    char name [20];
    int age;
    

    printf("Enter your name: ");
    scanf("%[^\n]s", name);

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Hello, %s !\n", name);


    float num1;
    float num2;

    printf("Enter the first number: ");
    scanf("%f", &num1);
    printf("Enter the second number: ");
    scanf("%f", &num2);

    printf("Arithmetic calculations :\n");
    printf("%.2f + %.2f = %.2f\n",num1,num2,num1+num2);
    printf("%.2f - %.2f = %.2f\n",num1,num2,num1-num2);
    printf("%.2f * %.2f = %.2f\n",num1,num2,num1*num2);
    printf("%.2f / %.2f = %.2f\n",num1,num2,num1/num2);



}