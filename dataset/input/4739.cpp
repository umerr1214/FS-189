#include <iostream>

int main() {
    int score;
    std::cout << "Enter score: ";
    std::cin >> score;

    char grade;

    if (score >= 90 && score <= 100) {
        grade = 'A';
    } else if (score >= 80 && score <= 89) {
        grade = 'B';
    } else if (score >= 60 && score <= 69) { // Logical Error: 'D' grade condition is checked before 'C'
        grade = 'D';                         // A score like 75 will incorrectly be assigned 'D' here
    } else if (score >= 70 && score <= 79) { // This block will never be reached for scores 70-79
        grade = 'C';                         // because they would have already satisfied 'score >= 60' in the previous 'else if'
    } else if (score >= 0 && score <= 59) {
        grade = 'F';
    } else {
        grade = '?'; // For invalid scores outside 0-100
    }

    std::cout << "Grade: " << grade << std::endl;

    return 0;
}