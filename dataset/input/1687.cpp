#include <iostream>
#include <string>

// Base class Employee
class Employee {
private:
    std::string name;
    int employeeID;

public:
    // Constructor using initializer list
    Employee(const std::string& name, int employeeID)
        : name(name), employeeID(employeeID) {}

    // Method to display details (missing const-correctness and not virtual)
    void displayDetails() {
        std::cout << "Name: " << name << "\n";
        std::cout << "ID: " << employeeID << "\n";
    }
    // Missing virtual destructor, which can be a robustness issue in polymorphic scenarios
};

// Derived class Manager
class Manager : public Employee {
private:
    std::string department;

public:
    // Constructor calling base constructor and using initializer list
    Manager(const std::string& name, int employeeID, const std::string& department)
        : Employee(name, employeeID), department(department) {}

    // Method to display details (missing const-correctness).
    // This implementation *only* displays the department, omitting inherited Employee details.
    // This is a robustness issue as it provides incomplete information for a Manager object.
    void displayDetails() {
        std::cout << "Department: " << department << "\n";
    }
    // Missing virtual destructor
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
    mgr.displayDetails(); // This will only print "Department: Sales"
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