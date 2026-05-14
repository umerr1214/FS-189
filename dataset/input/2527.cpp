#include <iostream>
#include <string>
#include <vector> // Included for potential future use or to show a slightly larger header set
// #include <atomic> // This would be needed for a robust solution, but intentionally omitted for the bug

class Student {
private:
    std::string name;
    int studentID;
    // Robustness Issue: This static member is shared across all Student objects
    // and is modified without any synchronization mechanism.
    // In a multi-threaded environment, concurrent access to activeStudentsCount
    // during constructor/destructor calls would lead to a race condition and
    // an incorrect final count.
    static int activeStudentsCount;

public:
    // Default constructor
    Student() : name("Unknown"), studentID(0) {
        activeStudentsCount++; // Modifying shared resource without lock
    }

    // Parameterized constructor
    Student(const std::string& n, int id) : name(n), studentID(id) {
        activeStudentsCount++; // Modifying shared resource without lock
    }

    // Destructor
    ~Student() {
        std::cout << "Student " << name << " with ID " << studentID << " destroyed." << std::endl;
        activeStudentsCount--; // Modifying shared resource without lock
    }

    // Accessors
    std::string getName() const { return name; }
    int getStudentID() const { return studentID; }

    // Static method to get the current count of active students
    static int getActiveStudentsCount() {
        return activeStudentsCount;
    }
};

// Initialize the static member outside the class definition
int Student::activeStudentsCount = 0;

// Function to demonstrate object creation and destruction
void createAndDestroyStudents() {
    Student s1("Alice", 101); // activeStudentsCount = 2
    {
        Student s2("Bob", 102);     // activeStudentsCount = 3
        Student s3("Charlie", 103); // activeStudentsCount = 4
    } // s3 and s2 are destroyed here (reverse order of creation)
    // s3 destroyed: activeStudentsCount = 3
    // s2 destroyed: activeStudentsCount = 2
    Student s4("David", 104); // activeStudentsCount = 3
} // s4 and s1 are destroyed here (reverse order of creation)
// s4 destroyed: activeStudentsCount = 2
// s1 destroyed: activeStudentsCount = 1

int main() {
    std::cout << "Initial active students: " << Student::getActiveStudentsCount() << std::endl; // Expected: 0

    Student globalStudent("GlobalStudent", 999); // activeStudentsCount = 1
    std::cout << "After global student: " << Student::getActiveStudentsCount() << std::endl; // Expected: 1

    createAndDestroyStudents(); // This function will create and destroy several Student objects

    std::cout << "After function call: " << Student::getActiveStudentsCount() << std::endl; // Expected: 1 (globalStudent still active)

    return 0; // globalStudent is destroyed here
} // globalStudent destroyed: activeStudentsCount = 0