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
        std::cout << "  Employee ID: " << id << ", Name: " << name << std::endl;
    }
};

class Department {
public:
    std::string name;
    std::vector<Employee*> employees; // Aggregation: stores pointers to Employee objects

    Department(std::string name) : name(std::move(name)) {}

    void addEmployee(Employee* emp) {
        // LOGICAL ERROR: This check incorrectly prevents adding more than one employee to any department.
        // It should iterate through 'employees' to check for the specific 'emp' by ID,
        // but instead, it simply checks if the department is not empty and returns.
        if (!employees.empty()) {
             std::cout << "Department " << name << " already has employees, cannot add " << emp->name << "." << std::endl;
             return;
        }

        employees.push_back(emp);
        std::cout << "Added employee " << emp->name << " to " << name << std::endl;
    }

    void listEmployees() const {
        std::cout << "Department: " << name << std::endl;
        if (employees.empty()) {
            std::cout << "  No employees in this department." << std::endl;
        } else {
            for (const auto& emp : employees) {
                emp->display();
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

    // Add employees to departments
    hr.addEmployee(&emp1); // Alice added
    hr.addEmployee(&emp2); // Bob will be blocked by the logical error
    eng.addEmployee(&emp2); // Bob added
    eng.addEmployee(&emp3); // Charlie will be blocked by the logical error

    std::cout << "\n--- Listing Employees ---" << std::endl;
    hr.listEmployees();
    std::cout << std::endl;
    eng.listEmployees();
    std::cout << std::endl;

    return 0;
}