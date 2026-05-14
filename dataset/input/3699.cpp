#include <iostream>
#include <string>
#include <array>       // For std::array
#include <algorithm>   // For std::max_element
#include <iomanip>     // For std::fixed and std::setprecision
#include <limits>      // For std::numeric_limits, though not strictly needed with std::max_element

struct Student {
    std::string name;
    int id;
    float grade;
};

int main() {
    std::array<Student, 3> students;

    // Populate data
    students[0] = {"Alice Smith", 101, 95.5f};
    students[1] = {"Bob Johnson", 102, 88.0f};
    students[2] = {"Charlie Davis", 103, 98.2f};

    // Find the student with the highest grade using std::max_element
    // This is an idiomatic, readable, and efficient way in C++.
    // The lambda function defines the comparison criteria: 'a' is considered 'less' than 'b' if 'a.grade' is lower.
    auto highest_grade_it = std::max_element(students.begin(), students.end(),
                                             [](const Student& a, const Student& b) {
                                                 return a.grade < b.grade;
                                             });

    // Check if an element was found. For std::array<Student, 3>, this will always be true,
    // but it's good practice for general ranges (e.g., std::vector that could be empty).
    if (highest_grade_it != students.end()) {
        const Student& highest_student = *highest_grade_it; // Dereference iterator to get the Student object

        std::cout << "Student with the highest grade:" << std::endl;
        std::cout << "Name: " << highest_student.name << std::endl;
        std::cout << "ID: " << highest_student.id << std::endl;
        std::cout << std::fixed << std::setprecision(2); // Format grade to 2 decimal places
        std::cout << "Grade: " << highest_student.grade << std::endl;
    } else {
        // This block is effectively unreachable for a std::array<Student, 3>
        std::cout << "No students available to determine the highest grade." << std::endl;
    }

    return 0;
}