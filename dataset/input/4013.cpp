#include <iostream>

template <typename T>
T findMax(T a, T b) {
    // Logical Error: This function incorrectly returns the smaller of the two values.
    return (a < b) ? a : b;
}

int main() {
    // Demonstrate with int
    int int1 = 10;
    int int2 = 5;
    std::cout << "Max of " << int1 << " and " << int2 << " is: " << findMax(int1, int2) << std::endl; // Expected: 10, Actual: 5

    // Demonstrate with double
    double double1 = 3.14;
    double double2 = 2.71;
    std::cout << "Max of " << double1 << " and " << double2 << " is: " << findMax(double1, double2) << std::endl; // Expected: 3.14, Actual: 2.71

    // Demonstrate with char
    char char1 = 'X'; // ASCII 88
    char char2 = 'A'; // ASCII 65
    std::cout << "Max of '" << char1 << "' and '" << char2 << "' is: " << findMax(char1, char2) << std::endl; // Expected: X, Actual: A

    return 0;
}