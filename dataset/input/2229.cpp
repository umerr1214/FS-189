#include <iostream>
#include <string>
#include <vector>

class Student {
private:
    std::string name;
    int id;

public:
    // Default constructor
    // Uses member initializer list for efficient initialization.
    Student() : name("Unknown"), id(0) {}

    // Parameterized constructor
    // Uses 'const std::string&' for 'newName' to avoid unnecessary copies (efficiency).
    // Uses member initializer list for efficient initialization.
    Student(const std::string& newName, int newId) : name(newName), id(newId) {
        // Optional: Add input validation for 'newId' here if specific constraints apply
        // (e.g., if ID must be positive). For this problem, no validation was requested,
        // so it's omitted for simplicity and direct adherence to the prompt.
    }

    // Getters for testing purposes (const-correctness for good practice)
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

    // Test parameterized constructor
    Student s2("Alice", 101);
    s2.printStudent(); // Expected: Student Name: Alice, ID: 101

    // Another test case
    Student s3("Charlie Brown", 333);
    s3.printStudent(); // Expected: Student Name: Charlie Brown, ID: 333

    return 0;
}