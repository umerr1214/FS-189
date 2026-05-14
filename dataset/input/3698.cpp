#include <iostream>
#include <string>
#include <array>
#include <iomanip> // For std::fixed and std::setprecision

struct Student {
    std::string name;
    int id;
    float grade;
};

int main() {
    std::array<Student, 3> sArr; // Less descriptive array name

    // Populate data
    sArr[0] = {"Alice Johnson", 101, 95.5f};
    sArr[1] = {"Bob Williams", 102, 88.0f};
    sArr[2] = {"Charlie Brown", 103, 98.2f};

    // Readability/Efficiency Issue:
    // - Manual iteration instead of std::max_element
    // - Initializing with a 'magic number' (-1.0f) instead of a more robust approach like numeric_limits or first element
    // - Slightly less optimal variable names (sArr, currentMaxGrade, bestIdx)
    // - Hardcoded loop limit (3) instead of using sArr.size()
    // - Redundant check for bestIdx != -1 for a fixed-size array of 3
    float currentMaxGrade = -1.0f; // Magic number initialization
    int bestIdx = -1; // Index of the student with the highest grade

    for (int i = 0; i < 3; ++i) { // Fixed loop limit
        if (sArr[i].grade > currentMaxGrade) {
            currentMaxGrade = sArr[i].grade;
            bestIdx = i;
        }
    }

    if (bestIdx != -1) { // Redundant check for fixed size array
        std::cout << "Student with the highest grade:" << std::endl;
        std::cout << "Name: " << sArr[bestIdx].name << std::endl;
        std::cout << "ID: " << sArr[bestIdx].id << std::endl;
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Grade: " << sArr[bestIdx].grade << std::endl;
    } else {
        // This branch is unreachable for a std::array<Student, 3>
        std::cout << "No students found." << std::endl;
    }

    return 0;
}