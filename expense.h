
#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>
#include <vector>

using namespace std;

struct Expense {
    int id;
    string name;
    string category;
    double amount;
    string date;
};

void addExpense(vector<Expense>& expenses);
void viewExpenses(const vector<Expense>& expenses);
void searchExpense(const vector<Expense>& expenses);
void updateExpense(vector<Expense>& expenses);
void deleteExpense(vector<Expense>& expenses);
void showSummary(const vector<Expense>& expenses);

#endif
