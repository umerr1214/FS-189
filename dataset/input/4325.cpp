#include <iostream>

int main() {
    int score;
    std::cout << "Enter score (0-100): ";
    std::cin >> score;

    // Logical error: The condition for 'Pass' and 'Fail' is reversed.
    // It prints 'Pass' for scores below 60 and 'Fail' for scores 60 or above.
    if (score < 60) { 
        std::cout << "Pass" << std::endl;
    } else {
        std::cout << "Fail" << std::endl;
    }

    return 0;
}