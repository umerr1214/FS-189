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
};

class Course {
private:
    std::string name;
    Student* assignedStudent; // Aggregation

public:
    Course(std::string name) : name(name), assignedStudent(nullptr) {
        std::cout << "Course " << name << " created." << std::endl;
    }

    // SEMANTIC ERROR: Course does not own the Student object (aggregation).
    // Deleting assignedStudent here violates the aggregation principle and leads to
    // undefined behavior (e.g., double-free if the Student is also deleted elsewhere,
    // or deleting memory not allocated by 'new' if Student was stack-allocated).
    ~Course() {
        std::cout << "Course " << name << " destroyed." << std::endl;
        if (assignedStudent != nullptr) {
            std::cout << "SEMANTIC ERROR: Attempting to delete assigned student '" << assignedStudent->name << "' from course " << name << std::endl;
            delete assignedStudent; // This is the semantic error.
        }
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
    // Students are dynamically allocated to clearly demonstrate the double-free issue
    // when Course attempts to delete them.
    Student* s1 = new Student("Alice", 101);
    Student* s2 = new Student("Bob", 102);

    Course c1("C++ Programming");
    Course c2("Data Structures");

    c1.display();
    c2.display();

    c1.assignStudent(s1);
    c1.display();

    c2.assignStudent(s2);
    c2.display();

    c1.unassignStudent();
    c1.display();

    // Test re-assignment
    c1.assignStudent(s2); // s2 is now assigned to c1. c2 still points to s2.
    c1.display();

    std::cout << "\n--- End of main scope, courses destroyed ---\n";
    // c1 and c2 destructors are called here.
    // c1's destructor will call delete s2.
    // c2's destructor will call delete s2 (again, causing double-free).
    // s1 was unassigned from c1, so c1's destructor won't delete s1.

    std::cout << "\n--- Manual cleanup of students ---\n";
    // This will attempt to delete s1 (correct) and s2 (double-free).
    delete s1; // Correct deletion for s1 (was unassigned and not deleted by Course)
    delete s2; // DOUBLE-FREE: s2 was already deleted by c1 and c2 destructors.

    return 0;
}