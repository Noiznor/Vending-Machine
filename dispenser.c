/*
============================================================================
FILE : dispenser.c
AUTHOR : Noiznor
DESCRIPTION : Implementation of stock management functions for the Snack Shop vending machine.
COPYRIGHT : 2024-02-05
REVISION HISTORY
Date: By: Description:
============================================================================
*/

#include "vending.h"

/*
============================================================================
FUNCTION : displayProducts
DESCRIPTION : Displays the available products along with their prices and stock.
ARGUMENTS : None
RETURNS : void
===========================================================================
*/
void displayProducts()
{
    showMoney();
    printf("\t\t\t");printf("Available Products:");
    for (int i = 1; i <= NUM_PRODUCTS; i++)
    {
        if (i == NUM_PRODUCTS)
        {
            printf("\n");
            printf("\t\t\t");
            printf("[%d] %s\n", i, products[i - 1].name);
        } else
        {
            printf("\n");
            printf("\t\t\t");
            printf("[%d] %s - $%d |Stock: %d|\n", i, products[i - 1].name, products[i - 1].price, products[i - 1].stock);
        }
    }
}

/*
============================================================================
FUNCTION : manageStock
DESCRIPTION : Allows the admin to manage the stock of available products.
ARGUMENTS : None
RETURNS : void
===========================================================================
*/
void manageStock()
{
  int productNumber, quantity;

  printf("\t\t\t");
  printf("Choose product to add stock to:\n");

  for (int i = 0; i < NUM_PRODUCTS - 1; i++)
  {
    printf("\t\t\t");
    printf("[%d] %s |Stock: %d|", i + 1, products[i].name, products[i].stock);
    printf("\n");
  }
  printf("\n");
  printf("\t\t\t");
  printf("Enter product number: ");
  scanf("%d", &productNumber);
  system("cls");

  // Adjust product index to account for skipped "Menu" item
  if (productNumber < 1 || productNumber > NUM_PRODUCTS - 1)
  {
    printf("\n\t\t\tInvalid product number!\n");
    fflush(stdout);  // Ensure message is displayed immediately
    sleep(1);
    system("cls");
    adminMenu();
    return;
  }

  int productIndex = productNumber - 1;

  printf("\n\t\t\tEnter quantity to add: ");
  scanf("%d", &quantity);

  if (quantity <= 0)
    {
        printf("\n\t\t\tInvalid quantity!\n");
        fflush(stdout);  // Ensure message is displayed immediately
        sleep(1);
        system("cls");
        adminMenu();
    return;
  }

  products[productIndex].stock += quantity;
  saveData(); // Update data file
  printf("\n");
  printf("\t\t\t");
  printf("[%d] Stock added successfully!\n", quantity);
  printf("\n\t\t\tPress any key to go back...");
  getch();
  system("cls");
  return adminMenu();
}
