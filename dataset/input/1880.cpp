#include <iostream>
#include <string>
#include <vector> // Unnecessary header for this class

class StudentGrade {
private:
    int studentId;
    double score;

public:
    // Constructor using initialization list with less descriptive parameter names
    StudentGrade(int i, double s) : studentId(i), score(s) {}

    // Public method to display grade, using std::endl repeatedly
    void displayGrade() {
        std::cout << "Student ID: " << studentId << std::endl;
        std::cout << "Score: " << score << std::endl;
    }
};

int main() {
    StudentGrade student1(201, 75.5);
    std::cout << "Displaying student1's grade:" << std::endl;
    student1.displayGrade();
    std::cout << std::endl;

    StudentGrade student2(202, 92.0);
    std::cout << "Displaying student2's grade:" << std::endl;
    student2.displayGrade();

    return 0;
}