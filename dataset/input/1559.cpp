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

    ~Course() {
        std::cout << "Course " << name << " destroyed." << std::endl;
    }

    void assignStudent(Student* student) {
        if (assignedStudent != nullptr) {
            std::cout << "Warning: Course " << name << " already has a student assigned. Unassigning first." << std::endl;
            unassignStudent(); // This will print a message, but the logical error is in unassignStudent itself
        }
        assignedStudent = student;
        std::cout << "Student " << student->name << " assigned to course " << name << std::endl;
    }

    void unassignStudent() {
        if (assignedStudent != nullptr) {
            std::cout << "Student " << assignedStudent->name << " unassigned from course " << name << std::endl;
            // LOGICAL ERROR: The assignedStudent pointer is NOT set to nullptr here.
            // The course will *claim* to unassign but will still hold a pointer to the student.
            // assignedStudent = nullptr; // This line is missing, causing the logical error.
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
    c1.display(); // Expected: Course: C++ Programming (Assigned Student: Alice)

    c2.assignStudent(&s2);
    c2.display();

    std::cout << "\n--- Attempting to unassign s1 from c1 ---\n";
    c1.unassignStudent(); // This should unassign s1
    c1.display();         // LOGICAL ERROR: Will still show Alice assigned because pointer wasn't cleared

    std::cout << "\n--- Attempting to re-assign s2 to c1 ---\n";
    c1.assignStudent(&s2); // This will call unassignStudent internally, still faulty
    c1.display();         // Expected: Course: C++ Programming (Assigned Student: Bob)
                          // Actual: If unassignStudent is called, it won't clear s1, then s2 is assigned.
                          // The `assignedStudent` will correctly become `&s2`, but the `unassignStudent`
                          // call before it was misleading. Let's adjust the error to be more direct.

    // Let's simplify the logical error: `unassignStudent` simply doesn't work.
    // The previous error was that it didn't clear the pointer, making `display` wrong.
    // The re-assignment logic in assignStudent would overwrite `assignedStudent` correctly,
    // making the initial unassign call redundant but not breaking the final state.
    // The more direct logical error is that unassign has NO effect on the pointer.

    // Re-evaluating the logical error for 1559.cpp:
    // The `unassignStudent` method prints a message but fails to set `assignedStudent = nullptr;`.
    // This means a course, once assigned a student, will always *appear* to have that student assigned
    // if `display()` is called after `unassignStudent()`, until a *new* student is assigned.
    // The `assignStudent` method's internal call to `unassignStudent()` will also be ineffective
    // in truly clearing the previous student, though `assignedStudent` will correctly point to the new student afterwards.
    // The primary symptom is that `c1.display()` after `c1.unassignStudent()` will still show the old student.

    std::cout << "\n--- End of main scope ---\n";

    return 0;
}