#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision

int main() {
    double value;
    std::cout << "Enter a monetary value: ";
    std::cin >> value; // Read the monetary value from the user

    // Syntax Error: Missing '<<' operator after std::fixed
    std::cout << "$" << std::fixed std::setprecision(2) << value << std::endl;

    return 0;
}