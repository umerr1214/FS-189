#include <iostream>
#include <limits> // Required for std::numeric_limits

int main() {
    int num // SYNTAX ERROR: Missing semicolon here
    do {
        std::cout << "Please enter a number between 1 and 10 (inclusive):\n";
        std::cin >> num;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please try again.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (num < 1 || num > 10) {
            std::cout << "Invalid input. Please try again.\n";
            // For out-of-range numeric input, cin is not in a fail state.
            // No need to clear/ignore here for stream state recovery.
        }

    } while (num < 1 || num > 10 || std::cin.fail()); // Loop until valid number AND successful read

    std::cout << "You entered: " << num << "\n";

    return 0;
}