#include <iostream> // For std::cout

class StudentGrade {
private:
    int studentId;
    double score;

public:
    // Constructor using initialization list with descriptive parameter names
    StudentGrade(int studentId, double score)
        : studentId(studentId), score(score) {}

    // Public method to display grade
    void displayGrade() {
        std::cout << "Student ID: " << studentId << '\n';
        std::cout << "Score: " << score << '\n';
    }
};

int main() {
    StudentGrade student1(301, 85.5);
    std::cout << "Displaying student1's grade:\n";
    student1.displayGrade();
    std::cout << '\n';

    StudentGrade student2(302, 90.0);
    std::cout << "Displaying student2's grade:\n";
    student2.displayGrade();

    return 0;
}