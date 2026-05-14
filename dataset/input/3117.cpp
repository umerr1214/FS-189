#include <iostream>
#include <vector>
#include <string>
#include <utility> // For std::move

class Employee {
public:
    std::string name;
    int id;

    // Constructor using initializer list and std::move for efficiency with string
    Employee(std::string name, int id) : name(std::move(name)), id(id) {}

    // Const method to display employee details
    void display() const {
        std::cout << "Name: " << name << ", ID: " << id << std::endl;
    }
};

class Department {
private:
    std::vector<Employee> employees;

public:
    // Efficiently adds an employee by taking a const reference
    void addEmployee(const Employee& emp) {
        employees.push_back(emp);
    }

    // Displays all employees using a range-based for loop and is const-correct
    void displayAllEmployees() const {
        std::cout << "Department Employees:" << std::endl;
        if (employees.empty()) {
            std::cout << "No employees in this department." << std::endl;
            return;
        }
        for (const auto& emp : employees) { // Range-based for loop for readability and safety
            emp.display();
        }
    }
};

int main() {
    Department hrDepartment;

    // Creating Employee objects
    Employee emp1("Alice", 101);
    Employee emp2("Bob", 102);
    Employee emp3("Charlie", 103);

    // Adding employees to the department
    hrDepartment.addEmployee(emp1);
    hrDepartment.addEmployee(emp2);
    hrDepartment.addEmployee(emp3);

    // Displaying all employees in the department
    hrDepartment.displayAllEmployees();

    return 0;
}