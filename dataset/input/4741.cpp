#include <iostream>
#include <string>
#include <sstream> // Required for test harness to redirect I/O

// Core logic function that takes input/output streams
void grading_logic_4741(std::istream& in, std::ostream& out, std::ostream& err) {
    int score;
    out << "Enter student's numerical score (0-100): ";
    in >> score;

    char grade;

    // Robustness Issue: No explicit input validation for the 0-100 range.
    // Scores outside this range will be processed and assigned a grade
    // without indicating an error to the user that the input was invalid.
    // For example, -5 will be 'F', and 105 will be 'A'.
    if (score >= 90) {
        grade = 'A';
    } else if (score >= 80) {
        grade = 'B';
    } else if (score >= 70) {
        grade = 'C';
    } else if (score >= 60) {
        grade = 'D';
    } else { // This 'else' branch catches all scores less than 60, including negative ones.
        grade = 'F';
    }

    out << "The letter grade is: " << grade << std::endl;
}

int main() {
    // This main function simply calls the grading logic with standard I/O streams.
    // This structure allows for easier testing by redirecting streams in a test harness.
    grading_logic_4741(std::cin, std::cout, std::cerr);
    return 0;
}