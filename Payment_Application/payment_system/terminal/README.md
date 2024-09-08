# Terminal Module

## Overview

The Terminal Module handles transaction data, including transaction amounts and dates. It validates card expiration dates and checks if transaction amounts are within allowable limits. This module works in conjunction with the Card Module to process and validate card transactions.

## Files

### 1. `terminal.h`

This header file defines the data structures, enumerations, and function declarations for managing terminal data.

#### Contents

- **Data Structures**
  - **`ST_terminalData_t`**: 
    - **Description**: Structure to store terminal transaction data.
    - **Members**:
      - `float transAmount`: The amount of the transaction.
      - `float maxTransAmount`: The maximum allowable transaction amount.
      - `float maxDepositAmount`: The maximum allowable deposit amount.
      - `uint8_t transactionDate[11]`: Array to store the transaction date in `DD/MM/YYYY` format.

- **Enumerations**
  - **`EN_terminalError_t`**: Enum for error codes related to terminal data validation.
    - **`TERMINAL_OK`**: Indicates successful validation.
    - **`WRONG_DATE`**: Indicates an error in retrieving or processing the date.
    - **`EXPIRED_CARD`**: Indicates that the card has expired.
    - **`INVALID_CARD`**: Indicates an invalid card.
    - **`INVALID_AMOUNT`**: Indicates an invalid transaction amount.
    - **`EXCEED_MAX_AMOUNT`**: Indicates that the transaction amount exceeds the maximum allowable amount.
    - **`INVALID_MAX_AMOUNT`**: Indicates an invalid maximum transaction amount.

- **Function Declarations**
  - **`void getTerminalData(ST_terminalData_t *termData)`**
    - **Description**: Initializes the `ST_terminalData_t` structure with default values.

  - **`EN_terminalError_t getTransactionDate(ST_terminalData_t *termData)`**
    - **Description**: Retrieves the current date and stores it in the `termData` structure in `DD/MM/YYYY` format.

  - **`EN_terminalError_t isCardExpired(ST_cardData_t *cardData, ST_terminalData_t* termData)`**
    - **Description**: Checks if the card is expired based on the current transaction date and the card's expiration date.
    - **Parameters**:
      - `cardData`: Pointer to the `ST_cardData_t` structure containing card expiration data.
      - `termData`: Pointer to the `ST_terminalData_t` structure containing the transaction date.

  - **`EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData)`**
    - **Description**: Prompts the user to input the transaction amount and stores it in the `termData` structure.
    - **Parameters**:
      - `termData`: Pointer to the `ST_terminalData_t` structure where the transaction amount will be stored.

  - **`EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData)`**
    - **Description**: Checks if the transaction amount is below the maximum allowable transaction amount.
    - **Parameters**:
      - `termData`: Pointer to the `ST_terminalData_t` structure containing the transaction amount and maximum transaction amount.

### 2. `terminal.c`

This file contains the implementation of functions declared in `terminal.h`.

#### Functions

- **`void getTerminalData(ST_terminalData_t *termData)`**
  - **Description**: Initializes the `ST_terminalData_t` structure with default values for maximum transaction and deposit amounts, and sets the transaction amount to 0.

- **`EN_terminalError_t getTransactionDate(ST_terminalData_t *termData)`**
  - **Description**: 
    - **Functionality**: Retrieves the current date and formats it as `DD/MM/YYYY`. Stores this date in the `transactionDate` field of the `termData` structure.
    - **Error Handling**: Returns `WRONG_DATE` if `termData` is `NULL`.

- **`EN_terminalError_t isCardExpired(ST_cardData_t *cardData, ST_terminalData_t* termData)`**
  - **Description**: 
    - **Functionality**: Compares the card's expiration date with the current transaction date to determine if the card is expired.
    - **Error Handling**: Returns `EXPIRED_CARD` if the card is expired.

- **`EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData)`**
  - **Description**: 
    - **Functionality**: Prompts the user to enter a transaction amount, validates that it is positive, and stores it in the `termData` structure.
    - **Error Handling**: Returns `INVALID_AMOUNT` if the transaction amount is not positive or `termData` is `NULL`.

- **`EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData)`**
  - **Description**: 
    - **Functionality**: Checks if the transaction amount is less than or equal to the maximum allowable transaction amount.
    - **Error Handling**: Returns `EXCEED_MAX_AMOUNT` if the transaction amount exceeds the maximum allowable amount or `termData` is `NULL`.
