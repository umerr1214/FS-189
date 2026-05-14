#include <iostream>
#include <string>

class Employee {
private:
    std::string name;
    int employeeID;

public:
    Employee(const std::string& n, int id) : name(n), employeeID(id) {}

    void displayDetails() const {
        std::cout << "Employee Name: " << name << std::endl;
        std::cout << "Employee ID: " << employeeID << std::endl;
    }
};

class Manager : public Employee {
private:
    std::string department;

public:
    Manager(const std::string& n, int id, const std::string& dept)
        : Employee(n, id), department(dept) {}

    void displayDetails() const {
        Employee::displayDetails();
        std::cout << "Department: " << department << std::endl;
    }
} // SYNTAX ERROR: Missing semicolon here

int main() {
    Employee emp("Alice Smith", 101);
    std::cout << "--- Employee Details ---" << std::endl;
    emp.displayDetails();
    std::cout << std::endl;

    Manager mgr("Bob Johnson", 201, "Sales");
    std::cout << "--- Manager Details ---" << std::endl;
    mgr.displayDetails();

    return 0;
}