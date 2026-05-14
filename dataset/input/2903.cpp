#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Employee {
public:
    std::string name;
    int id;

    Employee(std::string n, int i) : name(n), id(i) {}

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
        // LOGICAL ERROR: Only add employees with even IDs
        if (emp->id % 2 == 0) {
            employees.push_back(emp);
        } else {
            std::cout << "LOGICAL ERROR: Employee " << emp->name << " (ID: " << emp->id << ") not added to " << name << " due to odd ID." << std::endl;
        }
    }

    void displayEmployees() const {
        std::cout << "Department: " << name << std::endl;
        if (employees.empty()) {
            std::cout << "  No employees in this department." << std::endl;
        }
        for (const auto& emp : employees) {
            emp->display();
        }
    }
};

int main() {
    Employee emp1("Alice", 101); // Odd ID
    Employee emp2("Bob", 102);   // Even ID
    Employee emp3("Charlie", 103); // Odd ID
    Employee emp4("David", 104);   // Even ID

    Department hr("Human Resources");
    hr.addEmployee(&emp1); // Will not be added
    hr.addEmployee(&emp2); // Will be added
    hr.addEmployee(&emp3); // Will not be added
    hr.addEmployee(&emp4); // Will be added

    std::cout << "\n--- HR Department Employees ---" << std::endl;
    hr.displayEmployees();

    // Demonstrate independence
    std::cout << "\nEmployee 1 (Alice, ID 101) exists independently, even if not added to HR:" << std::endl;
    emp1.display();
    std::cout << "Employee 3 (Charlie, ID 103) exists independently, even if not added to HR:" << std::endl;
    emp3.display();

    std::cout << "\nEnd of program." << std::endl;

    return 0;
}