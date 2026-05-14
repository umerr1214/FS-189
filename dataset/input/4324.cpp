#include <iostream>

int main() {
    int score;
    std::cout << "Enter score (0-100): ";
    std::cin >> score // Syntax error: Missing semicolon

    if (score >= 60) {
        std::cout << "Pass" << std::endl;
    } else {
        std::cout << "Fail" << std::endl;
    }

    return 0;
}