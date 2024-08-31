#include "application.h"
#include "../menu/menu.h"
#include <stdlib.h>

// Function to gather transaction data
void app(ST_transaction_t *transData) {
    // Get card details from the user
    getcard(&transData->cardHolderData);

    // Validate cardholder name
    EN_cardError_t nameError = getCardHolderName(&transData->cardHolderData);
    if (nameError == WRONG_NAME) {
        printf("Incorrect name! Come back soon.\n");
        return;
    }

    // Validate card expiration date
    EN_cardError_t cardDateError = getCardExpiryDate(&transData->cardHolderData);
    if (cardDateError == WRONG_EXP_DATE) {
        printf("Incorrect date! Come back soon.\n");
        return;
    }

    // Validate card number (PAN)
    EN_cardError_t cardNumError = getCardPAN(&transData->cardHolderData);
    if (cardNumError == WRONG_PAN) {
        printf("Incorrect card number! Come back soon.\n");
        return;
    }

    // Validate account existence
    ST_accountsDB_t *accountReference = NULL;
    EN_serverError_t accountFound = isValidAccount(&transData->cardHolderData, &accountReference);
    if (accountFound == ACCOUNT_NOT_FOUND) {
        printf("Declined: Invalid account!\n");
        return;
    }

    // Check if the account is blocked
    EN_serverError_t blockedAccount = isBlockedAccount(accountReference);
    if (blockedAccount == BLOCKED_ACCOUNT) {
        printf("Declined: Blocked account.\n");
        return;
    }

    // Get terminal and transaction data
    getTerminalData(&transData->terminalData);
    getTransactionDate(&transData->terminalData);

    // Check if the card is expired
    EN_terminalError_t cardExpiredError = isCardExpired(&transData->cardHolderData, &transData->terminalData);
    if (cardExpiredError == EXPIRED_CARD) {
        printf("Declined: Expired card!\n");
        return;
    }

    // Welcome message
    printf("===================================================================\n");
    printf("          Welcome : %s\n", transData->cardHolderData.cardHolderName);
    printf("===================================================================\n");

    int choice, next;
    do {
        // Display menu and get user choice
        choice = menu();

        // Handle user choices
        switch (choice) {
            case 1:
                handleMoneyTransfer(transData, accountReference);
                break;
            case 2:
                listSavedTransactions(transData);
                break;
            case 3:
                printf("===============================================\n");
                printf("        Available balance: %.2f\n", accountReference->balance);
                printf("===============================================\n");
                break;
            case 4:
                handleMoneyDeposit(transData,accountReference);
                break;
            case 0:
                printf("Thank you for using our service. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
                break;
        }

        if(choice==0)
        {
            break;
        }
        // Ask if the user wants to return to the menu or exit
        printf("Press 1 to return to the menu, or 0 to exit: ");
        scanf("%d", &next);
        if (next == 0) {
            printf("Thank you for using our service. Goodbye!\n");
            break;
        }

    } while (choice != 0 && next != 0);
}






