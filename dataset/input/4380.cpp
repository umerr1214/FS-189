#include <iostream>
#include <string>

int main() {
    float choice; // Semantic Error: 'switch' statement requires an integral type.
                  // Using float here violates the semantic rule of the switch construct.
    std::cout << "Enter your choice (1-3): ";
    std::cin >> choice;

    // This switch statement will cause a compilation error because 'choice' is a float.
    // Additionally, case labels must be integral constant expressions.
    switch (choice) {
        case 1.0f: // Semantic Error: Case labels must be integral constants.
            std::cout << "You chose Square.\n";
            break;
        case 2.0f:
            std::cout << "You chose Circle.\n";
            break;
        case 3.0f:
            std::cout << "You chose Triangle.\n";
            break;
        default:
            std::cout << "Invalid choice.\n";
            break;
    }

    return 0;
}