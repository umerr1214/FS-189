#include <iostream>
#include <string>
#include <vector>

// Base class - SEMANTIC ERROR HERE (missing virtual)
class Employee {
public:
    std::string name;
    int id;

    Employee(std::string name, int id) : name(name), id(id) {}

    // SEMANTIC ERROR: Missing 'virtual' keyword.
    // This prevents polymorphic behavior when printDetails is called via a base pointer/reference.
    void printDetails() const { // Should be virtual void printDetails() const;
        std::cout << "Employee: " << name << ", ID: " << id;
    }
};

// Derived Manager class
class Manager : public Employee {
public:
    std::string department;

    Manager(std::string name, int id, std::string department)
        : Employee(name, id), department(department) {}

    void printDetails() const {
        Employee::printDetails();
        std::cout << ", Department: " << department;
    }
};

// Derived Worker class
class Worker : public Employee {
public:
    double hourlyRate;

    Worker(std::string name, int id, double hourlyRate)
        : Employee(name, id), hourlyRate(hourlyRate) {}

    void printDetails() const {
        Employee::printDetails();
        std::cout << ", Hourly Rate: " << hourlyRate;
    }
};

int main() {
    Manager mgr("Alice Smith", 101, "Sales");
    Worker wrk("Bob Johnson", 202, 25.50);

    // Demonstrate the semantic error using base class pointers
    std::vector<Employee*> employees;
    employees.push_back(&mgr);
    employees.push_back(&wrk);

    std::cout << "Details via Employee pointers (Semantic Error - expected derived, got base):\n";
    for (const auto& emp_ptr : employees) {
        emp_ptr->printDetails(); // This will call Employee::printDetails(), not derived versions
        std::cout << "\n";
    }
    std::cout << "\n";

    // Direct calls (will work correctly, but not demonstrate the error)
    std::cout << "Direct calls (correct behavior):\n";
    mgr.printDetails();
    std::cout << "\n";
    wrk.printDetails();
    std::cout << "\n";

    return 0;
}