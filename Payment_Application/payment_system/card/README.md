# Card Module

## Overview

This card module is designed to handle and validate credit card data. It includes functionality for entering and validating cardholder names, card expiration dates, and Primary Account Numbers (PAN). This application is intended for educational purposes and demonstrates basic input handling and validation.

## Files

### 1. `card.cpp`

This file contains the implementation of functions related to handling and validating card data.

#### Functions

- **`void getcard(ST_cardData_t *cardData)`**
  - **Description**: Initializes the `ST_cardData_t` structure by clearing its fields. It sets the cardholder name, primary account number, and card expiration date to empty strings.
  - **Parameters**: 
    - `cardData`: A pointer to the `ST_cardData_t` structure to be initialized.

- **`EN_cardError_t getCardHolderName(ST_cardData_t *cardData)`**
  - **Description**: Prompts the user to enter the cardholder's name, validates its length, and stores it in the `cardData` structure.
  - **Parameters**:
    - `cardData`: A pointer to the `ST_cardData_t` structure where the cardholder name will be stored.
  - **Returns**: An `EN_cardError_t` value indicating the success or failure of the operation (`WRONG_NAME` or `CARD_OK`).

- **`EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData)`**
  - **Description**: Prompts the user to enter the card expiration date in `MM/YY` format, validates the format, and stores it in the `cardData` structure.
  - **Parameters**:
    - `cardData`: A pointer to the `ST_cardData_t` structure where the expiration date will be stored.
  - **Returns**: An `EN_cardError_t` value indicating the success or failure of the operation (`WRONG_EXP_DATE` or `CARD_OK`).

- **`EN_cardError_t getCardPAN(ST_cardData_t *cardData)`**
  - **Description**: Prompts the user to enter the Primary Account Number (PAN), validates its length and numeric content, and stores it in the `cardData` structure.
  - **Parameters**:
    - `cardData`: A pointer to the `ST_cardData_t` structure where the PAN will be stored.
  - **Returns**: An `EN_cardError_t` value indicating the success or failure of the operation (`WRONG_PAN` or `CARD_OK`).

### 2. `card.h`

This header file declares the functions and data structures related to card data handling.

#### Contents

- **Function Declarations**: For `getcard`, `getCardHolderName`, `getCardExpiryDate`, and `getCardPAN`.
- **Data Structures**: Definition of `ST_cardData_t` and error codes (`EN_cardError_t`).
