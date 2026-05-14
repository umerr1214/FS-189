#include <iostream>
#include <string>

// Robustness Issue: Attributes are public, violating encapsulation.
// This makes the class less robust against misuse, as external code can
// directly modify attributes to invalid states (e.g., negative age)
// without any validation or control.

class Person {
public: // Robustness Issue: Public attributes
    std::string name;
    int age;

    // Parameterized constructor for Person
    Person(std::string pName, int pAge) : name(pName), age(pAge) {
        // No validation for age, allows negative values (robustness issue)
    }

    void displayPersonInfo() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

class Student : public Person {
public: // Robustness Issue: Public attributes
    std::string studentId;

    // Student constructor chaining to Person's constructor
    Student(std::string pName, int pAge, std::string sId)
        : Person(pName, pAge), studentId(sId) {
        // No specific validation for studentId
    }

    void displayStudentInfo() const {
        displayPersonInfo(); // Call base class display
        std::cout << "Student ID: " << studentId << std::endl;
    }
};

int main() {
    // Test Case 1
    Student student1("Alice Smith", 20, "S1001");
    std::cout << "--- Student 1 ---" << std::endl;
    student1.displayStudentInfo();

    // Demonstrate robustness issue: direct modification
    student1.age = -5; // Directly setting an invalid age
    student1.studentId = ""; // Directly setting an empty ID
    std::cout << "\n--- Student 1 (After direct modification) ---" << std::endl;
    student1.displayStudentInfo();

    // Test Case 2
    Student student2("Bob Johnson", 22, "S1002");
    std::cout << "\n--- Student 2 ---" << std::endl;
    student2.displayStudentInfo();

    return 0;
}