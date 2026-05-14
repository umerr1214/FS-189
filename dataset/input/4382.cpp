#include <iostream>
#include <string>
#include <limits> // Required for numeric_limits

// Core logic for the program
void solve() {
    int o; // Cryptic variable name for option

    // Ask the user to choose an option
    std::cout << "Choose an option (1 for 'Square', 2 for 'Circle', 3 for 'Triangle'): ";
    
    // Read the user's input
    std::cin >> o;

    // Check for input failure (non-numeric input)
    if (std::cin.fail()) {
        std::cin.clear(); // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        std::cout << "Invalid input. Please enter a number.\n";
        return; // Exit after first invalid non-numeric input
    }

    // Use a switch statement to print the chosen shape's name
    switch (o) { // Inconsistent indentation for switch
        case 1:
            std::cout << "Square\n";
        break;
        case 2:
            std::cout << "Circle\n";
            break; // Bad indentation here
        case 3:
            std::cout << "Triangle\n";
            break;
        default: // Default case is present but overall readability is poor
            std::cout << "Invalid option chosen.\n";
            break;
    }
}

int main() {
    solve();
    return 0;
}