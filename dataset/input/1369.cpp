#include <iostream>
#include <string>

// Base class Person
class Person {
public:
    std::string name; // Public member: Accessible from anywhere
protected:
    int age;          // Protected member: Accessible from derived classes and within Person
private:
    std::string socialSecurityNumber; // Private member: Accessible only from within Person

public:
    // Constructor
    Person(std::string n, int a, std::string ssn) 
        : name(n), age(a), socialSecurityNumber(ssn) {}

    // A public method to allow Person itself to display its private member
    void displayPrivateInfo() const {
        std::cout << "Person's SSN (accessed via Person's own method): " << socialSecurityNumber << std::endl;
    }
};

// Derived class Student
class Student : public Person {
public:
    std::string studentId;

    // Constructor calls base class constructor
    Student(std::string n, int a, std::string ssn, std::string id)
        : Person(n, a, ssn), studentId(id) {}

    // Method to demonstrate access from the derived class
    void demonstrateAccess() const {
        std::cout << "--- Student Derived Class Access Attempt ---" << std::endl;
        std::cout << "Student ID: " << studentId << std::endl;

        // 1. Accessing 'public' member 'name' from base class
        std::cout << "Name (public, accessible from Student): " << name << std::endl;

        // 2. Accessing 'protected' member 'age' from base class
        std::cout << "Age (protected, accessible from Student): " << age << std::endl;

        // 3. Attempting to access 'private' member 'socialSecurityNumber' from base class
        // This line will cause a compile-time error, demonstrating a robustness issue
        // where the code attempts to violate encapsulation.
        std::cout << "Attempting to access private SSN directly from Student: " << socialSecurityNumber << std::endl; 
        // Expected compile-time error: 'std::string Person::socialSecurityNumber' is private within this context
        // This code is intentionally left with the error to illustrate the robustness issue:
        // the program fails to compile due to a fundamental access violation, indicating
        // a lack of robustness in the code's design for not adhering to access rules.
    }
};

int main() {
    // Creating a Student object will trigger the constructor, but the call to demonstrateAccess
    // will not happen if the compilation fails. The point of this example is the compilation failure itself.
    Student student1("Alice Smith", 20, "123-45-6789", "S001");
    student1.demonstrateAccess(); 

    // This part of the code would only execute if the above compile-time error was fixed.
    // student1.displayPrivateInfo(); // This would call Person's method, which can access SSN.

    return 0;
}