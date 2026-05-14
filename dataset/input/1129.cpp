#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Not strictly needed, but common header

// Employee class
class Employee {
public:
    std::string name;
    int id;

    Employee(std::string name, int id) : name(std::move(name)), id(id) {}

    void print() const {
        std::cout << "  Employee ID: " << id << ", Name: " << name << std::endl;
    }
};

// Department class
class Department {
public:
    std::string name;
    // Aggregation: stores raw pointers to Employee objects.
    // The Department does not own the Employee objects' memory.
    std::vector<Employee*> employees;

    Department(std::string name) : name(std::move(name)) {}

    // Method to add an employee
    // Robustness Issue: Does not check if 'emp' is a nullptr before adding.
    void addEmployee(Employee* emp) {
        employees.push_back(emp);
    }

    // Method to list employees
    // Robustness Issue: Iterates through employees and dereferences pointers
    // without checking if they are valid (e.g., if a nullptr was added).
    void listEmployees() const {
        std::cout << "Department: " << name << std::endl;
        if (employees.empty()) {
            std::cout << "  No employees in this department." << std::endl;
            return;
        }
        for (const auto& emp : employees) {
            // Potential Null Pointer Dereference if 'emp' is nullptr
            emp->print();
        }
    }
};

int main() {
    std::cout << "--- Demonstrating Robustness Issue (Null Pointer Dereference) ---" << std::endl;

    // Create Employee objects
    Employee emp1("Alice", 101);
    Employee emp2("Bob", 102);

    // Create departments
    Department hr_dept("Human Resources");
    Department it_dept("IT Department");

    // Add employees to departments
    hr_dept.addEmployee(&emp1);
    hr_dept.addEmployee(&emp2);

    it_dept.addEmployee(&emp1); // Alice is in multiple departments

    std::cout << "\nInitial Department Listings:" << std::endl;
    hr_dept.listEmployees();
    it_dept.listEmployees();

    std::cout << "\n--- Adding a nullptr to a department (Robustness Issue) ---" << std::endl;
    Employee* null_emp = nullptr;
    hr_dept.addEmployee(null_emp); // Adding a nullptr without checks

    std::cout << "\nAttempting to list employees after adding nullptr to HR Dept:" << std::endl;
    // This call will likely cause a crash (segmentation fault) when it tries to call emp->print() on the nullptr.
    hr_dept.listEmployees();

    // Clean up dynamically allocated employees if any were created on heap.
    // In this example, employees are on stack, so no manual deletion needed.

    std::cout << "\n--- Program will likely crash before reaching here ---" << std::endl;

    return 0;
}