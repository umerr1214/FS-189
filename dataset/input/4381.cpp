#include <iostream>
#include <string>

// Core logic for the program
void solve() {
    int option;

    // Ask the user to choose an option
    std::cout << "Choose an option (1 for 'Square', 2 for 'Circle', 3 for 'Triangle'): ";
    
    // Read the user's input
    std::cin >> option;

    // Use a switch statement to print the chosen shape's name
    // This version lacks a default case and robust input validation.
    switch (option) {
        case 1:
            std::cout << "Square\n";
            break;
        case 2:
            std::cout << "Circle\n";
            break;
        case 3:
            std::cout << "Triangle\n";
            break;
        // No default case to handle invalid numbers or non-integer input gracefully.
    }
}

int main() {
    solve();
    return 0;
}