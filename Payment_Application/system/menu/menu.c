#include "menu.h"

// Display main menu options
int menu() {
    int choice;
    printf("===================================\n");
    printf("Please choose an option:\n");
    printf("1 - Transfer Money\n");
    printf("2 - View Previous Transactions\n");
    printf("3 - View Balance\n");
    printf("4 - Deposit\n");
    printf("0 - Exit\n");
    printf("===================================\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Display money transfer options
int TransferMoneyMenu() {
    int choice;
    printf("===========================================\n");
    printf("Please choose an option:\n");
    printf("1 - Transfer money to a bank account.\n");
    printf("2 - Personal withdrawal.\n");
    printf("===========================================\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}
