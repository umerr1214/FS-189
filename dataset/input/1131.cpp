#include <iostream>
#include <vector>
#include <string>
#include <memory> // For std::shared_ptr
#include <algorithm> // For std::remove_if (if a remove method was implemented)

// Employee class
class Employee {
public:
    std::string name;
    int id;

    Employee(std::string name, int id) : name(std::move(name)), id(id) {
        std::cout << "Employee created: " << this->name << " (ID: " << this->id << ")" << std::endl;
    }

    ~Employee() {
        std::cout << "Employee destroyed: " << this->name << " (ID: " << this->id << ")" << std::endl;
    }

    void print() const {
        std::cout << "  Employee ID: " << id << ", Name: " << name << std::endl;
    }
};

// Department class
class Department {
public:
    std::string name;
    // Aggregation: stores shared pointers to Employee objects.
    // This demonstrates shared ownership and ensures employees exist independently
    // but are only destroyed when no department (or other shared_ptr) references them.
    std::vector<std::shared_ptr<Employee>> employees;

    Department(std::string name) : name(std::move(name)) {
        std::cout << "Department created: " << this->name << std::endl;
    }

    ~Department() {
        std::cout << "Department destroyed: " << this->name << std::endl;
    }

    // Method to add an employee
    // Takes a shared_ptr, correctly managing shared ownership.
    void addEmployee(std::shared_ptr<Employee> emp) {
        if (emp) {
            employees.push_back(emp);
            std::cout << "  Added " << emp->name << " to " << name << std::endl;
        } else {
            std::cout << "  Warning: Attempted to add a null employee to " << name << std::endl;
        }
    }

    // Method to list employees
    void listEmployees() const {
        std::cout << "Department: " << name << std::endl;
        if (employees.empty()) {
            std::cout << "  No employees in this department." << std::endl;
            return;
        }
        for (const auto& emp : employees) {
            if (emp) { // Check if pointer is still valid (though shared_ptr handles this gracefully)
                emp->print();
            } else {
                std::cout << "  (Invalid/Null Employee Entry)" << std::endl;
            }
        }
    }

    // Optional: Method to remove an employee by ID (not strictly required by question but good for demonstration)
    void removeEmployee(int id) {
        auto it = std::remove_if(employees.begin(), employees.end(),
                                 [id](const std::shared_ptr<Employee>& emp) {
                                     return emp && emp->id == id;
                                 });
        if (it != employees.end()) {
            std::cout << "  Removed employee with ID " << id << " from " << name << std::endl;
            employees.erase(it, employees.end());
        } else {
            std::cout << "  Employee with ID " << id << " not found in " << name << std::endl;
        }
    }
};

int main() {
    std::cout << "--- Demonstrating Correct Aggregation with std::shared_ptr ---" << std::endl;

    // Create Employee objects using std::make_shared
    auto emp_alice = std::make_shared<Employee>("Alice", 101);
    auto emp_bob = std::make_shared<Employee>("Bob", 102);
    auto emp_charlie = std::make_shared<Employee>("Charlie", 103);

    std::cout << "\n--- Creating Departments ---" << std::endl;
    Department hr_dept("Human Resources");
    Department it_dept("IT Department");
    Department sales_dept("Sales");

    std::cout << "\n--- Adding Employees to Departments ---" << std::endl;
    hr_dept.addEmployee(emp_alice);
    hr_dept.addEmployee(emp_bob);

    it_dept.addEmployee(emp_alice); // Alice is added to IT Department as well
    it_dept.addEmployee(emp_charlie);

    sales_dept.addEmployee(emp_bob); // Bob is added to Sales Department as well

    std::cout << "\n--- Initial Department Listings ---" << std::endl;
    hr_dept.listEmployees();
    it_dept.listEmployees();
    sales_dept.listEmployees();

    std::cout << "\n--- Demonstrating Independence (Employee Alice is in HR and IT) ---" << std::endl;
    // If hr_dept goes out of scope, Alice still exists because it_dept holds a shared_ptr to her.
    // Let's simulate removal from one department without destruction.
    std::cout << "Removing Alice from HR Department (employee ID 101)..." << std::endl;
    hr_dept.removeEmployee(101); // Alice is removed from HR's list

    std::cout << "\n--- Department Listings After Alice's Removal from HR ---" << std::endl;
    hr_dept.listEmployees(); // Alice no longer in HR list
    it_dept.listEmployees(); // Alice still in IT list
    sales_dept.listEmployees();

    std::cout << "\n--- End of main scope: Departments and Employees will be destroyed ---" << std::endl;
    // When main ends, hr_dept, it_dept, sales_dept go out of scope.
    // Their destructors are called.
    // shared_ptr's will decrement their reference counts.
    // Alice will be destroyed when both emp_alice and it_dept's shared_ptr to her are gone.
    // Bob will be destroyed when both emp_bob and sales_dept's shared_ptr to him are gone.
    // Charlie will be destroyed when both emp_charlie and it_dept's shared_ptr to him are gone.

    return 0;
}