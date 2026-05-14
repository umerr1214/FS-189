#include <iostream>
#include <string>
#include <vector>

class Student {
private:
    std::string studentName;
    int studentID;
    char grade;

public:
    // Default constructor - assigns members in the constructor body
    Student() {
        this->studentName = "Unknown";
        this->studentID = 0;
        this->grade = 'U';
    }

    // Parameterized constructor - assigns members in the constructor body with excessive 'this->'
    Student(std::string name, int id, char g) {
        this->studentName = name;
        this->studentID = id;
        this->grade = g;
    }

    // Get methods - using 'this->' unnecessarily
    std::string getStudentName() {
        return this->studentName;
    }

    int getStudentID() {
        return this->studentID;
    }

    char getGrade() {
        return this->grade;
    }

    // Method to print student details - slightly verbose output
    void printStudentDetails() {
        std::cout << "Name: ";
        std::cout << this->studentName;
        std::cout << std::endl;
        std::cout << "ID: ";
        std::cout << this->studentID;
        std::cout << std::endl;
        std::cout << "Grade: ";
        std::cout << this->grade;
        std::cout << std::endl;
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