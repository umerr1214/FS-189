#include <iostream>
#include <string>
#include <vector> // Unnecessary header for this simple problem, but included.

// Base class Person with public members and assignment in constructor body
class Person {
public: // All members are public, breaking encapsulation
    std::string name;
    int age;

    // Constructor for Person, using assignment in the body (less efficient for complex types)
    Person(std::string n, int a) {
        this->name = n; // Unnecessary use of 'this->'
        this->age = a;   // Unnecessary use of 'this->'
    }

    void displayPersonInfo() const {
        std::cout << "Person Name: " << this->name << ", Age: " << this->age << std::endl; // Unnecessary use of 'this->'
    }
};

// Derived class Teacher with public members and assignment in constructor body
class Teacher : public Person {
public: // All members are public, breaking encapsulation
    std::string subject;
    double salary;

    // Constructor for Teacher, calling Person's constructor and using assignment for its own members
    Teacher(std::string n, int a, std::string s, double sal)
        : Person(n, a) { // Correctly calls base constructor
        this->subject = s;   // Assignment in body, less efficient than initializer list for string
        this->salary = sal;  // Assignment in body
    }

    void displayTeacherInfo() const {
        // Calls base class display, but could also duplicate logic for Person members
        this->displayPersonInfo(); // Unnecessary use of 'this->'
        std::cout << "Subject: " << this->subject << ", Salary: $" << this->salary << std::endl; // Unnecessary use of 'this->'
    }
};

int main() {
    std::cout << "--- Readability / Efficiency Issue Demonstration ---" << std::endl;

    // Create a Person object
    Person person1("Alice", 30);
    person1.displayPersonInfo();

    std::cout << std::endl;

    // Create a Teacher object
    Teacher teacher1("Bob", 45, "Chemistry", 75000.50);
    teacher1.displayTeacherInfo();

    std::cout << std::endl;

    // Demonstrate direct access to public members (readability/encapsulation issue)
    std::cout << "Direct access to public members (Person): " << teacher1.name << ", " << teacher1.age << std::endl;
    teacher1.salary = 80000.0; // Directly modifying a public member
    std::cout << "Modified salary directly: $" << teacher1.salary << std::endl;

    return 0;
}