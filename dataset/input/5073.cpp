#include <iostream>
#include <limits> // Required for std::numeric_limits

int main() {
    int score;
    std::cout << "Enter student's numerical score (an integer between 0 and 100): ";

    // Robust input validation loop to ensure the score is an integer
    // and within the specified range of 0 to 100.
    while (!(std::cin >> score) || score < 0 || score > 100) {
        std::cout << "Invalid input. Please enter a numerical score between 0 and 100: ";
        std::cin.clear(); // Clear error flags (e.g., if non-integer was entered)
        // Ignore the rest of the invalid line to prevent infinite loops
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    char grade;

    // Correct, efficient, and readable if-else if-else structure.
    // Conditions are checked in descending order, naturally handling the upper bounds.
    if (score >= 90) {
        grade = 'A';
    } else if (score >= 80) {
        grade = 'B';
    } else if (score >= 70) {
        grade = 'C';
    } else if (score >= 60) {
        grade = 'D';
    } else { // If score is less than 60, and due to validation, it must be >= 0
        grade = 'F';
    }

    std::cout << "The assigned letter grade is: " << grade << std::endl;

    return 0;
}