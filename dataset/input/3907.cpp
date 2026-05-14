#include <iostream>
#include <limits> // Required for std::numeric_limits

int main() {
    int dayNum;

    while (true) {
        std::cout << "Enter an integer between 1 and 7: ";
        std::cin >> dayNum;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear(); // Clears the error flag, but leaves invalid characters in the buffer.
            // Robustness Issue: Missing std::cin.ignore() here.
            // If non-numeric input is entered, this will lead to an infinite loop
            // as the same invalid input is re-read repeatedly.
        } else if (dayNum < 1 || dayNum > 7) {
            std::cout << "Invalid input. Please enter a number between 1 and 7.\n";
        } else {
            break; // Valid input received
        }
    }

    switch (dayNum) {
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
            // This default should ideally not be reached due to the while loop validation.
            std::cout << "Error: Unexpected value.\n";
            break;
    }

    return 0;
}