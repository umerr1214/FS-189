#include <iostream>
#include <string>
#include <vector>

class Student {
private:
    std::string name;
    int id;

public:
    // Default constructor
    Student() : name("Unknown"), id(0) {
        // No input validation for default values, which are hardcoded.
    }

    // Parameterized constructor
    Student(std::string newName, int newId) : name(newName), id(newId) {
        // Robustness Issue: No validation for 'newId'.
        // If 'id' is expected to be non-negative or within a certain range
        // (common for IDs), this constructor allows creation of students
        // with invalid IDs (e.g., negative) without any checks.
        // This can lead to incorrect state or crashes later if other parts
        // of the system assume valid ID ranges.
    }

    // Getters for testing purposes
    std::string getName() const {
        return name;
    }

    int getId() const {
        return id;
    }

    void printStudent() const {
        std::cout << "Student Name: " << name << ", ID: " << id << std::endl;
    }
};

int main() {
    // Test default constructor
    Student s1;
    s1.printStudent(); // Expected: Student Name: Unknown, ID: 0

    // Test parameterized constructor with valid data
    Student s2("Alice", 101);
    s2.printStudent(); // Expected: Student Name: Alice, ID: 101

    // Test parameterized constructor with a potentially invalid ID (robustness issue)
    // The constructor allows this without any checks.
    Student s3("Bob", -5);
    s3.printStudent(); // Expected: Student Name: Bob, ID: -5

    // Another test
    Student s4("Charlie", 999999);
    s4.printStudent(); // Expected: Student Name: Charlie, ID: 999999

    return 0;
}