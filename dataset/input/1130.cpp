#include <iostream>
#include <vector>
#include <string>
#include <sstream> // For std::ostringstream

// Employee class
class Employee {
public:
    std::string name;
    int id;

    Employee(std::string name, int id) : name(std::move(name)), id(id) {}

    // Helper to get employee info as string
    std::string getInfo() const {
        return "  Employee ID: " + std::to_string(id) + ", Name: " + name;
    }
};

// Department class
class Department {
public:
    std::string name;
    // Aggregation: stores raw pointers to Employee objects.
    // While technically correct for aggregation, using raw pointers for shared ownership
    // is less idiomatic and safer than smart pointers like std::shared_ptr,
    // impacting readability and requiring careful manual memory management in client code.
    std::vector<Employee*> employees;

    Department(std::string name) : name(std::move(name)) {}

    // Method to add an employee
    // Takes a raw pointer, implying external ownership.
    void addEmployee(Employee* emp) {
        if (emp) { // Basic check for robustness, but not fixing the core issue of raw pointers
            employees.push_back(emp);
        } else {
            std::cerr << "Warning: Attempted to add a null employee to department " << name << std::endl;
        }
    }

    // Method to list employees
    // Readability/Efficiency Issue: Builds the entire output string using ostringstream
    // before printing. For very large lists, direct printing with std::cout in a loop
    // can be more efficient and simpler to read.
    void listEmployees() const {
        std::ostringstream oss;
        oss << "Department: " << name << std::endl;
        if (employees.empty()) {
            oss << "  No employees in this department." << std::endl;
        } else {
            for (const auto& emp : employees) {
                if (emp) { // Check for robustness
                    oss << emp->getInfo() << std::endl;
                } else {
                    oss << "  (Invalid/Null Employee Entry)" << std::endl;
                }
            }
        }
        std::cout << oss.str(); // Print the accumulated string once
    }

    // No destructor needed as Department does not own Employee objects' memory.
};

int main() {
    std::cout << "--- Demonstrating Readability / Efficiency Issue ---" << std::endl;

    // Create Employee objects on the heap to ensure they outlive main's stack frame
    // and demonstrate manual memory management required with raw pointers.
    Employee* emp1 = new Employee("Alice", 101);
    Employee* emp2 = new Employee("Bob", 102);
    Employee* emp3 = new Employee("Charlie", 103);

    // Create departments
    Department sales_dept("Sales");
    Department marketing_dept("Marketing");

    // Add employees to departments
    sales_dept.addEmployee(emp1);
    sales_dept.addEmployee(emp2);
    marketing_dept.addEmployee(emp1); // Alice is in multiple departments
    marketing_dept.addEmployee(emp3);

    std::cout << "\nListing Departments:" << std::endl;
    sales_dept.listEmployees();
    marketing_dept.listEmployees();

    // Demonstrate independence: Charlie is removed from Marketing (conceptually, not by method)
    // but still exists if another department held him (not the case here, but the principle holds).
    // Here, we just show he's managed externally.
    std::cout << "\nDemonstrating employee independence (Alice in both Sales and Marketing):" << std::endl;
    std::cout << "Alice (ID 101) exists independently and is referenced by both departments." << std::endl;

    // Clean up dynamically allocated employees. This manual management is prone to errors.
    delete emp1;
    delete emp2;
    delete emp3;

    std::cout << "\n--- End of demonstration ---" << std::endl;

    return 0;
}