#include <iostream>
#include <limits> // Required for std::numeric_limits

int main() {
    int num;
    do {
        std::cout << "Enter an integer between 1 and 10 (inclusive): ";
        std::cin >> num;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter an integer.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
        } else if (num < 1 || num > 10) {
            std::cout << "Input out of range. Please enter a number between 1 and 10.\n";
        }
    } while (num >= 1 && num <= 10); // Logical Error: Loop continues as long as input is VALID.
                                     // It should continue if input is INVALID.
    std::cout << "You entered: " << num << ". Valid input!\n"; // This will actually print the first *invalid* input after a valid one.
    return 0;
}