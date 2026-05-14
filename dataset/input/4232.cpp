#include <iostream>
#include <limits> // Required for std::numeric_limits

int user_main() {
    int user_value;
    bool input_ok = false; // Readability/Efficiency Issue: This boolean flag is redundant.
                           // The loop condition could directly check 'user_value > 0'
                           // after input and validation.

    do {
        std::cout << "Kindly enter a positive whole number: ";

        if (!(std::cin >> user_value)) {
            std::cout << "Invalid character input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            input_ok = false; // Explicitly set to false, which is correct but redundant given the loop condition.
            // A 'continue' statement here could also make the flow slightly cleaner, but the current structure works.
        } else {
            if (user_value > 0) {
                input_ok = true; // Set flag to true if valid.
            } else {
                std::cout << "The number must be greater than zero. Please retry.\n";
                input_ok = false; // Explicitly set to false, also somewhat redundant.
            }
        }
    } while (!input_ok); // The loop condition relies on the redundant flag.

    std::cout << "You successfully entered: " << user_value << ".\n";
    return 0;
}