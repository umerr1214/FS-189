#include <iostream>
#include <vector>
#include <string>

class Employee {
private:
    std::string name;
    int id;
public:
    Employee(std::string name, int id) : name(name), id(id) {}
    std::string getName() const { return name; }
    int getId() const { return id; }
};

class Department {
private:
    std::string name;
    std::vector<Employee> employees;
public:
    Department(std::string name) : name(name) {}

    void addEmployee(const Employee& emp) {
        employees.push_back(emp);
    }

    void displayStaff() const {
        std::cout << "Department: " << name << std::endl;
        // Logical Error: Always prints "No staff" regardless of employees in the vector
        std::cout << "  No staff currently." << std::endl;
    }
};

int main() {
    Employee emp1("Alice", 101);
    Employee emp2("Bob", 102);

    Department engineering("Engineering");
    engineering.addEmployee(emp1);
    engineering.addEmployee(emp2);

    engineering.displayStaff();

    Department sales("Sales");
    sales.displayStaff(); // Should also print "No staff" due to the error

    return 0;
}