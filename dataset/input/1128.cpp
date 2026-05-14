#include <iostream>
#include <vector>
#include <string>
#include <utility> // For std::move
#include <algorithm> // For std::remove_if if needed.

class Employee {
public:
    std::string name;
    int id;

    Employee(std::string name, int id) : name(std::move(name)), id(id) {}

    void display() const {
        std::cout << "  Employee ID: " << id << ", Name: " << name << std::endl;
    }
};

class Department {
public:
    std::string name;
    // SEMANTIC ERROR: This stores Employee objects by value (copies), breaking aggregation.
    // The Department now owns copies of employees, and the original Employee objects
    // cannot be "added to multiple departments" in the sense of the same instance.
    std::vector<Employee> employees;

    Department(std::string name) : name(std::move(name)) {}

    // Method now takes Employee by const reference, and stores a copy.
    void addEmployee(const Employee& emp) {
        // Optional: Check for duplicates based on ID (though technically it's a copy, so ID is the only identifier)
        for (const Employee& existingEmp : employees) {
            if (existingEmp.id == emp.id) {
                std::cout << "Employee with ID " << emp.id << " already in department " << name << std::endl;
                return;
            }
        }
        employees.push_back(emp); // A copy of emp is made here
        std::cout << "Added employee " << emp.name << " to " << name << std::endl;
    }

    void listEmployees() const {
        std::cout << "Department: " << name << std::endl;
        if (employees.empty()) {
            std::cout << "  No employees in this department." << std::endl;
        } else {
            for (const auto& emp : employees) {
                emp.display();
            }
        }
    }
};

int main() {
    // Create employees independently
    Employee emp1("Alice", 101);
    Employee emp2("Bob", 102);
    Employee emp3("Charlie", 103);

    // Create departments
    Department hr("Human Resources");
    Department eng("Engineering");

    // Add employees to departments. Copies are made.
    hr.addEmployee(emp1);
    hr.addEmployee(emp2);
    eng.addEmployee(emp2); // A *different* copy of emp2 is made for Engineering
    eng.addEmployee(emp3);

    std::cout << "\n--- Listing Employees ---" << std::endl;
    hr.listEmployees();
    std::cout << std::endl;
    eng.listEmployees();
    std::cout << std::endl;

    std::cout << "\n--- Demonstrating semantic error (employee independence) ---" << std::endl;
    std::cout << "Original emp2 (Bob) before name change: ";
    emp2.display();
    emp2.name = "Robert"; // Change the original independent employee object
    std::cout << "Original emp2 (Bob) after name change to Robert: ";
    emp2.display();
    std::cout << "\nNow listing departments again. The name change for emp2 will NOT reflect in departments." << std::endl;
    hr.listEmployees();
    std::cout << std::endl;
    eng.listEmployees();
    std::cout << std::endl;

    return 0;
}