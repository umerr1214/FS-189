#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // For std::fixed and std::setprecision
#include <utility> // For std::move

class Student {
private:
    std::string name;
    int id;
    double grade;

public:
    // Default constructor: Uses initializer list for efficient initialization
    Student() : name(""), id(0), grade(0.0) {}

    // Parameterized constructor: Uses initializer list and efficient string passing
    // Passing std::string by value and then moving it is an idiomatic way to handle
    // both lvalue and rvalue arguments efficiently (copy-and-swap or pass-by-value-and-move idiom).
    Student(std::string n, int i, double g) : name(std::move(n)), id(i), grade(g) {
        // No explicit input validation is required by the question, but could be added here
        // for a more robust class (e.g., if (i < 0) id = 0; if (g < 0) grade = 0.0;).
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
    students.push_back(Student("Alice Johnson", 101, 95.5));
    students.push_back(Student("Bob Smith", 102, 88.0));

    // Additional students
    students.push_back(Student("Charlie Brown", 103, 75.0));
    students.push_back(Student("Diana Prince", 104, 82.3));
    students.push_back(Student("Eve Adams", 105, 91.7));

    std::cout << "--- Student List ---" << std::endl;
    for (size_t i = 0; i < students.size(); ++i) {
        std::cout << "Student " << i + 1 << ": " << students[i] << std::endl;
    }

    return 0;
}