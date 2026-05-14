#include <iostream>
#include <string>
#include <limits> // Required for numeric_limits

// The core logic of the program, wrapped in a function for testing purposes.
void user_solution_logic() {
    int score;
    std::cout << "Enter a numeric score (0-100): ";
    std::cin >> score;

    // Input validation for non-numeric input
    if (std::cin.fail()) {
        std::cin.clear(); // Clear the error flag
        // Ignore the rest of the invalid line to prevent infinite loop on subsequent reads
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a numeric score." << std::endl;
        return; // Exit the function as input was invalid
    }

    // Input validation for score range (0-100)
    if (score < 0 || score > 100) {
        std::cout << "Score must be between 0 and 100." << std::endl;
        return; // Exit the function if score is out of range
    }

    char grade;
    // Correct and efficient use of if-else if-else statements.
    // The conditions are ordered from highest to lowest, and subsequent 'else if'
    // implicitly handles the upper bound from the previous condition.
    if (score >= 90) { // Score is 90-100
        grade = 'A';
    } else if (score >= 80) { // Score is 80-89
        grade = 'B';
    } else if (score >= 70) { // Score is 70-79
        grade = 'C';
    } else if (score >= 60) { // Score is 60-69
        grade = 'D';
    } else { // Score is below 60 (0-59)
        grade = 'F';
    }

    std::cout << grade << std::endl;
}

int main() {
    user_solution_logic();
    return 0;
}