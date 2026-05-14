#include <iostream>
#include <string>

class Student {
private:
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
} // SYNTAX ERROR: Missing semicolon after class definition

int main() {
    Student s1;
    Student s2("Alice", 101);
    {
        Student s3("Bob", 102);
    } // s3 destroyed here
    std::cout << "Main function ending." << std::endl;
    return 0;
}