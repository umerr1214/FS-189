#include <iostream>
#include <string>
#include <limits> // For std::numeric_limits

struct Student {
    std::string name;
    int id;
    float grade;
} // SYNTAX ERROR: Missing semicolon here

int main() {
    Student students[3];

    // Populate data
    students[0] = {"Alice", 101, 88.5f};
    students[1] = {"Bob", 102, 92.0f};
    students[2] = {"Charlie", 103, 85.0f};

    float maxGrade = -1.0f; // Grades are typically non-negative
    int highestStudentIndex = -1;

    for (int i = 0; i < 3; ++i) {
        if (students[i].grade > maxGrade) {
            maxGrade = students[i].grade;
            highestStudentIndex = i;
        }
    }

    if (highestStudentIndex != -1) {
        std::cout << "Student with the highest grade:" << std::endl;
        std::cout << "Name: " << students[highestStudentIndex].name << std::endl;
        std::cout << "ID: " << students[highestStudentIndex].id << std::endl;
        std::cout << "Grade: " << students[highestStudentIndex].grade << std::endl;
    } else {
        std::cout << "No students found or grades are all negative." << std::endl;
    }

    return 0;
}