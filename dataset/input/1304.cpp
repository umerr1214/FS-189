#include <iostream>
#include <vector>
#include <string>
#include <utility> // For std::move

class Employee {
public:
    std::string name;
    int id;

    Employee(std::string name, int id) : name(std::move(name)), id(id) {}

    void display() const {
        std::cout << "  ID: " << id << ", Name: " << name << std::endl;
    }
};

class Department {
public:
    std::string name;
    std::vector<Employee> employees; // Stores Employee objects directly (by value)

    Department(std::string name) : name(std::move(name)) {}

    // Readability / Efficiency Issue:
    // 1. Takes Employee by value, causing an unnecessary copy of the Employee object
    //    every time an employee is added. If Employee objects were large, this would be inefficient.
    // 2. Uses std::endl frequently, which flushes the buffer each time, potentially reducing performance.
    void addEmployee(Employee emp) { // Employee passed by value
        employees.push_back(emp); // Another copy (or move if emp is an rvalue)
        std::cout << "Added employee " << emp.name << " to " << name << "." << std::endl << std::endl; // Excessive std::endl
    }

    void displayStaff() const {
        std::cout << "Department: " << name << std::endl << std::endl; // Excessive std::endl
        std::cout << "Staff:" << std::endl;
        if (employees.empty()) {
            std::cout << "  No staff currently." << std::endl << std::endl; // Excessive std::endl
        } else {
            for (const auto& emp : employees) {
                emp.display(); // Employee::display also uses std::endl
            }
        }
        std::cout << "--- End of Staff List ---" << std::endl << std::endl; // Excessive std::endl
    }
};

int main() {
    // Create employees
    Employee emp1("Alice Johnson", 101);
    Employee emp2("Bob Smith", 102);
    Employee emp3("Charlie Brown", 103);

    // Create a department
    Department sales("Sales");

    // Add employees to the department (each call involves a copy)
    sales.addEmployee(emp1);
    sales.addEmployee(emp2);
    sales.addEmployee(emp3);

    // Display staff
    sales.displayStaff();

    // Demonstrate another department with different employees
    Department marketing("Marketing");
    Employee emp4("Diana Prince", 201);
    marketing.addEmployee(emp4);
    marketing.displayStaff();

    return 0;
}