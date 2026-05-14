#include <iostream>

int main() {
    int opt; // Poor variable name
    do {
        // Redundant menu display logic
        std::cout << "Menu:\n";
        std::cout << "1. Say Hello\n"; // Magic number 1
        std::cout << "2. Say Goodbye\n"; // Magic number 2
        std::cout << "3. Exit\n"; // Magic number 3
        std::cout << "Your selection: "; // Less descriptive prompt
        std::cin >> opt;

        if (std::cin.fail()) { // Basic input validation, but could be cleaner
            std::cout << "That's not a number! Try again.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n'); // Arbitrary large number for ignore
            opt = 0; // Set to an invalid option to re-display menu
        } else {
            switch (opt) {
                case 1:
                    std::cout << "Hello there!\n";
                    break;
                case 2:
                    std::cout << "Farewell!\n";
                    break;
                case 3:
                    std::cout << "Quitting program.\n";
                    break;
                default:
                    std::cout << "Invalid input. Please enter 1, 2, or 3.\n"; // Slightly redundant message
                    break;
            }
        }
        std::cout << "\n";
    } while (opt != 3); // Magic number 3

    return 0;
}