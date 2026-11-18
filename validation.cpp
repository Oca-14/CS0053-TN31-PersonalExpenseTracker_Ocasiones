
#include "Validation.h"

#include <iostream>
#include <sstream>

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
