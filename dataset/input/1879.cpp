#include <iostream>
#include <string> // Not strictly needed, but common

class StudentGrade {
private:
    int studentId;
    double score;

public:
    // Constructor using initialization list
    StudentGrade(int id, double s) : studentId(id), score(s) {}

    // Public method to display grade
    void displayGrade() {
        std::cout << "Student ID: " << studentId << std::endl;
        std::cout << "Score: " << score << std::endl;
        // No validation for score range, allowing invalid scores to be stored and displayed.
    }
};

int main() {
    // Test case demonstrating the robustness issue: a negative score
    StudentGrade student1(101, -5.0);
    std::cout << "Displaying student1's grade (invalid score):" << std::endl;
    student1.displayGrade();
    std::cout << std::endl;

    // Another invalid score (above 100, if scores are typically 0-100)
    StudentGrade student2(102, 105.0);
    std::cout << "Displaying student2's grade (invalid score):" << std::endl;
    student2.displayGrade();
    std::cout << std::endl;

    // A valid score to show it works for valid cases too
    StudentGrade student3(103, 88.5);
    std::cout << "Displaying student3's grade (valid score):" << std::endl;
    student3.displayGrade();

    return 0;
}