#include <iostream>
#include <string>
#include <utility> // Included for std::move, though const& is used here

class Student {
public:
    int studentID;
    std::string name;
    std::string major;

    // Default constructor - uses initializer list for efficiency and clarity
    Student() : studentID(0), name("N/A"), major("Undecided") {}

    // Parameterized constructor - uses initializer list and const references for efficiency and best practice
    Student(int id, const std::string& n, const std::string& m)
        : studentID(id), name(n), major(m) {}
    
    // Alternative for parameterized constructor (pass by value + move for potential optimization for rvalues):
    // Student(int id, std::string n, std::string m)
    //     : studentID(id), name(std::move(n)), major(std::move(m)) {}
    // The const& version used above is generally preferred for clarity when just copying.

    void display() const {
        std::cout << "ID: " << studentID << ", Name: " << name << ", Major: " << major << std::endl;
    }
};

int main() {
    // Test case for default constructor
    Student s1;
    std::cout << "Default Student: ";
    s1.display(); // Expected: ID: 0, Name: N/A, Major: Undecided

    // Test case for parameterized constructor
    Student s2(101, "Alice Smith", "Computer Science");
    std::cout << "Parameterized Student: ";
    s2.display(); // Expected: ID: 101, Name: Alice Smith, Major: Computer Science

    Student s3(102, "Bob Johnson", "Physics");
    std::cout << "Parameterized Student: ";
    s3.display(); // Expected: ID: 102, Name: Bob Johnson, Major: Physics

    // Additional test for a student with empty name/major (valid input)
    Student s4(103, "", "");
    std::cout << "Student with empty strings: ";
    s4.display(); // Expected: ID: 103, Name: , Major:

    return 0;
}