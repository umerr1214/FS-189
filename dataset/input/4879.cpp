#include <iostream>
#include <string>
#include <limits> // Required for numeric_limits

// The core logic of the program, wrapped in a function for testing purposes.
void user_solution_logic() {
    int score;
    std::cout << "Enter a numeric score (0-100): ";
    std::cin >> score;

    // Basic handling for non-numeric input.
    // This is a minimal robustness aspect, but the primary robustness issue
    // for this category is the lack of score range validation (0-100).
    if (std::cin.fail()) {
        std::cin.clear(); // Clear the error flag
        // Ignore the rest of the invalid line to prevent infinite loop on subsequent reads
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a numeric score." << std::endl;
        return; // Exit the function as input was invalid
    }

    // Robustness Issue: No validation for score < 0 or score > 100.
    // Negative scores will incorrectly be assigned 'F'.
    // Scores greater than 100 will incorrectly be assigned 'A'.
    char grade;
    if (score >= 90) { // Handles 90-100 and also scores > 100
        grade = 'A';
    } else if (score >= 80) { // Handles 80-89
        grade = 'B';
    } else if (score >= 70) { // Handles 70-79
        grade = 'C';
    } else if (score >= 60) { // Handles 60-69
        grade = 'D';
    } else { // Handles scores below 60, including negative numbers
        grade = 'F';
    }

    std::cout << grade << std::endl;
}

int main() {
    user_solution_logic();
    return 0;
}