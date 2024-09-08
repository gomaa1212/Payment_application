# File Handling Module

## Overview

The File Handling Module is responsible for reading and writing account and transaction data to and from text files. It supports operations such as loading account data from a file, updating account balances, reading transaction data, and appending new transactions.

## Files

### 1. `file_handling.h`

This header file declares the data structures, constants, and function prototypes related to file operations for account and transaction data.

#### Contents

- **Constants**
  - **`FILEACOUNTNAME`**: Defines the filename for account data storage (`"accounts.txt"`).
  - **`FILETRANSACTIONNAME`**: Defines the filename for transaction data storage (`"transaction.txt"`).

- **Global Variables**
  - **`extern queu transActionQueue`**: Queue for managing transaction data.
  - **`extern List accounstList`**: List for managing account data.
  - **`extern int lastSeqNum`**: Keeps track of the last transaction sequence number.

- **Function Prototypes**
  - **`void readAccountDataDB()`**
    - **Description**: Reads account data from the `accounts.txt` file and populates `accounstList`.

  - **`void readTransactionData()`**
    - **Description**: Reads transaction data from the `transaction.txt` file and populates `transActionQueue`.

  - **`void appendtransactioncardData(ST_transaction_t *transData)`**
    - **Description**: Appends a new transaction to the `transaction.txt` file.

  - **`int updateAccountBalane()`**
    - **Description**: Updates the `accounts.txt` file with the latest account data from `accounstList`.

### 2. `file_handling.c`

This file contains the implementation of the functions declared in `file_handling.h`. It handles reading from and writing to files related to account and transaction data.

#### Functions

- **`void readAccountDataDB()`**
  - **Description**: 
    - **Functionality**: Opens the `accounts.txt` file, reads account data, and populates `accounstList`.
    - **Error Handling**: Prints an error message if the file cannot be opened.

- **`int updateAccountBalane()`**
  - **Description**: 
    - **Functionality**: Opens the `accounts.txt` file for writing and updates it with the current account data from `accounstList`.
    - **Error Handling**: Prints an error message if the file cannot be opened.

- **`void readTransactionData()`**
  - **Description**: 
    - **Functionality**: Opens the `transaction.txt` file, reads transaction data, and populates `transActionQueue`. Updates `lastSeqNum` with the most recent transaction sequence number.
    - **Error Handling**: Prints an error message if the file cannot be opened.

- **`void appendtransactioncardData(ST_transaction_t *transData)`**
  - **Description**: 
    - **Functionality**: Appends a new transaction to the `transaction.txt` file.
    - **Error Handling**: Prints an error message if the file cannot be opened.


