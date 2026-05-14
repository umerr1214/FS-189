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
    // Parameterized constructor using initializer list and const reference for string to avoid copies
    Person(const std::string& n, int a) : name(n), age(a) {}

    // Method to print Person details, marked const as it doesn't modify object state
    void printPersonDetails() const {
        std::cout << "Name: " << name << ", Age: " << age;
    }
};

// Derived class Student
class Student : public Person {
private:
    int studentId;

public:
    // Constructor uses initializer list to call base class constructor and initialize studentId
    // Passes string by const reference for efficiency.
    Student(const std::string& n, int a, int id) : Person(n, a), studentId(id) {}

    // Method to print full details for Student, marked const as it doesn't modify object state
    void printFullDetails() const {
        printPersonDetails(); // Access protected members via base class method
        std::cout << ", Student ID: " << studentId << std::endl;
    }
};

int main() {
    // Test case 1: Standard student
    Student s1("David Lee", 21, 3001);
    s1.printFullDetails();

    // Test case 2: Another student
    Student s2("Emily Chen", 19, 3002);
    s2.printFullDetails();

    // Test case 3: Student with a longer name
    Student s3("Ferdinand Maximilian Von Habsburg", 23, 3003);
    s3.printFullDetails();

    return 0;
}