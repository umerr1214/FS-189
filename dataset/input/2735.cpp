#include <iostream>
#include <string>
#include <vector>

// Base class
class Employee {
public:
    std::string name;
    int id;

    Employee(std::string name, int id) : name(name), id(id) {}

    void printDetails() const {
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

// Derived Worker class - LOGICAL ERROR HERE
class Worker : public Employee {
public:
    double hourlyRate;

    Worker(std::string name, int id, double hourlyRate)
        : Employee(name, id), hourlyRate(hourlyRate) {}

    void printDetails() const {
        Employee::printDetails();
        // LOGICAL ERROR: Should print hourlyRate, but incorrectly prints id again
        std::cout << ", Hourly Rate (Incorrectly printed as ID): " << id; 
    }
};

int main() {
    Manager mgr("Alice Smith", 101, "Sales");
    Worker wrk("Bob Johnson", 202, 25.50);

    std::cout << "Manager Details:\n";
    mgr.printDetails();
    std::cout << "\n\n";

    std::cout << "Worker Details:\n";
    wrk.printDetails();
    std::cout << "\n";

    return 0;
}