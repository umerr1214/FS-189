#include <iostream>
#include <vector>
#include <string>
#include <utility> // For std::move

class Employee {
private:
    std::string name;
    int id;
public:
    // Constructor uses std::move for efficiency when handling string parameters.
    Employee(std::string name, int id) : name(std::move(name)), id(id) {}

    // Method to display employee information, uses '\n' for efficient output.
    void display() const {
        std::cout << "ID: " << id << ", Name: " << name << '\n';
    }

    // Getter for ID, which can be useful for future features or debugging.
    int getId() const { return id; }
};

class Department {
private:
    std::string name;
    std::vector<Employee> employees;
public:
    // Constructor takes string by value and moves it, efficiently handling both lvalue and rvalue arguments.
    Department(std::string name) : name(std::move(name)) {}

    // Method to add an employee.
    // Overload 1: Takes `const Employee&` to efficiently add an existing employee object without copying.
    void addEmployee(const Employee& employee) {
        employees.push_back(employee);
    }

    // Overload 2: Takes `Employee&&` (rvalue reference) to efficiently move a temporary
    // `Employee` object directly into the vector, avoiding unnecessary copies.
    void addEmployee(Employee&& employee) {
        employees.push_back(std::move(employee));
    }

    void listEmployees() const {
        std::cout << "Department: " << name << '\n';
        if (employees.empty()) {
            std::cout << "  No employees.\n";
            return;
        }
        // Uses a range-based for loop for modern, readable, and concise iteration over the collection.
        for (const auto& emp : employees) {
            emp.display();
        }
    }
};

int main() {
    Department hrDept("Human Resources");

    // Adding an employee using an lvalue reference (first overload of addEmployee)
    Employee alice("Alice Smith", 101);
    hrDept.addEmployee(alice);

    // Adding employees using rvalue references (second overload of addEmployee)
    hrDept.addEmployee(Employee("Bob Johnson", 102));
    hrDept.addEmployee(Employee("Charlie Brown", 103));

    std::cout << "--- Listing HR Department Employees ---\n";
    hrDept.listEmployees();
    std::cout << "\n";

    Department engDept("Engineering");
    engDept.addEmployee(Employee("David Lee", 201));
    engDept.addEmployee(Employee("Eve Davis", 202));
    std::cout << "--- Listing Engineering Department Employees ---\n";
    engDept.listEmployees();

    return 0;
}