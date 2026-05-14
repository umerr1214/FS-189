#include <iostream>
#include <string>
#include <vector>

// Base class Employee
class Employee {
protected:
    std::string name;
    int id;
public:
    // Constructor: Pass strings by const reference for efficiency and good practice.
    Employee(const std::string& name, int id) : name(name), id(id) {}

    // Virtual destructor for proper polymorphic cleanup.
    virtual ~Employee() = default;

    // Virtual method to print details, marked const as it does not modify the object's state.
    virtual void printDetails() const {
        std::cout << "Employee Name: " << name << ", ID: " << id;
    }
};

// Derived class Manager
class Manager : public Employee {
private:
    std::string department;
public:
    // Constructor: Pass strings by const reference for efficiency.
    Manager(const std::string& name, int id, const std::string& department)
        : Employee(name, id), department(department) {}

    // Override printDetails, marked const, and calls base class method to avoid code duplication.
    void printDetails() const override {
        Employee::printDetails(); // Call base class method to print common details
        std::cout << ", Department: " << department << std::endl;
    }
};

// Derived class Worker
class Worker : public Employee {
private:
    double hourlyRate;
public:
    // Constructor: Pass strings by const reference for efficiency.
    Worker(const std::string& name, int id, double hourlyRate)
        : Employee(name, id), hourlyRate(hourlyRate) {}

    // Override printDetails, marked const, and calls base class method to avoid code duplication.
    void printDetails() const override {
        Employee::printDetails(); // Call base class method to print common details
        std::cout << ", Hourly Rate: " << hourlyRate << std::endl;
    }
};

int main() {
    // Driver code to demonstrate functionality of the correctly implemented classes
    std::vector<Employee*> employees;

    // Create instances of Manager and Worker
    employees.push_back(new Manager("Alice Wonderland", 101, "Marketing"));
    employees.push_back(new Worker("Bob The Builder", 202, 35.75));
    employees.push_back(new Manager("Charlie Chaplin", 303, "Finance"));
    employees.push_back(new Worker("Dora The Explorer", 404, 28.00));

    std::cout << "--- Employee Details ---" << std::endl;
    for (const auto& emp : employees) {
        emp->printDetails(); // Polymorphic call to printDetails
    }
    std::cout << "------------------------" << std::endl;

    // Clean up dynamically allocated memory using polymorphic deletion.
    // The virtual destructor in Employee ensures that the correct derived
    // class destructor is called before the base class destructor.
    for (Employee* emp : employees) {
        delete emp;
    }

    return 0;
}