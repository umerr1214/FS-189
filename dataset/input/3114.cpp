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
    std::vector<Employee*> employees; // Stores pointers to Employee objects
    std::string departmentName;

public:
    Department(std::string name) : departmentName(name) {}

    // Semantic error: Takes Employee by value, then stores a pointer to this temporary object.
    // The temporary 'emp' object is destroyed when addEmployee returns, leaving a dangling pointer.
    void addEmployee(Employee emp) {
        employees.push_back(&emp); // Storing address of a temporary stack object
    }

    void displayAllEmployees() const {
        std::cout << "--- Employees in " << departmentName << " Department ---" << std::endl;
        if (employees.empty()) {
            std::cout << "No employees in this department." << std::endl;
        } else {
            for (const auto& empPtr : employees) {
                // Accessing dangling pointers here will lead to undefined behavior
                empPtr->display(); // CRASH or garbage output expected
            }
        }
        std::cout << "------------------------------------------" << std::endl;
    }
};

int main() {
    Department itDept("IT");

    Employee empA("Grace", 201);
    Employee empB("Heidi", 202);

    itDept.addEmployee(empA); // empA is copied to a temporary in addEmployee, its address is taken
    itDept.addEmployee(empB); // empB is copied to a temporary in addEmployee, its address is taken

    std::cout << "Attempting to display employees (expecting crash or garbage):" << std::endl;
    itDept.displayAllEmployees(); // This will try to dereference dangling pointers

    return 0;
}