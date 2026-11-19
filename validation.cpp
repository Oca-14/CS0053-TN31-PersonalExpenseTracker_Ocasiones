#include "Validation.h"

#include <iostream>
#include <sstream>
#include <cctype>

using namespace std;

int readInt(const string& prompt) {
    string input;
    int value;
    stringstream stream;

    while (true) {
        cout << prompt;
        getline(cin, input);

        stream.clear();
        stream.str(input);

        if (stream >> value) {
            stream >> ws;

            if (stream.eof()) {
                return value;
            }
        }

        cout << "Invalid input. Please enter a whole number.\n";
    }
}

double readPositiveDouble(const string& prompt) {
    string input;
    double value;
    stringstream stream;

    while (true) {
        cout << prompt;
        getline(cin, input);

        stream.clear();
        stream.str(input);

        if (stream >> value) {
            stream >> ws;

            if (stream.eof() && value > 0) {
                return value;
            }
        }

        cout << "Invalid amount. Enter a number greater than zero.\n";
    }
}

string readNonEmptyLine(const string& prompt) {
    string input;

    while (true) {
        cout << prompt;
        getline(cin, input);

        if (input.find_first_not_of(" \t") != string::npos) {
            return input;
        }

        cout << "This field cannot be empty. Please try again.\n";
    }
}

bool isValidDate(const string& date) {
    if (date.length() != 10) {
        return false;
    }

    if (date[4] != '-' || date[7] != '-') {
        return false;
    }

    for (int i = 0; i < 10; i++) {
        if (i != 4 && i != 7 && !isdigit(date[i])) {
            return false;
        }
    }

    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));

    if (year < 1 || month < 1 || month > 12) {
        return false;
    }

    int daysInMonth[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    bool leapYear = (year % 400 == 0) ||
                    (year % 4 == 0 && year % 100 != 0);

    if (leapYear) {
        daysInMonth[1] = 29;
    }

    if (day < 1 || day > daysInMonth[month - 1]) {
        return false;
    }

    return true;
}

string readValidDate(const string& prompt) {
    string date;

    while (true) {
        date = readNonEmptyLine(prompt);

        if (isValidDate(date)) {
            return date;
        }

        cout << "Invalid date. Use YYYY-MM-DD format.\n";
    }
}