# Card Module

## Overview

This module contains definitions and implementations for handling and validating credit card data. It includes structures and functions for managing cardholder information, expiration dates, and Primary Account Numbers (PAN).

## Files

### 1. `card.h`

This header file declares the data structures and functions used in the card module.

#### Contents

- **Data Structures**
  - **`ST_cardData_t`**: 
    - **Description**: Structure to store card data.
    - **Members**:
      - `uint8_t cardHolderName[25]`: Array to hold the cardholder's name (maximum length 24 characters plus null terminator).
      - `uint8_t primaryAccountNumber[20]`: Array to hold the PAN (maximum length 19 characters plus null terminator).
      - `uint8_t cardExpirationDate[6]`: Array to hold the card expiration date in `MM/YY` format (5 characters plus null terminator).

- **Enumerations**
  - **`EN_cardError_t`**: Enum for error codes related to card data validation.
    - **`CARD_OK`**: Indicates successful validation.
    - **`WRONG_NAME`**: Indicates an invalid cardholder name.
    - **`WRONG_EXP_DATE`**: Indicates an invalid card expiration date.
    - **`WRONG_PAN`**: Indicates an invalid PAN.

- **Function Declarations**
  - **`void getcard(ST_cardData_t *cardData)`**
    - **Description**: Initializes the `ST_cardData_t` structure by clearing its fields.

  - **`EN_cardError_t getCardHolderName(ST_cardData_t *cardData)`**
    - **Description**: Prompts the user to input the cardholder's name, validates the length, and stores it in the `cardData` structure.

  - **`EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData)`**
    - **Description**: Prompts the user to input the card expiration date, validates the format, and stores it in the `cardData` structure.

  - **`EN_cardError_t getCardPAN(ST_cardData_t *cardData)`**
    - **Description**: Prompts the user to input the PAN, validates the length and numeric content, and stores it in the `cardData` structure.

### 2. `card.cpp`

This file implements the functions declared in `card.h`.

#### Functions

- **`void getcard(ST_cardData_t *cardData)`**
  - **Description**: Clears the fields in the `ST_cardData_t` structure by setting them to empty strings.

- **`EN_cardError_t getCardHolderName(ST_cardData_t *cardData)`**
  - **Description**: 
    - **Functionality**: Prompts the user for the cardholder's name, validates its length, and stores it in `cardData`.
    - **Validation**: Ensures the length of the name is between 20 and 24 characters.
    - **Error Handling**: Returns `WRONG_NAME` if validation fails.

- **`EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData)`**
  - **Description**: 
    - **Functionality**: Prompts the user for the card expiration date, validates its format, and stores it in `cardData`.
    - **Validation**: Ensures the format is `MM/YY` and that the length is exactly 5 characters.
    - **Error Handling**: Returns `WRONG_EXP_DATE` if validation fails.

- **`EN_cardError_t getCardPAN(ST_cardData_t *cardData)`**
  - **Description**: 
    - **Functionality**: Prompts the user for the PAN, validates its length and numeric content, and stores it in `cardData`.
    - **Validation**: Ensures the PAN is between 16 and 19 characters long and contains only digits.
    - **Error Handling**: Returns `WRONG_PAN` if validation fails.
