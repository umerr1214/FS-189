#include <iostream>
// #include <string> // Not strictly needed for this problem's current implementation

int main() {
    char day_char; // Semantic Error: Declared as char instead of int
    std::cout << "Enter an integer between 1 and 7 (as a character, e.g., '1'): " << std::endl;
    std::cin >> day_char;

    // The switch statement compares 'day_char' (e.g., ASCII 49 for '1')
    // with integer literals (e.g., 1). This will never match for '1'-'7'.
    switch (day_char) {
        case 1: // This compares day_char with integer 1, not character '1' (ASCII 49)
            std::cout << "Monday" << std::endl;
            break;
        case 2:
            std::cout << "Tuesday" << std::endl;
            break;
        case 3:
            std::cout << "Wednesday" << std::endl;
            break;
        case 4:
            std::cout << "Thursday" << std::endl;
            break;
        case 5:
            std::cout << "Friday" << std::endl;
            break;
        case 6:
            std::cout << "Saturday" << std::endl;
            break;
        case 7:
            std::cout << "Sunday" << std::endl;
            break;
        default:
            std::cout << "Invalid input. Please enter a number between 1 and 7." << std::endl;
            break;
    }

    return 0;
}