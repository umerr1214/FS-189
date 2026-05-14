#include <iostream>
#include <vector>
#include <string>
#include <utility> // For std::move
#include <algorithm> // Not strictly needed for this basic aggregation, but good to include for general C++

class Employee {
private:
    std::string name;
    int id;

public:
    // Constructor using initialization list for efficiency and correctness
    Employee(std::string name, int id) : name(std::move(name)), id(id) {
        std::cout << "Employee " << this->name << " (" << this->id << ") created.\n";
    }

    // Destructor to track object lifetime
    ~Employee() {
        std::cout << "Employee " << this->name << " (" << this->id << ") destroyed.\n";
    }

    // Const getter for name
    const std::string& getName() const {
        return name;
    }

    // Const getter for id
    int getId() const {
        return id;
    }

    // Const method to display employee details
    void display() const {
        std::cout << "  - Employee: " << name << ", ID: " << id << "\n";
    }
};

class Department {
private:
    std::string name;
    std::vector<Employee*> employees; // Aggregation using raw pointers

public:
    // Constructor using initialization list
    Department(std::string name) : name(std::move(name)) {
        std::cout << "Department " << this->name << " created.\n";
    }

    // Destructor: Important for aggregation, it *does not* delete the Employee pointers.
    // The Department aggregates, but does not own, the Employee objects.
    ~Department() {
        std::cout << "Department " << this->name << " destroyed. (Employee objects remain independent)\n";
        // No 'delete' calls here, as Employee objects are owned externally.
    }

    // Method to add an employee pointer
    void addEmployee(Employee* emp) {
        if (emp != nullptr) {
            // Optional: check for duplicates if required, but not strictly part of aggregation
            // For simplicity, we just add.
            employees.push_back(emp);
            std::cout << "  Added Employee " << emp->getName() << " to " << name << ".\n";
        } else {
            std::cerr << "  Warning: Attempted to add a null employee to " << name << ".\n";
        }
    }

    // Const method to display all employees using a range-based for loop
    void displayEmployees() const {
        std::cout << "Department " << name << " Employees:\n";
        if (employees.empty()) {
            std::cout << "  (No employees in this department)\n";
        } else {
            for (const Employee* emp : employees) { // Use const Employee* for safety
                if (emp != nullptr) {
                    emp->display();
                } else {
                    std::cout << "  - (Null Employee pointer in vector)\n";
                }
            }
        }
    }
};

int main() {
    std::cout << "--- Program Start ---\n";

    // 1. Employee objects created on the stack (independent existence)
    Employee emp_stack1("Alice", 101);
    Employee emp_stack2("Bob", 102);

    // 2. Dynamically allocated Employee objects (independent existence, owned by main)
    Employee* emp_heap1 = new Employee("Charlie", 103);
    Employee* emp_heap2 = new Employee("David", 104);

    { // Scope for Department object
        Department hr_dept("Human Resources");
        hr_dept.addEmployee(&emp_stack1); // Add stack-allocated employee
        hr_dept.addEmployee(&emp_stack2); // Add stack-allocated employee
        hr_dept.addEmployee(emp_heap1);   // Add dynamically allocated employee
        hr_dept.addEmployee(nullptr);     // Test null pointer handling
        hr_dept.displayEmployees();

        std::cout << "\n--- Department HR scope ends ---\n";
    } // hr_dept goes out of scope here. Its destructor is called, but it does NOT delete employees.

    std::cout << "\n--- After Department HR scope ---\n";

    // Demonstrate independent existence: stack-allocated employees are still valid
    std::cout << "Verifying stack-allocated employees after department destruction:\n";
    emp_stack1.display();
    emp_stack2.display();

    // Demonstrate independent existence: dynamically allocated employee is still valid
    std::cout << "Verifying heap-allocated employee (emp_heap1) after department destruction:\n";
    if (emp_heap1 != nullptr) {
        emp_heap1->display();
    } else {
        std::cout << "  (emp_heap1 is null, unexpected in this correct version)\n";
    }

    // emp_heap2 was never added to a department, clearly independent
    std::cout << "Verifying heap-allocated employee (emp_heap2) never added to department:\n";
    if (emp_heap2 != nullptr) {
        emp_heap2->display();
    } else {
        std::cout << "  (emp_heap2 is null, unexpected)\n";
    }

    // Clean up dynamically allocated memory
    std::cout << "\n--- Cleaning up dynamically allocated employees ---\n";
    delete emp_heap1;
    emp_heap1 = nullptr; // Good practice to nullify pointers after deletion
    delete emp_heap2;
    emp_heap2 = nullptr;

    std::cout << "--- Program End ---\n";

    return 0;
}