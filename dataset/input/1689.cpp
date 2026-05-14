#include <iostream>
#include <string>

// Base class Employee
class Employee {
private:
    std::string name;
    int employeeID;

public:
    // Constructor using initializer list and const reference for string to avoid copying
    Employee(const std::string& name, int employeeID)
        : name(name), employeeID(employeeID) {}

    // Method to display details, marked virtual and const for best practices
    virtual void displayDetails() const {
        std::cout << "Name: " << name << "\n";
        std::cout << "ID: " << employeeID << "\n";
    }

    // Virtual destructor for proper cleanup in polymorphic scenarios
    virtual ~Employee() = default;
};

// Derived class Manager
class Manager : public Employee {
private:
    std::string department;

public:
    // Constructor calling base constructor and using initializer list for department
    Manager(const std::string& name, int employeeID, const std::string& department)
        : Employee(name, employeeID), department(department) {}

    // Method to display details, marked const and override for best practices
    void displayDetails() const override {
        Employee::displayDetails(); // Call base class method to display employee details
        std::cout << "Department: " << department << "\n";
    }

    // Destructor, marked override for best practices
    ~Manager() override = default;
};

int main() {
    // Test cases for Employee
    Employee emp("Alice Smith", 101);
    std::cout << "Employee Details:\n";
    emp.displayDetails();
    std::cout << "\n";

    // Test cases for Manager
    Manager mgr("Bob Johnson", 201, "Sales");
    std::cout << "Manager Details:\n";
    mgr.displayDetails();
    std::cout << "\n";

    Employee emp2("Charlie Brown", 102);
    std::cout << "Employee Details:\n";
    emp2.displayDetails();
    std::cout << "\n";

    Manager mgr2("Diana Prince", 202, "Marketing");
    std::cout << "Manager Details:\n";
    mgr2.displayDetails();
    std::cout << "\n";

    return 0;
}