#include <iostream>
#include <string>
#include <limits> // Required for numeric_limits

// The core logic of the program, wrapped in a function for testing purposes.
void user_solution_logic() {
    int score;
    std::cout << "Enter a numeric score (0-100): ";
    std::cin >> score;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a numeric score." << std::endl;
        return;
    }

    if (score < 0 || score > 100) {
        std::cout << "Score must be between 0 and 100." << std::endl;
        return;
    }

    char grade;
    // Readability/Efficiency Issue: Redundant checks in conditions.
    // The upper bound check (e.g., 'score <= 100' or 'score <= 89') is redundant
    // because the input is already validated to be within 0-100, and the 'else if'
    // structure inherently handles the upper bounds from previous conditions.
    if (score >= 90 && score <= 100) { 
        grade = 'A';
    } else if (score >= 80 && score <= 89) {
        grade = 'B';
    } else if (score >= 70 && score <= 79) {
        grade = 'C';
    } else if (score >= 60 && score <= 69) {
        grade = 'D';
    } else { // score < 60
        grade = 'F';
    }

    std::cout << grade << std::endl;
}

int main() {
    user_solution_logic();
    return 0;
}