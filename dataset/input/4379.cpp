#include <iostream>
#include <string>

int main() {
    int choice;
    std::cout << "Enter your choice (1-3): ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            std::cout << "You chose Square.\n";
            // Logical Error: Missing break; will cause fall-through to case 2
        case 2:
            std::cout << "You chose Circle.\n";
            // Logical Error: Missing break; will cause fall-through to case 3
        case 3:
            std::cout << "You chose Triangle.\n";
            break;
        default:
            std::cout << "Invalid choice.\n";
            break;
    }

    return 0;
}