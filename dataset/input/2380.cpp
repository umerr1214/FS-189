#include <iostream>
#include <string>

class Student {
private:
    int studentID;
    std::string name;
    std::string major;

public:
    // Constructor
    Student(int id, const std::string& n, const std::string& m) :
        studentID(id), name(n), major(m) {}

    // Public getter methods
    int getStudentID() const {
        return studentID;
    }

    const std::string& getName() const {
        return name;
    }

    const std::string& getMajor() const {
        return major;
    }
} // Syntax Error: Missing semicolon after class definition

int main() {
    Student s1(101, "Alice Smith", "Computer Science");
    std::cout << "Student ID: " << s1.getStudentID() << std::endl;
    std::cout << "Name: " << s1.getName() << std::endl;
    std::cout << "Major: " << s1.getMajor() << std::endl;
    std::cout << "---" << std::endl;

    Student s2(102, "Bob Johnson", "Physics");
    std::cout << "Student ID: " << s2.getStudentID() << std::endl;
    std::cout << "Name: " << s2.getName() << std::endl;
    std::cout << "Major: " << s2.getMajor() << std::endl;

    return 0;
}