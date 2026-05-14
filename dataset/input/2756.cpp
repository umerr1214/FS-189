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
    // Default constructor
    Person() : name(""), age(0) {}

    // Constructor passes string by value, causing a copy.
    Person(std::string n, int a) { // 'n' is a copy of the argument
        this->name = n; // Another copy/move operation occurs here
        this->age = a;
    }

    // Method to print Person details
    void printPersonDetails() const {
        std::cout << "Name: " << name << ", Age: " << age;
    }

    // Setter for name, passes string by value, causing another copy.
    void setName(std::string newName) { // 'newName' is a copy
        this->name = newName; // Another copy/move
    }
};

// Derived class Student
class Student : public Person {
private:
    int studentId;

public:
    // Constructor passes string by value, causing a copy.
    // It does not use the base class's parameterized constructor in its initializer list.
    // Instead, it implicitly calls Person's default constructor, then assigns to protected members.
    Student(std::string n, int a, int id) : studentId(id) { // 'n' is a copy
        // Implicitly calls Person() default constructor first.
        // Then, assigns to protected members. This is less efficient (extra default construction + assignment)
        // and less idiomatic than using Person(n, a) in the initializer list.
        this->name = n; // Assigns to protected member 'name' (another copy/move)
        this->age = a;  // Assigns to protected member 'age'
    }

    // Method to print full details for Student.
    // Not marked const, though it doesn't modify object state, reducing clarity and usage flexibility.
    void printFullDetails() { // Missing const qualifier
        printPersonDetails(); // Uses base class method
        std::cout << ", Student ID: " << studentId << std::endl;
    }
};

int main() {
    // Test case 1
    Student s1("Charlie Brown", 18, 2001);
    s1.printFullDetails();

    // Test case 2
    Student s2("Lucy Van Pelt", 19, 2002);
    s2.printFullDetails();

    return 0;
}