#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For std::find_if

class Employee {
private:
    std::string name;
    int id;

public:
    Employee(std::string name, int id) : name(std::move(name)), id(id) {}

    const std::string& getName() const {
        return name;
    }

    int getId() const {
        return id;
    }

    void display() const {
        std::cout << "  - Employee ID: " << id << ", Name: " << name << std::endl;
    }
};

class Department {
private:
    std::string name;
    std::vector<Employee> employees; // Semantic Error: Stores Employee objects by value (composition/ownership)
                                     // instead of by pointer/reference (aggregation).
                                     // This means Department owns copies, violating "Employee can exist independently"
                                     // in the context of the department's collection.

public:
    Department(std::string name) : name(std::move(name)) {}

    // No explicit destructor needed for std::vector<Employee> as it manages its own memory.
    // However, conceptually, the Department now owns these Employee objects,
    // rather than merely aggregating references to externally managed ones.

    void addEmployee(const Employee& emp) { // Takes by const reference, but stores a copy
        // Check if employee already exists by ID to prevent duplicates
        auto it = std::find_if(employees.begin(), employees.end(),
                               [&emp](const Employee& existing_emp) {
                                   return existing_emp.getId() == emp.getId();
                               });
        if (it == employees.end()) {
            employees.push_back(emp); // A copy of the Employee object is made and stored.
            std::cout << "Added employee " << emp.getName() << " to " << name << std::endl;
        } else {
            std::cout << "Employee " << emp.getName() << " (ID: " << emp.getId() << ") already in " << name << std::endl;
        }
    }

    void listEmployees() const {
        std::cout << "Employees in Department " << name << ":" << std::endl;
        if (employees.empty()) {
            std::cout << "  (No employees in this department)" << std::endl;
        } else {
            for (const auto& emp : employees) {
                emp.display();
            }
        }
    }
};

int main() {
    // Create Employee objects independently
    Employee emp1("Alice", 101);
    Employee emp2("Bob", 102);
    Employee emp3("Charlie", 103);

    // Create a Department
    Department hrDept("Human Resources");

    // Add employees to the department
    hrDept.addEmployee(emp1); // A copy of emp1 is made
    hrDept.addEmployee(emp2); // A copy of emp2 is made
    hrDept.addEmployee(emp1); // A copy of emp1 (again) is attempted, but blocked by ID check

    // List employees in the department
    hrDept.listEmployees();

    std::cout << "\n--- Another Department ---" << std::endl;
    Department devDept("Development");
    devDept.addEmployee(emp3); // A copy of emp3 is made
    devDept.addEmployee(emp2); // A copy of emp2 is made

    devDept.listEmployees();

    std::cout << "\n--- Verifying independent existence ---" << std::endl;
    // Original employee objects still exist, but they are distinct from the copies in departments.
    emp1.display();
    emp2.display();
    emp3.display();

    // To further illustrate the semantic issue: if emp1's name was changed *after* adding to department,
    // the department's copy would not reflect the change, which is characteristic of composition/value semantics,
    // not typical aggregation (where changes to the original aggregated object would be visible).
    std::cout << "\n--- Illustrating semantic difference ---" << std::endl;
    Employee original_emp_test("Test Employee", 999);
    Department testDept("Test Department");
    testDept.addEmployee(original_emp_test); // Department gets a copy
    original_emp_test = Employee("Changed Test Employee", 999); // Original object changes
    std::cout << "Original employee after change:" << std::endl;
    original_emp_test.display();
    std::cout << "Department's employee (should not change):" << std::endl;
    testDept.listEmployees(); // Department's copy remains unchanged

    return 0;
}