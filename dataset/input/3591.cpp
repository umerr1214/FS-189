#include <iostream>
#include <limits> // Required for std::numeric_limits

int main() {
    std::cout << "Enter a day number (1-7): ";
    int dayNumber;

    // Robust input validation: Check if input operation failed (e.g., non-integer input)
    if (!(std::cin >> dayNumber)) {
        std::cout << "Invalid input. Please enter a valid integer.\n";
        std::cin.clear(); // Clear error flags
        // Discard invalid input from the buffer until a newline character is found
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 1; // Indicate an error
    }

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
        default:
            // Specific error message for out-of-range integer input
            std::cout << "Invalid day number. Please enter a number between 1 and 7.\n";
            break;
    }

    return 0;
}