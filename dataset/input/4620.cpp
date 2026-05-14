#include <iostream>

// Semantic Error: The function is declared to return 'int' instead of 'bool'.
// While C++ allows implicit conversion from int (0/1) to bool (false/true),
// the problem statement semantically expects a boolean return type for clarity and type safety.
int isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 1; // True
            } else {
                return 0; // False
            }
        } else {
            return 1; // True
        }
    } else {
        return 0; // False
    }
}

int main() {
    // The driver in the JSON will call the isLeapYear function.
    // This main function is just a placeholder to make it a complete C++ file.
    std::cout << "This program has a semantic error related to return type." << std::endl;
    return 0;
}