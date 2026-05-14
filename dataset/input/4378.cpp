#include <iostream>
#include <string>

int main() {
    int choice;
    std::cout << "Enter your choice (1-3): " // Syntax Error: Missing semicolon
    std::cin >> choice;

    switch (choice) {
        case 1:
            std::cout << "You chose Square.\n";
            break;
        case 2:
            std::cout << "You chose Circle.\n";
            break;
        case 3:
            std::cout << "You chose Triangle.\n";
            break;
        default:
            std::cout << "Invalid choice.\n";
            break;
    }

    return 0;
}