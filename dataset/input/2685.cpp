#include <iostream>
#include <string>
#include <vector>

class Student {
private:
    std::string studentName;
    int studentID;
    char grade;

public:
    // Default constructor using initializer list
    Student() : studentName("Unknown"), studentID(0), grade('U') {}

    // Parameterized constructor using initializer list
    Student(std::string name, int id, char g) : studentName(name), studentID(id), grade(g) {}

    // Get methods marked as const
    std::string getStudentName() const {
        return studentName;
    }

    int getStudentID() const {
        return studentID;
    }

    char getGrade() const {
        return grade;
    }

    // Method to print student details, marked as const
    void printStudentDetails() const {
        std::cout << "Name: " << studentName << std::endl;
        std::cout << "ID: " << studentID << std::endl;
        std::cout << "Grade: " << grade << std::endl;
    }
};

int main() {
    // Test Case 1: Default constructor
    Student student1;
    std::cout << "Student 1:\n";
    student1.printStudentDetails();
    std::cout << "--------------------\n";

    // Test Case 2: Parameterized constructor
    Student student2("Alice Smith", 1001, 'A');
    std::cout << "Student 2:\n";
    student2.printStudentDetails();
    std::cout << "--------------------\n";

    // Test Case 3: Another parameterized constructor
    Student student3("Bob Johnson", 2002, 'B');
    std::cout << "Student 3:\n";
    student3.printStudentDetails();
    std::cout << "--------------------\n";

    return 0;
}