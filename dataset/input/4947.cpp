#include <iostream>
#include <limits> // Required for std::numeric_limits

int user_main() {
    int limit;
    // Input validation loop for robustness
    while (true) {
        std::cout << "Enter a positive integer limit: ";
        std::cin >> limit;

        if (std::cin.fail()) { // Handles non-numeric input
            std::cout << "Invalid input. Please enter an integer." << std::endl;
            std::cin.clear(); // Clear error flags
            // Discard invalid input from buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        } else if (limit <= 0) { // Enforces "positive integer" requirement
            std::cout << "Limit must be a positive integer. Please try again." << std::endl;
        } else {
            // Valid input received
            break; 
        }
    }

    long long sumOfEvens = 0; // Descriptive variable name for readability
    // Efficient iteration: starts at 2 and increments by 2
    for (int i = 2; i <= limit; i += 2) {
        sumOfEvens += i;
    }

    std::cout << "The sum of even numbers up to " << limit << " is: " << sumOfEvens << std::endl;

    return 0;
}