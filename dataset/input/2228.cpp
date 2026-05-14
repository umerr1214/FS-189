#include <iostream>
#include <string>
#include <vector>

class Student {
private:
    std::string name;
    int id;

public:
    // Default constructor
    Student() {
        // Readability / Efficiency Issue: Not using member initializer list.
        // For std::string, this means default constructing 'name' then assigning,
        // which is less efficient than direct initialization.
        name = "Unknown";
        id = 0;
    }

    // Parameterized constructor
    Student(std::string newName, int newId) { // Readability / Efficiency Issue: newName passed by value
        // Readability / Efficiency Issue: Not using member initializer list.
        // 'newName' is copied twice: once when passed by value, and again during assignment.
        // For 'id', it's also assigned after default construction (though less impactful for int).
        name = newName;
        id = newId;
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

    // Test parameterized constructor
    Student s2("Alice", 101);
    s2.printStudent(); // Expected: Student Name: Alice, ID: 101

    // Another test
    Student s3("Bob", 500);
    s3.printStudent(); // Expected: Student Name: Bob, ID: 500

    return 0;
}