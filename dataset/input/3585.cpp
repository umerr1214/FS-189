#include <iostream>
#include <string>

int main() {
    int num;
    std::cout << "Enter an integer: ";
    std::cin >> num;

    // Correct implementation using if-else if-else statements
    if (num > 0) {
        std::cout << "The number is positive." << std::endl;
    } else if (num < 0) {
        std::cout << "The number is negative." << std::endl;
    } else { // If not positive and not negative, it must be zero
        std::cout << "The number is zero." << std::endl;
    }

    return 0;
}