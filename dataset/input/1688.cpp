#include <iostream>
#include <string>

// Base class Employee
class Employee {
private:
    std::string name;
    int employeeID;

public:
    // Constructor: string parameter passed by value (inefficient), members assigned in body (less efficient/readable)
    Employee(std::string n, int id) {
        name = n;
        employeeID = id;
    }

    // Method to display details (missing const-correctness)
    void displayDetails() {
        std::cout << "Name: " << name << "\n";
        std::cout << "ID: " << employeeID << "\n";
    }
};

// Derived class Manager
class Manager : public Employee {
private:
    std::string department;

public:
    // Constructor: string parameter passed by value (inefficient), poor variable names, members assigned in body
    Manager(std::string n, int id, std::string dept) : Employee(n, id) {
        department = dept;
    }

    // Method to display details (missing const-correctness).
    // This implementation correctly calls the base method, but other readability/efficiency issues persist.
    void displayDetails() {
        Employee::displayDetails(); // Call base class method to display employee details
        std::cout << "Department: " << department << "\n";
    }
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