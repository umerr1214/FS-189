#include <iostream>
#include <string>

class Student {
public:
    std::string name; // Public members, less encapsulated
    int studentID;
    double gpa;
    static int totalStudents;

    // Constructor without initializer list, using assignment in body (less efficient for strings)
    Student(std::string studentName, int studentId, double studentGpa) {
        this->name = studentName; // Excessive this->
        this->studentID = studentId;
        this->gpa = studentGpa;
        Student::totalStudents++; // Using class name prefix, not strictly bad but can be simplified
    }

    ~Student() {
        Student::totalStudents--; // Correctly decremented, but other issues exist
    }

    void displayStudent() const { // Not using const reference for name/id/gpa if they were private getters
        std::cout << "Student Name: " << this->name << std::endl; // Excessive this->
        std::cout << "Student ID: " << this->studentID << std::endl;
        std::cout << "Student GPA: " << this->gpa << std::endl;
        std::cout << "--------------------" << std::endl;
    }
};

// Initialize static member
int Student::totalStudents = 0;

int main() {
    std::cout << "Total students count: " << Student::totalStudents << std::endl;

    Student student1("Alice Smith", 1001, 3.95);
    student1.displayStudent();
    std::cout << "Total students count: " << Student::totalStudents << std::endl;

    {
        Student student2("Bob Johnson", 1002, 3.40);
        student2.displayStudent();
        Student student3("Charlie Brown", 1003, 3.70);
        student3.displayStudent();
        std::cout << "Total students count: " << Student::totalStudents << std::endl;
    }

    std::cout << "Total students count after block: " << Student::totalStudents << std::endl;

    Student student4("Diana Prince", 1004, 4.00);
    student4.displayStudent();
    std::cout << "Total students count: " << Student::totalStudents << std::endl;

    return 0;
}