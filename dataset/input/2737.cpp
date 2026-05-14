#include <iostream>
#include <string>
#include <vector>

// Base class Employee
class Employee {
protected:
    std::string name;
    int id;
public:
    Employee(std::string n, int i) : name(n), id(i) {}

    // Robustness Issue: Non-virtual destructor.
    // If a derived object is deleted via a base pointer,
    // the derived class's destructor will NOT be called.
    // This can lead to resource leaks if derived classes manage resources.
    ~Employee() {
        // For demonstration purposes, if Manager or Worker had specific resources
        // to clean up (e.g., dynamically allocated memory), their destructors
        // would not be invoked when deleted through an Employee* pointer.
        // std::cout << "Employee destructor called for " << name << " (ID: " << id << ")" << std::endl;
    }

    virtual void printDetails() const {
        std::cout << "Employee Name: " << name << ", ID: " << id;
    }
};

// Derived class Manager
class Manager : public Employee {
private:
    std::string department;
public:
    Manager(std::string n, int i, std::string d)
        : Employee(n, i), department(d) {}

    // ~Manager() { std::cout << "Manager destructor called for " << name << " (ID: " << id << ")" << std::endl; }

    void printDetails() const override {
        Employee::printDetails();
        std::cout << ", Department: " << department << std::endl;
    }
};

// Derived class Worker
class Worker : public Employee {
private:
    double hourlyRate;
public:
    Worker(std::string n, int i, double hr)
        : Employee(n, i), hourlyRate(hr) {}

    // ~Worker() { std::cout << "Worker destructor called for " << name << " (ID: " << id << ")" << std::endl; }

    void printDetails() const override {
        Employee::printDetails();
        std::cout << ", Hourly Rate: " << hourlyRate << std::endl;
    }
};

int main() {
    std::vector<Employee*> employees;

    // Creating objects with potential robustness issues:
    // 1. Allowing negative IDs without validation.
    employees.push_back(new Manager("Alice Smith", 101, "Sales"));
    employees.push_back(new Worker("Bob Johnson", 202, 25.50));
    employees.push_back(new Manager("Charlie Brown", 303, "Marketing"));
    employees.push_back(new Worker("Diana Prince", -404, 30.00)); // Robustness issue: negative ID allowed

    std::cout << "--- Employee Details ---" << std::endl;
    for (const auto& emp : employees) {
        emp->printDetails();
    }
    std::cout << "------------------------" << std::endl;

    // This loop demonstrates the robustness issue with the non-virtual destructor.
    // When `delete emp` is called, only `Employee::~Employee()` is invoked,
    // not `Manager::~Manager()` or `Worker::~Worker()`.
    // If derived classes managed dynamic memory or other resources, this would lead to leaks.
    std::cout << "\nAttempting to delete employees polymorphically..." << std::endl;
    for (Employee* emp : employees) {
        delete emp; // Only Employee::~Employee() is called due to non-virtual destructor
    }
    std::cout << "Employees deleted (potential resource leaks if derived classes manage resources)." << std::endl;

    return 0;
}