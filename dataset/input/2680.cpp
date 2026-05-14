#include <iostream>
#include <string>

class Student {
private:
    std::string studentName;
    int studentID;
    char grade;

public:
    // Default constructor
    Student() : studentName("N/A"), studentID(0), grade('F') {}

    // Parameterized constructor
    Student(std::string name, int id, char g) : studentName(name), studentID(id), grade(g) {}

    // Get methods
    std::string getStudentName() const { return studentName; }
    int getStudentID() const { return studentID; }
    char getGrade() const { return grade; }

    // Print method
    void printStudentDetails() const {
        std::cout << "Name: " << studentName << std::endl;
        std::cout << "ID: " << studentID << std::endl;
        std::cout << "Grade: " << grade << std::endl;
    }
} // SYNTAX ERROR: Missing semicolon here

int main() {
    Student s1;
    std::cout << "Default Student Details:" << std::endl;
    s1.printStudentDetails();
    std::cout << std::endl;

    Student s2("Alice Smith", 101, 'A');
    std::cout << "Parameterized Student Details:" << std::endl;
    s2.printStudentDetails();
    std::cout << std::endl;

    return 0;
}