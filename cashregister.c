/*
============================================================================
FILE : cashregister.c
AUTHOR : Noiznor
DESCRIPTION : Implementation of the admin menu for the Snack Shop vending machine.
COPYRIGHT : 2024-02-05
REVISION HISTORY
Date: By: Description:
============================================================================
*/

#include "vending.h"

/*
============================================================================
FUNCTION : showMoney
DESCRIPTION : Displays the current balance of the vending machine.
ARGUMENTS : None
RETURNS : void
===========================================================================
*/
void showMoney()
{
    printf("\t\t\t");printf("Vending Machine Balance: [$%d]\n", money);
    printf("\n");
}

/*
============================================================================
FUNCTION : adminMenu
DESCRIPTION : Displays the admin menu and processes the admin's choice.
ARGUMENTS : None
RETURNS : void
===========================================================================
*/
void adminMenu()
{
    printf("\n\n");
    printf("\t\t\t[1]. Manage Stock\n");
    printf("\n\n");
    printf("\t\t\t[2]. Log Out\n");
    scanf("%d", &choice);
    system("cls");

    switch(choice)
    {
        case 1:
            manageStock(); // Call new function for stock management
            break;
        case 2:
            printf("\n");
            printf("\t\t\t");printf("Logging Out...\n");
            fflush(stdout);  // Ensure message is displayed immediately
            sleep(1);
            system("cls");
            mainMenu();
            return; //
    }
}
