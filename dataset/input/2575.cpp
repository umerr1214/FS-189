#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Not strictly needed for this version, but good to include for vector operations

class Employee {
public:
    std::string name;
    int employeeID;

    Employee(std::string name, int employeeID) : name(name), employeeID(employeeID) {}

    void display() const {
        std::cout << "  ID: " << employeeID << ", Name: " << name << std::endl;
    }
};

class Department {
public:
    std::string departmentName;
    std::vector<Employee> employees;

    Department(std::string name) : departmentName(name) {}

    // Robustness Issue: Does not check for duplicate employee IDs
    void addEmployee(Employee emp) {
        employees.push_back(emp); // Always adds the employee, even if ID already exists
        std::cout << "Added employee: " << emp.name << " (ID: " << emp.employeeID << ")" << std::endl;
    }

    // Robustness Issue: Does not explicitly handle an empty department
    void listAllEmployees() const {
        std::cout << "Employees in " << departmentName << ":" << std::endl;
        for (const auto& emp : employees) {
            emp.display();
        }
    }
};

int main() {
    Department hrDept("Human Resources");

    std::cout << "--- Adding Employees ---" << std::endl;
    hrDept.addEmployee(Employee("Alice Smith", 101));
    hrDept.addEmployee(Employee("Bob Johnson", 102));
    hrDept.addEmployee(Employee("Charlie Brown", 103));
    std::cout << "Attempting to add duplicate ID 101 for David Lee..." << std::endl;
    hrDept.addEmployee(Employee("David Lee", 101)); // Duplicate ID added
    hrDept.addEmployee(Employee("Eve Davis", 104));
    std::cout << std::endl;

    std::cout << "--- Listing Employees ---" << std::endl;
    hrDept.listAllEmployees();
    std::cout << std::endl;

    Department salesDept("Sales");
    std::cout << "--- Listing Employees in Empty Sales Department ---" << std::endl;
    salesDept.listAllEmployees(); // Lists nothing for an empty department
    
    return 0;
}