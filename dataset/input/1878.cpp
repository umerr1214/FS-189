#include <iostream>
#include <string>

class StudentGrade {
private:
    int studentId;
    double score;

public:
    // Semantic error: Members are initialized in the constructor body, not the initialization list,
    // violating the problem's explicit requirement.
    StudentGrade(int id, double s) {
        studentId = id; // Assignment, not initialization
        score = s;     // Assignment, not initialization
    }

    void displayGrade() {
        std::cout << "Student ID: " << studentId << std::endl;
        std::cout << "Score: " << score << std::endl;
    }
};

int main() {
    StudentGrade student1(101, 85.5);
    student1.displayGrade();

    StudentGrade student2(102, 92.0);
    student2.displayGrade();

    return 0;
}