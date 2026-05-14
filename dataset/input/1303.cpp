#include <iostream>
#include <vector>
#include <string>
#include <memory> // Not strictly needed for this robustness issue, but good practice for correct version

class Employee {
public:
    std::string name;
    int id;

    Employee(std::string name, int id) : name(std::move(name)), id(id) {}

    void display() const {
        std::cout << "  ID: " << id << ", Name: " << name << std::endl;
    }
};

class Department {
public:
    std::string name;
    std::vector<Employee*> employees; // Stores raw pointers

    Department(std::string name) : name(std::move(name)) {}

    // Robustness Issue: Does not check for nullptr before adding.
    // Dereferencing a nullptr in displayStaff() will cause a crash.
    void addEmployee(Employee* emp) {
        employees.push_back(emp);
    }

    void displayStaff() const {
        std::cout << "Department: " << name << std::endl;
        std::cout << "Staff:" << std::endl;
        if (employees.empty()) {
            std::cout << "  No staff currently." << std::endl;
        } else {
            for (const auto& emp : employees) {
                // This will crash if 'emp' is nullptr
                emp->display();
            }
        }
    }

    // Destructor to clean up allocated Employee objects IF Department owned them.
    // However, the prompt says "Employees can exist independently", implying
    // Department does not own their lifetime. For this robustness issue,
    // we assume raw pointers are passed and the crash occurs due to nullptr.
    // If Department were to own them, a memory leak would be another issue.
    // Here, the issue is dereferencing an invalid pointer.
};

int main() {
    // Create employees
    Employee emp1("Alice", 101);
    Employee emp2("Bob", 102);

    // Create a department
    Department engineering("Engineering");

    // Add employees to the department
    engineering.addEmployee(&emp1);
    engineering.addEmployee(&emp2);

    // Robustness Issue: Adding a nullptr without checking.
    // This simulates a scenario where an invalid employee pointer might be passed.
    Employee* invalid_emp = nullptr;
    engineering.addEmployee(invalid_emp);

    // Attempt to display staff, which will crash when trying to access invalid_emp->display()
    engineering.displayStaff();

    return 0; // This line might not be reached due to the crash
}