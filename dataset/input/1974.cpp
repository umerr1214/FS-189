#include <iostream>
#include <string>

class Student {
public:
    std::string name;
    int studentID;
    double gpa;
    static int totalStudents; // Declared static member

    Student(std::string n, int id, double g) : name(n), studentID(id), gpa(g) {
        totalStudents++;
    }

    void display() const {
        std::cout << "Name: " << name << ", ID: " << studentID << ", GPA: " << gpa << std::endl;
    }
};

// SEMANTIC ERROR: Static member `totalStudents` is declared but not defined outside the class.
// int Student::totalStudents = 0; // This line is missing, causing a linker error.

int main() {
    Student s1("Alice", 101, 3.8);
    Student s2("Bob", 102, 3.5);

    // Attempting to access totalStudents will lead to a linker error
    std::cout << "Total students created: " << Student::totalStudents << std::endl;

    s1.display();
    s2.display();

    return 0;
}