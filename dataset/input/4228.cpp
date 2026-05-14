#include <iostream>

int main() {
    int num;
    do {
        std::cout << "Enter a positive integer: ";
        std::cin >> num;
        if (num <= 0) {
            std::cout << "Invalid input. Please enter a positive integer." << std::endl;
        }
    } while (num <= 0) // Syntax Error: Missing semicolon after the do-while condition
    std::cout << "You entered: " << num << std::endl;
    return 0;
}