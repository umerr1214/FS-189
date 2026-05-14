#include <iostream>
#include <string>

// Student's solution logic is encapsulated in student_main
int student_main() { // Renamed from main() for testing harness
    int score;
    std::string grade;

    std::cout << "Enter a numeric score (0-100): ";
    std::cin >> score;

    // Logical Error: Using score > 90 instead of score >= 90 for 'A' grade.
    // This causes a score of 90 to incorrectly fall into the 'B' category.
    if (score > 90 && score <= 100) { // Should be score >= 90
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

    std::cout << "The letter grade is: " << grade << std::endl;

    return 0;
}

// Original main function calls student_main for standalone execution
int main() {
    return student_main();
}