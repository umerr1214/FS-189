#include <iostream>
#include <string>
#include <vector>

class Student {
public:
    std::string name;
    int studentID;
    double gpa;
    static int totalStudents;

    Student(std::string name, int studentID, double gpa) : name(name), studentID(studentID), gpa(gpa) {
        totalStudents++;
    }

    // Robustness Issue: Destructor is missing totalStudents--
    ~Student() {
        // totalStudents--; // This line is intentionally missing, leading to an incorrect count
    }

    void displayStudent() const {
        std::cout << "Name: " << name << ", ID: " << studentID << ", GPA: " << gpa << std::endl;
    }
};

// Initialize static member
int Student::totalStudents = 0;

int main() {
    std::cout << "Initial total students: " << Student::totalStudents << std::endl;

    Student s1("Alice", 101, 3.8);
    s1.displayStudent();
    std::cout << "After s1 created, total students: " << Student::totalStudents << std::endl;

    {
        Student s2("Bob", 102, 3.5);
        s2.displayStudent();
        Student s3("Charlie", 103, 3.9);
        s3.displayStudent();
        std::cout << "Inside block, after s2, s3 created, total students: " << Student::totalStudents << std::endl;
    } // s2 and s3 go out of scope here, but totalStudents is not decremented

    std::cout << "After block, total students: " << Student::totalStudents << std::endl;

    Student s4("David", 104, 3.2);
    s4.displayStudent();
    std::cout << "After s4 created, total students: " << Student::totalStudents << std::endl;

    return 0;
}