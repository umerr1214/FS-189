#include <iostream>

int main() {
    int studentScore; // Using a slightly less conventional variable name
    std::cout << "Enter student's numerical score (an integer from 0 to 100): ";
    std::cin >> studentScore;

    char assignedGrade; // Another slightly less conventional name

    // Readability / Efficiency Issue: The conditions are overly explicit and redundant.
    // In a properly chained 'if-else if-else' structure where conditions are checked
    // in descending order, the upper bound check (e.g., 'studentScore <= 89') is
    // unnecessary because the previous 'if' condition already ensures that if execution
    // reaches a subsequent 'else if', the score must be less than the previous upper bound.
    // This adds redundant comparisons and makes the code more verbose than necessary,
    // slightly impacting efficiency and readability.
    if (studentScore >= 90 && studentScore <= 100) {
        assignedGrade = 'A';
    } else if (studentScore >= 80 && studentScore <= 89) { // Redundant 'studentScore <= 89'
        assignedGrade = 'B';
    } else if (studentScore >= 70 && studentScore <= 79) { // Redundant 'studentScore <= 79'
        assignedGrade = 'C';
    } else if (studentScore >= 60 && studentScore <= 69) { // Redundant 'studentScore <= 69'
        assignedGrade = 'D';
    } else if (studentScore >= 0 && studentScore <= 59) { // Redundant 'studentScore <= 59'
        assignedGrade = 'F';
    } else {
        // This branch handles scores outside the 0-100 range.
        // It's correct to handle these, but the issue is in the redundant checks above.
        assignedGrade = 'X'; // Indicate an invalid grade for out-of-range input
        std::cout << "Score entered is outside the typical grading range (0-100)." << std::endl;
    }

    std::cout << "The student's final grade is: " << assignedGrade << std::endl;

    return 0;
}