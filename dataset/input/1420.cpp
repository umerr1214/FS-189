#include <iostream>
#include <vector>
#include <string>
#include <utility> // For std::move

class Employee {
public:
    std::string name;
    int id;

    Employee(std::string name, int id) : name(std::move(name)), id(id) {}

    void print() const {
        std::cout << "Employee: " << name << " (ID: " << id << ")" << std::endl;
    }
} // SYNTAX ERROR: Missing semicolon here

class Department {
private:
    std::string name;
    std::vector<Employee*> employees; // Aggregation: pointers

public:
    Department(std::string name) : name(std::move(name)) {}

    void addEmployee(Employee* emp) {
        if (emp) {
            employees.push_back(emp);
        }
    }

    void printDepartment() const {
        std::cout << "Department: " << name << std::endl;
        std::cout << "Employees:" << std::endl;
        if (employees.empty()) {
            std::cout << "  No employees." << std::endl;
        } else {
            for (const auto& emp : employees) {
                std::cout << "  ";
                emp->print();
            }
        }
    }

    // Destructor: Department aggregates, doesn't own Employee objects
    ~Department() {
        // No delete for aggregated Employee pointers
    }
};

int main() {
    // Employee objects are created independently
    Employee emp1("Alice", 101);
    Employee emp2("Bob", 102);

    Department hr("Human Resources");
    hr.addEmployee(&emp1);
    hr.addEmployee(&emp2);

    hr.printDepartment();

    return 0;
}