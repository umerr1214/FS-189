#include <iostream>

int main() {
    std::cout << "Kindly enter a numeric value for the day (from 1 to 7): " << std::endl; // Verbose prompt, uses std::endl
    int dayNumber;
    std::cin >> dayNumber; // Assumes valid integer input, no explicit error handling for non-numeric

    switch (dayNumber) {
        case 1:
            std::cout << "The selected day is indeed Monday." << std::endl; // Verbose output, uses std::endl
            break;
        case 2:
            std::cout << "The selected day is indeed Tuesday." << std::endl;
            break;
        case 3:
            std::cout << "The selected day is indeed Wednesday." << std::endl;
            break;
        case 4:
            std::cout << "The selected day is indeed Thursday." << std::endl;
            break;
        case 5:
            std::cout << "The selected day is indeed Friday." << std::endl;
            break;
        case 6:
            std::cout << "The selected day is indeed Saturday." << std::endl;
            break;
        case 7:
            std::cout << "The selected day is indeed Sunday." << std::endl;
            break;
        default:
            std::cout << "Regrettably, the provided day number is outside the acceptable range of 1 to 7." << std::endl; // Verbose default
            break;
    }

    return 0;
}