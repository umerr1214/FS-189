#include <iostream>
#include <string>
#include <vector> // Included for potential future use or consistency, though not strictly required by core classes.

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
    // Constructor for Course
    Course(const std::string& n) : name(n), assignedStudent(nullptr) {}

    // Destructor for Course
    // IMPORTANT for aggregation: Do NOT delete assignedStudent here.
    // The Course class does not own the Student object's memory.
    ~Course() {
        // No delete assignedStudent; as per aggregation pattern.
    }

    // Assign a student to the course
    // ROBUSTNESS ISSUE: Does not check if 'student' is nullptr before assignment.
    // Also, allows re-assigning without checking if it's the same student or if a student is already assigned.
    void assignStudent(Student* student) {
        assignedStudent = student;
    }

    // Unassign the current student from the course
    // ROBUSTNESS ISSUE: Redundantly sets assignedStudent to nullptr even if it's already nullptr.
    // No check if a student is actually assigned.
    void unassignStudent() {
        assignedStudent = nullptr;
    }

    // Method to get course name
    const std::string& getName() const { return name; }

    // Method to get the assigned student's name
    // ROBUSTNESS ISSUE: DEREFERENCING POTENTIAL NULLPTR WITHOUT CHECK.
    // If assignedStudent is nullptr, this will cause a segmentation fault (crash).
    std::string getAssignedStudentName() const {
        return assignedStudent->getName(); // CRITICAL FLAW: Potential crash point
    }
};

// Driver code to demonstrate the robustness issue
int main() {
    Student alice("Alice Smith");
    Student bob("Bob Johnson");

    Course mathCourse("Calculus I");

    std::cout << "--- Initial State ---" << std::endl;
    std::cout << "Course: " << mathCourse.getName() << std::endl;
    // Attempting to call getAssignedStudentName() here would crash if not careful.
    // We'll demonstrate the crash after unassigning.

    std::cout << "\n--- Assigning Alice ---" << std::endl;
    mathCourse.assignStudent(&alice);
    std::cout << "Course: " << mathCourse.getName() << ", Assigned Student: " << mathCourse.getAssignedStudentName() << std::endl;

    std::cout << "\n--- Unassigning student ---" << std::endl;
    mathCourse.unassignStudent(); // assignedStudent is now nullptr
    std::cout << "Course: " << mathCourse.getName() << std::endl;

    std::cout << "\n--- Attempting to get student name after unassigning (EXPECTED CRASH) ---" << std::endl;
    // This line will cause a segmentation fault because assignedStudent is nullptr
    // and getAssignedStudentName() does not perform a nullptr check.
    std::cout << "Course: " << mathCourse.getName() << ", Assigned Student: " << mathCourse.getAssignedStudentName() << std::endl;

    // The program will likely terminate before reaching here after the crash.
    // If it didn't crash, it would print an empty string or garbage depending on compiler/platform.

    return 0;
}