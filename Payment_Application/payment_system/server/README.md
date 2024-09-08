# Server Module

## Overview

The Server Module handles the core business logic for transaction processing and account management. It includes functions for validating accounts, managing transactions, and updating account balances.

## Files

### 1. `server.h`

This header file declares the data structures, enumerations, and function prototypes used in the server module.

#### Data Structures

- **`EN_transState_t`**: Enumeration for transaction states.
  - `APPROVED`
  - `DECLINED_INSUFFECIENT_FUND`
  - `DECLINED_STOLEN_CARD`
  - `FRAUD_CARD`
  - `INTERNAL_SERVER_ERROR`
  - `DECLINED_EXCEED_LIMIT`

- **`ST_transaction_t`**: Structure for transaction data.
  - `ST_cardData_t cardHolderData`
  - `ST_terminalData_t terminalData`
  - `EN_transState_t transState`
  - `uint32_t transactionSequenceNumber`

- **`EN_serverError_t`**: Enumeration for server errors.
  - `SERVER_OK`
  - `SAVING_FAILED`
  - `TRANSACTION_NOT_FOUND`
  - `ACCOUNT_NOT_FOUND`
  - `LOW_BALANCE`
  - `BLOCKED_ACCOUNT`

- **`EN_accountState_t`**: Enumeration for account states.
  - `BLOCKED`
  - `RUNNING`

- **`ST_accountsDB_t`**: Structure for account data.
  - `float balance`
  - `EN_accountState_t state`
  - `uint8_t primaryAccountNumber[20]`
  - `uint8_t AccountName[25]`
  - `uint8_t AccountDate[6]`

#### Function Prototypes

- **`EN_serverError_t isValidAccount(ST_cardData_t *cardData, ST_accountsDB_t** accountRefrence)`**
  - Validates account details based on card data.

- **`EN_serverError_t isValidAccountReceiver(ST_cardData_t *cardData, ST_accountsDB_t** accountRefrence)`**
  - Validates the receiving account details.

- **`EN_serverError_t isBlockedAccount(ST_accountsDB_t *accountRefrence)`**
  - Checks if the account is blocked.

- **`EN_serverError_t isAmountAvailable(ST_terminalData_t *termData, ST_accountsDB_t* accountRefrence)`**
  - Checks if sufficient funds are available in the account.

- **`void listSavedTransactions(ST_transaction_t *transData)`**
  - Lists saved transactions for a specific card.

- **`EN_transState_t getTransactionStateToenum(char *strstate)`**
  - Converts a transaction state string to its corresponding enum value.

- **`char *getTransactionStateTostring(EN_transState_t enumstate)`**
  - Converts a transaction state enum value to its corresponding string.

- **`EN_accountState_t getAccountStateToenum(char *strstate)`**
  - Converts an account state string to its corresponding enum value.

- **`char *getAccountStateTostring(EN_accountState_t enumstate)`**
  - Converts an account state enum value to its corresponding string.

- **`void handleMoneyTransfer(ST_transaction_t *transData, ST_accountsDB_t *accountReference)`**
  - Handles the process of transferring money from one account to another.

- **`void handleMoneyDeposit(ST_transaction_t *transData, ST_accountsDB_t *accountReference)`**
  - Handles the process of depositing money into an account.

### 2. `server.c`

This file contains the implementation of the functions declared in `server.h`. It performs the core server-side operations related to transactions and account management.

#### Functions

- **`EN_serverError_t isValidAccount(ST_cardData_t *cardData, ST_accountsDB_t** accountRefrence)`**
  - **Description**: Validates account details by checking the provided card data against the account database.
  - **Error Handling**: Returns `ACCOUNT_NOT_FOUND` if the account is not found.

- **`EN_serverError_t isValidAccountReceiver(ST_cardData_t *cardData, ST_accountsDB_t** accountRefrence)`**
  - **Description**: Validates the receiving account by checking the card data.
  - **Error Handling**: Returns `ACCOUNT_NOT_FOUND` if the receiving account is not found.

- **`EN_serverError_t isBlockedAccount(ST_accountsDB_t *accountRefrence)`**
  - **Description**: Checks if the account is blocked.
  - **Error Handling**: Returns `ACCOUNT_NOT_FOUND` if the account reference is null.

- **`EN_serverError_t isAmountAvailable(ST_terminalData_t *termData, ST_accountsDB_t* accountRefrence)`**
  - **Description**: Checks if sufficient funds are available for the transaction.
  - **Error Handling**: Returns `LOW_BALANCE` if the funds are insufficient.

- **`void listSavedTransactions(ST_transaction_t *transData)`**
  - **Description**: Lists all transactions for the specified card.
  - **Error Handling**: Displays a message if no transactions are found.

- **`EN_transState_t getTransactionStateToenum(char *strstate)`**
  - **Description**: Converts a transaction state string to its corresponding enum value.
  - **Error Handling**: Defaults to `INTERNAL_SERVER_ERROR` if the string does not match any known state.

- **`char *getTransactionStateTostring(EN_transState_t enumstate)`**
  - **Description**: Converts a transaction state enum value to its corresponding string.

- **`EN_accountState_t getAccountStateToenum(char *strstate)`**
  - **Description**: Converts an account state string to its corresponding enum value.

- **`char *getAccountStateTostring(EN_accountState_t enumstate)`**
  - **Description**: Converts an account state enum value to its corresponding string.

- **`void handleMoneyTransfer(ST_transaction_t *transData, ST_accountsDB_t *accountReference)`**
  - **Description**: Manages the process of transferring money from one account to another, including validation and updates.

- **`void handleMoneyDeposit(ST_transaction_t *transData, ST_accountsDB_t *accountReference)`**
  - **Description**: Manages the process of depositing money into an account, including validation and updates.


