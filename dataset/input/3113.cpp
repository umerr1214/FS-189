#include <iostream>
#include <vector>
#include <string>

class Employee {
public:
    std::string name;
    int id;

    Employee(std::string n, int i) : name(n), id(i) {}

    void display() const {
        std::cout << "Name: " << name << ", ID: " << id << std::endl;
    }
};

class Department {
private:
    std::vector<Employee> employees;
    std::string departmentName;

public:
    Department(std::string name) : departmentName(name) {}

    void addEmployee(Employee emp) {
        employees.push_back(emp);
    }

    void displayAllEmployees() const {
        std::cout << "--- Employees in " << departmentName << " Department ---" << std::endl;
        if (employees.empty()) {
            std::cout << "No employees in this department." << std::endl;
        } else {
            // Logical error: Only display employees with even IDs
            for (const auto& emp : employees) {
                if (emp.id % 2 == 0) {
                    emp.display();
                }
            }
        }
        std::cout << "------------------------------------------" << std::endl;
    }
};

int main() {
    Department salesDept("Sales");

    Employee emp1("Alice", 101); // Odd ID
    Employee emp2("Bob", 102);   // Even ID
    Employee emp3("Charlie", 103); // Odd ID
    Employee emp4("David", 104);   // Even ID

    salesDept.addEmployee(emp1);
    salesDept.addEmployee(emp2);
    salesDept.addEmployee(emp3);
    salesDept.addEmployee(emp4);

    salesDept.displayAllEmployees();

    return 0;
}