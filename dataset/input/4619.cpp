#include <iostream>

bool isLeapYear(int year) {
    // Logical Error: Incorrectly handles years divisible by 400.
    // It checks if divisible by 4 AND not by 100.
    // This logic fails for years like 2000 or 2400 which are divisible by 100
    // but are also divisible by 400 (and thus are leap years).
    // The correct logic should be: (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
    return (year % 4 == 0 && year % 100 != 0);
}

int main() {
    // The driver in the JSON will call the isLeapYear function.
    // This main function is just a placeholder to make it a complete C++ file.
    std::cout << "This program has a logical error." << std::endl;
    return 0;
}