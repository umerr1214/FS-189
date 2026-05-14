#include <iostream>

int main() {
    int score;
    std::cout << "Enter score: ";
    std::cin >> score;

    char grade; // 'grade' is declared but not initialized

    if (score >= 90 && score <= 100) {
        grade = 'A';
    } else if (score >= 80 && score <= 89) {
        grade = 'B';
    } else if (score >= 70 && score <= 79) {
        grade = 'C';
    } else if (score >= 60 && score <= 69) {
        grade = 'D';
    } else if (score >= 0 && score <= 59) {
        grade = 'F';
    }
    // Semantic Error: If 'score' is outside the 0-100 range (e.g., 101 or -5),
    // 'grade' will remain uninitialized. Using an uninitialized local variable
    // leads to undefined behavior when printed.

    std::cout << "Grade: " << grade << std::endl; // Potential use of uninitialized 'grade'

    return 0;
}