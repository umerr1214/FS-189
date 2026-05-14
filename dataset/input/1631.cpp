#include <iostream>
#include <string>

class Student {
private:
    int studentID;
    std::string name;

public:
    Student(int id, std::string n) : studentID(id), name(n) {}

    void enrollInCourse(std::string courseName) {
        // LOGICAL ERROR: This method prints a hardcoded course name
        // instead of using the 'courseName' parameter.
        std::cout << name << " (ID: " << studentID << ") has enrolled in " << "Introduction to C++" << "." << std::endl;
    }
};

int main() {
    Student s1(101, "Alice Smith");
    s1.enrollInCourse("Calculus I"); // Intended: Calculus I, Actual: Introduction to C++

    Student s2(102, "Bob Johnson");
    s2.enrollInCourse("Linear Algebra"); // Intended: Linear Algebra, Actual: Introduction to C++
    return 0;
}