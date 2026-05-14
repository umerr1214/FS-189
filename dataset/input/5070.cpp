#include <iostream>

// Function containing the core logic
void run_grading_logic() {
    char score_char; // SEMANTIC ERROR: Using 'char' to store an integer score (0-100)
    std::cout << "Enter student's score (0-100): ";
    std::cin >> score_char; // Reads only the first character, e.g., '9' for input "90"

    // Comparisons will be made using the ASCII value of the character read.
    // For example, if input is "90", score_char becomes '9' (ASCII 57).
    // The condition (score_char >= 90) will evaluate to (57 >= 90), which is false.
    // This fundamentally misinterprets the numerical value of the score.
    if (score_char >= 90 && score_char <= 100) {
        std::cout << "Grade: A" << std::endl;
    } else if (score_char >= 80 && score_char <= 89) {
        std::cout << "Grade: B" << std::endl;
    } else if (score_char >= 70 && score_char <= 79) {
        std::cout << "Grade: C" << std::endl;
    } else if (score_char >= 60 && score_char <= 69) {
        std::cout << "Grade: D" << std::endl;
    } else if (score_char >= 0 && score_char <= 59) { // This will likely catch most inputs due to ASCII values
        std::cout << "Grade: F" << std::endl;
    } else {
        std::cout << "Invalid score." << std::endl;
    }
}

int main() {
    run_grading_logic();
    return 0;
}