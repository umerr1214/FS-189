#include <iostream>
#include <string>
#include <sstream> // Required for test harness to redirect I/O

// Core logic function that takes input/output streams
void grading_logic_4743(std::istream& in, std::ostream& out, std::ostream& err) {
    int score;
    out << "Enter student's numerical score (0-100): ";
    in >> score;

    // Correct Version: Robust input validation.
    // Checks for non-numeric input (in.fail()) and out-of-range scores.
    if (in.fail()) {
        err << "Invalid input. Please enter a numerical score." << std::endl;
        in.clear(); // Clear error flags
        // Optionally, consume invalid input to prevent infinite loops if reading again
        // in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return; // Exit the function gracefully
    } else if (score < 0 || score > 100) {
        err << "Invalid score. Please enter a numerical score between 0 and 100." << std::endl;
        return; // Exit the function gracefully
    }

    char grade;

    // Correct Version: Assign letter grade using an efficient and readable if-else if chain.
    // The order is important to ensure correct grading (highest score range first).
    if (score >= 90) {
        grade = 'A';
    } else if (score >= 80) {
        grade = 'B';
    } else if (score >= 70) {
        grade = 'C';
    } else if (score >= 60) {
        grade = 'D';
    } else { // This covers scores from 0 to 59
        grade = 'F';
    }

    out << "The letter grade is: " << grade << std::endl;
}

int main() {
    // This main function simply calls the grading logic with standard I/O streams.
    // This structure allows for easier testing by redirecting streams in a test harness.
    grading_logic_4743(std::cin, std::cout, std::cerr);
    return 0;
}