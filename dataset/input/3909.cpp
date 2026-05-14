#include <iostream>
#include <limits> // Required for std::numeric_limits

int main() {
    int dayNumber;
    bool isValidInput = false;

    // Loop until valid input is received
    while (!isValidInput) {
        std::cout << "Enter an integer between 1 and 7 (1 for Monday, 7 for Sunday): ";
        std::cin >> dayNumber;

        if (std::cin.fail()) {
            // Handle non-numerical input
            std::cout << "Invalid input. Please enter a numerical value.\n";
            std::cin.clear(); // Clear the error flag
            // Discard all remaining characters in the input buffer up to the newline
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (dayNumber < 1 || dayNumber > 7) {
            // Handle numerical input outside the valid range
            std::cout << "Invalid input. The number must be between 1 and 7.\n";
            // For out-of-range numerical input, cin state is fine, no need to clear/ignore.
        } else {
            // Valid input received
            isValidInput = true;
        }
    }

    // Use a switch statement to print the corresponding day of the week
    switch (dayNumber) {
        case 1:
            std::cout << "Monday\n";
            break;
        case 2:
            std::cout << "Tuesday\n";
            break;
        case 3:
            std::cout << "Wednesday\n";
            break;
        case 4:
            std::cout << "Thursday\n";
            break;
        case 5:
            std::cout << "Friday\n";
            break;
        case 6:
            std::cout << "Saturday\n";
            break;
        case 7:
            std::cout << "Sunday\n";
            break;
        // A default case is not strictly necessary here because the input validation
        // loop ensures 'dayNumber' will always be between 1 and 7.
    }

    return 0;
}