#include <iostream>
#include <limits> // Required for std::numeric_limits

int main() {
    int num;
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
        }

    } while (num >= 1 && num <= 10); // LOGICAL ERROR: The loop continues as long as input is VALID.
                                    // It should continue as long as input is INVALID.
                                    // This causes an infinite loop for valid inputs (e.g., 5).
                                    // It exits for invalid inputs (e.g., 0), which is incorrect.

    // This line will only be reached if the loop exited, meaning the last input was invalid.
    // Thus, it will print an invalid number, or the initial uninitialized value if the first input was invalid.
    std::cout << "You entered: " << num << "\n"; 

    return 0;
}