#include <iostream>

int main() {
    // Semantic error: Using unsigned int for a problem that requires checking for negative numbers.
    // unsigned int cannot represent negative values, making the 'num < 0' condition semantically incorrect
    // and always false (or evaluating based on wrap-around behavior if assigned a negative literal,
    // but typically it means negative numbers are not representable).
    unsigned int num; 
    std::cout << "Enter an integer: ";
    std::cin >> num;

    if (num > 0) {
        std::cout << "Positive" << std::endl;
    } else if (num < 0) { // This condition will always be false for an unsigned int
        std::cout << "Negative" << std::endl;
    } else { // This 'else' will catch num == 0
        std::cout << "Zero" << std::endl;
    }

    return 0;
}