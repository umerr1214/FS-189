#include <iostream>

// Syntax Error: Missing 'template <typename T>' keyword for the function template
T findMax(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    // Demonstrate with int
    int int1 = 10;
    int int2 = 5;
    std::cout << "Max of " << int1 << " and " << int2 << " is: " << findMax(int1, int2) << std::endl;

    // Demonstrate with double
    double double1 = 3.14;
    double double2 = 2.71;
    std::cout << "Max of " << double1 << " and " << double2 << " is: " << findMax(double1, double2) << std::endl;

    // Demonstrate with char
    char char1 = 'X';
    char char2 = 'A';
    std::cout << "Max of '" << char1 << "' and '" << char2 << "' is: " << findMax(char1, char2) << std::endl;

    return 0;
}