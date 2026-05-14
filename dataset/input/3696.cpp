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

    // Populate data designed to expose the semantic error
    students[0] = {"Alice", 101, 90.5f};
    students[1] = {"Bob", 102, 90.8f};
    students[2] = {"Charlie", 103, 90.2f};

    // SEMANTIC ERROR: Using 'int' for maxGrade.
    // This causes implicit truncation when assigning float values to it,
    // leading to incorrect comparisons and potentially wrong highest student.
    int maxGrade = static_cast<int>(students[0].grade); // Truncates 90.5f to 90
    int highestStudentIndex = 0;

    for (int i = 1; i < 3; ++i) {
        // The comparison `students[i].grade > maxGrade` compares a float with an int.
        // If true, `maxGrade` (an int) is updated by truncating the float grade.
        // Example with provided data:
        // Initial: maxGrade=90 (from 90.5f), highestStudentIndex=0 (Alice)
        // i=1 (Bob, 90.8f): 90.8f > 90 (true). maxGrade becomes 90 (from 90.8f), highestStudentIndex=1 (Bob)
        // i=2 (Charlie, 90.2f): 90.2f > 90 (true). maxGrade becomes 90 (from 90.2f), highestStudentIndex=2 (Charlie)
        // Result: Charlie (90.2f), which is incorrect as Bob (90.8f) has the highest grade.
        if (students[i].grade > maxGrade) {
            maxGrade = static_cast<int>(students[i].grade); // Truncation happens here
            highestStudentIndex = i;
        }
    }

    std::cout << "Student with the highest grade:" << std::endl;
    std::cout << "Name: " << students[highestStudentIndex].name << std::endl;
    std::cout << "ID: " << students[highestStudentIndex].id << std::endl;
    std::cout << "Grade: " << students[highestStudentIndex].grade << std::endl;

    return 0;
}