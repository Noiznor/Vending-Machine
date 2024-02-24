/*
============================================================================
FILE : main.c
AUTHOR : Cabang Raezan, Juanite Leesandro, Polotan Genesis
DESCRIPTION : Main program for Snack Shop vending machine
COPYRIGHT : 2024-02-05
REVISION HISTORY
Date: By: Description:

============================================================================
*/



#include "vending.h"
#include <string.h>
#define DATA_FILE "data.dat"


int main()
{
    loadData();
    WelcomeScrn();
    mainMenu();

    do {

        switch (itemChoice)
        {
            case 1:
                displayProducts();
                buyProduct();
                break;
            case 2:
                adminLogin();
                break;
            case 3:
                printf("\t\t\t");printf("Exiting...\n");
                getch();
                getchar();
                return 0;
            default:
                printf("\t\t\t");printf("Invalid choice!\n");
                printf("\n");
                printf("\t\t\t");printf("Please Wait...\n");
                fflush(stdout);  // Ensure message is displayed immediately
                sleep(1);
                system("cls");
                mainMenu();
        }
    } while (choice != 3);

    return 0;
}


/*
============================================================================
FUNCTION : loadData
DESCRIPTION : Loads data from the data file into the program.
ARGUMENTS : None
RETURNS : void
===========================================================================
*/
loadData()
{
    FILE *fp = fopen(DATA_FILE, "rb");
    if (fp == NULL)
    {
        //printf("Error opening data file!\n");
        return;
    }

    fread(&products, sizeof(struct Product), NUM_PRODUCTS, fp);
    fread(&money, sizeof(int), 1, fp);
    fclose(fp);
}

/*
============================================================================
FUNCTION : saveData
DESCRIPTION : Saves data from the program into the data file.
ARGUMENTS : None
RETURNS : void
===========================================================================
*/
saveData()
{
    FILE *fp = fopen(DATA_FILE, "wb");
    if (fp == NULL)
    {
        //printf("Error opening data file!\n");
        return;
    }

    fwrite(&products, sizeof(struct Product), NUM_PRODUCTS, fp);
    fwrite(&money, sizeof(int), 1, fp);
    fclose(fp);
}

/*
============================================================================
FUNCTION : mainMenu
DESCRIPTION : Displays the main menu of the Snack Shop vending machine.
ARGUMENTS : None
RETURNS : void
===========================================================================
*/
mainMenu()
{
    printf("\t\t\t");printf("***Welcome to Snack Shop***");
    printf("\n");
    printf("\t\t\t");printf("1. Buy");
    printf("\n");
    printf("\t\t\t");printf("2. Admin Login");
    printf("\n");
    printf("\t\t\t");printf("3. Exit");
    printf("\n");
    printf("\t\t\t");printf("Enter your choice: ");
    scanf("%d", &itemChoice);
    system("cls");
}


/*
============================================================================
FUNCTION : adminLogin
DESCRIPTION : Authenticates the admin and displays the admin menu if successful.
ARGUMENTS : None
RETURNS : void
===========================================================================
*/
adminLogin()
{
    char password[50];
    printf("\n");
    printf("\t\t\t");printf("Enter admin password: ");
    scanf("%s", password);
    system("cls");

    if (strcmp(password, PASSWORD) == 0)
        {
            printf("\t\t\t");printf("Welcome Admin");
            adminMenu();

    } else
    {
        printf("\t\t\t");printf("Invalid password!\n");
    }
}

void WelcomeScrn()
{
    printf("\t\t\t");printf("Welcome to Snack Shop!");
    printf("\n\n");
    printf("\t\t\t");printf("Press any key to continue.");
    printf("\n");
    getch();
    system("cls");
    return;
}
