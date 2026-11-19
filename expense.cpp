#include "Expense.h"
#include "Validation.h"

#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

void addExpense(vector<Expense>& expenses) {
    Expense newExpense;

   int newID = 1;

    while (true) {
        bool idExists = false;

        for (const Expense& expense : expenses) {
            if (expense.id == newID) {
                idExists = true;
                break;
            }
        }

        if (!idExists) {
            break;
        }

        newID++;
    }

    newExpense.id = newID;

    cout << "\n===== ADD EXPENSE =====\n";

    newExpense.name = readNonEmptyLine("Enter expense name: ");
    newExpense.category = readNonEmptyLine("Enter category: ");
    newExpense.amount = readPositiveDouble("Enter amount: ");
    newExpense.date = readValidDate("Enter date (YYYY-MM-DD): ");

    expenses.push_back(newExpense);

    cout << "\nExpense added successfully!\n";
    cout << "Assigned Expense ID: " << newExpense.id << "\n";
}

void viewExpenses(const vector<Expense>& expenses) {
    if (expenses.empty()) {
        cout << "\nNo expenses found.\n";
        return;
    }

    vector<Expense> sortedExpenses = expenses;

    sort(sortedExpenses.begin(), sortedExpenses.end(),
         [](const Expense& a, const Expense& b) {
             return a.id < b.id;
         });

    cout << "\n==================== EXPENSE RECORDS ====================\n";
    cout << left << setw(5) << "ID"
         << setw(20) << "Name"
         << setw(15) << "Category"
         << setw(12) << "Amount"
         << setw(12) << "Date" << "\n";
    cout << "---------------------------------------------------------\n";

    for (const Expense& expense : sortedExpenses) {
        cout << left << setw(5) << expense.id
             << setw(20) << expense.name
             << setw(15) << expense.category
             << setw(12) << fixed << setprecision(2) << expense.amount
             << setw(12) << expense.date << "\n";
    }
    cout << "=========================================================\n";
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
            expense.date = readValidDate("Enter date (YYYY-MM-DD): ");

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
