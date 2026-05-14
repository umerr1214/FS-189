#include <iostream>
#include <string>

class Student {
public:
    int studentID;
    std::string name;
    std::string major;

    // Default constructor - readability issue (assignments in body instead of initializer list)
    Student() {
        studentID = 0;
        name = "N/A";
        major = "Undecided";
    }

    // Parameterized constructor - efficiency issue (pass by value, assignments in body)
    Student(int id, std::string n, std::string m) { // Pass by value creates copies of n and m
        this->studentID = id; // Mixing this-> with direct access (minor readability)
        name = n;             // n is a copy, then assigned to name (another copy/move)
        this->major = m;      // m is a copy, then assigned to major (another copy/move)
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

    // Test case for parameterized constructor (efficiency issue here)
    Student s2(101, "Alice Smith", "Computer Science");
    std::cout << "Parameterized Student: ";
    s2.display(); // Expected: ID: 101, Name: Alice Smith, Major: Computer Science

    Student s3(102, "Bob Johnson", "Physics");
    std::cout << "Parameterized Student: ";
    s3.display(); // Expected: ID: 102, Name: Bob Johnson, Major: Physics

    return 0;
}