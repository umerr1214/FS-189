#include <iostream>
#include <string>

class Employee {
protected:
    std::string name;
    int id;
public:
    Employee(std::string n, int i) : name(n), id(i) {}
    virtual void displayInfo() const {
        std::cout << "Employee Name: " << name << ", ID: " << id << std::endl;
    }
};

class Manager : public Employee {
private:
    std::string department;
public:
    Manager(std::string n, int i, std::string d) : Employee(n, i), department(d) {}
    void displayInfo() const override {
        // Logical Error: This method only displays manager-specific details
        // but does not call the base class Employee::displayInfo() to include
        // the employee's name and ID, as required by "include additional details".
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