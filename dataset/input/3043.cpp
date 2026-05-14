#include <iostream>
#include <string>
#include <iomanip> // Not used for specific formatting in this case, but good practice.

class Person {
protected:
    std::string name;
public:
    Person(const std::string& n) : name(n) {
        std::cout << "Person constructor called for: " << name << std::endl;
    }
    void displayPerson() const {
        std::cout << "Name: " << name;
    }
};

class Employee : public Person {
protected:
    int employeeId;
    double salary;
public:
    // Robustness Issue: employeeId and salary are not initialized in the initializer list.
    // They are default-initialized (to indeterminate values for built-in types)
    // and then assigned in the constructor body. This is less robust as the object
    // exists in a potentially uninitialized state for a brief period.
    Employee(const std::string& n, int id, double s) : Person(n) {
        employeeId = id; // Assignment, not initialization
        salary = s;      // Assignment, not initialization
        std::cout << "Employee constructor called for ID: " << employeeId << ", Salary: " << salary << std::endl;
    }
    void displayEmployee() const {
        displayPerson();
        std::cout << ", Employee ID: " << employeeId << ", Salary: " << salary;
    }
};

class Manager : public Employee {
protected:
    std::string department;
public:
    Manager(const std::string& n, int id, double s, const std::string& dept)
        : Employee(n, id, s), department(dept) { // 'department' is correctly initialized
        std::cout << "Manager constructor called for Department: " << department << std::endl;
    }
    void displayManager() const {
        displayEmployee();
        std::cout << ", Department: " << department << std::endl;
    }
};

int main() {
    std::cout << "Creating a Manager object..." << std::endl;
    Manager mgr("Alice Smith", 101, 75000.50, "Sales");
    std::cout << "\nManager Details:" << std::endl;
    mgr.displayManager();
    return 0;
}