#include <iostream>
#include <vector>
#include <string>
#include <utility> // For std::move

class Employee {
public:
    std::string name;
    int employeeID;

    Employee(std::string name, int employeeID) : name(std::move(name)), employeeID(employeeID) {
        // std::cout << "Employee " << employeeID << " created." << std::endl; // For debugging
    }

    void display() const {
        std::cout << "ID: " << employeeID << ", Name: " << name << std::endl;
    }

    ~Employee() {
        // std::cout << "Employee " << employeeID << " destroyed." << std::endl; // For debugging
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

    // SEMANTIC ERROR: Department uses raw pointers for aggregation, implying it takes
    // ownership of dynamically allocated Employee objects passed to it.
    // However, its destructor is empty and does not delete these objects,
    // leading to a memory leak when Department objects are destroyed.
    ~Department() {
        // This destructor is intentionally left empty to demonstrate a memory leak.
        // A correct implementation, if Department owned the Employee objects, would be:
        // for (Employee* emp : employees) {
        //     delete emp;
        // }
        // employees.clear();
    }
};

int main() {
    // Dynamically allocate Employee objects.
    // The Department class will store pointers to these, but its destructor
    // will fail to delete them, causing a memory leak.
    Employee* emp1 = new Employee("Alice", 101);
    Employee* emp2 = new Employee("Bob", 102);
    Employee* emp3 = new Employee("Charlie", 103); // This one is created but never added to a department, also a leak if not deleted by main.

    Department hr("Human Resources");
    hr.addEmployee(emp1);
    hr.addEmployee(emp2);

    std::cout << "Listing employees in HR department:" << std::endl;
    hr.listEmployees();

    Department sales("Sales");
    sales.addEmployee(emp3); // Add Charlie to Sales department

    std::cout << "\nListing employees in Sales department:" << std::endl;
    sales.listEmployees();

    // No `delete emp1;`, `delete emp2;`, `delete emp3;` calls here
    // to highlight the memory leak, both from Department's lack of cleanup
    // and main's direct allocation.
    // The primary semantic error is Department's failure to manage resources it aggregates.

    return 0; // Memory leaks for emp1, emp2, emp3 at this point.
}