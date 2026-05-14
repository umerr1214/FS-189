#include <iostream>
#include <limits> // For numeric_limits
#include <ios>    // For streamsize

int main() {
    int num;
    do {
        std::cout << "Enter a positive integer: " // Syntax Error: Missing semicolon
        while (!(std::cin >> num)) {
            std::cout << "Invalid input. Please enter an integer: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if (num <= 0) {
            std::cout << "Input must be a positive integer. Try again.\n";
        }
    } while (num <= 0);
    std::cout << "You entered: " << num << "\n";
    return 0;
}