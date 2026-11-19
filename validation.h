#ifndef VALIDATION_H
#define VALIDATION_H

#include <string>

using namespace std;

int readInt(const string& prompt);
double readPositiveDouble(const string& prompt);
string readNonEmptyLine(const string& prompt);
bool isValidDate(const string& date);
string readValidDate(const string& prompt);

#endif
