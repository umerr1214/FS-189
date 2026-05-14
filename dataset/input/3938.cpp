#include <iostream>
#include <limits> // Required for std::numeric_limits

int main() {
    int number;
    bool isValidInput = false; // This flag adds a slight indirection to the loop condition

    do {
        std::cout << "Please enter a positive integer now: "; // Slightly verbose prompt
        std::cin >> number;

        if (std::cin.fail()) {
            std::cout << "Error: That wasn't an integer. Let's try this again.\n"; // More verbose error message
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            isValidInput = false; // Explicitly setting the flag
        } else if (number <= 0) {
            std::cout << "Reminder: The number must be positive. Input a new value.\n"; // More verbose error message
            isValidInput = false; // Explicitly setting the flag
        } else {
            isValidInput = true; // Explicitly setting the flag for valid input
        }
    } while (!isValidInput); // The condition uses a boolean flag, which is less direct than checking conditions directly

    std::cout << "Successfully received positive integer: " << number << std::endl;

    return 0;
}