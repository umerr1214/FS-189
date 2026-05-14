#include <iostream>

int main() {
    int score;
    std::cout << "Enter score: " // Missing semicolon here, will cause a syntax error
    std::cin >> score;

    char grade;

    if (score >= 90 && score <= 100) {
        grade = 'A';
    } else if (score >= 80 && score <= 89) {
        grade = 'B';
    } else if (score >= 70 && score <= 79) {
        grade = 'C';
    } else if (score >= 60 && score <= 69) {
        grade = 'D';
    } else if (score >= 0 && score <= 59) {
        grade = 'F';
    } else {
        grade = '?'; // For invalid scores outside 0-100
    }

    std::cout << "Grade: " << grade << std::endl;

    return 0;
}