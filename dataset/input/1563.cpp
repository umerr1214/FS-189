#include <iostream>
#include <string>
#include <vector> // Included for potential future use or consistency.

// Student class definition
class Student {
private:
    std::string name;
public:
    // Constructor for Student
    Student(const std::string& n) : name(n) {}

    // Method to get student's name
    const std::string& getName() const { return name; }
};

// Course class definition, demonstrating aggregation
class Course {
private:
    std::string name;
    Student* assignedStudent; // Aggregation: Course has a Student, but does not own its lifetime.
                              // The Student object can exist independently.
public:
    // Constructor for Course: Initializes name and sets assignedStudent to nullptr.
    Course(const std::string& n) : name(n), assignedStudent(nullptr) {}

    // Destructor for Course:
    // IMPORTANT for aggregation: Do NOT delete assignedStudent here.
    // The Course class does not own the Student object's memory; it only holds a pointer to it.
    ~Course() {
        // No delete assignedStudent; as per aggregation pattern.
    }

    // Assign a student to the course.
    // This method is robust, checking for null input and existing assignments.
    void assignStudent(Student* student) {
        if (student == nullptr) {
            std::cout << "Attempted to assign a null student to course '" << name << "'. No action taken." << std::endl;
            return;
        }
        if (assignedStudent == student) {
            std::cout << "Student '" << student->getName() << "' is already assigned to course '" << name << "'. No change needed." << std::endl;
            return;
        }
        if (assignedStudent != nullptr) {
            std::cout << "Student '" << assignedStudent->getName() << "' unassigned from course '" << name << "' before assigning new student." << std::endl;
        }
        assignedStudent = student;
        std::cout << "Student '" << student->getName() << "' assigned to course '" << name << "'." << std::endl;
    }

    // Unassign the current student from the course.
    // This method is robust, checking if a student is actually assigned before unassigning.
    void unassignStudent() {
        if (assignedStudent != nullptr) {
            std::cout << "Student '" << assignedStudent->getName() << "' unassigned from course '" << name << "'." << std::endl;
            assignedStudent = nullptr;
        } else {
            std::cout << "No student was assigned to course '" << name << "' to unassign. No action taken." << std::endl;
        }
    }

    // Method to get course name
    const std::string& getName() const { return name; }

    // Method to get the assigned student's name.
    // This method is robust, checking for nullptr before dereferencing.
    std::string getAssignedStudentName() const {
        if (assignedStudent != nullptr) {
            return assignedStudent->getName();
        } else {
            return "No student assigned";
        }
    }
};

// Driver code to demonstrate the correct implementation
int main() {
    Student alice("Alice Smith");
    Student bob("Bob Johnson");

    Course mathCourse("Calculus I");

    std::cout << "--- Initial State ---" << std::endl;
    std::cout << "Course: " << mathCourse.getName() << ", Assigned Student: " << mathCourse.getAssignedStudentName() << std::endl;

    std::cout << "\n--- Assigning Alice ---" << std::endl;
    mathCourse.assignStudent(&alice);
    std::cout << "Course: " << mathCourse.getName() << ", Assigned Student: " << mathCourse.getAssignedStudentName() << std::endl;

    std::cout << "\n--- Re-assigning Alice (same student) ---" << std::endl;
    mathCourse.assignStudent(&alice); // Should detect same student
    std::cout << "Course: " << mathCourse.getName() << ", Assigned Student: " << mathCourse.getAssignedStudentName() << std::endl;

    std::cout << "\n--- Assigning Bob (replaces Alice) ---" << std::endl;
    mathCourse.assignStudent(&bob);
    std::cout << "Course: " << mathCourse.getName() << ", Assigned Student: " << mathCourse.getAssignedStudentName() << std::endl;

    std::cout << "\n--- Unassigning student ---" << std::endl;
    mathCourse.unassignStudent();
    std::cout << "Course: " << mathCourse.getName() << ", Assigned Student: " << mathCourse.getAssignedStudentName() << std::endl;

    std::cout << "\n--- Unassigning again (no student assigned) ---" << std::endl;
    mathCourse.unassignStudent(); // Should handle gracefully
    std::cout << "Course: " << mathCourse.getName() << ", Assigned Student: " << mathCourse.getAssignedStudentName() << std::endl;

    std::cout << "\n--- Attempting to assign nullptr ---" << std::endl;
    mathCourse.assignStudent(nullptr); // Should handle gracefully
    std::cout << "Course: " << mathCourse.getName() << ", Assigned Student: " << mathCourse.getAssignedStudentName() << std::endl;

    std::cout << "\n--- Assigning Alice again for final check ---" << std::endl;
    mathCourse.assignStudent(&alice);
    std::cout << "Course: " << mathCourse.getName() << ", Assigned Student: " << mathCourse.getAssignedStudentName() << std::endl;

    return 0;
}