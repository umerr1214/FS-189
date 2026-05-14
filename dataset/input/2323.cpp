#include <iostream>
#include <string>
#include <vector> // Included for potential future use, not strictly needed here

// Base class Person
class Person {
public:
    std::string name;
    int age;

    // Constructor for Person
    Person(std::string n, int a) {
        name = n; // No validation for age
        age = a;
    }

    void displayPersonInfo() const {
        std::cout << "Person Name: " << name << ", Age: " << age << std::endl;
    }
};

// Derived class Teacher
class Teacher : public Person {
public:
    std::string subject;
    double salary;

    // Constructor for Teacher, calling Person's constructor
    Teacher(std::string n, int a, std::string s, double sal)
        : Person(n, a) { // Base class constructor call
        subject = s; // No validation for salary
        salary = sal;
    }

    void displayTeacherInfo() const {
        displayPersonInfo(); // Re-use base class display
        std::cout << "Subject: " << subject << ", Salary: $" << salary << std::endl;
    }
};

int main() {
    // Demonstrating the robustness issue: allowing invalid data
    std::cout << "--- Robustness Issue Demonstration ---" << std::endl;

    // Create a Person with an invalid age (negative)
    Person person1("Alice", -5);
    person1.displayPersonInfo(); // Displays invalid age

    std::cout << std::endl;

    // Create a Teacher with an invalid salary (negative)
    Teacher teacher1("Bob", 35, "Math", -1500.00);
    teacher1.displayTeacherInfo(); // Displays invalid salary

    std::cout << std::endl;

    // Another example with potentially misleading data
    Teacher teacher2("Charlie", 40, "Physics", 0.0); // Zero salary might be valid but unusual
    teacher2.displayTeacherInfo();

    return 0;
}