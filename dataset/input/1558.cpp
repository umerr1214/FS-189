#include <iostream>
#include <string>
#include <vector>

class Student {
public:
    std::string name;
    int id;

    Student(std::string name, int id) : name(name), id(id) {
        std::cout << "Student " << name << " created." << std::endl;
    }

    ~Student() {
        std::cout << "Student " << name << " destroyed." << std::endl;
    }

    void display() const {
        std::cout << "Student: " << name << " (ID: " << id << ")" << std::endl;
    }
} // SYNTAX ERROR: Missing semicolon here

class Course {
private:
    std::string name;
    Student* assignedStudent; // Aggregation

public:
    Course(std::string name) : name(name), assignedStudent(nullptr) {
        std::cout << "Course " << name << " created." << std::endl;
    }

    ~Course() {
        std::cout << "Course " << name << " destroyed." << std::endl;
    }

    void assignStudent(Student* student) {
        if (assignedStudent != nullptr) {
            std::cout << "Warning: Course " << name << " already has a student assigned. Unassigning first." << std::endl;
            unassignStudent();
        }
        assignedStudent = student;
        std::cout << "Student " << student->name << " assigned to course " << name << std::endl;
    }

    void unassignStudent() {
        if (assignedStudent != nullptr) {
            std::cout << "Student " << assignedStudent->name << " unassigned from course " << name << std::endl;
            assignedStudent = nullptr;
        } else {
            std::cout << "No student assigned to course " << name << " to unassign." << std::endl;
        }
    }

    void display() const {
        std::cout << "Course: " << name;
        if (assignedStudent != nullptr) {
            std::cout << " (Assigned Student: " << assignedStudent->name << ")";
        } else {
            std::cout << " (No student assigned)";
        }
        std::cout << std::endl;
    }
};

int main() {
    Student s1("Alice", 101);
    Student s2("Bob", 102);

    Course c1("C++ Programming");
    Course c2("Data Structures");

    c1.display();
    c2.display();

    c1.assignStudent(&s1);
    c1.display();

    c2.assignStudent(&s2);
    c2.display();

    c1.unassignStudent();
    c1.display();

    // Test re-assignment
    c1.assignStudent(&s2);
    c1.display();

    std::cout << "\n--- End of main scope ---\n";

    return 0;
}