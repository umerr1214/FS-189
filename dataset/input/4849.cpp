#include <iostream>

int main() {
    int choice;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Say Hello\n";
        std::cout << "2. Say Goodbye\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice; // Robustness issue: no input validation, no error handling for non-integer input

        switch (choice) {
            case 1:
                std::cout << "Hello!\n";
                break;
            case 2:
                std::cout << "Goodbye!\n";
                break;
            case 3:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
        std::cout << "\n"; // Add a newline for better readability between menu displays
    } while (choice != 3);

    return 0;
}