#include <iostream>
#include <limits> // Required for std::numeric_limits

int main() {
    int num;
    do {
        std::cout << "Enter an integer between 1 and 10 (inclusive): " // Syntax Error: Missing semicolon
        std::cin >> num;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter an integer.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
        } else if (num < 1 || num > 10) {
            std::cout << "Input out of range. Please enter a number between 1 and 10.\n";
        }
    } while (num < 1 || num > 10 || std::cin.fail());
    std::cout << "You entered: " << num << ". Valid input!\n";
    return 0;
}