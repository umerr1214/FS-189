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
} // ERROR: Missing semicolon here

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
        if (employees.empty()) {
            std::cout << "  No staff currently." << std::endl;
        } else {
            for (const auto& emp : employees) {
                std::cout << "  - " << emp.getName() << " (ID: " << emp.getId() << ")" << std::endl;
            }
        }
    }
};

int main() {
    Employee emp1("Alice", 101);
    Employee emp2("Bob", 102);

    Department engineering("Engineering");
    engineering.addEmployee(emp1);
    engineering.addEmployee(emp2);

    engineering.displayStaff();

    return 0;
}