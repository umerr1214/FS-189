#include <iostream>
#include <vector>
#include <string>

class Employee {
public:
    std::string name;
    int id;

    Employee(std::string n, int i) : name(n), id(i) {
        std::cout << "Employee " << name << " (ID: " << id << ") created." << std::endl;
    }

    ~Employee() {
        std::cout << "Employee " << name << " (ID: " << id << ") destroyed." << std::endl;
    }

    void display() const {
        std::cout << "Employee: " << name << " (ID: " << id << ")" << std::endl;
    }
};

class Department {
private:
    std::string name;
    std::vector<Employee*> employees;

public:
    Department(std::string n) : name(n) {}

    void addEmployee(Employee* emp) {
        employees.push_back(emp);
    }

    void displayEmployees() const {
        std::cout << "Department: " << name << std::endl;
        for (const auto& emp : employees) {
            // SEMANTIC ERROR: Potential dangling pointer access here
            // if an employee was created on the stack and went out of scope.
            // Accessing 'emp' after it's been destroyed leads to Undefined Behavior.
            if (emp) { 
                emp->display();
            } else {
                std::cout << "  (Null employee pointer encountered)" << std::endl;
            }
        }
    }
    // No explicit destructor to delete Employee* as Department aggregates, not owns,
    // which is correct for the problem's aggregation requirement.
    // The error stems from how Employee objects are managed in main.
};

int main() {
    Department hr("Human Resources");

    // Employee emp1 is created on the stack in main's scope
    Employee emp1("Alice", 101);
    hr.addEmployee(&emp1);

    { // A new, inner scope
        Employee emp2("Bob", 102); // emp2 created on stack within this scope
        hr.addEmployee(&emp2);
        std::cout << "Inside scope: Added Bob to HR." << std::endl;
    } // emp2 is destroyed here as it goes out of scope, but hr still holds a pointer to it!

    std::cout << "\nAttempting to display HR employees after Bob is destroyed:" << std::endl;
    // SEMANTIC ERROR OCCURS HERE: hr.displayEmployees() will try to access emp2,
    // which is now a dangling pointer (points to freed stack memory).
    hr.displayEmployees(); // This will likely crash or show garbage for Bob.

    // Demonstrate independence of emp1 (which is still in scope)
    std::cout << "\nEmployee 1 (Alice, ID 101) still exists independently:" << std::endl;
    emp1.display();

    std::cout << "\nEnd of program." << std::endl;

    return 0;
}