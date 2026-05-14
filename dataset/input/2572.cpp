#include <iostream>
#include <vector>
#include <string>
#include <utility> // For std::move

class Employee {
public:
    std::string name // Missing semicolon here, will cause a syntax error
    int employeeID;

    Employee(std::string name, int employeeID) : name(std::move(name)), employeeID(employeeID) {}

    void display() const {
        std::cout << "ID: " << employeeID << ", Name: " << name << std::endl;
    }
};

class Department {
private:
    std::string departmentName;
    std::vector<Employee*> employees; // Aggregation using raw pointers

public:
    Department(std::string name) : departmentName(std::move(name)) {}

    void addEmployee(Employee* emp) {
        if (emp) {
            employees.push_back(emp);
        }
    }

    void listEmployees() const {
        std::cout << "Department: " << departmentName << std::endl;
        if (employees.empty()) {
            std::cout << "No employees in this department." << std::endl;
        } else {
            for (const auto& emp : employees) {
                emp->display();
            }
        }
    }

    // In this aggregation setup, Department does not own Employee objects,
    // so it doesn't delete them. The client code is responsible for their lifetime.
    ~Department() {
        // No deletion needed here for this specific aggregation model
    }
};

int main() {
    // Create Employee objects on the stack (client owns them)
    Employee emp1("Alice", 101);
    Employee emp2("Bob", 102);

    Department hr("Human Resources");
    hr.addEmployee(&emp1); // Add pointers to stack-allocated employees
    hr.addEmployee(&emp2);

    std::cout << "Listing employees in HR department:" << std::endl;
    hr.listEmployees();

    Department sales("Sales");
    std::cout << "\nListing employees in Sales department (empty):" << std::endl;
    sales.listEmployees();

    return 0;
}