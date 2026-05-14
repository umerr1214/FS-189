#include <iostream>
#include <string>

class Person {
protected:
    std::string name;
public:
    // Efficiency Issue: Passing string by value, which causes an unnecessary copy.
    Person(std::string n) : name(n) {
        std::cout << "Person constructor called for: " << name << std::endl;
    }
    // Readability Issue: display method is not const, even though it doesn't modify object state.
    void displayPerson() {
        std::cout << "Name: " << name;
    }
};

class Employee : public Person {
protected:
    int employeeId;
    double salary;
public:
    // Efficiency Issue: Passing string by value in base class constructor.
    Employee(std::string n, int id, double s) : Person(n), employeeId(id), salary(s) {
        std::cout << "Employee constructor called for ID: " << employeeId << ", Salary: " << salary << std::endl;
    }
    // Readability Issue: display method is not const.
    void displayEmployee() {
        displayPerson();
        std::cout << ", Employee ID: " << employeeId << ", Salary: " << salary;
    }
};

class Manager : public Employee {
protected:
    std::string department;
public:
    // Efficiency Issue: Passing string by value, which causes an unnecessary copy.
    // Also, base class constructor takes string by value.
    Manager(std::string n, int id, double s, std::string dept)
        : Employee(n, id, s), department(dept) {
        std::cout << "Manager constructor called for Department: " << department << std::endl;
    }
    // Readability Issue: display method is not const.
    void displayManager() {
        displayEmployee();
        std::cout << ", Department: " << department << std::endl;
    }
};

int main() {
    std::cout << "Creating a Manager object..." << std::endl;
    // String literals are converted to std::string, then passed by value to constructors, leading to copies.
    Manager mgr("Bob Johnson", 102, 85000.75, "Marketing");
    std::cout << "\nManager Details:" << std::endl;
    mgr.displayManager();
    return 0;
}