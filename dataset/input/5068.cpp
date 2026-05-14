#include <iostream>

// Function containing the core logic
void run_grading_logic() {
    int score;
    std::cout << "Enter student's score (0-100): ";
    std::cin >> score;

    if (score >= 90 && score <= 100) {
        std::cout << "Grade: A" // SYNTAX ERROR: Missing semicolon
    } else if (score >= 80 && score <= 89) {
        std::cout << "Grade: B" << std::endl;
    } else if (score >= 70 && score <= 79) {
        std::cout << "Grade: C" << std::endl;
    } else if (score >= 60 && score <= 69) {
        std::cout << "Grade: D" << std::endl;
    } else if (score >= 0 && score <= 59) {
        std::cout << "Grade: F" << std::endl;
    } else {
        std::cout << "Invalid score." << std::endl;
    }
}

int main() {
    run_grading_logic();
    return 0;
}