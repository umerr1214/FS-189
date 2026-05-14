#include <iostream>
#include <string>
#include <vector>
#include <sstream>

// Base class Person
class Person {
protected:
    std::string name;
    int age;

public:
    // Constructor allows potentially non-sensical age (e.g., negative)
    // Passes string by value, which is not ideal but not the primary robustness issue here.
    Person(std::string n, int a) : name(n), age(a) {}

    // Method to print Person details
    void printPersonDetails() const {
        // No validation for name or age before printing.
        // For example, if name is empty, it prints "Name: , Age: X".
        // If age is negative, it prints "Age: -X".
        std::cout << "Name: " << name << ", Age: " << age;
    }
};

// Derived class Student
class Student : public Person {
private:
    int studentId;

public:
    // Constructor allows potentially non-sensical age or studentId (e.g., negative)
    // Passes string by value, which is not ideal but not the primary robustness issue here.
    Student(std::string n, int a, int id) : Person(n, a), studentId(id) {}

    // Method to print full details for Student
    void printFullDetails() const {
        // No validation for name, age, or studentId before printing.
        // It simply prints whatever values are stored, even if they are semantically invalid.
        printPersonDetails(); // Uses base class method
        std::cout << ", Student ID: " << studentId << std::endl;
    }
};

int main() {
    // Test case 1: Valid data
    Student s1("Alice Smith", 20, 1001);
    s1.printFullDetails();

    // Test case 2: Potentially invalid/nonsensical data
    // A robust program might handle negative age or ID differently,
    // e.g., print "Invalid Age" or throw an error. This code just prints it.
    Student s2("Bob Johnson", -5, -123); // Example of non-robust handling of invalid data
    s2.printFullDetails();

    // Test case 3: Empty name
    Student s3("", 22, 1003); // A robust program might print "Unknown Name" or similar
    s3.printFullDetails();

    return 0;
}