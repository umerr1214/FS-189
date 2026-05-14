#include <iostream>

int main() {
    int num = 0; // Initialize to 0 to make behavior deterministic if input fails
    std::cout << "Enter an integer: ";
    std::cin >> num;

    // Robustness issue: Does not check if input was successful.
    // If user enters non-integer (e.g., "abc"), std::cin fails, num remains 0,
    // and the program incorrectly reports "The number is zero."
    // It also leaves the input stream in a fail state.

    if (num > 0) {
        std::cout << "The number is positive." << std::endl;
    } else if (num < 0) {
        std::cout << "The number is negative." << std::endl;
    } else { // This branch is incorrectly taken if non-integer input causes num to remain 0
        std::cout << "The number is zero." << std::endl;
    }

    return 0;
}