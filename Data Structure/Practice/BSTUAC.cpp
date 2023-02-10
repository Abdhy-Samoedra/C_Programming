#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int cust_name = 55;

struct customer
{
    char name[cust_name];
    char membershipName[20];

    struct customer *left, *right;
} *rootCustomer = 0;

struct membership
{
    char name[20];

    struct customer *left, *right;
} *rootMembership = 0;

void insertMembership(struct membership *curr, char name[])
{
    struct membership = 
}