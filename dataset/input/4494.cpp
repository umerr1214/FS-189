#include <iostream>

int main() {
    const int num; // Semantic error: 'const' variable 'num' must be initialized.
                   // Even if initialized, std::cin >> num would be an error.
    std::cout << "Enter an integer: ";
    std::cin >> num; // Semantic error: Attempting to modify a 'const' variable.

    if (num > 0) {
        std::cout << "The number is positive." << std::endl;
    } else if (num < 0) {
        std::cout << "The number is negative." << std::endl;
    } else {
        std::cout << "The number is zero." << std::endl;
    }

    return 0;
}