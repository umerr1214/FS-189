#include <iostream>
#include <string>

class StudentGrade {
private:
    int studentId;
    double score;

public:
    // Constructor initialization list
    StudentGrade(int id, double s) : studentId(id), score(s) {
        // Body of constructor
    }

    void displayGrade() {
        std::cout << "Student ID: " << studentId << std::endl;
        std::cout << "Score: " << score << std::endl
    } // Missing semicolon here, causing a syntax error
};

int main() {
    StudentGrade student1(101, 85.5);
    student1.displayGrade();

    StudentGrade student2(102, 92.0);
    student2.displayGrade();

    return 0;
}