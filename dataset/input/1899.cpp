#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Required for std::find_if to check for duplicate students.

// Represents a student with a name and a unique ID.
class Student {
public:
    std::string name;
    int id;

    // Constructor to initialize student details.
    // Uses std::move for efficiency when passing string by value.
    Student(std::string name, int id) : name(std::move(name)), id(id) {}

    // Displays the student's ID and name.
    void display() const {
        std::cout << "  - ID: " << id << ", Name: " << name << std::endl;
    }

    // Overload comparison operator for checking student equality (by ID), though a lambda is used in this example.
    // This is good practice for classes representing unique entities.
    bool operator==(const Student& other) const {
        return id == other.id;
    }
};

// Represents a course that aggregates Student objects.
class Course {
private:
    std::string courseName;
    std::vector<Student> students; // Collection to store Student objects.

public:
    // Constructor to initialize the course name.
    // Uses std::move for efficiency when passing string by value.
    Course(std::string name) : courseName(std::move(name)) {}

    // Adds a student to the course.
    // Takes a const reference to avoid unnecessary copying and ensures robustness by checking for duplicates.
    void addStudent(const Student& student) {
        // Check if a student with the same ID already exists in the course.
        // Uses std::find_if with a lambda for efficient and readable search.
        auto it = std::find_if(students.begin(), students.end(),
                               [&](const Student& s) { return s.id == student.id; });

        if (it == students.end()) { // Student not found, add them
            students.push_back(student);
            std::cout << "Successfully added student: " << student.name << " (ID: " << student.id << ") to " << courseName << "." << std::endl;
        } else { // Student found, report duplicate
            std::cout << "Warning: Student with ID " << student.id << " (" << student.name << ") is already enrolled in " << courseName << ". Not added again." << std::endl;
        }
    }

    // Displays all enrolled students in the course.
    // Uses a range-based for loop for clear, modern, and efficient iteration.
    void displayStudents() const {
        std::cout << "\n--- Course: " << courseName << " ---" << std::endl;
        if (students.empty()) {
            std::cout << "  No students enrolled." << std::endl;
        } else {
            std::cout << "Enrolled Students (" << students.size() << "):" << std::endl;
            for (const auto& student : students) { // Range-based for loop
                student.display();
            }
        }
        std::cout << "---------------------------------" << std::endl;
    }
};

int main() {
    std::cout << "--- Testing Correct Version ---" << std::endl;

    Course algorithmsCourse("Advanced Algorithms");

    // Test Case 1: Add unique students
    Student sA("David Lee", 301);
    Student sB("Emily Chen", 302);
    Student sC("Fiona Wang", 303);

    algorithmsCourse.addStudent(sA);
    algorithmsCourse.addStudent(sB);
    algorithmsCourse.displayStudents();

    // Test Case 2: Attempt to add a duplicate student (should be handled gracefully)
    std::cout << "\nAttempting to add David Lee (ID: 301) again..." << std::endl;
    algorithmsCourse.addStudent(sA); // This call will detect the duplicate and not add it.
    algorithmsCourse.displayStudents();

    // Test Case 3: Add another unique student
    algorithmsCourse.addStudent(sC);
    algorithmsCourse.displayStudents();

    // Test Case 4: Display an empty course
    Course linearAlgebra("Linear Algebra");
    linearAlgebra.displayStudents();

    return 0;
}