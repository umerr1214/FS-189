#include <iostream>
#include <string>

// Student's solution logic is encapsulated in student_main
int student_main() { // Renamed from main() for testing harness
    int score;
    std::string grade;

    std::cout << "Enter a numeric score (0-100): ";
    std::cin >> score;

    if (score >= 90 && score <= 100) {
        grade = "A";
    } else if (score >= 80 && score <= 89) {
        grade = "B";
    } else if (score >= 70 && score <= 79) {
        grade = "C";
    } else if (score >= 60 && score <= 69) {
        grade = "D";
    } else if (score >= 0 && score < 60) {
        grade = "F";
    } else {
        grade = "Invalid Score";
    }

    // Semantic Error: Only printing the grade, not the full message "The letter grade is: "
    // This deviates from the common user interaction expectation implied by "print a letter grade"
    // in the context of a program prompting a user.
    std::cout << grade << std::endl; // Should be: std::cout << "The letter grade is: " << grade << std::endl;

    return 0;
}

// Original main function calls student_main for standalone execution
int main() {
    return student_main();
}