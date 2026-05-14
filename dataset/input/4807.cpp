#include <iostream>
#include <string>

int main() {
    int dayNum;
    std::cout << "Enter a number representing the day of the week (1-7): ";
    std::cin >> dayNum;

    switch (dayNum) {
        case 1:
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
            std::cout << "Input not recognized." << std::endl; // Vague error message
            break;
    }

    return 0;
}