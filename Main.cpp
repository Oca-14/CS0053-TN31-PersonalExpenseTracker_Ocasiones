
#include <iostream>
#include <vector>

#include "Expense.h"
#include "file_manager.h"
#include "validation.h"

using namespace std;

int main() {
    vector<Expense> expenses;
    int choice;

    cout << "====================================\n";
    cout << "       PERSONAL EXPENSE TRACKER     \n";
    cout << "====================================\n";

    loadExpenses(expenses);

    do {
        cout << "\n========== MAIN MENU ==========\n";
        cout << "1. Add Expense\n";
        cout << "2. View Expenses\n";
        cout << "3. Search Expense\n";
        cout << "4. Update Expense\n";
        cout << "5. Delete Expense\n";
        cout << "6. Expense Summary\n";
        cout << "0. Exit\n";
        cout << "===============================\n";

        choice = readInt("Enter your choice: ");

        switch (choice) {
            case 1:
                addExpense(expenses);
                saveExpenses(expenses);
                break;

            case 2:
                viewExpenses(expenses);
                break;

            case 3:
                searchExpense(expenses);
                break;

            case 4:
                updateExpense(expenses);
                saveExpenses(expenses);
                break;

            case 5:
                deleteExpense(expenses);
                saveExpenses(expenses);
                break;

            case 6:
                showSummary(expenses);
                break;

            case 0:
                saveExpenses(expenses);
                cout << "\nThank you for using Personal Expense Tracker!\n";
                break;

            default:
                cout << "Invalid menu choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
