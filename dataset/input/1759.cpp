#include <iostream>
#include <vector>
#include <string>
#include <utility> // For std::move
#include <algorithm> // Not used for actual robustness issue, but often helpful

class Employee {
private:
    std::string name;
    int id;
public:
    Employee(std::string name, int id) : name(std::move(name)), id(id) {}
    void display() const {
        std::cout << "ID: " << id << ", Name: " << name << '\n';
    }
    int getId() const { return id; }
    const std::string& getName() const { return name; }
};

class Department {
private:
    std::string name;
    std::vector<Employee> employees;
public:
    Department(std::string name) : name(std::move(name)) {}

    void addEmployee(const Employee& emp) {
        // Robustness Issue: This method does not check for duplicate employees
        // by ID or any other criteria. Adding the same employee multiple times
        // will result in multiple entries in the department's collection,
        // leading to inconsistent or incorrect data in a real-world scenario.
        // A robust system would typically prevent duplicates or handle them explicitly.
        employees.push_back(emp);
    }

    void listEmployees() const {
        std::cout << "Department: " << name << '\n';
        if (employees.empty()) {
            std::cout << "  No employees.\n";
            return;
        }
        for (const auto& emp : employees) {
            emp.display();
        }
    }
};

int main() {
    Department hrDept("Human Resources");

    // Adding initial employees
    hrDept.addEmployee(Employee("Alice Smith", 101));
    hrDept.addEmployee(Employee("Bob Johnson", 102));
    hrDept.addEmployee(Employee("Charlie Brown", 103));

    // Robustness Issue demonstrated: Adding an employee with ID 101 again.
    // The current implementation simply adds a duplicate entry.
    // A robust system would typically detect this and either reject the addition,
    // update the existing record, or provide a warning.
    hrDept.addEmployee(Employee("Alice Smith Jr.", 101)); // Same ID as Alice Smith, but different name

    std::cout << "--- Listing HR Department Employees (with duplicate ID) ---\n";
    hrDept.listEmployees();
    std::cout << "\n";

    Department engDept("Engineering");
    engDept.addEmployee(Employee("David Lee", 201));
    engDept.addEmployee(Employee("Eve Davis", 202));
    std::cout << "--- Listing Engineering Department Employees ---\n";
    engDept.listEmployees();

    return 0;
}