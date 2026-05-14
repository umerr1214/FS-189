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
        // Optional: Check if employee already exists to avoid duplicates
        for (Employee* existingEmp : employees) {
            if (existingEmp->id == emp->id) {
                std::cout << "Employee with ID " << emp->id << " already in department " << name << std::endl;
                return;
            }
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
} // SYNTAX ERROR: Missing semicolon here

int main() {
    // Create employees independently
    Employee emp1("Alice", 101);
    Employee emp2("Bob", 102);
    Employee emp3("Charlie", 103);

    // Create departments
    Department hr("Human Resources");
    Department eng("Engineering");

    // Add employees to departments
    hr.addEmployee(&emp1);
    hr.addEmployee(&emp2);
    eng.addEmployee(&emp2); // Bob is in two departments
    eng.addEmployee(&emp3);

    std::cout << "\n--- Listing Employees ---" << std::endl;
    hr.listEmployees();
    std::cout << std::endl;
    eng.listEmployees();
    std::cout << std::endl;

    return 0;
}