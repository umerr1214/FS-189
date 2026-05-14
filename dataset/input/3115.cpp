#include <iostream>
#include <vector>
#include <string>
#include <stdexcept> // Required for std::out_of_range

class Employee {
public:
    std::string name;
    int id;

    Employee(std::string name, int id) : name(std::move(name)), id(id) {}

    void display() const {
        std::cout << "Name: " << name << ", ID: " << id << std::endl;
    }
};

class Department {
private:
    std::vector<Employee> employees;

public:
    void addEmployee(Employee emp) { // Takes by value, which is fine, but not optimal
        employees.push_back(emp);
    }

    // Robustness Issue: Off-by-one error with std::vector::at() leading to std::out_of_range
    void displayAllEmployees() const {
        std::cout << "Department Employees:" << std::endl;
        if (employees.empty()) {
            std::cout << "No employees in this department." << std::endl;
            // Even if empty, the loop below would still attempt to access employees.at(0) if size() was 0 and loop started at 0
            // The fix below ensures it crashes only if there are employees and the loop goes one too far.
            // If empty, the loop condition i <= employees.size() (0 <= 0) makes it run once for i=0, causing a crash.
            return;
        }

        // The robustness issue is here: i <= employees.size()
        // If employees.size() is N, valid indices are 0 to N-1.
        // This loop attempts to access employees.at(N) which is out of bounds.
        for (size_t i = 0; i <= employees.size(); ++i) {
            try {
                employees.at(i).display(); // std::vector::at() throws std::out_of_range
            } catch (const std::out_of_range& e) {
                std::cerr << "Error: " << e.what() << " - Attempted to access employee at index " << i << std::endl;
                // In a real application, this would be caught and handled,
                // but for demonstrating a robustness issue, we let it propagate or terminate.
                throw; // Re-throw to show the unhandled exception
            }
        }
    }
};

int main() {
    Department hrDepartment;

    Employee emp1("Alice", 101);
    Employee emp2("Bob", 102);
    Employee emp3("Charlie", 103);

    hrDepartment.addEmployee(emp1);
    hrDepartment.addEmployee(emp2);
    hrDepartment.addEmployee(emp3);

    // This call will lead to a crash due to the robustness issue in displayAllEmployees
    try {
        hrDepartment.displayAllEmployees();
    } catch (const std::out_of_range& e) {
        std::cerr << "Program terminated due to unhandled exception: " << e.what() << std::endl;
        return 1; // Indicate an error
    }

    return 0;
}