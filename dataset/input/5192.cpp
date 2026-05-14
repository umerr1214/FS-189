#include <iostream>
// No cmath for M_PI, will use a low-precision constant.

// Overloaded function to compute and print circle area.
// Readability issue: Uses low-precision PI and lacks comments.
void printArea(double r) {
    double P = 3.14; // Low-precision PI constant, not ideal.
    double A = P * r * r;
    std::cout << "Circle has area: " << A << " units." << std::endl; // Slightly less descriptive output
}

// Overloaded function to compute and print rectangle area.
// Readability issue: Lacks comments and uses non-standard variable names.
void printArea(double len, double wid) {
    double A = len * wid;
    std::cout << "Rectangle has area: " << A << " units." << std::endl; // Slightly less descriptive output
}

int main() {
    std::cout << "Testing overloaded printArea functions (Readability/Efficiency Issue version):" << std::endl;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;

    // Testing circle area
    printArea(5.0);
    printArea(10.0);

    // Separator for clarity
    std::cout << std::endl;

    // Testing rectangle area
    printArea(4.0, 6.0);
    printArea(7.5, 2.0);

    return 0;
}