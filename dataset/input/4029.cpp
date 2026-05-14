#include <iostream>
#include <limits> // Required for std::numeric_limits

int main() {
    int number;
    std::cout << "Enter an integer: ";

    // Robust input validation loop
    while (!(std::cin >> number)) {
        std::cout << "Invalid input. Please enter an integer: ";
        std::cin.clear(); // Clear the error flags on std::cin
        // Discard invalid input from the buffer up to the newline character
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    if (number > 0) {
        std::cout << "The number is positive." << std::endl;
    } else if (number < 0) {
        std::cout << "The number is negative." << std::endl;
    } else { // number must be 0
        std::cout << "The number is zero." << std::endl;
    }

    return 0;
}