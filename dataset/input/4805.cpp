#include <iostream>
#include <string>

int main() {
    int dayNum;
    std::cout << "Enter a number (1-7) for the day of the week: " << std::endl;
    std::cin >> dayNum;

    switch (dayNum) {
        case 1:
            std::cout << "Tuesday" << std::endl; // Logical error: should be Monday
            break;
        case 2:
            std::cout << "Wednesday" << std::endl; // Logical error: should be Tuesday
            break;
        case 3:
            std::cout << "Thursday" << std::endl; // Logical error: should be Wednesday
            break;
        case 4:
            std::cout << "Friday" << std::endl; // Logical error: should be Thursday
            break;
        case 5:
            std::cout << "Saturday" << std::endl; // Logical error: should be Friday
            break;
        case 6:
            std::cout << "Sunday" << std::endl; // Logical error: should be Saturday
            break;
        case 7:
            std::cout << "Monday" << std::endl; // Logical error: should be Sunday
            break;
        default:
            std::cout << "Invalid day number." << std::endl;
            break;
    }

    return 0;
}