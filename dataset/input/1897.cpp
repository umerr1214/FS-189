#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Not strictly needed for this version, but good practice for C++ development.

// Represents a student with a name and an ID.
class Student {
public:
    std::string name;
    int id;

    // Constructor to initialize student details.
    // Uses std::move for efficiency when passing string by value.
    Student(std::string name, int id) : name(std::move(name)), id(id) {}

    // Method to display student information.
    void display() const {
        std::cout << "  - ID: " << id << ", Name: " << name << std::endl;
    }
};

// Represents a course that aggregates Student objects.
class Course {
private:
    std::string courseName;
    std::vector<Student> students; // Collection to store Student objects.

public:
    // Constructor to initialize the course name.
    Course(std::string name) : courseName(std::move(name)) {}

    // Robustness Issue: This method does NOT check for duplicate students.
    // It simply adds the student regardless of whether they are already enrolled.
    void addStudent(const Student& student) {
        students.push_back(student);
        std::cout << "Added student: " << student.name << " (ID: " << student.id << ") to " << courseName << "." << std::endl;
    }

    // Displays all enrolled students in the course.
    // Uses a range-based for loop for clear iteration.
    void displayStudents() const {
        std::cout << "\n--- Course: " << courseName << " ---" << std::endl;
        if (students.empty()) {
            std::cout << "  No students enrolled." << std::endl;
        } else {
            std::cout << "Enrolled Students (" << students.size() << "):" << std::endl;
            for (const auto& student : students) {
                student.display();
            }
        }
        std::cout << "---------------------------------" << std::endl;
    }
};

int main() {
    std::cout << "--- Testing Robustness Issue: Duplicate Students ---" << std::endl;

    Course cppCourse("C++ Programming");

    // Test Case 1: Add initial students
    Student s1("Alice Smith", 101);
    Student s2("Bob Johnson", 102);
    Student s3("Charlie Brown", 103);

    cppCourse.addStudent(s1);
    cppCourse.addStudent(s2);
    cppCourse.displayStudents();

    // Test Case 2: Add a duplicate student (this demonstrates the robustness issue)
    std::cout << "\nAttempting to add Alice Smith (ID: 101) again..." << std::endl;
    cppCourse.addStudent(s1); // Adding Alice again without checking for duplicates
    cppCourse.displayStudents(); // Alice Smith (ID 101) will appear twice

    // Test Case 3: Add another unique student
    cppCourse.addStudent(s3);
    cppCourse.displayStudents();

    // Test Case 4: Display an empty course
    Course emptyCourse("Empty Course");
    emptyCourse.displayStudents();

    return 0;
}