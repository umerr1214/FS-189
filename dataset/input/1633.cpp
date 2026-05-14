#include <iostream>
#include <string>
#include <vector>

class Student {
private:
    int studentID;
    std::string name;

public:
    // Parameterized constructor - lacks validation for studentID and name
    Student(int id, std::string n) {
        studentID = id;
        name = n;
    }

    // Public method to enroll in a course - lacks validation for courseName
    void enrollInCourse(std::string courseName) {
        std::cout << "Student " << name << " (ID: " << studentID << ") has enrolled in " << courseName << ".\n";
    }

    // Optional: Getters for testing/display purposes
    int getStudentID() const {
        return studentID;
    }

    std::string getName() const {
        return name;
    }
};

int main() {
    // Test Case 1: Valid student, valid course
    Student s1(101, "Alice Smith");
    s1.enrollInCourse("Mathematics I");

    // Test Case 2: Student with a negative ID (Robustness issue: no validation)
    Student s2(-5, "Bob Johnson");
    s2.enrollInCourse("Physics II");

    // Test Case 3: Student with an empty name (Robustness issue: no validation)
    Student s3(103, "");
    s3.enrollInCourse("Chemistry Basics");

    // Test Case 4: Student enrolling in an empty course name (Robustness issue: no validation)
    Student s4(104, "Charlie Brown");
    s4.enrollInCourse("");

    // Test Case 5: Student with zero ID
    Student s5(0, "Diana Prince");
    s5.enrollInCourse("History of Art");

    return 0;
}