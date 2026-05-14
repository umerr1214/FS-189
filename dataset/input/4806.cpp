#include <iostream>
#include <string>

int main() {
    char dayNumChar; // Semantic error: User expects to input an integer, but it's read as a character
    std::cout << "Enter a number (1-7) for the day of the week: " << std::endl;
    std::cin >> dayNumChar; // Reads character '1' (ASCII 49) if user types 1

    switch (dayNumChar) { // Switching on a char. Case labels are integer literals (1, 2, etc.)
        case 1: // This case label is int 1, which will not match char '1' (ASCII 49)
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
            std::cout << "Invalid day number." << std::endl; // This will likely be hit for valid inputs like '1'
            break;
    }

    return 0;
}