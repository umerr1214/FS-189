#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // For std::fixed and std::setprecision

class Student {
private:
    std::string name;
    int id;
    double grade;

public:
    // Default constructor: Initializes members to default values
    Student() : name(""), id(0), grade(0.0) {}

    // Parameterized constructor: Accepts name, id, and grade
    // Robustness issue: No input validation for id or grade.
    // Allows negative values which might be invalid in a real-world scenario.
    Student(std::string n, int i, double g) : name(n), id(i), grade(g) {
        // No checks are performed here to ensure id is non-negative or grade is within a valid range (e.g., 0-100).
        // This can lead to the object being in an "invalid" state according to business rules.
    }

    // Friend function to allow easy printing of Student objects
    friend std::ostream& operator<<(std::ostream& os, const Student& s) {
        os << "Name: " << s.name << ", ID: " << s.id << ", Grade: " << std::fixed << std::setprecision(1) << s.grade;
        return os;
    }
};

int main() {
    std::vector<Student> students;

    // Test default constructor
    students.push_back(Student());

    // Test parameterized constructor with valid data
    students.push_back(Student("Alice", 101, 95.5));
    students.push_back(Student("Bob", 102, 88.0));

    // Demonstrate robustness issue: creating students with "invalid" data
    students.push_back(Student("Charlie", -5, 75.0));   // Negative ID
    students.push_back(Student("David", 104, -10.0));   // Negative Grade
    students.push_back(Student("Eve", -10, -5.0));      // Both negative

    std::cout << "--- Student List ---" << std::endl;
    for (size_t i = 0; i < students.size(); ++i) {
        std::cout << "Student " << i + 1 << ": " << students[i] << std::endl;
    }

    return 0;
}