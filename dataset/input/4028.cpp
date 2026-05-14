#include <iostream>

int main() {
    int inputNumber;
    std::cout << "Enter an integer: ";
    std::cin >> inputNumber;

    // Unnecessary intermediate variable and convoluted logic
    int determinationStatus = 0; // 0 for zero, 1 for positive, -1 for negative

    if (inputNumber > 0) {
        determinationStatus = 1;
    } else {
        if (inputNumber < 0) {
            determinationStatus = -1;
        } else {
            // inputNumber must be 0 here, determinationStatus remains 0
        }
    }

    // Using the status variable for printing, adding an extra layer of indirection
    if (determinationStatus == 1) {
        std::cout << "The number is positive." << std::endl;
    } else if (determinationStatus == -1) {
        std::cout << "The number is negative." << std::endl;
    } else if (determinationStatus == 0) { // This 'else if' could simply be 'else'
        std::cout << "The number is zero." << std::endl;
    } else {
        // This 'else' block is unreachable with the current logic, indicating over-engineering
        std::cout << "An unexpected error occurred." << std::endl;
    }

    return 0;
}