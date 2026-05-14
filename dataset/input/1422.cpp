#include <iostream>
#include <vector>
#include <string>
#include <utility> // For std::move

class Employee {
public:
    std::string name;
    int id;

    Employee(std::string name, int id) : name(std::move(name)), id(id) {
        std::cout << "Employee created: " << name << std::endl;
    }

    void print() const {
        std::cout << "Employee: " << name << " (ID: " << id << ")" << std::endl;
    }

    ~Employee() {
        std::cout << "Employee destroyed: " << name << std::endl;
    }
};

class Department {
private:
    std::string name;
    // SEMANTIC ERROR: The question explicitly asks for a "list of Employee pointers".
    // This implementation uses a vector of Employee objects by value, changing the
    // aggregation relationship to composition/copying.
    std::vector<Employee> employees; // Should be std::vector<Employee*> for aggregation

public:
    Department(std::string name) : name(std::move(name)) {}

    // The addEmployee method now takes a const reference and copies the object.
    void addEmployee(const Employee& emp) {
        employees.push_back(emp); // A copy of the Employee object is made
        std::cout << "Added employee (by copy): " << emp.name << std::endl;
    }

    void printDepartment() const {
        std::cout << "Department: " << name << std::endl;
        std::cout << "Employees:" << std::endl;
        if (employees.empty()) {
            std::cout << "  No employees." << std::endl;
        } else {
            for (const auto& emp : employees) {
                std::cout << "  ";
                emp.print();
            }
        }
    }

    // Destructor: For a vector of objects, default destructor handles destruction.
    // No explicit delete is needed, but the objects stored are copies, not aggregated pointers.
    ~Department() {
        std::cout << "Department " << name << " destructor called." << std::endl;
        // The copies of Employee objects within 'employees' vector are destroyed automatically here.
    }
};

int main() {
    // Original Employee objects created independently
    Employee emp1("Alice", 101);
    Employee emp2("Bob", 102);

    Department hr("Human Resources");
    hr.addEmployee(emp1); // A COPY of emp1 is made and stored in hr
    hr.addEmployee(emp2); // A COPY of emp2 is made and stored in hr

    hr.printDepartment();

    std::cout << "End of main. Original employees still exist and will be destroyed after copies." << std::endl;
    // The original emp1 and emp2 objects will be destroyed here, after the Department's copies are destroyed.

    return 0;
}