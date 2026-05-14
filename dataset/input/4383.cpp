#include <iostream> // Required for input/output operations
#include <string>   // Required for string manipulation
#include <limits>   // Required for std::numeric_limits
#include <ios>      // Required for std::streamsize

// Core logic for the program to be tested
void solve() {
    int choice; // Descriptive variable name for user's choice

    // Loop until valid input is received
    while (true) {
        // Ask the user to choose an option
        std::cout << "Choose an option (1 for 'Square', 2 for 'Circle', 3 for 'Triangle'): ";
        
        // Attempt to read the user's input
        std::cin >> choice;

        // Check if the input operation failed (e.g., non-integer input)
        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear(); // Clear the error flag
            // Discard the rest of the invalid input line
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            // Input was a number, now check if it's within the valid range
            // Discard any remaining characters on the line after the number
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break; // Valid number received, exit the loop
        }
    }

    // Use a switch statement to print the chosen shape's name
    switch (choice) {
        case 1:
            std::cout << "Square\n";
            break;
        case 2:
            std::cout << "Circle\n";
            break;
        case 3:
            std::cout << "Triangle\n";
            break;
        default:
            // Handle cases where the number is valid but not 1, 2, or 3
            std::cout << "Invalid option. Please choose 1, 2, or 3.\n";
            break;
    }
}

int main() {
    // Call the core logic function
    solve();
    return 0;
}