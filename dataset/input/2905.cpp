#include <iostream>
#include <vector>
#include <string>
#include <utility> // For std::move

class Employee {
public:
    std::string name;
    int id;

    Employee(std::string name, int id) : name(std::move(name)), id(id) {
        std::cout << "Employee " << this->name << " (" << this->id << ") created.\n";
    }

    ~Employee() {
        std::cout << "Employee " << this->name << " (" << this->id << ") destroyed.\n";
    }

    void display() const {
        std::cout << "  - Employee: " << name << ", ID: " << id << "\n";
    }
};

class Department {
private:
    std::string name;
    std::vector<Employee*> employees; // Aggregation using pointers

public:
    Department(std::string name) : name(std::move(name)) {
        std::cout << "Department " << this->name << " created.\n";
    }

    // Robustness Issue: Department destructor attempts to delete Employee objects
    // it does not own. This will lead to double-free or deleting stack-allocated memory.
    ~Department() {
        std::cout << "Department " << this->name << " destroyed. Attempting to delete employees...\n";
        for (Employee* emp : employees) {
            if (emp != nullptr) {
                std::cout << "  (Department deleting Employee " << emp->name << ")\n";
                delete emp; // CRITICAL ERROR: Double-free or deleting stack memory
            }
        }
        std::cout << "Department " << this->name << " destruction complete.\n";
    }

    void addEmployee(Employee* emp) {
        if (emp != nullptr) {
            employees.push_back(emp);
            std::cout << "  Added Employee " << emp->name << " to " << name << ".\n";
        } else {
            std::cout << "  Attempted to add a null employee to " << name << ".\n";
        }
    }

    void displayEmployees() const {
        std::cout << "Department " << name << " Employees:\n";
        if (employees.empty()) {
            std::cout << "  (No employees in this department)\n";
        } else {
            for (const Employee* emp : employees) {
                if (emp != nullptr) {
                    emp->display();
                } else {
                    std::cout << "  - (Null Employee pointer)\n";
                }
            }
        }
    }
};

int main() {
    std::cout << "--- Program Start ---\n";

    // Employee objects created on the stack (independent existence)
    Employee emp1("Alice", 101);
    Employee emp2("Bob", 102);

    // Dynamically allocated Employee (independent existence, owned by main)
    Employee* emp3 = new Employee("Charlie", 103);
    Employee* emp4 = new Employee("David", 104);

    {
        Department hr_dept("Human Resources");
        hr_dept.addEmployee(&emp1); // Add stack-allocated employee
        hr_dept.addEmployee(&emp2); // Add stack-allocated employee
        hr_dept.addEmployee(emp3);  // Add dynamically allocated employee
        hr_dept.displayEmployees();
        // Department hr_dept goes out of scope here.
        // Its destructor will attempt to delete emp1, emp2 (stack - crash)
        // and emp3 (dynamically allocated - double free with main's delete).
    } // CRASH/UNDEFINED BEHAVIOR EXPECTED HERE due to hr_dept's destructor

    std::cout << "\n--- After Department HR scope ---\n";
    // If the program didn't crash, emp1 and emp2 should still be valid.
    // However, emp3 would have been deleted by hr_dept.
    emp1.display(); // Accessing stack object
    emp2.display(); // Accessing stack object

    // Attempting to access emp3 will be use-after-free if hr_dept deleted it.
    // If hr_dept deleted it, main's delete will be a double-free.
    if (emp3 != nullptr) { // This check won't prevent use-after-free, just double-delete if main sets to nullptr
        std::cout << "Attempting to display emp3 after HR dept destruction (might be crash/UAF):\n";
        emp3->display(); // Use-after-free if hr_dept deleted it
        delete emp3;     // Double-free if hr_dept deleted it
    } else {
        std::cout << "emp3 was already null.\n";
    }

    // emp4 was never added to a department, still owned by main.
    std::cout << "Displaying emp4 (never added to department):\n";
    emp4->display();
    delete emp4; // Correctly delete emp4

    std::cout << "--- Program End ---\n";

    return 0;
}