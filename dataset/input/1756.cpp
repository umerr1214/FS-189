#include <string>
#include <vector>
#include <iostream>

class Employee {
public:
    int id;
    std::string name;

    Employee(int id, const std::string& name) : id(id), name(name) {}

    void display() const {
        std::cout << "  ID: " << id << ", Name: " << name << std::endl;
    }
};

class Department {
private:
    std::string name;
    std::vector<Employee> employees;

public:
    Department(const std::string& name) : name(name) {}

    void addEmployee(const Employee& emp) {
        employees.push_back(emp) // Syntax Error: Missing semicolon
    }

    void listEmployees() const {
        std::cout << "Department: " << name << std::endl;
        if (employees.empty()) {
            std::cout << "  No employees." << std::endl;
            return;
        }
        for (const auto& emp : employees) {
            emp.display();
        }
    }
};

int main() {
    Department hr("Human Resources");
    Employee e1(101, "Alice Smith");
    Employee e2(102, "Bob Johnson");

    hr.addEmployee(e1);
    hr.addEmployee(e2);

    hr.listEmployees();

    return 0;
}