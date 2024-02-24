/*
============================================================================
FILE : vending.c
AUTHOR : Cabang Raezan, Juanitee Leesandro, Polotan Genesis
DESCRIPTION : Implementation of product purchase operations for the Snack Shop vending machine.
COPYRIGHT : 2024-02-05
REVISION HISTORY
Date: By: Description:
============================================================================
*/

#include "vending.h"


struct Product products[NUM_PRODUCTS] =
{
    {"Candy", 10, 100, 0},
    {"Crackers", 15, 100, 0},
    {"Cookies", 20, 100, 0},
    {"Soda", 30, 100, 0},
    {"Menu", 0, 0, 0} //Go back to main Menu button
};

money = 1000;


/*
============================================================================
FUNCTION : getCurrentTimestamp
DESCRIPTION : Returns the current timestamp.
ARGUMENTS : None
RETURNS : time_t - Current timestamp
===========================================================================
*/
time_t getCurrentTimestamp()
{
    time_t t;
    time(&t);
    return t;
}

/*
============================================================================
FUNCTION : buyProduct
DESCRIPTION : Allows the user to buy a product and updates stock and money accordingly.
ARGUMENTS : None
RETURNS : void
===========================================================================
*/
buyProduct()
{
    int productNumber, quantity;
    double userPayment;
    char confirmPurchase;

    printf("\n");
    printf("\t\t\t");printf("Enter product number [1-%d]: ", NUM_PRODUCTS - 1);
    scanf("%d", &productNumber);
    system("cls");

    if (productNumber < 1 || productNumber > NUM_PRODUCTS)
        {
            printf("\n");
            printf("\t\t\t");printf("Invalid product number!\n");
            displayProducts();
            system("cls");
        return;
        }

    if (productNumber == NUM_PRODUCTS)
        {
            printf("\n");
            printf("\t\t\t");printf("Going back to main menu...\n");
            fflush(stdout);  // Ensure message is displayed immediately
            sleep(1);
            system("cls");
            mainMenu();
            return; // Go back to main menu
        }

    int productIndex = productNumber - 1;

    if (products[productIndex].stock == 0)
        {
            printf("\n");
            printf("\t\t\t");printf("%s is out of stock!\n", products[productIndex].name);
            printf("\t\t\t");printf("Press any key to go back...");
            getch();
            system("cls");
        return;
        }

    do
        {
        printf("\t\t\t");printf("Enter how many %s you want to buy (max %d): ", products[productIndex].name, products[productIndex].stock);
        scanf("%d", &quantity);
        system("cls");
        }
    while (quantity < 1 || quantity > products[productIndex].stock);

    double totalPrice = quantity * products[productIndex].price;

    printf("\n");
    printf("\t\t\t");printf("Total price: $%.2f", totalPrice);

    printf("\n");
    printf("\t\t\t");printf("Confirm purchase (y/n): ");
    scanf(" %c", &confirmPurchase);
    system("cls");

    if (confirmPurchase != 'y' && confirmPurchase != 'Y')
    {
        printf("\n");
        printf("\t\t\t");printf("Purchase cancelled.\n");
        fflush(stdout);  // Ensure message is displayed immediately
        sleep(1);
        system("cls");
        return;
    }
        printf("\t\t\tTotal price: $%.2f\n", totalPrice);
    printf("\t\t\tEnter your payment amount: $");
    scanf("%lf", &userPayment);

    if (userPayment < totalPrice)
        {
        // Handle insufficient payment (once without looping)
        printf("\t\t\tInsufficient payment! You need $%.2f more.\n", totalPrice - userPayment);
        double remainingPayment;
        printf("\t\t\tEnter the remaining payment amount: $");
        scanf("%lf", &remainingPayment);
        userPayment += remainingPayment;
        system("cls");

        if (userPayment < totalPrice)
        {
            // Cancel transaction if still insufficient
            printf("\t\t\tTransaction cancelled.\n");
            printf("\t\t\tTotal payment refunded: $%.2f\n", userPayment);
            fflush(stdout);  // Ensure message is displayed immediately
            sleep(1);
            system("cls");
            return;
        }
    }

    if(userPayment > totalPrice)
    {
        printf("\t\t\t");printf("You bought %d %s.\n", quantity, products[productIndex].name);
        printf("\t\t\t");printf("Total price: $%.2f\n", totalPrice);
        printf("\t\t\t");printf("Money deposited: $%.2f\n", userPayment);
        printf("\t\t\t");printf("Change: $%.2f\n", userPayment - totalPrice);
    }

    if(userPayment == totalPrice)
    {
        printf("\t\t\t");printf("You bought %d %s.\n", quantity, products[productIndex].name);
    }

    products[productIndex].stock -= quantity;
    money += totalPrice;
    products[productIndex].lastUpdated = getCurrentTimestamp();
    saveData();

    printf("\n");
    printf("\t\t\t");printf("Successful Transaction...");
    printf("\n");
    printf("\t\t\t");printf("Press any key to go back...");
    getch();
    system("cls");
}
