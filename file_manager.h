
#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Expense.h"

#include <vector>
#include <string>

using namespace std;

void saveExpenses(const vector<Expense>& expenses);
void loadExpenses(vector<Expense>& expenses);

#endif
