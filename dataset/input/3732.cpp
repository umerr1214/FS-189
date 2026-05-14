#include <iostream>

int main() {
    unsigned int number; // Semantic error: Using unsigned int for a number that can be negative
    std::cout << "Enter an integer: ";
    std::cin >> number;

    if (number > 0) {
        std::cout << number << " is a positive number." << std::endl;
    } else if (number < 0) { // This condition will always be false for an unsigned int
        std::cout << number << " is a negative number." << std::endl;
    } else {
        std::cout << "The number is zero." << std::endl;
    }

    return 0;
}