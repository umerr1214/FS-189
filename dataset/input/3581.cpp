#include <iostream>

int main() {
    int num;
    std::cout << "Enter an integer: ";
    std::cin >> num;

    // Logical error: Zero is incorrectly classified as positive.
    if (num >= 0) { 
        std::cout << "Positive" << std::endl;
    } else { // This 'else' block will only be reached if num < 0
        std::cout << "Negative" << std::endl;
    }

    return 0;
}