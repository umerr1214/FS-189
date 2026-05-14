#include <iostream>
#include <vector>
#include <string>

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
        employees.push_back(emp);
    }

    void displayEmployees() const {
        std::cout << "Department: " << name << std::endl;
        for (const auto& emp : employees) {
            emp->display();
        }
    }
};

int main() {
    Employee emp1("Alice", 101);
    Employee emp2("Bob", 102);

    Department hr("Human Resources");
    hr.addEmployee(&emp1);
    hr.addEmployee(&emp2);

    hr.displayEmployees();

    std::cout << "\nEmployee 1 exists independently:" << std::endl;
    emp1.display() // SYNTAX ERROR: Missing semicolon here

    Department sales("Sales");
    Employee emp3("Charlie", 103);
    sales.addEmployee(&emp3);
    sales.displayEmployees();

    std::cout << "\nEnd of program." << std::endl;

    return 0;
}