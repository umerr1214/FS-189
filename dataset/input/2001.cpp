#include <iostream>
#include <string>
#include <vector>

class Employee {
protected:
    std::string name;
    double salary;

public:
    // Constructor using initializer list for efficient member initialization
    Employee(std::string name, double salary)
        : name(std::move(name)), salary(salary) {}

    // Virtual destructor for proper polymorphic cleanup
    virtual ~Employee() = default;

    // Virtual display method for runtime polymorphism
    virtual void display() const {
        std::cout << "Employee: " << name << ", Salary: $" << salary << std::endl;
    }

    // Getters for name and salary (const-correct)
    const std::string& getName() const { return name; }
    double getSalary() const { return salary; }
};

class Manager : public Employee {
private:
    std::string department;

public:
    // Constructor using initializer list for base class and member initialization
    Manager(std::string name, double salary, std::string department)
        : Employee(std::move(name), salary), department(std::move(department)) {}

    // Override display method
    void display() const override {
        std::cout << "Manager: " << name << ", Salary: $" << salary
                  << ", Department: " << department << std::endl;
    }

    // Getter for department (const-correct)
    const std::string& getDepartment() const { return department; }
};

class Engineer : public Employee {
private:
    std::string specialization;

public:
    // Constructor using initializer list for base class and member initialization
    Engineer(std::string name, double salary, std::string specialization)
        : Employee(std::move(name), salary), specialization(std::move(specialization)) {}

    // Override display method
    void display() const override {
        std::cout << "Engineer: " << name << ", Salary: $" << salary
                  << ", Specialization: " << specialization << std::endl;
    }

    // Getter for specialization (const-correct)
    const std::string& getSpecialization() const { return specialization; }
};

int main() {
    // Create instances of all three types
    Employee emp("John Doe", 50000.0);
    Manager mgr("Jane Smith", 120000.0, "Research & Development");
    Engineer eng("Peter Jones", 85000.0, "Machine Learning");

    std::cout << "--- Employee Information ---" << std::endl;
    emp.display();
    mgr.display();
    eng.display();

    std::cout << "\n--- Polymorphic Display ---" << std::endl;
    std::vector<Employee*> employees;
    employees.push_back(&emp);
    employees.push_back(&mgr);
    employees.push_back(&eng);

    for (const auto* e : employees) {
        e->display();
    }
    
    // Demonstrate getter usage
    std::cout << "\nManager's Department: " << mgr.getDepartment() << std::endl;

    return 0;
}