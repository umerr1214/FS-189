#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For std::find_if

class Employee {
private:
    std::string name;
    int id;

public:
    Employee(std::string name, int id) : name(std::move(name)), id(id) {}

    const std::string& getName() const {
        return name;
    }

    int getId() const {
        return id;
    }

    void display() const {
        std::cout << "  - Employee ID: " << id << ", Name: " << name << std::endl;
    }
}; // Missing semicolon here, causing a syntax error

class Department {
private:
    std::string name;
    std::vector<Employee*> employees; // Aggregation: stores pointers to Employee objects

public:
    Department(std::string name) : name(std::move(name)) {}

    // Destructor to clean up pointers (but not delete Employee objects as they exist independently)
    // In a real scenario, manage ownership carefully, e.g., with smart pointers or clear documentation.
    // For this problem, Employee objects are assumed to be managed externally.
    ~Department() {
        // No deletion of Employee* as they are aggregated, not composed.
        // Employees are assumed to be managed by the caller.
    }

    void addEmployee(Employee* emp) {
        if (emp == nullptr) {
            std::cerr << "Error: Cannot add a null employee." << std::endl;
            return;
        }
        // Check if employee already exists to prevent duplicates (optional, but good practice)
        auto it = std::find_if(employees.begin(), employees.end(),
                               [emp](const Employee* existing_emp) {
                                   return existing_emp->getId() == emp->getId();
                               });
        if (it == employees.end()) {
            employees.push_back(emp);
            std::cout << "Added employee " << emp->getName() << " to " << name << std::endl;
        } else {
            std::cout << "Employee " << emp->getName() << " (ID: " << emp->getId() << ") already in " << name << std::endl;
        }
    }

    void listEmployees() const {
        std::cout << "Employees in Department " << name << ":" << std::endl;
        if (employees.empty()) {
            std::cout << "  (No employees in this department)" << std::endl;
        } else {
            for (const auto& emp : employees) {
                emp->display();
            }
        }
    }
};

int main() {
    // Create Employee objects independently
    Employee emp1("Alice", 101);
    Employee emp2("Bob", 102);
    Employee emp3("Charlie", 103);

    // Create a Department
    Department hrDept("Human Resources");

    // Add employees to the department
    hrDept.addEmployee(&emp1);
    hrDept.addEmployee(&emp2);
    hrDept.addEmployee(&emp1); // Try adding Alice again

    // List employees in the department
    hrDept.listEmployees();

    std::cout << "\n--- Another Department ---" << std::endl;
    Department devDept("Development");
    devDept.addEmployee(&emp3);
    devDept.addEmployee(&emp2); // Bob also works in Development

    devDept.listEmployees();

    std::cout << "\n--- Verifying independent existence ---" << std::endl;
    emp1.display(); // Alice still exists independently
    emp2.display(); // Bob still exists independently

    return 0;
}