#include <iostream>
#include <limits> // Required for std::numeric_limits

int main() {
    int num;
    bool isValidInput = false;

    do {
        std::cout << "Please enter an integer between 1 and 10: ";
        std::cin >> num;

        if (std::cin.fail()) {
            std::cout << "That's not an integer. Try again.\n"; // Slightly less precise error message
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            // Readability/Efficiency Issue: Using separate if statements for range checks
            // makes the code slightly more verbose and less concise than a single combined condition.
            if (num < 1) {
                std::cout << "The number is too low. It must be between 1 and 10.\n";
            } else if (num > 10) {
                std::cout << "The number is too high. It must be between 1 and 10.\n";
            } else {
                isValidInput = true;
            }
        }
    } while (!isValidInput);

    std::cout << "Thank you! You entered: " << num << "\n";
    return 0;
}