#include <iostream>
#include <string> // Not strictly needed for this version, but good practice.

int main() {
    int score;
    std::cout << "Enter score: ";
    std::cin >> score;

    // Correct Version: Simple, direct, and efficient implementation.
    // Assumes valid input within the specified range (0-100) as per problem statement.
    if (score >= 60) {
        std::cout << "Pass" << std::endl;
    } else {
        std::cout << "Fail" << std::endl;
    }

    return 0;
}