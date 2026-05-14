#include <iostream>
#include <vector>
#include <string>
#include <memory> // For std::shared_ptr
#include <utility> // For std::move

class Employee {
public:
    std::string name;
    int id;

    Employee(std::string name, int id) : name(std::move(name)), id(id) {}

    void display() const {
        std::cout << "  ID: " << id << ", Name: " << name << '\n'; // Use '\n' for efficiency
    }
};

class Department {
public:
    std::string name;
    // Aggregates Employee objects using shared pointers.
    // This allows employees to exist independently and be shared among departments
    // without complex memory management or ownership issues.
    std::vector<std::shared_ptr<Employee>> employees;

    Department(std::string name) : name(std::move(name)) {}

    // Adds an employee to the department.
    // Takes a shared_ptr to indicate shared ownership and prevent null dereferences.
    void addEmployee(std::shared_ptr<Employee> emp) {
        if (emp) { // Robustness check: ensure the pointer is not null
            employees.push_back(std::move(emp)); // Use std::move for efficiency if 'emp' is an rvalue
            std::cout << "Added employee " << employees.back()->name << " to " << name << ".\n";
        } else {
            std::cerr << "Warning: Attempted to add a null employee to department " << name << ".\n";
        }
    }

    void displayStaff() const {
        std::cout << "\nDepartment: " << name << '\n';
        std::cout << "Staff:\n";
        if (employees.empty()) {
            std::cout << "  No staff currently.\n";
        } else {
            for (const auto& emp : employees) {
                // No need for null check here if addEmployee already handles it
                emp->display();
            }
        }
        std::cout << "--- End of Staff List ---\n";
    }
};

int main() {
    // Create employees. They exist independently and can be shared.
    auto emp1 = std::make_shared<Employee>("Alice Johnson", 101);
    auto emp2 = std::make_shared<Employee>("Bob Smith", 102);
    auto emp3 = std::make_shared<Employee>("Charlie Brown", 103);

    // Create a department
    Department engineering("Engineering");

    // Add employees to the department
    engineering.addEmployee(emp1);
    engineering.addEmployee(emp2);
    engineering.addEmployee(emp3);

    // Display staff
    engineering.displayStaff();

    // Demonstrate another department sharing an employee and adding a new one
    Department marketing("Marketing");
    auto emp4 = std::make_shared<Employee>("Diana Prince", 201);
    marketing.addEmployee(emp2); // Bob Smith also works in Marketing (shared)
    marketing.addEmployee(emp4);
    marketing.addEmployee(nullptr); // Attempt to add null, should be handled gracefully

    marketing.displayStaff();

    // The shared_ptr automatically handles memory deallocation when
    // the last shared_ptr pointing to an Employee object goes out of scope.

    return 0;
}