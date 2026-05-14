#include <iostream>
#include <string>
#include <vector> // Not strictly needed for this class, but common for C++ programs

class Student {
private:
    int studentID;
    std::string name;

public:
    // Parameterized constructor using initializer list for efficient and correct initialization
    Student(int studentID, const std::string& name)
        : studentID(studentID), name(name) {
        // Constructor body can be empty if no further logic is needed
    }

    // Public method to enroll in a course
    // Uses const reference for courseName to avoid unnecessary copying and indicate read-only
    void enrollInCourse(const std::string& courseName) {
        std::cout << "Student " << name << " (ID: " << studentID << ") has enrolled in " << courseName << ".\n";
        // Using '\n' instead of std::endl for efficiency when simply printing to console
    }

    // Optional: Getters for accessing private members (good practice)
    int getStudentID() const {
        return studentID;
    }

    const std::string& getName() const {
        return name;
    }
};

int main() {
    // Test Case 1
    Student s1(301, "Harry Potter");
    s1.enrollInCourse("Potions Class");

    // Test Case 2
    Student s2(302, "Hermione Granger");
    s2.enrollInCourse("Ancient Runes");

    // Test Case 3
    Student s3(303, "Ron Weasley");
    s3.enrollInCourse("Charms");

    return 0;
}