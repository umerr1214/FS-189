#include <iostream>
#include <string>

class Student {
// SEMANTIC ERROR: Members are declared as public instead of private as required by the question.
public:
    std::string name;
    int studentID;

public:
    // Default constructor
    Student() : name("Unknown"), studentID(0) {}

    // Parameterized constructor
    Student(std::string n, int id) : name(n), studentID(id) {}

    // Destructor
    ~Student() {
        std::cout << "Student " << name << " with ID " << studentID << " destroyed." << std::endl;
    }
};

int main() {
    Student s1;
    Student s2("Alice", 101);
    {
        Student s3("Bob", 102);
        // Demonstrating the semantic violation: direct access to public members
        // std::cout << "Inside block: s3.name = " << s3.name << ", s3.studentID = " << s3.studentID << std::endl;
    } // s3 destroyed here
    std::cout << "Main function ending." << std::endl;
    return 0;
}