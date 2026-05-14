#include <iostream>
#include <string>
#include <vector>

class Employee {
public:
    std::string name;
    double salary;

    Employee(std::string n, double s) : name(n), salary(s) {}

    virtual void display() const {
        std::cout << "Name: " << name << ", Salary: " << salary << std::endl;
    }
};

class Manager : public Employee {
public:
    std::string department;

    // Logical error: The 'department' is always initialized to "General"
    // instead of using the provided 'd' parameter.
    Manager(std::string n, double s, std::string d) : Employee(n, s), department("General") {}
    
    void display() const override {
        std::cout << "Manager - ";
        Employee::display();
        std::cout << "  Department: " << department << std::endl;
    }
};

class Engineer : public Employee {
public:
    std::string specialization;

    Engineer(std::string n, double s, std::string spec) : Employee(n, s), specialization(spec) {}

    void display() const override {
        std::cout << "Engineer - ";
        Employee::display();
        std::cout << "  Specialization: " << specialization << std::endl;
    }
};

int main() {
    Manager m("Alice", 75000.0, "HR");
    Engineer e("Bob", 60000.0, "Software");

    std::cout << "Manager details:" << std::endl;
    m.display(); // This will show Department: General, not HR

    std::cout << "\nEngineer details:" << std::endl;
    e.display();

    // Verification for the logical error
    std::cout << "\n--- Verification ---" << std::endl;
    if (m.department == "HR") {
        std::cout << "Test Passed: Manager's department is correctly set." << std::endl;
    } else {
        std::cout << "Test Failed: Manager's department is incorrectly set to '" << m.department << "'. Expected 'HR'." << std::endl;
    }

    return 0;
}