#include <iostream>
#include <string>

int main() {
    int day;
    std::cout << "Enter an integer between 1 and 7: " << std::endl;
    std::cin >> day;

    switch (day) {
        case 1:
            std::cout << "Monday" << std::endl;
            // Logical Error: Missing break statement, causing fall-through
        case 2:
            std::cout << "Tuesday" << std::endl;
            // Logical Error: Missing break statement, causing fall-through
        case 3:
            std::cout << "Wednesday" << std::endl;
            // Logical Error: Missing break statement, causing fall-through
        case 4:
            std::cout << "Thursday" << std::endl;
            // Logical Error: Missing break statement, causing fall-through
        case 5:
            std::cout << "Friday" << std::endl;
            // Logical Error: Missing break statement, causing fall-through
        case 6:
            std::cout << "Saturday" << std::endl;
            // Logical Error: Missing break statement, causing fall-through
        case 7:
            std::cout << "Sunday" << std::endl;
            break; // This is the only break for the valid day cases
        default:
            std::cout << "Invalid input. Please enter a number between 1 and 7." << std::endl;
            break;
    }

    return 0;
}