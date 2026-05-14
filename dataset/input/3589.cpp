#include <iostream>

int main() {
    std::cout << "Enter a day number (1-7): ";
    int dayNumber;
    std::cin >> dayNumber; // No check for cin.fail() or stream state

    switch (dayNumber) {
        case 1:
            std::cout << "Monday\n";
            break;
        case 2:
            std::cout << "Tuesday\n";
            break;
        case 3:
            std::cout << "Wednesday\n";
            break;
        case 4:
            std::cout << "Thursday\n";
            break;
        case 5:
            std::cout << "Friday\n";
            break;
        case 6:
            std::cout << "Saturday\n";
            break;
        case 7:
            std::cout << "Sunday\n";
            break;
        default:
            // This default message is generic for both out-of-range integers
            // and cases where std::cin failed to read an integer (e.g., "abc")
            // and dayNumber might be 0 or uninitialized.
            std::cout << "Invalid input.\n";
            break;
    }

    return 0;
}