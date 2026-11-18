
#include "Expense.h"
#include "Validation.h"

#include <iostream>
#include <iomanip>

using namespace std;

void addExpense(vector<Expense>& expenses) {
    Expense newExpense;

    int nextId = 1;

    for (const Expense& expense : expenses) {
        if (expense.id >= nextId) {
            nextId = expense.id + 1;
        }
    }

    newExpense.id = nextId;

    cout << "\n===== ADD EXPENSE =====\n";

    newExpense.name = readNonEmptyLine("Enter expense name: ");
    newExpense.category = readNonEmptyLine("Enter category: ");
    newExpense.amount = readPositiveDouble("Enter amount: ");
    newExpense.date = readNonEmptyLine("Enter date (YYYY-MM-DD): ");

    expenses.push_back(newExpense);

    cout << "\nExpense added successfully!\n";
    cout << "Assigned Expense ID: " << newExpense.id << "\n";
}

void viewExpenses(const vector<Expense>& expenses) {
    cout << "\n===== ALL EXPENSES =====\n";

    if (expenses.empty()) {
        cout << "No expense records found.\n";
        return;
    }

    cout << left
         << setw(8) << "ID"
         << setw(20) << "Name"
         << setw(18) << "Category"
         << setw(12) << "Amount"
         << setw(15) << "Date" << "\n";

    cout << string(73, '-') << "\n";

    for (const Expense& expense : expenses) {
        cout << left
             << setw(8) << expense.id
             << setw(20) << expense.name
             << setw(18) << expense.category
             << fixed << setprecision(2)
             << setw(12) << expense.amount
             << setw(15) << expense.date << "\n";
    }
}

void searchExpense(const vector<Expense>& expenses) {
    cout << "\n===== SEARCH EXPENSE =====\n";

    if (expenses.empty()) {
        cout << "No expense records available.\n";
        return;
    }

    int searchId = readInt("Enter Expense ID: ");

    for (const Expense& expense : expenses) {
        if (expense.id == searchId) {
            cout << "\nExpense found!\n";
            cout << "ID: " << expense.id << "\n";
            cout << "Name: " << expense.name << "\n";
            cout << "Category: " << expense.category << "\n";
            cout << "Amount: " << fixed << setprecision(2)
                 << expense.amount << "\n";
            cout << "Date: " << expense.date << "\n";
            return;
        }
    }

    cout << "Expense not found.\n";
}

void updateExpense(vector<Expense>& expenses) {
    cout << "\n===== UPDATE EXPENSE =====\n";

    if (expenses.empty()) {
        cout << "No expense records available.\n";
        return;
    }

    int updateId = readInt("Enter Expense ID to update: ");

    for (Expense& expense : expenses) {
        if (expense.id == updateId) {
            cout << "\nEnter the new information.\n";

            expense.name = readNonEmptyLine("Enter new name: ");
            expense.category = readNonEmptyLine("Enter new category: ");
            expense.amount = readPositiveDouble("Enter new amount: ");
            expense.date = readNonEmptyLine("Enter new date (YYYY-MM-DD): ");

            cout << "\nExpense updated successfully!\n";
            return;
        }
    }

    cout << "Expense not found.\n";
}

void deleteExpense(vector<Expense>& expenses) {
    cout << "\n===== DELETE EXPENSE =====\n";

    if (expenses.empty()) {
        cout << "No expense records available.\n";
        return;
    }

    int deleteId = readInt("Enter Expense ID to delete: ");

    for (size_t i = 0; i < expenses.size(); i++) {
        if (expenses[i].id == deleteId) {
            expenses.erase(expenses.begin() + i);

            cout << "Expense deleted successfully!\n";
            return;
        }
    }

    cout << "Expense not found.\n";
}

void showSummary(const vector<Expense>& expenses) {
    cout << "\n===== EXPENSE SUMMARY =====\n";

    if (expenses.empty()) {
        cout << "No expense records available.\n";
        return;
    }

    double total = 0;

    for (const Expense& expense : expenses) {
        total += expense.amount;
    }

    cout << "Total number of expenses: "
         << expenses.size() << "\n";

    cout << "Total expenses: PHP "
         << fixed << setprecision(2) << total << "\n";
}
