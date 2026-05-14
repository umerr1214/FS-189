#include <iostream>

int main() {
    int num;
    do {
        std::cout << "Enter a positive integer: ";
        std::cin >> num; // Semantic Error: Does not handle non-integer input (e.g., "abc") gracefully.
                         // If std::cin fails, it enters a fail state, and subsequent extractions will also fail,
                         // leading to an infinite loop without clearing the error state or discarding bad input.
        if (num <= 0) {
            std::cout << "Invalid input. Please enter a positive integer." << std::endl;
        }
    } while (num <= 0);
    std::cout << "You entered: " << num << std::endl;
    return 0;
}