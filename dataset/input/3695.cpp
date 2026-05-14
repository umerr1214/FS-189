#include <iostream>
#include <string>
#include <limits> // For std::numeric_limits

struct Student {
    std::string name;
    int id;
    float grade;
};

int main() {
    Student students[3];

    // Populate data
    students[0] = {"Alice", 101, 88.5f};
    students[1] = {"Bob", 102, 92.0f};
    students[2] = {"Charlie", 103, 85.0f};

    // Initialize with first student's grade and index
    float minGrade = students[0].grade; // LOGICAL ERROR: Should be maxGrade, initialized to a very low value or first student's grade
    int lowestStudentIndex = 0; // LOGICAL ERROR: Should be highestStudentIndex

    // Loop to find the student with the highest grade, but logic incorrectly finds the lowest
    for (int i = 1; i < 3; ++i) {
        if (students[i].grade < minGrade) { // LOGICAL ERROR: Condition checks for minimum grade, not maximum
            minGrade = students[i].grade;
            lowestStudentIndex = i;
        }
    }

    // Print details of the student found (will be the one with the lowest grade due to logical error)
    std::cout << "Student with the highest grade:" << std::endl;
    std::cout << "Name: " << students[lowestStudentIndex].name << std::endl;
    std::cout << "ID: " << students[lowestStudentIndex].id << std::endl;
    std::cout << "Grade: " << students[lowestStudentIndex].grade << std::endl;

    return 0;
}