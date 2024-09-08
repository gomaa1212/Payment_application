# Menu Module

## Overview

The Menu Module provides the user interface for interacting with the payment application. It displays various options for users to choose from, such as transferring money, viewing transactions, and checking balance.

## Files

### 1. `menu.c`

This source file contains functions for displaying menus and capturing user choices.

#### Functions

- **`int menu()`**
  - **Description**: Displays the main menu options for the user and captures their choice.
  - **Options**:
    - `1` - Transfer Money
    - `2` - View Previous Transactions
    - `3` - View Balance
    - `4` - Deposit
    - `0` - Exit
  - **Returns**: The user's choice as an integer.

- **`int TransferMoneyMenu()`**
  - **Description**: Displays the money transfer options and captures the user's choice.
  - **Options**:
    - `1` - Transfer money to a bank account
    - `2` - Personal withdrawal
  - **Returns**: The user's choice as an integer.


