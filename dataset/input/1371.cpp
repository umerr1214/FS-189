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

    // Public method to display Person's public, protected, and private info
    // Note: private and protected members are accessible within their own class methods.
    void displayPersonInfo() const {
        std::cout << "--- Person Base Class Info (from Person object) ---" << std::endl;
        std::cout << "Name (public): " << name << std::endl;
        std::cout << "Age (protected, via Person's public method): " << age << std::endl;
        std::cout << "Social Security Number (private, via Person's public method): " << socialSecurityNumber << std::endl;
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
    void demonstrateAccessFromStudent() const {
        std::cout << "\n--- Student Derived Class Access Demonstration ---" << std::endl;
        std::cout << "Student ID: " << studentId << std::endl;

        // 1. Accessing 'public' member 'name' from base class
        std::cout << "\n1. Accessing 'public' member 'name':" << std::endl;
        std::cout << "   - 'name' is public in Person." << std::endl;
        std::cout << "   - It is directly accessible from Student (derived class)." << std::endl;
        std::cout << "   Student's Name: " << name << std::endl;

        // 2. Accessing 'protected' member 'age' from base class
        std::cout << "\n2. Accessing 'protected' member 'age':" << std::endl;
        std::cout << "   - 'age' is protected in Person." << std::endl;
        std::cout << "   - It is directly accessible from Student (derived class)." << std::endl;
        std::cout << "   Student's Age: " << age << std::endl;

        // 3. Attempting to access 'private' member 'socialSecurityNumber' from base class
        std::cout << "\n3. Attempting to access 'private' member 'socialSecurityNumber':" << std::endl;
        std::cout << "   - 'socialSecurityNumber' is private in Person." << std::endl;
        std::cout << "   - It is NOT accessible directly from Student (derived class)." << std::endl;
        std::cout << "   - Trying to access it directly (e.g., 'socialSecurityNumber') would result in a compile-time error." << std::endl;
        std::cout << "   - To access it, a public or protected method *within the Person class itself* would be needed." << std::endl;
        // Example of what would cause an error (commented out to allow compilation):
        // std::cout << "   Inaccessible SSN: " << socialSecurityNumber << std::endl; 
    }
};

int main() {
    // Create a Person object and display its info
    Person person1("John Doe", 35, "000-11-2222");
    person1.displayPersonInfo();

    // Create a Student object and demonstrate access
    Student student1("Jane Smith", 20, "123-45-6789", "S1001");
    student1.demonstrateAccessFromStudent();

    std::cout << "\n--- External Access (from main function) ---" << std::endl;
    // Accessing public members directly from main
    std::cout << "Accessing person1.name (public): " << person1.name << std::endl;
    std::cout << "Accessing student1.name (public inherited): " << student1.name << std::endl;
    std::cout << "Accessing student1.studentId (public): " << student1.studentId << std::endl;

    // Attempting to access protected member 'age' from outside the class hierarchy (main)
    std::cout << "\nAttempting to access person1.age (protected) from main: NOT ACCESSIBLE." << std::endl;
    std::cout << "   - Uncommenting 'person1.age' would cause a compile-time error." << std::endl;
    // person1.age; // Compile-time error: 'int Person::age' is protected within this context

    // Attempting to access private member 'socialSecurityNumber' from outside the class hierarchy (main)
    std::cout << "Attempting to access person1.socialSecurityNumber (private) from main: NOT ACCESSIBLE." << std::endl;
    std::cout << "   - Uncommenting 'person1.socialSecurityNumber' would cause a compile-time error." << std::endl;
    // person1.socialSecurityNumber; // Compile-time error: 'std::string Person::socialSecurityNumber' is private within this context

    return 0;
}