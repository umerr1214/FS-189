#include <iostream>
#include <vector>
#include <string>
#include <utility> // For std::move

class Employee {
public:
    std::string name;
    int id;

    Employee(std::string name, int id) : name(std::move(name)), id(id) {
        std::cout << "Employee created: " << name << std::endl;
    }

    void print() const {
        std::cout << "Employee: " << name << " (ID: " << id << ")" << std::endl;
    }

    ~Employee() {
        std::cout << "Employee destroyed: " << name << std::endl;
    }
};

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

    // LOGICAL ERROR: Department destructor attempts to delete aggregated Employee objects.
    // This is incorrect for aggregation where Employee objects are owned externally.
    // If employees are stack-allocated (as in main), this leads to undefined behavior/crash.
    // If employees are heap-allocated and managed elsewhere, this leads to a double-free.
    ~Department() {
        std::cout << "Department " << name << " destructor called." << std::endl;
        for (Employee* emp : employees) {
            std::cout << "  Attempting to delete employee: " << emp->name << std::endl;
            delete emp; // This is the logical error for aggregation
        }
        employees.clear();
    }
};

int main() {
    // Employee objects created independently on the stack
    Employee emp1("Alice", 101);
    Employee emp2("Bob", 102);

    // Department aggregates pointers to these stack-allocated employees
    Department hr("Human Resources");
    hr.addEmployee(&emp1);
    hr.addEmployee(&emp2);

    hr.printDepartment();

    std::cout << "End of main. Department destructor will now be called." << std::endl;
    // When 'hr' goes out of scope, its destructor will try to delete &emp1 and &emp2.
    // Deleting stack-allocated memory is undefined behavior and will likely crash.

    return 0;
}