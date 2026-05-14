#include <iostream>
#include <string>
#include <vector>

class Student {
private:
    int studentID;
    std::string name;

public:
    // Parameterized constructor - uses less descriptive parameter names and initializes in body
    Student(int s_id, std::string s_name) {
        this->studentID = s_id; // Using 'this->' everywhere adds verbosity
        this->name = s_name;
    }

    // Public method to enroll in a course - uses multiple string concatenations and std::endl
    void enrollInCourse(std::string course) {
        std::string message = "Student " + this->name + " (ID: ";
        message = message + std::to_string(this->studentID) + ") has enrolled in ";
        message = message + course + ".";
        std::cout << message << std::endl; // std::endl flushes the buffer, which can be less efficient than '\n'
    }
};

int main() {
    // Test Case 1
    Student s1(201, "Emily White");
    s1.enrollInCourse("Biology I");

    // Test Case 2
    Student s2(202, "Frank Green");
    s2.enrollInCourse("Sociology");

    // Test Case 3
    Student s3(203, "Grace Black");
    s3.enrollInCourse("Psychology");

    return 0;
}