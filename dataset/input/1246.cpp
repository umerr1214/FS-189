#include <iostream>
#include <string>

class Employee {
protected:
    std::string name;
    int id;
public:
    Employee(std::string n, int i) : name(n), id(i) {}
    virtual void displayInfo() const {
        std::cout << "Employee Name: " << name << ", ID: " << id << std::endl // SYNTAX ERROR: Missing semicolon
    }
};

class Manager : public Employee {
private:
    std::string department;
public:
    Manager(std::string n, int i, std::string d) : Employee(n, i), department(d) {}
    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << "  Department: " << department << std::endl;
    }
};

int main() {
    Employee emp("Alice", 101);
    Manager mgr("Bob", 201, "Sales");

    std::cout << "--- Employee Info ---" << std::endl;
    emp.displayInfo();
    std::cout << std::endl;

    std::cout << "--- Manager Info ---" << std::endl;
    mgr.displayInfo();
    std::cout << std::endl;

    return 0;
}