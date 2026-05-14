#include <iostream>
#include <limits> // Required for std::numeric_limits

int main() {
    int num;
    do {
        std::cout << "Enter a positive integer: ";
        std::cin >> num;
        // Semantic Error: No input validation for non-integer input.
        // If the user enters non-integer data, std::cin will enter a fail state.
        // Without clearing the error state and ignoring the bad input,
        // std::cin will continuously fail on subsequent attempts, leading to an infinite loop.
    } while (num <= 0);
    std::cout << "You entered: " << num << std::endl;
    return 0;
}