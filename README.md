# CS0053-TN31-PersonalExpenseTracker_Ocasiones
A console-based C++ Personal Expense Tracker for CS0053-TN31.

## 1. Project Overview

The Personal Expense Tracker is a console-based C++ application designed to help users record, manage, and monitor their daily expenses.

## 2. Features

- Add Expense
- View Expenses
- Search Expense
- Update Expense
- Delete Expense
- Expense Summary
- Save and Load Expense Records

## 3. Technologies Used

- C++
- Visual Studio Code
- MinGW-w64 G++
- Git
- GitHub

## 4. Project Structure

- main.cpp
- Expense.h
- Expense.cpp
- FileManager.h
- FileManager.cpp
- Validation.h
- Validation.cpp
- expenses.txt 

## 5. Requirements

- Visual Studio Code or another C++ code editor
- MinGW-w64 G++ compiler
- Git

## 6. How to Compile

Open the terminal inside the project folder and enter:

```
g++ main.cpp Expense.cpp FileManager.cpp Validation.cpp -o expense_tracker
```

## 7. How to Run

```
.\expense_tracker.exe
```

## 8. Data Storage

Expense records are stored locally in expenses.txt.
The application loads saved records when it starts and saves changes made to expense records.

## 9. Group Members

- Member 1: [Ocasiones, James A.]

## 10. Course Information

Course: CS0053
Section: TN31
Project: Personal Expense Tracker
