#include <iostream>
#include <limits> // Required for numeric_limits

int main() {
    int choice;
    do {
        // Display menu
        std::cout << "--- Menu ---\n";
        std::cout << "1. Say Hello\n";
        std::cout << "2. Say Goodbye\n"
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";

        // Get user choice
        std::cin >> choice;

        // Input validation for non-integer input
        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear(); // Clear the error flag
            // Ignore remaining characters in the input buffer up to the newline
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            choice = 0; // Set choice to an invalid value to continue loop
            continue;
        }

        // Process choice
        switch (choice) {
            case 1:
                std::cout << "Say Hello!\n";
                break;
            case 2:
                std::cout << "Say Goodbye!\n";
                break;
            case 3:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
        std::cout << "\n"; // Newline for better readability between menu displays
    } while (choice != 3);

    return 0;
}