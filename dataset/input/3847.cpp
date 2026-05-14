#include <iostream>

int main() {
    int num;
    bool isValid = false;
    do {
        std::cout << "Enter an integer between 1 and 10: ";
        std::cin >> num;

        // Robustness Issue: This code does NOT handle non-integer input robustly.
        // If non-integer input (e.g., "abc") is given, std::cin will go into a fail state,
        // and the loop will become infinite because std::cin >> num will always fail
        // and not extract new input, and std::cin.fail() will always be true.
        // It's missing std::cin.clear() and std::cin.ignore().
        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter an integer.\n";
            // Missing: std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (num >= 1 && num <= 10) {
            isValid = true;
        } else {
            std::cout << "Input out of range. Please enter a number between 1 and 10.\n";
        }
    } while (!isValid);

    std::cout << "You entered a valid number: " << num << "\n";
    return 0;
}