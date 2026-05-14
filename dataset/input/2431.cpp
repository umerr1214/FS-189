#include <iostream>
#include <string>

// Base class for a Person
class Person {
protected:
    std::string name;
    int age;
public:
    // Constructor: No input validation for age
    Person(std::string n, int a) : name(n), age(a) {}

    // Method to display person information
    virtual void display() const {
        std::cout << "Name: " << name << ", Age: " << age;
    }
};

// Derived class for an Employee, inheriting from Person
class Employee : public Person {
protected:
    int employeeId;
    double salary;
public:
    // Constructor: No input validation for salary
    Employee(std::string n, int a, int id, double s)
        : Person(n, a), employeeId(id), salary(s) {}

    // Overridden method to display employee information
    virtual void display() const override {
        Person::display();
        std::cout << ", Employee ID: " << employeeId << ", Salary: " << salary;
    }

    // Method to calculate bonus: Does not check for negative salary, leading to negative bonus
    double calculateBonus(double percentage) const {
        return salary * percentage; // If salary is negative, bonus will be negative
    }
};

// Derived class for a Manager, inheriting from Employee
class Manager : public Employee {
private:
    std::string department;
    int numDirectReports;
public:
    // Constructor: No input validation for numDirectReports
    Manager(std::string n, int a, int id, double s, std::string dept, int reports)
        : Employee(n, a, id, s), department(dept), numDirectReports(reports) {}

    // Overridden method to display manager information
    void display() const override {
        Employee::display();
        std::cout << ", Department: " << department << ", Direct Reports: " << numDirectReports;
    }

    // Method for conducting a performance review
    void conductPerformanceReview(const std::string& employeeName) const {
        std::cout << "Manager " << name << " is conducting a performance review for " << employeeName << " in " << department << ".\n";
    }
};

int main() {
    // Demonstrating robustness issues with invalid data
    Person p_invalid_age("Alice", -5); // Negative age
    std::cout << "Person Info (Invalid Age): ";
    p_invalid_age.display();
    std::cout << "\n";

    Employee e_invalid_salary("Bob", 30, 101, -5000.0); // Negative salary
    std::cout << "Employee Info (Invalid Salary): ";
    e_invalid_salary.display();
    std::cout << "\n";
    std::cout << "Employee Bonus (10% on negative salary): " << e_invalid_salary.calculateBonus(0.10) << "\n"; // Negative bonus

    Manager m_invalid_reports("Charlie", 45, 201, 80000.0, "Sales", -2); // Negative direct reports
    std::cout << "Manager Info (Invalid Reports): ";
    m_invalid_reports.display();
    std::cout << "\n";
    m_invalid_reports.conductPerformanceReview("Dave");
    std::cout << "\n";

    // Valid data for comparison
    Person p_valid("Eve", 25);
    std::cout << "Valid Person Info: ";
    p_valid.display();
    std::cout << "\n";

    Employee e_valid("Frank", 35, 102, 60000.0);
    std::cout << "Valid Employee Info: ";
    e_valid.display();
    std::cout << "\n";
    std::cout << "Valid Employee Bonus (10%): " << e_valid.calculateBonus(0.10) << "\n";

    Manager m_valid("Grace", 50, 202, 120000.0, "HR", 10);
    std::cout << "Valid Manager Info: ";
    m_valid.display();
    std::cout << "\n";
    m_valid.conductPerformanceReview("Heidi");

    return 0;
}