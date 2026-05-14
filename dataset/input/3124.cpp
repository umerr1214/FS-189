#include <iostream>
#include <string>

// The Student class definition is missing a semicolon at the end,
// which is a syntax error.
class Student {
public:
    std::string name;
    int id;
    double grade;

    // Default constructor
    Student() : name(""), id(0), grade(0.0) {}

    // Parameterized constructor
    Student(std::string n, int i, double g) : name(n), id(i), grade(g) {}

    void display() const {
        std::cout << "Name: " << name << ", ID: " << id << ", Grade: " << grade << std::endl;
    }
} // SYNTAX ERROR: Missing semicolon here

int main() {
    // Test default constructor
    Student s1;
    s1.display();

    // Test parameterized constructor
    Student s2("Alice", 101, 95.5);
    s2.display();

    Student s3("Bob", 202, 88.0);
    s3.display();

    return 0;
}