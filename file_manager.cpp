#include "file_manager.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void saveExpenses(const vector<Expense>& expenses) {
    ofstream file("expenses.txt");

    if (!file.is_open()) {
        cout << "Error: Unable to save expense records.\n";
        return;
    }

    for (const Expense& expense : expenses) {
        file << expense.id << ","
             << expense.name << ","
             << expense.category << ","
             << expense.amount << ","
             << expense.date << "\n";
    }

    file.close();

    cout << "Expense records saved successfully.\n";
}

void loadExpenses(vector<Expense>& expenses) {
    ifstream file("expenses.txt");

    if (!file.is_open()) {
        cout << "No existing expense file found. Starting a new record.\n";
        return;
    }

    string line;

    while (getline(file, line)) {
        stringstream stream(line);
        string idText;
        string name;
        string category;
        string amountText;
        string date;

        if (!getline(stream, idText, ',')) {
            continue;
        }

        if (!getline(stream, name, ',')) {
            continue;
        }

        if (!getline(stream, category, ',')) {
            continue;
        }

        if (!getline(stream, amountText, ',')) {
            continue;
        }

        if (!getline(stream, date)) {
            continue;
        }

        try {
            Expense expense;

            expense.id = stoi(idText);
            expense.name = name;
            expense.category = category;
            expense.amount = stod(amountText);
            expense.date = date;

            expenses.push_back(expense);
        }
        catch (...) {
            cout << "Warning: A record could not be loaded.\n";
        }
    }

    file.close();

    cout << "Expense records loaded successfully.\n";
}
