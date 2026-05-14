#include <iostream>
#include <string>
#include <vector>

class Student {
private:
    std::string studentName;
    int studentID;
    char grade;

public:
    // Default constructor
    Student() {
        studentName = "Unknown";
        studentID = 0;
        grade = 'U';
    }

    // Parameterized constructor
    // No validation is performed on studentID or grade, allowing potentially invalid states.
    Student(std::string name, int id, char g) {
        studentName = name;
        studentID = id;
        grade = g;
    }

    // Get methods
    std::string getStudentName() {
        return studentName;
    }

    int getStudentID() {
        return studentID;
    }

    char getGrade() {
        return grade;
    }

    // Method to print student details
    void printStudentDetails() {
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

    // Test Case 2: Parameterized constructor with valid data
    Student student2("Alice Smith", 1001, 'A');
    std::cout << "Student 2:\n";
    student2.printStudentDetails();
    std::cout << "--------------------\n";

    // Test Case 3: Parameterized constructor with another valid data
    Student student3("Bob Johnson", 2002, 'B');
    std::cout << "Student 3:\n";
    student3.printStudentDetails();
    std::cout << "--------------------\n";

    // Test Case 4: Demonstrating robustness issue - negative ID and invalid grade are accepted
    Student student4("Charlie Brown", -5, 'X');
    std::cout << "Student 4 (Robustness Issue - Invalid Data):\n";
    student4.printStudentDetails();
    std::cout << "--------------------\n";

    return 0;
}