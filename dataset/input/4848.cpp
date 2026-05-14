#include <iostream>
#include <limits> // Required for numeric_limits

int main() {
    char choice_char; // Declared as char
    int choice_int; // For comparison with numeric limits

    do {
        // Display menu
        std::cout << "--- Menu ---\n";
        std::cout << "1. Say Hello\n";
        std::cout << "2. Say Goodbye\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";

        // Get user choice as char
        std::cin >> choice_char;

        // Input validation for non-integer input (if char input fails, it's usually EOF or stream error)
        if (std::cin.fail()) {
            std::cout << "Input error. Exiting.\n";
            choice_char = '3'; // Force exit
            continue;
        }

        // Convert char to int for logical comparison, though the semantic error is in the switch
        // This line is added to handle potential non-digit char inputs more robustly,
        // but the core semantic error for '1', '2', '3' remains in the switch.
        if (choice_char >= '1' && choice_char <= '3') {
            choice_int = choice_char - '0';
        } else {
            choice_int = 0; // Treat as invalid
        }
        
        // Process choice
        // Semantic Error: 'choice_char' holds ASCII value, comparing it with integer literals 1, 2, 3
        switch (choice_char) {
            case 1: // This compares ASCII value of choice_char with integer 1 (not ASCII '1')
                std::cout << "Say Hello!\n";
                break;
            case 2: // Compares ASCII value with integer 2
                std::cout << "Say Goodbye!\n";
                break;
            case 3: // Compares ASCII value with integer 3
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
        std::cout << "\n"; // Newline for better readability between menu displays
    } while (choice_char != '3'); // Loop condition correctly checks for char '3'

    return 0;
}