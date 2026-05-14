#include <iostream>
#include <string>
#include <stdexcept> // For input validation exceptions

// Base class for a Person
class Person {
protected:
    std::string name;
    int age;

public:
    // Constructor with input validation for age
    Person(const std::string& name, int age) : name(name) {
        if (age < 0 || age > 150) { // Reasonable age range
            throw std::out_of_range("Age must be between 0 and 150.");
        }
        this->age = age;
    }

    // Virtual method to display person information
    virtual void display() const {
        std::cout << "Name: " << name << ", Age: " << age;
    }

    // Getter for name, useful for derived classes without direct access
    const std::string& getName() const {
        return name;
    }
};

// Derived class for an Employee, inheriting from Person
class Employee : public Person {
protected:
    int employeeId;
    double salary;

public:
    // Constructor with input validation for salary
    Employee(const std::string& name, int age, int employeeId, double salary)
        : Person(name, age), employeeId(employeeId) {
        if (salary < 0) { // Salary cannot be negative
            throw std::out_of_range("Salary cannot be negative.");
        }
        this->salary = salary;
    }

    // Overridden method to display employee information
    virtual void display() const override {
        Person::display();
        std::cout << ", Employee ID: " << employeeId << ", Salary: " << salary;
    }

    // Method to calculate bonus based on a percentage, with validation
    double calculateBonus(double percentage) const {
        if (percentage < 0) {
            throw std::invalid_argument("Bonus percentage cannot be negative.");
        }
        return salary * percentage;
    }
};

// Derived class for a Manager, inheriting from Employee
class Manager : public Employee {
private:
    std::string department;
    int numDirectReports;

public:
    // Constructor with input validation for number of direct reports
    Manager(const std::string& name, int age, int employeeId, double salary,
            const std::string& department, int numDirectReports)
        : Employee(name, age, employeeId, salary), department(department) {
        if (numDirectReports < 0) { // Number of reports cannot be negative
            throw std::out_of_range("Number of direct reports cannot be negative.");
        }
        this->numDirectReports = numDirectReports;
    }

    // Overridden method to display manager information
    void display() const override {
        Employee::display();
        std::cout << ", Department: " << department << ", Direct Reports: " << numDirectReports;
    }

    // Method for conducting a performance review
    void conductPerformanceReview(const std::string& employeeName) const {
        std::cout << "Manager " << getName() << " is conducting a performance review for "
                  << employeeName << " in " << department << ".\n";
    }
};

int main() {
    // Using a try-catch block to handle potential exceptions from constructors
    try {
        std::cout << "--- Creating Valid Objects ---\n";

        Person p("Alice", 30);
        std::cout << "Person Info: ";
        p.display();
        std::cout << "\n";

        Employee e("Bob", 35, 101, 60000.0);
        std::cout << "Employee Info: ";
        e.display();
        std::cout << "\n";
        std::cout << "Employee Bonus (10%): " << e.calculateBonus(0.10) << "\n";

        Manager m("Charlie", 45, 201, 90000.0, "Engineering", 10);
        std::cout << "Manager Info: ";
        m.display();
        std::cout << "\n";
        m.conductPerformanceReview("Dave");
        std::cout << "\n";

        // Demonstrate polymorphism using base class pointers
        std::cout << "--- Demonstrating Polymorphism ---\n";
        Person* people[3];
        people[0] = new Person("Eve", 28);
        people[1] = new Employee("Frank", 32, 102, 55000.0);
        people[2] = new Manager("Grace", 50, 202, 120000.0, "HR", 15);

        for (int i = 0; i < 3; ++i) {
            people[i]->display();
            std::cout << "\n";
        }

        // Clean up dynamically allocated objects
        for (int i = 0; i < 3; ++i) {
            delete people[i];
        }
        std::cout << "\n";

        // --- Attempting to Create Invalid Objects (expecting errors) ---
        std::cout << "--- Attempting to Create Invalid Objects (expecting errors) ---\n";
        try {
            Person p_invalid_age("Invalid Age", -5); // This will throw
        } catch (const std::out_of_range& ex) {
            std::cerr << "Error creating Person: " << ex.what() << "\n";
        }

        try {
            Employee e_invalid_salary("Invalid Salary", 30, 103, -1000.0); // This will throw
        } catch (const std::out_of_range& ex) {
            std::cerr << "Error creating Employee: " << ex.what() << "\n";
        }
        
        try {
            Manager m_invalid_reports("Invalid Reports", 40, 203, 70000.0, "Marketing", -1); // This will throw
        } catch (const std::out_of_range& ex) {
            std::cerr << "Error creating Manager: " << ex.what() << "\n";
        }

    } catch (const std::exception& ex) {
        // Catch any other unexpected exceptions
        std::cerr << "An unexpected error occurred: " << ex.what() << "\n";
    }

    return 0;
}