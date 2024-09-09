# Payment Application

## Overview

The **Payment Application** is a comprehensive system designed to manage financial transactions, including money transfers, deposits, and transaction history tracking. The application allows users to perform various banking operations securely and efficiently.

## Features

- **Money Transfer:** Transfer funds between accounts, either to another bank account or for personal withdrawals.
- **View Previous Transactions:** Retrieve and display a history of past transactions for a given account.
- **View Balance:** Check the available balance in an account.
- **Deposit Funds:** Add money to an account while adhering to deposit limits.
- **Account Validation:** Verify account existence and status (active or blocked).
- **Transaction State Management:** Handle and record transaction outcomes such as approved, declined, or fraud.
  
## Components

- **Data Structures:** Utilizes lists and queues for managing account and transaction data.
- **File Handling:** Reads from and writes to files for storing account and transaction information.
- **Server Logic:** Validates transactions, checks account status, and manages transaction records.
- **Menu System:** Offers a menu-driven interface for users to choose operations such as transferring money, viewing transactions, checking balance, or making deposits.

## User Choices and Actions

### 1. Transfer Money

**Action:**
- The application first prompts the user to choose between two options:
  - **1**: Transfer money to a bank account.
  - **2**: Personal withdrawal.

- **Transfer to a Bank Account:**
  - The user is prompted to enter the recipient’s account number and the transaction amount.
  - The recipient’s account is validated to ensure it exists and is not blocked.
  - The application checks if there are sufficient funds available for the transfer.
  - If all validations pass, the application updates the balances of both the sender and recipient accounts.
  - The transaction details are saved in the transaction records.
  - The user is notified if the transaction is approved or declined due to reasons such as insufficient funds, a blocked account, or exceeding limits.

- **Personal Withdrawal:**
  - The user is prompted to enter the amount they wish to withdraw.
  - The application checks if the withdrawal amount does not exceed the maximum allowed limit.
  - If valid, the amount is subtracted from the user's account balance, and the balance is updated accordingly.
  - The transaction details are saved in the transaction records.
  - The user is notified if the withdrawal was successful or if it exceeded the allowed limit.

**Processing:**
- If all validations pass, the application updates the balances of both the sender and recipient accounts.
- The transaction details are saved in the transaction records.

**Feedback:**
- The user is notified if the transaction is approved or declined. Reasons for decline may include insufficient funds, a blocked account, or exceeding limits.

### 2. View Previous Transactions

**Action:**
- The application retrieves and displays a list of past transactions associated with the user’s card.

**Details:**
- Each transaction displays information such as the transaction date, amount, state (approved or declined), and other relevant details.

**Feedback:**
- If no previous transactions are found, the user is informed that there are no transactions available.

### 3. View Balance

**Action:**
- The application displays the current balance of the user’s account.

**Details:**
- The balance is presented in a formatted manner for clarity.

**Feedback:**
- The user is provided with their available balance.

### 4. Deposit

**Action:**
- The application prompts the user to enter the deposit amount.

**Validation:**
- It checks that the deposit amount does not exceed the maximum allowed deposit limit.

**Processing:**
- If the deposit amount is valid, it is added to the user’s account balance.
- The account balance is updated accordingly.

**Feedback:**
- The user is informed whether the deposit was successful or if it exceeded the allowed limit.

### 0. Exit

**Action:**
- The application terminates and exits the program.

**Feedback:**
- The user receives a thank you message for using the service, and the program ends.

### Invalid Choice

**Action:**
- If the user enters an option not listed in the menu, the application displays an error message.

**Feedback:**
- The user is prompted to select a valid option from the menu.

## Post-Action Options

After completing an action, the user is asked if they wish to return to the main menu or exit the application. The choices are:
- **1**: Return to the menu for another operation.
- **0**: Exit the application.

