#include <iostream>
#include <limits> // Required for std::numeric_limits

int main() {
    int num = 0; // Initialize to ensure loop starts and num has a defined value
    do {
        std::cout << "Please enter a number between 1 and 10 (inclusive):\n";
        std::cin >> num;

        // SEMANTIC ERROR: Fails to clear error state and ignore buffer for non-numeric input
        if (std::cin.fail()) {
            std::cout << "Invalid input. Please try again.\n";
            // Missing: std::cin.clear();
            // Missing: std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            // Without these lines, std::cin remains in a failed state.
            // The `std::cin.fail()` in the while condition will perpetually be true,
            // leading to an infinite loop for non-numeric input.
        } else if (num < 1 || num > 10) {
            std::cout << "Invalid input. Please try again.\n";
            // For out-of-range numeric input, cin is not in a fail state,
            // so clear/ignore is not needed for stream state, but could be for remaining line content.
            // The primary semantic error is the lack of stream recovery for `cin.fail()`.
        }

    } while (num < 1 || num > 10 || std::cin.fail()); // Loop until valid number AND successful read

    std::cout << "You entered: " << num << "\n";

    return 0;
}