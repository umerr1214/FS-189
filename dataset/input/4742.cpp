#include <iostream>
#include <string>
#include <sstream> // Required for test harness to redirect I/O

// Core logic function that takes input/output streams
void grading_logic_4742(std::istream& in, std::ostream& out, std::ostream& err) {
    int score;
    out << "Enter student's numerical score (0-100): ";
    in >> score;

    char grade = ' '; // Initialize grade

    // Basic input validation to ensure functionality for valid range,
    // but the issue is in the grading logic structure.
    if (in.fail() || score < 0 || score > 100) {
        err << "Invalid score entered. Score must be between 0 and 100." << std::endl;
        return; // Exit if input is invalid
    }

    // Readability / Efficiency Issue: Uses excessively nested if-else statements
    // instead of a flat if-else if chain. This makes the code harder to read
    // and less efficient due to deeper nesting levels, even though it's functionally correct.
    if (score >= 90) {
        grade = 'A';
    } else { // score < 90
        if (score >= 80) {
            grade = 'B';
        } else { // score < 80
            if (score >= 70) {
                grade = 'C';
            } else { // score < 70
                if (score >= 60) {
                    grade = 'D';
                } else { // score < 60
                    grade = 'F';
                }
            }
        }
    }

    out << "The letter grade is: " << grade << std::endl;
}

int main() {
    // This main function simply calls the grading logic with standard I/O streams.
    // This structure allows for easier testing by redirecting streams in a test harness.
    grading_logic_4742(std::cin, std::cout, std::cerr);
    return 0;
}