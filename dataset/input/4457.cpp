#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision

int main() {
    double value;
    std::cout << "Enter a monetary value: ";
    std::cin >> value; // Read the monetary value from the user

    // Logical Error: std::fixed is missing.
    // std::setprecision(2) without std::fixed sets the total number of significant digits,
    // not the number of digits after the decimal point.
    std::cout << "$" << std::setprecision(2) << value << std::endl;

    return 0;
}