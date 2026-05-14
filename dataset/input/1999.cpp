#include <iostream>
#include <string>
#include <vector>

class Employee {
protected:
    std::string name;
    double salary;

public:
    // Robustness Issue: Allows negative salary which is typically invalid.
    // No validation is performed for name or salary.
    Employee(std::string name, double salary) : name(name), salary(salary) {
        // No validation logic here for salary or name.
        // A negative salary is accepted, which might lead to incorrect calculations later.
    }

    virtual void display() const {
        std::cout << "Employee: " << name << ", Salary: $" << salary << std::endl;
    }
    
    // Simple getters for testing purposes
    std::string getName() const { return name; }
    double getSalary() const { return salary; }
};

class Manager : public Employee {
private:
    std::string department;

public:
    Manager(std::string name, double salary, std::string department)
        : Employee(name, salary), department(department) {
        // Inherits the potential robustness issue from Employee constructor
    }

    void display() const override {
        std::cout << "Manager: " << name << ", Salary: $" << salary
                  << ", Department: " << department << std::endl;
    }
    
    std::string getDepartment() const { return department; }
};

class Engineer : public Employee {
private:
    std::string specialization;

public:
    Engineer(std::string name, double salary, std::string specialization)
        : Employee(name, salary), specialization(specialization) {
        // Inherits the potential robustness issue from Employee constructor
    }

    void display() const override {
        std::cout << "Engineer: " << name << ", Salary: $" << salary
                  << ", Specialization: " << specialization << std::endl;
    }
    
    std::string getSpecialization() const { return specialization; }
};

int main() {
    // Test cases demonstrating the robustness issue (negative salary)
    Employee emp1("Alice", 60000.0);
    Employee emp2("Bob", -5000.0); // This is the robustness issue: negative salary accepted

    Manager mgr1("Charlie", 90000.0, "HR");
    Manager mgr2("David", -10000.0, "Finance"); // Negative salary for manager

    Engineer eng1("Eve", 75000.0, "Software Development");
    Engineer eng2("Frank", -8000.0, "Network Engineering"); // Negative salary for engineer

    std::cout << "--- Employee Data ---" << std::endl;
    emp1.display();
    emp2.display();
    mgr1.display();
    mgr2.display();
    eng1.display();
    eng2.display();

    // Example of how negative salary might lead to incorrect logic
    if (emp2.getSalary() < 0) {
        std::cout << "Warning: Employee " << emp2.getName() << " has a negative salary!" << std::endl;
    }
    if (mgr2.getSalary() < 0) {
        std::cout << "Warning: Manager " << mgr2.getName() << " has a negative salary!" << std::endl;
    }

    return 0;
}