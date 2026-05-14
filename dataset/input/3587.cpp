#include <iostream>
#include <string>

int main() {
    int day;
    std::cout << "Enter a day number (1-7): ";
    std::cin >> day;

    switch (day) {
        case 1:
            std::cout << "Monday\n";
            // Missing break; statement, causing fall-through
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
            std::cout << "Invalid day number\n";
            break;
    }

    return 0;
}