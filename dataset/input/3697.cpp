#include <iostream>
#include <string>
#include <array> // Using std::array as per "array of 3 Student objects"
#include <iomanip> // For std::fixed and std::setprecision

struct Student {
    std::string name;
    int id;
    float grade;
};

int main() {
    std::array<Student, 3> students;

    // Populate data with all negative grades to expose the robustness issue
    // The actual highest grade among these is -2.2f (Charlie).
    students[0] = {"Alice", 101, -5.5f};
    students[1] = {"Bob", 102, -8.0f};
    students[2] = {"Charlie", 103, -2.2f};

    // Robustness Issue: Initializing max_grade to 0.0f, which might be higher than all actual grades
    // if all grades are negative. The highest_student is initialized to students[0]
    // and only updated if a student's grade *exceeds* the current max_grade (which could be 0.0f).
    float max_grade = 0.0f; // Flawed initialization for scenarios with all negative grades
    Student highest_student = students[0]; // Initialize with the first student

    for (size_t i = 0; i < students.size(); ++i) {
        if (students[i].grade > max_grade) { // This comparison is the core of the flaw
            max_grade = students[i].grade;
            highest_student = students[i];
        }
    }

    std::cout << "Student with the highest grade:" << std::endl;
    std::cout << "Name: " << highest_student.name << std::endl;
    std::cout << "ID: " << highest_student.id << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Grade: " << highest_student.grade << std::endl;

    return 0;
}