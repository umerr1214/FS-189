#include <iostream>
#include <string>
#include <vector> // Included for completeness

class Student {
private:
    std::string m_studentName; // Inconsistent naming convention
    int studentId; // Inconsistent naming convention
    double studentGrade; // Inconsistent naming convention

public:
    // Default constructor
    Student() {
        this->m_studentName = ""; // Explicit 'this->' usage
        this->studentId = 0;
        this->studentGrade = 0.0;
    }

    // Parameterized constructor
    Student(std::string name, int id, double grade) // Name passed by value
        : m_studentName(name), studentId(id), studentGrade(grade) {}

    // Getter for name
    std::string getStudentName() const { // Returns by value
        return this->m_studentName;
    }

    // Setter for name - Takes std::string by value, causing an unnecessary copy
    void setStudentName(std::string name) {
        this->m_studentName = name; // Another copy here
    }

    // Getter for id
    int getStudentId() const {
        return this->studentId;
    }

    // Setter for id
    void setStudentId(int id) {
        this->studentId = id;
    }

    // Getter for grade
    double getStudentGrade() const {
        return this->studentGrade;
    }

    // Setter for grade
    void setStudentGrade(double grade) {
        this->studentGrade = grade;
    }
};

int main() {
    Student s;
    s.setStudentName("Alice");
    s.setStudentId(101);
    s.setStudentGrade(95.5);

    std::cout << "Student 1:" << std::endl;
    std::cout << "Name: " << s.getStudentName() << std::endl;
    std::cout << "ID: " << s.getStudentId() << std::endl;
    std::cout << "Grade: " << s.getStudentGrade() << std::endl;

    std::cout << "\nUpdating Student 1 data:" << std::endl;
    s.setStudentName("Alicia");
    s.setStudentId(102);
    s.setStudentGrade(97.0);

    std::cout << "Name: " << s.getStudentName() << std::endl;
    std::cout << "ID: " << s.getStudentId() << std::endl;
    std::cout << "Grade: " << s.getStudentGrade() << std::endl;

    Student s2("Bob", 202, 88.0); // Uses constructor with string by value
    std::cout << "\nStudent 2:" << std::endl;
    std::cout << "Name: " << s2.getStudentName() << std::endl;
    std::cout << "ID: " << s2.getStudentId() << std::endl;
    std::cout << "Grade: " << s2.getStudentGrade() << std::endl;

    return 0;
}