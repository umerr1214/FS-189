#include <iostream>

int main() {
    int score;
    std::cout << "Enter student's numerical score (0-100): ";
    std::cin >> score;

    char grade;

    // Robustness Issue: The program does not explicitly validate if the input score
    // is within the expected range of 0-100. It proceeds to assign a grade based
    // on the existing if-else if-else structure even for scores outside this range.
    // For example, a negative score like -5 will fall into the 'F' category,
    // and a score greater than 100 like 105 will fall into the 'A' category,
    // without any explicit error or warning to the user that the input was out of bounds.
    if (score >= 90) {
        grade = 'A';
    } else if (score >= 80) {
        grade = 'B';
    } else if (score >= 70) {
        grade = 'C';
    } else if (score >= 60) {
        grade = 'D';
    } else { // This branch handles scores 0-59, but also any score less than 0
        grade = 'F';
    }

    std::cout << "The grade is: " << grade << std::endl;

    return 0;
}