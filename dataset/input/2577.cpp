#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For std::find_if

class Employee {
public:
    std::string name;
    int employeeID;

    Employee(std::string name, int employeeID) : name(name), employeeID(employeeID) {}

    // Getter methods for encapsulation and const correctness
    const std::string& getName() const { return name; }
    int getEmployeeID() const { return employeeID; }

    void display() const {
        std::cout << "  ID: " << employeeID << ", Name: " << name << std::endl;
    }
};

class Department {
private:
    std::string departmentName;
    std::vector<Employee> employees;

public:
    Department(std::string name) : departmentName(name) {}

    // Efficient parameter passing (const reference) and robustness (duplicate ID check)
    bool addEmployee(const Employee& emp) {
        // Check for duplicate employee ID before adding
        auto it = std::find_if(employees.begin(), employees.end(),
                               [&](const Employee& existingEmp) {
                                   return existingEmp.getEmployeeID() == emp.getEmployeeID();
                               });

        if (it == employees.end()) {
            employees.push_back(emp); // Add employee (copy construction or move if emp is an rvalue)
            std::cout << "Successfully added employee: " << emp.getName() << " (ID: " << emp.getEmployeeID() << ")" << std::endl;
            return true;
        } else {
            std::cout << "Error: Employee with ID " << emp.getEmployeeID() << " already exists in " << departmentName << ". Not added." << std::endl;
            return false;
        }
    }

    // Const-correct method to list all employees, handles empty department gracefully
    void listAllEmployees() const {
        std::cout << "Employees in " << departmentName << ":" << std::endl;
        if (employees.empty()) {
            std::cout << "  (No employees in this department.)" << std::endl;
            return;
        }
        for (const auto& emp : employees) { // Use const auto& for efficient and safe iteration
            emp.display();
        }
    }
};

int main() {
    Department itDept("IT Department");

    std::cout << "--- Adding Employees to IT Department ---" << std::endl;
    itDept.addEmployee(Employee("Sarah Connor", 301));
    itDept.addEmployee(Employee("John Doe", 302));
    itDept.addEmployee(Employee("Jane Smith", 303));
    std::cout << "Attempting to add Sarah Connor again (ID 301)..." << std::endl;
    itDept.addEmployee(Employee("Sarah Connor", 301)); // Attempt to add duplicate ID
    itDept.addEmployee(Employee("Mike Ross", 304));
    std::cout << std::endl;

    std::cout << "--- Listing Employees in IT Department ---" << std::endl;
    itDept.listAllEmployees();
    std::cout << std::endl;

    Department emptyDept("Empty Department");
    std::cout << "--- Listing Employees in Empty Department ---" << std::endl;
    emptyDept.listAllEmployees();
    std::cout << std::endl;
    
    return 0;
}