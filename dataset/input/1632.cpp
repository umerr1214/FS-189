#include <iostream>
#include <string>

class Student {
private:
    int studentID;
    std::string name;

public:
    Student(int id, std::string n) : studentID(id), name(n) {}

    void enrollInCourse(std::string courseName) {
        std::cout << name << " (ID: " << studentID << ") has enrolled in " << courseName << "." << std::endl;
    }
};

int main() {
    Student s1(101, "Alice Smith");
    s1.enrollInCourse("Calculus I");

    // SEMANTIC ERROR: Attempting to access private member 'studentID' directly from outside the class.
    // This violates encapsulation and will result in a compilation error.
    std::cout << "Student ID (direct access attempt): " << s1.studentID << std::endl;
    
    return 0;
}