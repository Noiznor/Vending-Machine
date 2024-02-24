#ifndef VENDING_H_INCLUDED
#define VENDING_H_INCLUDED
#include <string.h>


#define NUM_PRODUCTS 5
#define DATA_FILE "data.dat"
#define PASSWORD "oten"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <unistd.h>
#include <conio.h>



struct Product {
    char name[50];
    int price;
    int stock;
    time_t lastUpdated;
};

extern struct Product products[NUM_PRODUCTS];
extern int money;

int choice, itemChoice, passcode;
void displayProducts();
void buyProduct();
void loadData();
void saveData();
void WelcomeScrn();

#endif // VENDING_H_INCLUDED
