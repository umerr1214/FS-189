#include <iostream>
#include <vector>
#include <string>
#include <memory>   // For std::unique_ptr and std::make_unique
#include <algorithm> // For std::find_if, std::remove_if

class Employee {
public:
    int id;
    std::string name;

    Employee(int id, const std::string& name) : id(id), name(name) {
        // std::cout << "Employee " << name << " (ID: " << id << ") created.\n";
    }

    // No need for explicit destructor if no other resources are managed, unique_ptr handles itself.
    // ~Employee() {
    //     std::cout << "Employee " << name << " (ID: " << id << ") destroyed.\n";
    // }

    void display() const {
        std::cout << "  ID: " << id << ", Name: " << name << "\n";
    }
};

class Department {
private:
    std::string name;
    std::vector<std::unique_ptr<Employee>> employees; // Aggregating Employee objects with smart pointers

public:
    Department(const std::string& name) : name(name) {
        // std::cout << "Department " << name << " created.\n";
    }

    // The default destructor is sufficient because std::unique_ptr handles deletion automatically.
    // The default copy/move constructors/assignment operators are implicitly deleted/generated correctly
    // due to std::unique_ptr, ensuring proper resource management (no copying unique_ptrs).

    // Adds an employee by transferring ownership of a unique_ptr.
    // The employee object is created independently (e.g., using std::make_unique) and then moved into the department.
    void addEmployee(std::unique_ptr<Employee> emp) {
        if (emp) {
            // Check for duplicates based on ID using std::find_if for efficiency and readability
            auto it = std::find_if(employees.begin(), employees.end(),
                                   [&emp](const std::unique_ptr<Employee>& existing_emp) {
                                       return existing_emp->id == emp->id;
                                   });
            if (it == employees.end()) {
                employees.push_back(std::move(emp)); // Transfer ownership
                // std::cout << "Added employee " << employees.back()->name << " to " << name << ".\n";
            } else {
                // std::cout << "Employee with ID " << emp->id << " already exists in " << name << ". Not added.\n";
            }
        }
    }

    // Finds an employee by ID and returns a const raw pointer for observation.
    // Ownership is not transferred or modified. Returns nullptr if not found.
    const Employee* findEmployee(int id) const {
        auto it = std::find_if(employees.begin(), employees.end(),
                               [id](const std::unique_ptr<Employee>& emp) {
                                   return emp->id == id;
                               });
        return (it != employees.end()) ? it->get() : nullptr;
    }

    // Removes an employee by ID. Returns true if successful, false otherwise.
    bool removeEmployee(int id) {
        auto it = std::remove_if(employees.begin(), employees.end(),
                                 [id](const std::unique_ptr<Employee>& emp) {
                                     return emp->id == id;
                                 });
        if (it != employees.end()) {
            employees.erase(it, employees.end()); // Erase the removed elements (and their unique_ptrs)
            // std::cout << "Removed employee with ID " << id << " from " << name << ".\n";
            return true;
        }
        // std::cout << "Employee with ID " << id << " not found in " << name << " for removal.\n";
        return false;
    }

    void listEmployees() const {
        std::cout << "Department: " << name << " (" << employees.size() << " employees)\n";
        if (employees.empty()) {
            std::cout << "  No employees.\n";
        } else {
            for (const auto& emp_ptr : employees) { // Use range-based for loop for clarity
                emp_ptr->display();
            }
        }
    }
};

int main() {
    Department hr_dept("Human Resources");

    // Create employees independently using std::make_unique and add them to the department
    hr_dept.addEmployee(std::make_unique<Employee>(101, "Alice"));
    hr_dept.addEmployee(std::make_unique<Employee>(102, "Bob"));
    hr_dept.addEmployee(std::make_unique<Employee>(103, "Charlie"));
    hr_dept.addEmployee(std::make_unique<Employee>(102, "Duplicate Bob")); // This will not be added due to duplicate ID

    hr_dept.listEmployees();

    std::cout << "\nAttempting to find employee with ID 102...\n";
    const Employee* bob = hr_dept.findEmployee(102);
    if (bob) {
        std::cout << "Found: ";
        bob->display();
    } else {
        std::cout << "Employee 102 not found.\n";
    }

    std::cout << "\nAttempting to find employee with ID 999...\n";
    const Employee* unknown = hr_dept.findEmployee(999);
    if (unknown) {
        std::cout << "Found: ";
        unknown->display();
    } else {
        std::cout << "Employee 999 not found.\n";
    }

    std::cout << "\nRemoving employee with ID 101...\n";
    hr_dept.removeEmployee(101);
    hr_dept.listEmployees();

    std::cout << "\nRemoving non-existent employee with ID 999...\n";
    hr_dept.removeEmployee(999);
    hr_dept.listEmployees();

    Department it_dept("IT Operations");
    it_dept.addEmployee(std::make_unique<Employee>(201, "David"));
    it_dept.listEmployees();

    // All dynamically allocated Employee objects are automatically deallocated
    // when their respective unique_ptr goes out of scope (e.g., when Department is destroyed),
    // ensuring no memory leaks.

    return 0;
}