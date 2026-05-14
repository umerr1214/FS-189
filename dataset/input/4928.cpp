#include <iostream>
#include <string>

// This version is functionally correct but has a readability issue due to a less direct
// and slightly more nested if-else structure than necessary for this simple problem.
// A direct if-else if-else chain would be clearer and more conventional.
void solve() {
    int num;
    std::cout << "Enter an integer: ";
    std::cin >> num;

    // Basic input validation, but the primary issue is structure.
    if (std::cin.fail()) {
        std::cout << "Invalid input. Please enter an integer." << std::endl;
        return;
    }

    if (num == 0) {
        std::cout << "Zero" << std::endl;
    } else { // If not zero, it must be either positive or negative
        if (num > 0) {
            std::cout << "Positive" << std::endl;
        } else { // If not zero and not positive, it must be negative
            std::cout << "Negative" << std::endl;
        }
    }
}