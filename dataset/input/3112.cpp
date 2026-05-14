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
    Department(std::string name) : departmentName(name) {} // Missing semicolon here

    void addEmployee(Employee emp) {
        employees.push_back(emp);
    }

    void displayAllEmployees() const {
        std::cout << "--- Employees in " << departmentName << " Department ---" << std::endl;
        if (employees.empty()) {
            std::cout << "No employees in this department." << std::endl;
        } else {
            for (const auto& emp : employees) {
                emp.display();
            }
        }
        std::cout << "------------------------------------------" << std::endl;
    }
};

int main() {
    Department hrDept("Human Resources");

    Employee emp1("Alice", 101);
    Employee emp2("Bob", 102);
    Employee emp3("Charlie", 103);

    hrDept.addEmployee(emp1);
    hrDept.addEmployee(emp2);
    hrDept.addEmployee(emp3);

    hrDept.displayAllEmployees();

    return 0;
}