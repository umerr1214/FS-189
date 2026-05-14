#include <iostream>

int main() {
    int num;
    do {
        std::cout << "Enter an integer between 1 and 10 (inclusive): ";
        std::cin >> num;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter an integer.\n";
            std::cin.clear(); // Semantic Error: Clears the error flag, but not the bad input from the buffer.
            // Missing std::cin.ignore() or equivalent to clear the input buffer.
            // This will cause an infinite loop if non-integer input is provided,
            // as std::cin will continuously fail on the same bad input.
        } else if (num < 1 || num > 10) {
            std::cout << "Input out of range. Please enter a number between 1 and 10.\n";
        }
    } while (num < 1 || num > 10 || std::cin.fail());
    std::cout << "You entered: " << num << ". Valid input!\n";
    return 0;
}