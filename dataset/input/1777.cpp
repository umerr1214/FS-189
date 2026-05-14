#include <iostream>
#include <string>
#include <vector> // Included for typical C++ programs, not strictly used here

class Student {
public:
    int studentID;
    std::string name;
    std::string major;

    // Default constructor: Initializes all members correctly as per prompt
    Student() : studentID(0), name("N/A"), major("Undecided") {
        // All members initialized correctly by initializer list
    }

    // Parameterized constructor with a robustness issue:
    // It correctly initializes studentID and name, but forgets to initialize major
    // with the provided argument, leaving it as a default-constructed std::string (empty string).
    Student(int id, const std::string& n, const std::string& m) : studentID(id), name(n) {
        // 'major' is not initialized in the initializer list, and also not assigned in the body.
        // This leaves 'major' as a default-constructed std::string, which is an empty string.
        // This is a robustness issue as the object state is not as expected by the caller.
        // It won't crash, but the data will be incorrect.
    }

    void display() const {
        std::cout << "ID: " << studentID << ", Name: " << name << ", Major: " << major << std::endl;
    }
};

int main() {
    // Test case for default constructor
    Student s1;
    std::cout << "Default Student: ";
    s1.display(); // Expected: ID: 0, Name: N/A, Major: Undecided

    // Test case for parameterized constructor (robustness issue here)
    Student s2(101, "Alice Smith", "Computer Science");
    std::cout << "Parameterized Student (expected CS, got empty): ";
    s2.display(); // Actual: ID: 101, Name: Alice Smith, Major: (empty string)

    Student s3(102, "Bob Johnson", "Physics");
    std::cout << "Parameterized Student (expected Physics, got empty): ";
    s3.display(); // Actual: ID: 102, Name: Bob Johnson, Major: (empty string)

    return 0;
}