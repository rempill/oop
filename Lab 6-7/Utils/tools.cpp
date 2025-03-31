//
// Created by Mihai on 30.03.2025.
//

#include "tools.h"

int getValidatedInt(const string& prompt) {
    int value;
    cout << prompt;
    while (!(cin >> value)) {
        cout << "Invalid input. Please enter a valid integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return value;
}

float getValidatedFloat(const string& prompt) {
    float value;
    cout << prompt;
    while (!(cin >> value)) {
        cout << "Invalid input. Please enter a valid float: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return value;
}